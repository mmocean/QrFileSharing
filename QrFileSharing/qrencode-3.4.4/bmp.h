/*************************************************************************
	> File Name: bmp.h
	> Author: 
	> Mail: @163.com 
	> Created Time: Sun 22 Mar 2015 03:10:32 PM CST
 ************************************************************************/

#ifndef __BMP_H__
#define __BMP_H__

//refer to:http://www.cnblogs.com/kingmoon/archive/2011/04/18/2020097.html
#pragma pack(push, 2)
typedef struct {
	 short	bfType;	//2 bytes
	 int	bfSize;	//4 bytes
	 short  bfReserved1;
	 short  bfReserved2;
	 int	bfOffBits;
}BitMapFileHeader;

typedef struct {
	 int     biSize;
	 int     biWidth;
	 int     biHeight;
	 short   biPlanes;
	 short   biBitCount;
	 int     biCompression;
	 int     biSizeImage;
	 int     biXPelsPerMeter;
	 int     biYPelsPerMeter;
	 int     biClrUsed;
	 int     biClrImportant;
}BitMapInfoHeader;

#pragma pack(pop)


/*
1 ��ɫ #FFFFFF 2 ��ɫ #FF0000 3 ��ɫ #00FF00 
4 ��ɫ #0000FF 5 ĵ���� #FF00FF 6 ��ɫ #00FFFF 
7 ��ɫ #FFFF00 8 ��ɫ #000000 9 ���� #70DB93 
10 �ɿ���ɫ #5C3317 11 ����ɫ #9F5F9F 12 ��ͭɫ #B5A642 
13 ����ɫ #D9D919 14 ��ɫ #A67D3D 15 ��ͭɫ #8C7853 
16 2����ͭɫ #A67D3D 17 ʿ�ٷ���ɫ #5F9F9F 18 ��ͭɫ #D98719 
19 ͭɫ #B87333 20 ɺ���� #FF7F00 21 ����ɫ #42426F 
22 ���� #5C4033 23 ���� #2F4F2F 24 ��ͭ��ɫ #4A766E 
25 ������� #4F4F2F 26 ������ɫ #9932CD 27 ����ɫ #871F78 
28 ��ʯ���� #6B238E 29 ��Ǧ��ɫ #2F4F4F 30 ���غ�ɫ #97694F 
32 ������ʯɫ #7093DB 33 ��ľɫ #855E42 34 ����ɫ #545454 
35 ����õ���ɫ#856363 36 ��ʯɫ #D19275 37 ��שɫ #8E2323 
38 ɭ���� #238E23 39 ��ɫ #CD7F32 40 �ʻ�ɫ #DBDB70 
41 ��ɫ #C0C0C0 42 ͭ��ɫ #527F76 43 ���ɫ #93DB70 
44 ������ #215E21 45 ӡ�Ⱥ� #4E2F2F 46 ����ɫ #9F9F5F 
47 ǳ��ɫ #C0D9D9 48 ǳ��ɫ #A8A8A8 49 ǳ����ɫ #8F8FBD 
59 ǳľɫ #E9C2A6 60 ʯ����ɫ #32CD32 61 �ۻ�ɫ #E47833 
62 �ֺ�ɫ #8E236B 63 �к���ɫ #32CD99 64 ����ɫ #3232CD 
65 ��ɭ���� #6B8E23 66 ���ʻ�ɫ #EAEAAE 67 ������ɫ #9370DB 
68 �к���ɫ #426F42 69 ��ʯ����ɫ #7F00FF 70 �д���ɫ #7FFF00 
71 ������ʯɫ #70DBDB 72 ���Ϻ�ɫ #DB7093 73 ��ľɫ #A68064 
74 �����ɫ #2F2F4F 75 ������ #23238E 76 �޺��� #4D4DFF 
77 �޺�ۺ� #FF6EC7 78 �������ɫ #00009C 79 ���غ�ɫ #EBC79E 
80 �����ɫ #CFB53B 81 ��ɫ #FF7F00 82 �Ⱥ�ɫ #FF2400 
83 ����ɫ #DB70DB 84 ǳ��ɫ #8FBC8F 85 �ۺ�ɫ #BC8F8F 
86 ����ɫ #EAADEA 87 ʯӢɫ #D9D9F3 88 ����ɫ #5959AB 
89 ����ɫ #6F4242 90 �ɺ�ɫ #BC1717 91 ����ɫ #238E68 
92 �����ɿ���ɫ#6B4226 93 ��ɫ #8E6B23 94 ��ɫ #E6E8FA 
95 ���� #3299CC 96 ʯ���� #007FFF 97 �޷ۺ�ɫ #FF1CAE 
98 ����ɫ #00FF7F 99 ����ɫ #236B8E 100 ������ɫ #38B0DE 
101 �غ�ɫ #DB9370 102 �Ϻ�ɫ #D8BFD8 103 ʯ����ɫ #ADEAEA 
104 Ũ����ɫ #5C4033 105 ��ǳ��ɫ #CDCDCD 106 ������ɫ #4F2F4F 
107 ��������ɫ #CC3299 108 ���ɫ #D8D8BF 109 ����ɫ #99CC
*/


/*do not modify this order.*/
enum {
	COLOR_WHITE = 0,	
	COLOR_RED,	
	COLOR_GREEN,	
	COLOR_BLUE,
	COLOR_BLACK,
	/*if necessary add other indexes here*/
	COLOR_SUM
};

static unsigned char COLOR_TABLE[COLOR_SUM][3] = {
	{0xFF,0xFF,0xFF},	/*COLOR_WHITE*/
	{0xFF,0x00,0x00},	/*COLOR_RED*/
	{0x00,0xFF,0x00},	/*COLOR_GREEN*/
	{0x00,0x00,0xFF},	/*COLOR_BLUE*/
	{0x00,0x00,0x00}	/*COLOR_BLACK*/
	/*if necessary add the value of other colors here*/
};


static void Padding_BmpHeader( BitMapFileHeader *bmfh, BitMapInfoHeader *bmih, const int bmfsize, const int width, const int pixel );

static int Search_ColorTable( const int colorindex, int *red, int *green, int *blue );

static int Padding_BmpData( unsigned char *qrdata, unsigned char *bmpdata, const int width, const int realwidth, const int pixel, const int fgcolor, const int bgcolor );

static int Write_BmpFile( BitMapFileHeader *bmfh, BitMapInfoHeader *bmih, unsigned char *bmpdata, const int bmpsize, const char*filename );

#ifdef __cplusplus  
extern "C"  
#endif  
int writeBMP( const char* string, const char *filename, char *errorinfo, const int pixel, const int level, const int fgcolor, const int bgcolor );


/*

2.��ά������� LMQH 
3.��ά���С:1-40
4.ǰ��ɫ,����ɫ
�����ַ���,�������ɵĶ�ά���ļ�·��
5.��Сд�Ƿ����� - Ĭ��Ӧ�������е�
���ݴ���Ϣerror
 casesensitive case-sensitive(1) or not(0).
*/


#endif /* __BMP_H__ */
