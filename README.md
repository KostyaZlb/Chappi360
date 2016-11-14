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
##Класс ChappiAPI
**public**
```cpp 
float getDist(int) 
– возвращает значение с датчика расстояния,  
если поставить 1 возвращает расстояние в сантиметрах, 0 в дюймах.   
unsigned char getS1LineState() - возвращаемое значение в диапазоне от 0 до 100,  
зависит от цвета поверхности  ( а так же зависит от типа датчика)  
void setMotionMotor(byte in) – отсылает команду на моторы, команда формируется из восьми  
бит значение каждого можно увидеть в таблице в низу:
```
Bit7                               |	Bit6	                              | Bit5	                                   |Bit4	                      |Bit3	                                 |Bit2	                                    |Bit1	                                 |Bit0                                      |
-----------------------------------|--------------------------------------|------------------------------------------|----------------------------|--------------------------------------|------------------------------------------|--------------------------------------|------------------------------------------|
Разрешает движение моторами M2 и M3|Движение мотором M1 по часовой стрелке|Движение мотором M1 против часовой стрелки|Разрешает движение мотору M1|Движение мотором M2 по часовой стрелке|Движение мотором M2 против часовой стрелки|Движение мотором M3 по часовой стрелке|Движение мотором M3 против часовой стрелки|
```cpp
void setSpeedMotor1(char in) – задает скорость вращения мотора 1
void setSpeedMotor2(char in) – задает скорость вращения мотора 2
void setSpeedMotor3(char in) – задает скорость вращения мотора 3
```
###Функции доступные в тестовом режиме (возможна не стабильная работа)
```cpp 
char getRotMot1() -Возвращает 'L' если мотор 1 вращается в левую сторону и 'R' в правую
char getRotMot2() - Возвращает 'L' если мотор 2 вращается в левую сторону и 'R' в правую
char getRotMot3() - Возвращает 'L' если мотор 3 вращается в левую сторону и 'R' в правую
int getRevMinMot1() - возвращает количество оборотов двигателя 1 в минуту
int getRevMinMot2() - возвращает количество оборотов двигателя 2 в минуту
int getRevMinMot3() - возвращает количество оборотов двигателя 3 в минуту
```
