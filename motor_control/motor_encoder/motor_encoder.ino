/*
 * 功能：
 *  1.编码器计数
 *  2.速度计算
 * 
 * 实现：
 *  1.定义中断引脚、计数器（使用volatile修饰）
 *  2.设置引脚模式输入
 *  3.中断函数计算脉冲数
 *    3-1.单倍频计数
 *    3-2.双倍频计数
 *    3-3.四倍频计数
 */

int encoder_a = 21;
int encoder_b = 20;
volatile int count = 0;

void count_a()
{
  // 四倍频计数
  if (digitalRead(encoder_a) == HIGH) {
    if (digitalRead(encoder_b) == HIGH) {
      count++;
    } else {
      count--;
    }

  } else {
    if (digitalRead(encoder_b) == LOW) {
      count++;
    } else {
      count--;
    }
  }
}


void count_b()
{
  // 四倍频计数
  if (digitalRead(encoder_b) == HIGH) {
    if (digitalRead(encoder_a) == LOW) {
      count++;
    } else {
      count--;
    }

  } else {
    if (digitalRead(encoder_a) == HIGH) {
      count++;
    } else {
      count--;
    }
  }
}

void setup() {
  Serial.begin(57600);
  pinMode(encoder_a, INPUT);
  pinMode(encoder_b, INPUT);
  attachInterrupt(2, count_a, CHANGE);
  attachInterrupt(3, count_b, CHANGE);

}

void loop() {
  delay(2000);
  Serial.println(count);

}
