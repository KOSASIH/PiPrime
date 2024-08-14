import Foundation

func main() {
  let cmd = readLine(strippingNewline: true)
  switch cmd {
  case "init":
    initCmd()
  case "run":
    runCmd()
  case "stop":
    stopCmd()
  case "status":
    statusCmd()
  default:
    print("Unknown command: \(cmd)")
  }
}

func initCmd() {
  print("Initializing...")
  // initialization code here
}

func runCmd() {
  print("Running...")
  // running code here
}

func stopCmd() {
  print("Stopping...")
  // stopping code here
}

func statusCmd() {
  print("Status:")
  // status code here
}

func readLine(_ prompt: String = "") -> String? {
  print(prompt, terminator: "")
  return readLine()
}

func readInt(_ prompt: String = "") -> Int? {
  guard let line = readLine(prompt) else { return nil }
  return Int(line)
}

func readFloat(_ prompt: String = "") -> Float? {
  guard let line = readLine(prompt) else { return nil }
  return Float(line)
}

main()
