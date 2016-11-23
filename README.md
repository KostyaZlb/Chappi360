# Chappi360
##API для работы с платформой обучения Chappi360

###Инструкция по установке
Для ArduinoIDE:
Запускаем ArduinoIDE заходим в меню “Файл”->“Создать новый проект”, сохраняем.
Теперь скачиваем данный репозиторий и распаковываем, копируем данные папки в директорию проекта.
Переходим к файлу проекта и подключаем файл ChappiAPI.h
```cpp
#include "ChappiAPI.h"
```
после этого нам доступен функционал API.
##Структура:
**patch.h** – библиотеки зависимостей  
**config.h** – содержит базовые макросы  
**ChappiAPI.h** –структура класса ChappiAPI для быстрого доступа ко всей периферии платформы  
**EncoderLab.h** – структура класса EncoderLab для работы с энкодерами  
**Ultrasonic.h** – структура класса Ultrasonic  
##Описание класса ChappiAPI
**public**
```cpp 
float getDist(int) 
```
–возвращает значение с датчика расстояния, если поставить 1 возвращает расстояние в сантиметрах, 0 в дюймах.  
```cpp
unsigned char getS1LineState()
```
–возвращаемое значение в диапазоне от 0 до 100, зависит от цвета поверхности  ( а так же зависит от типа датчика)  
```cpp
void setMotionMotor(byte in)
```
–отсылает команду на моторы, команда формируется из восьми бит значение каждого можно увидеть в таблице в низу:  

| Bit7	                              | Bit6                                    | Bit5                                         | Bit4                          | Bit3                                    | Bit2                                         | Bit1	                                  | Bit0                                         |  
|-------------------------------------|-----------------------------------------|----------------------------------------------|-------------------------------|-----------------------------------------|----------------------------------------------|-----------------------------------------|----------------------------------------------|  
| Разрешает движение моторами M2 и M3 | Движение мотором M1 по ча-совой стрелке | Движение мотором M1 про-тив часо-вой стрелки | Разрешает движение моторам M1 | Движение мотором M2 по ча-совой стрелке | Движение мотором M2 про-тив часо-вой стрелки | Движение мотором M3 по ча-совой стрелке | Движение мотором M3 про-тив часо-вой стрелки |  

```cpp
void setSpeedMotor1(char in)
``` 
– задает скорость вращения мотора 1  
```cpp 
void setSpeedMotor2(char in)
``` 
– задает скорость вращения мотора 2  
```cpp
void setSpeedMotor3(char in)
``` 
– задает скорость вращения мотора 3  
###Функции доступные в тестовом режиме (возможна не стабильная работа)
```cpp 
char getRotMot1()
```
-возвращает 'L' если мотор 1 вращается в левую сторону и 'R' в правую
```cpp
char getRotMot2()
```
-возвращает 'L' если мотор 2 вращается в левую сторону и 'R' в правую
```cpp
char getRotMot3()
```
-возвращает 'L' если мотор 3 вращается в левую сторону и 'R' в правую
```cpp
int getRevMinMot1()
```
-возвращает количество оборотов двигателя 1 в минуту
```cpp
int getRevMinMot2()
```
-возвращает количество оборотов двигателя 2 в минуту
```cpp
int getRevMinMot3()
``` 
-возвращает количество оборотов двигателя 3 в минуту

## Пример использования библиотеки   

```cpp
// Подключаем библиотеку API
#include "ChappiAPI.h"

// Создаем указатель на класс ChappiAPI
ChappiAPI* chappi = new ChappiAPI;

void setup()
{

  // Инициализируем порты которые задействованы на плате робота
  // Макро определения пинов в файле config.h

  // Инициализация портов которые использует сдвиговый регистр
  pinMode(R_DATA, OUTPUT);
  pinMode(R_LACH, OUTPUT);
  pinMode(R_CLOCK, OUTPUT);

  // Инициализация портов ШИМ как выходы
  pinMode(pwmMot1, OUTPUT);
  pinMode(pwmMot2, OUTPUT);
  pinMode(pwmMot3, OUTPUT);

  // Инициализация цифровых пинов как входы (используются для подключения энкодеров)
  // Мотора №1
  pinMode(ENC_PIN1_M1, INPUT);
  pinMode(ENC_PIN2_M1, INPUT);

  // Мотора №2
  pinMode(ENC_PIN1_M2, INPUT);
  pinMode(ENC_PIN2_M2, INPUT);

  // Мотора №3
  pinMode(ENC_PIN1_M3, INPUT);
  pinMode(ENC_PIN2_M3, INPUT);

  // Инициализация аналоговых портов, как входы (используются для датчиков линии)
  pinMode(ANALOG1, INPUT);
  pinMode(ANALOG2, INPUT);

  // Инициализация последовательного порта (устанавливаем скорость 9600 bit/s)
  Serial.begin(9600);
}

void loop()
{
  // Устанавливаем скорость мотора №1 в отметку 200
  chappi->setSpeedMotor1(200);
  // Отсылаем команду на сдвиговый регистр вращать мотором №1 в левую сторону
  //  макро определение MOTOR1_L  можно посмотреть в файле
  chappi->setMotionMotor(MOTOR1_L);

  // Отсылаем значение с датчика линии №1 в последовательный порт
  Serial.println(chappi->getS1LineState());
}
```  
