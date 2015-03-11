# include <allegro.h>
# include <allegro_native_dialog.h>
# include <allegro_ttf.h>
# include <allegro_font.h>
# include <allegro_primitives.h>
# include <allegro_image.h>

# include <iostream>
using namespace std;

int screenwidth = 1000;
int screenheight = 600;

# include "Credits.h"
# include "HighScores.h"
# include "EndGame.h"
# include "workingeasy.h"
# include "workingmedium.h"
# include "workingdifficult.h"

int main()
{   int m, n, o, p, q;
    bool det_click = false;

    if(!al_init())
    {
        al_show_native_message_box(NULL,NULL,NULL,"ALLEGRO 5 CANNOT BE INITIALISED",NULL,ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    //TO CREATE GAME WINDOW WHICH IS RESIZABLE
    al_set_new_display_flags(ALLEGRO_WINDOWED | ALLEGRO_RESIZABLE);
    ALLEGRO_DISPLAY *display = al_create_display(screenwidth , screenheight);

    //TO SET TITLE OF THE GAME WINDOW
    al_set_window_title(display,"MINESWEEPER");
    al_set_window_position(display, 300, 50);

    //TO SHOW ERROR MESSAGE IF GAME SCREEN IS NOT CREATED
    if(!display)
    {
        al_show_native_message_box(NULL,"MINESWEEPER","ËRROR","DISPLAY BE CANNOT BE CREATED",NULL,ALLEGRO_MESSAGEBOX_ERROR);
        return-1;
    }

    al_init_font_addon();
    al_init_ttf_addon();
    ALLEGRO_FONT *font1 = al_load_ttf_font("Digital Sans.ttf",60,NULL),*font2 = al_load_ttf_font("Digital Sans.ttf",40,NULL);



    while (true){

    if(display == NULL){return 0;}

    //Background
    al_clear_to_color(al_map_rgb(255,255,255));
    al_init_image_addon();
    ALLEGRO_BITMAP *backgr;
    backgr = al_load_bitmap("background.png");
    if(!backgr)
    {
        al_show_native_message_box(display, "Error", "Error", "Failed to load image!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        al_destroy_display(display);
        return -1;
    }
    al_draw_bitmap(backgr, screenwidth / 2 - 256, screenheight / 2 - 256, NULL);


    //TO DISPLAY TEXT ON GAMESCREEN
    al_draw_text(font1,al_map_rgb(44,117,255),screenwidth/2,screenheight/60,ALLEGRO_ALIGN_CENTRE,"MINESWEEPER");

    //TO DRAW LINE
    al_init_primitives_addon();
    ALLEGRO_COLOR ElectricBlue = al_map_rgb(44,117,255);
    ALLEGRO_COLOR BrightRed = al_map_rgb(250,28,3);
    ALLEGRO_COLOR Black = al_map_rgb(0, 0, 0);
    ALLEGRO_COLOR Grey = al_map_rgb(172, 166, 166);
    al_draw_line(300,80,700,80,ElectricBlue,4.0);

  //  al_draw_text(font2,al_map_rgb(200,50,3),screenwidth/100,screenheight/6,ALLEGRO_ALIGN_LEFT,"ENTER PLAYER NAME :");


    al_install_keyboard();

    al_draw_text(font2, Black, screenwidth/100, screenheight/4, ALLEGRO_ALIGN_LEFT, "SELECT GAME MODE TO START GAME :");
    al_draw_text(font2, BrightRed, screenwidth/20, screenheight/3, ALLEGRO_ALIGN_LEFT, "- EASY");
    al_draw_text(font2, BrightRed, screenwidth/20, screenheight/2.4, ALLEGRO_ALIGN_LEFT, "- MEDIUM");
    al_draw_text(font2, BrightRed, screenwidth/20, screenheight/2, ALLEGRO_ALIGN_LEFT, "- DIFFICULT");
    al_draw_text(font2, Black, screenwidth/100, screenheight/1.62, ALLEGRO_ALIGN_LEFT, "VIEW HIGHSCORES");
    al_draw_text(font2, Black, screenwidth/100, screenheight/1.36, ALLEGRO_ALIGN_LEFT, "CREDITS");
    al_draw_text(font2, Black, screenwidth/100, screenheight/1.18, ALLEGRO_ALIGN_LEFT, "QUIT GAME");
    al_draw_line(screenwidth/100, screenheight/4 + 45, screenwidth/100 + 20, screenheight/4 + 45, Grey, 2.0);
    al_draw_line(screenwidth/100, screenheight/1.62 + 45, screenwidth/100 + 20, screenheight/1.62 + 45, Grey, 2.0);
    al_draw_line(screenwidth/100, screenheight/1.36 + 45, screenwidth/100 + 20, screenheight/1.36 + 45, Grey, 2.0);
    al_draw_line(screenwidth/100, screenheight/1.18 + 45, screenwidth/100 + 20, screenheight/1.18 + 45, Grey, 2.0);
    al_flip_display();

    al_install_mouse();

    screenwidth = al_get_display_width(display);
    screenheight = al_get_display_height(display);

    //Pressing C button for returning to main screen
    ALLEGRO_EVENT_QUEUE *eventqueue = al_create_event_queue();
    al_register_event_source(eventqueue, al_get_keyboard_event_source());
    al_register_event_source(eventqueue, al_get_display_event_source(display));
    al_register_event_source(eventqueue, al_get_mouse_event_source());

    ALLEGRO_EVENT event;

    al_wait_for_event(eventqueue, &event);
    if(event.type == ALLEGRO_EVENT_KEY_DOWN)
    {
        switch (event.keyboard.keycode)
        {
            case ALLEGRO_KEY_C : al_clear_to_color(al_map_rgb(255,255,255)); credits(screenwidth, screenheight, display, backgr); break;
            case ALLEGRO_KEY_H : al_clear_to_color(al_map_rgb(255,255,255)); highscores(screenwidth, screenheight, display, backgr); break;
            case ALLEGRO_KEY_Q : al_destroy_font(font1); al_destroy_font(font2); al_destroy_display(display); al_destroy_bitmap(backgr); return 0; break;
        }
    }
    else if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
    {
        al_destroy_font(font1); al_destroy_font(font2); al_destroy_display(display); al_destroy_bitmap(backgr); return 0;
    }
    else if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
    {
        int mousex = event.mouse.x;
        int mousey = event.mouse.y;//cout << mousex << " " << mousey << endl;
        det_click=true;
        if((0 < mousex) && (mousex < screenwidth / 3.16) && (mousey > screenheight / 1.57) && (mousey < screenheight / 1.57 + 45 )) {al_clear_to_color(al_map_rgb(255,255,255)); p = highscores(screenwidth, screenheight, display, backgr);}
        if((0 < mousex) && (mousex < screenwidth / 6.25) && (mousey > screenheight / 1.34) && (mousey < screenheight / 1.34 + 45)) {al_clear_to_color(al_map_rgb(255,255,255)); q = credits(screenwidth, screenheight, display, backgr);}
        if((0 < mousex) && (mousex < screenwidth / 5) && (mousey > screenheight / 1.17) && (mousey < screenheight / 1.17 + 45)) {al_destroy_font(font1); al_destroy_font(font2); al_destroy_display(display); al_destroy_bitmap(backgr); return 0;}
        if((60 < mousex) && (mousex < 170) && (mousey > 210) && (mousey < 250)) {al_clear_to_color(al_map_rgb(255,255,255)); m = gridcreateeasy(screenwidth, screenheight, display, backgr);}
        if((60 < mousex) && (mousex < 270) && (mousey > 255) && (mousey < 290)) {al_clear_to_color(al_map_rgb(255,255,255)); n = gridcreatemedium(screenwidth, screenheight, display, backgr);}
        if((60 < mousex) && (mousex < 240) && (mousey > 300) && (mousey < 350)) {al_clear_to_color(al_map_rgb(255,255,255)); o = gridcreatedifficult(screenwidth, screenheight, display, backgr);}


    }


    if (m == 200){continue;} else if (m == 201) {al_destroy_font(font1); al_destroy_font(font2); al_destroy_display(display); al_destroy_bitmap(backgr); return 0;}
    if (n == 200){continue;} else if (n == 201) {al_destroy_font(font1); al_destroy_font(font2); al_destroy_display(display); al_destroy_bitmap(backgr); return 0;}
    if (o == 200){continue;} else if (o == 201) {al_destroy_font(font1); al_destroy_font(font2); al_destroy_display(display); al_destroy_bitmap(backgr); return 0;}
    if (p == 201) {al_destroy_font(font1); al_destroy_font(font2); al_destroy_display(display); al_destroy_bitmap(backgr); return 0;}
    if (q == 201) {al_destroy_font(font1); al_destroy_font(font2); al_destroy_display(display); al_destroy_bitmap(backgr); return 0;}

}
}
