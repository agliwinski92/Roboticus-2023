#include <IRremote.h>
#define irPin 11		// pin odbioru danych z podczerwieni
#define silnik_prawy 5		// pin sterowania silnikiem
#define silnik_lewy 6 		// pin sterowania silnikiem

IRrecv irrecv(irPin);
decode_results results;

void setup() {
	Serial.begin(9600);
	irrecv.enableIRIn();
	pinMode(silnik_prawy, OUTPUT);
	pinMode(silnik_lewy, OUTPUT); 
}
void loop() {
	if (irrecv.decode(&results)) {	// jeśli jest sygnał to:
      	switch (results.value) {
         	case 0x10:
            	digitalWrite(silnik_prawy, HIGH);
           	digitalWrite(silnik_lewy, HIGH);
	    	delay(500);
                break;
		case 0x16:
            	digitalWrite(silnik_prawy, HIGH);
		delay(250);
           	break;
         	case 0x15:
            	digitalWrite(silnik_lewy, HIGH);
            	delay(250);
            	break;
         	default:
            	digitalWrite(silnik_prawy, LOW);
            	digitalWrite(silnik_lewy, LOW);
        	break;
         }
   irrecv.resume();
   }
   digitalWrite(silnik_prawy, LOW);
   digitalWrite(silnik_lewy, LOW);
}
