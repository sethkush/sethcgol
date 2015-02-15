# sethcgol
This is a simple Conway's Game Of Life program written in C.  It is my first real C project, and is mostly just an experiment to explore what can be done in the language.  It is currently functional, but incomplete.  Any constructive criticism or help is more than welcome; I'm still learning.  The controls during the simulation are currently 'p' to pause and 'q' to quit.

Todo:

1. Write a proper Makefile.

2. Change allocation of field array to use just one malloc() call.

3. Create a border around the field and have it fit to the terminal.

4. Allow editing while paused using arrow keys and space bar.

5. Take command-line arguments for initial setup.

6. Create a loading and saving system

7. Separate the UI from the backend to allow easier integration with a graphical frontend.
