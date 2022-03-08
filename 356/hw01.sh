#!/bin/sh
# (4) Create a directory named temp in the home directory.
echo -e "Creating directory /temp in home directory.\n"
mkdir ~/temp

# (5 & 6) Create a file, 5.out, containing a summary of the df command, as well as a file, 6.out, containing only the usernames beginning with j (first initial) from passwd.txt.
echo -e "Summarizing df command in 5.out and writing all usernames starting with j to 6.out.\n"
echo -e "The df command displays available disk space on the filesystem that contains each file name argument. With no given file name, it will display the available space on all currently mounted filesystems. By default, this information is displayed in 1K blocks; if the environment variable POSIXLY_CORRECT is used, 512-byte blocks are displayed instead.\n\nIf the absolute file name of a disk node is used as an argument, it will display the available space on that file system, so long as the file system is mounted." > temp/5.out | grep '^j' passwd.txt > temp/6.out

# (7) Count the number of Unix logins with the letter "d" (last initial) and write to file 7.out.
echo -e "Counting the number of users beginning with letter d and writing to 7.out.\n"
grep '^d' passwd.txt | wc -l > temp/7.out

# (8) Write the output of the env command to file 8.out, making sure the list is sorted alphabetically.
echo -e "Sorting the output of the env command by dictionary order and writing to 8.out.\n"
env | sort -d > temp/8.out

# (9) Write a program to convert miles to kilometers, making sure to output the converstion to file 9.out.
echo "Enter number of miles to convert to kilometers: "
read mi

if [ $mi -lt 1 ]
then
	echo "You must enter a number greater than 0."
fi

km=`echo $mi \* 1.61 | bc`

echo -e "Miles you entered:		$mi\n$mi miles in kilometers:		$km\n"

echo "Converted $mi miles to $km kilometers." > temp/9.out

# (10) Concatenate the contents of 6-9.out to a new file, jdrakos_hw01.txt.
echo "Combining the contents of files 6-9.out to jdrakos_hw01.txt."
cat temp/{6..9}.out > jdrakos_hw01.txt
