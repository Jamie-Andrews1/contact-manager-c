#!/bin/bash

# 1. Colors for terminal output
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

echo -e "${GREEN}Starting Functional Tests...${NC}"

# 2. Compile the project
gcc ../main.c ../functions.c -o contacts_test
if [ $? -ne 0 ]; then
    echo -e "${RED}Compilation Failed!${NC}"
    exit 1
fi

# 3. Create a clean test environment
rm -f ~/Documents/contacts.csv
touch ~/Documents/contacts.csv
chmod +x ~/Documents/contacts.csv

./contacts_test add Archie 555-0123 arch@linux.org

# 5. Verify the result using 'grep'
if grep -q "Archie" ~/Documents/contacts.csv; then
    echo -e "${GREEN}[PASS]${NC} Contact successfully saved to CSV."
else
    echo -e "${RED}[FAIL]${NC} Contact was NOT found in the file."
    exit 1
fi

./contacts_test delete Archie

if grep -q "Archie" ~/Documents/contacts.csv; then
    echo -e "${RED}[FAIL]${NC} Contact was NOT removed successfully."
    exit 1
else
    echo -e "${GREEN}[PASS]${NC} Contact successfully removed from CSV."
fi

echo -e "${GREEN}All Bash tests passed!${NC}"

# clean up
rm ~/Documents/contacts.csv