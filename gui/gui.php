<?php

class GUI {
  private $window;

  public function __construct() {
    $this->window = new GtkWindow();
    $this->window->set_title("GUI");
    $this->window->set_default_size(350, 70);

    $init_button = new GtkButton("Init");
    $init_button->connect("clicked", array($this, "init_cmd"));

    $run_button = new GtkButton("Run");
    $run_button->connect("clicked", array($this, "run_cmd"));

    $stop_button = new GtkButton("Stop");
    $stop_button->connect("clicked", array($this, "stop_cmd"));

    $status_button = new GtkButton("Status");
    $status_button->connect("clicked", array($this, "status_cmd"));

    $vbox = new GtkVBox();
    $vbox->pack_start($init_button);
    $vbox->pack_start($run_button);
    $vbox->pack_start($stop_button);
    $vbox->pack_start($status_button);

    $this->window->add($vbox);
    $this->window->show_all();
  }

  public function init_cmd() {
    // initialization code here
  }

  public function run_cmd() {
    // running code here
  }

  public function stop_cmd() {
    // stopping code here
  }

  public function status_cmd() {
    // status code here
  }
}

$gui = new GUI();
Gtk::main();
