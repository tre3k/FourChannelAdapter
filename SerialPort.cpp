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
    descriptor = open(path, O_RDWR|O_NOCTTY|O_SYNC);
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

    cfsetospeed(&tty, (speed_t) B9600);
    cfsetispeed(&tty, (speed_t) B9600);
    //setSpeed(speed);

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
#ifdef DEBUG_MESSAGE
    printf("Open serial port ok! descriptor: %d\n",descriptor);


    int mode;
    int status = ioctl(descriptor,MOXA_GET_OP_MODE, &mode);
    printf("get mode: %d status: %d\n",mode, status);

    switch(mode){
        case RS232_MODE:
            printf("RS232 mode\n");
            break;
        case RS485_2WIRE_MODE:
            printf("RS485 2Wire mode\n");
            break;
        case RS422_MODE:
            printf("RS422 mode\n");
            break;
        case RS485_4WIRE_MODE:
            printf("RS485 4Wire mode\n");
            break;
    }
#endif
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