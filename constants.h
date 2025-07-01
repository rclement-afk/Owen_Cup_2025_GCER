#ifndef STRUCT_CONSTANTS
#define STRUCT_CONSTANTS
#include <kipr/wombat.h>
#include <math.h>
#define gyro_axis_up_down()      (gyro_z())
#define gyro_axis_left_right() 	 (gyro_x())
#define gyro_axis_forward_back() (gyro_y())
#define turn 600000//this is a garbage variable used to make the god function work
#define forward 5318008
#define  L_Arm 3
#define R_Arm 0
#define R_Down 1717
#define L_Down 1708
#define cup_hold 20000
#define early_hold 39000//after first pom dump in startbox
#define first_hold 58000//after pom dump
#define second_hold 69800//after first drink
#define third_hold 86800//after second drink
#define forth_hold 110800//after third drink


// left motor = black wire toward screen
// right motor = red toward screen

struct {
    int rm,lm; 

    double nw_bias;
}static const bias = {
    .rm = 367,
    .lm = 369,
    .nw_bias = -0.5,
};


struct {
    int left,right,backleft,backright,l_average,r_average;   
}static const motors = {
    .left = 2,
    .right= 1,
    .backleft = 0,
    .backright = 0,
    .l_average = 341,
    .r_average =380


};

struct {
    int left, right,et;
    int black, white, lmidpoint,rmidpoint;
}static const irs = {
    .left  = 1,
    .right = 0,
    .black = 3700,
    .white = 2000,
    .lmidpoint = 1800,
    .rmidpoint = 1800,
    .et = 5,
};

typedef int intfunc();
struct {
    intfunc *l, *r, *lf, *rf;
    int black, white, midpoint;
}static const cliffs = {
    .l = get_create_lcliff,
    .r = get_create_rcliff,
    .lf = get_create_lfcliff,
    .rf = get_create_rfcliff,
    .black = 3800,
    .white = 2000,
    .midpoint = 3000
};

struct {
    int min[4], max[4];
}static const servos = {
    .min = {150,	960,	680,	1830},//calibrate servo on ground 1800
    .max = {2000,	2047,	2000,	964}
}; //ports:	 ^0		 ^1		 ^2		 ^3	
//port 1 = drawer controller

struct {
    int et, light, slider;
}static const analogs = {
    .et = 0000,
    .light = 0000,
    .slider = 0000
};

struct digital {
    int l, r, reset, thatclicker;
}static const digitals = {
    .l = 0000,
    .r = 0000,
    .reset = 0000,
    .thatclicker = 0
};
////////////////
void write();
int wandbval();
int fill();
int rewrite();
void ticks_to_inches(int target_mav_speed, double distance);
int single_write(int da_number);
#endif
//////////////////////////////////////////////////////////////////
#ifndef LOCOMOTION_LIBRARY
#define LOCOMOTION_LIBRARY

#define square_up 65000
#define squareup 65000
#define square 65000
#define Square_up 65000
#define Square_Up 65000

// General Utilities (exposed)
void motor_motor(int left, int right);
unsigned int milliseconds();
double new_calibrate_z();
double new_calibrate_y();

#define Left 5000
#define Right 5001 // numbers are placeholders; change to whatever you want
#define sign(x) ({__typeof__ (x) _x = x; (_x>=0) - (_x<0); })
#define min(x,y) ({__typeof__ (x) _x = x; __typeof__ (y) _y = y; _x <= _y ? _x : _y;})
#define max(x,y) ({__typeof__ (x) _x = x; __typeof__ (y) _y = y; _x >= _y ? _x : _y;})
#define lerp(x,y,f) ({__typeof__ (f) _f = f; ((x) * (1.0 - _f)) + ((y) * _f);})

#define vrg_cnt(vrg1,vrg2,vrg3,vrg4,vrg5,vrg6,vrg7,vrg8,vrgN, ...) vrgN
#define vrg_argn(...) vrg_cnt(__VA_ARGS__, 8, 7, 6, 5, 4, 3, 2, 1, 0)
#define vrg_cat0(x,y) x ## y
#define vrg_cat(x,y) vrg_cat0(x,y)
#define vrg(vrg_f,...) vrg_cat(vrg_f, vrg_argn(__VA_ARGS__))(__VA_ARGS__)

// PID Structures and Functions
struct pid_struct {
    double p, i, d;
    double i_sum;
    double error_prev;
    unsigned long now_prev;
};

