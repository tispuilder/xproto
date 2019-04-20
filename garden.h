/*
 * The MIT License
 *
 * Copyright 2019 XueQin.
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
 * File:   garden.h
 * Author: qinxue
 *
 * Created on April 20, 2019, 3:02 PM
 */

#ifndef GARDEN_H
#define GARDEN_H

#define SENSOR_DS3231 0x1  //时间 YYMMDDHHmmss WW
#define SENSOR_BH1750FVI 0x2 //光照
#define SENSOR_DHT22 0x3 //温湿度
#define SENSOR_ML8511 0x4 //紫外线
#define SENSOR_AD_SOILHUMITY 0x5 //土壤湿度

#define CONTROL_PWM_PLANTLIGHT 0x1
#define CONTROL_PWM_NORMALLIGHT 0x2
#define CONTROL_HUMITY 0x3
#define CONTROL_PWM_UV 0x4
#define CONTROL_PWM_HEAT 0x5
#define CONTROL_FAN 0x6
#define CONTROL_PUMP 0x7


#define DATA_TYPE_UINT8 0x1
#define DATA_TYPE_INT32 0x2
#define DATA_TYPE_UINT32 0x3
#define DATA_TYPE_FLOAT32 0x4


#define I2C_NONE 0x0
#define I2C_QUERY_SENSORS 0x1
#define I2C_QUERY_CONTROLS 0x2
#define I2C_QUERY_ACTIONS 0x3


typedef struct {
  float temperature;
  float humidity;
  float uv;
  float soilHumidity;
} ARDUINO_SENSOR_TABLE;

typedef struct {
  float illuminance;
  uint8_t year;
  uint8_t month;
  uint8_t day;
  uint8_t week;
  uint8_t hour;
  uint8_t minute;
  uint8_t second;
} ESP_SENSOR_TABLE;

typedef struct {
    uint8_t mask; //ABCD-EFGH  PWM0 PWM1 HEAT0 UV PUMP FAN CUST0 CUST1 
    uint pwm_light0; //Plant light
    uint pwm_light1; //normal light   
    uint pwm_heat0;
    uint pwm_uv;    
} ARDUINO_CONTROL_TABLE;

typedef struct {
    uint8_t mask;
    float float_value;
    uint  uint_value;
    int   int_value;
} ARDUINO_ACTION;

typedef struct {
    uint8_t query;
    typedef union {
        ARDUINO_SENSOR_TABLE sensors;
        ARDUINO_CONTROL_TABLE controls;
        ARDUINO_ACTION action;
    } body;
} ARDUINO_RESPONSE;



#endif /* GARDEN_H */

