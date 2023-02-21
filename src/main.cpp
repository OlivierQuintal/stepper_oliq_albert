#include <mbed.h>


#define STEPS_PER_REVOLUTION 200  // 200 steps par revolution (1.8 degre)
#define degParSecMax 720      // degré par seconde max

DigitalOut stepPin(p21);
DigitalOut dirPin(p22);
DigitalOut En(p23);
AnalogIn  pot(p15);

int vitesse = 0;    // valeur entre 0 et 720



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
    vitesse = pot.read() * degParSecMax;     // valeur entre 0 et 720

    printf("%d\n\r",vitesse);
    //vitesseAngleParSeconde();
    step = (vitesse * (STEPS_PER_REVOLUTION / 360))/2;  
    printf("%d\n\r",step);
    timeStep = 1 / step;
    printf("%d\n\r",timeStep);

  }
}


void fonctionStep (void)
{
  stepPin = !stepPin;
  //vitesseAngleParSeconde();
  t.attach(&fonctionStep, timeStep);

}

void vitesseAngleParSeconde (void)
{
  step = (vitesse * (STEPS_PER_REVOLUTION / 360))/2;      
  timeStep = 1 / step;
  //printf("%d\n\r",timeStep * 1000);          
}



