/*
  bitOperation

  六种位运算, 了解
    1. 位运算的含义
    2. 数据类型对位运算的影响
  
  modified 2023-09-04
  by 唐国安 郭明旻
*/

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);  // 初始化串口, 默认波特率为 9600
  while (!Serial) {};  // 等待串口初始化完成

  char buf[64];  // 输出字符串
  int a;
  int b;
  int c;

  // 左移
  a = 0x0f;
  b = a << 2;  // 左移 2 位
  sprintf(buf, "0x0f << 2 = 0x%x ( %d )", b, b);
  Serial.println(buf);

  // 右移
  a = 0x0f;
  b = a >> 2;  // 右移 2 位
  sprintf(buf, "0x0f >> 2 = 0x%x ( %d )", b, b);
  Serial.println(buf);

  // 按位与
  a = 0x01;
  b = 0x03;
  c = a & b;  // 按位与
  sprintf(buf, "0x01 & 0x03 = 0x%x ( %d )", c, c);
  Serial.println(buf);

  // 按位或
  a = 0x01;
  b = 0x03;
  c = a | b;  // 按位或
  sprintf(buf, "0x01 | 0x03 = 0x%x ( %d )", c, c);
  Serial.println(buf);

  // 按位异或
  a = 0x01;
  b = 0x03;
  c = a ^ b;  // 按位异或
  sprintf(buf, "0x01 ^ 0x03 = 0x%x ( %d )", c, c);
  Serial.println(buf);

  // 按位取反
  a = 0x05;
  c = ~a;  // 按位取反
  sprintf(buf, "~0x05 = 0x%x ( %d )", c, c);
  Serial.println(buf);
  sprintf(buf, "~0x05 = 0x%x ( %u )", c, c); // 输出格式的影响
  Serial.println(buf);

  // 数据类型的影响
  uint16_t cc;  // 跨平台数据类型，明确数据类型的长度，推荐使用
  cc = ~a;  // 按位取反
  Serial.println(c);
  Serial.println(cc);
}

void loop() {
  // put your main code here, to run repeatedly:
}