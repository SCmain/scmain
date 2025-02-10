# scmain
## Summary of source files

### `.c` and `.h` files
Each file has a well-defined function in the SCMAIN application:

- **scmain.c** : Main entry point of the application, management of main loops and interactions with modules.
- **sck.h** : Global definitions and constants of the project.
- **scstat.h / scstat.c** : Management of system status and errors.
- **ro.h / ro.c** : Interface and control of the robot mechanism.
- **cmdfns.h / cmdfns.c** : Management of commands sent by serial ports.
- **sctim.h / sctim.c** : Management of system timers.
- **ser.h / ser.c** : Management of serial communications via COM1, COM2 and COM3.
- **mapio.h / mapio.c** : Access interface to the system input/output ports.
- **scintr.h / scintr.c** : Management of system interrupts.
- **scmac.h / scmac.c** : Management of command macros used for robot control.
- **cfg.h / cfg.c** : Reading and management of configuration files.
- **log.h / log.c** : Management of logs for program execution.

### `Makefile` files
- **Main Makefile** : Compiles and links the entire SCMAIN application.
- **configgen.mak, ethgaread.mak, ethgatest.mak, otest.mak, vergen.mak** : Specific utilities, generating additional executables needed to configure and test hardware components.

## Detailed Analysis and Documentation

### General Operation of the Application
The SCMAIN application works as an interface between a serial terminal (COM1, COM2, COM3) and a robot controller via Ethernet (ETH0). It processes commands received via the serial port and sends control signals to a robot and its components (pre-alignor, trajectory, etc.).

#### **Serial Port Management**
- **COM1**: Main communication terminal.
- **COM2**: Possible connection to another terminal.
- **COM3**: Specific connection to an ISOPORT terminal.

#### **Command and Macro Management**
- Commands received via COM1 are processed and converted into macro commands.
- These macros are sent to the Galil controller via Ethernet (ETH0).

#### **Parameter File Management**
The application loads several binary files stored in `/root/controller/scmain/`. These files contain critical settings for system management and control macros.