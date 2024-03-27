/**********************************************************************************/
/*                                                                                */
/*    Copyright (C) 2005 OLIMEX  LTD.                                             */
/*                                                                                */
/*    Module Name    :  LCD module                                                */
/*    File   Name    :  lcd.h                                                     */
/*    Revision       :  02.00                                                     */
/*    Date           :  2011/06/27 code clean-up                                  */
/*    Revision       :  01.00                                                     */
/*    Date           :  2006/01/26 initial version                                */
/*                                                                                */
/**********************************************************************************/
#ifndef _LCD_3310_H
#define _LCD_3310_H

#ifdef __cplusplus
 extern "C" {
#endif

/* definitions */
#define SEND_CMD                   0
#define SEND_CHR                   1

#define LCD_X_RES                  84
#define LCD_Y_RES                  48

#define PIXEL_OFF                  0
#define PIXEL_ON                   1
#define PIXEL_XOR                  2

#define FONT_1X                    1
#define FONT_2X                    2

// this is the buffer size
#define LCD_CACHE_SIZE             ((LCD_X_RES * LCD_Y_RES) / 8)



/****************************************************************************/
/*  Initialize LCD Controller                                               */
/*  Function : LCDInit                                                      */
/*      Parameters                                                          */
/*          Input   :  Nothing                                              */
/*          Output  :  Nothing                                              */
/****************************************************************************/
void LCDInit(void);

/****************************************************************************/
/*  Send to LCD                                                             */
/*  Function : LCDSend                                                      */
/*      Parameters                                                          */
/*          Input   :  data and  SEND_CHR or SEND_CMD                       */
/*          Output  :  Nothing                                              */
/****************************************************************************/
void LCDSend(unsigned char data, unsigned char cd);

/****************************************************************************/
/*  Update LCD memory                                                       */
/*  Function : LCDUpdate                                                    */
/*      Parameters                                                          */
/*          Input   :  Nothing                                              */
/*          Output  :  Nothing                                              */
/****************************************************************************/
void LCDUpdate ( void );

/****************************************************************************/
/*  Clear LCD                                                               */
/*  Function : LCDClear                                                     */
/*      Parameters                                                          */
/*          Input   :  Nothing                                              */
/*          Output  :  Nothing                                              */
/****************************************************************************/
void LCDClear(void);

/****************************************************************************/
/*  Change LCD Pixel mode                                                   */
/*  Function : LcdContrast                                                  */
/*      Parameters                                                          */
/*          Input   :  contrast                                             */
/*          Output  :  Nothing                                              */
/****************************************************************************/
void LCDPixel (unsigned char x, unsigned char y, unsigned char mode );

/****************************************************************************/
/*  Write char at x position on y row                                       */
/*  Function : LCDChrXY                                                     */
/*      Parameters                                                          */
/*          Input   :  position, row, char                                  */
/*          Output  :  Nothing                                              */
/****************************************************************************/
void LCDChrXY (unsigned char x, unsigned char y, unsigned char ch );

/****************************************************************************/
/*  Write char at x position on y row                                       */
/*  Function : LCDPixelXY                                                   */
/*      Parameters                                                          */
/*          Input   :  position, row                                        */
/*          Output  :  Nothing                                              */
/****************************************************************************/
void LCDPixelXY (unsigned char x, unsigned char y);

void LCDLine (int x1, int y1, int x2, int y2);
void LCDRectangle (int x1, int y1, int x2, int y2);
void LCDSolidRectangle (int x1, int y1, int x2, int y2);
void LCD4EllipsePoints (int CX, int CY, int X, int Y);
void LCDEllipse (int CX, int CY, int XRadius, int YRadius);
void LCDCircle (int x, int y, int r);
void LCDTriangle (int x1, int y1, int x2, int y2, int x3, int y3);

/****************************************************************************/
/*  Write char at x position on y row - inverse                             */
/*  Function : LCDChrXY                                                     */
/*      Parameters                                                          */
/*          Input   :  position, row, char                                  */
/*          Output  :  Nothing                                              */
/****************************************************************************/
void LCDChrXYInverse (unsigned char x, unsigned char y, unsigned char ch );
/****************************************************************************/
/*  Set LCD Contrast                                                        */
/*  Function : LcdContrast                                                  */
/*      Parameters                                                          */
/*          Input   :  contrast                                             */
/*          Output  :  Nothing                                              */
/****************************************************************************/
void LCDContrast(unsigned char contrast);

/****************************************************************************/
/*  Send string to LCD                                                      */
/*  Function : LCDStr                                                       */
/*      Parameters                                                          */
/*          Input   :  row, text, inversion                                 */
/*          Output  :  Nothing                                              */
/****************************************************************************/
void LCDStr(unsigned char row, const unsigned char *dataPtr, unsigned char inv);

void Delay(volatile unsigned long a);
void Delayc(volatile unsigned char a);

#ifdef __cplusplus
}
#endif

#endif // _LCD_3310_H


