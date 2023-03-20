#include <VirtualWire.h> // podłączamy bibliotekę obsługi modułu komunikacji radiowej

// definiujemy piny

#define transmit_pin 10
#define led_pin 11

// definiujemy zmienne które będą nam mówić jaki jest status silnika:

// status_silnika = 0 [ oznacza ze jest wylaczony ]
// status_silnika = 1 [ oznacza ze pracuja oba silniki ]
// status_silnika = 2 [ oznacza ze pracuje tylko prawy ]
// status_silnika = 3 [ oznacza ze pracuj3 tylko lewy  ]

int status_silnika = 0;

// definiujemy ustawienia pinów

void setup()
{
  Serial.begin(9600); // open the serial port at 9600 bps:
    // przygotowujemy potrzebne informacje dla biblioteki
    vw_set_tx_pin(transmit_pin);
    vw_setup(2000);
    
    pinMode(led_pin, OUTPUT); // led do informacji czy urządzenie działa [pin 11]
    
    pinMode(5, INPUT_PULLUP); // obsługa prawego silnika [pin 5]
    pinMode(6, INPUT_PULLUP); // obsługa lewego silnika [pin 6]
}

// pętla wykonująca zadanie

void loop()
{
    
  // ----------------------------- sprawdzamy stan przyciskow ------------------------------------------------
    
if ((digitalRead(5) == LOW) && (digitalRead(6) == LOW))             // sprawdzamy czy oba przyciski są wcisniete, jeśli tak to:
    { status_silnika = 1; }                                         // ustawiamy status 1, ktory przeslemy do odbiornika 
    else {                                                          // jeśli nie został spełniony (przyciski nie są wciśnięte) to:
         if ((digitalRead(5) == LOW) && (digitalRead(6) == HIGH))   // sprawdzamy czy przycisk prawego silnika jest wcisniety, jeśli tak to:
            { status_silnika = 2; }                                   
            else {
                 if ((digitalRead(5) == HIGH) && (digitalRead(6) == LOW))
                    { status_silnika = 3; }
                 else 
                    { status_silnika = 0;}          
                 }
         }
    
   // ----------------------------- przesylamy sygnal za pomoca string [wiadomosc txt ] ------------------------------------------------ 
  
  String toSend = (String(status_silnika, DEC));         // tresc wiadomości, czyli statusy przysków silników
  char msg[2]; 					                         // tworzymy tablicę typu char o nazwie [msg] o wielkosci [2 znakow]
  
  toSend.toCharArray(msg, toSend.length() + 1);  // konwertujemy nasz tekst do tablicy char'ów   
    
  digitalWrite(led_pin, HIGH); 			// zapalamy LED

  vw_send((uint8_t *)msg, strlen(msg)); // wysyłamy 
  vw_wait_tx(); 

  digitalWrite(led_pin, LOW); 			// gasimy LED
  delay(500); 						    // czekamy 1 sekundę
  
  Serial.print("Status: ");
  Serial.println(status_silnika);

  // zerujemy statusy po wykonaniu operacji
  status_silnika = 0;

}





