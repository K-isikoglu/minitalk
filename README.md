# minitalk
This project is about coding a small data exchange program using UNIX signals.
It enables to send text messages from one process to another.

1. To compile, use `make`.
2. To start the program, first run `./server`. This will run the server and show the PID (process id) of it.
3. Then open another terminal (another process) and run `./client SERVER_PID MESSAGE_TO_SENT`.
   
The sent message will be sent to the server process. The only communication done between the two processes are the two signals: SIGUSR1 and SIGUSR2!
