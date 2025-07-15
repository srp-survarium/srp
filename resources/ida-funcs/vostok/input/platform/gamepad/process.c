void __thiscall vostok::input::platform::gamepad::process(
        vostok::input::platform::gamepad *this,
        vostok::input::vector<vostok::input::handler *> *handlers)
{
  void **M_start; // ebx
  __int16 buttons; // ax
  int i; // eax
  int v7; // eax
  unsigned __int16 k; // bx
  unsigned __int16 m; // bx
  __int16 v10; // [esp+4h] [ebp-Ch]
  int j; // [esp+8h] [ebp-8h]
  int v12; // [esp+Ch] [ebp-4h]
  void **M_finish; // [esp+18h] [ebp+8h]
  void **v14; // [esp+18h] [ebp+8h]
  void **v15; // [esp+18h] [ebp+8h]

  if ( this->m_inserted )
  {
    M_start = handlers->_M_impl._M_start;
    M_finish = handlers->_M_impl._M_finish;
    buttons = this->m_current_state.buttons;
    v10 = buttons ^ LOWORD(this->m_previous_state.buttons);
    for ( i = (unsigned __int16)(v10 & buttons); ; i &= i - 1 )
    {
      v12 = i;
      if ( !(_WORD)i )
        break;
      if ( M_start != M_finish )
      {
        v7 = (unsigned __int16)i & ~((unsigned __int16)i - 1);
        for ( j = v7;
              !(*(unsigned __int8 (__thiscall **)(void *, vostok::input::world *, int, _DWORD))(*(_DWORD *)*M_start + 4))(
                 *M_start,
                 this->m_world,
                 v7,
                 0);
              v7 = j )
        {
          if ( ++M_start == M_finish )
            break;
        }
        i = v12;
      }
    }
    v14 = handlers->_M_impl._M_start;
    for ( k = v10 & ~LOWORD(this->m_current_state.buttons);
          k
       && !(*(unsigned __int8 (__thiscall **)(void *, vostok::input::world *, int, int))(*(_DWORD *)*v14 + 4))(
             *v14,
             this->m_world,
             k & ~(k - 1),
             1);
          k &= k - 1 )
    {
      ;
    }
    v15 = handlers->_M_impl._M_start;
    for ( m = this->m_previous_state.buttons & LOWORD(this->m_current_state.buttons);
          m
       && !(*(unsigned __int8 (__thiscall **)(void *, vostok::input::world *, int, int))(*(_DWORD *)*v15 + 4))(
             *v15,
             this->m_world,
             m & ~(m - 1),
             2);
          m &= m - 1 )
    {
      ;
    }
  }
}
