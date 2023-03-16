// konfiguracja ustawień

#include <VirtualWire.h> // podłączamy bibliotekę obsługi modułu komunikacji radiowej

// definiujemy piny

#define led_pin 11
#define transmit_pin 10
#define prawy_s 5
#define lewy_s 6

void setup()
{
    // przygotowujemy potrzebne informacje dla biblioteki
    vw_set_tx_pin(transmit_pin);
    vw_setup(2000);
    pinMode(led_pin, OUTPUT);
    pinMode(prawy_s, INPUT_PULLUP); // prawy silnik
    pinMode(lewy_s, INPUT_PULLUP); // prawy silnik
}

// << KONFIG >>



void loop()
{
  
  String toSend = ("hello world"); 		// tekst wiadomości
  char msg[23]; 					// tworzymy tablicę typu char
  
  // konwertujemy nasz tekst do tablicy char'ów
  toSend.toCharArray(msg, toSend.length() + 1); 
  
  
  digitalWrite(led_pin, HIGH); 			// zapalamy LED

  vw_send((uint8_t *)msg, strlen(msg));		// wysyłamy 
  vw_wait_tx(); 

  digitalWrite(led_pin, LOW); 			// gasimy LED
  delay(1000); 						// czekamy 1 sekundę
  
}
