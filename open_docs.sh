#!/bin/bash

FILE="docs/html/index.html"

if [[ "$OSTYPE" == "linux-gnu"* ]]; then
    # Linux
    xdg-open $FILE &
elif [[ "$OSTYPE" == "darwin"* ]]; then
    # macOS
    open $FILE &
elif [[ "$OSTYPE" == "cygwin" ]]; then
    # Cygwin
    cygstart $FILE &
elif [[ "$OSTYPE" == "msys" ]]; then
    # Git Bash/MSYS2
    start $FILE &
elif [[ "$OSTYPE" == "win32" ]]; then
    # Windows
    start $FILE &
else
    echo "Unsupported OS: $OSTYPE"
fi