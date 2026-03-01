# Contact Manager CLI

A lightweight, terminal-based contact management system written in C. Designed for performance and simplicity on Linux systems.

## 🚀 Features

- Persistent Storage: Saves all data to a local contacts.csv.

- Fast Search: Quick lookup by name or email.

- Modular Design: Clean separation between the UI (main.c) and logic (functions.c).

- Safe Memory: Uses custom struct management to prevent memory leaks.

## 🛠️ Requirements

- Compiler: gcc (Base-devel package on Arch)

- Shell: bash

- Optional: gdb for debugging

## 🏗️ Installation & Building

Since I use a custom build script, you don't need to worry about complex gcc flags.

### 1. Clone the repository:

```bash
git clone https://github.com/Jamie-Andrews1/contact-manager-c
cd contact-manager-c-main
```

### 2. Make the build script executable:

```Bash
chmod +x build.sh
```

### 3. Compile:

```Bash
./build.sh
```

## 📂 Project Structure

- main.c - The entry point and user menu loop.

- functions.c - Implementation of CRUD operations.

- functions.h - Header file containing structs and prototypes.

- build.sh - Automation script for compilation and environment setup.
