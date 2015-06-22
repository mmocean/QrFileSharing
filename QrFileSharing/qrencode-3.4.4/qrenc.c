/*************************************************************************
	> File Name: qrenc.c
	> Author: 
	> Mail: @163.com 
	> Created Time: Sun 22 Mar 2015 02:13:29 PM CST
 ************************************************************************/

#if HAVE_CONFIG_H
# include "config.h"
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "qrencode.h"

#include "bmp.h"

#include "config.h"

#include "bitstream.h"  
#include "config.h"  
#include "mmask.h"    
#include "qrencode.h"        
#include "qrinput.h"  
#include "rscode.h"     
#include "mask.h"    
#include "mqrspec.h"  
#include "qrencode_inner.h"  
#include "qrspec.h"   
#include "split.h"


#ifdef __cplusplus  
extern "C"  
#endif  
int writeBMP( const char* string, const char *filename, char *errorinfo, const int pixel, const int level, const int fgcolor, const int bgcolor )
{
	BitMapFileHeader bmfh;
	BitMapInfoHeader bmih;
	QRcode* pQRC = NULL;
	unsigned int width, realwidth, bmpsize = 0;
 	unsigned char* pBmpData = NULL;

	if( NULL == string || NULL == filename || NULL == errorinfo )
	{
		if( errorinfo )
		{ 
			sprintf( errorinfo, "%s\n", "error:Empty Pointer" ); 
		}
		return -1;
	}

	if( pixel < 1 || pixel > 20 )
	{
		sprintf( errorinfo, "%s\n", "error:pixel should be between 1 and 20" ); 
		return -2;
	}

	if( level < 0 || level > 3 )
	{
		sprintf( errorinfo, "%s\n", "error:level should be between 0 and 4" ); 
		return -3;
	}

    if ( NULL == (pQRC = QRcode_encodeString(string, 0, level, QR_MODE_8, 1)) )
	{
		sprintf( errorinfo, "%s\n", "error:QRcode_encodeString" ); 
		return -4;
	}

	width = pQRC->width;
	realwidth = width * pixel * 3;
	if (realwidth % 4)
		realwidth = (realwidth / 4 + 1) * 4;
	bmpsize = realwidth * width * pixel;

	if ( NULL == (pBmpData = (unsigned char*)malloc(bmpsize)) )
	{
		sprintf( errorinfo, "%s\n", "error:malloc" ); 
		QRcode_free(pQRC);
		return -5;	 
	}
	 

	Padding_BmpHeader( &bmfh, &bmih, bmpsize, width, pixel );

	//memset(pBmpData, 0xff, bmpsize);
	if( Padding_BmpData( pQRC->data, pBmpData, width, realwidth, pixel, fgcolor, bgcolor ) < 0 )
	{
		sprintf( errorinfo, "%s\n", "error:Padding_BmpData" ); 
		free(pBmpData);
		QRcode_free(pQRC);
		return -6;
	}

	if( Write_BmpFile( &bmfh, &bmih, pBmpData, bmpsize, filename ) < 0 )
	{
		sprintf( errorinfo, "%s\n", "error:Write_BmpFile" ); 
		free(pBmpData);
		QRcode_free(pQRC);
		return -7;
	}
	
	if( pBmpData )
		free(pBmpData);
	if( pQRC )
		QRcode_free(pQRC);
	 
    return 0;
}


static void Padding_BmpHeader( BitMapFileHeader *bmfh, BitMapInfoHeader *bmih, const int bmfsize, const int width, const int pixel )
{
	//BitMapFileHeader
	memset( bmfh, 0x00, sizeof(BitMapFileHeader) );
	bmfh->bfType = 0x4d42;  // "Fixed String:BM"
	bmfh->bfSize = sizeof(BitMapFileHeader) + sizeof(BitMapInfoHeader) + bmfsize;
	bmfh->bfReserved1 = 0;
	bmfh->bfReserved2 = 0;
	bmfh->bfOffBits = sizeof(BitMapFileHeader) + sizeof(BitMapInfoHeader);

	//BitMapInfoHeader
	memset( bmih, 0x00, sizeof(BitMapInfoHeader) );
	bmih->biSize = sizeof(BitMapInfoHeader);
	bmih->biWidth = width*pixel;
	//bmih->biHeight = -(width*pixel);//当前的负值导致程序不能self-adaption
	bmih->biHeight = width*pixel;
	bmih->biPlanes = 1;
	bmih->biBitCount = 24;
	bmih->biCompression = 0;
	bmih->biSizeImage = bmfsize;
	bmih->biXPelsPerMeter = 0;
	bmih->biYPelsPerMeter = 0;
	bmih->biClrUsed = 0;
	bmih->biClrImportant = 0;
}


static int Padding_BmpData( unsigned char *qrdata, unsigned char *bmpdata, const int width, const int realwidth, const int pixel, const int fgcolor, const int bgcolor )
{
	
	int i= 0;
	int j= 0;
	int k= 0;
	int n= 0;

	int fgred= 0;
	int fggreen= 0;
	int fgblue = 0;

	int bgred= 0;
	int bggreen= 0;
	int bgblue = 0;

	if( Search_ColorTable( fgcolor, &fgred, &fggreen, &fgblue ) < 0 )
		return -1;


	if( Search_ColorTable( bgcolor, &bgred, &bggreen, &bgblue ) < 0 )
		return -1;

	//这里需要修改下
	//如果biHeight为负,则位图为从上到下存储。
	//设置biHeight为正,则从下到上存储
	for( i = width-1; i >= 0 ; i-- )
	{
		unsigned char *p = bmpdata + realwidth * i * pixel;
		for( j = width; j > 0 ; j-- )
		{
			if ( *qrdata & 1 )
			{//foreground color
				for( k= 0; k < pixel; k++ )
				{
					for( n = 0; n < pixel; n++ )
					{
						*( p + n * 3 + realwidth * k ) =  fgred;
						*( p + n * 3 + realwidth * k + 1 ) =  fggreen;
						*( p + n * 3 + realwidth * k + 2 ) =  fgblue;
					}
				}
			} else {//background color
				for( k= 0; k < pixel; k++ )
				{
					for( n = 0; n < pixel; n++ )
					{
						*( p + n * 3 + realwidth * k ) =  bgred;
						*( p + n * 3 + realwidth * k + 1 ) =  bggreen;
						*( p + n * 3 + realwidth * k + 2 ) =  bgblue;
					}
				}						
			}
			p += 3 * pixel;
			qrdata++;
		}
	}

	return 0;
}


static int Write_BmpFile( BitMapFileHeader *bmfh, BitMapInfoHeader *bmih, unsigned char *bmpdata, const int bmpsize, const char*filename )
{
	FILE *fp = fopen( filename, "wb" );
	if( NULL != fp )
	{
		fwrite( bmfh, sizeof(BitMapFileHeader), 1, fp );
		fwrite( bmih, sizeof(BitMapInfoHeader), 1, fp );
		fwrite( bmpdata, sizeof(unsigned char), bmpsize, fp );		 
	} else {
		return -1; 
	}
	fclose( fp );	
	
	return 0;
}


static int Search_ColorTable( const int colorindex, int *red, int *green, int *blue )
{
	if( colorindex >= COLOR_SUM )
		return -1;

	*blue = COLOR_TABLE[colorindex][0];
	*green = COLOR_TABLE[colorindex][1];
	*red = COLOR_TABLE[colorindex][2];

	//printf( "%d:%x %x %x\n", colorindex, *red, *green, *blue );

	return 0;
}



