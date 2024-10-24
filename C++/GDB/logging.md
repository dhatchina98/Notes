# Logging
- what you see in the terminal we are going to logging that in file.

```c++
(gdb) set logging enabled on

// now logs are stored `gdb.txt` file.
```

- if you need logs to be stored in different file, then

```c++
(gdb) set logging file myfile.txt

(gdb) set logging enabled on

// now logs are stored in given file.
```

- everytime when u running program logs should be overwrite the same file means,
  
```
(gdb) set logging overwrite on
```
- to see selected logging options

```c++
(gdb) show logging

// output
logging enabled : on
logging file :  the current logfile is "myfile.txt"
logging overwrite : on
...
...
```