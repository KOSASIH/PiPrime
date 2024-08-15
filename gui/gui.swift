import Cocoa

class GUI: NSObject {
  let window: NSWindow
  let initButton: NSButton
  let runButton: NSButton
  let stopButton: NSButton
  let statusButton: NSButton

  override init() {
    window = NSWindow(contentRect: NSMakeRect(100, 100, 350, 70), styleMask: [.titled, .closable], backing: .buffered, defer: false)
    window.title = "GUI"

    initButton = NSButton(title: "Init", target: self, action: #selector(initCmd))
    runButton = NSButton(title: "Run", target: self, action: #selector(runCmd))
    stopButton = NSButton(title: "Stop", target: self, action: #selector(stopCmd))
    statusButton = NSButton(title: "Status", target: self, action: #selector(statusCmd))

    let vbox = NSView(frame: NSMakeRect(0, 0, 350, 70))
    vbox.addSubview(initButton)
    vbox.addSubview(runButton)
    vbox.addSubview(stopButton)
    vbox.addSubview(statusButton)

    window.contentView = vbox
    window.makeKeyAndOrderFront(nil)
  }

  @objc func initCmd() {
    // initialization code here
  }

  @objc func runCmd() {
    // running code here
  }

  @objc func stopCmd() {
    // stopping code here
  }

  @objc func statusCmd() {
    // status code here
  }
}

let gui = GUI()
NSApplication.shared.run()
