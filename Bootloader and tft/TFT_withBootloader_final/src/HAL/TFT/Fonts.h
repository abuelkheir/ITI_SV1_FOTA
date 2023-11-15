/*
 * Fonts.h
 *
 *  Created on: Sep 22, 2023
 *      Author: mayke
 */

#ifndef FONTS_H_
#define FONTS_H_

typedef volatile struct {
    const u8 width;
    u8 height;
    const u16 *data;
} FontDef;


FontDef Font_7x10;
FontDef Font_11x18;
FontDef Font_16x26;




#endif /* FONTS_H_ */
