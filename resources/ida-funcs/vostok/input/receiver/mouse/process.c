void __userpurge vostok::input::receiver::mouse::process(
        vostok::input::receiver::mouse *this@<ecx>,
        int a2@<esi>,
        vostok::input::vector<vostok::input::handler *> *handlers)
{
  vostok::input::vector<vostok::input::handler *> *v3; // ecx
  __int16 v4; // dx
  int v5; // eax
  void **M_finish; // ebp
  void **M_start; // edi
  vostok::input::mouse_button v8; // ebp
  char v9; // bl
  char v10; // al
  int v11; // eax
  void **v12; // edi
  vostok::input::mouse_button v13; // ebx
  int v14; // eax
  void **v15; // edi
  vostok::input::mouse_button v16; // ebx
  void **j; // edi
  vostok::input::receiver::mouse *v18; // [esp+20h] [ebp-18h]
  vostok::input::handler **it_e; // [esp+2Ch] [ebp-Ch]
  int i; // [esp+30h] [ebp-8h]
  int ia; // [esp+30h] [ebp-8h]
  int ib; // [esp+30h] [ebp-8h]
  __int16 changed_buttons; // [esp+34h] [ebp-4h]

  v3 = handlers;
  v4 = (unsigned __int8)(*(_BYTE *)(a2 + 16) ^ *(_BYTE *)(a2 + 32));
  v5 = (unsigned __int8)(v4 & *(_BYTE *)(a2 + 16));
  M_finish = handlers->_M_impl._M_finish;
  it_e = (vostok::input::handler **)M_finish;
  changed_buttons = v4;
  i = v5;
  if ( ((unsigned __int8)v4 & *(_BYTE *)(a2 + 16)) != 0 )
  {
    do
    {
      M_start = v3->_M_impl._M_start;
      if ( v3->_M_impl._M_start != M_finish )
      {
        v8 = vostok::input::receiver::mouse::convert_to_binder_mouse_button(
               (unsigned __int16)v5 & ~((unsigned __int16)v5 - 1),
               v18);
        do
        {
          v9 = (*(int (__thiscall **)(void *, _DWORD, vostok::input::mouse_button, _DWORD))(*(_DWORD *)*M_start + 8))(
                 *M_start,
                 *(_DWORD *)(a2 + 44),
                 v8,
                 0);
          v10 = (*(int (__thiscall **)(void *, _DWORD, vostok::input::mouse_button, int))(*(_DWORD *)*M_start + 8))(
                  *M_start,
                  *(_DWORD *)(a2 + 44),
                  v8,
                  2);
          if ( v9 )
            break;
          if ( v10 )
            break;
          ++M_start;
        }
        while ( M_start != (void **)it_e );
        v5 = i;
        M_finish = (void **)it_e;
        v3 = handlers;
      }
      v5 &= v5 - 1;
      i = v5;
    }
    while ( (_WORD)v5 );
    v4 = changed_buttons;
  }
  v11 = (unsigned __int16)(v4 & ~*(unsigned __int8 *)(a2 + 16));
  for ( ia = v11; (_WORD)v11; ia = v11 )
  {
    v12 = v3->_M_impl._M_start;
    if ( v3->_M_impl._M_start != M_finish )
    {
      v13 = vostok::input::receiver::mouse::convert_to_binder_mouse_button(
              (unsigned __int16)v11 & ~((unsigned __int16)v11 - 1),
              v18);
      do
      {
        if ( (*(unsigned __int8 (__thiscall **)(void *, _DWORD, vostok::input::mouse_button, int))(*(_DWORD *)*v12 + 8))(
               *v12,
               *(_DWORD *)(a2 + 44),
               v13,
               1) )
        {
          break;
        }
        ++v12;
      }
      while ( v12 != M_finish );
      v11 = ia;
      v3 = handlers;
    }
    v11 &= v11 - 1;
  }
  v14 = (unsigned __int8)(*(_BYTE *)(a2 + 16) & *(_BYTE *)(a2 + 32));
  ib = v14;
  if ( (*(_BYTE *)(a2 + 16) & *(_BYTE *)(a2 + 32)) != 0 )
  {
    do
    {
      v15 = v3->_M_impl._M_start;
      if ( v3->_M_impl._M_start != M_finish )
      {
        v16 = vostok::input::receiver::mouse::convert_to_binder_mouse_button(
                (unsigned __int16)v14 & ~((unsigned __int16)v14 - 1),
                v18);
        do
        {
          if ( (*(unsigned __int8 (__thiscall **)(void *, _DWORD, vostok::input::mouse_button, int))(*(_DWORD *)*v15 + 8))(
                 *v15,
                 *(_DWORD *)(a2 + 44),
                 v16,
                 2) )
          {
            break;
          }
          ++v15;
        }
        while ( v15 != M_finish );
        v3 = handlers;
        v14 = ib;
      }
      v14 &= v14 - 1;
      ib = v14;
    }
    while ( (_WORD)v14 );
  }
  if ( *(_DWORD *)(a2 + 4) || *(_DWORD *)(a2 + 8) || *(_DWORD *)(a2 + 12) )
  {
    for ( j = v3->_M_impl._M_start; j != M_finish; ++j )
    {
      if ( (*(unsigned __int8 (__thiscall **)(void *, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)*j + 12))(
             *j,
             *(_DWORD *)(a2 + 44),
             *(_DWORD *)(a2 + 4),
             *(_DWORD *)(a2 + 8),
             *(_DWORD *)(a2 + 12)) )
      {
        break;
      }
    }
  }
}
