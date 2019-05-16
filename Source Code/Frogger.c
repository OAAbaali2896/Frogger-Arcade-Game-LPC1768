#include "LPC17xx.H"
#include "GLCD.h"
#include "GLCD_UTILS.h"
#include <stdlib.h>
#include "uart.h"
#include "system_LPC17xx.h"
		

		//UART Variables 
		extern volatile uint32_t UART0_Count;
		extern volatile uint8_t UART0_Buffer[BUFSIZE];
		
		//Variables for the game
		int c,c1,c2,c3,c4,c5,c6;
		int b,b1,b2,b3,b4,b5,b6;
		int d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13,d14,d15,d16,d17,d18;
		int s1,s2,s3,s4,s5,s6,s7,s8,s9,s10,s11,s12;
		int k;
		int lilly1=0,lilly2=0,lilly3=0,lilly4=0,lilly5=0;
		int success=0;
		int faliure=4;
		int pause=0;
		
		//strigs for the game
		unsigned char d[]="Frog is on Lilly Pad";
		unsigned char e[]="Frog is Down";
		unsigned char f[]="Game Over";
		unsigned char g[]="You Win";
		unsigned char h[]="Insert a Coin";
		unsigned char u[]="3";
		unsigned char i[]="2";
		unsigned char o[]="1";
		unsigned char p[]="0";
		unsigned char Pause[]="Game is Paused";
		unsigned char Pause1[]="Game will Resume";
		unsigned char welcome[]="Welcome to Frogger";
		unsigned char coin1[]="Insert coin";
		unsigned char coin2[]="to play";
	
		///////SAFE ZONE/////
		int SafeZone_x=319; 
		int SafeZone_y=239;        
		
		///////Frog/////
		int W_Frog=10;
		int Frog_x=319/2; 
		int Frog_y=231; 
		int Frog_cx=19;
		int Frog_cy=18;
		
		///////Traffic regions/////
		int Traffic_x=319; 
		int Traffic_y=239;        
		
		///Traffic 1///
		///Lane 1///
		int T1L1Car1_L=50;
		int T1L1Car1_R=74;
		int T1L1Car2_L=150;
		int T1L1Car2_R=174;
		int T1L1Car3_L=240;
		int T1L1Car3_R=264;
		int Traffic1lane1_y=239;
		///Lane 2///
		int T1L2Bus1_L=20;
		int T1L2Bus1_R=120;
		int T1L2Bus2_L=185;
		int T1L2Bus2_R=285;
		int Traffic1lane2_y=239;
		///Lane 3///
		int T1L3Car1_L=50;
		int T1L3Car1_R=74;
		int T1L3Car2_L=150;
		int T1L3Car2_R=174;
		int T1L3Car3_L=240;
		int T1L3Car3_R=264;
		int Traffic1lane3_y=239;
		///Lane 4///
		int T1L4Bus1_L=20;
		int T1L4Bus1_R=120;
		int T1L4Bus2_L=185;
		int T1L4Bus2_R=285;
		int Traffic1lane4_y=239;
		///Lane 5///
		int T1L5Car1_L=50;
		int T1L5Car1_R=74;
		int T1L5Car2_L=150;
		int T1L5Car2_R=174;
		int T1L5Car3_L=240;
		int T1L5Car3_R=264;
		int Traffic1lane5_y=239;
		
///////Traffic 2/////
		int Traffic2_x=260; 
		int Traffic2_y=239;       
		//Lane1-Turtles//
		int L1T1_L=1;
		int L1T1_R=21;
		int L1T2_L=23;
		int L1T2_R=43;
		int L1T3_L=45;
		int L1T3_R=65;
		int L1T4_L=126;
		int L1T4_R=146;
		int L1T5_L=148;
		int L1T5_R=168;
		int L1T6_L=170;
		int L1T6_R=190;
		int L1T7_L=255;
		int L1T7_R=275;
		int L1T8_L=277;
		int L1T8_R=297;
		int L1T9_L=299;
		int L1T9_R=319;
		//Lane2-Logs//
		int L2L1_L=20;
		int L2L1_R=120;
		int L2L2_L=185;
		int L2L2_R=285;
		//Lane3-Turtles//
		int L3T1_L=1;
		int L3T1_R=21;
		int L3T2_L=23;
		int L3T2_R=43;
		int L3T3_L=45;
		int L3T3_R=65;
		int L3T4_L=126;
		int L3T4_R=146;
		int L3T5_L=148;
		int L3T5_R=168;
		int L3T6_L=170;
		int L3T6_R=190;
		int L3T7_L=255;
		int L3T7_R=275;
		int L3T8_L=277;
		int L3T8_R=297;
		int L3T9_L=299;
		int L3T9_R=319;
		//Lane4-Logs//
		int L4L1_L=20;
		int L4L1_R=120;
		int L4L2_L=185;
		int L4L2_R=285;
	//Lane5-Turtles//
		int L5T1_L=1;
		int L5T1_R=21;
		int L5T2_L=23;
		int L5T2_R=43;
		int L5T3_L=45;
		int L5T3_R=65;
		int L5T4_L=126;
		int L5T4_R=146;
		int L5T5_L=148;
		int L5T5_R=168;
		int L5T6_L=170;
		int L5T6_R=190;
		int L5T7_L=255;
		int L5T7_R=275;
		int L5T8_L=277;
		int L5T8_R=297;
		int L5T9_L=299;
		int L5T9_R=319;
		
	//Delay//
	void Delay(){
		int i;
		for(i=0;i<24000000;i++);
	}
	
///Speed of Traffic 1///
		///Lane 1//
		int cx_Traffic1Lane1=10;
		///Lane 2//
		int cx_Traffic1Lane2=15; 
		///Lane 3//
		int cx_Traffic1Lane3=20;
		///Lane 4//
		int cx_Traffic1Lane4=15;
		///Lane 5//
		int cx_Traffic1Lane5=30;
		
///////Speed of Traffic 2/////
	int cx_T2L1=4; //Lane 1-Turtles
	int cx_T2L2=4; //Lane 2-Logs
	int cx_T2L3=4; //Lane 3-Turtles
	int cx_T2L4=4; //Lane 4-Logs
	int cx_T2L5=4; //lane 5-Turtles


	//////FUNCTION TO DRAW 5 LillyPads//////
void draw5Lilly(){
	//Lily Pad
	int i,j;
	GLCD_SetTextColor(DarkGreen);
	for(i=12-(14/2);i<=12+(14/2);i++){					
					for(j=15-(12/2);j<=15+(12/2);j++)
						GLCD_PutPixel(i,j);
	}
	for(i=86-(14/2);i<=86+(14/2);i++){					
					for(j=15-(12/2);j<=15+(12/2);j++)
						GLCD_PutPixel(i,j);
	}
	for(i=160-(14/2);i<=160+(14/2);i++){					
					for(j=15-(12/2);j<=15+(12/2);j++)
						GLCD_PutPixel(i,j);
	}
	for(i=234-(14/2);i<=234+(14/2);i++){					
					for(j=15-(12/2);j<=15+(12/2);j++)
						GLCD_PutPixel(i,j);
	}
	for(i=308-(14/2);i<=308+(14/2);i++){					
					for(j=15-(12/2);j<=15+(12/2);j++)
						GLCD_PutPixel(i,j);
	}
}

//////FUNCTION TO DRAW Traffic 1//////
void drawTraffic1(int cx, int cy, unsigned short color){
	int i,j;
	GLCD_SetTextColor(color);
	for(i=0;i<=cx;i++){
					for(j=133;j<222;j++)
						GLCD_PutPixel(i,j);
	}
}
	//////FUNCTION TO DRAW Traffic 2//////
void drawTraffic2(int cx, int cy, unsigned short color){
	int i,j;
	GLCD_SetTextColor(color);
	for(i=0;i<=cx;i++){					
					for(j=24;j<114;j++)
						GLCD_PutPixel(i,j);
	}
}

		//////FUNCTION TO DRAW Water for Lilly Pad//////
void drawWaterforLilly(int cx, int cy, unsigned short color){
	int i,j;
	GLCD_SetTextColor(color);
	for(i=0;i<=cx;i++){					
					for(j=0;j<24;j++)
						GLCD_PutPixel(i,j);
	}
}

		//////FUNCTION TO DRAW Safe Zone//////
