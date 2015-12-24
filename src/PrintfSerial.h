/**
 * Project:     PrintfSerial Library
 * Description: PrintfSerial library for Arduino
 * Version:     v1.0
 * Author:      Kompanets Konstantin (aka I2M)
 */

#ifndef PRINTFSERIAL_H
#define PRINTFSERIAL_H

#include "Arduino.h"
#include <SoftwareSerial.h>

#define BUFFER_SIZE    128

class PrintfSerial : public SoftwareSerial {
public:
  PrintfSerial(uint8_t receive_pin, uint8_t transmit_pin, bool inverse_logic = false);
  void printf(char *format, ...);
  void printf(const __FlashStringHelper *format, ...);
};

#endif
