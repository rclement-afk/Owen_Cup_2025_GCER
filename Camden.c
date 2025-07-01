#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <constants.h>
#include <time.h>
#include <stddef.h>
#include <stdbool.h>
int L_Travel=L_Down-760;//960
int R_Travel=R_Down-784;//784
int L_Up=L_Down-1541;
int R_Up=R_Down-1672;
void Blue_Cup(){}

void one_cup_left() {

}
void owen_turn_middle()
{}

void right_shift(){
    raise_routine();
    turn1(-45);
    Drive(-1300,5);
    turn1(45); 
    Drive(1300,3.5);
    lower_routine();
}
void supa_left_shift()//used in scenario 3
{
    raise_routine();
    turn1(45);
    Drive(-1300,12);
    turn1(-45);
    Drive(1300,8);
    lower_routine();
}
void supa_right_shift()//used in scenario 1
{
    raise_routine();
    turn1(-45);
    Drive(-1300,12);
    turn1(45);
    Drive(1300,8);
    lower_routine();
}
void scenario1_left_shift()
{
    raise_routine();
    turn1(45); 
    Drive(-1300,6);
    turn1(-45);
    Drive(1300, 4);
    lower_routine();
}

void left_shift(){
    raise_routine();
    turn1(45); 
    Drive(-1300,6);
    turn1(-45);
    Drive(1300, 4);
    lower_routine();
}

void scenario1(int side, int num_cups,int input) {//blue pink green
    int internal_timer = input;
    internal_timer = systime()-input;
    printf("internal_timer = %d \n",internal_timer);
    // PINK =1 
    if (num_cups == 2) {

    }

    else if (num_cups == 3) {
        lower_routine();//should be dumped at 62
        while(internal_timer<second_hold){msleep(5); internal_timer =systime()-input;}//adjusting
        scenario1_left_shift();//positioning for green drop
        while(internal_timer<third_hold){msleep(5); internal_timer =systime()-input;}//adjusting
        supa_right_shift();// positioning for blue
        while(internal_timer<forth_hold){msleep(5); internal_timer =systime()-input;}//this exits scenario and put into
        //time to dump
        raise_routine();
        Drive(-1500,3.0);
        msleep(40);
        turn1(90);
        Drive(1500,4.5);
        set_servo_position(R_Arm,R_Down-200);
    }
}
void scenario2(int side, int num_cups,int input) {//blue green pink
    int internal_timer = input;
    internal_timer = systime()-input;
    printf("internal_timer = %d \n",internal_timer);
    if (num_cups == 2) {

    }


    else if (num_cups == 3) {
        while(internal_timer<first_hold){msleep(5); internal_timer =systime()-input;}//adjusting
        left_shift();
        while(internal_timer<second_hold){msleep(5); internal_timer =systime()-input;}//adjusting
        right_shift();
        while(internal_timer<third_hold){msleep(5); internal_timer =systime()-input;}//adjusting
        right_shift();
        while(internal_timer<forth_hold){msleep(5); internal_timer =systime()-input;}//this exits scenario and put into 
    }
    raise_routine();
    Drive(-1500,3.0);
    msleep(40);
    turn1(90);
    Drive(1500,4.5);
    set_servo_position(R_Arm,R_Down-200);
}

void scenario3(int side, int num_cups,int input) {//pink blue green
    int internal_timer = input;
    internal_timer = systime()-input;
    printf("internal_timer = %d \n",internal_timer);


    if (num_cups == 2) {

    } 
    else if (num_cups == 3) {
        while(internal_timer<first_hold){msleep(5); internal_timer =systime()-input;}//adjusting
        right_shift();
        while(internal_timer<second_hold){msleep(5); internal_timer =systime()-input;}//adjusting
        supa_left_shift();
        while(internal_timer<third_hold){msleep(5); internal_timer =systime()-input;}//adjusting
        right_shift();
        while(internal_timer<forth_hold){msleep(5); internal_timer =systime()-input;}//this exits scenario and put into 

    }
    raise_routine();
    Drive(-1500,3.0);
    msleep(40);
    turn1(90);
    Drive(1500,6.5);
    set_servo_position(R_Arm,R_Down-200);
}

