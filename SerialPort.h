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
