
#ifndef MyoController_H
#define MyoController_H

#include "Arduino.h"

#define DEBUG	0

enum Poses{
	rest,
	fist,
	waveIn,
	waveOut,
	fingersSpread,
	doubleTap,
	unknown
};

class MyoController {
public:

    /* Initialization methods */
    MyoController();
    ~MyoController();
    bool initMyo();
    bool updatePose();
    Poses getCurrentPose();
private:
	Poses current_pose_;
	String storageStr;
	String msgChar;
};

#endif