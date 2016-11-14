/*
 * EncoderLab.h
 *
 * Created: 11.11.2016 19:43:35
 *  Author: kosty
 */ 
#include <Arduino.h>
#include "EncoderLab.h"

EncoderLab::EncoderLab()
{
  
}

void EncoderLab::initEncoder(unsigned char mpin1, unsigned char mpin2)
{
  pin1 = mpin1;
  pin2 = mpin2;
}

/***********************************************************************/
/*  Функция декодирования кода Грея, взятая с Википедии.               */
/*  Принимает число в коде Грея, возвращает обычное его представление. */
/***********************************************************************/
unsigned EncoderLab::graydecode(unsigned gray)
{
  unsigned bin;

  for (bin = 0; gray; gray >>= 1)
  bin ^= gray;

  return bin;
}

/************************************************************************/
/*  Возвращает направление двигателя                                    */
/************************************************************************/
char EncoderLab::ENC_DIR()
{
 static uint8_t previous_code = 0; // предыдущий считанный код

  uint8_t gray_code = digitalRead(pin1) | (digitalRead(pin2) << 1),
  code = graydecode(gray_code);

  if(code == 0){
    if (previous_code == 3)
    return 'R';
    else if (previous_code == 1)
    return 'L';
  }

  previous_code = code;
}

/************************************************************************/
/* Возвращает количество оборотов в минут                               */
/************************************************************************/
int EncoderLab::REV_min()
{
  i=0;
  currentTime = millis();
  if (currentTime >= (loopTime + 200))
  {
    static uint8_t previous_code = 0; // предыдущий считанный код
  
    uint8_t gray_code = digitalRead(pin1) | (digitalRead(pin2) << 1),
    code = graydecode(gray_code);
  
    if(code == 0){
      if (previous_code == 3)
      i += i++;
      else if (previous_code == 1)
      i += i++;
    }
  
    previous_code = code;
  }
  return i*5*60/1800;
}

/************************************************************************/
/* Деструктор класса                                                    */
/************************************************************************/
EncoderLab::~EncoderLab()
{
  
}

