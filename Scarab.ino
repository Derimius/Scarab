//	SCARAB By Michael Chukwukere (A.K.A. Derimius)

#include <SoftwareSerial.h>
#include <Servo.h>

Servo LC1, LF1, LT1;	// This includes the Servos that control the joints of the first leg of the robot, LC1 (Left Coxa 1), LF1 (Left Femur 1), LT1 (Left Tibia 1)
Servo LC2, LF2, LT2;	// This includes the Servos that control the joints of the second leg of the robot, LC2 (Left Coxa 2), LF2 (Left Femur 2), LT2 (Left Tibia 2)
Servo LC3, LF3, LT3;	// This includes the Servos that control the joints of the third leg of the robot, LC3 (Left Coxa 3), LF3 (Left Femur 3), LT3 (Left Tibia 3)
Servo RC1, RF1, RT1;	// This includes the Servos that control the joints of the first leg of the robot, RC1 (Right Coxa 1), RF1 (Right Femur 1), RT1 (Righit Tibia 1)
Servo RC2, RF2, RT2;	// This includes the Servos that control the joints of the second leg of the robot, RC2 (Right Coxa 2), RF2 (Right Femur 2), RT1 (Righit Tibia 2)
Servo RC3, RF3, RT3;	// This includes the Servos that control the joints of the third leg of the robot, RC3 (Right Coxa 3), RF3 (Right Femur 3), RT3 (Righit Tibia 3)
Servo CLAW;				// This servo controls the mandible gear of the robot

int bluetoothTx = 10;	// This is the Bluetooth Transmission pin
int bluetoothRx = 11;	// This is the Bluetooth Reception pin

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);


int Received = 0;
int DELAY = 5;
int MODE = 0;
bool impair_start = false;

int FM1 = 0;
int FM2 = 0;
int FM3 = 0;
int FM4 = 0;
int FM5 = 0;
int FM6 = 0;
int FM7 = 0;
int FM8 = 0;

// To set the starting angles of the servos

int home_LC1 = 90;
int home_LF1 = 90;
int home_LT1 = 90;

int home_LC2 = 90;
int home_LF2 = 90;
int home_LT2 = 90;

int home_LC3 = 90;
int home_LF3 = 90;
int home_LT3 = 90;

int home_RC1 = 90;
int home_RF1 = 90;
int home_RT1 = 90;

int home_RC2 = 90;
int home_RF2 = 90;
int home_RT2 = 90;

int home_RC3 = 90;
int home_RF3 = 90;
int home_RT3 = 90;

int home_CLAW = 90;


// Declare the pin locations of each servo
void setup() {
    Serial.begin(9600);
    bluetooth.begin(9600);
    
    LC1.attach(7);
    LF1.attach(6);
    LT1.attach(5);
    
    LC2.attach(23);
    LF2.attach(9);
    LT2.attach(8);
    
    LC3.attach(13);
    LF3.attach(12);
    LT3.attach(22);
    
    RC1.attach(42);
    RF1.attach(43);
    RT1.attach(44);
    
    RC2.attach(49);
    RF2.attach(50);
    RT3.attach(51);
    
    RC3.attach(46);
    RF3.attach(47);
    RT3.attach(48);
    
    CLAW.attach(35);
    
}



void loop(){
    
    if(bluetooth.available()>0)
  {
        Received = bluetooth.read();
        Serial.println(Received);
    if (Received == 0)
    {
        MODE = 0;
    
    impair_start = false;
    FM1 = 0;
    FM2 = 0;
    FM3 = 0;
    FM4 = 0;
    FM5 = 0;
    FM6 = 0;
    FM7 = 0;
    FM8 = 0;
    }
    
    if (Received == 1)
    { 
        MODE = 1;
    }
    
    if (Received == 2)
    { 
        MODE = 2;
    }
    
    if (Received == 3)
    { 
        MODE = 3;
    }
    
    if (Received == 4)
    { 
        MODE = 4;
    }
    
    if (Received == 5)
    { 
        MODE = 5;
    }
    
    if (Received == 6)
    { 
        MODE = 6;
    }
    
    if (Received == 7)
    { 
        MODE = 7;
    }
    
    if (Received == 8)
    {
        MODE = 8;
    }
    
    if (Received >= 12)
    {
      DELAY = map(Received,15,100,5,80);  
    }
    
  }


//Home Position
if(MODE == 0){
    set_home_pos();
}


//Move Forward
if(MODE == 1){
    move_frwd();
}


//Move Backwards
if(MODE == 2){
    move_bwd();
}


//Move Right
if(MODE == 3){
    move_right();
}


//Move Left
if(MODE == 4){
    move_left();
}


//Rotate Left
if(MODE == 5){
    rotate_left();
}


//Rotate Right
if(MODE == 6){
    rotate_right();
}



delay(DELAY); //This adds delay of the loop, and controls the speed

}




