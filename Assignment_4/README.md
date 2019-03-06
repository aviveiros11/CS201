CS201 Spring 2019 <br />
Assignment #4: Processes and Shared Memory <br />
Due Friday, Mar 8th, at 11:59pm <br />
15 points <br />

Here's what the program should do:
⦁ the main() should create a 32-byte shared-memory block
⦁ the parent should fork a child process
⦁ the parent should attach to the shared-memory block
⦁ in a for-loop, the parent should write each word from the array to the shared-memory block and then
usleep(500000) and then read a string from the shared memory and print it out
⦁ the parent should wait for the child to exit
⦁ the child should attach to the shared-memory block
⦁ in a for-loop, the child should read a string from the shared memory, then convert it to upper case, and
then write the converted string back to the shared memory and then usleep(1000000)
⦁ the child then exits and the parent exits
