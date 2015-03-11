# include <cstdio>
# include <string.h>
# include <iostream>
using namespace std;


struct Hswrite
{
    char Name[50];
    float time;
};


void rectimeeasy(int screenwidth, int screenheight, ALLEGRO_DISPLAY *display, ALLEGRO_BITMAP *backgr, float timereg){

int maxt = 5;

    Hswrite newinfoeasy;

    newinfoeasy.time = timereg;

    //File editing
    FILE *HSNAMETXT;
    HSNAMETXT = fopen("hsnameeasy.txt","r+");
    if (HSNAMETXT == NULL)
    {
        cout << "Could not open file" << endl;
      //  return -1;
    }
    FILE *HSTIMETXT;
    HSTIMETXT = fopen("hstimeeasy.txt","r+");
    if (HSTIMETXT == NULL)
    {
        cout << "Could not open file" << endl;
        //return -2;
    }
    Hswrite infoeasy[5];

    for(int i = 0; i < 5; i++)
    {
    fgets(infoeasy[i].Name, 100, HSNAMETXT);
    int l = strlen(infoeasy[i].Name);
    infoeasy[i].Name[l] = '\0';
    fscanf(HSTIMETXT, "%f", &infoeasy[i].time);
    }
//for(int i=0;i<5;i++)
  //  cout<<info[i].name<<'\t'<<info[i].time<<endl;
    for(int i = 0; i < 5; i++)
    {
        if(infoeasy[i].time > newinfoeasy.time)
        {
            maxt=i;
            break;
        }
    }

    if(maxt < 5)
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
    al_draw_text(font1, ElectricBlue, screenwidth / 2, screenheight / 60, ALLEGRO_ALIGN_CENTRE, "CONGRATS!! You created history!!");
    al_draw_line(300 , 80, 700, 80, ElectricBlue, 4.0);

    al_flip_display();

    //Content written i.e. student names
    ALLEGRO_FONT *font2 = al_load_ttf_font("Digital Sans.ttf", 40, NULL);

    //TO INPUT NAME OF PLAYER AND DISPLAY IT
    bool done=false, print=false;
    char player_name[2],p;
    int c = 0, i = 0;
    int x = 400;

    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
    al_register_event_source(event_queue,al_get_keyboard_event_source());
    al_register_event_source(event_queue,al_get_display_event_source(display));


    while(!done)
    {
        ALLEGRO_EVENT events;
        al_wait_for_event(event_queue,&events);
        if(events.type== ALLEGRO_EVENT_KEY_DOWN)
        {
            switch(events.keyboard.keycode)
            {
                case ALLEGRO_KEY_ENTER:
                done=true;
                break;
                default :
                c=events.keyboard.keycode;
                print=true;
            }

        }

        //Check
        i++;

        if(print)
        {
            print=false;
            p=c+64;
            player_name[0]=p;
            player_name[1]='\0';
            al_draw_text(font2,ElectricBlue,x,100,ALLEGRO_ALIGN_LEFT,player_name);
            x+=25;
            al_flip_display();
            newinfoeasy.Name[i] = player_name[0];
        }
    }
    newinfoeasy.Name[i + 1] == '\0';

    //Underlining Heading

    for(int i = 4; i > maxt; i--)
    {
        infoeasy[i] = infoeasy[i - 1];
    }
    infoeasy[maxt] = newinfoeasy;

    rewind(HSNAMETXT);
    rewind(HSTIMETXT);

    for(int i = 0; i < 5; i++)
    {
        fputs(infoeasy[i].Name, HSNAMETXT);
        if(i == maxt){fputs("\n",HSNAMETXT);}
        fprintf(HSTIMETXT, "%4f\n", infoeasy[i].time);
    }
    }
    fclose(HSNAMETXT);
    fclose(HSTIMETXT);
}



