#define _CRT_SECURE_NO_WARNINGS
# include "iGraphics.h"
int flag = 0;
int mposx,  mposy;
int pacindx=30,pacindy=37;
int pac_move_dir=0;
int pac_dx=5,pac_dy=5;
int green_enemy_indx=400,green_enemy_indy=428;

//clock counting....
time_t start_pulse, end_pulse;
int time_sec=0;
char count_down[20];
int life_sec = 8;
//

int score=0;
char score_show[20];

int pac_image_index=0;
int enemy_image_index=0;

int enemy_move_dir=0;

char pac_right[4][20]={"photo//right//0.bmp","photo//right//1.bmp","photo//right//2.bmp","photo//right//3.bmp"};
char pac_left[4][20]={"photo//left//0.bmp","photo//left//1.bmp","photo//left//2.bmp","photo//left//3.bmp"};
char pac_up[4][20]={"photo//up//0.bmp","photo//up//1.bmp","photo//up//2.bmp","photo//up//3.bmp"};
char pac_down[4][20]={"photo//down//0.bmp","photo//down//1.bmp","photo//down//2.bmp","photo//down//3.bmp"};
//enemy 
char enemy_green[4][30]={"photo//greenenemy//1.bmp","photo//greenenemy//2.bmp","photo//greenenemy//3.bmp","photo//greenenemy//4.bmp"};
char enemy_purple[4][30]={"photo//purpleenemy//1.bmp","photo//purpleenemy//2.bmp","photo//purpleenemy//3.bmp","photo//purpleenemy//4.bmp"};

void enemy_rand_dir();
/*
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	
	
	//place your drawing codes here
	iClear();

	
	//instructions
	iSetColor(0, 255, 255);
	iText2(1050, 500, "INSTRUCTIONS : ", GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(255, 255, 255);
	iText2(965, 470, "This is a new version \`PacMan Game\'", GLUT_BITMAP_TIMES_ROMAN_24);
	iText2(965, 440, "The ", GLUT_BITMAP_TIMES_ROMAN_24);

	iSetColor(255,255,0);
	iText2(1013, 440, "YELLOW", GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(255, 255, 255);
	iText2(1120, 440, "colored charecter is", GLUT_BITMAP_TIMES_ROMAN_24);
	iText2(965, 410, "yours.", GLUT_BITMAP_TIMES_ROMAN_24);

	iText2(965, 350, "There is a  ", GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(0, 255, 0);
	iText2(1070, 350, "GREEN", GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(255, 255, 255);
	iText2(1160, 350, "colored Enemy", GLUT_BITMAP_TIMES_ROMAN_24);
	
	iText2(965, 290, "Your Life time is about only 8 sec.", GLUT_BITMAP_TIMES_ROMAN_24);
	iText2(965, 260, "Every time you eat your enemy once ", GLUT_BITMAP_TIMES_ROMAN_24);
	iText2(965, 230, "your life time will increase and you score.", GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(255, 0, 0);
	iText2(965, 200, "SO, EAT to LIVE", GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(255, 255, 255);
	//

	_itoa(score, score_show, 9);
	iShowBMP2(0,0,"photo//board3.bmp",-1);
	iSetColor(0, 0, 255);
	iText2(50,570,"SCORE : ",GLUT_BITMAP_TIMES_ROMAN_24);
	iText2(150,570,score_show,GLUT_BITMAP_TIMES_ROMAN_24);
	//enemy
	iShowBMP2(green_enemy_indx,green_enemy_indy,enemy_green[enemy_image_index],255);
	//timing...
	_itoa((life_sec - time_sec), count_down, 10);
	if (life_sec - time_sec >= 0)
	{
		iText2(350, 570, "Time : ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText2(440, 570, count_down, GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else
	{
		iSetColor(255, 0, 0);
		iText2(350, 570, "GAME OVER", GLUT_BITMAP_TIMES_ROMAN_24);
		//iText2(440, 570, count_down, GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(0, 255, 100);
		iText2(389, 280, "ENTER to Restart", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255, 100, 0);
		iText2(420, 250, "ESC. to exit", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	

	//

	//pacman
	if (pac_move_dir==0)
	{
		iShowBMP2(pacindx,pacindy,pac_right[pac_image_index],255);
	}
	if (pac_move_dir==1)
	{
		iShowBMP2(pacindx,pacindy,pac_left[pac_image_index],255);
	}
	if (pac_move_dir==2)
	{
		iShowBMP2(pacindx,pacindy,pac_up[pac_image_index],255);
	}
	if (pac_move_dir==3)
	{
		iShowBMP2(pacindx,pacindy,pac_down[pac_image_index],255);
	}

	
	

}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//printf ("p : %d\t p : %d\n",pacindx,pacindy);
		printf("m : %d\tm : %d\n",mx,my);
		printf("%d\t%d\n", green_enemy_indx, green_enemy_indy);
		//place your codes here
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}
/*iPassiveMouseMove is called to detect and use
the mouse point without pressing any button */

