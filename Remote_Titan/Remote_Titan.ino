/* 02.01.2018 Board rev.-1.2~~~~~~~~~~Ревизия платы-1.2
   https://github.com/SFERA-GIT/Nano-shield-rev.-1.2
   Разработано СФЕРА74 (г.Челябинск) http://sphere74.ru/ для
   СФЕРА ЗНАНИЙ (г.Челябинск) http://сферазнаний.рф/
   Пример программы для управляемого Титана.
   Для работы необходим смартфон на базе Android и установленное
   приложение ArdumotiveBT_controller_v2.1. 
   1.Для использования приложения на смартфоне необходимо включить
   Bluetooth.
   2. Добавить устройство HC-05 в настройках Bluetooth.
   3. Перейти в приложение Ardumotive_BT и Лист доступных BT устройств
   4. Выбрать модуль HC-05.
   5. Нажать кнопку Статуса подключения и дождаться зеленого индикатора.
*/
int Lms, Rms;

// Создаем переменную для команд Bluetooth 
char vcmd; 
// Создаем переменные для запоминания скорости двигателей 
int vspdL, vspdR; 
/* Создаем переменную, на значение которой будет уменьшаться скорость при плавных поворотах. 
Текущая скорость должна быть больше этого значения. В противном случае двигатели со стороны направления поворота просто не будут вращаться */ 

void setup() { 
// Устанавливаем скорость передачи данных по Bluetooth 
Serial.begin(9600); 
  pinMode(9, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void motor(int x, int y) {
  if (x > 0){digitalWrite (13, 1);} 
  else{digitalWrite(13, 0);}
  if (y > 0){digitalWrite (12, 1);} 
  else{digitalWrite(12, 0);}
  analogWrite(11, abs(y));
  analogWrite(10, abs(x));
}
void loop() { 
// Если есть данные 
if (Serial.available()) 
{ 
// Читаем команды и заносим их в переменную. char преобразует код символа команды в символ 
vcmd = (char)Serial.read(); 
// Отправляем команду в порт, чтобы можно было их проверить в «Мониторе порта» 
Serial.println(vcmd);
//motor(Lms,Rms);
// Вперед 
if (vcmd) {} else{ 
motor(0,0);
} 
// Вперед 
if (vcmd == 'F') { 
motor(Lms,Rms);
 
} 
// Назад 
if (vcmd == 'B') 
{ 
motor(-1*Lms,-1*Rms); 

} 
// Влево 
if (vcmd == 'L') 
{ 
motor(Lms,-1*Rms);

} 
// Вправо 
if (vcmd == 'R') 
{ 

motor(-1*Lms,Rms);
} 
// Прямо и влево 
if (vcmd == 'G') 
{ 

} 
// Прямо и вправо 
if (vcmd == 'I') 
{ 
 
} 
// Назад и влево 
if (vcmd == 'H') 
{ 

} 
// Назад и вправо 
if (vcmd == 'J') 
{ 
 
} 
// Стоп 
if (vcmd == 'S') 
{ 
 
} 
// Buzzer on 
if (vcmd == 'V') 
{ 

} 
// Buzzer off 
if (vcmd == 'v') 
{ 

} 
// Скорость 0% 
if (vcmd == '0') 
{ 
Rms=0;
Lms=0; 
} 
// Скорость 10% 
if (vcmd == '1') 
{ 
Rms=70;
Lms=70; 
} 
// Скорость 20% 
if (vcmd == '2') 
{ 
Rms=70;
Lms=70; 
} 
// Скорость 30% 
if (vcmd == '3') 
{ 
Rms=70;
Lms=70; 
} 
// Скорость 40% 
if (vcmd == '4') 
{ 
Rms=120;
Lms=120; 
} 
// Скорость 50% 
if (vcmd == '5') 
{ 
Rms=70;
Lms=70; 
} 
// Скорость 60% 
if (vcmd == '6') 
{ 
Rms=70;
Lms=70;
} 
// Скорость 70% 
if (vcmd == '7') 
{ 
Rms=70;
Lms=70; 
} 
// Скорость 80% 
if (vcmd == '8') 
{ 
Rms=70;
Lms=70; 
} 
// Скорость 90% 
if (vcmd == '9') 
{ 
Rms=70;
Lms=70; 
} 
// Скорость 100% 
if (vcmd == 'q') 
{ 
Rms=150;
Lms=150; 
} 
} 
}

