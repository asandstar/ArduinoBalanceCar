/*
  Blink

  控制板载LED的明暗变化，了解
    1. 数字端口的输出控制
    2. PWM 效果
  
  modified 2023-09-04
  by 唐国安 郭明旻
*/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);  // 使用Uno时, LED_BUILTIN 为 port 13.
}

// the loop function runs over and over again forever
void loop() {
  int cycle = 20;                 // 明暗周期, 单位 ms. 可尝试较小数值，如 20 ms
  int duty = 10;                   // 点亮时长, 与cycle的比值在0-1之间变化, 观察PWM效果

  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(duty);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(cycle - duty);              // wait for a second
}