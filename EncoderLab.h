/*
 * config.h
 *
 * Created: 11.11.2016 19:43:30
 *  Author: kosty
 */ 

#ifndef ENCODERLAB_H_
#define ENCODERLAB_H_

#include <Arduino.h>

class EncoderLab
{
  public:
  EncoderLab();
  ~EncoderLab();

  char ENC_DIR();
  int REV_min();
  void initEncoder(unsigned char mpin1, unsigned char mpin2);
  private:
  double i=0;
  unsigned char encoder_A;
  unsigned char encoder_B;
  unsigned long currentTime = millis();
  unsigned long loopTime = currentTime;
  unsigned char pin1, pin2;
  unsigned graydecode(unsigned gray);
};

#endif /* ENCODERLAB_H_ */

