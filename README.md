# Get_next_line
***
• _This project has been created as part of the 42 curriculum by lheteau. We are the 29th december 2025._

***
### Table of contents
***
1. _Description_
2. _Instructions_
3. _Ressources_

***
## **Description**
***
• get_next_line is a function written to read text from a file descriptor line by line. Each call to get_next_line(int fd) returns the only next line from the given file descriptor, preserving the original order of the text.

A line is defined as a sequence of characters ending with a newline character ```'\n'``` or, in the case of the last line of the file, the end-of-file character ```'\0'```.

To achieve this behavior, the function reads data in fixed-size chunks defined by ```BUFFER_SIZE```. If a complete line is not obtained after a read operation, the remaining data is stored in a persistent buffer (stash) and combined with subsequent reads until a full line is formed.

Any excess data beyond the returned line is preserved in the stash for the next function call. This mechanism ensures efficient memory usage and allows the function to handle lines of arbitrary length while maintaining continuity between successive calls.
***
• The goal of this project is to understand and properly use ```static variables``` in order to preserve data between function calls.

## **Instructions**
***
• To use ft_printf in your own project, include the header: ```"get_next_line.h"```.
***
• Example main :
```
# include <fcntl.h>
# include <stdio.h>
# include "get_next_line.h"

int		main(void)
{
	int	fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);

	line = get_next_line(fd);
	printf("Line 1\n: %s", line);
	free(line);

	line = get_next_line(fd);
	printf("Line 2\n: %s", line);
	free(line);
	
	close (fd);
}
```

## **Ressources**
***
• I used several articles and online resources to support my coding journey. Notably, the video “Understanding get_next_line” by the youTuber nikito was very helpful. I also consulted the websites unstop.com and koor.com, which provided explanations about static variables and the usage of the open and read functions in C.
***
• Artificial Intelligence tools were used to better understand the use and manipulation of pointers with static variables, as well as to clarify misconceptions regarding the difference between ```(*stash)[i]``` and ```*stash[i]```.

They were also helpful in the writing and structuring of this README.
