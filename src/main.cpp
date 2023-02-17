#include <mbed.h>


DigitalOut stepPin(p21);
DigitalOut dirPin(p22);
DigitalOut En(p23);
//const int stepsPerRevolution = 200;
int i;

int main() {
  En = 1;
  dirPin = 1;
  while (true) {

    for (i = 1000; i > 200; i--) // augmenter graduellement la vitesse du moteur 
    {
        stepPin = 1;  
        wait_us(i);
        stepPin = 0;
        wait_us(i);
    }
      
  for(i = 200; i>135; i--)  // augmenter la vitesse encore plus graduellement qu'au dému (1 step plus rapide a tous les 3 seconde )
  {
    for (int a = 0 ; a < 3000 ; a++)
    {
        stepPin = 1;  
        wait_us(i);
        stepPin = 0;
        wait_us(i);
    }

  }
  for(i = 135; i>130; i--)  // augmenter la vitesse encore plus graduellement qu'au dému (1 step plus rapide a tous les 3 seconde )
  {
    for (int a = 0 ; a < 6000 ; a++)
    {
        stepPin = 1;  
        wait_us(i);
        stepPin = 0;
        wait_us(i);
    }

  } 
   
     while(true)      // reste a vitesse constante
    {
       stepPin = 1;
       wait_us(i);
       stepPin = 0;

       wait_us(i);
     }
  }
}

