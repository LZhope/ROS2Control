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

/* 
  封装变量：开始时间、单位时间、减速比、脉冲数、N倍频测速



*/

long start_time = millis();
int interval_time = 50;
int reduction = 60; // 减速比
int pulse = 13; // 脉冲
int frequency = 4;  // 4倍频
int per_round_pulse = reduction * pulse * frequency;

void get_current_vel(){
  long right_now = millis();
  long past_time = right_now - start_time;
  if ( past_time > interval_time) {
    noInterrupts();
    double vel = (double)count / per_round_pulse / past_time * 1000 * 60; 
    Serial.println(vel);
    count = 0;
    start_time = right_now;
    interrupts();
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
  // delay(2000);
  // Serial.println(count);
  delay(20);
  get_current_vel();

}
