/**
 * Project:     PrintfSerial Library
 * Description: PrintfSerial library for Arduino
 * Version:     v1.0
 * Author:      Kompanets Konstantin (aka I2M)
 */

#include "PrintfSerial.h"

PrintfSerial::PrintfSerial(uint8_t receive_pin, uint8_t transmit_pin, bool inverse_logic) :
  SoftwareSerial(receive_pin, transmit_pin, inverse_logic) {
}

void PrintfSerial::printf(char *format, ...) {
  char buffer[BUFFER_SIZE];
  va_list ap;
  va_start(ap, format);
  vsnprintf(buffer, sizeof(buffer), format, ap);
  va_end(ap);
  uint8_t *s = (uint8_t *)&buffer;
  while (*s) write(*s++);
}

void PrintfSerial::printf(const __FlashStringHelper *format, ...) {
  char buffer[BUFFER_SIZE];
  va_list ap;
  va_start (ap, format);
  vsnprintf_P(buffer, sizeof(buffer), (const char *)format, ap);
  va_end(ap);
  uint8_t *s = (uint8_t *)&buffer;
  while (*s) write(*s++);
}
