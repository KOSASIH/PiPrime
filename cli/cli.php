<?php

function main() {
  $cmd = trim(fgets(STDIN));
  switch ($cmd) {
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
      echo "Unknown command: $cmd\n";
  }
}

function initCmd() {
  echo "Initializing...\n";
  // initialization code here
}

function runCmd() {
  echo "Running...\n";
  // running code here
}

function stopCmd() {
  echo "Stopping...\n";
  // stopping code here
}

function statusCmd() {
  echo "Status:\n";
  // status code here
}

function readLine($prompt) {
  echo $prompt;
  return trim(fgets(STDIN));
}

function readInt($prompt) {
  return intval(readLine($prompt));
}

function readFloat($prompt) {
  return floatval(readLine($prompt));
}

main();

?>
