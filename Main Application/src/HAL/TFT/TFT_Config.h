/*
 * TFT_Config.h
 *
 *  Created on: ??�/??�/????
 *      Author: omara
 */

#ifndef HAL_TFT_TFT_CONFIG_H_
#define HAL_TFT_TFT_CONFIG_H_


#define PINA0     MGPIO_PIN0
#define PIN_RST   MGPIO_PIN1
#define TFT_PORT  MGPIOA_PORT

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x0400
#define LIME    0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

#define SWRESET 0x01 // software reset
#define SLPOUT 0x11 // sleep out
#define DISPOFF 0x28 // display off
#define DISPON 0x29 // display on
#define XSET 0x2A // column address set
#define YSET 0x2B // row address set
#define RAMWR 0x2C // RAM write
#define MADCTL 0x36 // axis control
#define COLMOD 0x3A // color mode

// 1.8" TFT display constants
#define XSIZE 128
#define YSIZE 160

#define XMAX XSIZE-1
#define YMAX YSIZE-1

#endif /* HAL_TFT_TFT_CONFIG_H_ */
