#include<stdio.h>
#include<stdlib.h>
#include<allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_ttf.h>
#include<time.h>
#include<allegro5/allegro_image.h>

int height = 700;
int width = 600;

void input(int letter_x, int wordinput[]);
int check(int word[], int wordinput[]);


int main()
{
	al_init();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_mouse();
	al_init_image_addon();

	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_FONT* font30 = NULL; 	ALLEGRO_FONT* font15 = NULL;
	ALLEGRO_FONT* font40 = NULL;
	ALLEGRO_TIMER* timer = NULL;

	ALLEGRO_BITMAP* backround = NULL;
	ALLEGRO_BITMAP* word1bm = NULL;
	ALLEGRO_BITMAP* word2bm = NULL;
	ALLEGRO_BITMAP* word3bm = NULL;
	ALLEGRO_BITMAP* winscreen = NULL;

	font40 = al_load_font("courbd.ttf", 40, 0);
	font30 = al_load_font("courbd.ttf", 30, 0);
	font15 = al_load_font("courbd.ttf", 15, 0);

	backround = al_load_bitmap("backround.png");
	word1bm = al_load_bitmap("word1.png");
	word2bm = al_load_bitmap("word2.png");
	word3bm = al_load_bitmap("word3.png");
	winscreen = al_load_bitmap("winscreen.png");


	const int fps = 60;
	timer = al_create_timer(1.0 / fps);
	display = al_create_display(width, height);
	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_hide_mouse_cursor(display);

	//letters---------
	int word1[10] = { 'a','r','m','y',0,0,0,0,0,0 };
	int word2[10] = { 'r','a','m',0,0,0,0,0,0,0 };
	int word3[10] = { 'a','r','m',0,0,0,0,0,0,0 };
	int word4[10] = { 'a','b','c',0,0,0,0,0,0,0 };
	int letter_a = 'a';
	int letter_b = 'r';
	int letter_c = 'm';
	int letter_d = 'y';


	int wordinput[10] = { 0,0,0,0,0,0,0,0,0,0 };
	//

	bool redraw = true;
	int posx = 0, posy = 0;

	int dot1x = posx, dot1y = posy, dot2x = posx, dot2y = posy, dot3x = posx, dot3y = posy;

	bool hold = false;
	bool clicka = false;
	bool clickb = false;
	bool clickc = false;
	bool clickd = false;

	bool restart = false;

	bool locka = false;
	bool lockb = false;
	bool lockc = false;
	bool lockd = false;

	bool target = false;

	int ar = 0, ag = 0, ab = 0;
	int br = 0, bg = 0, bb = 0;
	int cr = 0, cg = 0, cb = 0;
	int dr = 0, dg = 0, db = 0;

	int wincnt = 0;
	int wincntgoal = 60;

	bool target_check = false;
	bool target_restart = false;
	bool target_exit = false;
	bool target_a = false;
	bool target_b = false;
	bool target_c = false;
	bool target_d = false;

	bool word1true = false;
	bool word2true = false;
	bool word3true = false;

	bool lineclicka = false;
	bool lineclickb = false;
	bool lineclickc = false;
	bool lineclickd = false;

	int checkx = 500, checky = 350;
	int restartx = 100, restarty = 350;
	int exitx = 330, exity = 650;
	int bx = 200, by = 450;
	int ax = 300, ay = 350;
	int cx = 400, cy = 450;
	int dx = 300, dy = 550;

	int loop = 1;
	al_start_timer(timer);

	while (loop)
	{

		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			redraw = true;

		}
		if (ev.type == ALLEGRO_EVENT_MOUSE_AXES)
		{
			posx = ev.mouse.x;
			posy = ev.mouse.y;
		}
		//
		//drawdrawdraw---------
		al_draw_bitmap(backround, 0, 0, 0);

		al_draw_filled_circle(310, 460, 130, al_map_rgb(150, 150, 150));
		al_draw_line(310, 430, 310, 500, al_map_rgb(130, 130, 130), 5);
		al_draw_line(270, 465, 350, 465, al_map_rgb(130, 130, 130), 5);


		//
		//target true
		if (abs(posx - checkx + 15) < 20 && abs(posy - checky - 10) < 5)
		{
			target_check = true;

		}
		if (abs(posx - restartx + 5) < 30 && abs(posy - restarty - 10) < 5)
		{
			target_restart = true;

		}
		if (abs(posx - exitx + 20) < 20 && abs(posy - exity - 10) < 5)
		{
			target_exit = true;

		}
		if (abs(posx - ax - 15) < 20 && abs(posy - ay - 15) < 20)
		{
			target_a = true;

		}
		if (abs(posx - bx - 15) < 20 && abs(posy - by - 15) < 20)
		{
			target_b = true;

		}
		if (abs(posx - cx - 15) < 20 && abs(posy - cy - 15) < 20)
		{
			target_c = true;

		}
		if (abs(posx - dx - 15) < 20 && abs(posy - dy - 15) < 20)
		{
			target_d = true;

		}
		//

		//target false
		if (abs(posx - checkx + 15) > 20 || abs(posy - checky - 10) > 5)
		{
			target_check = false;

		}
		if (abs(posx - restartx + 5) > 30 || abs(posy - restarty - 10) > 5)
		{
			target_restart = false;

		}
		if (abs(posx - exitx + 20) > 20 || abs(posy - exity - 10) > 5)
		{
			target_exit = false;

		}
		if (abs(posx - ax - 15) > 20 || abs(posy - ay - 15) > 20)
		{
			target_a = false;

		}
		if (abs(posx - bx - 15) > 20 || abs(posy - by - 15) > 20)
		{
			target_b = false;


		}
		if (abs(posx - cx - 15) > 20 || abs(posy - cy - 15) > 20)
		{
			target_c = false;

		}
		if (abs(posx - dx - 15) > 20 || abs(posy - dy - 15) > 20)
		{
			target_d = false;

		}
		//

		//click----------------------

		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if (ev.mouse.button & 1 && target_a && locka == false)
			{
				clicka = true;
			}
		}
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if (ev.mouse.button & 1 && target_b && lockb == false)
			{
				clickb = true;
			}
		}
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if (ev.mouse.button & 1 && target_c && lockc == false)
			{
				clickc = true;
			}
		}
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if (ev.mouse.button & 1 && target_d && lockd == false)
			{
				clickd = true;
			}
		}

		//click workstation---------
		if (clicka)
		{
			input(letter_a, wordinput);
			printf("a");
			clicka = false;
			locka = true;

			lineclicka = true;
			lineclickb = false;
			lineclickc = false;
			lineclickd = false;
		}
		if (clickb == true)
		{
			input(letter_b, wordinput);
			printf("b");
			clickb = false;
			lockb = true;

			lineclicka = false;
			lineclickb = true;
			lineclickc = false;
			lineclickd = false;
		}
		if (clickc)
		{
			input(letter_c, wordinput);
			printf("c");
			clickc = false;
			lockc = true;

			lineclicka = false;
			lineclickb = false;
			lineclickc = true;
			lineclickd = false;
		}
		if (clickd)
		{
			input(letter_d, wordinput);
			printf("d");
			clickd = false;
			lockd = true;

			lineclicka = false;
			lineclickb = false;
			lineclickc = false;
			lineclickd = true;
		}

		//right click-------------
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && ev.mouse.button & 2)
		{
			locka = false;
			lockb = false;
			lockc = false;
			lockd = false;

			int z;
			for (z = 0; z < 10; z++)
			{
				wordinput[z] = 0;
			}
			lineclicka = false;
			lineclickb = false;
			lineclickc = false;
			lineclickd = false;
		}

		//check
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && ev.mouse.button & 1 && target_check)
		{
			if (check(word1, wordinput) == 1)
			{
				word1true = true;
				printf("\nword1: correct\n");
			}
			else printf("\nword1:incorrect\n");

			if (check(word2, wordinput) == 1)
			{
				word2true = true;
				printf("\nword2: correct\n");
			}
			else printf("\nword2: incorrect\n");

			if (check(word3, wordinput) == 1)
			{
				word3true = true;
				printf("\nword3: correct\n");
			}
			else printf("\nword3: incorrect\n");


			locka = false;
			lockb = false;
			lockc = false;
			lockd = false;

			int z;
			for (z = 0; z < 10; z++)
			{
				wordinput[z] = 0;
			}
			lineclicka = false;
			lineclickb = false;
			lineclickc = false;
			lineclickd = false;
		}

		//restart --------------
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && ev.mouse.button & 1 && target_restart)
		{
			word1true = false;
			word2true = false;
			word3true = false;

			locka = false;
			lockb = false;
			lockc = false;
			lockd = false;

			int z;
			for (z = 0; z < 10; z++)
			{
				wordinput[z] = 0;
			}
			lineclicka = false;
			lineclickb = false;
			lineclickc = false;
			lineclickd = false;

			wincnt = 0;
		}

		//exit----------------
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && ev.mouse.button & 1 && target_exit)
		{
			loop = 0;
		}

		//draw-------------
		if (locka)
		{
			al_draw_filled_circle(ax + 8, ay + 15, 25, al_map_rgb(255, 0, 0));
			ar = 255; ag = 255; ab = 255;
		}
		if (lockb)
		{
			al_draw_filled_circle(bx + 8, by + 15, 25, al_map_rgb(255, 0, 0));
			br = 255; bg = 255; bb = 255;
		}
		if (lockc)
		{
			al_draw_filled_circle(cx + 8, cy + 15, 25, al_map_rgb(255, 0, 0));
			cr = 255; cg = 255; cb = 255;
		}
		if (lockd)
		{
			al_draw_filled_circle(dx + 8, dy + 15, 25, al_map_rgb(255, 0, 0));
			dr = 255; dg = 255; db = 255;
		}
		if (!locka && !lockb && !lockc && !lockd)
		{
			ar = 0, ag = 0, ab = 0;
			br = 0, bg = 0, bb = 0;
			cr = 0, cg = 0, cb = 0;
			dr = 0, dg = 0, db = 0;
		}
		//line drawing-------
		if (lineclicka)
		{
			al_draw_line(ax + 8, ay + 15, posx, posy, al_map_rgb(255, 0, 0), 10);
		}
		if (lineclickb)
		{
			al_draw_line(bx + 8, by + 15, posx, posy, al_map_rgb(255, 0, 0), 10);
		}
		if (lineclickc)
		{
			al_draw_line(cx + 8, cy + 15, posx, posy, al_map_rgb(255, 0, 0), 10);
		}
		if (lineclickd)
		{
			al_draw_line(dx + 8, dy + 15, posx, posy, al_map_rgb(255, 0, 0), 10);
		}
		//
		if ((wordinput[0] == 'a' && wordinput[1] == 'r') || (wordinput[1] == 'a' && wordinput[0] == 'r')
			|| (wordinput[1] == 'a' && wordinput[2] == 'r') || (wordinput[2] == 'a' && wordinput[1] == 'r')
			|| (wordinput[2] == 'a' && wordinput[3] == 'r') || (wordinput[3] == 'a' && wordinput[2] == 'r'))
		{
			al_draw_line(ax + 8, ay + 15, bx + 8, by + 15, al_map_rgb(255, 0, 0), 10);
		}
		if ((wordinput[0] == 'a' && wordinput[1] == 'm') || (wordinput[1] == 'a' && wordinput[0] == 'm')
			|| (wordinput[1] == 'a' && wordinput[2] == 'm') || (wordinput[2] == 'a' && wordinput[1] == 'm')
			|| (wordinput[2] == 'a' && wordinput[3] == 'm') || (wordinput[3] == 'a' && wordinput[2] == 'm'))
		{
			al_draw_line(ax + 8, ay + 15, cx + 8, cy + 15, al_map_rgb(255, 0, 0), 10);
		}
		if ((wordinput[0] == 'm' && wordinput[1] == 'r') || (wordinput[1] == 'm' && wordinput[0] == 'r')
			|| (wordinput[1] == 'm' && wordinput[2] == 'r') || (wordinput[2] == 'm' && wordinput[1] == 'r')
			|| (wordinput[2] == 'm' && wordinput[3] == 'r') || (wordinput[3] == 'm' && wordinput[2] == 'r'))
		{
			al_draw_line(cx + 8, cy + 15, bx + 8, by + 15, al_map_rgb(255, 0, 0), 10);
		}
		if ((wordinput[0] == 'a' && wordinput[1] == 'y') || (wordinput[1] == 'a' && wordinput[0] == 'y')
			|| (wordinput[1] == 'a' && wordinput[2] == 'y') || (wordinput[2] == 'a' && wordinput[1] == 'y')
			|| (wordinput[2] == 'a' && wordinput[3] == 'y') || (wordinput[3] == 'a' && wordinput[2] == 'y'))
		{
			al_draw_line(ax + 8, ay + 15, dx + 8, dy + 15, al_map_rgb(255, 0, 0), 10);
		}
		if ((wordinput[0] == 'r' && wordinput[1] == 'y') || (wordinput[1] == 'r' && wordinput[0] == 'y')
			|| (wordinput[1] == 'r' && wordinput[2] == 'y') || (wordinput[2] == 'r' && wordinput[1] == 'y')
			|| (wordinput[2] == 'r' && wordinput[3] == 'y') || (wordinput[3] == 'r' && wordinput[2] == 'y'))
		{
			al_draw_line(bx + 8, by + 15, dx + 8, dy + 15, al_map_rgb(255, 0, 0), 10);
		}
		if ((wordinput[0] == 'm' && wordinput[1] == 'y') || (wordinput[1] == 'm' && wordinput[0] == 'y')
			|| (wordinput[1] == 'm' && wordinput[2] == 'y') || (wordinput[2] == 'm' && wordinput[1] == 'y')
			|| (wordinput[2] == 'm' && wordinput[3] == 'y') || (wordinput[3] == 'm' && wordinput[2] == 'y'))
		{
			al_draw_line(cx + 8, cy + 15, dx + 8, dy + 15, al_map_rgb(255, 0, 0), 10);
		}

		if ((locka && lockb && lockc && lockd) || posx > 450 && posy < 400 || posx < 130 && posy < 400)
		{
			lineclicka = false;
			lineclickb = false;
			lineclickc = false;
			lineclickd = false;
		}
		if (posy < 300)
		{
			locka = false;
			lockb = false;
			lockc = false;
			lockd = false;
			int r = 0, g = 0, b = 0;
			int z;
			for (z = 0; z < 10; z++)
			{
				wordinput[z] = 0;
			}
			lineclicka = false;
			lineclickb = false;
			lineclickc = false;
			lineclickd = false;
		}


		if (redraw && al_event_queue_is_empty(event_queue))
		{
			redraw = false;

			if (word1true)
			{
				al_draw_bitmap(word1bm, 0, 0, 0);
			}
			if (word2true)
			{
				al_draw_bitmap(word2bm, 0, 0, 0);
			}
			if (word3true)
			{
				al_draw_bitmap(word3bm, 0, 0, 0);
			}

			al_draw_text(font30, al_map_rgb(ar, ag, ab), ax, ay, 0, "A");
			al_draw_text(font30, al_map_rgb(br, bg, bb), bx, by, 0, "R");
			al_draw_text(font30, al_map_rgb(cr, cg, cb), cx, cy, 0, "M");
			al_draw_text(font30, al_map_rgb(dr, dg, db), dx, dy, 0, "Y");

			al_draw_text(font15, al_map_rgb(255, 255, 255), checkx - 40, checky, 0, "check");

			al_draw_line(0, 300, 600, 300, al_map_rgb(30, 30, 30), 5);

			if (word1true && word2true && word3true)
			{

				if (wincnt < wincntgoal)
				{
					wincnt++;
				}
				else al_draw_bitmap(winscreen, 0, 0, 0);
			}
			al_draw_text(font15, al_map_rgb(255, 255, 255), exitx - 40, exity, 0, "exit");
			al_draw_text(font15, al_map_rgb(255, 255, 255), restartx - 40, restarty, 0, "restart");

			al_draw_filled_circle(posx, posy, 3, al_map_rgb(255, 255, 255));
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}

	}


	return 0;
}

void input(int letter_x, int wordinput[])
{
	int x;
	for (x = 0; x < 9; x++)
	{
		if (wordinput[x] == 0)
		{
			wordinput[x] = letter_x;
		}
		if (wordinput[x] == letter_x)
		{
			break;
		}
	}
}
int check(int word[], int wordinput[])
{
	if (wordinput[0] != 0 && wordinput[1] != 0)
	{
		int flag = 0;
		int i;
		for (i = 0; i < 10; i++)
		{
			if (word[i] == wordinput[i])
			{
				flag = 1;
			}
			else if (word[i] != wordinput[i])
			{
				flag = 0;

			}
			if (flag == 0)
			{
				break;
			}
		}
		if (flag == 1) {
			return 1;
		}
		else if (flag == 0) {
			return 0;
		}
	}
}