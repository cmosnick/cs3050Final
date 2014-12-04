The purpose of this project is to read in a maze representation (as shown in maze.txt)
and to traverse it from start to end.  Aim is to find the shortest contiguous path.

To run:
	-type "make"
	-type "./main <file_with_maze.txt>"

By this time, each character is scanned into a 2D array.
From that array, a "Grid" object is created for each element in that array.
The Grid objects' neighbors are assigned to its left, right, front, and back pointers.
The pointer to the Start Grid object is returned to main as head.