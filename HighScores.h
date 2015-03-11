# include <cstdio>

int highscoreseasy(int screenwidth, int screenheight, ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *backgr);
int highscoresmedium(int screenwidth, int screenheight, ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *backgr);
int highscoresdifficult(int screenwidth, int screenheight, ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *backgr);



struct Hs
{
    char Name[50];
    char time[10];
};

int highscores(int screenwidth, int screenheight, ALLEGRO_DISPLAY *display, ALLEGRO_BITMAP *backgr)
{
    int p, q;
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
    al_draw_text(font1, ElectricBlue, screenwidth / 2, screenheight / 60, ALLEGRO_ALIGN_CENTRE, "HighScore");

    //Content written i.e. student names
    ALLEGRO_FONT *font2 = al_load_ttf_font("Digital Sans.ttf", 40, NULL);
    al_draw_text(font2, BrightRed, screenwidth / 2, screenheight / 6 + 100, ALLEGRO_ALIGN_CENTER, "Easy");
    al_draw_text(font2, BrightRed, screenwidth / 2, screenheight / 4 + 100, ALLEGRO_ALIGN_CENTER, "Medium");
    al_draw_text(font2, BrightRed, screenwidth / 2, screenheight / 3 + 100, ALLEGRO_ALIGN_CENTER, "Difficult");
    al_draw_text(font2, BrightRed, 19*screenwidth / 20, 21*screenheight / 24, ALLEGRO_ALIGN_RIGHT, "Back To Main Screen");

    //Underlining Heading
    al_draw_line(screenwidth / 2 - 140 , 80, screenwidth / 2 + 140, 80, ElectricBlue, 4.0);

    al_flip_display();

    ALLEGRO_EVENT_QUEUE *backpress = al_create_event_queue();
    al_register_event_source(backpress, al_get_keyboard_event_source());
    al_register_event_source(backpress, al_get_display_event_source(display));
    al_register_event_source(backpress, al_get_mouse_event_source());

    ALLEGRO_EVENT eventback;

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
        int mousey = eventback.mouse.y;//cout << mousex << " " << mousey << endl;
        if((screenwidth / 2 - 50 < mousex) && (mousex < screenwidth / 2 + 50) && (mousey > screenheight / 6 + 100) && (mousey < screenheight / 6 + 140)) {al_clear_to_color(al_map_rgb(255,255,255)); p = highscoreseasy(screenwidth, screenheight, display, backgr);}
        if((screenwidth / 2 - 70 < mousex) && (mousex < screenwidth / 2 + 70) && (mousey > screenheight / 4 + 90) && (mousey < screenheight / 4 + 130)) {al_clear_to_color(al_map_rgb(255,255,255)); p = highscoresmedium(screenwidth, screenheight, display, backgr);}
        if((screenwidth / 2 - 50 < mousex) && (mousex < screenwidth / 2 + 50) && (mousey > screenheight / 3 + 100) && (mousey < screenheight / 3 + 140)) {al_clear_to_color(al_map_rgb(255,255,255)); p = highscoresdifficult(screenwidth, screenheight, display, backgr);}
        if((600 < mousex) && (mousex < 1000) && (mousey < 580) && (mousey > 520)) {done = true;}

     }
    if(p == 201) {return 201;} else if(p == 200) {return 200;}
}
}


