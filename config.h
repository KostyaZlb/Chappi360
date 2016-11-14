/*
 * config.h
 *
 * Created: 11.11.2016 19:43:49
 *  Author: kosty
 */ 

#ifndef CONFIG_H_
#define CONFIG_H_

#define MOTOR1_L B01010000
#define MOTOR1_R B00110000

#define MOTOR2_R B10001000
#define MOTOR2_L B10000100

#define MOTOR3_R B10000010
#define MOTOR3_L B10000001

// пины которые используються для сдвигового регистра
#define R_DATA 10 // 13 пин используеться для передачи данных в сдвиговый регистр
#define R_LACH 11 // 14 пин для открытия закрытия защелки регистра
#define R_CLOCK 12 // 15 пин "для часов" регистра

// пины на коротых задействован ШИМ для моторов
#define pwmMot1 5 // для мотора 1
#define pwmMot2 9 // и мотора 2
#define pwmMot3 6 // мотора 3

#define ENC_PIN1_M1 15 // вывод1 енкодера мотора1 
#define ENC_PIN2_M1 8 // вывод2 енкодера мотора1 

#define ENC_PIN1_M3 17 // вывод1 енкодера мотора3
#define ENC_PIN2_M3 16 // вывод2 енкодера мотора3 

#define ENC_PIN1_M2 14 // вывод1 енкодера мотора2 
#define ENC_PIN2_M2 13 // вывод2 енкодера мотора2 

// эти пины могут работать исключительно как АЦП
// (по умолчанию к ним датчики линии)
#define ANALOG1 A6
#define ANALOG2 A7
 
// Свободные цифровые порты 
// (по умолчанию к ним подключается дальномер)
#define DIGITAL1 4 // пин "триггер"
#define DIGITAL2 7 // пин "эхо"

#define  SerialSpeed 9600

#endif /* CONFIG_H_ */
