#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

echo -e "${GREEN}Starting Functional Tests...${NC}"

gcc tests.c ../functions.c -o contacts_test
if [ $? -ne 0 ]; then
    echo -e "${RED}Compilation Failed!${NC}"
    exit 1
fi

./contacts_test