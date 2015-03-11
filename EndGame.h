
int win(int screenwidth, int screenheight, ALLEGRO_DISPLAY *display, ALLEGRO_BITMAP *backgr)
{

    al_draw_bitmap(backgr, screenwidth / 2 - 256, screenheight / 2 - 256, NULL);

    //initialising all required libraries
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_primitives_addon();

    //defining colors to be used
    ALLEGRO_COLOR ElectricBlue = al_map_rgb(44, 117, 255);
    ALLEGRO_COLOR BrightRed = al_map_rgb(250, 28, 3);

    //Heading
    ALLEGRO_FONT *font1 = al_load_ttf_font("Digital Sans.ttf", 60, NULL),*font2 = al_load_ttf_font("Digital Sans.ttf",40,NULL);

    al_draw_text(font1, ElectricBlue, screenwidth / 2, screenheight / 50, ALLEGRO_ALIGN_CENTRE, "You WIN!!");
    //Underlining Heading
    al_draw_line(screenwidth / 2 -130 , 80, screenwidth / 2 + 130, 80, ElectricBlue, 4.0);

    al_draw_text(font2, BrightRed, screenwidth / 2, screenheight / 3.5, ALLEGRO_ALIGN_CENTER, "New game");
    al_draw_text(font2, BrightRed, screenwidth / 2, screenheight / 2, ALLEGRO_ALIGN_CENTER, "Quit");

    al_flip_display();

    al_install_mouse();
    int mousex,mousey;
    bool det_click=false;
    bool done = false;
    while(!done){
    //Pressing back button for returning to main screen
    ALLEGRO_EVENT_QUEUE *backpress = al_create_event_queue();
    al_register_event_source(backpress, al_get_keyboard_event_source());
    al_register_event_source(backpress, al_get_display_event_source(display));
    al_register_event_source(backpress, al_get_mouse_event_source());

    ALLEGRO_EVENT eventback;

    al_wait_for_event(backpress, &eventback);
    if(eventback.type == ALLEGRO_EVENT_KEY_DOWN){
    if(eventback.keyboard.keycode == ALLEGRO_KEY_BACKSPACE) {done = true;}}
    else if(eventback.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
    {
        return 201;
    }
    else if(eventback.type == ALLEGRO_EVENT_MOUSE_AXES)
    {
        mousex = eventback.mouse.x;
        mousey = eventback.mouse.y;

    }
     else if(eventback.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
    {
        //cout << mousex << " " << mousey << endl;
        if((400 < mousex) && (mousex < 600) && (mousey > 170) && (mousey < 220)) {al_clear_to_color(al_map_rgb(255,255,255)); return 200;}
        if((460 < mousex) && (mousex < 540) && (mousey > 300) && (mousey < 350)) { return 201;}
    }
    if(det_click==false)
    {
        if((400 < mousex) && (mousex < 600) && (mousey > 170) && (mousey < 220))
        {
            al_draw_text(font2, ElectricBlue, screenwidth / 2, screenheight / 3.5, ALLEGRO_ALIGN_CENTER, "New game");
            al_draw_text(font2, BrightRed, screenwidth / 2, screenheight / 2, ALLEGRO_ALIGN_CENTER, "Quit");
        }
        else if((460 < mousex) && (mousex < 540) && (mousey > 300) && (mousey < 350))
        {
            al_draw_text(font2, BrightRed, screenwidth / 2, screenheight / 3.5, ALLEGRO_ALIGN_CENTER, "New game");
            al_draw_text(font2, ElectricBlue, screenwidth / 2, screenheight / 2, ALLEGRO_ALIGN_CENTER, "Quit");
        }
        else
        {
            al_draw_text(font2, BrightRed, screenwidth / 2, screenheight / 3.5, ALLEGRO_ALIGN_CENTER, "New game");
            al_draw_text(font2, BrightRed, screenwidth / 2, screenheight / 2, ALLEGRO_ALIGN_CENTER, "Quit");
        }

    }
    al_flip_display();
}
}


int lose(int screenwidth, int screenheight, ALLEGRO_DISPLAY *display, ALLEGRO_BITMAP *backgr)
{
    int mousex,mousey;
    bool det_click=false;
    al_draw_bitmap(backgr, screenwidth / 2 - 256, screenheight / 2 - 256, NULL);

    //initialising all required libraries
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_primitives_addon();

    //defining colors to be used
    ALLEGRO_COLOR ElectricBlue = al_map_rgb(0, 0, 255);
    ALLEGRO_COLOR BrightRed = al_map_rgb(250, 28, 3);

    //Heading
    ALLEGRO_FONT *font1 = al_load_ttf_font("Digital Sans.ttf", 60, NULL);
    al_draw_text(font1, ElectricBlue, screenwidth / 2, screenheight / 50, ALLEGRO_ALIGN_CENTRE, "You Lose!!");

    //Content written i.e. student names
    ALLEGRO_FONT *font2 = al_load_ttf_font("Digital Sans.ttf", 40, NULL);

    //Underlining Heading
    al_draw_line(screenwidth / 2 - 130 , 80, screenwidth / 2 + 130, 80, ElectricBlue, 4.0);

    al_draw_text(font2, BrightRed, screenwidth / 2, screenheight / 3.5, ALLEGRO_ALIGN_CENTER, "New game");
    al_draw_text(font2, BrightRed, screenwidth / 2, screenheight / 2, ALLEGRO_ALIGN_CENTER, "Quit");

    al_flip_display();

    al_install_mouse();


    bool done = false;
    while(!done){
    det_click=false;
    //Pressing back button for returning to main screen
    ALLEGRO_EVENT_QUEUE *backpress = al_create_event_queue();
    al_register_event_source(backpress, al_get_keyboard_event_source());
    al_register_event_source(backpress, al_get_display_event_source(display));
    al_register_event_source(backpress, al_get_mouse_event_source());

    ALLEGRO_EVENT eventback;

    al_wait_for_event(backpress, &eventback);
    if(eventback.type == ALLEGRO_EVENT_KEY_DOWN){
    if(eventback.keyboard.keycode == ALLEGRO_KEY_BACKSPACE) {done = true;}}
    else if(eventback.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
    {
        return 201;
    }
    else if(eventback.type == ALLEGRO_EVENT_MOUSE_AXES)
    {
        mousex = eventback.mouse.x;
        mousey = eventback.mouse.y;

    }
    else if(eventback.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
    {
        det_click=true;
        //cout << mousex << " " << mousey << endl;
        if((400 < mousex) && (mousex < 600) && (mousey > 170) && (mousey < 220)) {al_clear_to_color(al_map_rgb(255,255,255)); return 200;}
        if((460 < mousex) && (mousex < 540) && (mousey > 300) && (mousey < 350)) {return 201;}
    }
    if(det_click==false)
    {
        if((400 < mousex) && (mousex < 600) && (mousey > 170) && (mousey < 220))
        {
            al_draw_text(font2, ElectricBlue, screenwidth / 2, screenheight / 3.5, ALLEGRO_ALIGN_CENTER, "New game");
            al_draw_text(font2, BrightRed, screenwidth / 2, screenheight / 2, ALLEGRO_ALIGN_CENTER, "Quit");
        }
        else if((460 < mousex) && (mousex < 540) && (mousey > 300) && (mousey < 350))
        {
            al_draw_text(font2, BrightRed, screenwidth / 2, screenheight / 3.5, ALLEGRO_ALIGN_CENTER, "New game");
            al_draw_text(font2, ElectricBlue, screenwidth / 2, screenheight / 2, ALLEGRO_ALIGN_CENTER, "Quit");
        }
        else
        {
            al_draw_text(font2, BrightRed, screenwidth / 2, screenheight / 3.5, ALLEGRO_ALIGN_CENTER, "New game");
            al_draw_text(font2, BrightRed, screenwidth / 2, screenheight / 2, ALLEGRO_ALIGN_CENTER, "Quit");
        }

    }
    al_flip_display();
}
}