///SET THE HOME POSITION 

void set_home_pos()
{
    LC1.write(home_LC1);
    LF1.write(home_LF1);
    LT1.write(home_LT1);
    
    LC2.write(home_LC2);
    LF2.write(home_LF2);
    LT2.write(home_LT2);
    
    LC3.write(home_LC3);
    LF3.write(home_LF3);
    LT3.write(home_LT3);
    
    RC1.write(home_RC1);
    RF1.write(home_RF1);
    RT1.write(home_RT1);
    
    RC2.write(home_RC2);
    RF2.write(home_RF2);
    RT2.write(home_RT2);
    
    RC3.write(home_RC3);
    RF3.write(home_RF3);
    RT3.write(home_RT3);
    
    CLAW.write(home_CLAW);
    
}///END OF CODE


///MOVE FORWARD 
void move_frwd(){
    
    //STEP ONE
    
    //impair lift by 10 degrees
    if (FM1 <=10)
    {
        LF1.write(home_LF1 - FM1);
        LT1.write(home_LT1 - FM1);
        LF3.write(home_LF3 - FM1);
        LT3.write(home_LT3 - FM1);
        RF2.write(home_RF2 - FM1);
        RT2.write(home_RT3 - FM1);
        FM1++;
    }
    
    
    //impair rotate coxae forward 30 degrees. 
    if (FM2 <= 30)
    {
        LC1.write(home_LC1 - FM2);
        LC3.write(home_LC3 - FM2);
        RC2.write(home_RC2 + FM2);
        FM2++;
    }
    
    
    //impair touch ground -10 degrees.
    if (FM2 > 20 && FM3 <=10)
    {
        LF1.write(home_LF1 + FM3);
        LT1.write(home_LT1 + FM3);
        LF3.write(home_LF3 + FM3);
        LT3.write(home_LF3 + FM3);
        RF2.write(home_RF2 + FM3);
        RT2.write(home_RT2 + FM3);
        FM3++;
    }
    
    
    //impair rotate backward -30 degrees.
    if (FM2 >= 30)
    {
        LC1.write(home_LC1 - FM4);
        LC3.write(home_LC3 - FM4);
        RC2.write(home_RC2 - FM4);
        FM4++;
        impair_start = true;
    }
    
    if(FM4 >= 30) {
        FM1 = 0;
        FM2 = 0;
        FM3 = 0;
        FM4 = 0;
    }
    
    
    //STEP TWO
    
    if (impair_start){
        //Pair lift 10 degrees
        if (FM5 <=10)
        {
            LF2.write(home_LF2 - FM5);
            LT2.write(home_LT2 - FM5);
            RF1.write(home_RF1 - FM5);
            RT1.write(home_RT1 - FM5);
            RF3.write(home_RF3 - FM5);
            RT3.write(home_RT3 - FM5);
            FM5++;
        }
        
        
        //Pair rotate forward 30 degrees
        if (FM6 <=30)
        {
            LC2.write(home_LC2 - FM6);
            RC1.write(home_RC1 + FM6);
            RC3.write(home_RC3 + FM6);
            FM6++;
        }
        
        
        //Pair touch ground -10 degrees
        if (FM6 > 20 && FM7 <=10)
        {
            LF2.write(home_LF2 + FM7);
            LT2.write(home_LT2 + FM7);
            RF1.write(home_RF1 + FM7);
            RT1.write(home_RT1 + FM7);
            RF3.write(home_RF3 + FM7);
            RT3.write(home_RT3 + FM7);
            FM7++;
        }
        
        
        //Pair rotate backward -30 degrees
        if (FM6 >= 30)
        {
            LC2.write(home_LC2 + FM8);
            RC1.write(home_RC1 - FM8);
            RC3.write(home_RC3 - FM8);
            FM8++;
        }
        
        if(FM8 >= 30)
        {
            impair_start = false;
            FM5 = 0;
            FM6 = 0;
            FM7 = 0;
            FM8 = 0;
        }
        
    }
    
} ///END MOVE FORWARD



