#include <VirtualWire.h>

#define led_pin 13		// pin leda informacyjnego czy kod działa
#define receive_pin 11 		// pin odbioru danych

#define silnik_prawy 5		// pin sterowania silnikiem
#define silnik_lewy 6 		// pin sterowania silnikiem

void setup()
{

    vw_set_rx_pin(receive_pin);
    vw_setup(2000);	 
    vw_rx_start(); // startujemy odbieranie danych (uruchamiamy)
    pinMode(led_pin, OUTPUT);
}

void loop()
{
     // częśc wymagana do poprawnego działania biblioteki
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;
    
    // jeśli odbierzemy dane
    if (vw_get_message(buf, &buflen)) 
    {
	int i;
	int status;
        String odebrana_liczba;

        digitalWrite(led_pin, HIGH); //zapalamy LED odbioru danych
        	
	for (i = 0; i < buflen; i++) // w pętli zczytujemy dane z odbiornika
	{
           odebrana_liczba+=char(buf[i]);
	}
	    
	status = odebrana_liczba.toInt();    // zamieniamy odebrany znak tesktowy na liczbę
	
	switch (status) {
		case 0:  // gdy status = 0 wykonaj:
		{ 
			digitalWrite(silnik_prawy, LOW); 
			digitalWrite(silnik_lewy, LOW);
			break;
		}
		case 1:  // gdy status = 1 wykonaj:
		{ 
			digitalWrite(silnik_prawy, LOW); 
			digitalWrite(silnik_lewy, LOW);
			break;
		}
		case 2:  // gdy status = 2 wykonaj:
		{ 
			digitalWrite(silnik_prawy, LOW); 
			digitalWrite(silnik_lewy, LOW);
			break;
		}
		default:
		status = 0;
        	break;
		}
  
	
        digitalWrite(led_pin, LOW); // gasimy LED
    }
}





