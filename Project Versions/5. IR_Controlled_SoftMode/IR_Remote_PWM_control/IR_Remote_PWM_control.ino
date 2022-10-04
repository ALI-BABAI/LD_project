// !!! https://arduino.ru/Reference/AnalogWrite
// https://arduino-tex.ru/news/33/ky-008-lazernyi-modul-podklyuchenie-k-arduino.html
// https://xn--18-6kcdusowgbt1a4b.xn--p1ai/%D0%BB%D0%B0%D0%B7%D0%B5%D1%80%D0%BD%D1%8B%D0%B9-%D0%BC%D0%BE%D0%B4%D1%83%D0%BB%D1%8C-%D0%B0%D1%80%D0%B4%D1%83%D0%B8%D0%BD%D0%BE/

/* ПОВТОР ТЕОРИИ
// Порт для включения лазерного светодиода можно менять
// !!! но только на аналоговый выход с поддержкой ШИМ     // другие порты горят статично (на ЛД высокий(5В) и низкий(0В) уровни только)

// Уменьшая задержку (DELAY_LD) и аналоговый итератор (ANALOG_ITERATOR) будет мигать быстрее, вплоть до неотличимого мигания

// Выдает аналоговую величину (ШИМ волну) на порт вход/выхода.
// Функция может быть полезна для управления яркостью подключенного светодиода или скоростью электродвигателя.
// После вызова analogWrite() на выходе будет генерироваться постоянная прямоугольная волна с заданной шириной импульса до следующего вызова analogWrite
// (или вызова digitalWrite или digitalRead на том же порту вход/выхода). Частота ШИМ сигнала приблизительно 490 Hz
*/

#include "IRremote.h"             // библиотека для ИК-модуля
#include "stdint.h"
#include "IR_OnOff_LD.h"          // библиотека с информацией о МК

#define LASER        10           // Порт к которому подключен лазерный диод
#define IR_MODULE    5            // Порт к которому подключен ИК-приёмник

#define RIGHT        0xFF5AA5     // Код команды пульта:
#define LEFT         0xFF10EF     // Код команды пульта:
#define UP           0xFF18E7     // Код команды пульта:
#define DOWN         0xFF4AB5     // Код команды пульта: 
#define OK           0xFF38C7     // Код команды пульта: ВКЛ/ВЫКЛ лазера

IRrecv irrecv(IR_MODULE);         // Обозначаем вывод, к которому подключен приемник
decode_results results;           // задаём переменную, в которую летят коды от пульта

bool START = 0;                   // Состояние лазера (изначально выкл)
uint8_t DELAY_LD        = 1;      // управление скоростью включения/выключения
uint8_t ANALOG_ITERATOR = 100;    // 0...255

void setup()
{
  pinMode(LASER, OUTPUT);         // инициализируем Pin10 как выход
  Serial.begin(9600);             // включение монитора порта (CTRL+SHIFT+M)
  dumpArduinoIDE();               // выводит активную версию софта
  dumpPlatform();                 // выводит тип МК
  dumpClock();                    // выводит частоту микроконтроллера в монитор порта

  irrecv.enableIRIn();            // запускаем приёмник IR
  Serial.println("Enabled IRin"); // сигнал о готовности модуля ИК-приёмника
}

void loop()
{
  if (irrecv.decode(&results))
  {
    Serial.print("Received command = 0x");
    Serial.println(results.value, HEX); // выводим полученные данные на монитор порта
    switch (results.value)              // обработка полученной команды
    {
      case RIGHT:
        DELAY_LD++;
        break;
      case LEFT:
        if(DELAY_LD == 0)
          NOP;
        else 
          DELAY_LD--;
        break;
      case UP:
        if(ANALOG_ITERATOR == 255)
          NOP;
        else
          ANALOG_ITERATOR++;
        break;
      case DOWN:
        if(ANALOG_ITERATOR == 0)
          NOP;
        else
          ANALOG_ITERATOR--;
        break;
      case OK:
        START = !START;                 // лазер меняет своё состояние (ВКЛ/ВЫКЛ)
        break;
      default:
        digitalWrite(LASER, LOW);
        break;
    }
  }
  if (START)
  {
    analogWrite(LASER, ANALOG_ITERATOR);
    delay(DELAY_LD);
    irrecv.resume();
    if (irrecv.decode(&results))
      START = 0;
  }
  irrecv.resume(); // Ждем следующее значение от пульта ДУ
}
