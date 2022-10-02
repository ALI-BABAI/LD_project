

#define NOP __asm__("nop")

void dumpClock() {
#if defined(F_CPU)
    Serial.print(F("MCU Clock: "));
    Serial.println(F_CPU);
#endif
}

void dumpArduinoIDE() {
    Serial.print(F("Arduino IDE version: "));
    Serial.print(ARDUINO / 10000);
    Serial.write('.');
    Serial.print((ARDUINO % 10000) / 100);
    Serial.write('.');
    Serial.println(ARDUINO % 100);
}
void dumpPlatform() {
    Serial.print(F("MCU Platform: "));

#if defined(__AVR_ATmega8__)
  Serial.println(F("Atmega8"));
#elif defined(__AVR_ATmega16__)
    Serial.println(F("ATmega16"));
#elif defined(__AVR_ATmega32__)
  Serial.println(F("ATmega32"));
#elif defined(__AVR_ATmega32U4__)
  Serial.println(F("Arduino Leonardo / Yun / Teensy 1.0 / ATmega32U4"));
#elif defined(__AVR_ATmega48__) || defined(__AVR_ATmega48P__)
  Serial.println(F("ATmega48"));
#elif defined(__AVR_ATmega64__)
  Serial.println(F("ATmega64"));
#elif defined(__AVR_ATmega88__) || defined(__AVR_ATmega88P__)
  Serial.println(F("ATmega88"));
#elif defined(__AVR_ATmega162__)
  Serial.println(F("ATmega162"));
#elif defined(__AVR_ATmega164A__) || defined(__AVR_ATmega164P__)
  Serial.println(F("ATmega164"));
#elif defined(__AVR_ATmega324P__) || defined(__AVR_ATmega324A__) || defined(__AVR_ATmega324PA__)
  Serial.println(F("ATmega324"));

#elif defined(__AVR_ATmega644__) || defined(__AVR_ATmega644P__)
  Serial.println(F("ATmega644"));
#elif defined(__AVR_ATmega1280__)
  Serial.println(F("Arduino Mega1280"));
#elif defined(__AVR_ATmega1281__)
  Serial.println(F("ATmega1281"));
#elif defined(__AVR_ATmega1284__) || defined(__AVR_ATmega1284P__)
  Serial.println(F("ATmega1284"));
#elif defined(__AVR_ATmega2560__)
  Serial.println(F("Arduino Mega2560"));
#elif defined(__AVR_ATmega2561__)
  Serial.println(F("ATmega2561"));

#elif defined(__AVR_ATmega8515__)
  Serial.println(F("ATmega8515"));
#elif defined(__AVR_ATmega8535__)
  Serial.println(F("ATmega8535"));

#elif defined(__AVR_AT90USB162__)
  Serial.println(F("Teensy 1.0 / AT90USB162"));
  // Teensy 2.0
#elif defined(__MK20DX128__) || defined(__MK20DX256__)
  Serial.println(F("Teensy 3.0 / Teensy 3.1 / MK20DX128 / MK20DX256"));
#elif defined(__MKL26Z64__)
  Serial.println(F("Teensy-LC / MKL26Z64"));
#elif defined(__AVR_AT90USB646__)
  Serial.println(F("Teensy++ 1.0 / AT90USB646"));
#elif defined(__AVR_AT90USB1286__)
  Serial.println(F("Teensy++ 2.0 / AT90USB1286"));

#elif defined(__AVR_ATtiny84__)
  Serial.println(F("ATtiny84"));
#elif defined(__AVR_ATtiny85__)
  Serial.println(F("ATtiny85"));
#else
    Serial.println(F("ATmega328(P) / (Duemilanove, Diecimila, LilyPad, Mini, Micro, Fio, Nano, etc)"));
#endif
}

