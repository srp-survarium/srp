void __usercall vostok::console_commands::cc_delegate::~cc_delegate(
        vostok::console_commands::cc_delegate *this@<ecx>,
        survarium::keyboard_key_descr ***a2@<esi>)
{
  survarium::keyboard_key_descr **v2; // eax
  void (__cdecl *v3)(survarium::keyboard_key_descr ***, survarium::keyboard_key_descr ***, int); // eax
  survarium::keyboard_key_descr **v4; // eax
  void (__cdecl *v5)(survarium::keyboard_key_descr ***, survarium::keyboard_key_descr ***, int); // eax

  v2 = a2[16];
  if ( v2 )
  {
    if ( ((unsigned __int8)v2 & 1) == 0 )
    {
      v3 = *(void (__cdecl **)(survarium::keyboard_key_descr ***, survarium::keyboard_key_descr ***, int))((unsigned int)v2 & 0xFFFFFFFE);
      if ( v3 )
        v3(a2 + 18, a2 + 18, 2);
    }
    a2[16] = 0;
  }
  *a2 = stru_95AF78.m_key_bindings[37].m_keyboard;
  v4 = a2[8];
  if ( v4 )
  {
    if ( ((unsigned __int8)v4 & 1) == 0 )
    {
      v5 = *(void (__cdecl **)(survarium::keyboard_key_descr ***, survarium::keyboard_key_descr ***, int))((unsigned int)v4 & 0xFFFFFFFE);
      if ( v5 )
        v5(a2 + 10, a2 + 10, 2);
    }
    a2[8] = 0;
  }
}
