#include <MyoController.h>
#include <Servo.h>
#define FIST_PIN 10 //we throw paper hand
#define FINGERSSPREAD_PIN 11 //we throw scissors
#define DOUBLETAP_PIN 9 //we throw rock
Servo rock;

Servo paper;

Servo scissors;
MyoController myo = MyoController();
const int KEEP_UP_TIME=3000;
const int DOWN_POS=30;
const int UP_POS=120;
void setup() {
  paper.attach(FIST_PIN);  
  rock.attach(DOUBLETAP_PIN); 
  scissors.attach(FINGERSSPREAD_PIN); 
   myo.initMyo();
}

void loop()
{
   myo.updatePose();
   switch (myo.getCurrentPose()) {
    case rest:
      setNeutral();
      break;
    case fist:
      throwPaper();
      break;
    case fingersSpread:
      throwScissors();
      break;
    case waveIn:
      throwRock();
      break;
    default:
      setNeutral();
      break;
   }
   delay(10);
   //demo();
   
}

void setNeutral()
{
  rock.write(DOWN_POS);
  paper.write(DOWN_POS);
  scissors.write(DOWN_POS);
  delay(1000);
}

void throwPaper()
{
  paper.write(UP_POS);
  delay(KEEP_UP_TIME);
  //setNeutral();
  
}
void throwScissors()
{
  scissors.write(UP_POS);
  delay(KEEP_UP_TIME);
  //setNeutral();  
}
void throwRock()
{
  rock.write(UP_POS);
  delay(KEEP_UP_TIME);
  //setNeutral();

}
void demo()
{
throwRock();
delay(1000);
setNeutral();
delay(1000);
}




