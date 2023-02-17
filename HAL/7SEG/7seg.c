/*
 * CFile1.c
 *
 * Created: 2/17/2023 5:38:51 AM
 *  Author: Mohamed Sameh
 */ 

#include "../../MCAL/DIO/dio.h"
#include "7seg.h"


void seven_seg_init(dio_level_t portname)
{
	dio_set_port_direction(portname, DIO_DIRECTION_OUTPUT);
}

void seven_seg_write(dio_level_t portname, unsigned char number)
{
	unsigned char arr[]={ 0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x47,0x7f,0x6f};
	
	dio_write_port(portname,arr[number]);
}