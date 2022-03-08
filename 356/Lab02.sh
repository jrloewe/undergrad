#!/bin/sh

# (2) Create directory "lab02" in user's home directory.
echo -e "Creating the lab02 directory in the home directory.\n"
mkdir ~/lab02

cd lab02

# (3) Create files "MyNotes.txt", "MeetingNotes.txt", and "PublicNotes.txt" in the lab02 folder.
echo -e "Creating files MyNotes.txt, MeetingNotes.txt, and PublicNotes.txt in the newly created directory.\n"
touch MyNotes.txt MeetingNotes.txt PublicNotes.txt

# (4) List the contents of the directory and the permissions of the files contained within.
echo "List the contents of the lab02 directory and the permissions of its files."
ls -la

# (5) Provide a brief description of the chmod command to the terminal.
echo -e "\nGiving a brief description of the chmod command."
echo -e "The chmod command is used to change the access bits of files on the system. By using a combination of the letters ugoa, where (u) controls access for the user who owns it, (g) is for other users in the file's group, other (o) users not in the files group, or all (a) users. By using +, -, or = in combination with rwxXst (read, write, execute, etc), permissions can be changed for (u), (g), and (o).\n"

# (6) Change the permissions of MyNotes.txt so only the owner has rwx permissions.
echo -e "Changing file permissions for MyNotes.txt so that only the user (u) has read, write, and execute permissions.\n"
chmod u+x,go-rwx MyNotes.txt

# (7) Change the permissions of MeetingNotes.txt so that the owner and group have rw permissions (not x), but all others have no permissions.
echo -e "Changing file permissions for MeetingNotes.txt so that the user (u) and group (g) only have read and write, while all others have no permissions.\n"
chmod ug+rw,o-rwx MeetingNotes.txt

# (8) Change the permissions of PublicNotes.txt so that the owner only has write permissions, the group has write and execute permissions, and everyone else has read-only permission.
echo -e "Changing file permissions for PublicNotes.txt, so that the user (u) has write-only permission, the group (g) has write and execute permissions, and all others (o) have read-only permission."
chmod u-r,g+x-r,o+r PublicNotes.txt

# (9) Print the current working directory to the console.
echo -e "\nPrinting the current working directory to the console."
pwd

# (10) Print the contents of the current working directory to the console, displaying the permissions in the process.
echo -e "\nDisplaying the content of lab02, as well as the permissions of everything contained within."
ls -la

# (11) Move up one directory.
echo -e "\nMoving back up one directory."
cd ..

# (12) Delete the lab02 folder, along with all of its contents.
echo "Now deleting the lab02 folder and its contents."
rm -r ~/lab02