void iPassiveMouseMove(int mx,int my)
{
	//place your code here

 mposx = mx;
 mposy = my;
 if(mx== 2){}        /*Something to do with mx*/
 else if(my== 2){}   /*Something to do with my*/

}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if(key == 'q')
	{
		//score++;
		//do something with 'q'
	}
	if (key=='\r')
	{
		//printf("y");
		//life_sec = 8;
		start_pulse = clock();
		end_pulse = clock();
		time_sec=0;
		score = 0;
	}
	if (key==27)
	{
		exit(0);
	}

	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	if(key == GLUT_KEY_RIGHT)
	{
		if (life_sec - time_sec >= 0)
		pac_move_dir=0;
		//pacindx+=10;
	}
	if(key == GLUT_KEY_LEFT)
	{
		//pacindx-=5;
		if (life_sec - time_sec >= 0)
		pac_move_dir=1;
	}
	if(key == GLUT_KEY_UP)
	{
		//pacindy+=5;
		if (life_sec - time_sec >= 0)
		pac_move_dir=2;
	}
	if(key == GLUT_KEY_DOWN)
	{
		//pacindy-=5;
		if (life_sec - time_sec >= 0)
		pac_move_dir=3;
	}


	//place your codes for other keys here
}
//
void pac_right_control()
{
	if (life_sec - time_sec >= 0)
	{
		pac_image_index++;
	}
	else
	{
		pac_image_index = 1;
	}
	if (pac_image_index > 3)
	{
		pac_image_index=0;
	}
	//pac_image_index++;

}
void pac_move_control()
{
	if (life_sec - time_sec >= 0)
	{
		if (pac_move_dir == 0)
		{
			if (865>pacindx)
			{
				if (pacindy<41)
				{
					pacindx += 3;
				}
				if ((pacindy>226) && (pacindy<240))
				{
					if (pacindx<183)
					{
						pacindx += 3;
					}
					if (pacindx>708)
					{
						pacindx += 3;
					}

				}
				if (pacindy>422)
				{
					pacindx += 3;
				}
				if ((pacindy>135) && (pacindy<145))
				{
					if (pacindx<615)
					{
						pacindx += 3;
					}
				}
				if ((pacindy>329) && (pacindy<340))
				{
					if (pacindx<615)
					{
						pacindx += 3;
					}

				}

			}
		}
		if (pac_move_dir == 1)
		{
			if (30<pacindx)
			{
				if ((pacindy>28) && (pacindy<45))
				{
					pacindx -= 3;
				}
				if ((pacindy>427))
				{
					pacindx -= 3;
				}
				if ((pacindy>226) && (pacindy<240))// mid
				{
					if (pacindx<189)
					{
						pacindx -= 3;
					}
					if (pacindx>712)
					{
						pacindx -= 3;
					}

				}
				if ((pacindy>329) && (pacindy<340))
				{
					if (pacindx>278)
					{
						pacindx -= 3;
					}

				}
				if ((pacindy>135) && (pacindy<145))
				{
					if (pacindx>278)
					{
						pacindx -= 3;
					}
				}

			}
		}
		if (pac_move_dir == 2)
		{
			if (432>pacindy)
			{
				if ((pacindx>0) && (pacindx<40))   //(pacindx>50)&&(pacindx<170)
				{
					pacindy += 3;
				}
				if ((pacindx>166) && (pacindx<186))
				{
					pacindy += 3;
				}
				if ((pacindx>270) && (pacindx<281))
				{
					pacindy += 3;
				}
				if ((pacindx>608) && (pacindx<623))
				{
					pacindy += 3;
				}
				if ((pacindx>708) && (pacindx<723))
				{
					pacindy += 3;
				}
				if (pacindx>854)
				{
					pacindy += 3;
				}

			}
		}
		if (pac_move_dir == 3)
		{
			if (40<pacindy)
			{
				if ((pacindx>0) && (pacindx<40))   //(pacindx>50)&&(pacindx<170)
				{
					pacindy -= 3;
				}
				if ((pacindx>166) && (pacindx<186))
				{
					pacindy -= 3;
				}
				if ((pacindx>270) && (pacindx<281))
				{
					pacindy -= 3;
				}
				if ((pacindx>608) && (pacindx<623))
				{
					pacindy -= 3;
				}
				if ((pacindx>708) && (pacindx<723))
				{
					pacindy -= 3;
				}
				if (pacindx>854)
				{
					pacindy -= 3;
				}
			}
		}
	}
	
	

}
void enemy_move_control()
{
	if (life_sec - time_sec >= 0)
		enemy_image_index++;
	if (enemy_image_index > 3)
	{
		enemy_image_index=0;
	}
}

