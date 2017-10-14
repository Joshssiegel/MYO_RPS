#include "MyoController.h"
/**
 * @brief Constructor - Instantiates MyoController object
 */
MyoController::MyoController()
{
	msgChar=String("");
}

/**
 * @brief Destructor
 */
MyoController::~MyoController()
{

}
bool MyoController::initMyo(){
	Serial.begin(9600);
	return true;	
}

bool MyoController::updatePose(){
	if (Serial.available())
	{
		storageStr = String("");
		while(Serial.available())
		{
			storageStr = storageStr + char(Serial.read());
			delay(1);
		}

		msgChar = storageStr;
		//Serial.print(msgChar);

	}

	if(msgChar.indexOf("rest")>=0)
	{
		current_pose_=rest;
	}
	else if (msgChar.indexOf("fist")>=0)
	{
		current_pose_=fist;
	}
	else if (msgChar.indexOf("waveIn")>=0)
	{
		current_pose_=waveIn;
	} 
	else if (msgChar.indexOf("waveOut")>=0)
	{
		current_pose_=waveOut;
	} 
	else if (msgChar.indexOf("fingersSpread")>=0)
	{
		current_pose_=fingersSpread;
	} 
	else if (msgChar.indexOf("doubleTap")>=0)
	{
		current_pose_=doubleTap;
	} 
	else
	{
		current_pose_=unknown;
	}
}
Poses MyoController::getCurrentPose(){
	return current_pose_;
}