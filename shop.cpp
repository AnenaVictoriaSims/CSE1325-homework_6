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
#include <FL/Fl_Input.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Float_Input.H>
#include <FL/Fl_Color_Chooser.H>
#include <fstream>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

/*-------------------GLOBAL VARIABLES--------------------*/

// Used by Main and MakeParts for user input
int gloArgc;
char **gloArgv;
// Used by MakeParts for txt input boxes
Fl_Input* prtName;
Fl_Int_Input* prtNumb;
Fl_Input* prtType;
Fl_Float_Input* weight;
Fl_Float_Input* cost;
Fl_Input* descr;

/*----------------------MakeWin CLASS--------------------*/

// Generic class to make new windows
class MakeWin
{
public:
    // Constructor w/no prams, for derived classes
    MakeWin(){};
    // Constructor w/method initialization for window
    MakeWin(int x,int y,const char* L): X(x),Y(y),lab(L){}
    void winProps()
    {
        win = new Fl_Window(X, Y, lab);     //make window
        win->color( FL_WHITE );             //background color white
    }
    void showWin()
    {
        win->end();     //no more additions
        win->show();    //show window
    }
private:
    int X, Y;
    const char* lab;
    Fl_Window *win;
};

/*----------------------MakeBox CLASS--------------------*/
// Main window display box thats on top of buttons
class MakeBox
{
public:
    MakeBox(){};
    MakeBox(int s, int x, int y, int w, int h, const char* L):S(s),X(x),Y(y),W(w),H(h),lab(L){}
    void boxProps(){
        Fl_Box *box = new Fl_Box(X,Y,W,H,lab);
        box->box(FL_RSHADOW_BOX);
        box->align(FL_ALIGN_WRAP);
        box->labelfont(FL_BOLD);
        box->labelsize(S);
        box->labeltype(FL_SHADOW_LABEL);
    }
private:
    int S, X, Y, W, H;
    const char* lab;
};
/*---------------------DisplayBox CLASS------------------*/
class DisplayBox{
public:
    DisplayBox(){};
    DisplayBox(int wx, int wy, int s, int x, int y, int w, int h, const char* L):wX(wx),wY(wy),S(s),X(x),Y(y),W(w),H(h),lab(L){}
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
    const char* lab;
};
/*-----------------------------------------------------MakeParts CLASS----------------------------------------------------*/
class MakeParts
{
private:
    // The widgets
    
public:
    MakeParts(){}
    MakeParts(int x,int y,int w,int h)
    {
        // Setup the colours
        Fl::args(gloArgc, gloArgv);
        Fl::get_system_colors();
        // Create the window
        Fl_Window *window = new Fl_Window(400, 350);
        int X = x, Y = y, W = w, H = h;
        // Create text boxes
        prtName = new Fl_Input(x, y, w, h, "Part Name:");
        prtName->tooltip("Name must be < 35 chars");
        y += 35;
        prtNumb = new Fl_Int_Input(x,y,w,h,"Part Number:");
        prtNumb->tooltip("Number must be < 35 chars");
        y+= 35;
        prtType = new Fl_Input(x, y, w, h, "Part Type:");
        prtType->tooltip("head,arms,legs,torso,loco");
        y+= 35;
        weight = new Fl_Float_Input(x,y,w,h,"Part Weight(lbs):");
        weight->tooltip("Enter number only");
        y+= 35;
        cost = new Fl_Float_Input(x,y,w,h,"Part Cost$ :");
        cost->tooltip("Enter value only, no $ ");
        y+= 35;
        descr = new Fl_Input(x, y, w, h, "Part Description:");
        descr->tooltip("Description must be < 90 chars");
        y += 35;
        Fl_Button* sub = new Fl_Button(x,y,200,h,"Submit");
        
        sub->callback(statCB);
        window->end();
        window->show(gloArgc, gloArgv);
    }
    void inputCB(Fl_Widget* w, void* p)
    {
        cout << "Part name value is: " << prtName->value() << endl;
        cout << "Part number value is: " << prtNumb->value() << endl;
        cout << "Part type value is: " << prtType->value() << endl;
        cout << "Part weight value is: " << weight->value() << endl;
        cout << "Part cost value is: " << cost->value() << endl;
        cout << "Part description value is: " << descr->value() << endl;
    }
    static void statCB(Fl_Widget* w, void* p)
    {
        MakeParts *o = (MakeParts*)p;
        o->inputCB(w,p);
    }
};
/*----------------------------------------------------MakeButtons CLASS---------------------------------------------------*/
class MakeButtons : DisplayBox, MakeParts{
 public:
//--------------------------Constructor--------------------
    MakeButtons(int x,int y,int w,int h,const char* L):X(x),Y(y),W(w),H(h),lab(L){}
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
             case 6:
                 but->callback( catCB );
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
                {
                    MakeParts prts(150,10,200,30);
                }
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
            {"Create robot order",0,saHandleMenu,(void*)1},
            {"View your sales log",0,saHandleMenu,(void*)2},
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
                cout << "Code to view customer orders" << endl;
                break;
            case 2:
                cout << "Code to view customer bill" << endl;
                break;
        }
    }
