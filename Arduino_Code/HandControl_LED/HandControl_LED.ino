#include <MyoController.h>
#include <Servo.h>
#define FIST_PIN 10 //we throw paper hand
#define FINGERSSPREAD_PIN 11 //we throw scissors
#define DOUBLETAP_PIN 9 //we throw rock
int rock=9;

int paper=10;

int scissors=11;
MyoController myo = MyoController();
const int KEEP_UP_TIME=3000;
const int DOWN_POS=30;
const int UP_POS=120;
void setup() {
  paper=(FIST_PIN);  
  rock=(DOUBLETAP_PIN); 
  scissors=(FINGERSSPREAD_PIN); 
  pinMode(rock, OUTPUT);
  pinMode(paper, OUTPUT);
  pinMode(scissors, OUTPUT);

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
      //throwPaper();
      break;
   }
   delay(10);
   //demo();
   
}

void setNeutral()
{
  /*rock.write(DOWN_POS);
  paper.write(DOWN_POS);
  scissors.write(DOWN_POS);*/
  digitalWrite(scissors, LOW);
  digitalWrite(paper, LOW);
  digitalWrite(rock, LOW);
  //delay(1000);
}

void throwPaper()
{
  setNeutral();
  digitalWrite(paper, HIGH);
  
  delay(KEEP_UP_TIME);
  digitalWrite(paper, LOW);
  //setNeutral();
  
}
void throwScissors()
{
  setNeutral();
  digitalWrite(scissors, HIGH);
  delay(KEEP_UP_TIME);
  digitalWrite(scissors, LOW);

  //setNeutral();  
}
void throwRock()
{
  setNeutral();

  digitalWrite(rock, HIGH);
  delay(KEEP_UP_TIME);
  digitalWrite(rock, LOW);
  //setNeutral();

}
void demo()
{
throwPaper();
delay(1000);
setNeutral();
delay(1000);
}
