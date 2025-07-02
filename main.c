//#define R_Down 1717
//#define L_Down 1708
#include <kipr/wombat.h>
#include <constants.h>
#include <threads.h>

int timer;
int main()
{
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
