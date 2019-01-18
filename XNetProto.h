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
 * File:   XNetProto.h
 * Author: XueQin
 *
 * Created on January 18, 2019, 9:21 PM
 */

#ifndef XNETPROTO_H
#define XNETPROTO_H

#define ARDUINO_LED  0
#define ARDUINO_HEAT 1
#define ARDUINO_WATER 2
#define ARDUINO_SPRAY 3
typedef unsigned char uint8_t;
typedef struct {
    short year;
    short month;
    short day;
    short hour;
    short minute;
    
    short second;
    short week;
    float humidity;
    float temperature;
    float heatIndex;
    
    float illuminance;
    float uvIntensity;
    float soilHumidity;
} ARDUINO_WHITEBOARD;

typedef struct {
    unsigned char cmd;
    unsigned char length;    
    unsigned char body[256];
} ARDUINO_MESSAGE;

class XNetProto {
public:
    static void convRaw2Hex(char * dst, const uint8_t * src, int len);
    static void convHex2Raw(uint8_t * dst, const char * src, int len);
    
private:
    XNetProto();
    virtual ~XNetProto();

};

#endif /* XNETPROTO_H */

