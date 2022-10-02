// !!! https://arduino.ru/Reference/AnalogWrite
// https://arduino-tex.ru/news/33/ky-008-lazernyi-modul-podklyuchenie-k-arduino.html
// https://xn--18-6kcdusowgbt1a4b.xn--p1ai/%D0%BB%D0%B0%D0%B7%D0%B5%D1%80%D0%BD%D1%8B%D0%B9-%D0%BC%D0%BE%D0%B4%D1%83%D0%BB%D1%8C-%D0%B0%D1%80%D0%B4%D1%83%D0%B8%D0%BD%D0%BE/

// Порт для включения лазерного светодиода можно менять
// !!! но только на аналоговый выход с поддержкой ШИМ     // другие порты горят статично (на ЛД высокий(5В) и низкий(0В) уровни только)

// Уменьшая задержку (DELAY_LD) и аналоговый итератор (ANALOG_ITERATOR) будет мигать быстрее, вплоть до неотличимого мигания

// Выдает аналоговую величину (ШИМ волну) на порт вход/выхода.
// Функция может быть полезна для управления яркостью подключенного светодиода или скоростью электродвигателя.
// После вызова analogWrite() на выходе будет генерироваться постоянная прямоугольная волна с заданной шириной импульса до следующего вызова analogWrite
// (или вызова digitalWrite или digitalRead на том же порту вход/выхода). Частота ШИМ сигнала приблизительно 490 Hz.

#define DELAY_LD          10  // управление скоростью включения/выключения
#define ANALOG_ITERATOR   255 // 0...255

#define LASER             10  // Порт к которому подключен лазерный диод

void setup() 
{
   pinMode(LASER, OUTPUT);    // инициализируем Pin10 как выход
} 

void loop()
{
   for (int i=0; i<=ANALOG_ITERATOR; i++) // плавное включение лазера
   {
      analogWrite(LASER, i);
      delay(DELAY_LD);
   }
   for (int i=ANALOG_ITERATOR; i>=0; i--) //плавное выключение лазера
   {
      analogWrite(LASER, i);
      delay(DELAY_LD);
   }

//Яркость ЛД : напряжение зависит от Х (LASER, Х)
  analogWrite(LASER, 0);
  delay(1000);
  analogWrite(LASER, 100);
  delay(1000);
  analogWrite(LASER, 150);
  delay(1000);
  analogWrite(LASER, 200);
  delay(1000);
  analogWrite(LASER, 255);
  delay(1000);

  for (int i=0; i<10; i++)
  {
    analogWrite(LASER, 255);
    delay(1000);
    analogWrite(LASER, 100);
    delay(1000);
  }
}
