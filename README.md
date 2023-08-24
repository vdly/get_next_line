# Description of the Open()

    int open(const char *pathname, int flags);

- opens a file for reading or writing
- input must specify the absolute or relative path and the name of the file
  in string format or a pointer to it
- flags input argument specifies the attributes that the file must have: 
    > O_RDONLY (reading only)
    > O_WRONLY (writing only)
		> O_RDWR (reading and writing)

- function is defined in <unistd.h>
- flags that define the attributes and mode to open the file are defined in <fcntl.h>

# Description of the Read()

    size_t read(int fd, void *buf, size_t count);

- reads the contents of the open file which is specified by its descriptor in the “fd”
  input argument
- reads and copies the count number of bytes into the buffer that is pointed to by buf
- returns the number of bytes read:
		> 0 means that the file is read to the end
		> -1 means that an error occurs
  
- function is declared in <unistd.h>