int highscoreseasy(int screenwidth, int screenheight, ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *backgr)
{
    al_draw_bitmap(backgr, screenwidth / 2 - 256, screenheight / 2 - 256, NULL);

    //File editing
    FILE *HSNAMEEASYTXT;
    HSNAMEEASYTXT = fopen("hsnameeasy.txt","r");
    if (HSNAMEEASYTXT == NULL)
    {
        cout << "Could not open file" << endl;
        return -1;
    }
    FILE *HSTIMEEASYTXT;
    HSTIMEEASYTXT = fopen("hstimeeasy.txt","r");
    if (HSTIMEEASYTXT == NULL)
    {
        cout << "Could not open file" << endl;
        return -2;
    }
    Hs info;

    //defining colors to be used
    ALLEGRO_COLOR ElectricBlue = al_map_rgb(44, 117, 255);
    ALLEGRO_COLOR BrightRed = al_map_rgb(250, 28, 3);

    //Heading
    ALLEGRO_FONT *font1 = al_load_ttf_font("Digital Sans.ttf", 60, NULL);
    al_draw_text(font1, ElectricBlue, screenwidth / 2, screenheight / 60, ALLEGRO_ALIGN_CENTRE, "High Scores (EASY)");

    //Content written i.e. High Scores. Note that x = 0.5y
    ALLEGRO_FONT *font2 = al_load_ttf_font("Digital Sans.ttf", 40, NULL);

    for(int i = 0; i < 5; i++){
    fgets(info.Name, 100, HSNAMEEASYTXT);
    int l = strlen(info.Name);
    if(i != 4)
    info.Name[l - 1] = '\0';
    fgets(info.time, 100, HSTIMEEASYTXT);
    l = strlen(info.time);
    if(i != 4)
    info.time[l - 1] = '\0';
    int ycoord = (screenheight / 6) + (screenheight * (i) / 12);
    al_draw_text(font2, BrightRed, screenwidth / 20, ycoord , ALLEGRO_ALIGN_LEFT, info.Name);
    al_draw_text(font2, BrightRed, screenwidth / 20 + 500, ycoord , ALLEGRO_ALIGN_RIGHT, info.time);
    }

    //Underlining Heading
    al_draw_line(screenwidth / 2 - 140 , 80, screenwidth / 2 + 140, 80, ElectricBlue, 4.0);

    al_draw_text(font2, BrightRed, 19*screenwidth / 20, 21*screenheight / 24, ALLEGRO_ALIGN_RIGHT, "Back To Main Screen");

    al_flip_display();

    ALLEGRO_EVENT_QUEUE *backpress = al_create_event_queue();
    al_register_event_source(backpress, al_get_keyboard_event_source());
    al_register_event_source(backpress, al_get_display_event_source(display));
    al_register_event_source(backpress, al_get_mouse_event_source());

    ALLEGRO_EVENT eventback;

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

    al_clear_to_color(al_map_rgb(0,0,0));
    fclose(HSNAMEEASYTXT);
    fclose(HSTIMEEASYTXT);
    return 200;
}



int highscoresmedium(int screenwidth, int screenheight, ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *backgr)
{
    al_draw_bitmap(backgr, screenwidth / 2 - 256, screenheight / 2 - 256, NULL);

    //File editing
    FILE *HSNAMEMEDIUMTXT;
    HSNAMEMEDIUMTXT = fopen("hsnamemedium.txt","r");
    if (HSNAMEMEDIUMTXT == NULL)
    {
        cout << "Could not open file" << endl;
        return -1;
    }
    FILE *HSTIMEMEDIUMTXT;
    HSTIMEMEDIUMTXT = fopen("hstimemedium.txt","r");
    if (HSTIMEMEDIUMTXT == NULL)
    {
        cout << "Could not open file" << endl;
        return -2;
    }
    Hs info;

    //defining colors to be used
    ALLEGRO_COLOR ElectricBlue = al_map_rgb(44, 117, 255);
    ALLEGRO_COLOR BrightRed = al_map_rgb(250, 28, 3);

    //Heading
    ALLEGRO_FONT *font1 = al_load_ttf_font("Digital Sans.ttf", 60, NULL);
    al_draw_text(font1, ElectricBlue, screenwidth / 2, screenheight / 60, ALLEGRO_ALIGN_CENTRE, "High Scores (MEDIUM)");

    //Content written i.e. High Scores. Note that x = 0.5y
    ALLEGRO_FONT *font2 = al_load_ttf_font("Digital Sans.ttf", 40, NULL);

    for(int i = 0; i < 5; i++){
    fgets(info.Name, 100, HSNAMEMEDIUMTXT);
    int l = strlen(info.Name);
    if(i != 4)
    info.Name[l - 1] = '\0';
    fgets(info.time, 100, HSTIMEMEDIUMTXT);
    l = strlen(info.time);
    if(i != 4)
    info.time[l - 1] = '\0';
    int ycoord = (screenheight / 6) + (screenheight * (i) / 12);
    al_draw_text(font2, BrightRed, screenwidth / 20, ycoord , ALLEGRO_ALIGN_LEFT, info.Name);
    al_draw_text(font2, BrightRed, screenwidth / 20 + 500, ycoord , ALLEGRO_ALIGN_RIGHT, info.time);
    }

    //Underlining Heading
    al_draw_line(screenwidth / 2 - 140 , 80, screenwidth / 2 + 140, 80, ElectricBlue, 4.0);

    al_draw_text(font2, BrightRed, 19*screenwidth / 20, 21*screenheight / 24, ALLEGRO_ALIGN_RIGHT, "Back To Main Screen");

    al_flip_display();

    ALLEGRO_EVENT_QUEUE *backpress = al_create_event_queue();
    al_register_event_source(backpress, al_get_keyboard_event_source());
    al_register_event_source(backpress, al_get_display_event_source(display));
    al_register_event_source(backpress, al_get_mouse_event_source());

    ALLEGRO_EVENT eventback;

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

    //destroying not required pointers to prevent memory leak
    al_clear_to_color(al_map_rgb(0,0,0));
    fclose(HSNAMEMEDIUMTXT);
    fclose(HSTIMEMEDIUMTXT);
    return 200;
}


