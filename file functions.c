#include <kipr/wombat.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <constants.h>
#include <time.h>
#include <stddef.h>
#include <stdbool.h>

int rewrite(int left_ticks_per_inch, int right_ticks_per_inch){

    FILE * file1 = fopen("left_wheel1", "r"); 
    char file1_entry[10000];
    fgets(file1_entry, sizeof(file1_entry), file1);
    int left_wheel1 = atoi(file1_entry);
    printf("Left Wheel old: %d,", left_wheel1);
    fclose(file1);

    FILE * file2 = fopen("left_wheel2", "r"); 
    char file2_entry[10000];
    fgets(file2_entry, sizeof(file2_entry), file2);
    int left_wheel2 = atoi(file2_entry);
    printf(" %d,", left_wheel2);
    fclose(file2);

    FILE * file3 = fopen("left_wheel3", "r"); 
    char file3_entry[10000];
    fgets(file3_entry, sizeof(file3_entry), file3);
    int left_wheel3 = atoi(file3_entry);
    printf(" %d,", left_wheel3);
    fclose(file3);

    FILE * file4 = fopen("left_wheel4", "r"); 
    char file4_entry[10000];
    fgets(file4_entry, sizeof(file4_entry), file4);
    int left_wheel4 = atoi(file4_entry);
    printf(" %d,", left_wheel4);
    fclose(file4);

    FILE * file5 = fopen("left_wheel5", "r"); 
    char file5_entry[10000];
    fgets(file5_entry, sizeof(file5_entry), file5);
    int left_wheel5 = atoi(file5_entry);
    printf(" %d; ", left_wheel5);
    fclose(file5);

    FILE * file6 = fopen("right_wheel1", "r"); 
    char file6_entry[10000];
    fgets(file6_entry, sizeof(file6_entry), file6);
    int right_wheel1 = atoi(file6_entry);
    printf("Right Wheel old: %d,", right_wheel1);
    fclose(file6);

    FILE * file7 = fopen("right_wheel2", "r"); 
    char file7_entry[10000];
    fgets(file7_entry, sizeof(file7_entry), file7);
    int right_wheel2 = atoi(file7_entry);
    printf(" %d,", right_wheel2);
    fclose(file7);

    FILE * file8 = fopen("right_wheel3", "r"); 
    char file8_entry[10000];
    fgets(file8_entry, sizeof(file8_entry), file8);
    int right_wheel3 = atoi(file8_entry);
    printf(" %d,", right_wheel3);
    fclose(file8);

    FILE * file9 = fopen("KISS/right_wheel4", "r"); 
    char file9_entry[10000];
    fgets(file9_entry, sizeof(file9_entry), file9);
    int right_wheel4 = atoi(file9_entry);
    printf(" %d,", right_wheel4);
    fclose(file9);

    FILE * file10 = fopen("right_wheel5", "r"); 
    char file10_entry[10000];
    fgets(file10_entry, sizeof(file10_entry), file10);
    int right_wheel5 = atoi(file10_entry);
    printf(" %d; \n", right_wheel5);
    fclose(file10);


    // 1 will always be the oldest value
    file1 = fopen("left_wheel1", "w"); 
    fprintf(file1, "%d", left_wheel2);
    fclose(file1);

    file2 = fopen("left_wheel2", "w"); 
    fprintf(file2, "%d", left_wheel3);
    fclose(file2);

    file3 = fopen("left_wheel3", "w"); 
    fprintf(file3, "%d", left_wheel4);
    fclose(file3);

    file4 = fopen("left_wheel4", "w"); 
    fprintf(file4, "%d", left_wheel5);
    fclose(file4);

    file5 = fopen("left_wheel5", "w"); 
    fprintf(file5, "%d", left_ticks_per_inch);
    fclose(file5);

    file6 = fopen("right_wheel1", "w"); 
    fprintf(file6, "%d", right_wheel2);
    fclose(file6);

    file7 = fopen("right_wheel2", "w"); 
    fprintf(file7, "%d", right_wheel3);
    fclose(file7);

    file8 = fopen("right_wheel3", "w"); 
    fprintf(file8, "%d", right_wheel4);
    fclose(file8);

    file9 = fopen("right_wheel4", "w"); 
    fprintf(file9, "%d", right_wheel5);
    fclose(file9);

    file10 = fopen("right_wheel5", "w"); 
    fprintf(file10, "%d", right_ticks_per_inch);
    fclose(file10);

    printf("Left Wheel new: %d, %d, %d, %d, %d; ", left_wheel2, left_wheel3, left_wheel4, left_wheel5, left_ticks_per_inch);
    printf("Right Wheel new: %d, %d, %d, %d, %d; \n ", right_wheel2, right_wheel3, right_wheel4, right_wheel5, right_ticks_per_inch);

    float left_avg = (left_wheel2 + left_wheel3 + left_wheel4 + left_wheel5 + left_ticks_per_inch)/ 5;

    float right_avg = (right_wheel2 + right_wheel3 + right_wheel4 + right_wheel5 + right_ticks_per_inch) / 5;

    printf("left average: %f, right average: %f,", left_avg, right_avg);

    FILE * file11= fopen("right_mortor_averge", "w"); 
    fprintf(file11, "%f", right_avg); 
    fclose(file11);

    FILE * file12= fopen("left_mortor_averge", "w"); 
    fprintf(file12, "%f", left_avg); 
    fclose(file12);

    return 0;
}


