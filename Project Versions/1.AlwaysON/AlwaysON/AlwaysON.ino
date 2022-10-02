// https://arduino-tex.ru/news/33/ky-008-lazernyi-modul-podklyuchenie-k-arduino.html
// https://xn--18-6kcdusowgbt1a4b.xn--p1ai/%D0%BB%D0%B0%D0%B7%D0%B5%D1%80%D0%BD%D1%8B%D0%B9-%D0%BC%D0%BE%D0%B4%D1%83%D0%BB%D1%8C-%D0%B0%D1%80%D0%B4%D1%83%D0%B8%D0%BD%D0%BE/

// При включение ЛД горит, затем гаснет на пару секунд - после снова горит.
// Возможно это из-за конденсаторов --> точно из-за них!
// (Us)|(U-) == 4V

#define LASER             10  // Порт к которому подключен лазерный диод

void setup()
{
  pinMode(LASER, OUTPUT);     // инициализируем Pin10 как выход
}

void loop()
{
  digitalWrite(LASER, HIGH);  // постоянный высокий уровень на лазерном диоде
}