struct pid_int {
    double p, i, d;
    int i_sum;
    int error_prev;
    unsigned long now_prev;
};
struct {
    int left, right,et;
    int black, white, lmidpoint,rmidpoint;
}static const small_irs = {
    .left  = 4,
    .right = 5,
    .black = 3700,
    .white = 2000,
    .lmidpoint = 3200,
    .rmidpoint = 3200,
    .et = 5,
};
struct pid_struct* pid_create(float p, float i, float d);
double pid_calc(struct pid_struct *pid, float setpoint, float process_var);
void pid_destroy(struct pid_struct *pid);

// Gyro Calibration
int gyro_x_bias();
int gyro_y_bias();
int gyro_z_bias();
double calibrate_gyro();

// Smart Servo Controls
#define smart_servo_flags_blocking 0x1
#define smart_servo_flags_sleepy 0x2
#define smart_servo_flags_unused 0xC

#define percent_default (50)
#define time_default (1.5)
#define delay_default (0)
#define flags_default (0x0)

unsigned int smart_servoX(unsigned short port, short percent, unsigned long duration_ms, unsigned long delay_ms, unsigned short flags);
#define smart_servo_ms(x,y,z,a,b) smart_servoX(x,y,z,a,b)
#define smart_servo_sec(x,y,z,a,b) smart_servoX(x,y,z*1000,a*1000,b)
struct locolib_servo_entry* smart_servo_search_id(unsigned int id);
void smart_servo_document_queue();

#define smart_servo(...) vrg(smart_servo, __VA_ARGS__)
#define smart_servo1(x) smart_servo_sec(x, percent_default, time_default, delay_default, flags_default)
#define smart_servo2(x,y) smart_servo_sec(x, y, time_default, delay_default, flags_default)
#define smart_servo3(x,y,z) smart_servo_sec(x, y, z, delay_default, flags_default)
#define smart_servo4(x,y,z,a) smart_servo_sec(x, y, z, a, flags_default)
#define smart_servo5(x,y,z,a,b) smart_servo_sec(x, y, z, a, b)

typedef int int_func(); 
void demo_gyro_drive(int speed, double distance, int_func exit_condition);
void demo_gyro_turn(short angle_degrees, float radius);
void demo_gyro_square_up(int speed);
void demo_gyro_drive1(int speed, double distance);

int Diag();
//extern int button;//is this used?
int servo_def();
int side_def();
void calibration_routine();
extern int motor_def();
int digital_def();
int IR_Ports();
void  ticks_to_inch_def(int target_mav_speed, double distance);


// External Declarations



extern const int right_cup_claw;
extern const int left_cup_claw;
// These are new and came from run.h
extern const int claw;
extern const int arm;

void Drive(int target_mav_speed, double inches);
extern double bias1;
void tick_turn(double degr);
void turn1(int angle);
void one_wheel_turn(int wheel, int degree);
void drive_ET(int measure, int speed);
void four_wheel_drive(int target_mav_speed, double inches);
void omni_strafe(double degree, double inches);
void four_turn(double degrees);
void position_starting_box();
int turn_numbertwo();
int follow_object();
int rotate_object();
void demo_gyro_square_up_small(int speed);
// Camden.c Variables
void drink_drop_left();
void two_cups_left();
void drink_drop_left();
void two_cups_right();
int cup_order(int side);
void drop_off_right();
void blue_left_side_load();
void scenario1(int side, int num_cups,int input),scenario2(int side, int num_cups,int input),scenario3(int side, int num_cups,int input),scenario4(int side, int num_cups,int input),scenario5(int side, int num_cups,int input),scenario6(int side, int num_cups,int input);
//double HOLDER;
void two_left(),one_right(),owen_turn(),right_side_load(int amount);
void left_shift();
void middle_shift();
void right_shift();
void slow_servo_rate(int port, int position, int rate);
void slow_servo(int port, int position);
int colorg();
extern int timer;
void bully_motor();
void Spec_Drive(int target_mav_speed,double inches);
void safe_square_up(int speed);
void safe_square_up_back(int speed);
void safe_small_square_up(int speed);
void  quick_front_IR_check();
void raise_routine();
void lower_routine();
void supa_left_shift();
int grab_cups(int input);
void scenario1_left_shift();
void supa_right_shift();
void starting_position();
#endif