//double Distance = 0.0;
void ticks_to_inches(int target_mav_speed, double distance){
    
    FILE * file995= fopen("FrontClicker.txt", "r"); 
     char line9[16];
    while(fgets(line9, sizeof(line9),file995))

    {printf("%s is front clicker\n", line9);}
    msleep(5);
    fclose(file995);
    int clicker=atof(line9);

    printf(" %d ", clicker);

    FILE *file999 = fopen("LeftMotor.txt","r"); // left motor definition 
    char line1[16];
    while(fgets(line1, sizeof(line1),file999))

    {printf("%s is Left Motor\n", line1);}
    msleep(5);
    fclose(file999);
    int left_motor=atof(line1);

    printf(" %d ", left_motor);

    FILE *file998 = fopen("RightMotor.txt","r"); // left motor definition 
    char line2[16];
    while(fgets(line2, sizeof(line2),file998))

    {printf("%s is Right Motor\n", line2);}
    msleep(5);
    fclose(file998);
    int right_motor=atof(line2);

    printf(" %d ", right_motor);

    FILE *file992 = fopen("BackRightMotor.txt","r"); // left motor definition 
    char line3[16];
    while(fgets(line3, sizeof(line3),file992))

    {printf("%s is BackRight Motor\n", line3);}
    msleep(5);
    fclose(file992);
    int backright_motor=atof(line3);

    printf(" %d ", backright_motor);

    FILE *file993 = fopen("BackLeftMotor.txt","r"); // left motor definition 
    char line4[16];
    while(fgets(line4, sizeof(line4),file993))

    {printf("%s is BackLeft Motor\n", line4);}
    msleep(5);
    fclose(file993);
    int backleft_motor=atof(line4);

    printf(" %d ", backleft_motor);
    
    
  

    //Distance = distance;
    //Distance = Distance * 1.0;
    printf(" %.2f ", distance);
    cmpc(left_motor);
    
    
    cmpc(right_motor);
    
    //double duration_sec = fabs(duration_sec);
    double start_sec = seconds();
    double accel_duration_sec = abs(target_mav_speed)*0.0003;
clicker=0;
    int run_speed = 0 , theta = 0;
    printf("\n here ");
    if( target_mav_speed > 0 && distance > 0){
        printf("\n here1 ");
        while(digital(clicker)==0) {
            printf("\n here2 ");
            run_speed = target_mav_speed;
            if( seconds() - start_sec < accel_duration_sec )
                printf("\n here3 ");
               // run_speed = lerp(0, target_mav_speed, (seconds()-start_sec) / accel_duration_sec );

            mav(left_motor, run_speed - run_speed*theta*0.0001);
            mav(right_motor,run_speed + run_speed*theta*0.0001);
           // mav(backleft_motor, run_speed - run_speed*theta*0.0001);
           // mav(backright_motor,run_speed + run_speed*theta*0.0001);
            msleep(10);
            theta += (gyro_z()-5.35)*2;
        }
    }else{
        while(digital(clicker)==0) {
            if(target_mav_speed < 0){
                run_speed = target_mav_speed;
                if( seconds() - start_sec < accel_duration_sec )
                    run_speed = lerp(0, target_mav_speed, (seconds()-start_sec) / accel_duration_sec );

                mav(left_motor,  run_speed - run_speed*theta*0.0001);
                mav(right_motor,run_speed + run_speed*theta*0.0001);
               // mav(backleft_motor, run_speed - run_speed*theta*0.0001);
                //mav(backright_motor,run_speed + run_speed*theta*0.0001);
                msleep(10);
                theta += (gyro_z()-1)*2;
            }else{
                run_speed = target_mav_speed;
                if( seconds() - start_sec < accel_duration_sec )
                    run_speed = lerp(0, target_mav_speed, (seconds()-start_sec) / accel_duration_sec );

                mav(left_motor,  -1*run_speed - run_speed*theta*0.0001);
                mav(right_motor, -1*run_speed + run_speed*theta*0.0001);
                mav(backleft_motor,  -1*run_speed - run_speed*theta*0.0001);
                mav(backright_motor, -1*run_speed + run_speed*theta*0.0001);
                msleep(10);
                theta += gyro_z()-1;
            }
        } 
    }
    
    int ticks0 = gmpc(right_motor);
    int ticks1 = gmpc(left_motor);
    motor(right_motor, 0);
    motor(left_motor, 0);
    motor(backright_motor, 0);
    motor(backleft_motor, 0);  

    msleep(100);
    double left_ticks_per_inch = distance;
    double right_ticks_per_inch = distance;
    left_ticks_per_inch = ticks0 / distance;//how far will it travel
    right_ticks_per_inch = ticks1 / distance;
    printf("Left wheel ticks = %f, Right wheel ticks = %f\n",left_ticks_per_inch,right_ticks_per_inch);

    FILE * file970= fopen("r_average", "w"); 

    fprintf(file970, "%f",right_ticks_per_inch);
    char line[16];
    while(fgets(line, sizeof(line),file970)){}
    fclose(file970);
    int r_average=atof(line);

    FILE * file969= fopen("l_average", "w"); 
    fprintf(file969, "%f",left_ticks_per_inch);
    char line565[16];
    while(fgets(line565, sizeof(line565),file969)){}
    fclose(file969);
    int l_average=atof(line565);

    printf("Right motor avg:%d \n",r_average);
    printf("Left motor avg:%d \n",l_average);



}

