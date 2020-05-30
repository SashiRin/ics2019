#include "cpu/exec.h"

make_EHelper(lui) {
  rtl_sr(id_dest->reg, &id_src->val, 4);

  print_asm_template2(lui);
}

make_EHelper(arithmetici) {
  switch (decinfo.isa.instr.funct3)
  {
  case 0:
    rtl_addi(&id_dest->val, &id_src->val, decinfo.isa.instr.simm11_0);
    print_asm_template2(addi);
    break;
  
  default:
    break;
  }
}

make_EHelper(auipc) {
  s0 = decinfo.seq_pc - 4;
  rtl_add(&id_src->val, &s0, &id_src->val);
  rtl_sr(id_dest->reg, &id_src->val, 4);
  print_asm_template2(auipc);
}