///MOVE BACKWARDS
void move_bwd(){
    
    //STEP ONE
    
    //impair Lift 10 degrees
    if (FM1 <=10)
    {
        LF1.write(home_LF1 - FM1);
        LT1.write(home_LT1 - FM1);
        LF3.write(home_LF3 - FM1);
        LT3.write(home_LT3 - FM1);
        RF2.write(home_RF2 - FM1);
        RT2.write(home_RT2 - FM1);
        FM1++;
    }
    
    //impair rotate coxae backward -30 degrees
    if (FM2 <= 30)
    {
        LC1.write(home_LC1 + FM2);
        LC3.write(home_LC3 + FM2);
        RC2.write(home_RC2 - FM2);
        FM2++;
    }
    
    //impair touch ground-10 degrees
    if (FM2 > 20 && FM3 <=10)
    {
        LF1.write(home_LF1 + FM3);
        LT1.write(home_LT1 + FM3);
        LF3.write(home_LF3 + FM3);
        LT3.write(home_LF3 + FM3);
        RF2.write(home_RF2 + FM3);
        RT2.write(home_RT2 + FM3);
        FM3++;
    }
    
    //impair rotate coxae forward 30 degrees
    if (FM2 >= 30)
    {
        LC1.write(home_LC1 - FM4);
        LC3.write(home_LC3 - FM4);
        RC2.write(home_RC2 + FM4);
        FM4++;
        impair_start = true;
    }
    if (FM4 >= 30)
    {
        FM1 = 0;
        FM2 = 0;
        FM3 = 0;
        FM4 = 0;
    }
    
    
    ///STEP TWO
    
    if (impair_start){
        //Pair Lift 10 degrees
        if (FM5 <=10)
        {
            LF2.write(home_LF2 - FM5);
            LT2.write(home_LT2 - FM5);
            RF1.write(home_RF1 - FM5);
            RT1.write(home_RT1 - FM5);
            RF3.write(home_RF3 - FM5);
            RT3.write(home_RT3 - FM5);
            FM5++;
        }
        
        //Pair rotate backward -30 degrees
        if (FM6 <= 30)
        {
            LC2.write(home_LC2 + FM6);
            RC1.write(home_RC1 - FM6);
            RC3.write(home_RC3 - FM6);
            FM6++;
        }
        
        //Pair touch ground -10 degrees
        if (FM6 > 20 && FM7 <=10)
        {
            LF2.write(home_LF2 + FM7);
            LT2.write(home_LT2 + FM7);
            RF1.write(home_RF1 + FM7);
            RT1.write(home_RT1 + FM7);
            RF3.write(home_RF3 + FM7);
            RT3.write(home_RT3 + FM7);
            FM7++;
        }
        
        //Pair rotate forward 30 degrees
        if (FM6 >= 30)
        {
            LC2.write(home_LC2 - FM8);
            RC1.write(home_RC1 + FM8);
            RC3.write(home_RC3 + FM8);
            FM8++;
        }
        
        if(FM8 >= 30){
            FM5 = 0;
            FM6 = 0;
            FM7 = 0;
            FM8 = 0;
        }
    }
}///END MOVE BACKWARDS 



