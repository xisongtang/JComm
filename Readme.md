JComm
=====

**API for java serial port communication on windows**  


- There is only one JComm class, so it is very easy to use. The file main.java is a demo for you.
- For some reason, my mingw cannot compile the .dll in 32-bit mode, but it cannot be a problem, you can easily compile it by using the command in makefile, or just use command `make JComm32`(`make JComm64` for 64-bit windows).
- The .dll in JCommdll is 64-bit.