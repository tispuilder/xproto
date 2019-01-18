/*
 * The MIT License
 *
 * Copyright 2019 qinxue.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/* 
 * File:   XNetProto.cpp
 * Author: qinxue
 * 
 * Created on January 18, 2019, 9:21 PM
 */

#include "XNetProto.h"


XNetProto::XNetProto() {
}

XNetProto::~XNetProto() {
}

void XNetProto::convRaw2Hex(char* dst, const uint8_t* src, int len) {
    static const char hexchars[] = "0123456789ABCDEF";
    int index = 0;
    for (int i = 0; i < len; i++) {
        uint8_t raw = src[i];
        dst[index++] = hexchars[(src[i] >> 4) & 0x0F];
        dst[index++] = hexchars[src[i] & 0x0F];
    }
    dst[index] = 0;
}

char toupper(char c) {
    if(c - 'a' >=0 && 'f' - c >= 0) {
        return 'A' + (c - 'a');
    }
    return c;
}
void XNetProto::convHex2Raw(uint8_t* dst, const char* src, int len) {
    short i;
    uint8_t highByte, lowByte;

    for (i = 0; i < len; i += 2) {
        highByte = toupper(src[i]);
        lowByte = toupper(src[i + 1]);

        if (highByte > 0x39)
            highByte -= 0x37;
        else
            highByte -= 0x30;

        if (lowByte > 0x39)
            lowByte -= 0x37;
        else
            lowByte -= 0x30;

        dst[i / 2] = (highByte << 4) | lowByte;
    }
}