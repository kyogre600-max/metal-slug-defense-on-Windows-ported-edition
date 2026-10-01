#include "../aot_runtime.h"
void install_0();
void install_1();
void install_2();
void install_3();
void install_4();
void install_5();
void install_6();
void install_7();
void install_8();
void install_9();
void install_10();
void install_11();
void install_12();
void install_13();
void install_14();
void install_15();
void install_16();
void install_17();
void install_18();
void install_19();
void install_20();
void install_21();
void install_22();
void install_23();
void install_24();
void install_25();
void install_26();
void install_27();
void install_28();
void install_29();
void install_30();
void install_31();
void install_32();
void install_33();
void install_34();
void install_35();
void install_36();
void install_37();
void install_38();
void install_39();
void install_40();
void install_41();
void install_42();
void install_43();
void install_44();
void install_45();
void install_46();
void install_47();
void install_48();
void install_49();

static Block text_blocks[0x110000/2]={},sort_blocks[4096/2]={};
static uint8_t text_modes[0x110000/2]={},sort_modes[4096/2]={};
void register_block(uint32_t p,Block f){
 uint32_t a=p&~1u;
 if(a>=0x10124000&&a<0x10234000){auto n=(a-0x10124000)/2;text_blocks[n]=f;text_modes[n]=p&1;}
 else if(a>=0x1f010000&&a<0x1f011000){auto n=(a-0x1f010000)/2;sort_blocks[n]=f;sort_modes[n]=p&1;}
}
Block find_block(uint32_t p){
 static bool ready=false;
 if(!ready){install_0();install_1();install_2();install_3();install_4();install_5();install_6();install_7();install_8();install_9();install_10();install_11();install_12();install_13();install_14();install_15();install_16();install_17();install_18();install_19();install_20();install_21();install_22();install_23();install_24();install_25();install_26();install_27();install_28();install_29();install_30();install_31();install_32();install_33();install_34();install_35();install_36();install_37();install_38();install_39();install_40();install_41();install_42();install_43();install_44();install_45();install_46();install_47();install_48();install_49(); ready=true;}
 uint32_t a=p&~1u;
 if(a>=0x10124000&&a<0x10234000){auto n=(a-0x10124000)/2;return text_modes[n]==(p&1)?text_blocks[n]:nullptr;}
 if(a>=0x1f010000&&a<0x1f011000){auto n=(a-0x1f010000)/2;return sort_modes[n]==(p&1)?sort_blocks[n]:nullptr;}
 return nullptr;
}
