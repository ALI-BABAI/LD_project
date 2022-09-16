#define LASER 6 // задаем имя для Pin10

void setup() {
   pinMode(LASER, OUTPUT); // инициализируем Pin10 как выход
}

void loop() {
// мигнёт 5 раз, затем пауза 100мсек
for (int i=0; i<=5; i++) // мигание лазерным светодиодом
   {
      digitalWrite(LASER, HIGH);
      delay(1000);
      digitalWrite(LASER, LOW);
      delay(1000);
   }
   delay(15);
}