void drawSafeZone(int cx, int cy, unsigned short color){
	int i,j;
	GLCD_SetTextColor(color);
	for(i=0;i<=cx;i++){
					for(j=cy-125;j<=cy-107;j++)
						GLCD_PutPixel(i,j);
			}
	for(i=0;i<=cx;i++){
					for(j=cy-17;j<=cy;j++)
						GLCD_PutPixel(i,j);
		}
}

		//////FUNCTION TO DRAW Shrubs//////
void drawShrub(int cx, int cy, unsigned short color){	
	int i,j;
	GLCD_SetTextColor(color);
	for(i=cx-295;i<=cx-245;i++){					
					for(j=0;j<=cy-216;j++)
						GLCD_PutPixel(i,j);
	}
	for(i=cx-221;i<=cx-171;i++){			
					for(j=0;j<=cy-216;j++)
						GLCD_PutPixel(i,j);
	}
	for(i=cx-147;i<=cx-97;i++){			
					for(j=0;j<=cy-216;j++)
						GLCD_PutPixel(i,j);
	}
	for(i=cx-73;i<=cx-23;i++){				
					for(j=0;j<=cy-216;j++)
						GLCD_PutPixel(i,j);
	}
	for(i=0;i<=cx;i++){
		for(j=0;j<=1;j++)
			GLCD_PutPixel(i,j);
	}
	for(i=0;i<=1;i++){
		for(j=0;j<=cy-216;j++)
			GLCD_PutPixel(i,j);
	}
	for(i=318;i<=319;i++){
		for(j=0;j<=cy-216;j++)
			GLCD_PutPixel(i,j);
	}
	
}
	//////FUNCTION TO DRAW Frog//////
void drawFrog(int cx, int cy, int W, unsigned short color){
int x = cx -W/2;
int y = cy-W/2;
GLCD_SetTextColor(color);
	
GLCD_PutPixel( 0 + x,1 + y);
GLCD_PutPixel( 0 + x,2 + y);
GLCD_PutPixel( 0 + x,9 + y);
GLCD_PutPixel( 0 + x,10 + y);


GLCD_PutPixel( 1 + x,0 + y);
GLCD_PutPixel( 1 + x,1 + y);
GLCD_PutPixel( 1 + x,2 + y);
GLCD_PutPixel( 1 + x,3 + y);
GLCD_PutPixel( 1 + x,4 + y);
GLCD_PutPixel( 1 + x,7 + y);
GLCD_PutPixel( 1 + x,8 + y);
GLCD_PutPixel( 1 + x,9 + y);
GLCD_PutPixel( 1 + x,10 + y);
GLCD_PutPixel( 1 + x,11 + y);

GLCD_PutPixel( 2 + x,4 + y);
GLCD_PutPixel( 2 + x,7 + y);

GLCD_PutPixel( 3 + x,3 + y);
GLCD_PutPixel( 3 + x,4 + y);
GLCD_PutPixel( 3 + x,5 + y);
GLCD_PutPixel( 3 + x,6 + y);
GLCD_PutPixel( 3 + x,7 + y);
GLCD_PutPixel( 3 + x,8 + y);
GLCD_PutPixel( 3 + x,9 + y);

GLCD_PutPixel( 4 + x,0 + y);
GLCD_PutPixel( 4 + x,1 + y);
GLCD_PutPixel( 4 + x,2 + y);
GLCD_PutPixel( 4 + x,3 + y);
GLCD_PutPixel( 4 + x,4 + y);
GLCD_PutPixel( 4 + x,5 + y);
GLCD_PutPixel( 4 + x,6 + y);
GLCD_PutPixel( 4 + x,7 + y);
GLCD_PutPixel( 4 + x,8 + y);
GLCD_PutPixel( 4 + x,9 + y);
GLCD_PutPixel( 4 + x,10 + y);

GLCD_PutPixel( 5 + x,0 + y);
GLCD_PutPixel( 5 + x,1 + y);
GLCD_PutPixel( 5 + x,2 + y);
GLCD_PutPixel( 5 + x,3 + y);
GLCD_PutPixel( 5 + x,4 + y);
GLCD_PutPixel( 5 + x,5 + y);
GLCD_PutPixel( 5 + x,6 + y);
GLCD_PutPixel( 5 + x,7 + y);
GLCD_PutPixel( 5 + x,8 + y);
GLCD_PutPixel( 5 + x,9 + y);
GLCD_PutPixel( 5 + x,10 + y);

GLCD_PutPixel( 6 + x,0 + y);
GLCD_PutPixel( 6 + x,1 + y);
GLCD_PutPixel( 6 + x,2 + y);
GLCD_PutPixel( 6 + x,3 + y);
GLCD_PutPixel( 6 + x,4 + y);
GLCD_PutPixel( 6 + x,5 + y);
GLCD_PutPixel( 6 + x,6 + y);
GLCD_PutPixel( 6 + x,7 + y);
GLCD_PutPixel( 6 + x,8 + y);
GLCD_PutPixel( 6 + x,9 + y);
GLCD_PutPixel( 6 + x,10 + y);

GLCD_PutPixel( 7 + x,0 + y);
GLCD_PutPixel( 7 + x,1 + y);
GLCD_PutPixel( 7 + x,2 + y);
GLCD_PutPixel( 7 + x,3 + y);
GLCD_PutPixel( 7 + x,4 + y);
GLCD_PutPixel( 7 + x,5 + y);
GLCD_PutPixel( 7 + x,6 + y);
GLCD_PutPixel( 7 + x,7 + y);
GLCD_PutPixel( 7 + x,8 + y);
GLCD_PutPixel( 7 + x,9 + y);
GLCD_PutPixel( 7 + x,10 + y);

GLCD_PutPixel( 8 + x,3 + y);
GLCD_PutPixel( 8 + x,4 + y);
GLCD_PutPixel( 8 + x,5 + y);
GLCD_PutPixel( 8 + x,6 + y);
GLCD_PutPixel( 8 + x,7 + y);
GLCD_PutPixel( 8 + x,8 + y);
GLCD_PutPixel( 8 + x,9 + y);

GLCD_PutPixel( 9 + x,4 + y);
GLCD_PutPixel( 9 + x,7 + y);

GLCD_PutPixel( 10 + x,0 + y);
GLCD_PutPixel( 10 + x,1 + y);
GLCD_PutPixel( 10 + x,2 + y);
GLCD_PutPixel( 10 + x,3 + y);
GLCD_PutPixel( 10 + x,4 + y);
GLCD_PutPixel( 10 + x,7 + y);
GLCD_PutPixel( 10 + x,8 + y);
GLCD_PutPixel( 10 + x,9 + y);
GLCD_PutPixel( 10 + x,10 + y);
GLCD_PutPixel( 10 + x,11 + y);

GLCD_PutPixel( 11 + x,1 + y);
GLCD_PutPixel( 11 + x,2 + y);
GLCD_PutPixel( 11 + x,9 + y);
GLCD_PutPixel( 11 + x,10 + y);
}

		//////FUNCTION TO DRAW Circle//////
void draw_circle_filled(int cx, int cy, int radius, unsigned short color) {
	int x = radius, y = 0;
	int xChange = 1 - (radius << 1);
	int yChange = 0;
	int radiusError = 0;
	
	int xn;
	GLCD_SetTextColor(color);

	while (x >= y) {
		GLCD_PutPixel(x + cx, y + cy); // call of GCLD function;
		GLCD_PutPixel(y + cx, x + cy);
		GLCD_PutPixel(-x + cx, y + cy);
		GLCD_PutPixel(-y + cx, x + cy);
		GLCD_PutPixel(-x + cx, -y + cy);
		GLCD_PutPixel(-y + cx, -x + cy);
		GLCD_PutPixel(x + cx, -y + cy);
		GLCD_PutPixel(y + cx, -x + cy);
		
		for (xn = 0; xn < x; xn++) {
			GLCD_PutPixel(cx + xn, cy + y);
			GLCD_PutPixel(cx - xn, cy + y);
			GLCD_PutPixel(cx + xn, cy - y);
			GLCD_PutPixel(cx - xn, cy - y);
			GLCD_PutPixel(cx + y, cy + xn);
			GLCD_PutPixel(cx - y, cy + xn);
			GLCD_PutPixel(cx + y, cy - xn);
			GLCD_PutPixel(cx - y, cy - xn);
		}

		y++;
		radiusError += yChange;
		yChange += 2;
		if (((radiusError << 1) + xChange) > 0) {
			x--;
			radiusError += xChange;
			xChange += 2;
		}
	}
}

		//////FUNCTION TO Reset Game//////
