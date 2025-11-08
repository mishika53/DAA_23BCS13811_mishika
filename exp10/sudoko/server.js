// server.js
const express = require('express');
const { spawn } = require('child_process');
const app = express();
const port = 3000;

app.use(express.static('.'));
app.use(express.text());

app.post('/solve', (req, res) => {
  const process = spawn('sudoku_solver.exe');

  process.stdin.write(req.body);
  process.stdin.end();

  let output = '';
  process.stdout.on('data', data => {
    output += data.toString();
  });

  process.stderr.on('data', data => {
    console.error(`stderr: ${data}`);
  });

  process.on('close', code => {
    res.send(output);
  });
});

app.listen(port, () => {
  console.log(`Server running at http://localhost:${port}`);
});
