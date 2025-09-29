#!/usr/bin/env node
// Print an N x N square of '#'
const arg = process.argv[2];
const n = Number.parseInt(arg, 10);

if (!Number.isFinite(n) || n < 1) {
  process.exit(0);
}

const row = '#'.repeat(n);
for (let i = 0; i < n; i += 1) {
  console.log(row);
}
