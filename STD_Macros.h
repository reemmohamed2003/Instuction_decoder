/*
 * STD_Macros.h
 *
 * Created: 3/20/2024 12:51:55 PM
 *  Author: Al-Arab
 */ 


#ifndef STD_MACROS_H_
#define STD_MACROS_H_
#define Register_Size 8
#define Set_BIT(reg,bit)  reg|=(1<<bit)
#define CLR_BIT(reg,bit)  reg&=(~(1<<bit))
#define TOG_BIT(reg,bit)  reg^=(1<<bit)
#define Read_BIT(reg,bit) ((reg&(1<<bit)>>bit))


#endif /* STD_MACROS_H_ */