void ResetGame(){
	cx_Traffic1Lane1=20;
	cx_Traffic1Lane2=20; 
	cx_Traffic1Lane3=20;
	cx_Traffic1Lane4=20;
	cx_Traffic1Lane5=20;
	drawTraffic1(Traffic_x,Traffic_y,Black);     	
	drawTraffic2(Traffic_x,Traffic_y,Navy);      	
	drawShrub(SafeZone_x,SafeZone_y,DarkGreen);
	cx_T2L1=4;
	cx_T2L2=4; 
	cx_T2L3=4; 
	cx_T2L4=4; 
	cx_T2L5=4; 
	Frog_x=319/2;
	Frog_y=231;
	drawFrog(319/2,Frog_y,W_Frog,Green);
}

		//////FUNCTION TO Insert a Coin//////
void InsertCoin(){
	GLCD_SetBackColor(Black);
	GLCD_SetTextColor(Green);
	GLCD_DisplayString(1, 1, &welcome[0]);
	drawFrog(319/2,239/3,0,Green);
	draw_circle_filled(319/2,200,24,Yellow);
	draw_circle_filled(319/2,200,22,Black);
	draw_circle_filled(319/2,200,20,Yellow);
	GLCD_SetTextColor(Yellow);
	GLCD_DisplayString(5, 4, &coin1[0]);
	GLCD_DisplayString(6, 6, &coin2[0]);
	while(1){
		if((LPC_GPIO2->FIOPIN & 0x800)==0)
			break;}
	GLCD_Clear(Black);
	GLCD_SetBackColor(Black);
	GLCD_SetTextColor(White);
	GLCD_DisplayString(5, 10, &u[0]);
	Delay();
	GLCD_DisplayString(5, 10, &i[0]);
	Delay();
	GLCD_DisplayString(5, 10, &o[0]);
	Delay();
}

//Fucntion for Frog hitting the cars, or falling on river///
void Collision(){
	cx_Traffic1Lane1=0;
	cx_Traffic1Lane2=0; 
	cx_Traffic1Lane3=0;
	cx_Traffic1Lane4=0;
	cx_Traffic1Lane5=0;
	cx_T2L1=0; 
	cx_T2L2=0; 
	cx_T2L3=0; 
	cx_T2L4=0; 
	cx_T2L5=0; 
	GLCD_SetTextColor(White);
	GLCD_SetBackColor(Black);
	GLCD_DisplayString(5, 4, &e[0]);
	Delay();
	GLCD_ClearLn(5);
	faliure-=1;
	if(faliure==0)
		while(1){
			GLCD_DisplayString(5,5,&f[0]);}
	ResetGame();
}

		//////FUNCTION which frog touches the Lilly Pad//////
void Success(){
	drawFrog(Frog_x,Frog_y,W_Frog,Green);
	GLCD_SetTextColor(White);
	GLCD_SetBackColor(Black);
	GLCD_DisplayString(5, 0, &d[0]);
	Delay();
	GLCD_ClearLn (5);
	success+=1;
	if(success==5)
		while(1){
			GLCD_DisplayString(5,5,&g[0]);}
	ResetGame();
}

		//////FUNCTION TO DRAW Lane 1 in Traffic 1//////
void drawT1L1(int cx1,int cx2, int cx3, int cx4, int cx5, int cx6, unsigned short color){
	int i,j;
		GLCD_SetTextColor(color);
		for(i=cx1;i<=cx2;i++){					
					for(j=207;j<=220;j++)
						GLCD_PutPixel(i,j);
	}

	for(i=cx3;i<=cx4;i++){			
					for(j=207;j<=220;j++)
						GLCD_PutPixel(i,j);
	}

	for(i=cx5;i<=cx6;i++){			
					for(j=207;j<=220;j++)
						GLCD_PutPixel(i,j);
	}
}
void drawT1L2(int cx1,int cx2, int cx3, int cx4, unsigned short color){
int i,j;
		GLCD_SetTextColor(color);
		for(i=cx1;i<=cx2;i++){					
					for(j=190;j<=203;j++)
						GLCD_PutPixel(i,j);
	}

	for(i=cx3;i<=cx4;i++){			
					for(j=190;j<=203;j++)
						GLCD_PutPixel(i,j);
	}
}
void drawT1L3(int cx7,int cx8, int cx9, int cx10, int cx11, int cx12, unsigned short color){
	int i,j;
		GLCD_SetTextColor(color);
		for(i=cx7;i<=cx8;i++){					
					for(j=168;j<=183;j++)
						GLCD_PutPixel(i,j);
	}

	for(i=cx9;i<=cx10;i++){			
					for(j=168;j<=183;j++)
						GLCD_PutPixel(i,j);
	}

	for(i=cx11;i<=cx12;i++){			
					for(j=168;j<=183;j++)
						GLCD_PutPixel(i,j);
	}
}
void drawT1L4(int cx1,int cx2, int cx3, int cx4, unsigned short color){
int i,j;
		GLCD_SetTextColor(color);
		for(i=cx1;i<=cx2;i++){					
					for(j=150;j<=163;j++)
						GLCD_PutPixel(i,j);
	}

	for(i=cx3;i<=cx4;i++){			
					for(j=150;j<=163;j++)
						GLCD_PutPixel(i,j);
	}
}
void drawT1L5(int cx1,int cx2, int cx3, int cx4, int cx5, int cx6, unsigned short color){
	int i,j;
		GLCD_SetTextColor(color);
		for(i=cx1;i<=cx2;i++){					
					for(j=133;j<=146;j++)
						GLCD_PutPixel(i,j);
	}

	for(i=cx3;i<=cx4;i++){			
					for(j=133;j<=146;j++)
						GLCD_PutPixel(i,j);
	}

	for(i=cx5;i<=cx6;i++){			
					for(j=133;j<=146;j++)
						GLCD_PutPixel(i,j);
	}
}

	//////FUNCTION TO Draw Turtles in Lane 1 in Traffic 2//////
void DrawLane1Turtle(int t1,int t2,int t3,int t4,int t5,int t6,int t7,int t8,int t9,int t10,int t11,int t12,int t13,int t14,int t15,int t16,int t17,int t18,unsigned short color){
	int i,j;
		GLCD_SetTextColor(color);
		for(i=t1;i<=t2;i++){					
					for(j=99;j<=112;j++)
						GLCD_PutPixel(i,j);
	}

	for(i=t3;i<=t4;i++){			
					for(j=99;j<=112;j++)
						GLCD_PutPixel(i,j);
	}

	for(i=t5;i<=t6;i++){			
					for(j=99;j<=112;j++)
						GLCD_PutPixel(i,j);
	}
	for(i=t7;i<=t8;i++){			
					for(j=99;j<=112;j++)
						GLCD_PutPixel(i,j);
	}
	for(i=t9;i<=t10;i++){			
					for(j=99;j<=112;j++)
						GLCD_PutPixel(i,j);
	}
	for(i=t11;i<=t12;i++){			
					for(j=99;j<=112;j++)
						GLCD_PutPixel(i,j);
	}
	for(i=t13;i<=t14;i++){			
					for(j=99;j<=112;j++)
						GLCD_PutPixel(i,j);
	}
	for(i=t15;i<=t16;i++){			
					for(j=99;j<=112;j++)
						GLCD_PutPixel(i,j);
	}
	for(i=t17;i<=t18;i++){			
					for(j=99;j<=112;j++)
						GLCD_PutPixel(i,j);
	}
}

	//////FUNCTION TO Draw Logs in Lane 2 in Traffic 2//////
