#include <MyoController.h>
#include <Servo.h>
#define FIST_PIN 10 //we throw paper hand
//#define WAVEIN_PIN 5
//#define WAVEOUT_PIN 6
#define FINGERSSPREAD_PIN 11 //we throw scissors
#define DOUBLETAP_PIN 9 //we throw rock
Servo rock;

Servo paper;

Servo scissors;
MyoController myo = MyoController();
const int KEEP_UP_TIME=5000;
const int DOWN_POS=20;
const int UP_POS=90;
void setup() {

  //pinMode(FIST_PIN, OUTPUT);
  //pinMode(WAVEIN_PIN, OUTPUT);
  //pinMode(WAVEOUT_PIN, OUTPUT);
  //pinMode(FINGERSSPREAD_PIN, OUTPUT);
  //pinMode(DOUBLETAP_PIN, OUTPUT);
  paper.attach(FIST_PIN);  // attaches the servo on pin 9 to the servo object
  rock.attach(DOUBLETAP_PIN);  // attaches the servo on pin 9 to the servo object
  scissors.attach(FINGERSSPREAD_PIN);  // attaches the servo on pin 9 to the servo object

  
  myo.initMyo();
}

void loop()
{
   //Serial.println("HI");
   myo.updatePose();
   switch ( myo.getCurrentPose() ) {
    case rest:
      setNeutral();
      break;
    case fist:
      throwPaper();
      break;
    case fingersSpread:
      throwScissors();
      break;
    case doubleTap:
      throwRock();
      break;
   } 
   delay(100);
}


void setNeutral()
{
  rock.write(DOWN_POS);
  paper.write(DOWN_POS);
  scissors.write(DOWN_POS);
}

void throwPaper()
{
  paper.write(UP_POS);
  delay(KEEP_UP_TIME);
  setNeutral();
  
}
void throwScissors()
{
  scissors.write(UP_POS);
  delay(KEEP_UP_TIME);
  setNeutral();  
}
void throwRock()
{
  rock.write(UP_POS);
  delay(KEEP_UP_TIME);
  setNeutral();

}
