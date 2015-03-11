# include <iostream>
# include <stdlib.h>
# include <ctime>
using namespace std;
#ifndef WORKINGEASY_H
#define WORKINGEASY_H
#endif
#ifndef TIMEREC_H
#define TIMEREC_H
#endif

//const int n = 12;
void allocate_grid(int grid_array[][12],int mines_array[]);
int analyse_click(int a[][12],int i,int j, ALLEGRO_DISPLAY *display, ALLEGRO_BITMAP *backgr);
void allocate_griddifficult(int grid_array[][12],int mines_array[]);
int blank_box_click(int a[][12],int i,int j);
int win_check(int a[][12], ALLEGRO_DISPLAY *display, ALLEGRO_BITMAP *backgr, float timereg, ALLEGRO_TIMER *timer);
int drawdifficult(int grid_array[][12],int screenwidth, int screenheight, ALLEGRO_DISPLAY *display, ALLEGRO_BITMAP *backgr);



int gridcreatedifficult(int screenwidth, int screenheight, ALLEGRO_DISPLAY *display, ALLEGRO_BITMAP *backgr)
{
    int mines_array[12];
    int grid_array[12][12];
    create_grid(mines_array, 12);
    allocate_griddifficult(grid_array,mines_array);

    int m = drawdifficult(grid_array, screenwidth, screenheight, display, backgr);
    if(m == 200){return 200;} else if (m == 201) {return 201;} else {return 0;}

    return 0;
}