///ROTATE LEFT 
void rotate_left(){
    
    
    ///STEP ONE 
    
    //impair Lift 10 degrees
    if (FM1 <=10)
    {
        LF1.write(home_LF1 - FM1);
        LT1.write(home_LT1 - FM1);
        LF3.write(home_LF3 - FM1);
        LT3.write(home_LT3 - FM1);
        RF2.write(home_RF2 - FM1);
        RT2.write(home_RT2 - FM1);
        FM1++;
    }
    
    //impair rotate coxae forward 30 degrees
    if (FM2 <= 30)
    {
        LC1.write(home_LC1 - FM2);
        LC3.write(home_LC3 - FM2);
        RC2.write(home_RC2 - FM2);
        FM2++;
    }
    
    
    //impair touch ground -10 degrees
    if (FM2 > 20 && FM3 <=10)
    {
        LF1.write(home_LF1 + FM3);
        LT1.write(home_LT1 + FM3);
        LF3.write(home_LF3 + FM3);
        LT3.write(home_LT3 + FM3);
        RF2.write(home_RF2 + FM3);
        RT2.write(home_RT2 + FM3);
        FM3++;
    }
    
    //impair rotate coxae backward -30 degrees
    if (FM2 >= 30)
    {
        LC1.write(home_LC1 + FM4);
        LC3.write(home_LC3 + FM4);
        RC2.write(home_RC2 + FM4);
        FM4++;
        impair_start = true;
    }
    
    if(FM4 >= 30)
    {
        FM1 = 0;
        FM2 = 0;
        FM3 = 0;
        FM4 = 0;
    }
    
    ///STEP TWO
    
    if(impair_start)
    {
        //Pair lift 10 degrees
        if (FM5 <=10)
        {
            LF2.write(home_LF2 - FM5);
            LT2.write(home_LT2 - FM5);
            RF1.write(home_RF1 - FM5);
            RT1.write(home_RT1 - FM5);
            RF3.write(home_RF3 - FM5);
            RT3.write(home_RT3 - FM5);
            FM5++;
        }
        
        //Pair rotate coxae forward 30 degrees
        if (FM6 <= 30)
        {
            LC2.write(home_LC2 - FM6);
            RC1.write(home_RC1 - FM6);
            RC3.write(home_RC3 - FM6);
            FM6++;
        }
        
        
        //Pair touch ground -10 degrees
        if (FM6 > 20 && FM7 <=10)
        {
            LF2.write(home_LF2 + FM7);
            LT2.write(home_LT2 + FM7);
            RF1.write(home_RF1 + FM7);
            RT1.write(home_RT1 + FM7);
            RF3.write(home_RF3 + FM7);
            RT3.write(home_RT3 + FM7);
            FM7++;
        }
        
        
        //Pair rotate coxae backward -30 degrees
        if (FM6 >= 30)
        {
            LC2.write(home_LC2 + FM8);
            RC1.write(home_RC1 + FM8);
            RC3.write(home_RC3 + FM8);
            FM8++;
        }
        
        if(FM8 >= 30) 
        {
            impair_start = false;
            FM5 = 0;
            FM6 = 0;
            FM7 = 0;
            FM8 = 0;
        }
    }
    
}///END ROTATE LEFT


///ROTATE RIGHT

void rotate_right(){
    
    
    ///STEP ONE 
    
    //impair Lift 10 degrees
    if (FM1 <=10)
    {
        LF1.write(home_LF1 - FM1);
        LT1.write(home_LT1 - FM1);
        LF3.write(home_LF3 - FM1);
        LT3.write(home_LT3 - FM1);
        RF2.write(home_RF2 - FM1);
        RT2.write(home_RT2 - FM1);
        FM1++;
    }
    
    //impair rotate coxae forward 30 degrees
    if (FM2 <= 30)
    {
        LC1.write(home_LC1 + FM2);
        LC3.write(home_LC3 + FM2);
        RC2.write(home_RC2 + FM2);
        FM2++;
    }
    
    
    //impair touch ground -10 degrees
    if (FM2 > 20 && FM3 <=10)
    {
        LF1.write(home_LF1 + FM3);
        LT1.write(home_LT1 + FM3);
        LF3.write(home_LF3 + FM3);
        LT3.write(home_LT3 + FM3);
        RF2.write(home_RF2 + FM3);
        RT2.write(home_RT2 + FM3);
        FM3++;
    }
    
    //impair rotate coxae backward -30 degrees
    if (FM2 >= 30)
    {
        LC1.write(home_LC1 - FM4);
        LC3.write(home_LC3 - FM4);
        RC2.write(home_RC2 - FM4);
        FM4++;
        impair_start = true;
    }
    
    if(FM4 >= 30)
    {
        FM1 = 0;
        FM2 = 0;
        FM3 = 0;
        FM4 = 0;
    }
    
    ///STEP TWO
    
    if(impair_start)
    {
        //Pair lift 10 degrees
        if (FM5 <=10)
        {
            LF2.write(home_LF2 - FM5);
            LT2.write(home_LT2 - FM5);
            RF1.write(home_RF1 - FM5);
            RT1.write(home_RT1 - FM5);
            RF3.write(home_RF3 - FM5);
            RT3.write(home_RT3 - FM5);
            FM5++;
        }
        
        //Pair rotate coxae forward 30 degrees
        if (FM6 <= 30)
        {
            LC2.write(home_LC2 + FM6);
            RC1.write(home_RC1 + FM6);
            RC3.write(home_RC3 + FM6);
            FM6++;
        }
        
        
        //Pair touch ground -10 degrees
        if (FM6 > 20 && FM7 <=10)
        {
            LF2.write(home_LF2 + FM7);
            LT2.write(home_LT2 + FM7);
            RF1.write(home_RF1 + FM7);
            RT1.write(home_RT1 + FM7);
            RF3.write(home_RF3 + FM7);
            RT3.write(home_RT3 + FM7);
            FM7++;
        }
        
        
        //Pair rotate coxae backward -30 degrees
        if (FM6 >= 30)
        {
            LC2.write(home_LC2 - FM8);
            RC1.write(home_RC1 - FM8);
            RC3.write(home_RC3 - FM8);
            FM8++;
        }
        
        if(FM8 >= 30) 
        {
            FM5 = 0;
            FM6 = 0;
            FM7 = 0;
            FM8 = 0;
        }
    }
    
}///END ROTATE RIGHT