void DrawLane2Log(int cx1,int cx2, int cx3, int cx4, unsigned short color){
int i,j;
		GLCD_SetTextColor(color);
		for(i=cx1;i<=cx2;i++){					
					for(j=81;j<=94;j++)
						GLCD_PutPixel(i,j);
	}

	for(i=cx3;i<=cx4;i++){			
					for(j=81;j<=94;j++)
						GLCD_PutPixel(i,j);
	}
}

	//////FUNCTION TO Draw Turtles in Lane 3 in Traffic 2//////
void DrawLane3Turtle(int t1,int t2,int t3,int t4,int t5,int t6,int t7,int t8,int t9,int t10,int t11,int t12,int t13,int t14,int t15,int t16,int t17,int t18,unsigned short color){
	int i,j;
		GLCD_SetTextColor(color);
		for(i=t1;i<=t2;i++){					
					for(j=63;j<=76;j++)
						GLCD_PutPixel(i,j);
	}

	for(i=t3;i<=t4;i++){			
					for(j=63;j<=76;j++)
						GLCD_PutPixel(i,j);
	}

	for(i=t5;i<=t6;i++){			
					for(j=63;j<=76;j++)
						GLCD_PutPixel(i,j);
	}
	for(i=t7;i<=t8;i++){			
					for(j=63;j<=76;j++)
						GLCD_PutPixel(i,j);
	}
	for(i=t9;i<=t10;i++){			
					for(j=63;j<=76;j++)
						GLCD_PutPixel(i,j);
	}
	for(i=t11;i<=t12;i++){			
					for(j=63;j<=76;j++)
						GLCD_PutPixel(i,j);
	}
	for(i=t13;i<=t14;i++){			
					for(j=63;j<=76;j++)
						GLCD_PutPixel(i,j);
	}
	for(i=t15;i<=t16;i++){			
					for(j=63;j<=76;j++)
						GLCD_PutPixel(i,j);
	}
	for(i=t17;i<=t18;i++){			
					for(j=63;j<=76;j++)
						GLCD_PutPixel(i,j);
	}
}

	//////FUNCTION TO Draw Logs in Lane 4 in Traffic 2//////
void DrawLane4Log(int cx1,int cx2, int cx3, int cx4, unsigned short color){
int i,j;
		GLCD_SetTextColor(color);
		for(i=cx1;i<=cx2;i++){					
					for(j=45;j<=58;j++)
						GLCD_PutPixel(i,j);
	}

	for(i=cx3;i<=cx4;i++){			
					for(j=45;j<=58;j++)
						GLCD_PutPixel(i,j);
	}
}

	//////FUNCTION TO Draw Turtles in Lane 5 in Traffic 2//////
void DrawLane5Turtle(int t1,int t2,int t3,int t4,int t5,int t6,int t7,int t8,int t9,int t10,int t11,int t12,int t13,int t14,int t15,int t16,int t17,int t18,unsigned short color){
	int i,j;
		GLCD_SetTextColor(color);
		for(i=t1;i<=t2;i++){					
					for(j=27;j<=40;j++)
						GLCD_PutPixel(i,j);
	}

	for(i=t3;i<=t4;i++){			
					for(j=27;j<=40;j++)
						GLCD_PutPixel(i,j);
	}

	for(i=t5;i<=t6;i++){			
					for(j=27;j<=40;j++)
						GLCD_PutPixel(i,j);
	}
	for(i=t7;i<=t8;i++){			
					for(j=27;j<=40;j++)
						GLCD_PutPixel(i,j);
	}
	for(i=t9;i<=t10;i++){			
					for(j=27;j<=40;j++)
						GLCD_PutPixel(i,j);
	}
	for(i=t11;i<=t12;i++){			
					for(j=27;j<=40;j++)
						GLCD_PutPixel(i,j);
	}
	for(i=t13;i<=t14;i++){			
					for(j=27;j<=40;j++)
						GLCD_PutPixel(i,j);
	}
	for(i=t15;i<=t16;i++){			
				for(j=27;j<=40;j++)
						GLCD_PutPixel(i,j);
	}
	for(i=t17;i<=t18;i++){			
					for(j=27;j<=40;j++)
						GLCD_PutPixel(i,j);
	}
}
	//////FUNCTION To Move Lane 1 in Traffic 1//////
void MoveTL1(){
	c1=T1L1Car1_L;
	c2=T1L1Car1_R;
	c3=T1L1Car2_L;
	c4=T1L1Car2_R;
	c5=T1L1Car3_L;
	c6=T1L1Car3_R;
	drawT1L1(c1,c2,c3,c4,c5,c6,Black);
	T1L1Car1_L = T1L1Car1_L - cx_Traffic1Lane1;
	T1L1Car1_R = T1L1Car1_R - cx_Traffic1Lane1;
	T1L1Car2_L = T1L1Car2_L - cx_Traffic1Lane1;
	T1L1Car2_R = T1L1Car2_R - cx_Traffic1Lane1;
	T1L1Car3_L = T1L1Car3_L - cx_Traffic1Lane1;
	T1L1Car3_R = T1L1Car3_R - cx_Traffic1Lane1;
	drawT1L1(T1L1Car1_L,T1L1Car1_R,T1L1Car2_L,T1L1Car2_R,T1L1Car3_L,T1L1Car3_R,Blue);}

	//////FUNCTION To Move Lane 2 in Traffic 1//////	
void MoveTL2(){
	//int k;
	c1=T1L2Bus1_L;
	c2=T1L2Bus1_R;
	c3=T1L2Bus2_L;
	c4=T1L2Bus2_R;
	T1L2Bus1_L = T1L2Bus1_L + cx_Traffic1Lane2;
	T1L2Bus1_R = T1L2Bus1_R + cx_Traffic1Lane2;
	T1L2Bus2_L = T1L2Bus2_L + cx_Traffic1Lane2;
	T1L2Bus2_R = T1L2Bus2_R + cx_Traffic1Lane2;
	drawT1L2(c1,c2,c3,c4,Black);
	drawT1L2(T1L2Bus1_L,T1L2Bus1_R,T1L2Bus2_L,T1L2Bus2_R,Yellow);
}

		//////FUNCTION To Move Lane 3 in Traffic 1//////
void MoveTL3(){
	b1=T1L3Car1_L;
	b2=T1L3Car1_R;
	b3=T1L3Car2_L;
	b4=T1L3Car2_R;
	b5=T1L3Car3_L;
	b6=T1L3Car3_R;
	T1L3Car1_L = T1L3Car1_L - cx_Traffic1Lane3;
	T1L3Car1_R = T1L3Car1_R - cx_Traffic1Lane3;
	T1L3Car2_L = T1L3Car2_L - cx_Traffic1Lane3;
	T1L3Car2_R = T1L3Car2_R - cx_Traffic1Lane3;
	T1L3Car3_L = T1L3Car3_L - cx_Traffic1Lane3;
	T1L3Car3_R = T1L3Car3_R - cx_Traffic1Lane3;
	drawT1L3(b1,b2,b3,b4,b5,b6,Black);
	drawT1L3(T1L3Car1_L,T1L3Car1_R,T1L3Car2_L,T1L3Car2_R,T1L3Car3_L,T1L3Car3_R,Blue);}
	
	//////FUNCTION To Move Lane 4 in Traffic 1//////
void MoveTL4(){
	c1=T1L4Bus1_L;
	c2=T1L4Bus1_R;
	c3=T1L4Bus2_L;
	c4=T1L4Bus2_R;
	drawT1L4(c1,c2,c3,c4,Black);
	T1L4Bus1_L = T1L4Bus1_L + cx_Traffic1Lane4;
	T1L4Bus1_R = T1L4Bus1_R + cx_Traffic1Lane4;
	T1L4Bus2_L = T1L4Bus2_L + cx_Traffic1Lane4;
	T1L4Bus2_R = T1L4Bus2_R + cx_Traffic1Lane4;
	drawT1L4(T1L4Bus1_L,T1L4Bus1_R,T1L4Bus2_L,T1L4Bus2_R,Yellow);}

	//////FUNCTION To Move Lane 5 in Traffic 1//////
