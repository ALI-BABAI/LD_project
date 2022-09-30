#include "IRremote.h"
#include "stdint.h"

#define IR_MODULE 5   // задаем имя для Pin5
#define LASER     10  // задаем имя для Pin10
#define LED       12  // задаем имя для Pin12

#define IR_RIGHT 0xFF5AA5
#define IR_LEFT  0xFF10EF
#define IR_UP    0xFF18E7
#define IR_DOWN  0xFF4AB5

uint16_t delayTime = 100;

// decode_type_t decode_type;  // deprecated, moved to decodedIRData.protocol ///< UNKNOWN, NEC, SONY, RC5, ...

IRrecv irrecv(IR_MODULE); // указываем вывод, к которому подключен приемник
decode_results results;

void setup() {
  pinMode(LASER, OUTPUT); // инициализируем Pin10 как выход
  //pinMode(LED, OUTPUT);   // инициализируем Pin12 как выход

//  IrReceiver.begin(IR_MODULE);

  Serial.begin(9600);
  Serial.println("Enabling IRin");
  irrecv.enableIRIn();      // запускаем приёмник IR
  Serial.println("Enabled IRin");

  IrReceiver.begin(IR_MODULE);
}

void loop() {
  //// мигнёт 5 раз, затем пауза 100мсек
  //  for (int i=0; i<=5; i++) // мигание лазерным светодиодом
  //  {
  //   digitalWrite(LASER, HIGH);
  ////   digitalWrite(LED, HIGH);
  //   delay(1000);
  //   digitalWrite(LASER, LOW);
  ////   digitalWrite(LED, LOW);
  //   delay(delayTime000);
  //  }


  if (irrecv.decode(&results))
  {
    switch (results.value)
    {
      case IR_LEFT:
        digitalWrite(LASER, HIGH);
//      delay(10000);
        break;
      case IR_RIGHT:
        digitalWrite(LASER, LOW);
//      delay(10000);
        break;
      case IR_UP:
        delayTime += 100;
        break;
      case IR_DOWN:
        if (delayTime == 100)
         delayTime = 100;
        else
          delayTime -= 100;
        break;
      default:
        digitalWrite(LASER, LOW);
        break;
    }
  Serial.println(results.value, HEX);
    

  }
  irrecv.resume(); // Ждем следующее значение от пульта ДУ
  delay(delayTime);
//digitalWrite(LASER, !(digitalRead(LASER)));

// IRData* read();    // returns decoded data          // check it
// irrecv.decodeNEC();
// irrecv.decodeDistance();
// void initDecodedIRData();
// void printActiveIRProtocols();
// void printActiveIRProtocols(Print *aSerial);


 
}
