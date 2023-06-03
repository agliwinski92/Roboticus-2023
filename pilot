#include <IRremote.h>
#define irPin 11
IRrecv irrecv(irPin);
decode_results results;
#define silnik_prawy 5		// pin sterowania silnikiem
#define silnik_lewy 6 		// pin sterowania silnikiem

void setup() {
   Serial.begin(9600);
   irrecv.enableIRIn();
}

void loop() {
   if (irrecv.decode(&results)) {

      switch (results.value) {
         case 0x143226DB:
            Serial.println("w lewo");
            break;

         case 0xE0984BB6:
            Serial.println("w gore");
            break;

         case 0x39D41DC6:
            Serial.println("w prawo");
            break;

         case 0x371A3C86:
            Serial.println("w dol");
            break;

         case 0xA32AB931:
            Serial.println("srodek");
            break;
         }

   irrecv.resume();
   }
}
