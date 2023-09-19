#ifndef _Bit_Math_H
#define _Bit_Math_H

#define Set_Bit(Reg,Bit) 	(Reg |= (1<<Bit))
#define set_Bit(Reg,Bit) 	(Reg |= (1<<Bit))

#define Clear_Bit(Reg,Bit) 	(Reg &= ~(1<<Bit))
#define clear_Bit(Reg,Bit) 	(Reg &= ~(1<<Bit))

#define Toggle_Bit(Var,Bit)	(Reg ^= (1<<Bit))
#define toggle_Bit(Var,Bit)	(Reg ^= (1<<Bit))

#define Get_Bit(Reg,Bit)	((Reg >> Bit)& 0x01)
#define get_Bit(Reg,Bit)	((Reg >> Bit)& 0x01)

#endif
