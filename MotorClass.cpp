//
// Created by Kirill Pshenichny on 17.12.18.
//

#include <poll.h>
#include "MotorClass.h"

using namespace Motor;

MotorClass::MotorClass(int fd_value) {
    fd = fd_value;
    setTitle();
}

void MotorClass::setChannel(int channel_value) {
    channel = channel_value;
}

void MotorClass::setDevice(int device_value) {
    device = device_value;
    setTitle();
}

int MotorClass::rawWriteRead(char *in_buff, char *out_buff, int write_size, int read_size) {
    int spot = 0;
    int i = 0;

    struct pollfd fds;
    fds.fd = fd;
    fds.events = POLLOUT;
    if(poll(&fds,2,500) < 0) return -1;

    /* SEND */
#ifdef DEBUG_MESSAGE
    printf("fd: %d, Send: ",fd);
#endif
    if(fds.revents & POLLOUT) {             //???
        for (i = 0; i < write_size; i++) {
#ifdef DEBUG_MESSAGE
            if(i==5 || i==13) printf("  ");
            printf("0x%.2x ", in_buff[i] & 0xff);
#endif
            if (write(fd, &in_buff[i], 1) == 0) break;
        }
#ifdef DEBUG_MESSAGE
        printf("\n");
#endif
    }

    /* RECV */
#ifdef DEBUG_MESSAGE
    printf("Recv: ");
#endif
    for(i=0;i<read_size;i++){
        spot += read(fd,&out_buff[i],1);
#ifdef DEBUG_MESSAGE
        if(i==5 || i==13) printf("  ");
        printf("0x%.2x ",out_buff[i] & 0xff);
#endif
    }
#ifdef DEBUG_MESSAGE
    printf("\n");
#endif
    return spot;
}

void MotorClass::setTitle() {
    tx_packet.title = 0x5aa5;
    tx_packet.num_of_device = (char) (device & 0xff);
    tx_packet.device_type = 253;
    tx_packet.signature = 0x9bb9;
    return;
}

char MotorClass::getCheckSum(char *buff){
    char check = 0x00;
    for(int i=2;i<13;i++) check ^= buff[i];
    return check;
}

int MotorClass::SendPacket() {
    tx_packet.checksum = getCheckSum((char *) &tx_packet);
    rawWriteRead((char *) &tx_packet, (char *) &rx_packet,
                 sizeof(tx_packet), sizeof(rx_packet));
    return 0;
}

void MotorClass::pushData(Motor::sPacket *pack, char *data) {
    for(int i=0;i<8;i++) pack->data[i] = data[i];
}

void MotorClass::popData(Motor::sPacket *pack, char *data) {
    for(int i=0;i<8;i++) data[i] = pack->data[i];
}

void MotorClass::sendPushPop(char *rxdata, char *txdata) {
    pushData(&tx_packet,(char *)txdata);
    SendPacket();
    popData(&rx_packet,(char *)rxdata);
}

char MotorClass::setNbitsNbytes(int nbits, int nbytes) {
    return (char) (((nbytes-1) << 6)&0xc0)|(nbits & 0xff);
}

void MotorClass::cmdSensorRead(Motor::sSensor *ssensor) {
    tx_packet.command = CMD_SENSOR_READ;
    char *bytes;
    bytes = (char *) ssensor;
    for(int i=1;i<sizeof(sSensorConfig);i++) bytes[i] = 0x00;
    sendPushPop((char *) ssensor,(char *) ssensor);
}

void MotorClass::cmdSensorWconfig(Motor::sSensorConfig *ssensorconf) {
    tx_packet.command = CMD_SENSOR_WCONFIG;
    sendPushPop((char *) ssensorconf,(char *) ssensorconf);
}

void MotorClass::cmdSensorRconfig(Motor::sSensorConfig *ssensorconf) {
    tx_packet.command = CMD_SENSOR_RCONFIG;
    char *bytes;
    bytes = (char *) ssensorconf;
    for(int i=1;i<sizeof(sSensorConfig);i++) bytes[i] = 0x00;
    sendPushPop((char *) ssensorconf,(char *) ssensorconf);
}

void MotorClass::cmdMotorRead(Motor::sMotorRW *smotorrw) {
    tx_packet.command = CMD_MOTOR_READ;
    char *bytes;
    bytes = (char *) smotorrw;
    for(int i=1;i<sizeof(sSensorConfig);i++) bytes[i] = 0x00;
    sendPushPop((char *) smotorrw,(char *) smotorrw);
}

void MotorClass::cmdMotorWrite(Motor::sMotorRW *smotorrw) {
    tx_packet.command = CMD_MOTOR_WRITE;
    sendPushPop((char *) smotorrw,(char *) smotorrw);
}

void MotorClass::cmdMotorWconfig(Motor::sMotorConfig *smotorconfig) {
    tx_packet.command = CMD_MOTOR_WCONFIG;
    sendPushPop((char *) smotorconfig,(char *) smotorconfig);
}

void MotorClass::cmdMotorRconfig(Motor::sMotorConfig *smotorconfig) {
    tx_packet.command = CMD_MOTOR_RCONFIG;
    char *bytes;
    bytes = (char *) smotorconfig;
    for(int i=1;i<sizeof(sSensorConfig);i++) bytes[i] = 0x00;
    sendPushPop((char *) smotorconfig,(char *) smotorconfig);
}

void MotorClass::cmdTaskRconfig(Motor::sTaskConfig *staskconfig) {
    tx_packet.command = CMD_TASK_RCONFIG;
    char *bytes;
    bytes = (char *) staskconfig;
    for(int i=1;i<sizeof(sTaskConfig);i++) bytes[i] = 0x00;                 // all zero except channel
    sendPushPop((char *) staskconfig,(char *) staskconfig);
}

void MotorClass::cmdTaskWconfig(Motor::sTaskConfig *staskconfig) {
    tx_packet.command = CMD_TASK_WCONFIG;
    sendPushPop((char *) staskconfig,(char *) staskconfig);
}

void MotorClass::cmdTaskRead(Motor::sTaskRead *staskread) {
    tx_packet.command = CMD_TASK_READ;
    char *bytes;
    bytes = (char *) staskread;
    for(int i=1;i<sizeof(sTaskRead);i++) bytes[i] = 0x00;                 // all zero except channel
    sendPushPop((char *) staskread,(char *) staskread);
}

void MotorClass::cmdTaskWrite(Motor::sTaskWrite *staskwrite) {
    tx_packet.command = CMD_TASK_WRITE;
    sendPushPop((char *) staskwrite,(char *) staskwrite);
}

bool MotorClass::cmdEcho() {
    tx_packet.command = CMD_ECHO;
    SendPacket();

    char *rx,*tx;
    tx = (char *)&tx_packet;
    rx = (char *)&rx_packet;

    for(int i=0;i<16;i++) if(tx[i]!=rx[i]) return false;
    return true;
}

int MotorClass::convertFromGrayCode(int value) {
    int retval = 0;
    for (retval=0;value;){
        retval^=value;
        value=value>>1;
    }
    return retval;
}
