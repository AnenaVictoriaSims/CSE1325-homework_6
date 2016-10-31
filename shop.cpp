//  GUI for Robbie Robot

//  shop:
//  - calls classes to make window & widgets

//  MakeWin:
//  - can be called to make a window with the given params

//  MakeBox:
//  - can be called to make a box with the given params

//  DisplayBox:
//  - can be called to make a display box

//  MakeButtons:
//  - creates unique buttons based on params
//  - each button has a callback & a handling method

//  A. Sims(10-30-16) : Need create a working Makefile so classes can be split into separate files. Need to figure out how to make menubar work with class structure

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Menu_Item.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Text_Display.H>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;


/*----------------------MakeWin CLASS--------------------*/
class MakeWin{
public:
    MakeWin(){};
    MakeWin(int x,int y,char* L): X(x),Y(y),lab(L){}
    void winProps(){
        win = new Fl_Window(X, Y, lab);
        win->color( FL_WHITE );
    }
    void showWin(){win->end();win->show();}
private:
    int X, Y;
    char* lab;
    Fl_Window *win;
};
/*----------------------MakeBox CLASS--------------------*/
class MakeBox{
public:
    MakeBox(){};
    MakeBox(int s, int x, int y, int w, int h, char* L):S(s),X(x),Y(y),W(w),H(h),lab(L){}
    void boxProps(){
        Fl_Box *box = new Fl_Box(X,Y,W,H,lab);
        box->box(FL_RSHADOW_BOX);
        box->labelfont(FL_BOLD+FL_ITALIC);
        box->labelsize(S);
        box->labeltype(FL_SHADOW_LABEL);
    }
private:
    int S, X, Y, W, H;
    char* lab;
};
/*---------------------DisplayBox CLASS------------------*/
class DisplayBox{
public:
    DisplayBox(){};
    DisplayBox(int wx, int wy, int s, int x, int y, int w, int h, char* L):wX(wx),wY(wy),S(s),X(x),Y(y),W(w),H(h),lab(L){}
    void dispBoxProps(){
        Fl_Window *win = new Fl_Window(wX,wY);
        Fl_Box *box = new Fl_Box(X,Y,W,H,lab);
        box->box(FL_UP_BOX);
        box->align(FL_ALIGN_WRAP);
        box->labelfont(FL_BOLD);
        box->labelsize(S);
        box->labeltype(FL_NORMAL_LABEL);
        //box->color( FL_RED );
        win->end();
        win->show();
    }
private:
    int wX, wY, S, X, Y, W, H;
    char* lab;
};
/*----------------------------------------------------MakeButtons CLASS---------------------------------------------------*/
class MakeButtons : DisplayBox{
 public:
//--------------------------Constructor--------------------
    MakeButtons(int x, int y, int w, int h, char* L):X(x),Y(y),W(w),H(h),lab(L){}
//----------------------Create Button----------------------
    void butProps(int k)
    {
         Fl_Button *but = new Fl_Button( X,Y,W,H,lab );
         switch( k )        //Determine which button was pushed
         {
             case 1:
                 but->callback( pmCB );     //perform callback for correct button
                 break;
             case 2:
                 but->callback( pbCB );
                 break;
             case 3:
                 but->callback( saCB );
                 break;
             case 4:
                 but->callback( bcCB );
                 break;
             case 5:
                 but->callback( docCB );
                 break;
         }
     }
//---------------------PM Handle Method--------------------
    static void pmHandleMenu(Fl_Widget *w, void *v)
    {
        if(!w || !v) return;    // no values passed
        switch( (intptr_t)v )   // give int value stored in 'v' to switch
        {
            case 1:     // if case 1 button was pushed
            {
                if(fl_choice("Are you the PM?", NULL, fl_no, fl_yes) == 2)      // display dialog box asking usr question
                    cout << "code to create robot parts" << endl;           // if yes, write code to create parts
                else
                {       // if no, instance displaybox class and display error msg to usr
                    DisplayBox box(640, 120, 36, 0, 0, 640, 120, "Only the PM can create parts");
                    box.dispBoxProps();
                }
                break;
            }
            case 2:     // if case 2 button was pushed, if/else works same as above
            {
                if(fl_choice("Are you the PM?", NULL, fl_no, fl_yes) == 2)
                    cout << "code to create robot Models" << endl;
                else
                {
                    DisplayBox box(640, 120, 36, 0, 0, 640, 120, "Only the PM can create models");
                    box.dispBoxProps();
                }
                break;
            }
            case 3:     // if case 3 button was pushed, if/else works same as above
            {
                if(fl_choice("Are you the PM?", NULL, fl_no, fl_yes) == 2)
                    cout << "code to display robot Models" << endl;
                else
                {
                    DisplayBox box(640, 120, 36, 0, 0, 640, 120, "Only the PM can view parts");
                    box.dispBoxProps();
                }
            }
                break;
            case 4:     // if case 4 button was pushed, anyone can view robot models
            {
                DisplayBox box(640, 120, 36, 0, 0, 640, 120, "Display models here");
                box.dispBoxProps();
            }
                break;
        }
    }
//------------------------PM Callback----------------------
    static void pmCB(Fl_Widget *w, void*)
    {
        Fl_Menu_Item rclick_menu[] = {      // array of popup menu options
            { "Create Robot Parts",  0, pmHandleMenu, (void*)1 },
            { "Create Robot Models",  0, pmHandleMenu, (void*)2 },  // calls handle method with given #
            { "View Robot Parts",  0, pmHandleMenu, (void*)3 },
            { "View Robot Models",  0, pmHandleMenu, (void*)4 },
            { 0 }
        };
        const Fl_Menu_Item *m = rclick_menu->popup( Fl::event_x(), Fl::event_y(), 0, 0, 0 );    // popup on right click
        if ( m )
            m->do_callback( w, m->user_data() );    // if right click rcvd do the callback
        return;
     }
//---------------------PB Handle Method--------------------
     static void pbHandleMenu(Fl_Widget *w, void *v)    //works the same as the PM handlw method
     {
         if(!w || !v) return;
         switch( (intptr_t)v )
         {
             case 1:
             {
                 if(fl_choice("Are you the PB?", NULL, fl_no, fl_yes) == 2)
                     cout << "Code to display all sales here" << endl;
                 else
                 {
                     DisplayBox box(640, 120, 36, 0, 0, 640, 120, "Only the PB can view all sales");
                     box.dispBoxProps();
                 }
                 break;
             }
             case 2:
             {
                 if(fl_choice("Are you the PB?", NULL, fl_no, fl_yes) == 2)
                    cout << "Code to display sales report by associate here" << endl;
                 else
                 {
                     DisplayBox box(640, 120, 36, 0, 0, 640, 120, "Only the PB can view sales reports for all associates");
                     box.dispBoxProps();
                 }
                 break;
             }
             case 3:
             {
                 if(fl_choice("Are you the PB?", NULL, fl_no, fl_yes) == 2)
                    cout << "Code to display options to create prefered customer list here" << endl;
                 else
                 {
                     DisplayBox box(640, 120, 36, 0, 0, 640, 120, "Only the PB can edit/view the prefered customer list.");
                     box.dispBoxProps();
                 }
                 break;
             }
             case 4:
                cout << "Code to display models here" << endl;
                break;
         }
     }
//------------------------PB Callback----------------------
    static void pbCB(Fl_Widget *w, void*)    // Works the same as PM callback
    {
        Fl_Menu_Item rclick_menu[] = {
            { "View sales",  0, pbHandleMenu, (void*)1 },
            { "View sales associate report",  0, pbHandleMenu, (void*)2 },
            { "Create list of prefered customers",  0, pbHandleMenu, (void*)3 },
            { "View Robot Models",  0, pbHandleMenu, (void*)4 },
            { 0 }
        };
        const Fl_Menu_Item *m = rclick_menu->popup( Fl::event_x(), Fl::event_y(), 0, 0, 0 );
        if ( m )
            m->do_callback( w, m->user_data() );
        return;
     }
//---------------------SA Handle Method--------------------
    static void saHandleMenu(Fl_Widget *w, void *v)
    {
        if(!w || !v) return;
        switch( (intptr_t)v )
        {
            case 1:
            {
                if(fl_choice("Are you the SA?", NULL, fl_no, fl_yes) == 2)
                    cout << "code to create order" << endl;
                else
                {
                    DisplayBox box(640, 120, 36, 0, 0, 640, 120, "Only the SA can create orders.");
                    box.dispBoxProps();
                }
                break;
            }
            case 2:
            {
                if(fl_choice("Are you a RRS staff memeber?", NULL, fl_no, fl_yes) == 2)
                    cout << "code to view all orders" << endl;
                else
                {
                    DisplayBox box(640, 120, 36, 0, 0, 640, 120, "Only RRS staff can view all orders");
                    box.dispBoxProps();
                }
                break;
            }
            case 3:
            {
                if(fl_choice("Are you a RRS staff memeber?", NULL, fl_no, fl_yes) == 2)
                {
                    cout << "code to ask for SA name & print SA report" << endl;
                }
                else
                {
                    DisplayBox box(640, 120, 36, 0, 0, 640, 120, "Only RRS staff can view SA sales report");
                    box.dispBoxProps();
                }
                break;
            }
        }
    }
//------------------------SA Callback----------------------
    static void saCB(Fl_Widget *w, void*)
    {
        Fl_Menu_Item rclick_menu[] = {
            { "Create robot order",  0, saHandleMenu, (void*)1 },
            { "View all orders",  0, saHandleMenu, (void*)2 },
            { "View associate sales log",  0, saHandleMenu, (void*)3 },
            { 0 }
        };
        const Fl_Menu_Item *m = rclick_menu->popup( Fl::event_x(), Fl::event_y(), 0, 0, 0 );
        if ( m )
            m->do_callback( w, m->user_data() );
        return;
    }
//---------------------BC Handle Method--------------------
    static void bcHandleMenu(Fl_Widget *w, void *v)
    {
        if(!w || !v) return;
        switch( (intptr_t)v )
        {
            case 1:
                cout << "Code to view robot models" << endl;
                break;
            case 2:
                cout << "Code to view customer orders" << endl;
                break;
            case 3:
                cout << "Code to view customer bill" << endl;
                break;
        }
    }
//------------------------SA Callback----------------------
    static void bcCB(Fl_Widget *w, void*)
    {
        Fl_Menu_Item rclick_menu[] = {
            { "View catologue",  0, bcHandleMenu, (void*)1 },
            { "View orders",  0, bcHandleMenu, (void*)2 },
            { "view bill",  0, bcHandleMenu, (void*)3 },
            { 0 }
        };
        const Fl_Menu_Item *m = rclick_menu->popup( Fl::event_x(), Fl::event_y(), 0, 0, 0 );
        if ( m )
            m->do_callback( w, m->user_data() );
        return;
    }
//------------------------Doc Callback----------------------
    static void docCB(Fl_Widget *w, void*)
    {
        Fl_Window *win = new Fl_Window(650, 480);       // create new win for display
        Fl_Text_Buffer *buff = new Fl_Text_Buffer();    // make a buffer to display text
        Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 650-40, 480-40, "Program Documentation");   // display box
        disp->buffer(buff);     // set buffer
        win->resizable(*disp);  // make window resizable
        win->show();            //show window
        //txt to display in window
        buff->text("This program facilitates the following processes for Robbie Robot Shop: creating robot parts,\ncreating robot models, displaying the parts and models, creating orders, viewing order history\nand customer bill, and generating sales reports. The undo and save featres can be found under\nthe 'file' menubar tab.");
    }
 private:       //button class private vars
 int X, Y, W, H, key;
 char* lab;
 };

/*-------------------------------------------------------SHOP CLASS-------------------------------------------------------*/
int main()
{
    // instance objects to make widgets w/given params
    MakeWin mainWin(1400,600,"Robbie Robot Shop");
    MakeBox mainBox(36,450,100,500,100,"Welcome!\nPlease select user type");
    MakeButtons mainBut1(475,300,140,50,"PM Menu");
    MakeButtons mainBut2(615,300,140,50,"PB Menu");
    MakeButtons mainBut3(755,300,140,50,"SA Menu");
    MakeButtons mainBut4(475,350,140,50,"BC Menu");
    MakeButtons mainBut5(615,350,140,50,"View Documentation");
    
    // gives widgets their properties
    mainWin.winProps();
    mainBox.boxProps();
    mainBut1.butProps(1);
    mainBut2.butProps(2);
    mainBut3.butProps(3);
    mainBut4.butProps(4);
    mainBut5.butProps(5);
    
    // shows the window
    mainWin.showWin();
    return(Fl::run());
}
