import * as electron from 'electron';

class GUI {
  private window: electron.BrowserWindow;

  constructor() {
    this.window = new electron.BrowserWindow({
      width: 350,
      height: 70,
      title: 'GUI'
    });

    const initButton = document.createElement('button');
    initButton.textContent = 'Init';
    initButton.addEventListener('click', () => {
      // initialization code here
    });

    const runButton = document.createElement('button');
    runButton.textContent = 'Run';
    runButton.addEventListener('click', () => {
      // running code here
    });

    const stopButton = document.createElement('button');
    stopButton.textContent = 'Stop';
    stopButton.addEventListener('click', () => {
      // stopping code here
    });

    const statusButton = document.createElement('button');
    statusButton.textContent = 'Status';
    statusButton.addEventListener('click', () => {
      // status code here
    });

    const container = document.createElement('div');
    container.appendChild(initButton);
    container.appendChild(runButton);
    container.appendChild(stopButton);
    container.appendChild(statusButton);

    this.window.loadURL(`file://${__dirname}/index.html`);
    this.window.webContents.send('gui', container);
  }
}

const gui = new GUI();
electron.app.on('ready', () => {
  gui.window.show();
});