int fill(){

    FILE * file1 = fopen("left_wheel1", "w"); 
    fprintf(file1, "%d", 0);
    fclose(file1);

    FILE * file2 = fopen("left_wheel2", "w"); 
    fprintf(file2, "%d", 0);
    fclose(file2);

    FILE * file3 = fopen("left_wheel3", "w"); 
    fprintf(file3, "%d", 0);
    fclose(file3);

    FILE * file4 = fopen("left_wheel4", "w"); 
    fprintf(file4, "%d", 0);
    fclose(file4);

    FILE * file5 = fopen("left_wheel5", "w"); 
    fprintf(file5, "%d", 0);
    fclose(file5);

    FILE * file6 = fopen("right_wheel1", "w"); 
    fprintf(file6, "%d", 0);
    fclose(file6);

    FILE * file7 = fopen("right_wheel2", "w"); 
    fprintf(file7, "%d", 0);
    fclose(file7);

    FILE * file8 = fopen("right_wheel3", "w"); 
    fprintf(file8, "%d", 0);
    fclose(file8);

    FILE * file9 = fopen("right_wheel4", "w"); 
    fprintf(file9, "%d", 0);
    fclose(file9);

    FILE * file10 = fopen("right_wheel5", "w"); 
    fprintf(file10, "%d", 0);
    fclose(file10);

    return 0;



}

