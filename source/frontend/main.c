/* ui_xml.h is generated by running make. It can be targeted specifically with
 * `make source/ui_xml.h` */
#include "data.h"
#include "version.h"
#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>

/* The macros VERSION, NAME, TARGET, AUTHOR and COPYRIGHT are available for this
program to reference information about itself. These macros are defined in
config.mk*/

GtkBuilder *builder;
GtkWidget *window;
GtkWidget *buttonEnc;
GtkWidget *buttonDec;
GtkEntry *inputEnc;
GtkEntry *inputPlain;
GtkLabel *labelStatus;
GtkWidget *inputKey;

int main(int argc, char *argv[]) {
  if (argc >= 2) {
    if (0 == strcmp(argv[1], "--version"))
      version();
  }

  gtk_init(&argc, &argv);

  builder = gtk_builder_new_from_resource(APP_PREFIX "/window_main.glade");
  window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));

  gtk_builder_connect_signals(builder, NULL);
  // g_object_unref(builder);

  window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
  buttonEnc = GTK_WIDGET(gtk_builder_get_object(builder, "buttonEnc"));
  buttonDec = GTK_WIDGET(gtk_builder_get_object(builder, "buttonDec"));
  inputEnc = GTK_ENTRY(gtk_builder_get_object(builder, "inputEnc"));
  inputPlain = GTK_ENTRY(gtk_builder_get_object(builder, "inputPlain"));
  labelStatus = GTK_LABEL(gtk_builder_get_object(builder, "labelStatus"));
  inputKey = GTK_WIDGET(gtk_builder_get_object(builder, "inputKey"));

  gtk_widget_show_all(window);
  gtk_main();
  return 0;
}

gint getKey() {
  return gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(inputKey));
}
const gchar *getPlain() { return gtk_entry_get_text(GTK_ENTRY(inputPlain)); }
const gchar *getEnc() { return gtk_entry_get_text(GTK_ENTRY(inputEnc)); }

char *get_encrypted(char *plain) {
  char command = strcpy("caesar enc ", plain);
  return system(command);
}

void on_buttonEnc_clicked(GtkButton *button) {
  printf("enc clicked\n");
  g_print("key: %d\n", getKey());
  g_print("Plain: %s\n", getPlain());
}

void on_buttonDec_clicked(GtkButton *button) {
  printf("dec clicked\n");
  g_print("key: %d\n", getKey());

  gtk_entry_set_text(GTK_ENTRY(inputPlain), (const gchar *)"Hello World");
}

void on_window_main_destroy() { gtk_main_quit(); }