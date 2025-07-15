void __usercall vostok::console_commands::cc_u32::~cc_u32(
        vostok::console_commands::cc_string *this@<ecx>,
        survarium::keyboard_key_descr ***a2@<esi>)
{
  survarium::keyboard_key_descr **v2; // eax
  void (__cdecl *v3)(survarium::keyboard_key_descr ***, survarium::keyboard_key_descr ***, int); // eax

  *a2 = stru_95AF78.m_key_bindings[37].m_keyboard;
  v2 = a2[8];
  if ( v2 )
  {
    if ( ((unsigned __int8)v2 & 1) == 0 )
    {
      v3 = *(void (__cdecl **)(survarium::keyboard_key_descr ***, survarium::keyboard_key_descr ***, int))((unsigned int)v2 & 0xFFFFFFFE);
      if ( v3 )
        v3(a2 + 10, a2 + 10, 2);
    }
    a2[8] = 0;
  }
}