void enemy_control()
{
	if (life_sec - time_sec >= 0)
	{
		if (enemy_move_dir == 0)
		{
			if (865>green_enemy_indx)
			{

				//green_enemy_indx+=5;
				if (green_enemy_indy<41)
				{
					green_enemy_indx += 5;
					//pacindx+=3;
				}
				else
				{

				}
				if ((green_enemy_indy>226) && (green_enemy_indy<240))
				{
					if (green_enemy_indx<183)
					{
						green_enemy_indx += 5;
						//pacindx+=3;
					}
					if (green_enemy_indx>708)
					{
						green_enemy_indx += 5;
						//pacindx+=3;
					}

				}
				else
				{

				}
				if (green_enemy_indy>422)
				{
					green_enemy_indx += 5;
					//pacindx+=3;
				}
				else
				{

				}
				if ((green_enemy_indy>135) && (green_enemy_indy<145))
				{
					if (green_enemy_indx<615)
					{
						green_enemy_indx += 5;
						//pacindx+=3;
					}
				}
				else
				{

				}
				if ((green_enemy_indy>329) && (green_enemy_indy<340))
				{
					if (green_enemy_indx<615)
					{
						green_enemy_indx += 5;
						//pacindx+=3;
					}

				}
				else
				{

				}
			}
			else
			{
				//enemy_rand_dir();
			}
		}
		if (enemy_move_dir == 1)
		{
			if (30<green_enemy_indx)
			{

				//green_enemy_indx-=5;
				if ((green_enemy_indy>28) && (green_enemy_indy<45))
				{
					green_enemy_indx -= 5;
					//pacindx-=3;
				}
				if ((green_enemy_indy>427))
				{
					green_enemy_indx -= 5;
					//pacindx-=3;
				}
				if ((green_enemy_indy>226) && (green_enemy_indy<240))// mid
				{
					if (green_enemy_indx<189)
					{
						green_enemy_indx -= 5;
						//pacindx-=3;
					}
					if (green_enemy_indx>712)
					{
						green_enemy_indx -= 5;
						//pacindx-=3;
					}

				}
				if ((green_enemy_indy>329) && (green_enemy_indy<340))
				{
					if (green_enemy_indx>278)
					{
						green_enemy_indx -= 5;
						//pacindx-=3;
					}

				}
				if ((green_enemy_indy>135) && (green_enemy_indy<145))
				{
					if (green_enemy_indx>278)
					{
						green_enemy_indx -= 5;
						//pacindx-=3;
					}
				}

			}
		}
		if (enemy_move_dir == 2)
		{
			if (432>green_enemy_indy)
			{
				//green_enemy_indy+=5;
				if ((green_enemy_indx>0) && (green_enemy_indx<40))   //(pacindx>50)&&(pacindx<170)
				{
					green_enemy_indy += 5;
					//pacindy+=3;
				}
				if ((green_enemy_indx>166) && (green_enemy_indx<186))
				{
					green_enemy_indy += 5;
					//pacindy+=3;
				}
				if ((green_enemy_indx>270) && (green_enemy_indx<281))
				{
					green_enemy_indy += 5;
					//pacindy+=3;
				}
				if ((green_enemy_indx>608) && (green_enemy_indx<623))
				{
					green_enemy_indy += 5;
					//pacindy+=3;
				}
				if ((green_enemy_indx>708) && (green_enemy_indx<723))
				{
					green_enemy_indy += 5;
					//pacindy+=3;
				}
				if (green_enemy_indx>854)
				{
					green_enemy_indy += 5;
					//pacindy+=3;
				}

			}
		}
		if (enemy_move_dir == 3)
		{
			if (40<green_enemy_indy)
			{
				//green_enemy_indy-=5;
				if ((green_enemy_indx>0) && (green_enemy_indx<40))   //(pacindx>50)&&(pacindx<170)
				{
					green_enemy_indy -= 5;
					//pacindy-=3;
				}
				if ((green_enemy_indx>166) && (green_enemy_indx<186))
				{
					green_enemy_indy -= 5;
					//pacindy-=3;
				}
				if ((green_enemy_indx>270) && (green_enemy_indx<281))
				{
					green_enemy_indy -= 5;
					//pacindy-=3;
				}
				if ((green_enemy_indx>608) && (green_enemy_indx<623))
				{
					green_enemy_indy -= 5;
					//pacindy-=3;
				}
				if ((green_enemy_indx>708) && (green_enemy_indx<723))
				{
					green_enemy_indy -= 5;
					//pacindy-=3;
				}
				if (green_enemy_indx>854)
				{
					green_enemy_indy -= 5;
					//pacindy-=3;
				}
			}
		}
	}
	
}
void enemy_rand_dir()
{
	//printf("%d\n",rand());
	if (flag == 1)
	{
		enemy_move_dir = rand() % 4;
		flag = 0;
	}
	
}
void enemy_dir_new()
{
	if ((green_enemy_indx >855) && (green_enemy_indy>426))
	{
		//printf("0_Yes\n");
		
		flag = 1;
	}
	else if ((green_enemy_indx > 855) && (green_enemy_indy <43))
	{
		
		//printf("1_yes\n");
		flag = 1;
	}
	else if ((green_enemy_indx <33) && (green_enemy_indy>426))
	{
		
		//printf("2_yes\n");
		flag = 1;
	}
	else if ((green_enemy_indx < 33) && (green_enemy_indy < 43))
	{
		
		//printf("3_yes\n");
		flag = 1;
	}
}

