#include <Stepper.h>

#define STEPS_PER_MOTOR_REVOLUTION 32   

#define STEPS_PER_OUTPUT_REVOLUTION 32 * 64

Stepper small_stepper(STEPS_PER_MOTOR_REVOLUTION, 2, 3, 4, 5);

int  Steps2Take;

void setup()
{

}

void loop()
{
  small_stepper.setSpeed(1); 
  Steps2Take  =  4;
  small_stepper.step(Steps2Take);
  delay(2000);

  Steps2Take  =  STEPS_PER_OUTPUT_REVOLUTION / 2;
  small_stepper.setSpeed(100);   
  small_stepper.step(Steps2Take);
  delay(1000);
  
  Steps2Take  =  - STEPS_PER_OUTPUT_REVOLUTION / 2;
  small_stepper.setSpeed(700);
  small_stepper.step(Steps2Take);
  delay(2000);

}
