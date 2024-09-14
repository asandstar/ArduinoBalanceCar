/*
  base

  不同进制数值的表示和显示, 了解
    1. 不同进制数值的表示方法
    2. 用不同进制显示数值
  
  modified 2023-09-05
  by 唐国安 郭明旻
*/

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);  // 初始化串口, 默认波特率为 9600
	while (!Serial) {};  // 等待串口初始化完成
	
  // a = b = c = 15
  int a = 0x0f;    // 十六进制表示
  int b = 017;     // 八进制表示
  int c = 0b1111;  // 二进制表示

  String str = "a = ";
  str += a;
  str += "\t b = ";
  str += b;
  str += "\t c = ";
  str += c;
  Serial.println(str);

  Serial.println("\t HEX \t OCT\t BIN");
  for (int i = 0; i <= 16; i++) {
    Serial.print(i);  // 十进制显示，默认
    Serial.print('\t');
    Serial.print(i, HEX);  // 十六进制显示
    Serial.print('\t');
    Serial.print(i, OCT);  // 八进制显示
    Serial.print('\t');
    Serial.println(i, BIN);  // 二进制显示
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}