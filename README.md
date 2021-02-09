[![jaeskim's 42Project Score](https://badge42.herokuapp.com/api/project/mrubio/42cursus-get_next_line)](https://github.com/JaeSeoKim/badge42)

## Objetive

Create a function that can read an entire file, line by line.

## Use

Calling function "get_next_line" in a loop, will allow you read an entire file until EOF ('\0').

Should works correctly if read from file or stdin.

The progran should be compile with flag `-D BUFFEE_SIZE=XX**` Being "XX" a number used as buffer size to read each loop. As default  `BUFFER_SIZE=32`

**Bonus:**

must be able to handle several file descriptors.
