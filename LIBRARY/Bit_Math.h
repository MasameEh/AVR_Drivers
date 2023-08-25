

#define REGISTER_SIZE 8
#define SET_BIT(REG,BIT_POS)    (REG|=(1<<BIT_POS))
#define CLR_BIT(REG,BIT_POS)    (REG&=(~(1<<BIT_POS)))
#define TOG_BIT(REG,BIT_POS)    (REG^=(1<<BIT_POS))
#define READ_BIT(REG,BIT_POS)    ((REG&(1<<BIT_POS))>>BIT_POS)
#define IS_BIT_SET(REG,BIT_POS)  ((REG&(1<<BIT_POS))>>BIT_POS)
#define IS_BIT_CLR(REG,BIT_POS)  (!((REG&(1<<BIT_POS))>>BIT_POS))

