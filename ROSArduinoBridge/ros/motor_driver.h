
// #ifdef L298_MOTOR_DRIVER
//   #define RIGHT_MOTOR_BACKWARD 5
//   #define LEFT_MOTOR_BACKWARD  6
//   #define RIGHT_MOTOR_FORWARD  9
//   #define LEFT_MOTOR_FORWARD   10
//   #define RIGHT_MOTOR_ENABLE 12
//   #define LEFT_MOTOR_ENABLE 13
  
// #elif defined L298P_MOTOR_DRIVER
//   #define LEFT_DIR 4
//   #define LEFT_PWM 5
//   #define RIGHT_DIR 7
//   #define RIGHT_PWM 6

// #elif defined TB6612_MOTOR_DRIVER
#ifdef TB6612_MOTOR_DRIVER
  #define LEFT_MOTOR_BACKWARD  5    //AIN1
  #define LEFT_MOTOR_FORWARD   4    //AIN2
  #define LEFT_MOTOR_PWM 9          //PWMA
  
  #define RIGHT_MOTOR_BACKWARD 6    //BIN1
  #define RIGHT_MOTOR_FORWARD  7    //BIN2
  #define RIGHT_MOTOR_PWM 8         //PWMB
  
  #define STBY 12                   //STBY
#endif

void initMotorController();
void setMotorSpeed(int i, int spd);
void setMotorSpeeds(int leftSpeed, int rightSpeed);
