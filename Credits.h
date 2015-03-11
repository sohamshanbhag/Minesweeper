
int credits(int screenwidth, int screenheight, ALLEGRO_DISPLAY *display, ALLEGRO_BITMAP *backgr)
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
    ALLEGRO_FONT *font1 = al_load_ttf_font("Digital Sans.ttf", 60, NULL);
    al_draw_text(font1, ElectricBlue, screenwidth / 2, screenheight / 60, ALLEGRO_ALIGN_CENTRE, "Credits");

    //Content written i.e. student names
    ALLEGRO_FONT *font2 = al_load_ttf_font("Digital Sans.ttf", 40, NULL);
    al_draw_text(font2, BrightRed, screenwidth / 2, screenheight / 6, ALLEGRO_ALIGN_CENTER, "Pratyarth Rao(Group Leader)");
    al_draw_text(font2, BrightRed, screenwidth / 2, screenheight / 4, ALLEGRO_ALIGN_CENTER, "Sunny Soni");
    al_draw_text(font2, BrightRed, screenwidth / 2, screenheight / 3, ALLEGRO_ALIGN_CENTER, "Shubham Bansal");
    al_draw_text(font2, BrightRed, screenwidth / 2, 5*screenheight / 12, ALLEGRO_ALIGN_CENTER, "Soham Shanbhag");
    al_draw_text(font2, BrightRed, 19*screenwidth / 20, 21*screenheight / 24, ALLEGRO_ALIGN_RIGHT, "Back To Main Screen");

    //Underlining Heading
    al_draw_line(420 , 80, 580, 80, ElectricBlue, 4.0);

    ALLEGRO_EVENT_QUEUE *backpress = al_create_event_queue();
    al_register_event_source(backpress, al_get_keyboard_event_source());
    al_register_event_source(backpress, al_get_display_event_source(display));
    al_register_event_source(backpress, al_get_mouse_event_source());

    ALLEGRO_EVENT eventback;

    al_flip_display();

    bool done = false;
    while(!done){
    //Pressing back button for returning to main screen

    al_wait_for_event(backpress, &eventback);
    if(eventback.type == ALLEGRO_EVENT_KEY_DOWN)
    {if(eventback.keyboard.keycode == ALLEGRO_KEY_BACKSPACE) {done = true;}}
    else if(eventback.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
    {
        return 201;
    }
     else if(eventback.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
    {
        int mousex = eventback.mouse.x;
        int mousey = eventback.mouse.y;
        if((600 < mousex) && (mousex < 1000) && (mousey < 580) && (mousey > 520)) {done = true;}
    }
}
}