void MoveTL5(){
	c1=T1L5Car1_L;
	c2=T1L5Car1_R;
	c3=T1L5Car2_L;
	c4=T1L5Car2_R;
	c5=T1L5Car3_L;
	c6=T1L5Car3_R;
	drawT1L5(c1,c2,c3,c4,c5,c6,Black);
	T1L5Car1_L = T1L5Car1_L - cx_Traffic1Lane5;
	T1L5Car1_R = T1L5Car1_R - cx_Traffic1Lane5;
	T1L5Car2_L = T1L5Car2_L - cx_Traffic1Lane5;
	T1L5Car2_R = T1L5Car2_R - cx_Traffic1Lane5;
	T1L5Car3_L = T1L5Car3_L - cx_Traffic1Lane5;
	T1L5Car3_R = T1L5Car3_R - cx_Traffic1Lane5;
	drawT1L5(T1L5Car1_L,T1L5Car1_R,T1L5Car2_L,T1L5Car2_R,T1L5Car3_L,T1L5Car3_R,Blue);}

	//////FUNCTION To Move Lane 1 in Traffic 2//////	
void MoveL1Turtle(){
	d1=L1T1_L;
	d2=L1T1_R;
	d3=L1T2_L;
	d4=L1T2_R;
	d5=L1T3_L;
	d6=L1T3_R;
	d7=L1T4_L;
	d8=L1T4_R;
	d9=L1T5_L;
	d10=L1T5_R;
	d11=L1T6_L;
	d12=L1T6_R;
	d13=L1T7_L;
	d14=L1T7_R;
	d15=L1T8_L;
	d16=L1T8_R;
	d17=L1T9_L;
	d18=L1T9_R;
	DrawLane1Turtle(d1,d2,d3,d4,d5,d6,d7,d8,d8,d10,d11,d12,d13,d14,d15,d16,d17,d18,Navy);
	L1T1_L=L1T1_L-cx_T2L1;
	L1T1_R=L1T1_R-cx_T2L1;
	L1T2_L=L1T2_L-cx_T2L1;
	L1T2_R=L1T2_R-cx_T2L1;
	L1T3_L=L1T3_L-cx_T2L1;
	L1T3_R=L1T3_R-cx_T2L1;
	L1T4_L=L1T4_L-cx_T2L1;
	L1T4_R=L1T4_R-cx_T2L1;
	L1T5_L=L1T5_L-cx_T2L1;
	L1T5_R=L1T5_R-cx_T2L1;
	L1T6_L=L1T6_L-cx_T2L1;
	L1T6_R=L1T6_R-cx_T2L1;
	L1T7_L=L1T7_L-cx_T2L1;
	L1T7_R=L1T7_R-cx_T2L1;
	L1T8_L=L1T8_L-cx_T2L1;
	L1T8_R=L1T8_R-cx_T2L1;
	L1T9_L=L1T9_L-cx_T2L1;
	L1T9_R=L1T9_R-cx_T2L1;
	DrawLane1Turtle(L1T1_L,L1T1_R,L1T2_L,L1T2_R,L1T3_L,L1T3_R,L1T4_L,L1T4_R,L1T5_L,L1T5_R,L1T6_L,L1T6_R,L1T7_L,L1T7_R,L1T8_L,L1T8_R,L1T9_L,L1T9_R,Red);
}
	
	//////FUNCTION To Move Lane 2 in Traffic 2//////
void MoveL2Log(){
	c1=L2L1_L;
	c2=L2L1_R;
	c3=L2L2_L;
	c4=L2L2_R;
	L2L1_L = L2L1_L + cx_T2L2;
	L2L1_R = L2L1_R + cx_T2L2;
	L2L2_L = L2L2_L + cx_T2L2;
	L2L2_R = L2L2_R + cx_T2L2;
	DrawLane2Log(c1,c2,c3,c4,Navy);
	DrawLane2Log(L2L1_L,L2L1_R,L2L2_L,L2L2_R,Maroon);
}	
	
	//////FUNCTION To Move Lane 3 in Traffic 2//////
void MoveL3Turtle(){
	d1=L3T1_L;
	d2=L3T1_R;
	d3=L3T2_L;
	d4=L3T2_R;
	d5=L3T3_L;
	d6=L3T3_R;
	d7=L3T4_L;
	d8=L3T4_R;
	d9=L3T5_L;
	d10=L3T5_R;
	d11=L3T6_L;
	d12=L3T6_R;
	d13=L3T7_L;
	d14=L3T7_R;
	d15=L3T8_L;
	d16=L3T8_R;
	d17=L3T9_L;
	d18=L3T9_R;
	DrawLane3Turtle(d1,d2,d3,d4,d5,d6,d7,d8,d8,d10,d11,d12,d13,d14,d15,d16,d17,d18,Navy);
	L3T1_L=L3T1_L-cx_T2L3;
	L3T1_R=L3T1_R-cx_T2L3;
	L3T2_L=L3T2_L-cx_T2L3;
	L3T2_R=L3T2_R-cx_T2L3;
	L3T3_L=L3T3_L-cx_T2L3;
	L3T3_R=L3T3_R-cx_T2L3;
	L3T4_L=L3T4_L-cx_T2L3;
	L3T4_R=L3T4_R-cx_T2L3;
	L3T5_L=L3T5_L-cx_T2L3;
	L3T5_R=L3T5_R-cx_T2L3;
	L3T6_L=L3T6_L-cx_T2L3;
	L3T6_R=L3T6_R-cx_T2L3;
	L3T7_L=L3T7_L-cx_T2L3;
	L3T7_R=L3T7_R-cx_T2L3;
	L3T8_L=L3T8_L-cx_T2L3;
	L3T8_R=L3T8_R-cx_T2L3;
	L3T9_L=L3T9_L-cx_T2L3;
	L3T9_R=L3T9_R-cx_T2L3;
	DrawLane3Turtle(L3T1_L,L3T1_R,L3T2_L,L3T2_R,L3T3_L,L3T3_R,L3T4_L,L3T4_R,L3T5_L,L3T5_R,L3T6_L,L3T6_R,L3T7_L,L3T7_R,L3T8_L,L3T8_R,L3T9_L,L3T9_R,Red);
}	

	//////FUNCTION To Move Lane 1 in Traffic 2//////



