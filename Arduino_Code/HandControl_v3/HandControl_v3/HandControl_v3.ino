#include <MyoController.h>
#include <Servo.h>
#define FIST_PIN 10 //we throw paper hand
#define FINGERSSPREAD_PIN 11 //we throw scissors
#define WAVEOUT_PIN 9 //we throw rock
Servo rock;

Servo paper;

Servo scissors;
MyoController myo = MyoController();
const int KEEP_UP_TIME=3000;
const int DOWN_POS=30;
const int UP_POS=120;
void setup() {

  //pinMode(FIST_PIN, OUTPUT);
  //pinMode(WAVEIN_PIN, OUTPUT);
  //pinMode(WAVEOUT_PIN, OUTPUT);
  //pinMode(FINGERSSPREAD_PIN, OUTPUT);
  //pinMode(WAVEOUT_PIN, OUTPUT);
  paper.attach(FIST_PIN);  // attaches the servo on pin 9 to the servo object
  rock.attach(WAVEOUT_PIN);  // attaches the servo on pin 9 to the servo object
  scissors.attach(FINGERSSPREAD_PIN);  // attaches the servo on pin 9 to the servo object

  
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
    case waveOut:
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
   throwPaper();
   delay(1000);
   throwScissors();
   delay(1000);
}


