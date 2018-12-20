//
// Created by Kirill Pshenichnyi on 17.12.18.
//

#ifndef FOURCHANNELADAPTER_SERIALPORT_H
#define FOURCHANNELADAPTER_SERIALPORT_H

#define DEBUG_MESSAGE

#include <termios.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <asm/ioctls.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>

#ifdef DEBUG_MESSAGE
#include <stdio.h>
#endif

namespace SP {
    const unsigned int MOXA = 0x400;
    const unsigned int MOXA_SET_OP_MODE = (MOXA + 66);
    const unsigned int MOXA_GET_OP_MODE = (MOXA + 67);

    enum {
        RS232_MODE,
        RS485_2WIRE_MODE,
        RS422_MODE,
        RS485_4WIRE_MODE
    };

    class SerialPort {
    private:
        int descriptor;
        int flags;
        struct termios tty_old;
        struct termios tty;

    public:
        int controller_number = 0;

    public:
        SerialPort(const char *path);
        ~SerialPort();
        int speed;
        int getDescriptor(void);
        void Open(const char *path);
        void Close(void);
        void setSpeed(int value);
        void setFlags(int value);
        int getSpeed(void);
    };
}

#endif //FOURCHANNELADAPTER_SERIALPORT_H
