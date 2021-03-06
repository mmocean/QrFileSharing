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
1 白色 #FFFFFF 2 红色 #FF0000 3 绿色 #00FF00 
4 蓝色 #0000FF 5 牡丹红 #FF00FF 6 青色 #00FFFF 
7 黄色 #FFFF00 8 黑色 #000000 9 海蓝 #70DB93 
10 巧克力色 #5C3317 11 蓝紫色 #9F5F9F 12 黄铜色 #B5A642 
13 亮金色 #D9D919 14 棕色 #A67D3D 15 青铜色 #8C7853 
16 2号青铜色 #A67D3D 17 士官服蓝色 #5F9F9F 18 冷铜色 #D98719 
19 铜色 #B87333 20 珊瑚红 #FF7F00 21 紫蓝色 #42426F 
22 深棕 #5C4033 23 深绿 #2F4F2F 24 深铜绿色 #4A766E 
25 深橄榄绿 #4F4F2F 26 深兰花色 #9932CD 27 深紫色 #871F78 
28 深石板蓝 #6B238E 29 深铅灰色 #2F4F4F 30 深棕褐色 #97694F 
32 深绿松石色 #7093DB 33 暗木色 #855E42 34 淡灰色 #545454 
35 土灰玫瑰红色#856363 36 长石色 #D19275 37 火砖色 #8E2323 
38 森林绿 #238E23 39 金色 #CD7F32 40 鲜黄色 #DBDB70 
41 灰色 #C0C0C0 42 铜绿色 #527F76 43 青黄色 #93DB70 
44 猎人绿 #215E21 45 印度红 #4E2F2F 46 土黄色 #9F9F5F 
47 浅蓝色 #C0D9D9 48 浅灰色 #A8A8A8 49 浅钢蓝色 #8F8FBD 
59 浅木色 #E9C2A6 60 石灰绿色 #32CD32 61 桔黄色 #E47833 
62 褐红色 #8E236B 63 中海蓝色 #32CD99 64 中蓝色 #3232CD 
65 中森林绿 #6B8E23 66 中鲜黄色 #EAEAAE 67 中兰花色 #9370DB 
68 中海绿色 #426F42 69 中石板蓝色 #7F00FF 70 中春绿色 #7FFF00 
71 中绿松石色 #70DBDB 72 中紫红色 #DB7093 73 中木色 #A68064 
74 深藏青色 #2F2F4F 75 海军蓝 #23238E 76 霓虹篮 #4D4DFF 
77 霓虹粉红 #FF6EC7 78 新深藏青色 #00009C 79 新棕褐色 #EBC79E 
80 暗金黄色 #CFB53B 81 橙色 #FF7F00 82 橙红色 #FF2400 
83 淡紫色 #DB70DB 84 浅绿色 #8FBC8F 85 粉红色 #BC8F8F 
86 李子色 #EAADEA 87 石英色 #D9D9F3 88 艳蓝色 #5959AB 
89 鲑鱼色 #6F4242 90 猩红色 #BC1717 91 海绿色 #238E68 
92 半甜巧克力色#6B4226 93 赭色 #8E6B23 94 银色 #E6E8FA 
95 天蓝 #3299CC 96 石板蓝 #007FFF 97 艳粉红色 #FF1CAE 
98 春绿色 #00FF7F 99 钢蓝色 #236B8E 100 亮天蓝色 #38B0DE 
101 棕褐色 #DB9370 102 紫红色 #D8BFD8 103 石板蓝色 #ADEAEA 
104 浓深棕色 #5C4033 105 淡浅灰色 #CDCDCD 106 紫罗兰色 #4F2F4F 
107 紫罗兰红色 #CC3299 108 麦黄色 #D8D8BF 109 黄绿色 #99CC
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

2.二维码纠错级别 LMQH 
3.二维码大小:1-40
4.前景色,背景色
传入字符串,传出生成的二维码文件路径
5.大小写是否敏感 - 默认应该是敏感的
传递错信息error
 casesensitive case-sensitive(1) or not(0).
*/


#endif /* __BMP_H__ */
