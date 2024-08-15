import tkinter as tk

class GUI:
    def __init__(self):
        self.window = tk.Tk()
        self.window.title("GUI")

        self.init_button = tk.Button(self.window, text="Init", command=self.init_cmd)
        self.init_button.pack()

        self.run_button = tk.Button(self.window, text="Run", command=self.run_cmd)
        self.run_button.pack()

        self.stop_button = tk.Button(self.window, text="Stop", command=self.stop_cmd)
        self.stop_button.pack()

        self.status_button = tk.Button(self.window, text="Status", command=self.status_cmd)
        self.status_button.pack()

    def init_cmd(self):
        # initialization code here
        pass

    def run_cmd(self):
        # running code here
        pass

    def stop_cmd(self):
        # stopping code here
        pass

    def status_cmd(self):
        # status code here
        pass

    def run(self):
        self.window.mainloop()

if __name__ == "__main__":
    gui = GUI()
    gui.run()
