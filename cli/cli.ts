import * as readline from 'readline';

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

function main() {
  rl.question('Enter command: ', (cmd) => {
    switch (cmd) {
      case 'init':
        initCmd();
        break;
      case 'run':
        runCmd();
        break;
      case 'stop':
        stopCmd();
        break;
      case 'status':
        statusCmd();
        break;
      default:
        console.log(`Unknown command: ${cmd}`);
    }
  });
}

function initCmd() {
  console.log('Initializing...');
  // initialization code here
}

function runCmd() {
  console.log('Running...');
  // running code here
}

function stopCmd() {
  console.log('Stopping...');
  // stopping code here
}

function statusCmd() {
  console.log('Status:');
  // status code here
}

function readLine(prompt: string): Promise<string> {
  return new Promise((resolve) => {
    rl.question(prompt, (line) => {
      resolve(line);
    });
  });
}

function readInt(prompt: string): Promise<number> {
  return readLine(prompt).then((line) => parseInt(line, 10));
}

function readFloat(prompt: string): Promise<number> {
  return readLine(prompt).then((line) => parseFloat(line));
}

main();
