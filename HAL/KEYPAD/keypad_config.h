


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#define KEYPAD_RAW_NUM    4
#define KEYPAD_COLUMN_NUM 4

#define KEYPAD_RAW_ARR_VALUE {     \
	{DIO_PORTA, DIO_PIN0},         \
	{DIO_PORTA, DIO_PIN1},         \
	{DIO_PORTA, DIO_PIN2},         \
	{DIO_PORTA, DIO_PIN3}          \
};

#define KEYPAD_COL_ARR_VALUE {     \
	{DIO_PORTA, DIO_PIN4},         \
	{DIO_PORTA, DIO_PIN5},         \
	{DIO_PORTA, DIO_PIN6},         \
	{DIO_PORTA, DIO_PIN7}          \
};


#define KEYPAD_KEY_VALUES   {	  \
	{'7','8','9','/'},         \
	{'4','5','6','*'},         \
	{'1','2','3','-'},         \
	{'A','0','=','+'}         \
}

#define RELEASED_LEVEL  DIO_LEVEL_HIGH
#define PRESSED_LEVEL   DIO_LEVEL_LOW

#define NO_PRESS_VAL    0


#endif /* KEYPAD_CONFIG_H_ */