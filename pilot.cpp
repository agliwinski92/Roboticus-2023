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
         case 0x10:
            digitalWrite(silnik_prawy, HIGH);
            digitalWrite(silnik_lewy, HIGH);
            break;

         case 0x16:
            digitalWrite(silnik_prawy, HIGH);
            break;

         case 0x15:
            digitalWrite(silnik_lewy, HIGH);
            break;

         default:
		      digitalWrite(silnik_prawy, LOW);
            digitalWrite(silnik_lewy, LOW);
        	   break;
         }

   irrecv.resume();
   }
}