void scenario4(int side, int num_cups,int input) {//pink green blue
    int internal_timer = input;
    internal_timer = systime()-input;
    printf("internal_timer = %d \n",internal_timer);

    if (num_cups == 2) {

    } 
    else if (num_cups == 3) {
        while(internal_timer<first_hold){msleep(5); internal_timer =systime()-input;}//adjusting
        right_shift();
        while(internal_timer<second_hold){msleep(5); internal_timer =systime()-input;}//adjusting
        left_shift();
        while(internal_timer<third_hold){msleep(5); internal_timer =systime()-input;}//adjusting
        left_shift();
        while(internal_timer<forth_hold){msleep(5); internal_timer =systime()-input;}//this exits scenario and put into 

    }
    raise_routine();
    Drive(-1500,3.0);
    msleep(40);
    turn1(90);
    Drive(1500,8.5);
    set_servo_position(R_Arm,R_Down-200);
}

void scenario5(int side, int num_cups,int input) {//green blue pink
    int internal_timer = input;
    internal_timer = systime()-input;
    printf("internal_timer = %d \n",internal_timer);

    ///////////////////////////////////////////////////////////////////////
    //DO WE WANT TO SUPA SHIFT THIS?????///////////////////////////////////
    if (num_cups == 2) {


    } else if (num_cups == 3) {
        while(internal_timer<first_hold){msleep(5); internal_timer =systime()-input;}//adjusting
        left_shift();
        while(internal_timer<second_hold){msleep(5); internal_timer =systime()-input;}//adjusting
        right_shift();
        msleep(30);
        right_shift();
        while(internal_timer<third_hold){msleep(5); internal_timer =systime()-input;}//adjusting
        left_shift();
        while(internal_timer<forth_hold){msleep(5); internal_timer =systime()-input;}//this exits scenario and put into
    }
    raise_routine();
    Drive(-1500,3.0);
    msleep(40);
    turn1(90);
    Drive(1500,6.5);
    set_servo_position(R_Arm,R_Down-200);
}

void scenario6(int side, int num_cups,int input) {//green pink blue

    int internal_timer = input;
    internal_timer = systime()-input;
    printf("internal_timer = %d \n",internal_timer);
    //DO WE WANT TO SUPA SHIFT THIS???////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////
    if (num_cups == 2) {
    } else if (num_cups == 3) {
        while(internal_timer<first_hold){msleep(5); internal_timer =systime()-input;}//adjusting
        lower_routine();
        while(internal_timer<second_hold){msleep(5); internal_timer =systime()-input;}//adjusting
        right_shift();
        while(internal_timer<third_hold){msleep(5); internal_timer =systime()-input;}//adjusting
        left_shift();
        msleep(30);
        left_shift();
        while(internal_timer<forth_hold){msleep(5); internal_timer =systime()-input;}//this exits scenario and put into
        raise_routine();
        Drive(-1500,3.0);
        msleep(40);
        turn1(90);
        Drive(1500,8.5);
        set_servo_position(R_Arm,R_Down-200);
    }
}
int cup_order(int side) {  /// THIS IS FOR TWO CUPS
    printf("\n cup_order 1 \n");
    //int num_cups=2;
    int order = 0;
    int pink = 1;
    //int blue = 0;
    int green = 2;
    int blue_order = 0;
    int pink_order = 0;
    int green_order = 0;
    int timeout = 1000; // Adjust as needed
    if(side_button()==1){wait_for_light(3);}
    shut_down_in(119);
    int initial_time=systime();//THIS IS WHERE INITIAL TIME IS SET//THERE ARE 2 OF THESE!!!
    set_servo_position(R_Arm,600);
    set_servo_position(L_Arm,600);
    msleep(150);
    safe_square_up(1500);
    safe_small_square_up(1400);
    Drive(1350,6);
    msleep(500);
    set_servo_position(L_Arm,100);
    msleep(10);
    set_servo_position(R_Arm,100);
    msleep(500);
    camera_open_black();
    camera_open_black();
    camera_update();
    camera_update();
    camera_update();
    camera_update();






    while (timeout > 0) {
        camera_update();
        if (get_object_count(0) > 0) {
            blue_order = get_object_center_x(0, 0);
            printf("blue=%d\n", blue_order);
        }
        if (get_object_count(1) > 0) {
            pink_order = get_object_center_x(1, 0);
            printf("pink=%d\n", pink_order);
        }
        if (get_object_count(2) > 0) {
            green_order = get_object_center_x(2, 0);
            printf("green=%d\n", green_order);
        }
        if (blue_order > 0 && pink_order > 0 && green_order > 0) {
            break;
        }
        msleep(10);
        timeout--;
    }

    if (timeout == 0) {
        printf("Error: Timeout while detecting objects\n");
        return -1;
    }

    // Determine the scenario
    if (blue_order < pink_order && pink_order < green_order) {
        if (side == pink) {
            printf("Scenario = Scenario 1\n");
            grab_cups(initial_time);
            scenario1(pink, 3,initial_time);
        } else if (side == green) {
            printf("Scenario = Scenario 2\n");
            grab_cups(initial_time);
            scenario2(green, 3,initial_time);
        }
    } else if (blue_order < green_order && green_order < pink_order) {
        if (side == pink) {
            printf("Scenario = Scenario 2\n");
            grab_cups(initial_time);
            scenario2(pink, 3,initial_time);
        } else if (side == green) {
            printf("Scenario = Scenario 1\n");
            grab_cups(initial_time);
            scenario1(green, 3,initial_time);
        }
    } else if (pink_order < blue_order && blue_order < green_order) {
        if (side == pink) {
            printf("Scenario = Scenario 3\n");
            grab_cups(initial_time);
            scenario3(pink, 3,initial_time);
        } else if (side == green) {
            printf("Scenario = Scenario 5\n");
            grab_cups(initial_time);
            scenario5(green, 3,initial_time);
        }
    } else if (pink_order < green_order && green_order < blue_order) {
        if (side == pink) {
            printf("Scenario = Scenario 4\n");
            grab_cups(initial_time);
            scenario4(pink, 3,initial_time);
        } else if (side == green) {
            printf("Scenario = Scenario 6\n");
            grab_cups(initial_time);
            scenario6(green, 3,initial_time);
        }
    } else if (green_order < blue_order && blue_order < pink_order) {
        if (side == pink) {
            printf("Scenario = Scenario 5\n");
            grab_cups(initial_time);
            scenario5(pink, 3,initial_time);
        } else if (side == green) {
            printf("Scenario = Scenario 3\n");
            grab_cups(initial_time);
            scenario3(green, 3,initial_time);
        }
    } else {
        if (side == pink) {
            printf("Scenario = Scenario 6\n");
            grab_cups(initial_time);
            scenario6(pink, 3,initial_time);
        } else if (side == green) {
            printf("Scenario = Scenario 4\n");
            grab_cups(initial_time);
            scenario4(green, 3,initial_time);
        }
    }
    // cup_run(2); // Example call to cup_run with 2 cups

    return order;
}

