#include <VirtualWire.h>

#define led_pin 13		// pin leda informacyjnego czy kod działa
#define receive_pin 11 		// pin odbioru danych


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

    if (vw_get_message(buf, &buflen)) // jeśli odbierzemy dane
    {
	int i;
        String wiadomosc;

        digitalWrite(led_pin, HIGH); //zapalamy LED
        	
	for (i = 0; i < buflen; i++) // w pętli zczytujemy dane z odbiornika
	{
            wiadomosc+=char(buf[i]);
	}
	Serial.println(wiadomosc);
        digitalWrite(led_pin, LOW); // gasimy LED
    }
}






    if (vw_get_message(buf, &buflen)) // jeśli odbierzemy dane
    {
	int i,pwm,wartosc;
        String liczba;

        digitalWrite(led_pin, HIGH); //zapalamy LED
       // w pętli zczytujemy dane z odbiornika 
        for (i = 0; i < buflen; i++) 
        {
          liczba+=char(buf[i]); // wiadomość
        }
        	
        wartosc = liczba.toInt();
        pwm = map(wartosc,0,1023,0,255);
	Serial.print(wartosc);// Debug
        Serial.print("   ");
        Serial.println (pwm);
        analogWrite(pwm_pin, pwm);
        digitalWrite(led_pin, LOW); // gasimy LED

