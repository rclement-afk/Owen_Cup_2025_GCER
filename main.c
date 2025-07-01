//#define R_Down 1717
//#define L_Down 1708
#include <kipr/wombat.h>
#include <constants.h>
#include <threads.h>

int timer;
int main()
{
    int initial_timer=systime();
    int L_Travel=L_Down-760;//960
    int R_Travel=R_Down-784;//784
    int L_Up=L_Down-1541;
    int R_Up=R_Down-1672;

 
    int pink =1;
    int green =2;
    
   // int final_timer = systime()-initial_timer;
   // printf("total time for dropoff = %d",final_timer);
  int battery_percentage=power_level()*100;
printf("\nThe Current Battery level is %d percentage \n",battery_percentage);
  starting_position();
   quick_front_IR_check();
 int num_cups=choose_cups();
  
  
    

    









 







    //printf("\nElapsed time = %d\n", timer);
  //  printf("/nThe total time is %d ms/n",timer-systime());
    return 0;
}