int drawdifficult(int grid_array[][12],int screenwidth, int screenheight, ALLEGRO_DISPLAY *display, ALLEGRO_BITMAP *backgr)
{
    al_init_font_addon();
    al_init_ttf_addon();
    ALLEGRO_FONT *font2 = al_load_ttf_font("Digital Sans.ttf",40,NULL);

    al_draw_bitmap(backgr, screenwidth / 2 - 256, screenheight / 2 - 256, NULL);
    al_init_primitives_addon();

    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 12; j++)
        {
            al_draw_rectangle(screenwidth/2 - 12*25 + 50*i, screenheight/2 - 12*25 + 50*j,screenwidth/2 - 12*25 + 50*(i + 1), screenheight/2 - 12*25 + 50*(j + 1),al_map_rgb(0,0,0), 1.0);
        }
    }



    al_init_image_addon();
    ALLEGRO_BITMAP *Flag;
    Flag = al_load_bitmap("Flag.png");
    if(!Flag)
    {
        al_show_native_message_box(display, "Error", "Error", "Failed to load image!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        al_destroy_display(display);
        return -1;
    }


    int time = 0;
    int mousex, mousey, temp, i, j, m, k;
    int minuteint = 0;
    ALLEGRO_MOUSE_STATE pressbutton;

    ALLEGRO_TIMER *timer = al_create_timer(1.0);

    float timereg;

    al_flip_display();

    //Pressing back button for returning to main screen
    ALLEGRO_EVENT_QUEUE *backpress = al_create_event_queue();
    al_register_event_source(backpress, al_get_display_event_source(display));
    al_register_event_source(backpress, al_get_mouse_event_source());
    al_register_event_source(backpress, al_get_timer_event_source(timer));

    ALLEGRO_EVENT eventback;

    al_start_timer(timer);

    bool done = false;
    int d1=0,d2=0,d3=0,d4=0;
    char s[3],mi[3];
    while(!done)
    {
        al_wait_for_event(backpress, &eventback);
        if(eventback.type == ALLEGRO_EVENT_TIMER)
        {
               time++;
            if(time > 59){minuteint += 1; time = 0;}
            //cout << minuteint << ":" << time << endl;
            timereg = minuteint + (0.01*time);
            d1++;
        if(d1>9)
        {
            d1=0;
            d2++;
        }
        if(d2==6)
        {
            d2=0;
            d3++;
        }
        if(d3>9)
        {
            d3=0;
            d4++;
        }
        s[1]=d1+48;
        s[0]=d2+48;
        mi[1]=d3+48;
        mi[0]=d4+48;
        s[2]='\0';mi[2]='\0';

        al_draw_filled_rectangle(870,140,980,200,al_map_rgb(255,255,255));
        al_draw_text(font2,al_map_rgb(0,0,0),23*screenwidth/25-20,screenheight/4,ALLEGRO_ALIGN_RIGHT,mi);
        al_draw_text(font2,al_map_rgb(0,0,0),23*screenwidth/25-13,screenheight/4-2,ALLEGRO_ALIGN_RIGHT,":");
        al_draw_text(font2,al_map_rgb(0,0,0),24*screenwidth/25-10,screenheight/4,ALLEGRO_ALIGN_RIGHT,s);
        al_flip_display();

        }
        else if(eventback.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            return 201;
        }
        else if(eventback.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {
            mousex = eventback.mouse.x;
            mousey = eventback.mouse.y;
            temp = mousex - screenwidth/2 + 300;
            j = temp / 50;cout << j;
            temp = mousey - screenheight/2 + 300;
            i = temp / 50;cout << i;

            al_get_mouse_state(&pressbutton);
            if (pressbutton.buttons & 2)
            {
                al_draw_bitmap(Flag, screenwidth/2 - 12*25 + 50*j, screenheight/2 - 12*25 + 50*i, NULL);
                al_draw_rectangle(screenwidth/2 - 12*25 + 50*j, screenheight/2 - 12*25 + 50*i,screenwidth/2 - 12*25 + 50*(j + 1), screenheight/2 - 12*25 + 50*(i + 1),al_map_rgb(0,0,0), 1.0);
                al_flip_display();
            }
            if (pressbutton.buttons & 1)
            {
                k = analyse_click(grid_array,i,j, display, backgr); if(k == 200){return 200;} else if (k == 201) {return 201;}
                m = win_check(grid_array, display, backgr, timereg, timer); if(m == 200){return 200;} else if (m == 201) {return 201;}
            }
        }
    }

}


void allocate_griddifficult(int grid_array[][12],int mines_array[])
{

    int r=0;
    int c=0;

    //intialising array with their respective numbers
    for(r=0;r<12;r++)
    {
        for(c=0;c<12;c++)
        {
            grid_array[r][c]=(r*12)+(c+1);
            //cout<<grid_array[r][c]<<endl; //printing grid-array
        }
    }
    // putting values -1 to selected grids
    for(r=0;r<12;r++)
    {
        for(c=0;c<12;c++)
        {
            for(int i=0;i<12;i++)
            {
                if(mines_array[i]==grid_array[r][c])
                {
                    grid_array[r][c]=-1;
                    break;
                }

            }
        }
    }
            // assigning 0 to other grids
            for(r=0;r<12;r++){
                for(c=0;c<12;c++){
                    if(grid_array[r][c]!=-1)
                        grid_array[r][c]=0;
                //cout<<grid_array[r][c]<<endl;
                }

            }
       // assigning the correct values
    for(int r=0;r<12;r++)
    {
        for(int c=0;c<12;c++)
        {
            if(grid_array[r][c]==-1){
            if(grid_array[r-1][c-1]!=-1 && r>0 && c>0)grid_array[r-1][c-1]++;
            if(grid_array[r-1][c]!=-1 && r>0)grid_array[r-1][c]++;
            if(grid_array[r-1][c+1]!=-1 && r>0 && c<12-1)grid_array[r-1][c+1]++;
            if(grid_array[r][c-1]!=-1 && c>0)grid_array[r][c-1]++;
            if(grid_array[r][c+1]!=-1 && c<12-1)grid_array[r][c+1]++;
            if(grid_array[r+1][c-1]!=-1 && r<12-1 && c>0)grid_array[r+1][c-1]++;
            if(grid_array[r+1][c]!=-1 && r<12-1)grid_array[r+1][c]++;
            if(grid_array[r+1][c+1]!=-1 && r<12-1 && c<12-1)grid_array[r+1][c+1]++;


            }
         }
    }

    for(r=0;r<12;r++)
    {
        for(c=0;c<12;c++)
        {
           // cout<<grid_array[r][c]<<'\t';
        }
       // cout<<endl<<endl;
    }
}

int blank_box_click(int a[][12],int i,int j)
{
    al_init_font_addon();
    al_init_ttf_addon();
    ALLEGRO_FONT *font2 = al_load_ttf_font("Digital Sans.ttf",40,NULL);
    char c[2];
    if(i<0 || j<0 || i>11 || j>11)return 0;
    if(a[i][j]!=0 && a[i][j]<10)
    {
        al_draw_filled_rectangle(screenwidth/2 - 12*25 + 50*j, screenheight/2 - 12*25 + 50*i,screenwidth/2 - 12*25 + 50*(j + 1), screenheight/2 - 12*25 + 50*(i + 1),al_map_rgb(200,200,200));
        al_draw_rectangle(screenwidth/2 - 12*25 + 50*j, screenheight/2 - 12*25 + 50*i,screenwidth/2 - 12*25 + 50*(j + 1), screenheight/2 - 12*25 + 50*(i + 1),al_map_rgb(0,0,0), 1.0);
        al_flip_display();
        c[0] = a[i][j]+48;
        c[1] = '\0';
        a[i][j]+=10;
        al_draw_text(font2, al_map_rgb(0,0,0), screenwidth/2 - 12*25 + 25 + 50*j, screenheight/2 - 12*25 + 50*i, ALLEGRO_ALIGN_CENTER, c);
        al_flip_display();
        return 0;
    }
    if(a[i][j]>=10)
    {
        return 0;
    }
    else if(a[i][j]==0)
    {
        al_draw_filled_rectangle(screenwidth/2 - 12*25 + 50*j, screenheight/2 - 12*25 + 50*i,screenwidth/2 - 12*25 + 50*(j + 1), screenheight/2 - 12*25 + 50*(i + 1),al_map_rgb(200,200,200));
        al_draw_rectangle(screenwidth/2 - 12*25 + 50*j, screenheight/2 - 12*25 + 50*i,screenwidth/2 - 12*25 + 50*(j + 1), screenheight/2 - 12*25 + 50*(i + 1),al_map_rgb(0,0,0), 1.0);
        al_flip_display();
        a[i][j]=10;
        blank_box_click(a,i+1,j);
        blank_box_click(a,i,j+1);
        blank_box_click(a,i-1,j);
        blank_box_click(a,i,j-1);
        blank_box_click(a,i+1,j+1);
        blank_box_click(a,i+1,j-1);
        blank_box_click(a,i-1,j-1);
        blank_box_click(a,i-1,j+1);
    }
    return 0;
}

int analyse_click(int a[][12], int i, int j, ALLEGRO_DISPLAY *display, ALLEGRO_BITMAP *backgr)
{
    al_init_image_addon();
    ALLEGRO_BITMAP *Mine;
    Mine = al_load_bitmap("Mine.png");
    if(!Mine)
    {
        al_show_native_message_box(display, "Error", "Error", "Failed to load image!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        al_destroy_display(display);
        return -1;
    }

   // cout << "test" << endl;
    char c[2];
    al_init_font_addon();
    al_init_ttf_addon();
    ALLEGRO_FONT *font2 = al_load_ttf_font("Digital Sans.ttf",40,NULL);


    if(a[i][j]>=10)return -2;
    if(a[i][j]==-1)
    {
        for(i = 0; i < 12; i++){for (j = 0; j < 12; j++){if(a[i][j] == -1){
        al_draw_filled_rectangle(screenwidth/2 - 12*25 + 50*j, screenheight/2 - 12*25 + 50*i,screenwidth/2 - 12*25 + 50*(j + 1), screenheight/2 - 12*25 + 50*(i + 1),al_map_rgb(255,255,255));
        al_draw_bitmap(Mine, screenwidth/2 - 12*25 + 50*j, screenheight/2 - 12*25 + 50*i, NULL);
        al_draw_rectangle(screenwidth/2 - 12*25 + 50*j, screenheight/2 - 12*25 + 50*i,screenwidth/2 - 12*25 + 50*(j + 1), screenheight/2 - 12*25 + 50*(i + 1),al_map_rgb(0,0,0), 1.0);
        al_flip_display();}}}
        al_rest(1.5);
        al_clear_to_color(al_map_rgb(255,255,255));
        int m = lose(screenwidth,screenheight, display, backgr);
        if(m == 200){return 200;} else if (m == 201) {return 201;} else {return 0;}
    }
    else if(a[i][j]==0)
    {
        blank_box_click(a,i,j);
        return 0;
    }
    else
    {
        al_draw_filled_rectangle(screenwidth/2 - 12*25 + 50*j, screenheight/2 - 12*25 + 50*i,screenwidth/2 - 12*25 + 50*(j + 1), screenheight/2 - 12*25 + 50*(i + 1),al_map_rgb(200,200,200));
        al_draw_rectangle(screenwidth/2 - 12*25 + 50*j, screenheight/2 - 12*25 + 50*i,screenwidth/2 - 12*25 + 50*(j + 1), screenheight/2 - 12*25 + 50*(i + 1),al_map_rgb(0,0,0), 1.0);
        al_flip_display();
        c[0] = a[i][j]+48;
        c[1] = '\0';
        al_draw_text(font2, al_map_rgb(0,0,0), screenwidth/2 - 12*25 + 25 + 50*j, screenheight/2 - 12*25 + 50*i, ALLEGRO_ALIGN_CENTER, c);
        al_flip_display();
        a[i][j]+=10;
        return 0;
    }
}



int win_check(int grid_array[][12], ALLEGRO_DISPLAY *display, ALLEGRO_BITMAP *backgr, float timereg, ALLEGRO_TIMER *timer)
{
    int m;
    int w=0;
    for(int i=0;i<12;i++){
        for(int j=0; j<12;j++){
            if(grid_array[i][j]>9)w++;}
                        }

    if(w==132)
    {
        al_destroy_timer(timer);
        al_clear_to_color(al_map_rgb(255,255,255));
        rectimedifficult(screenwidth, screenheight, display, backgr, timereg);
        al_clear_to_color(al_map_rgb(255,255,255));
        m = win(screenwidth,screenheight, display, backgr);

    }
    if(m == 200){return 200;} else if (m == 201) {return 201;} else {return 0;}
}

