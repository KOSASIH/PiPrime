import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class GUI {
  private JFrame window;

  public GUI() {
    window = new JFrame("GUI");
    window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    window.setSize(350, 70);

    JButton initButton = new JButton("Init");
    initButton.addActionListener(new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent e) {
        // initialization code here
      }
    });

    JButton runButton = new JButton("Run");
    runButton.addActionListener(new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent e) {
        // running code here
      }
    });

    JButton stopButton = new JButton("Stop");
    stopButton.addActionListener(new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent e) {
        // stopping code here
      }
    });

    JButton statusButton = new JButton("Status");
    statusButton.addActionListener(new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent e) {
        // status code here
      }
    });

    JPanel panel = new JPanel();
    panel.add(initButton);
    panel.add(runButton);
    panel.add(stopButton);
    panel.add(statusButton);

    window.getContentPane().add(panel);
    window.setVisible(true);
  }

  public static void main(String[] args) {
    new GUI();
  }
}