int highscoresdifficult(int screenwidth, int screenheight, ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *backgr)
{
    al_draw_bitmap(backgr, screenwidth / 2 - 256, screenheight / 2 - 256, NULL);

    //File editing
    FILE *HSNAMEDIFFICULTTXT;
    HSNAMEDIFFICULTTXT = fopen("hsnamedifficult.txt","r");
    if (HSNAMEDIFFICULTTXT == NULL)
    {
        cout << "Could not open file" << endl;
        return -1;
    }
    FILE *HSTIMEDIFFICULTTXT;
    HSTIMEDIFFICULTTXT = fopen("hstimedifficult.txt","r");
    if (HSTIMEDIFFICULTTXT == NULL)
    {
        cout << "Could not open file" << endl;
        return -2;
    }
    Hs info;

    //defining colors to be used
    ALLEGRO_COLOR ElectricBlue = al_map_rgb(44, 117, 255);
    ALLEGRO_COLOR BrightRed = al_map_rgb(250, 28, 3);

    //Heading
    ALLEGRO_FONT *font1 = al_load_ttf_font("Digital Sans.ttf", 60, NULL);
    al_draw_text(font1, ElectricBlue, screenwidth / 2, screenheight / 60, ALLEGRO_ALIGN_CENTRE, "High Scores (DIFFICULT)");

    //Content written i.e. High Scores. Note that x = 0.5y
    ALLEGRO_FONT *font2 = al_load_ttf_font("Digital Sans.ttf", 40, NULL);

    for(int i = 0; i < 5; i++){
    fgets(info.Name, 100, HSNAMEDIFFICULTTXT);
    int l = strlen(info.Name);
    if(i != 4)
    info.Name[l - 1] = '\0';
    fgets(info.time, 100, HSTIMEDIFFICULTTXT);
    l = strlen(info.time);
    if(i != 4)
    info.time[l - 1] = '\0';
    int ycoord = (screenheight / 6) + (screenheight * (i) / 12);
    al_draw_text(font2, BrightRed, screenwidth / 20, ycoord , ALLEGRO_ALIGN_LEFT, info.Name);
    al_draw_text(font2, BrightRed, screenwidth / 20 + 500, ycoord , ALLEGRO_ALIGN_RIGHT, info.time);
    }

    //Underlining Heading
    al_draw_line(screenwidth / 2 - 140 , 80, screenwidth / 2 + 140, 80, ElectricBlue, 4.0);

    al_draw_text(font2, BrightRed, 19*screenwidth / 20, 21*screenheight / 24, ALLEGRO_ALIGN_RIGHT, "Back To Main Screen");

    al_flip_display();

    ALLEGRO_EVENT_QUEUE *backpress = al_create_event_queue();
    al_register_event_source(backpress, al_get_keyboard_event_source());
    al_register_event_source(backpress, al_get_display_event_source(display));
    al_register_event_source(backpress, al_get_mouse_event_source());

    ALLEGRO_EVENT eventback;

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

    //destroying not required pointers to prevent memory leak
    al_clear_to_color(al_map_rgb(0,0,0));
    fclose(HSNAMEDIFFICULTTXT);
    fclose(HSTIMEDIFFICULTTXT);
    return 200;
}
