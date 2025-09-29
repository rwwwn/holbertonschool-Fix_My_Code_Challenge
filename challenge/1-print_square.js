#!/usr/bin/env node
// Print an N x N square of '#'
const size = parseInt(process.argv[2], 10);
if (!Number.isFinite(size) || size < 1) {
  process.exit(0);
}
const row = '#'.repeat(size);
for (let i = 0; i < size; i += 1) {
  console.log(row);
}
