// https://xn--18-6kcdusowgbt1a4b.xn--p1ai/%D0%BF%D0%BE%D0%B4%D0%BA%D0%BB%D1%8E%D1%87%D0%B5%D0%BD%D0%B8%D0%B5-%D0%BF%D0%BE%D1%82%D0%B5%D0%BD%D1%86%D0%B8%D0%BE%D0%BC%D0%B5%D1%82%D1%80%D0%B0-%D0%B0%D1%80%D0%B4%D1%83%D0%B8%D0%BD%D0%BE/

#define LASER             10  // Порт к которому подключен лазерный диод
#define VARIABLE_RESISTOR A1  // Порт к которому подключен потенциометр

int SensorValue = 0;          // Переменная для хранения показаний потенциометра

void setup()
{
  Serial.begin(9600);         // открыть терминал для отслеживания значения на аналоговом входе (CTRL + SHIFT + M) - *МониторПорта
  
  pinMode(LASER, OUTPUT);     // инициализируем Pin10 как выход
  pinMode(A1, INPUT);         // инициируем А1 как вход
}

void loop()
{
  SensorValue = analogRead(VARIABLE_RESISTOR);        // считываем данные с порта A1
  Serial.print("Analog input state (on variable resistor) = " );
  Serial.println(SensorValue);
  SensorValue = SensorValue / 4;                      // 0...255
  analogWrite(LASER, SensorValue);                    // меняем яркость LD
  delay(250);                                         // задержка, для спокойного отслеживания в мониторе
}
