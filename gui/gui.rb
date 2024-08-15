require 'gtk2'

class GUI
  def initialize
    @window = Gtk::Window.new
    @window.title = "GUI"
    @window.default_size = 350, 70

    @init_button = Gtk::Button.new("Init")
    @init_button.signal_connect("clicked") { init_cmd }

    @run_button = Gtk::Button.new("Run")
    @run_button.signal_connect("clicked") { run_cmd }

    @stop_button = Gtk::Button.new("Stop")
    @stop_button.signal_connect("clicked") { stop_cmd }

    @status_button = Gtk::Button.new("Status")
    @status_button.signal_connect("clicked") { status_cmd }

    @vbox = Gtk::VBox.new
    @vbox.pack_start(@init_button)
    @vbox.pack_start(@run_button)
    @vbox.pack_start(@stop_button)
    @vbox.pack_start(@status_button)

    @window.add(@vbox)
    @window.show_all
  end

  def init_cmd
    # initialization code here
  end

  def run_cmd
    # running code here
  end

  def stop_cmd
    # stopping code here
  end

  def status_cmd
    # status code here
  end
end

gui = GUI.new
Gtk.main
