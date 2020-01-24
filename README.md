# pathfinder
Pathfinder &amp;&amp; libmx

A program that finds all the shortest paths between all the islands,
using information about the bridges that connect them. So, the program:
1. reads data from the file which name is given as command-line argument;
2. finds all shortest paths between every combination of two islands.
Any pair of islands always has a path between them;
3. prints path using the FIFO(first) rule for the islands on the standard output.

# File input data:

• the first line in the file is a number of islands;

• remaining lines are describing distance between two islands, one per line. Each line
consists of two islands and bridge length between them in the format:

island1-island2,length_of_bridge .

– Island names contain only alphabetic characters and cannot be empty.

– Length contains only digits.

– The sum of the lengths of all bridges in the file does not exceed MAX_INT .

# Output
Output consist of information blocks about certain shortest path. Every block contains:
1. "========================================" upper boundary that consist of 40 '='
characters;
2. Path: <island1> -> <island2> - shows initial point and final destination;
3. Route: <island1> -> <all_islands_between> -> <island2> - shows the full route
between two islands;
4. Distance: <length1> + <length2> = <sum> - shows the distance between every island in
the route as well as their sum that indicates distance to the final destination;
5. "========================================" bottom boundary that consist of 40 '='
characters.

# Error handling. 
Prints on the standard error stream:

• "usage: ./pathfinder [filename]" , if there are an invalid number of command-line
arguments;

• "error: file [filename] does not exist" , if the file does not exist;

• "error: file [filename] is empty" , if the file is empty;

• "error: line 1 is not valid" , if the first line contains something other than digits;

• "error: line [line_number] is not valid" , if one of the remaining lines does not match
the format above;

• "error: invalid number of islands" , if the number received on the first line does not
coincide with the number of islands.

# Libmx
The project also consists "libmx" library, that have a lot of useful functions in it. Names of functions quite mnemonic, so you can figure out what function does by reading it's name. A bit later I'll make more detailed info about this library.
