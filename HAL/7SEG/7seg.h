/*
 * _7seg.h
 *
 * Created: 2/17/2023 5:39:24 AM
 *  Author: Mohamed Sameh
 */ 


#ifndef SEG_H_
#define SEG_H_

void seven_seg_init(dio_level_t portname);
void seven_seg_write(dio_level_t portname, unsigned char number);


#endif /* 7SEG_H_ */