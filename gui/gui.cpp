#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>

class GUI {
public:
  GUI() {
    window = new Fl_Window(350, 70);
    window->label("GUI");

    initButton = new Fl_Button(10, 10, 100, 25, "Init");
    initButton->callback(initCmd);

    runButton = new Fl_Button(120, 10, 100, 25, "Run");
    runButton->callback(runCmd);

    stopButton = new Fl_Button(230, 10, 100, 25, "Stop");
    stopButton->callback(stopCmd);

    statusButton = new Fl_Button(340, 10, 100, 25, "Status");
    statusButton->callback(statusCmd);

    window->end();
    window->show();
  }

  static void initCmd(Fl_Widget* w, void* data) {
    // initialization code here
  }

  static void runCmd(Fl_Widget* w, void* data) {
    // running code here
  }

  static void stopCmd(Fl_Widget* w, void* data) {
    // stopping code here
  }

  static void statusCmd(Fl_Widget* w, void* data) {
    // status code here
  }

private:
  Fl_Window* window;
  Fl_Button* initButton;
  Fl_Button* runButton;
  Fl_Button* stopButton;
  Fl_Button* statusButton;
};

int main() {
  GUI gui;
  return Fl::run();
}