//------------------------BC Callback----------------------
    static void bcCB(Fl_Widget *w, void*)
    {
        Fl_Menu_Item rclick_menu[] = {
            { "View orders",  0, bcHandleMenu, (void*)1 },
            { "view bill",  0, bcHandleMenu, (void*)2 },
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
    //------------------------cat Callback----------------------
    static void catCB(Fl_Widget *w, void*)
    {
        Fl_Window *win = new Fl_Window(650, 480);       // create new win for display
        Fl_Text_Buffer *buff = new Fl_Text_Buffer();    // make a buffer to display text
        Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 650-40, 480-40, "Robot Model Catalogue");   // display box
        disp->buffer(buff);     // set buffer
        win->resizable(*disp);  // make window resizable
        win->show();            //show window
        //txt to display in window
        buff->text("This is where the robot catalogue will be printed.");
    }
 private:       //button class private vars
 int X, Y, W, H, key;
 const char* lab;
 };
/*-------------------------------------------------------SHOP CLASS-------------------------------------------------------*/
int main(int argc,char **argv)
{
    gloArgc = argc;
    gloArgv = argv;
    const char *lab1 = "Robbie Robot Shop";
    const char *lab2 = "Welcome to the Robbie Robot Shop!\n\nPlease select a user type";
    const char *lab3 = "Project Manager Menu";
    const char *lab4 = "Shop Manager Menu";
    const char *lab5 = "Sales Associate Menu";
    const char *lab6 = "Customer Menu";
    const char *lab7 = "View Documentation";
    const char *lab8 = "View Robot Catalogue";
    
    // instance objects to make widgets w/given params
    MakeWin mainWin(1400,600,lab1);
    MakeBox mainBox(36,450,100,500,200,lab2);
    MakeButtons mainBut1(470,350,155,50,lab3);
    MakeButtons mainBut2(625,350,155,50,lab4);
    MakeButtons mainBut3(780,350,155,50,lab5);
    MakeButtons mainBut4(470,400,155,50,lab6);
    MakeButtons mainBut5(625,400,155,50,lab7);
    MakeButtons mainBut6(780,400,155,50,lab8);
    
    // gives widgets their properties
    mainWin.winProps();
    mainBox.boxProps();
    mainBut1.butProps(1);
    mainBut2.butProps(2);
    mainBut3.butProps(3);
    mainBut4.butProps(4);
    mainBut5.butProps(5);
    mainBut6.butProps(6);
    
    // shows the window
    mainWin.showWin();
    //gloArgc = argc;
    //gloArgv = argv;
    return(Fl::run());
}