void rectimemedium(int screenwidth, int screenheight, ALLEGRO_DISPLAY *display, ALLEGRO_BITMAP *backgr, float timereg){

int maxt = 5;

    Hswrite newinfomedium;

    newinfomedium.time = timereg;

    //File editing
    FILE *HSNAMETXT;
    HSNAMETXT = fopen("hsnamemedium.txt","r+");
    if (HSNAMETXT == NULL)
    {
        cout << "Could not open file" << endl;
      //  return -1;
    }
    FILE *HSTIMETXT;
    HSTIMETXT = fopen("hstimemedium.txt","r+");
    if (HSTIMETXT == NULL)
    {
        cout << "Could not open file" << endl;
        //return -2;
    }
    Hswrite infomedium[5];

    for(int i = 0; i < 5; i++)
    {
    fgets(infomedium[i].Name, 100, HSNAMETXT);
    int l = strlen(infomedium[i].Name);
    infomedium[i].Name[l] = '\0';
    fscanf(HSTIMETXT, "%f", &infomedium[i].time);
    }
//for(int i=0;i<5;i++)
  //  cout<<info[i].name<<'\t'<<info[i].time<<endl;
    for(int i = 0; i < 5; i++)
    {
        if(infomedium[i].time > newinfomedium.time)
        {
            maxt=i;
            break;
        }
    }

    if(maxt < 5)
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
    al_draw_text(font1, ElectricBlue, screenwidth / 2, screenheight / 60, ALLEGRO_ALIGN_CENTRE, "CONGRATS!! You created history!!");
    al_draw_line(300 , 80, 700, 80, ElectricBlue, 4.0);

    al_flip_display();

    //Content written i.e. student names
    ALLEGRO_FONT *font2 = al_load_ttf_font("Digital Sans.ttf", 40, NULL);

    //TO INPUT NAME OF PLAYER AND DISPLAY IT
    bool done=false, print=false;
    char player_name[2],p;
    int c = 0, i = 0;
    int x = 400;

    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
    al_register_event_source(event_queue,al_get_keyboard_event_source());
    al_register_event_source(event_queue,al_get_display_event_source(display));


    while(!done)
    {
        ALLEGRO_EVENT events;
        al_wait_for_event(event_queue,&events);
        if(events.type== ALLEGRO_EVENT_KEY_DOWN)
        {
            switch(events.keyboard.keycode)
            {
                case ALLEGRO_KEY_ENTER:
                done=true;
                break;
                default :
                c=events.keyboard.keycode;
                print=true;
            }

        }

        //Check
        i++;

        if(print)
        {
            print=false;
            p=c+64;
            player_name[0]=p;
            player_name[1]='\0';
            al_draw_text(font2,ElectricBlue,x,100,ALLEGRO_ALIGN_LEFT,player_name);
            x+=25;
            al_flip_display();
        }
        newinfomedium.Name[i] = player_name[0];
    }
    newinfomedium.Name[i + 1] == '\0';

    //Underlining Heading

    for(int i = 4; i > maxt; i--)
    {
        infomedium[i] = infomedium[i - 1];
    }
    infomedium[maxt] = newinfomedium;

    rewind(HSNAMETXT);
    rewind(HSTIMETXT);

    for(int i = 0; i < 5; i++)
    {
        fputs(infomedium[i].Name, HSNAMETXT);
        if(i == maxt){fputs("\n",HSNAMETXT);}
        fprintf(HSTIMETXT, "%4f\n", infomedium[i].time);
    }
    }
    fclose(HSNAMETXT);
    fclose(HSTIMETXT);
}



void rectimedifficult(int screenwidth, int screenheight, ALLEGRO_DISPLAY *display, ALLEGRO_BITMAP *backgr, float timereg){

int maxt = 5;

    Hswrite newinfodifficult;

    newinfodifficult.time = timereg;

    //File editing
    FILE *HSNAMETXT;
    HSNAMETXT = fopen("hsnamedifficult.txt","r+");
    if (HSNAMETXT == NULL)
    {
        cout << "Could not open file" << endl;
      //  return -1;
    }
    FILE *HSTIMETXT;
    HSTIMETXT = fopen("hstimedifficult.txt","r+");
    if (HSTIMETXT == NULL)
    {
        cout << "Could not open file" << endl;
        //return -2;
    }
    Hswrite infodifficult[5];

    for(int i = 0; i < 5; i++)
    {
    fgets(infodifficult[i].Name, 100, HSNAMETXT);
    int l = strlen(infodifficult[i].Name);
    infodifficult[i].Name[l] = '\0';
    fscanf(HSTIMETXT, "%f", &infodifficult[i].time);
    }
//for(int i=0;i<5;i++)
  //  cout<<info[i].name<<'\t'<<info[i].time<<endl;
    for(int i = 0; i < 5; i++)
    {
        if(infodifficult[i].time > newinfodifficult.time)
        {
            maxt=i;
            break;
        }
    }

    if(maxt < 5)
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
    al_draw_text(font1, ElectricBlue, screenwidth / 2, screenheight / 60, ALLEGRO_ALIGN_CENTRE, "CONGRATS!! You created history!!");
    al_draw_line(300 , 80, 700, 80, ElectricBlue, 4.0);

    al_flip_display();

    //Content written i.e. student names
    ALLEGRO_FONT *font2 = al_load_ttf_font("Digital Sans.ttf", 40, NULL);

    //TO INPUT NAME OF PLAYER AND DISPLAY IT
    bool done=false, print=false;
    char player_name[2],p;
    int c = 0, i = 0;
    int x = 400;

    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
    al_register_event_source(event_queue,al_get_keyboard_event_source());
    al_register_event_source(event_queue,al_get_display_event_source(display));


    while(!done)
    {
        ALLEGRO_EVENT events;
        al_wait_for_event(event_queue,&events);
        if(events.type== ALLEGRO_EVENT_KEY_DOWN)
        {
            switch(events.keyboard.keycode)
            {
                case ALLEGRO_KEY_ENTER:
                done=true;
                break;
                default :
                c=events.keyboard.keycode;
                print=true;
            }

        }

        //Check
        i++;

        if(print)
        {
            print=false;
            p=c+64;
            player_name[0]=p;
            player_name[1]='\0';
            al_draw_text(font2,ElectricBlue,x,100,ALLEGRO_ALIGN_LEFT,player_name);
            x+=25;
            al_flip_display();
        }
        newinfodifficult.Name[i] = player_name[0];
    }
    newinfodifficult.Name[i + 1] == '\0';

    //Underlining Heading

    for(int i = 4; i > maxt; i--)
    {
        infodifficult[i] = infodifficult[i - 1];
    }
    infodifficult[maxt] = newinfodifficult;

    rewind(HSNAMETXT);
    rewind(HSTIMETXT);

    for(int i = 0; i < 5; i++)
    {
        fputs(infodifficult[i].Name, HSNAMETXT);
        if(i == maxt){fputs("\n",HSNAMETXT);}
        fprintf(HSTIMETXT, "%4f\n", infodifficult[i].time);
    }
    }
    fclose(HSNAMETXT);
    fclose(HSTIMETXT);
}
