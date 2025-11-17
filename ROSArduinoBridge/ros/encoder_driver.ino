
#ifdef USE_BASE

// #ifdef ROBOGAIA
//   /* The Robogaia Mega Encoder shield */
//   #include "MegaEncoderCounter.h"

//   /* Create the encoder shield object */
//   MegaEncoderCounter encoders = MegaEncoderCounter(4); // Initializes the Mega Encoder Counter in the 4X Count mode
  
//   /* Wrap the encoder reading function */
//   long readEncoder(int i) {
//     if (i == LEFT) return encoders.YAxisGetCount();
//     else return encoders.XAxisGetCount();
//   }

//   /* Wrap the encoder reset function */
//   void resetEncoder(int i) {
//     if (i == LEFT) return encoders.YAxisReset();
//     else return encoders.XAxisReset();
//   }

// #elif defined(ARDUINO_ENC_COUNTER)
//   volatile long left_enc_pos = 0L;
//   volatile long right_enc_pos = 0L;
//   static const int8_t ENC_STATES [] = {0,1,-1,0,-1,0,0,1,1,0,0,-1,0,-1,1,0};  //encoder lookup table
    
//   /* Interrupt routine for LEFT encoder, taking care of actual counting */
//   ISR (PCINT2_vect){
//   	static uint8_t enc_last=0;
        
// 	enc_last <<=2; //shift previous state two places
// 	enc_last |= (PIND & (3 << 2)) >> 2; //read the current state into lowest 2 bits
  
//   	left_enc_pos += ENC_STATES[(enc_last & 0x0f)];
//   }
  
//   /* Interrupt routine for RIGHT encoder, taking care of actual counting */
//   ISR (PCINT1_vect){
//         static uint8_t enc_last=0;
          	
// 	enc_last <<=2; //shift previous state two places
// 	enc_last |= (PINC & (3 << 4)) >> 4; //read the current state into lowest 2 bits
  
//   	right_enc_pos += ENC_STATES[(enc_last & 0x0f)];
//   }
  
//   /* Wrap the encoder reading function */
//   long readEncoder(int i) {
//     if (i == LEFT) return left_enc_pos;
//     else return right_enc_pos;
//   }

//   /* Wrap the encoder reset function */
//   void resetEncoder(int i) {
//     if (i == LEFT){
//       left_enc_pos=0L;
//       return;
//     } else { 
//       right_enc_pos=0L;
//       return;
//     }
//   }
//-------------------------------------------------------------------------------------------------------------------------------------
// #elif defined ARDUINO_MY_COUNTER

#ifdef ARDUINO_MY_COUNTER
  //功能：实现左右电机的脉冲计数
  
  volatile long left_count = 0L;    //定义计数器
  volatile long right_count = 0L;
  //初始化
  void initEncoder(){
    pinMode(LEFT_A,INPUT);    // 20  --- 2
    pinMode(LEFT_B,INPUT);    // 21  --- 3
    pinMode(RIGHT_A,INPUT);   // 18  --- 5
    pinMode(RIGHT_B,INPUT);   // 19  --- 4

    //添加中断
    attachInterrupt(2,leftEncoderEventA,CHANGE);
    attachInterrupt(3,leftEncoderEventB,CHANGE);
    attachInterrupt(5,rightEncoderEventA,CHANGE);
    attachInterrupt(4,rightEncoderEventB,CHANGE);
  }
  //编写中断的回调函数
  void leftEncoderEventA(){
    if(digitalRead(LEFT_A) == HIGH){
      //再判断B的电压
      if(digitalRead(LEFT_B) == LOW){
        left_count++;
      } else {
        left_count--;
      }
    } else {
      if(digitalRead(LEFT_B) == HIGH){
        left_count++;
      } else {
        left_count--;
      }
    }
  }
  void leftEncoderEventB(){
    if(digitalRead(LEFT_B) == HIGH){
        if(digitalRead(LEFT_A) == HIGH){
          left_count++;
        } else {
          left_count--;
        }
    } else {
      if(digitalRead(LEFT_A) == LOW){
          left_count++;
        } else {
          left_count--;
        }
    }
  }
  void rightEncoderEventA(){
    //先判断A是是否跳变到高电压
    if(digitalRead(RIGHT_A) == HIGH){
      //再判断B的电压
      if(digitalRead(RIGHT_B) == LOW){
        right_count++;
      } else {
        right_count--;
      }
    } else {
      if(digitalRead(RIGHT_B) == HIGH){
        right_count++;
      } else {
        right_count--;
      }
    }
  }
  void rightEncoderEventB(){
    if(digitalRead(RIGHT_B) == HIGH){
      if(digitalRead(RIGHT_A) == HIGH){
        right_count++;
      } else {
        right_count--;
      }
    } else {
      if(digitalRead(RIGHT_A) == LOW){
          right_count++;
        } else {
          right_count--;
        }
    }
  }

  long readEncoder(int i){
    if (i == LEFT) return left_count;
    else return right_count;
  }
  void resetEncoder(int i){
    if (i == LEFT){
      left_count=0L;
      return;
    } else { 
      right_count=0L;
      return;
    }
  }
#else
  #error A encoder driver must be selected!
#endif

/* Wrap the encoder reset function */
void resetEncoders() {
  resetEncoder(LEFT);
  resetEncoder(RIGHT);
}

#endif

