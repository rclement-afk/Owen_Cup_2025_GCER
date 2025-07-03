//#define R_Down 1717
//#define L_Down 1708
#include <kipr/wombat.h>
#include <constants.h>
#include <threads.h>

int timer;
int main()
{
   /* enable_servos();
     lower_routine();
    msleep(2000);
    raise_routine();
    Drive(-1500,2.0);
     set_servo_position(L_Arm,1570);
    msleep(500);
    Drive(-1500,4.0);
    raise_routine();
    msleep(200);
    turn1(90);*/
    int initial_timer=systime();
    int battery_percentage=power_level()*100;
    printf("\nThe Current Battery level is %d percentage \n",battery_percentage);if(battery_percentage<=39){low_battery_printout();}
   // starting_position();
    quick_front_IR_check();
    int num_cups=choose_cups();

    timer = systime()-initial_timer;
    printf("/nThe total time is %d ms/n",timer);
    return num_cups;
}