int choose_side(int num_cups)
{
    set_extra_buttons_visible(1);
    int side;
    printf("\n num_cups: %d", num_cups);
    msleep(2000);

    // side pink=1 green=2

    while (1)
    {
        display_clear();
        printf("A Button = PINK side \n");
        printf("B Button = GREEN side \n");

        if (a_button(1))
        {
            display_clear();
            printf("You chose the PINK side! \n");
            msleep(2000);
            side=1;
            printf("HOLD DOWN SIDE BUTTON FOR WAIT_FOR_LIGHT! \n");
            msleep(1000);
            break;


        }
        else if (b_button(1))
        {
            display_clear();
            printf("You chose the GREEN side! \n");
            msleep(2000);
            side=2;
            printf("HOLD DOWN SIDE BUTTON FOR WAIT_FOR_LIGHT! \n");
            msleep(1000);
            break;

        }
    }
    if(side==2 && num_cups==2)
    {
        printf("\n cups = 2 side = 2");
        msleep(2000);
        cup_order2(2);

    }

    else if(side==2 && num_cups==3)
    {
        printf("\n cups = 3 side = 2");
        msleep(2000);
        cup_order2(2);
    }

    if(side==1 && num_cups==2)
    {
        printf("\n cups = 2 side = 1");
        msleep(2000);
        cup_order2(1);
    }
    else if(side == 1 && num_cups == 3)
    {
        printf("\n cups = 3 side = 1");
        msleep(2000);
        cup_order2(1);
    }

    return side;
}
// Function for right-side drop-off
void drop_off_right() {
}

// Function for left-side drop-off
void drop_off_left() {}

// Function for choosing the side