int IR_Ports()
{
    /*char work[] = "workpls";
    set_extra_buttons_visible (1);
    set_a_button_text(work);  
    set_b_button_text ("work");
 	set_c_button_text ("2");
 	set_x_button_text ("3");
 	set_y_button_text ("4");
 	set_z_button_text ("5");*/
    int ITL;
    int ITR;
    int et;
    printf("Select the left sensor\n a=0\n b=1\n c=2\n x=3\n y=4\n z=5");

    while(1)
    {
        if(side_button() == 1)
        {
            while(side_button() == 1){}
            return 8008;
        }
        if(a_button() == 1)
        {
            ITL=0;
            printf(" You have chosen port %d. \n", ITL);
            while(a_button()==1){}
            break;
        }
        if(b_button() == 1)
        {
            ITL=1;
            printf(" You have chosen port %d. \n", ITL);
            while(b_button()==1){}
            break;
        }
        if(c_button() == 1)
        {
            ITL=2;
            printf(" You have chosen port %d. \n", ITL);
            while(c_button()==1){}
            break;
        }
        if(x_button() == 1)
        {
            ITL=3;
            printf(" You have chosen port %d. \n", ITL);
            while(x_button()==1){}
            break;
        }
        if(y_button() == 1)
        {
            ITL=4;
            printf(" You have chosen port %d. \n", ITL);
            while(y_button()==1){}
            break;
        }
        if(z_button() == 1)
        {
            ITL=5; 
            printf(" You have chosen port %d. \n", ITL);
            while(z_button()==1){}
            break;
        }
    }




    msleep(1500);
    display_clear();
    printf("Select the right sensor\n a=0\n b=1\n c=2\n x=3\n y=4\n z=5");
    FILE * file11 = fopen("ITL.txt", "w"); 
    fprintf(file11, "%d", ITL);
    fclose(file11);
    while(1)
    {
        if(side_button() == 1)
        {
            while(side_button() == 1){}
            return 8008;
        }
        if(a_button() == 1)
        {
            ITR=0;
            printf(" You have chosen port %d. \n", ITR);
            while(a_button()==1){}
            break;
        }
        if(b_button() == 1)
        {
            ITR=1;
            printf(" You have chosen port %d. \n", ITR);
            while(b_button()==1){}
            break;
        }
        if(c_button() == 1)
        {
            ITR=2;
            printf(" You have chosen port %d. \n", ITR);
            while(c_button()==1){}
            break;
        }
        if(x_button() == 1)
        {
            ITR=3;
            printf(" You have chosen port %d. \n", ITR);
            while(x_button()==1){}
            break;
        }
        if(y_button() == 1)
        {
            ITR=4;
            printf(" You have chosen port %d. \n", ITR);
            while(y_button()==1){}
            break;
        }
        if(z_button() == 1)
        {
            ITR=5;
            printf(" You have chosen port %d. \n", ITR);
            while(z_button()==1){}
            break;
        }

    }
    msleep(1500);
    FILE * file13 = fopen("ITR.txt", "w"); 
    fprintf(file13, "%d", ITR);
    fclose(file13);


    msleep(1500);
    display_clear();
    printf("Select the et sensor\n a=0\n b=1\n c=2\n x=3\n y=4\n z=5");

    while(1)
    {
        if(side_button() == 1)
        {
            while(side_button() == 1){}
            return 8008;
        }
        if(a_button() == 1)
        {
            et=0;
            printf(" You have chosen port %d. \n", ITR);
            while(a_button()==1){}
            break;
        }
        if(b_button() == 1)
        {
            et=1;
            printf(" You have chosen port %d. \n", ITR);
            while(b_button()==1){}
            break;
        }
        if(c_button() == 1)
        {
            et=2;
            printf(" You have chosen port %d. \n", ITR);
            while(c_button()==1){}
            break;
        }
        if(x_button() == 1)
        {
            et=3;
            printf(" You have chosen port %d. \n", ITR);
            while(x_button()==1){}
            break;
        }
        if(y_button() == 1)
        {
            et=4;
            printf(" You have chosen port %d. \n", ITR);
            while(y_button()==1){}
            break;
        }
        if(z_button() == 1)
        {
            et=5;
            printf(" You have chosen port %d. \n", ITR);
            while(z_button()==1){}
            break;
        }

    }
    msleep(1500);
    FILE * file15 = fopen("et.txt", "w"); 
    fprintf(file15, "%d", et);
    fclose(file15);
    return 5;
}


int wandbval()
{
    int ITR = 1;
    int ITL = 2;
    int itrw;
    int itlw;
    int number;
    int num;
    /*
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                          Take the variables out of file10 and file13
                         					No. We need them - Alex
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                      Mason says hi cutie
                                                           Pancake
                         You should get someone to implement this code with wandb in diagnostics after
                         I implemented it because Camden is incompetent, also made it work better - Alexander Hamilton
                                                            funny haha           yippe i am so happy
    																													 */





















    /* if(side_button() ==1) 
    {
        while(side_button() == 1){}
        return 9001;
    }
    */

    printf("White and Black Midpoint Fetcher started\n");
    while(1)
    {
        while(side_button() == 1)
        {
            while(side_button() == 1){}
            itrw = analog(ITR);
            itlw = analog(ITL);
            printf(" right white value is %d",itrw);
            printf("\n left white value is %d",itlw );
            number  = 5;
        }
        if(number == 5)
        {
            break;
        }
    }
    msleep(1500);
    while(1)
    {
        printf("hi \n");
        while(side_button() == 1)
        {
            while(side_button() == 1){}

            printf("hi\n");

            int itrb = analog(ITR);
            int itlb = analog(ITL);
            printf("\n right black value is %d",itrb);
            printf("\n left black value is %d",itlb);

            int rmidpoint = itrw+itrb;
            rmidpoint = rmidpoint/2;

            int lmidpoint = itlw+itlb;
            lmidpoint = lmidpoint/2;

            FILE * file14 = fopen("rmidpoint", "w"); 
            fprintf(file14, "%d", rmidpoint);
            fclose(file14);

            FILE * file15 = fopen("lmidpoint", "w"); 
            fprintf(file15, "%d", lmidpoint);
            fclose(file15);

            printf("\n right midpoint = %d",rmidpoint);
            printf("\n left midpoint = %d",lmidpoint);
            num = 5;
        }
        if( num == 5)
        {

            break;
        }
    }
    return 420;
}

void ticks_to_inch_def(int target_mav_speed, double distance){


    FILE * file1 = fopen("left_wheel5", "r");

    //target_mav_speed = 1350;
    //distance = 15.0;

    if (file1 == NULL){
        //fill();
        ticks_to_inches(target_mav_speed, distance);
    }else{
        ticks_to_inches(target_mav_speed, distance);
    }
    printf("got to here");
    fclose(file1);


}