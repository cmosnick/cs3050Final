The purpose of this project is to read in a maze representation (as shown in maze.txt)
and to traverse it from start to end.  Aim is to find the shortest contiguous path.

To run:
	-type "make".  Enter.

	-type "./main <file_with_maze.txt>". Enter.

The application should print the originla maze scanned in, untraversed.
Then, it will traverse the maze recursively and print out the length of the shortest path.
Last, the application will print out all combinations of shortest paths to the end.


The algorithm will take into account unknown values when scanning into the maze, 
and will let the user know when a path was not found.