int choose_cups() {
    set_extra_buttons_visible(1);
    int num_cups;
    //int side;
    while (1) {
        display_clear();
        printf("X Button = 2 Cups \n");
        printf("Y Button = 3 Cups \n");

        if (x_button(1)) {
            display_clear();
            printf("You chose the 2 CUP RUN! \n");
            printf("-- Robot is now getting ready to set the starting position --\n");
            msleep(2000);
            num_cups = 2;
            starting_position();

            choose_side(num_cups);



            break;
        } else if (y_button(1)) {
            display_clear();
            printf("You chose the 3 CUP RUN! \n");
            printf("-- Robot is now getting ready to set the starting position --\n");
            msleep(2000);
            num_cups = 3;
            starting_position();
            choose_side(num_cups);


            break;
        }
    }

    return num_cups;
}
void cup_run(int num_cups) {

}

int   grab_cups(int input){
    int initial_time= input;
    printf("%d is the intro time",initial_time);
    int L_Travel=L_Down-760;//960
    int R_Travel=R_Down-784;//784
printf("%d and %d",L_Travel, R_Travel);
    int internal_timer=1;
    enable_servo(1);
    enable_servo(0);
    enable_servo(2);
    enable_servo(3);
    set_servo_position(L_Arm,L_Down);
    set_servo_position(R_Arm,R_Down);
    msleep(200);
    Spec_Drive(1200,15);
    int left_pos =L_Down;
    int right_pos =R_Down;
    int counter=0;
    while(counter<350)
    {
        counter=counter+1;

        set_servo_position(L_Arm,left_pos);
        set_servo_position(R_Arm,right_pos);
        left_pos = left_pos -2;
        right_pos = right_pos -2;
        msleep(2);
        //printf("%d is the counter value",counter);

    }
    //LIFTING CUPS PAUSE PINEAPPLE
    while(internal_timer<20500){msleep(5); internal_timer =systime()-input;}//adjusting
    //PINEAPPLE 
    //lifting cups
    // set_servo_position(R_Arm,(R_Down-450));
    //    set_servo_position(L_Arm,(L_Down-450));//lifting cups
    turn1(-3);
    Drive(-1400,8);

    //lifting cups
    //  slow_servo(R_Arm,400);
    //  slow_servo(L_Arm,400);//lifting cups

    turn1(-4);
    // set_servo_position(R_Arm,250);
    //    set_servo_position(L_Arm,250);
    //  msleep(100);
    demo_gyro_square_up_small(-1350);//ONLY SKETCHY LINE
    msleep(100);
    enable_servos();
    set_servo_position(L_Arm,780);
    set_servo_position(R_Arm,680);

    safe_square_up_back(-1450);
    Drive(1350,-4.5);
    safe_square_up(1450);
    Drive(1350,8);//this has been shrunk to stay out of bermuda triangle

    turn1(90);
    //ACCEPT THE FIRST SET OF POMS PINEAPPLE

    //PINEAPPLE 



    safe_square_up(1450);
    Drive(-1250,6);
    while(internal_timer<early_hold){msleep(5); internal_timer =systime()-input;}//this leaves first drop site at 3.4 seconds after other bot dumps
    //PINEAPPLE 
    safe_square_up(1500);
    safe_small_square_up(1450);//is this sketchy
    enable_servos();
    raise_routine();
    Drive(1400,21);///THIS WAS ORIGINALLY 22INCHES,CHANGED TO 21 TO INCREASE DISTANCE BETWEEN THE TWO ROBOTS
    turn1(90);

    safe_square_up_back(1500);
    Drive(1500,5.7);
    turn1(-90);
    safe_square_up(1500);
    Drive(-1500,6.25);
    enable_servos();
    lower_routine();
    while(internal_timer<58000){msleep(5); internal_timer =systime()-input;}
    return 0;
}


void starting_position(){
    set_servo_position(L_Arm,1200);
    set_servo_position(R_Arm,1200);
    enable_servos();
    msleep(300);
    safe_square_up(1200);
    set_servo_position(L_Arm,(L_Down-200));
    set_servo_position(R_Arm,(R_Down-200));
    Drive(-1000,5.4);

    msleep(400);

}



