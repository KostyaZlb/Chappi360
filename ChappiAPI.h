/*
 * ChappiAPI.h
 *
 * Created: 12.11.2016 1:29:41
 *  Author: kosty
 */ 


#ifndef CHAPPIAPI_H_
#define CHAPPIAPI_H_

#include "patch.h"
#include "config.h"

class ChappiAPI
{
public:
	ChappiAPI();
	~ChappiAPI();
	//void initChPins();

	float getDist(int);

	int getRevMinMot1();
	int getRevMinMot2();
	int getRevMinMot3();

	char getRotMot1();
	char getRotMot2();
	char getRotMot3();

	unsigned char getS1LineState();
	unsigned char getS2LineState();

	void setMotionMotor(byte in);

	void setSpeedMotor1(char);
	void setSpeedMotor2(char);
	void setSpeedMotor3(char);
private:
	Ultrasonic* sonar;
	EncoderLab* encoder;
};

#endif /* CHAPPIAPI_H_ */
