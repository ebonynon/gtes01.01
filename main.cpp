/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: ebony
 *
 * Created on November 14, 2018, 8:27 AM
 */

#include <iostream>
#include <stdlib.h> 
#include <gtk/gtk.h>

/*
 * 
 */

using namespace std;

GtkWidget *g_but_sum;
GtkWidget *g_but_close;
GtkWidget *g_txt_01;
GtkWidget *g_txt_02;

GtkWidget *cpopup; //form 2
GtkWidget *g_lab_01; //form 2 gtkobj

//gtkobj fun
static void sumbut() 
{
    int itotal;
    const char *num_01;
    const char *num_02;
    const char *total;
    
    cout << "sum"<< endl;
    num_01 = gtk_entry_get_text(GTK_ENTRY(g_txt_01));
    num_02 = gtk_entry_get_text(GTK_ENTRY(g_txt_02));
    
 
    itotal = atoi(num_01) + atoi(num_02);
    cout << itotal<< endl;
    std::string s = std::to_string(itotal);
    total = s.c_str();
    cout << total<< endl;
    gtk_label_set_text(GTK_LABEL(g_lab_01), total);
    gtk_widget_show(cpopup);
}

void closebut()
{
    cout << "close"<< endl;
    gtk_main_quit();
}

void exit()
{
    cout << "ESC"<< endl;
    gtk_main_quit();
}

//main fun
int main(int argc, char** argv) 
{
    GtkBuilder  *abuilder;
    GtkWidget   *cwin;
    //GtkWidget   *cpopup; form 2
    
    //init gtk lib
    gtk_init(&argc , &argv);
    
    //add glade files 
    abuilder = gtk_builder_new();
    gtk_builder_add_from_file(abuilder, "gtes01.glade" , NULL);
    
    //get win widget
    cwin = GTK_WIDGET(gtk_builder_get_object(abuilder, "from"));
    cpopup = GTK_WIDGET(gtk_builder_get_object(abuilder, "popup"));
    gtk_builder_connect_signals(abuilder, NULL);
    
    //get pointers to buttons 
    g_but_sum = GTK_WIDGET(gtk_builder_get_object(abuilder, "but_01"));
    g_but_close = GTK_WIDGET(gtk_builder_get_object(abuilder, "but_02"));
    g_lab_01 = GTK_WIDGET(gtk_builder_get_object(abuilder, "lab_01"));
    g_txt_01 = GTK_WIDGET(gtk_builder_get_object(abuilder, "txt_01"));
    g_txt_02 = GTK_WIDGET(gtk_builder_get_object(abuilder, "txt_02"));
 
    //gtkobj connect with fun
    g_signal_connect(g_but_sum, "clicked", G_CALLBACK(sumbut), NULL);
    g_signal_connect(g_but_close, "clicked", G_CALLBACK(closebut), NULL);
    g_signal_connect(cwin, "destroy", G_CALLBACK(exit), NULL);
  
    g_object_unref(abuilder);
 
    //gtk_widget_show(cpopup);
    gtk_widget_show(cwin);
    
    gtk_main();
 
    return 0;
    
}
