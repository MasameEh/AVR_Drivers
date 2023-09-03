/* 
 * File:   Bit_Math.h
 *
 * Author: Mohamed Sameh
 *
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

/* Section : Includes */

/* Section : Macro Declarations */
#define REGISTER_SIZE 8
#define SET_BIT(REG,BIT_POS)    (REG|=(1<<BIT_POS))
#define CLR_BIT(REG,BIT_POS)    (REG&=(~(1<<BIT_POS)))
#define TOG_BIT(REG,BIT_POS)    (REG^=(1<<BIT_POS))
#define READ_BIT(REG,BIT_POS)    ((REG&(1<<BIT_POS))>>BIT_POS)
#define IS_BIT_SET(REG,BIT_POS)  ((REG&(1<<BIT_POS))>>BIT_POS)
#define IS_BIT_CLR(REG,BIT_POS)  (!((REG&(1<<BIT_POS))>>BIT_POS))

/* Section : Macro Functions Declarations */


/* Section : Data Types Declarations  */


/* Section : Functions Declarations */

#endif