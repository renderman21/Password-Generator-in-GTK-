#include <iostream>
#include <gtk/gtk.h>
#include <string>

using namespace std; 
 // intialize 
 GtkWidget* window;
 GtkWidget* input, *text_input, *output, *text_output;
 GtkWidget* reset_button, *confirm_button;
 GtkWidget *box;
 

void destroy(GtkWidget *widget, gpointer data)
{
	gtk_main_quit();
}

void clear(GtkWidget *widget, gpointer data)
{
	const gchar* reset = ""; 

	gtk_entry_set_text(GTK_ENTRY(input), reset);
	gtk_entry_set_text(GTK_ENTRY(output), reset);
}

void passwordGen(GtkWidget *widget, gpointer data)
{
	const  gchar* requested_num = gtk_entry_get_text(GTK_ENTRY(input));
	int convert_num = atof(requested_num);
	int limit; 
	int randNum;
	string characters; 
	string newPass = "";
		
	for( limit = 0; convert_num > limit; limit++) 
	{
		randNum = rand() % 93; 
		characters = '!' + randNum; 
		newPass.append(characters);
	}
	
	const gchar * newPass_char = newPass.c_str();
	
	gtk_entry_set_text(GTK_ENTRY(output), newPass_char); 
}

int  main(int argc, char *argv[])
{
	gtk_init(&argc, &argv);

	//constructors
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL); 
	input = gtk_entry_new();
	output = gtk_entry_new(); 
	text_input = gtk_label_new("How many digits do you want?");
	text_output = gtk_label_new("Here's your new password."); 
	box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
	confirm_button = gtk_button_new_with_label("Confirm");
	reset_button =gtk_button_new_with_label("Reset");
	gtk_window_set_title(GTK_WINDOW(window), "Password Generator"); 
	
	//buttons 
	g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL); 
	g_signal_connect(confirm_button, "clicked", G_CALLBACK(passwordGen), input); 
	g_signal_connect(reset_button, "clicked", G_CALLBACK(clear), NULL); 

	//container management
	gtk_box_pack_start(GTK_BOX(box), text_input, FALSE,FALSE, 10);
	gtk_box_pack_start(GTK_BOX(box), input, FALSE,FALSE,10);
	gtk_box_pack_start(GTK_BOX(box), confirm_button, FALSE,FALSE,10);
	gtk_box_pack_start(GTK_BOX(box), reset_button, FALSE,FALSE,10);
	gtk_box_pack_start(GTK_BOX(box), text_output, FALSE,FALSE, 10);
	gtk_box_pack_start(GTK_BOX(box), output, FALSE,FALSE,10); 

	gtk_container_add(GTK_CONTAINER(window),box);
	
	gtk_widget_show_all(window); 

	gtk_main();
	
	return 0;
}
