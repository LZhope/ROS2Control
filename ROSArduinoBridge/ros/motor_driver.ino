

#ifdef USE_BASE
   
// #ifdef POLOLU_VNH5019
//   /* Include the Pololu library */
//   #include "DualVNH5019MotorShield.h"

//   /* Create the motor driver object */
//   DualVNH5019MotorShield drive;
  
//   /* Wrap the motor driver initialization */
//   void initMotorController() {
//     drive.init();
//   }

//   /* Wrap the drive motor set speed function */
//   void setMotorSpeed(int i, int spd) {
//     if (i == LEFT) drive.setM1Speed(spd);
//     else drive.setM2Speed(spd);
//   }

//   // A convenience function for setting both motor speeds
//   void setMotorSpeeds(int leftSpeed, int rightSpeed) {
//     setMotorSpeed(LEFT, leftSpeed);
//     setMotorSpeed(RIGHT, rightSpeed);
//   }
// #elif defined POLOLU_MC33926
//   /* Include the Pololu library */
//   #include "DualMC33926MotorShield.h"

//   /* Create the motor driver object */
//   DualMC33926MotorShield drive;
  
//   /* Wrap the motor driver initialization */
//   void initMotorController() {
//     drive.init();
//   }

//   /* Wrap the drive motor set speed function */
//   void setMotorSpeed(int i, int spd) {
//     if (i == LEFT) drive.setM1Speed(spd);
//     else drive.setM2Speed(spd);
//   }

//   // A convenience function for setting both motor speeds
//   void setMotorSpeeds(int leftSpeed, int rightSpeed) {
//     setMotorSpeed(LEFT, leftSpeed);
//     setMotorSpeed(RIGHT, rightSpeed);
//   }
// #elif defined L298_MOTOR_DRIVER
//   void initMotorController() {
//     digitalWrite(RIGHT_MOTOR_ENABLE, HIGH);
//     digitalWrite(LEFT_MOTOR_ENABLE, HIGH);
//   }
  
//   void setMotorSpeed(int i, int spd) {
//     unsigned char reverse = 0;
  
//     if (spd < 0)
//     {
//       spd = -spd;
//       reverse = 1;
//     }
//     if (spd > 255)
//       spd = 255;
    
//     if (i == LEFT) { 
//       if      (reverse == 0) { analogWrite(RIGHT_MOTOR_FORWARD, spd); analogWrite(RIGHT_MOTOR_BACKWARD, 0); }
//       else if (reverse == 1) { analogWrite(RIGHT_MOTOR_BACKWARD, spd); analogWrite(RIGHT_MOTOR_FORWARD, 0); }
//     }
//     else /*if (i == RIGHT) //no need for condition*/ {
//       if      (reverse == 0) { analogWrite(LEFT_MOTOR_FORWARD, spd); analogWrite(LEFT_MOTOR_BACKWARD, 0); }
//       else if (reverse == 1) { analogWrite(LEFT_MOTOR_BACKWARD, spd); analogWrite(LEFT_MOTOR_FORWARD, 0); }
//     }
//   }
  
//   void setMotorSpeeds(int leftSpeed, int rightSpeed) {
//     setMotorSpeed(LEFT, leftSpeed);
//     setMotorSpeed(RIGHT, rightSpeed);
//   }
// #elif defined L298P_MOTOR_DRIVER
//   //1.初始化
//   void initMotorController(){
//     pinMode(LEFT_DIR,OUTPUT);
//     pinMode(LEFT_PWM,OUTPUT);
//     pinMode(RIGHT_DIR,OUTPUT);
//     pinMode(RIGHT_PWM,OUTPUT);
//   }
//   //2.设置单电机的转速
//   void setMotorSpeed(int i, int spd){
//     unsigned char reverse = 0;
  
//     if (spd < 0)
//     {
//       spd = -spd;
//       reverse = 1;
//     }
//     if (spd > 255)
//       spd = 255;
    
//     if (i == LEFT) { 
//       if(reverse == 0){ //正转
//         //为电机输入低电压
//         digitalWrite(LEFT_DIR,LOW);
//         analogWrite(LEFT_PWM,spd);
//       }
//       else if (reverse == 1){ 
//         //为电机输入高电压
//         digitalWrite(LEFT_DIR,HIGH);
//         analogWrite(LEFT_PWM,spd);
//       }
//     }
//     else /*if (i == RIGHT) //no need for condition*/ {
//       if(reverse == 0){//正转
//         digitalWrite(RIGHT_DIR,LOW);
//         analogWrite(RIGHT_PWM,spd);
//       }
//       else if (reverse == 1){
//         digitalWrite(RIGHT_DIR,HIGH);
//         analogWrite(RIGHT_PWM,spd);
//       }
//     }
//   }
//   //3.设置两个电机的转速
//   void setMotorSpeeds(int leftSpeed, int rightSpeed){
//     setMotorSpeed(LEFT, leftSpeed);
//     setMotorSpeed(RIGHT, rightSpeed);
//   }

//--------------------------------------------TB6612FNG-------------------------------------------------------------------------------
// #elif defined TB6612_MOTOR_DRIVER

#ifdef TB6612_MOTOR_DRIVER

  void initMotorController() {

    digitalWrite(STBY, HIGH);
    pinMode(LEFT_MOTOR_FORWARD, OUTPUT);
    pinMode(LEFT_MOTOR_BACKWARD, OUTPUT);
    pinMode(LEFT_MOTOR_PWM, OUTPUT);
    pinMode(RIGHT_MOTOR_FORWARD, OUTPUT);
    pinMode(RIGHT_MOTOR_BACKWARD, OUTPUT);
    pinMode(RIGHT_MOTOR_PWM, OUTPUT);
    
  }
  
  void setMotorSpeed(int i, int spd) {
    unsigned char reverse = 0;
    if (spd < 0) {
      spd = -spd;
      reverse = 1;
    }
    if (spd > 255)
      spd = 255;
    
    if (i == LEFT) { 
      if (reverse == 0) {
        digitalWrite(LEFT_MOTOR_FORWARD, HIGH);
        digitalWrite(LEFT_MOTOR_BACKWARD, LOW);
        analogWrite(LEFT_MOTOR_PWM, spd);
      }
      else if (reverse == 1) {
        digitalWrite(LEFT_MOTOR_FORWARD, LOW);
        digitalWrite(LEFT_MOTOR_BACKWARD, HIGH);
        analogWrite(LEFT_MOTOR_PWM, spd);
      }
    }
    else {
      if (reverse == 0) {
        digitalWrite(RIGHT_MOTOR_FORWARD, HIGH);
        digitalWrite(RIGHT_MOTOR_BACKWARD, LOW);
        analogWrite(RIGHT_MOTOR_PWM, spd);
      }
      else if (reverse == 1) {
        digitalWrite(RIGHT_MOTOR_FORWARD, LOW);
        digitalWrite(RIGHT_MOTOR_BACKWARD, HIGH);
        analogWrite(RIGHT_MOTOR_PWM, spd);
      }
    }
  }
  
  void setMotorSpeeds(int leftSpeed, int rightSpeed) {
    setMotorSpeed(LEFT, leftSpeed);
    setMotorSpeed(RIGHT, rightSpeed);
  }
//-------------------------------------------------------------------------------------------------------------------------------------
#else
  #error A motor driver must be selected!
#endif

#endif