void MoveL4Log(){
	c1=L4L1_L;
	c2=L4L1_R;
	c3=L4L2_L;
	c4=L4L2_R;
	L4L1_L = L4L1_L + cx_T2L4;
	L4L1_R = L4L1_R + cx_T2L4;
	L4L2_L = L4L2_L + cx_T2L4;
	L4L2_R = L4L2_R + cx_T2L4;
	DrawLane4Log(c1,c2,c3,c4,Navy);
	DrawLane4Log(L4L1_L,L4L1_R,L4L2_L,L4L2_R,Maroon);
}
void MoveL5Turtle(){
	d1=L5T1_L;
	d2=L5T1_R;
	d3=L5T2_L;
	d4=L5T2_R;
	d5=L5T3_L;
	d6=L5T3_R;
	d7=L5T4_L;
	d8=L5T4_R;
	d9=L5T5_L;
	d10=L5T5_R;
	d11=L5T6_L;
	d12=L5T6_R;
	d13=L5T7_L;
	d14=L5T7_R;
	d15=L5T8_L;
	d16=L5T8_R;
	d17=L5T9_L;
	d18=L5T9_R;
	DrawLane5Turtle(d1,d2,d3,d4,d5,d6,d7,d8,d8,d10,d11,d12,d13,d14,d15,d16,d17,d18,Navy);
	L5T1_L=L5T1_L-cx_T2L5;
	L5T1_R=L5T1_R-cx_T2L5;
	L5T2_L=L5T2_L-cx_T2L5;
	L5T2_R=L5T2_R-cx_T2L5;
	L5T3_L=L5T3_L-cx_T2L5;
	L5T3_R=L5T3_R-cx_T2L5;
	L5T4_L=L5T4_L-cx_T2L5;
	L5T4_R=L5T4_R-cx_T2L5;
	L5T5_L=L5T5_L-cx_T2L5;
	L5T5_R=L5T5_R-cx_T2L5;
	L5T6_L=L5T6_L-cx_T2L5;
	L5T6_R=L5T6_R-cx_T2L5;
	L5T7_L=L5T7_L-cx_T2L5;
	L5T7_R=L5T7_R-cx_T2L5;
	L5T8_L=L5T8_L-cx_T2L5;
	L5T8_R=L5T8_R-cx_T2L5;
	L5T9_L=L5T9_L-cx_T2L5;
	L5T9_R=L5T9_R-cx_T2L5;
	DrawLane5Turtle(L5T1_L,L5T1_R,L5T2_L,L5T2_R,L5T3_L,L5T3_R,L5T4_L,L5T4_R,L5T5_L,L5T5_R,L5T6_L,L5T6_R,L5T7_L,L5T7_R,L5T8_L,L5T8_R,L5T9_L,L5T9_R,Red);
}
void MoveFrogLeft(){
	if(Frog_x<=4){
		Frog_x=20;
		drawFrog(Frog_x,Frog_y,W_Frog,Green);
	}
	c=Frog_x;
	Frog_x=Frog_x-Frog_cx;
	if(Frog_y>=222&&Frog_y<=239){
		drawFrog(c,Frog_y,W_Frog,Purple);
		//drawSafeZone(SafeZone_x,SafeZone_y,Purple);
		drawFrog(Frog_x,Frog_y,W_Frog,Green);}
	if(Frog_y>=132&&Frog_y<=222){
		drawFrog(c,Frog_y,W_Frog,Black);
		//drawTraffic1(Traffic_x,Traffic_y,Black);
		drawFrog(Frog_x,Frog_y,W_Frog,Green);}
	if(Frog_y>=114&&Frog_y<=132){
		drawFrog(c,Frog_y,W_Frog,Purple);
		//drawSafeZone(SafeZone_x,SafeZone_y,Purple);
		drawFrog(Frog_x,Frog_y,W_Frog,Green);}
	//for(k=0; k<300000; k++);
	if(Frog_y>=25&&Frog_y<=112){
			drawFrog(c,Frog_y,W_Frog,Navy);
			drawFrog(Frog_x,Frog_y,W_Frog,Green);}
	}
void MoveFrogRight(){
	if(Frog_x>=320){
		Frog_x=290;
		drawFrog(Frog_x,Frog_y,W_Frog,Green);
	}
	c=Frog_x;
	Frog_x=Frog_x+Frog_cx;
	if(Frog_y>=222&&Frog_y<=239){
		drawFrog(c,Frog_y,W_Frog,Purple);
		//drawSafeZone(SafeZone_x,SafeZone_y,Purple);
		drawFrog(Frog_x,Frog_y,W_Frog,Green);}
	if(Frog_y>=132&&Frog_y<=222){
		drawFrog(c,Frog_y,W_Frog,Black);
		//drawTraffic1(Traffic_x,Traffic_y,Black);
		drawFrog(Frog_x,Frog_y,W_Frog,Green);}
	if(Frog_y>=114&&Frog_y<=132){
		drawFrog(c,Frog_y,W_Frog,Purple);
		//drawSafeZone(SafeZone_x,SafeZone_y,Purple);
		drawFrog(Frog_x,Frog_y,W_Frog,Green);}
	//for(k=0; k<300000; k++);
		if(Frog_y>=25&&Frog_y<=112){
			drawFrog(c,Frog_y,W_Frog,Navy);
			drawFrog(Frog_x,Frog_y,W_Frog,Green);}
}	
void MoveFrogDown(){
	c=Frog_y;
	Frog_y=Frog_y+Frog_cy;
	if(Frog_y>=222&&Frog_y<=239){
		drawFrog(Frog_x,c,W_Frog,Purple);
		//drawSafeZone(SafeZone_x,SafeZone_y,Purple);
		drawFrog(Frog_x,Frog_y,W_Frog,Green);}
	if(c>114){
		drawSafeZone(SafeZone_x,SafeZone_y,Purple);
		//drawTraffic1(Traffic_x,Traffic_y,Black);
		drawFrog(Frog_x,Frog_y,W_Frog,Green);}
	if(c>132&&c<222){
		drawFrog(Frog_x,c,W_Frog,Black);
		//drawSafeZone(SafeZone_x,SafeZone_y,Purple);
		drawFrog(Frog_x,Frog_y,W_Frog,Green);}
	//for(k=0; k<300000; k++);
		if(c<114){
		drawFrog(Frog_x,c,W_Frog,Navy);
		//drawSafeZone(SafeZone_x,SafeZone_y,Purple);
		drawFrog(Frog_x,Frog_y,W_Frog,Green);}
		if(c>231){
		//Frog_y=219;
		drawFrog(Frog_x,231,W_Frog,Green);}
}
void MoveFrogUp(){
	b=Frog_y;
	Frog_y=Frog_y-Frog_cy;
	if(b>222){
		drawSafeZone(SafeZone_x,SafeZone_y,Purple);
		//drawSafeZone(SafeZone_x,SafeZone_y,Purple);
		drawFrog(Frog_x,Frog_y,W_Frog,Green);}
		//drawSafeZone(SafeZone_x,SafeZone_y,Purple);}
	if(b>132&&b<222){
		drawFrog(Frog_x,b,W_Frog,Black);
		//drawTraffic1(Traffic_x,Traffic_y,Black);
		drawFrog(Frog_x,Frog_y,W_Frog,Green);}
	if(b<132){
		drawSafeZone(SafeZone_x,SafeZone_y,Purple);
		//drawSafeZone(SafeZone_x,SafeZone_y,Purple);
		drawFrog(Frog_x,Frog_y,W_Frog,Green);}
	//for(k=0; k<300000; k++);
	if(b<114){
		drawFrog(Frog_x,b,W_Frog,Navy);
		//drawSafeZone(SafeZone_x,SafeZone_y,Purple);
		drawFrog(Frog_x,Frog_y,W_Frog,Green);}	
	//if(Frog_y<=4){
			//Frog_y=20;
			//drawFrog(Frog_x,Frog_y,W_Frog,Green);}
}	

