import java.util.Scanner;

public class Cli {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.print("Enter command: ");
    String cmd = scanner.nextLine();
    switch (cmd) {
      case "init":
        initCmd();
        break;
      case "run":
        runCmd();
        break;
      case "stop":
        stopCmd();
        break;
      case "status":
        statusCmd();
        break;
      default:
        System.out.println("Unknown command: " + cmd);
    }
  }

  public static void initCmd() {
    System.out.println("Initializing...");
    // initialization code here
  }

  public static void runCmd() {
    System.out.println("Running...");
    // running code here
  }

  public static void stopCmd() {
    System.out.println("Stopping...");
    // stopping code here
  }

  public static void statusCmd() {
    System.out.println("Status:");
    // status code here
  }

  public static String readLine(String prompt) {
    System.out.print(prompt);
    return new Scanner(System.in).nextLine();
  }

  public static int readInt(String prompt) {
    return Integer.parseInt(readLine(prompt));
  }

  public static float readFloat(String prompt) {
    return Float.parseFloat(readLine(prompt));
  }
}
