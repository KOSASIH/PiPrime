#include <gtk/gtk.h>

void initCmd(GtkWidget* widget, gpointer data) {
  // initialization code here
}

void runCmd(GtkWidget* widget, gpointer data) {
  // running code here
}

void stopCmd(GtkWidget* widget, gpointer data) {
  // stopping code here
}

void statusCmd(GtkWidget* widget, gpointer data) {
  // status code here
}

int main(int argc, char* argv[]) {
  gtk_init(&argc, &argv);

  GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "GUI");
  gtk_window_set_default_size(GTK_WINDOW(window), 350, 70);

  GtkWidget* initButton = gtk_button_new_with_label("Init");
  gtk_button_set_label(GTK_BUTTON(initButton), "Init");
  gtk_container_add(GTK_CONTAINER(window), initButton);
  gtk_signal_connect(GTK_OBJECT(initButton), "clicked", GTK_SIGNAL_FUNC(initCmd), NULL);

  GtkWidget* runButton = gtk_button_new_with_label("Run");
  gtk_button_set_label(GTK_BUTTON(runButton), "Run");
  gtk_container_add(GTK_CONTAINER(window), runButton);
  gtk_signal_connect(GTK_OBJECT(runButton), "clicked", GTK_SIGNAL_FUNC(runCmd), NULL);

  GtkWidget* stopButton = gtk_button_new_with_label("Stop");
  gtk_button_set_label(GTK_BUTTON(stopButton), "Stop");
  gtk_container_add(GTK_CONTAINER(window), stopButton);
  gtk_signal_connect(GTK_OBJECT(stopButton), "clicked", GTK_SIGNAL_FUNC(stopCmd), NULL);

  GtkWidget* statusButton = gtk_button_new_with_label("Status");
  gtk_button_set_label(GTK_BUTTON(statusButton), "Status");
  gtk_container_add(GTK_CONTAINER(window), statusButton);
  gtk_signal_connect(GTK_OBJECT(statusButton), "clicked", GTK_SIGNAL_FUNC(statusCmd), NULL);

  gtk_widget_show_all(window);
  gtk_main();
  return 0;
}