void PauseGame(){
	DrawLane1Turtle(L1T1_L,L1T1_R,L1T2_L,L1T2_R,L1T3_L,L1T3_R,L1T4_L,L1T4_R,L1T5_L,L1T5_R,L1T6_L,L1T6_R,L1T7_L,L1T7_R,L1T8_L,L1T8_R,L1T9_L,L1T9_R,Red);
	drawT1L1(T1L1Car1_L,T1L1Car1_R,T1L1Car2_L,T1L1Car2_R,T1L1Car3_L,T1L1Car3_R,Blue);      //Lane 1 in Traffic 1
	drawT1L2(T1L2Bus1_L,T1L2Bus1_R,T1L2Bus2_L,T1L2Bus2_R,Yellow);      //Lane 1 in Traffic 1
	drawT1L3(T1L3Car1_L,T1L3Car1_R,T1L3Car2_L,T1L3Car2_R,T1L3Car3_L,T1L3Car3_R,Blue);      //Lane 1 in Traffic 1
	drawT1L4(T1L4Bus1_L,T1L4Bus1_R,T1L4Bus2_L,T1L4Bus2_R,Yellow);      //Lane 1 in Traffic 1
	drawT1L5(T1L5Car1_L,T1L5Car1_R,T1L5Car2_L,T1L5Car2_R,T1L5Car3_L,T1L5Car3_R,Blue);      //Lane 1 in Traffic 1
	DrawLane2Log(L2L1_L,L2L1_R,L2L2_L,L2L2_R,Maroon);
	DrawLane3Turtle(L3T1_L,L3T1_R,L3T2_L,L3T2_R,L3T3_L,L3T3_R,L3T4_L,L3T4_R,L3T5_L,L3T5_R,L3T6_L,L3T6_R,L3T7_L,L3T7_R,L3T8_L,L3T8_R,L3T9_L,L3T9_R,Red);
	DrawLane4Log(L4L1_L,L4L1_R,L4L2_L,L4L2_R,Maroon);
	DrawLane5Turtle(L5T1_L,L5T1_R,L5T2_L,L5T2_R,L5T3_L,L5T3_R,L5T4_L,L5T4_R,L5T5_L,L5T5_R,L5T6_L,L5T6_R,L5T7_L,L5T7_R,L5T8_L,L5T8_R,L5T9_L,L5T9_R,Red);
	Frog_cx=0;
	Frog_cy=0;
	GLCD_SetBackColor(Black);
	GLCD_SetTextColor(White);
	GLCD_DisplayString(5, 3, &Pause[0]);
	while(1){
		Delay();
		if((LPC_GPIO2->FIOPIN&0x1000)==0)
			break;}
	//if(pause>1){
		GLCD_DisplayString(5, 2, &Pause1[0]);
		Delay();
		Frog_cx=19;
		Frog_cy=18;
		GLCD_ClearLn(5);//}
}
int main() {
	
		//Set up GLCD 
		GLCD_Init();               //Initializes the LCD display	
		GLCD_Clear(Black);         //Clear display and set background color to black
	
		InsertCoin();
		GLCD_Clear(Black);
	
		//UART init for part C
		UARTInit(0, 57600);
		
		drawSafeZone(SafeZone_x,SafeZone_y,Purple);   	//Safe Zone 1
		drawFrog(Frog_x,Frog_y,W_Frog,Green);           //Frog
		drawTraffic1(Traffic_x,Traffic_y,Black);     	//Traffic 1
		drawTraffic2(Traffic_x,Traffic_y,Navy);      	//Traffic 2
		drawWaterforLilly(Traffic_x,Traffic_y,Navy);
		draw5Lilly();            			//5 HOME
		drawShrub(SafeZone_x,SafeZone_y,DarkGreen);
		DrawLane1Turtle(L1T1_L,L1T1_R,L1T2_L,L1T2_R,L1T3_L,L1T3_R,L1T4_L,L1T4_R,L1T5_L,L1T5_R,L1T6_L,L1T6_R,L1T7_L,L1T7_R,L1T8_L,L1T8_R,L1T9_L,L1T9_R,Red);
		drawT1L1(T1L1Car1_L,T1L1Car1_R,T1L1Car2_L,T1L1Car2_R,T1L1Car3_L,T1L1Car3_R,Blue);      //Lane 1 in Traffic 1
		drawT1L2(T1L2Bus1_L,T1L2Bus1_R,T1L2Bus2_L,T1L2Bus2_R,Yellow);      //Lane 1 in Traffic 1
		drawT1L3(T1L3Car1_L,T1L3Car1_R,T1L3Car2_L,T1L3Car2_R,T1L3Car3_L,T1L3Car3_R,Blue);      //Lane 1 in Traffic 1
		drawT1L4(T1L4Bus1_L,T1L4Bus1_R,T1L4Bus2_L,T1L4Bus2_R,Yellow);      //Lane 1 in Traffic 1
		drawT1L5(T1L5Car1_L,T1L5Car1_R,T1L5Car2_L,T1L5Car2_R,T1L5Car3_L,T1L5Car3_R,Blue);      //Lane 1 in Traffic 1
		DrawLane2Log(L2L1_L,L2L1_R,L2L2_L,L2L2_R,Maroon);
	  DrawLane3Turtle(L3T1_L,L3T1_R,L3T2_L,L3T2_R,L3T3_L,L3T3_R,L3T4_L,L3T4_R,L3T5_L,L3T5_R,L3T6_L,L3T6_R,L3T7_L,L3T7_R,L3T8_L,L3T8_R,L3T9_L,L3T9_R,Red);
		DrawLane4Log(L4L1_L,L4L1_R,L4L2_L,L4L2_R,Maroon);
		DrawLane5Turtle(L5T1_L,L5T1_R,L5T2_L,L5T2_R,L5T3_L,L5T3_R,L5T4_L,L5T4_R,L5T5_L,L5T5_R,L5T6_L,L5T6_R,L5T7_L,L5T7_R,L5T8_L,L5T8_R,L5T9_L,L5T9_R,Red);
		
while(1){
	if((LPC_GPIO2->FIOPIN&0x1000)==0)
			PauseGame();
		if(faliure==4){
			GLCD_SetTextColor(White);
			GLCD_SetBackColor(DarkGreen);
			GLCD_DisplayString(0, 8, &u[0]);
		}
		if(faliure==3){
			GLCD_SetTextColor(White);
			GLCD_SetBackColor(DarkGreen);
			GLCD_DisplayString(0, 8, &i[0]);
		}
		if(faliure==2){
			GLCD_SetTextColor(White);
			GLCD_SetBackColor(DarkGreen);
			GLCD_DisplayString(0, 8, &o[0]);
		}
		if(faliure==1){
			GLCD_SetTextColor(White);
			GLCD_SetBackColor(DarkGreen);
			GLCD_DisplayString(0, 8, &p[0]);}
		MoveTL1();
		MoveTL2();
		MoveTL3();
		MoveTL4();
		MoveTL5();
		MoveL1Turtle();
		MoveL2Log();
		MoveL3Turtle();
		MoveL4Log();
		MoveL5Turtle();
	
	
				//UART code for Part C
				if ( UART0_Count != 0 ) {
					
						char char_from_pc = UART0_Buffer[0];						
						UARTSend( 0, (uint8_t *)UART0_Buffer, UART0_Count);
						UART0_Count = 0;
						
							//checks if the 4 characters keys are presses//
						if(char_from_pc=='w')
							MoveFrogUp();
						if(char_from_pc=='a')
							MoveFrogLeft();
						if(char_from_pc=='s')
							MoveFrogDown();
						if(char_from_pc=='d')
							MoveFrogRight();
				}
	
		//Recreating Lane1
		if(T1L1Car1_R<=0){
			T1L1Car1_L=319;
			T1L1Car1_R=343;}
		if(T1L1Car2_R<=0){
			T1L1Car2_L=319;
			T1L1Car2_R=343;}
		if(T1L1Car3_R<=0){
			T1L1Car3_L=319;
			T1L1Car3_R=343;}
		
		//Recreating Lane2
		if(T1L2Bus2_L>320){
			T1L2Bus2_L=-100;
			T1L2Bus2_R=0;}
		if(T1L2Bus1_L>320){
			T1L2Bus1_L=-100;
			T1L2Bus1_R=0;}
		
		//Recreating Lane3
		if(T1L3Car1_R<=0){
			T1L3Car1_L=319;
			T1L3Car1_R=343;}
		if(T1L3Car2_R<=0){
			T1L3Car2_L=319;
			T1L3Car2_R=343;}
		if(T1L3Car3_R<=0){
			T1L3Car3_L=319;
			T1L3Car3_R=343;}
			
			//Recreating Lane4
		if(T1L4Bus2_L>=320){
			T1L4Bus2_L=-100;
			T1L4Bus2_R=0;}
		if(T1L4Bus1_L>=320){
			T1L4Bus1_L=-100;
			T1L4Bus1_R=0;}
			
		//Recreating Lane5
		if(T1L5Car1_R<=0){
			T1L5Car1_L=319;
			T1L5Car1_R=343;}
		if(T1L5Car2_R<=0){
			T1L5Car2_L=319;
			T1L5Car2_R=343;}
		if(T1L5Car3_R<=0){
			T1L5Car3_L=319;
			T1L5Car3_R=343;}
			
		//Recreating Turtle at Lane1
			if(L1T3_R<0){
				L1T1_L=320;
				L1T1_R=340;
				L1T2_L=342;
				L1T2_R=362;
				L1T3_L=364;
				L1T3_R=384;}
			if(L1T6_R<0){
				L1T4_L=320;
				L1T4_R=340;
				L1T5_L=342;
				L1T5_R=362;
				L1T6_L=364;
				L1T6_R=384;}
			if(L1T9_R<0){
				L1T7_L=320;
				L1T7_R=340;
				L1T8_L=342;
				L1T8_R=362;
				L1T9_L=364;
				L1T9_R=384;}
		
		//Recreating Turtle at Lane3
			if(L3T3_R<0){
				L3T1_L=320;
				L3T1_R=340;
				L3T2_L=342;
				L3T2_R=362;
				L3T3_L=364;
				L3T3_R=384;}
			if(L3T6_R<0){
				L3T4_L=320;
				L3T4_R=340;
				L3T5_L=342;
				L3T5_R=362;
				L3T6_L=364;
				L3T6_R=384;}
			if(L3T9_R<0){
				L3T7_L=320;
				L3T7_R=340;
				L3T8_L=342;
				L3T8_R=362;
				L3T9_L=364;
				L3T9_R=384;}
			
			//Recreating Turtle at Lane5
			if(L5T3_R<0){
				L5T1_L=320;
				L5T1_R=340;
				L5T2_L=342;
				L5T2_R=362;
				L5T3_L=364;
				L5T3_R=384;}
			if(L5T6_R<0){
				L5T4_L=320;
				L5T4_R=340;
				L5T5_L=342;
				L5T5_R=362;
				L5T6_L=364;
				L5T6_R=384;}
			if(L5T9_R<0){
				L5T7_L=320;
				L5T7_R=340;
				L5T8_L=342;
				L5T8_R=362;
				L5T9_L=364;
				L5T9_R=384;}
				
		//Recreating Logs at Lane2
		if(L2L1_L>320){
			L2L1_L=-100;
			L2L1_R=0;}
		if(L2L2_L>320){
			L2L2_L=-100;
			L2L2_R=0;}	
			
		//Recreating Logs at Lane4
		if(L4L1_L>320){
			L4L1_L=-100;
			L4L1_R=0;}
		if(L4L2_L>320){
			L4L2_L=-100;
			L4L2_R=0;}	
			
			//Frog Detection at Traffic 1//
			//Lane 1//
			if(Frog_y>=207&&Frog_y<=220){
				if((Frog_x+W_Frog/2>T1L1Car1_L&&Frog_x+W_Frog/2<T1L1Car1_R)||(Frog_x+W_Frog/2>T1L1Car2_L&&Frog_x+W_Frog/2<T1L1Car2_R)||(Frog_x+W_Frog/2>T1L1Car3_L&&Frog_x+W_Frog/2<T1L1Car3_R))
				Collision();
		}
				 
		//Lane 2//
		if(Frog_y>=190&&Frog_y<=203){
			if((Frog_x+W_Frog/2>=T1L2Bus1_L&&Frog_x+W_Frog/2<=T1L2Bus1_R)||(Frog_x+W_Frog/2>=T1L2Bus2_L&&Frog_x+W_Frog/2<=T1L2Bus2_R))
				Collision();
		}
		
		//Lane 3//
			if(Frog_y>=168&&Frog_y<=183){
			if((Frog_x+W_Frog/2>T1L3Car1_L&&Frog_x+W_Frog/2<T1L3Car1_R)||(Frog_x+W_Frog/2>T1L3Car2_L&&Frog_x+W_Frog/2<T1L3Car2_R)||(Frog_x+W_Frog/2>T1L3Car3_L&&Frog_x+W_Frog/2<T1L3Car3_R))
				
				//Frog_x=0;
				//Frog_y=0;
				//cx_Traffic1Lane3=0;
				Collision();
					//drawFrog(Frog_x,Frog_y,W_Frog,Yellow);
			
		}
			
		//Lane 4//
		if(Frog_y>=150&&Frog_y<=163){
			if((Frog_x+W_Frog/2>=T1L4Bus1_L&&Frog_x+W_Frog/2<=T1L4Bus1_R)||(Frog_x+W_Frog/2>=T1L4Bus2_L&&Frog_x+W_Frog/2<=T1L4Bus2_R))
				Collision();		
		}
			
		//Lane 5//
			if(Frog_y>=133&&Frog_y<=146){
			if((Frog_x+W_Frog/2>T1L5Car1_L&&Frog_x+W_Frog/2<T1L5Car1_R)||(Frog_x+W_Frog/2>T1L5Car2_L&&Frog_x+W_Frog/2<T1L5Car2_R)||(Frog_x+W_Frog/2>T1L5Car3_L&&Frog_x+W_Frog/2<T1L5Car3_R))
				Collision();
		}
		
		//Traffic 2//
		//Lane 1 - Turtle//
		if(Frog_y>=99&&Frog_y<=112){
			if(
			(Frog_x>=L1T1_L&&Frog_x<=L1T3_R)||
			(Frog_x>=L1T4_L&&Frog_x+W_Frog/2<=L1T6_R)||
			(Frog_x>=L1T7_L&&Frog_x<=L1T9_R)){
				c=Frog_x;
				Frog_x-=4;
				drawFrog(c,Frog_y,W_Frog,Red);
				drawFrog(Frog_x,Frog_y,W_Frog,Green);
				if(Frog_x-W_Frog/2<0)
					Collision();
			}
				else
					Collision();
		}

			//Lane 2 - Logs//
		if(Frog_y>81&&Frog_y<94){
			if((Frog_x>=L2L1_L&&Frog_x<=L2L1_R)||(Frog_x>=L2L2_L&&Frog_x<=L2L2_R)){
				c=Frog_x;
				Frog_x+=4;
				drawFrog(c,Frog_y,W_Frog,Maroon);
				drawFrog(Frog_x,Frog_y,W_Frog,Green);
				if(Frog_x+W_Frog/2>320)
					Collision();}
			else
					Collision();
			}
		//Lane 3 - Turtle//
		if(Frog_y>=63&&Frog_y<=76){
			if(
				(Frog_x>=L3T1_L&&Frog_x<=L3T3_R)||
				(Frog_x>=L3T4_L&&Frog_x<=L3T6_R)||
				(Frog_x>=L3T7_L&&Frog_x<=L3T9_R)){
				c=Frog_x;
				Frog_x-=4;
				drawFrog(c,Frog_y,W_Frog,Red);
				drawFrog(Frog_x,Frog_y,W_Frog,Green);
				if(Frog_x-W_Frog/2<0)
					Collision();
			}
				else
					Collision();
		}

				//Lane 4 - Logs//
		if(Frog_y>=45&&Frog_y<=58){
			if((Frog_x>=L4L1_L&&Frog_x<=L4L1_R)||(Frog_x>=L4L2_L&&Frog_x<=L4L2_R)){
				c=Frog_x;
				Frog_x+=4;
				drawFrog(c,Frog_y,W_Frog,Maroon);
				drawFrog(Frog_x,Frog_y,W_Frog,Green);
				if(Frog_x+W_Frog/2>320)
					Collision();}
			else
					Collision();
			}
		
			//Lane 5 - Turtle//
		if(Frog_y>=27&&Frog_y<=40){
			if(
				(Frog_x>=L5T1_L&&Frog_x<=L5T3_R)||
				(Frog_x>=L5T4_L&&Frog_x<=L5T6_R)||
				(Frog_x>=L5T7_L&&Frog_x<=L5T9_R)){
				c=Frog_x;
				Frog_x-=4;
				drawFrog(c,Frog_y,W_Frog,Red);
				drawFrog(Frog_x,Frog_y,W_Frog,Green);
				if(Frog_x-W_Frog/2<0)
					Collision();
			}
				else
					Collision();
		}
		
		if(Frog_y-W_Frog/2<24){
			if(Frog_x>0&&Frog_x<24){
				lilly1+=1;
				if(lilly1>1)
					Collision();
				Success();}
			}
		if(Frog_y-W_Frog/2<24){
			if(Frog_x>74&&Frog_x<98){
				lilly2+=1;
				if(lilly2>1)
					Collision();
				Success();}
			}
		if(Frog_y-W_Frog/2<24){
			if(Frog_x>148&&Frog_x<172){
				lilly3+=1;
				if(lilly3>1)
					Collision();
				Success();}
			}
			if(Frog_y-W_Frog/2<24){
			if(Frog_x>222&&Frog_x<246){
				lilly4+=1;
				if(lilly4>1)
					Collision();
				Success();}
			}
			if(Frog_y-W_Frog/2<24){
			if(Frog_x>296&&Frog_x<319){
				lilly5+=1;
				if(lilly5>1)
					Collision();
			Success();}
		}
		if(Frog_y-W_Frog/2<24){
			if(
				(Frog_x>24&&Frog_x<74)||
				(Frog_x>98&&Frog_x<148)||
				(Frog_x>172&&Frog_x<222)||
				(Frog_x>246&&Frog_x<296)){
					Collision();}
		}
	}
}