void score_change()
{
	//if (flag == 1)
	{
		//printf("%d\t%d\n", pacindx, pacindy);
		//printf("%d\t%d\n", pacindx, pacindy);
	}
	if ((pacindx+34 >green_enemy_indx+3) && (pacindx+34 < green_enemy_indx+40))  //61
	{
		if ((pacindy+35 >green_enemy_indy+30) && (pacindy+35 < green_enemy_indy + 59))  //72
		{
			end_pulse = clock();
			score++;
		}
		
	}
	
}

void time_count()
{
	if (flag==1)
	{
		//printf("Yes");
	}
	if (flag == 0)
	{
		//printf("YES start Clock\n");
		//start_pulse = clock();
		{
			//printf("YES e Clock\n");
			start_pulse = clock();
			time_sec = (start_pulse - end_pulse) / CLOCKS_PER_SEC;
		}

	}
	//printf("%d\t L : %d\n",time_sec,life_sec);
	
}


int main()
{
	srand(time(NULL));
	iSetTimer(10,pac_move_control);
	iSetTimer(50,pac_right_control);
	iSetTimer(50,enemy_move_control);
	iSetTimer(1,enemy_control);
	iSetTimer(1,enemy_rand_dir);
	
	iSetTimer(1,score_change);
	iSetTimer(100, enemy_dir_new);
	iSetTimer(1, time_count);
	
	//place your own initialization codes here.
	iInitialize(1350, 650, "Pacman");
	return 0;
}
