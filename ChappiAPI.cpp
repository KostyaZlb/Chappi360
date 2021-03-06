/*
 * ChappiAPI.cpp
 *
 * Created: 12.11.2016 1:39:09
 *  Author: kosty
 */ 

 #include "ChappiAPI.h"

 ChappiAPI::ChappiAPI()
 {
  sonar = new Ultrasonic(DIGITAL1, DIGITAL2);
  
  encoder = new EncoderLab;
 }

 /************************************************************************/
 /* Инициализирует все пины робота которые используются                 */
 /* (вызывается в setup())                                              */
 /************************************************************************/
/* void ChappiAPI::initChPins()
 {
  pinMode(R_DATA, OUTPUT);
  pinMode(R_LACH, OUTPUT);
  pinMode(R_CLOCK, OUTPUT);

  pinMode(pwmMot1, OUTPUT);
  pinMode(pwmMot2, OUTPUT);
  pinMode(pwmMot3, OUTPUT);

  pinMode(ENC_PIN1_M1, INPUT);
  pinMode(ENC_PIN2_M1, INPUT);

  pinMode(ENC_PIN1_M2, INPUT);
  pinMode(ENC_PIN2_M2, INPUT);

  pinMode(ENC_PIN1_M3, INPUT);
  pinMode(ENC_PIN2_M3, INPUT);

  pinMode(ANALOG1, INPUT);
  pinMode(ANALOG2, INPUT);

  Serial.begin(SerialSpeed);
 }*/
 
 /************************************************************************/
 /* Вращается расстояние с ультразвукового датчика                       */
 /* если 1 то вращается в сантиметрах если 0 в дюймах                    */
 /************************************************************************/
 float ChappiAPI::getDist(int in)
 {
  return sonar->Ranging(in);
 }
 
 /************************************************************************/
 /* Возвращает 'L' если мотор 1 вращается в левую сторону и 'R' в правую */
 /************************************************************************/

char ChappiAPI::getRotMot1()
 {
  encoder->initEncoder(ENC_PIN1_M1, ENC_PIN2_M1);
  return encoder->ENC_DIR();
 }

 /************************************************************************/
 /* Возвращает 'L' если мотор 2 вращается в левую сторону и 'R' в правую */
 /************************************************************************/
char ChappiAPI::getRotMot2()
 {
   encoder->initEncoder(ENC_PIN1_M2, ENC_PIN2_M2);
   return encoder->ENC_DIR();
 }

 /************************************************************************/
 /* Возвращает 'L' если мотор 3 вращается в левую сторону и 'R' в правую */
 /************************************************************************/
 char ChappiAPI::getRotMot3()
 {
   encoder->initEncoder(ENC_PIN1_M3, ENC_PIN2_M3);
   return encoder->ENC_DIR();
 }

 /************************************************************************/
 /* Возвращает количество оборотов двигателя 1 в минуту                   */
 /************************************************************************/
 int ChappiAPI::getRevMinMot1()
 {
  encoder->initEncoder(ENC_PIN1_M1, ENC_PIN2_M1);
  return encoder->REV_min();
 }

 /************************************************************************/
 /* Возвращает количество оборотов двигателя 2 в минуту                   */
 /************************************************************************/
 int ChappiAPI::getRevMinMot2()
 {
   encoder->initEncoder(ENC_PIN1_M2, ENC_PIN2_M2);
   return encoder->REV_min();
 }

 /************************************************************************/
 /* Возвращает количество оборотов двигателя 3 в минуту                   */
 /************************************************************************/
 int ChappiAPI::getRevMinMot3()
 {
   encoder->initEncoder(ENC_PIN1_M3, ENC_PIN2_M3);
   return encoder->REV_min();
 }

 /************************************************************************/
 /* Возвращает значение от 0 до 100 зависит от цвета поверхности          */
 /* ( а так же зависит от типа датчика)                                  */
 /************************************************************************/
 unsigned char ChappiAPI::getS1LineState()
 {
  int i = analogRead(ANALOG1);
  return floor(i/102.3*10);
 }

 unsigned char ChappiAPI::getS2LineState()
 {
   int i = analogRead(ANALOG2);
   return floor(i/102.3*10);
 }

 /************************************************************************/
 /* Задается вращение двигателям                                        */
 /************************************************************************/
 void ChappiAPI::setMotionMotor(byte in)
 {
  digitalWrite(R_LACH, LOW);
  shiftOut(R_DATA, R_CLOCK, LSBFIRST, b00000000);
  digitalWrite(R_LACH, HIGH);
  digitalWrite(R_LACH, LOW); // открываем защелку для ввода информации
  shiftOut(R_DATA, R_CLOCK, LSBFIRST, in); // по битовый ввод информации в регистр
  digitalWrite(R_LACH, HIGH); // закрываем защелку
 }

 /************************************************************************/
 /* Задается скорость двигателя 1, функция принимает значение от 0 до 255*/
 /************************************************************************/
 void ChappiAPI::setSpeedMotor1(char in)
 {
  analogWrite(pwmMot1, in);
 }

 /************************************************************************/
 /* Задается скорость двигателя 2, функция принимает значение от 0 до 255*/
 /************************************************************************/
 void ChappiAPI::setSpeedMotor2(char in)
 {
   analogWrite(pwmMot2, in);
 }

 /************************************************************************/
 /* Задается скорость двигателя 3, функция принимает значение от 0 до 255*/
 /************************************************************************/
 void ChappiAPI::setSpeedMotor3(char in)
 {
   analogWrite(pwmMot3, in);
 }

 ChappiAPI::~ChappiAPI()
 {

 }
