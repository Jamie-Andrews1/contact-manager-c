#!/bin/bash

CC="gcc"
CFLAGS="-Wall -Wextra -std=c99"
TARGET="contact_manager"
SRCS="./main.c ./functions.c"

echo "🚀 Starting build for $TARGET..."

for file in $SRCS; do
    if [ ! -f "$file" ]; then
        echo "❌ Error: $file not found!"
        exit 1
    fi
done

$CC $CFLAGS $SRCS -o $TARGET

if [ $? -eq 0 ]; then
    echo "✅ Build successful!"

    if [ ! -f "~/Documents/contacts.csv" ]; then
        touch ~/Documents/contacts.csv
        chmod +x ~/Documents/contacts.csv
        echo "📝 Created empty contacts.csv"
    fi

    echo "💻 Run your tool with: ./$TARGET"
else
    echo "💥 Build failed. Check the errors above."
    exit 1
fi