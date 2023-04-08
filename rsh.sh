#!/bin/bash

# Regular expression for validating NUIDs
nuid_regex='^00[0-9]{7}$'

# Regular expression for validating Northeastern student emails
email_regex='^[a-z]+(\.[a-z][a-z0-9]*)*@northeastern\.edu$'

# Validate the first argument (NUID)
if ! [[ $1 =~ $nuid_regex ]]; then
    echo "Error: Invalid NUID. NUIDs should start with '00' and have 9 digits." >&2
    exit 1
fi

# Validate the second argument (email)
if ! [[ $2 =~ $email_regex ]]; then
    echo "Error: Invalid email. Northeastern student emails should follow the pattern 'firstname.lastname@northeastern.edu'." >&2
    exit 1
fi

# Extract the NUID from the first argument
nuid=$((10#$1))

# Calculate sc1 and generate the program codes
sc1=$(( $nuid % 19))
echo -e "Thanks, your email is: $2, \nand your 9 programs to work with are:"
for (( c=1; c<10; c++ ))
do
        increment=$(( $c))
        code=$(($(($sc1 + $increment)) % 19))
        code=$(printf %02d $code)
        echo "$c. codeN11$code.c"
done

# Calculate sc2 and print the Part 4 Program
sc2=$(( $nuid % 3))
echo -e "Your Part 4 Program is:"
if [[ $sc2 -eq 0 ]]
then
    echo "Buffer Overflow"
fi
if [[ $sc2 -eq 1 ]]
then
    echo "Undefined Behavior"
fi
if [[ $sc2 -eq 2 ]]
then
    echo "Memory Leak"
fi
