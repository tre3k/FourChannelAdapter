//
// Created by kirill on 17.12.18.
//


#include "SerialPort.h"

using namespace SP;

SerialPort::SerialPort(const char *path) {
    descriptor = 0;
    speed = 9600;
#ifdef DEBUG_MESSAGE
    printf("init serialPort %s\n",path);
#endif
    Open(path);
}

SerialPort::~SerialPort() {
    Close();
}

void SerialPort::Open(const char *path) {

    descriptor = open(path, O_RDWR|O_NOCTTY);
    if(descriptor < 0){
#ifdef DEBUG_MESSAGE
        printf("Error open!\n");
#endif
        return;
    }

    if(tcgetattr(descriptor, &tty)!=0){
        close(descriptor);
        descriptor = -1;
        return;
    }

    tty_old = tty;

    tty.c_cflag &= ~(PARENB | CSTOPB | CSIZE);
    tty.c_cflag = CS8|CREAD|CLOCAL;

    tty.c_cc[VTIME] = 5;
    tty.c_cc[VMIN] = 1;

    setSpeed(speed);

    tcflush(descriptor, TCIFLUSH);
    cfmakeraw(&tty);
    if(tcsetattr(descriptor,TCSANOW,&tty)!=0){
        close(descriptor);
        descriptor = -1;
#ifdef DEBUG_MESSAGE
        printf("Error set attributes!\n");
#endif
        return;
    }
}

void SerialPort::Close() {
    tcsetattr(descriptor, TCSANOW, &tty_old);
    close(descriptor);
}

void SerialPort::setSpeed(int value) {

    cfsetospeed(&tty, (speed_t) value);
    cfsetispeed(&tty, (speed_t) value);
    tcflush(descriptor, TCIFLUSH);
    cfmakeraw(&tty);
    if(tcsetattr(descriptor,TCSANOW,&tty)!=0){
#ifdef DEBUG_MESSAGE
        printf("Error set attributes!\n");
#endif
        return;
    }
    speed = value;
}

int SerialPort::getDescriptor() {
    return descriptor;
}

int SerialPort::getSpeed() {
    return speed;
}