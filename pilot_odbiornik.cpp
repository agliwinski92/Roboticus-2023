#include <VirtualWire.h>

#define led_pin 13		// pin leda informacyjnego czy kod działa
#define receive_pin 11 		// pin odbioru danych

#define silnik_prawy 5		// pin sterowania silnikiem
#define silnik_lewy 6 		// pin sterowania silnikiem

void setup()
{
    Serial.begin(9600);
    Serial.println("Setup ...");

    vw_set_rx_pin(receive_pin); 		// przygotowujemy potrzebne informacje dla biblioteki
    vw_setup(2000);	 
    vw_rx_start(); 				// startujemy odbieranie danych (uruchamiamy)
    
    pinMode(silnik_prawy, OUTPUT);
    pinMode(silnik_lewy, OUTPUT);
    Serial.println("Setup zakończony.");
}

void loop()
{
  // częśc wymagana do poprawnego działania biblioteki
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;
 
    if (vw_get_message(buf, &buflen)) // jeśli odbierzemy dane
    {
	int i,wartosc;
        String liczba;
 
        digitalWrite(led_pin, HIGH);  //zapalamy LED
       
        for (i = 0; i < buflen; i++)  // w pętli zczytujemy dane z odbiornika 
        {
          liczba+=char(buf[i]); // wiadomość
        }
        	
        wartosc = liczba.toInt();
        Serial.print(wartosc);// Debug
    }
}




