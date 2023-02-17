#include <mbed.h>


DigitalOut stepPin(p21);
DigitalOut dirPin(p22);
DigitalOut En(p23);

#define STEPS_PER_REVOLUTION 200
int vitesse = 0;


AnalogIn  pot(p15);
//const int stepsPerRevolution = 200;
int i;
float timeStep = 0.0025;
float vitesseAngle;
int step;


void fonctionStep (void);
void vitesseAngleParSeconde (void);

Timeout t; 




int main() {
  En = 1;
  dirPin = 1;
  //t.attach(fonctionStep, 0.1);
  t.attach(&fonctionStep, 0.0025);
  while (true) {

    


    vitesse = pot.read() * 720;     // valeur entre 0 et 720

    printf("%d\n\r",vitesse);
    //vitesseAngleParSeconde();
    step = (vitesse * (STEPS_PER_REVOLUTION / 360))/2;  
    printf("%d\n\r",step);
    timeStep = 1 / step;
    printf("%d\n\r",step);


  }
}



void fonctionStep (void)
{
  stepPin = !stepPin;
  //vitesseAngleParSeconde();
  t.attach(&fonctionStep, 0.0025);

}

void vitesseAngleParSeconde (void)
{
  step = (vitesse * (STEPS_PER_REVOLUTION / 360))/2;      
  timeStep = 1 / step;
  //printf("%d\n\r",timeStep * 1000);          
}


// 360 deg pour 200 steps 
// 1 deg pour 200/360 steps
// 1 step pour 360/200 deg
// 1 step pour 0.9 deg