int cup_order2(int side) {   // THIS IS FOR 3 CUPS
    printf( "\n cup_order 2 \n");
   // int num_cups=3;
    int order = 0;
    int pink = 1;
   // int blue = 0;
    int green = 2;
    int blue_order = 0;
    int pink_order = 0;
    int green_order = 0;
    int timeout = 1000; // Adjust as needed
    if(side_button()==1){wait_for_light(3);}
    shut_down_in(119.5);
    int initial_time=systime();//THIS IS WHERE INITIAL TIME IS SET//THERE ARE 2 OF THESE!!!
    set_servo_position(R_Arm,600);
    set_servo_position(L_Arm,600);
    msleep(1000);
    safe_square_up(1500);
    safe_small_square_up(1300);
    Drive(1250,7);
    msleep(500);
    set_servo_position(L_Arm,100);
    msleep(10);
    set_servo_position(R_Arm,100);
    msleep(1200);
    camera_open_black();
    camera_open_black();
    camera_update();
    camera_update();
    camera_update();
    camera_update();





    while (timeout > 0) {
        camera_update();
        if (get_object_count(0) > 0) {
            blue_order = get_object_center_x(0, 0);
            printf("blue=%d\n", blue_order);
        }
        if (get_object_count(1) > 0) {
            pink_order = get_object_center_x(1, 0);
            printf("pink=%d\n", pink_order);
        }
        if (get_object_count(2) > 0) {
            green_order = get_object_center_x(2, 0);
            printf("green=%d\n", green_order);
        }
        if (blue_order > 0 && pink_order > 0 && green_order > 0) {
            break;
        }
        msleep(10);
        timeout--;
    }

    if (timeout == 0) {
        printf("Error: Timeout while detecting objects\n");
        return -1;
    }

    // Determine the scenario
    if (blue_order < pink_order && pink_order < green_order) {
        if (side == pink) {
            printf("Scenario = Scenario 1\n");
            grab_cups(initial_time);
            scenario1(side,3,initial_time );

        } else if (side == green) {
            printf("Scenario = Scenario 2\n");
            grab_cups(initial_time);
            scenario2(side, 3,initial_time);
        }
    } else if (blue_order < green_order && green_order < pink_order) {
        if (side == pink) {
            printf("Scenario = Scenario 2\n");
            grab_cups(initial_time);
            scenario2(side, 3,initial_time);
        } else if (side == green) {
            printf("Scenario = Scenario 1\n");
            grab_cups(initial_time);
            scenario1(side, 3,initial_time);
        }
    } else if (pink_order < blue_order && blue_order < green_order) {
        if (side == pink) {
            printf("Scenario = Scenario 3\n");
            grab_cups(initial_time);
            scenario3(side, 3,initial_time);
        } else if (side == green) {
            printf("Scenario = Scenario 5\n");
            grab_cups(initial_time);
            scenario5(side, 3,initial_time);
        }
    } else if (pink_order < green_order && green_order < blue_order) {
        if (side == pink) {
            printf("Scenario = Scenario 4\n");
            grab_cups(initial_time);
            scenario4(side, 3,initial_time);
        } else if (side == green) {
            printf("Scenario = Scenario 6\n");
            grab_cups(initial_time);
            scenario6(side,3,initial_time );
        }
    } else if (green_order < blue_order && blue_order < pink_order) {
        if (side == pink) {
            printf("Scenario = Scenario 5\n");
            grab_cups(initial_time);
            scenario5(side, 3,initial_time);
        } else if (side == green) {
            printf("Scenario = Scenario 3\n");
            grab_cups(initial_time);
            scenario3(side, 3,initial_time);
        }
    } else {
        if (side == pink) {
            printf("Scenario = Scenario 6\n");
            grab_cups(initial_time);
            scenario6(side, 3,initial_time);
        } else if (side == green) {
            printf("Scenario = Scenario 4\n");
            grab_cups(initial_time);
            scenario4(side, 3,initial_time);
        }
    }

    return order;
}
void bully_motor(int port)
{
    int initial = gmpc(port);
    int ticks;
    int rate;
    int x = 0;

    do 
    {
        initial = gmpc(port);
        mav(port, 200);   
        msleep(200);
        ticks = gmpc(port); 
        printf("\n Initial: %d \n ticks: %d",initial,ticks);
        if(x == 0)
        {
            rate = ticks - initial;
            x = 1;
        }
        printf("\n rate: %d", rate);


    }while(ticks-initial >= rate);
    mav(port,-500);
    msleep(120);
    mav(port,0);

}
void raise_routine()
{
    set_servo_position(R_Arm,131);
    set_servo_position(L_Arm,464);
}
void lower_routine()
{
    set_servo_position(L_Arm,916);
    set_servo_position(R_Arm,680);
}
