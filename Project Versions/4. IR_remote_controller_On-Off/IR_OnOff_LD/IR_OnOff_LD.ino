// https://arduino-tex.ru/news/33/ky-008-lazernyi-modul-podklyuchenie-k-arduino.html
// https://xn--18-6kcdusowgbt1a4b.xn--p1ai/%D0%BB%D0%B0%D0%B7%D0%B5%D1%80%D0%BD%D1%8B%D0%B9-%D0%BC%D0%BE%D0%B4%D1%83%D0%BB%D1%8C-%D0%B0%D1%80%D0%B4%D1%83%D0%B8%D0%BD%D0%BE/

// Форма сигнала близка к меандру. Разумеется есть некоторый "скос"/"время установки"
// Лазерный диод мигает с частатой, заданной N миллисекунд:
// delay(N);

#include "IRremote.h"             // библиотека для ИК-модуля
#include "stdint.h"
#include "IR_OnOff_LD.h"          // библиотека с информацией о МК

#define LASER        10           // Порт к которому подключен лазерный диод
#define IR_MODULE    5            // Порт к которому подключен ИК-приёмник

#define RIGHT        0xFF5AA5     // Код команды пульта
#define LEFT         0xFF10EF     // Код команды пульта
#define UP           0xFF18E7     // Код команды пульта: ВКЛ лазера
#define DOWN         0xFF4AB5     // Код команды пульта: ВЫКЛ лазера

IRrecv irrecv(IR_MODULE);         // Обозначаем вывод, к которому подключен приемник
decode_results results;           // задаём переменную, в которую летят коды от пульта


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
        break;
      case LEFT:
        break;
      case UP:
        digitalWrite(LASER, HIGH);
        break;
      case DOWN:
        digitalWrite(LASER, LOW);
        break;
      default:
        digitalWrite(LASER, LOW);
        break;
    }
  }
  irrecv.resume(); // Ждем следующее значение от пульта ДУ
}
