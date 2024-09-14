/*
  MorseCodeLED

  用LED灯发送摩斯电码, 了解
    1. 二进制与位运算
  
  modified 2023-09-04
  by 唐国安 郭明旻
*/

//数字0-9的摩斯电码: 11111,01111,00111,00011,00001,00000,10000,11000,11100,11110
unsigned int NumberCode[] = { 0x1F, 0x0F, 0x07, 0x03, 0x01, 0x00, 0x10, 0x18, 0x1C, 0x1E };  // 数字0-9的摩斯电码
unsigned int Message[] = { 2623, 7193, 4762, 4827, 0626, 3810, 5280, 1395, 6432 };           // “机电系统原理及实践”的电报编码

#define SHORT 100            // 一个时间单位，表示短信号嘀（•）的时长
#define LONG (3 * SHORT)     // 三个时间段单位，表示长信号哒（–）的时长
#define BREAK (SHORT)        // 两个信号之间的时间间隔
#define BREAKx3 (3 * SHORT)  // 两个字符之间的时间间隔
#define BREAKx7 (7 * SHORT)  // 两个单词之间的时间间隔

#define LED_PIN 13  // 信号输出数字端口

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);                        // 设置数字端口为信号输出
  digitalWrite(LED_PIN, LOW);                      // 初始化为低电平，灯灭
  for (int i = 0; i < 9; i++) Decode(Message[i]);  // 对Message数组进行解码输出
}

void loop() {
}

// 将汉字电码拆分为4个数字，依次输出
// 输入参数data：某一个汉字的4位数字电码
void Decode(unsigned int data) {
  // Serial.print(data); Serial.print(' ');
  int c = 1000;  // 取十进制各位数字的量级基数

  while (c > 0) {       // 从高位到低位，依次获得十进制的各位数字
    byte d = data / c;  // 取data的最高位数字
    TransmitCode(d);    // 控制LED灯，发送信号
    delay(BREAKx3);     // 两个数字字符之间的时间间隔
    data -= c * d;      // data剩余未发送的数字
    c /= 10;            // 量级减一位
    // Serial.print(d);
  }
  // Serial.println();
  delay(BREAKx7);  // 两个单词（汉字字符）之间的时间间隔
}

// 将某个数字的摩斯电码发送出去
// 输入参数d：0-9的某个数字
void TransmitCode(byte d) {
  unsigned int mask = 0x10;            // 掩码，用于提取摩斯电码的各位二进制编码
  d = NumberCode[d];                   // 根据d的数值，找到其对应的摩斯电码
  while (mask > 0) {                   // 从高位到低位，依次获得摩斯电码的各位二进制编码
    digitalWrite(LED_PIN, HIGH);       // 点亮LED灯
    delay((d & mask) ? LONG : SHORT);  // 判断二进制编码为滴或哒，LED亮相应的时长
    digitalWrite(LED_PIN, LOW);        // 关闭LED灯
    mask = mask >> 1;                  // 掩码右移一位，等待获取下一位二进制编码
    delay(BREAK);                      // 两个信号之间的时间间隔
  }
}
