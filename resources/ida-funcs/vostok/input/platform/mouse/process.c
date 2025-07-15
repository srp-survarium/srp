void __thiscall vostok::input::platform::mouse::process(
        vostok::input::platform::mouse *this,
        vostok::input::vector<vostok::input::handler *> *handlers)
{
  vostok::input::vector<vostok::input::handler *> *v3; // ecx
  unsigned __int16 i; // bx
  void **M_start; // edi
  char v6; // al
  unsigned __int16 j; // bx
  void **v8; // edi
  unsigned __int16 k; // bx
  void **v10; // edi
  void **m; // edi
  vostok::input::platform::mouse *v12; // [esp+0h] [ebp-1Ch]
  __int16 v13; // [esp+Ch] [ebp-10h]
  int v14; // [esp+Ch] [ebp-10h]
  int v15; // [esp+Ch] [ebp-10h]
  int v16; // [esp+10h] [ebp-Ch]
  void **M_finish; // [esp+14h] [ebp-8h]
  char v18; // [esp+1Bh] [ebp-1h]

  v3 = handlers;
  M_finish = handlers->_M_impl._M_finish;
  v13 = (unsigned __int8)(this->m_current_state.buttons ^ this->m_previous_state.buttons);
  for ( i = (unsigned __int8)(v13 & this->m_current_state.buttons); i; i &= i - 1 )
  {
    M_start = v3->_M_impl._M_start;
    if ( v3->_M_impl._M_start != M_finish )
    {
      v16 = vostok::input::platform::mouse::convert_to_binder_mouse_button(i & ~(i - 1), v12);
      do
      {
        v18 = (*(int (__thiscall **)(void *, vostok::input::world *, int, _DWORD))(*(_DWORD *)*M_start + 8))(
                *M_start,
                this->m_world,
                v16,
                0);
        v6 = (*(int (__thiscall **)(void *, vostok::input::world *, int, int))(*(_DWORD *)*M_start + 8))(
               *M_start,
               this->m_world,
               v16,
               2);
        if ( v18 )
          break;
        if ( v6 )
          break;
        ++M_start;
      }
      while ( M_start != M_finish );
      v3 = handlers;
    }
  }
  for ( j = v13 & ~this->m_current_state.buttons; j; j &= j - 1 )
  {
    v8 = v3->_M_impl._M_start;
    if ( v3->_M_impl._M_start != M_finish )
    {
      v14 = vostok::input::platform::mouse::convert_to_binder_mouse_button(j & ~(j - 1), v12);
      do
      {
        if ( (*(unsigned __int8 (__thiscall **)(void *, vostok::input::world *, int, int))(*(_DWORD *)*v8 + 8))(
               *v8,
               this->m_world,
               v14,
               1) )
        {
          break;
        }
        ++v8;
      }
      while ( v8 != M_finish );
      v3 = handlers;
    }
  }
  for ( k = (unsigned __int8)(this->m_current_state.buttons & this->m_previous_state.buttons); k; k &= k - 1 )
  {
    v10 = v3->_M_impl._M_start;
    if ( v3->_M_impl._M_start != M_finish )
    {
      v15 = vostok::input::platform::mouse::convert_to_binder_mouse_button(k & ~(k - 1), v12);
      do
      {
        if ( (*(unsigned __int8 (__thiscall **)(void *, vostok::input::world *, int, int))(*(_DWORD *)*v10 + 8))(
               *v10,
               this->m_world,
               v15,
               2) )
        {
          break;
        }
        ++v10;
      }
      while ( v10 != M_finish );
      v3 = handlers;
    }
  }
  if ( this->m_current_state.x || this->m_current_state.y || this->m_current_state.z )
  {
    for ( m = v3->_M_impl._M_start;
          m != M_finish
       && !(*(unsigned __int8 (__thiscall **)(void *, vostok::input::world *, int, int, int))(*(_DWORD *)*m + 12))(
             *m,
             this->m_world,
             this->m_current_state.x,
             this->m_current_state.y,
             this->m_current_state.z);
          ++m )
    {
      ;
    }
  }
}
