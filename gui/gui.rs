use gtk::prelude::*;

fn main() {
    gtk::prelude::init();

    let window = gtk::Window::new(gtk::WindowType::Toplevel);
    window.set_title("GUI");
    window.set_default_size(350, 70);

    let init_button = gtk::Button::with_label("Init");
    init_button.connect_clicked(move |_| {
        // initialization code here
    });

    let run_button = gtk::Button::with_label("Run");
    run_button.connect_clicked(move |_| {
        // running code here
    });

    let stop_button = gtk::Button::with_label("Stop");
    stop_button.connect_clicked(move |_| {
        // stopping code here
    });

    let status_button = gtk::Button::with_label("Status");
    status_button.connect_clicked(move |_| {
        // status code here
    });

    let vbox = gtk::Box::new(gtk::Orientation::Vertical, 0);
    vbox.pack_start(&init_button, true, true, 0);
    vbox.pack_start(&run_button, true, true, 0);
    vbox.pack_start(&stop_button, true, true, 0);
    vbox.pack_start(&status_button, true, true, 0);

    window.add(&vbox);
    window.show_all();

    gtk::main();
}