///MOVE RIGHT
void move_right(){
    
    //impair Motor 2 -20 Motor 3 +20
    if (FM1 <= 20)
    {
        LF1.write(home_LF1 + FM1);
        LT1.write(home_LT1 + FM1);
        
        LF2.write(home_LF2 + FM1);
        LT2.write(home_LT2 - FM1*2);
        
        LF3.write(home_LF3 + FM1);
        LT3.write(home_LT3 + FM1);
        
        RF1.write(home_RF1 - FM1);
        RT1.write(home_RT1 + FM1*2);
        
        RF2.write(home_RF2 + FM1);
        RT2.write(home_RT2 - FM1);
        
        RF3.write(home_RF3 - FM1);
        RT3.write(home_RT3 + FM1*2);
        FM1++;
    }
    
    if(FM1 >=20 && FM2 <= 20)
    {
        LF2.write(home_LF2 + FM1 + FM2);
        LT2.write(home_LT2 - FM1*2 + FM2*2);
        
        RF1.write(home_RF1 - FM1*2 + FM2);
        RT1.write(home_RT1 + FM1*2 + FM2*2);
        
        RF3.write(home_RF3 - FM1 + FM2);
        RT3.write(home_RT3 + FM1*2 - FM2*2);
        FM2++;
    }
    
    if(FM2 >= 20 && FM3 <= 20)
    {
        LF1.write(home_LF1 + FM1 - FM3);
        LT1.write(home_LT1 + FM1 - FM1);
        
        LF3.write(home_LF3 + FM1 - FM3);
        LT3.write(home_LT3 + FM1 - FM3);
        
        RF2.write(home_RF2 + FM1 - FM3);
        RT2.write(home_RT2 - FM1 + FM3);
        FM3++;
    }
    
    if(FM3 >= 20)
    {
        FM1 = 0;
        FM2 = 0;
        FM3 = 0;
    }
    
}///END OF MOVE RIGHT



///MOVE LEFT

void move_left(){
    //impair Motor 2 -20 Motor 3 +20
    
    if (FM1 <= 20)
    {
        RF1.write(home_RF1 + FM1);
        RT1.write(home_RT1 + FM1);
        
        RF2.write(home_RF2 + FM1);
        RT2.write(home_RT2 - FM1*2);
        
        RF3.write(home_RF3 + FM1);
        RT3.write(home_RT3 + FM1);
        
        LF3.write(home_LF3 - FM1);
        LT3.write(home_LT3 + FM1*2);
        
        LF2.write(home_LF2 + FM1);
        LT2.write(home_LT2 - FM1);
        
        LF1.write(home_LF1 - FM1);
        LT1.write(home_LT1 + FM1*2);
        FM1++;
    }
    
    if(FM1 >= 20 && FM2 <= 20)
    {
        RF2.write(home_RF2 + FM1 + FM2);
        RT3.write(home_RT3 + FM1*2 + FM1*2);
        
        LF3.write(home_LF3 - FM1 + FM2);
        LT3.write(home_LT3 - FM1*2 - FM2*2);
        
        LF1.write(home_LF1 - FM1 + FM2);
        LT1.write(home_LT1 - FM1*2 - FM2*2);
        FM2++;
    }
    
    if(FM2 >= 20 && FM3 <= 20)
    {
        RF3.write(home_RF3 + FM1 - FM3);
        RT3.write(home_RT3 + FM1 - FM1);
        
        RF1.write(home_RF1 + FM1 - FM3);
        RT1.write(home_RT1 + FM1 - FM3);
        
        LF2.write(home_LT2 - FM1 + FM3);
        LT2.write(home_LT2 - FM1 + FM3);
        FM3++;
    }
    
    if(FM3 >= 20)
    {
        FM1 = 0;
        FM2 = 0;
        FM3 = 0;
    }
    
}///END OF CODE (MOVE LEFT)