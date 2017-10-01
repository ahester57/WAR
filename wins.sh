#!/bin/bash

echo Player 1:
cat winners.log | grep -c 1
echo vs.
echo Player 2:
cat winners.log | grep -c 2

