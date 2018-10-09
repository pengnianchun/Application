/* 
 * File:   LOGH.h
 * Author: mpszm
 *
 * Created on 2016年8月4日, 下午4:49
 */

#ifndef LOGO_H
#define	LOGO_H

const unsigned char BMP_LOGO[]=
{
/*------------------------------------------------------------------------------
;  若数据乱码，请检查字模格式设置，注意选择正确的取模方向和字节位顺序。
;  源文件 / 文字 : E:\HFMZKJ\MZKJProgram\SHFY\MUIC\BSP.X\src\test\TEST\bmp\金龙图标.bmp字模
;  宽×高（像素）: 64×40
;  字模格式/大小 : 单色点阵液晶字模，横向取模，字节正序/320字节
;  数据转换日期  : 2016-8-4 16:48:07
------------------------------------------------------------------------------*/
0x28,0x08,//高的像素数，宽的字节数，参数设置可选
0x00,0x00,0x07,0xFF,0xFF,0xC0,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xF8,0x00,0x00,
0x00,0x03,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x0F,0xFE,0x00,0x00,0xFF,0xE0,0x00,
0x00,0x3F,0xE0,0x00,0x00,0x0F,0xF8,0x00,0x00,0x7F,0x80,0x00,0x00,0x01,0xFC,0x00,
0x01,0xFC,0x00,0x00,0x00,0x00,0x7F,0x00,0x03,0xF8,0x00,0x00,0x00,0x00,0x3F,0x80,
0x07,0xE0,0x00,0xFF,0xFE,0x00,0x0F,0xC0,0x0F,0xC0,0x01,0xFF,0xFC,0x00,0x07,0xE0,
0x1F,0x80,0x03,0xFF,0xF8,0x00,0x03,0xF0,0x3F,0x00,0x0F,0xFF,0xF0,0x00,0x01,0xF8,
0x3E,0x00,0x1F,0xFF,0xC0,0x00,0x00,0xFC,0x7E,0x00,0x3F,0xFF,0x80,0x00,0x00,0x7C,
0xFC,0x00,0x7F,0xFF,0x00,0x00,0x00,0x7E,0xF8,0x01,0xFF,0xFE,0x00,0x00,0x00,0x3E,
0xF8,0x03,0xFF,0xF8,0x00,0x00,0x00,0x3E,0xF8,0x07,0xFF,0xF0,0x00,0x00,0x00,0x3E,
0xF8,0x0F,0xFF,0xFF,0xFE,0x00,0x00,0x3F,0xF8,0x07,0xFF,0xFF,0xFF,0x80,0x00,0x3F,
0xF8,0x00,0x00,0x3F,0xFF,0xE0,0x00,0x3F,0xF8,0x00,0x00,0x0F,0xFF,0xF0,0x00,0x3E,
0xF8,0x00,0x00,0x07,0xFF,0xF8,0x00,0x3E,0xF8,0x00,0x00,0x01,0xFF,0xFC,0x00,0x3E,
0xFC,0x00,0x00,0x00,0xFF,0xFE,0x00,0x7E,0x7C,0x00,0x00,0x00,0x7F,0xFF,0x80,0x7C,
0x7E,0x00,0x00,0x00,0x3F,0xFF,0xC0,0xFC,0x3F,0x00,0x00,0x00,0x0F,0xFF,0xE1,0xF8,
0x1F,0x80,0x00,0x00,0x07,0xFF,0xFB,0xF0,0x0F,0xC0,0x00,0x00,0x03,0xFF,0xFF,0xE0,
0x07,0xE0,0x00,0x00,0x01,0xFF,0xFF,0xC0,0x03,0xF8,0x00,0x00,0x00,0x7F,0xFF,0x80,
0x01,0xFC,0x00,0x00,0x00,0x3F,0xFF,0x00,0x00,0xFF,0x00,0x00,0x00,0x1F,0xFE,0x00,
0x00,0x3F,0xE0,0x00,0x00,0x1F,0xF8,0x00,0x00,0x0F,0xFE,0x00,0x00,0xFF,0xE0,0x00,
0x00,0x03,0xFF,0xFF,0xFF,0xFF,0x80,0x00,0x00,0x00,0x7F,0xFF,0xFF,0xFC,0x00,0x00,
0x00,0x00,0x07,0xFF,0xFF,0xC0,0x00,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0x00,0x00,
};


#endif	/* LOGO_H */

