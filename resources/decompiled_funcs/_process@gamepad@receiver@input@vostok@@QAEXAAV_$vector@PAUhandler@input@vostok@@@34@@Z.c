void __userpurge vostok::input::receiver::gamepad::process(
        vostok::input::receiver::gamepad *this@<ecx>,
        int a2@<esi>,
        vostok::input::vector<vostok::input::handler *> *handlers)
{
  vostok::input::vector<vostok::input::handler *> *v3; // edx
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // cx
  unsigned __int16 v6; // bp
  void **M_start; // edi
  void **v8; // ebx
  unsigned __int16 i; // di
  void **v10; // ebx
  unsigned __int16 j; // di
  void **it_e; // [esp+Ch] [ebp-8h]
  unsigned __int16 changed_buttons; // [esp+10h] [ebp-4h]

  if ( *(_BYTE *)(a2 + 93) )
  {
    v3 = handlers;
    it_e = handlers->_M_impl._M_finish;
    v4 = *(_WORD *)(a2 + 56);
    v5 = v4 ^ *(_WORD *)(a2 + 84);
    v6 = v5 & v4;
    M_start = handlers->_M_impl._M_start;
    changed_buttons = v5;
    if ( (v5 & v4) != 0 )
    {
      do
      {
        for ( ; M_start != it_e; ++M_start )
        {
          if ( (*(unsigned __int8 (__thiscall **)(void *, _DWORD, int, _DWORD))(*(_DWORD *)*M_start + 4))(
                 *M_start,
                 *(_DWORD *)(a2 + 4),
                 v6 & ~(v6 - 1),
                 0) )
          {
            break;
          }
        }
        v6 &= v6 - 1;
      }
      while ( v6 );
      v5 = changed_buttons;
      v3 = handlers;
    }
    v8 = v3->_M_impl._M_start;
    for ( i = v5 & ~*(_WORD *)(a2 + 56); i; i &= i - 1 )
    {
      if ( (*(unsigned __int8 (__thiscall **)(void *, _DWORD, int, int))(*(_DWORD *)*v8 + 4))(
             *v8,
             *(_DWORD *)(a2 + 4),
             i & ~(i - 1),
             1) )
      {
        break;
      }
    }
    v10 = handlers->_M_impl._M_start;
    for ( j = *(_WORD *)(a2 + 84) & *(_WORD *)(a2 + 56); j; j &= j - 1 )
    {
      if ( (*(unsigned __int8 (__thiscall **)(void *, _DWORD, int, int))(*(_DWORD *)*v10 + 4))(
             *v10,
             *(_DWORD *)(a2 + 4),
             j & ~(j - 1),
             2) )
      {
        break;
      }
    }
  }
}
