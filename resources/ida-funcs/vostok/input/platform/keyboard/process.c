void __thiscall vostok::input::platform::keyboard::process(
        vostok::input::platform::keyboard *this,
        vostok::input::vector<vostok::input::handler *> *handlers)
{
  unsigned int *p_dwData; // eax
  int v5; // ecx
  bool v6; // zf
  void **M_finish; // eax
  void **M_start; // edi
  void **v9; // edi
  void **v10; // [esp+Ch] [ebp-Ch]
  void **v11; // [esp+Ch] [ebp-Ch]
  unsigned int *v12; // [esp+10h] [ebp-8h]
  unsigned int v13; // [esp+14h] [ebp-4h]
  int *m_current_key_state; // [esp+14h] [ebp-4h]
  int v15; // [esp+20h] [ebp+8h]
  unsigned int v16; // [esp+20h] [ebp+8h]

  v13 = 0;
  if ( this->m_current_events_count )
  {
    p_dwData = &this->m_current_events[0].dwData;
    v12 = &this->m_current_events[0].dwData;
    do
    {
      v5 = *(p_dwData - 1);
      v6 = *(_BYTE *)p_dwData >= 0;
      M_finish = handlers->_M_impl._M_finish;
      M_start = handlers->_M_impl._M_start;
      v15 = v5;
      v10 = M_finish;
      if ( v6 )
      {
        if ( M_start != M_finish )
        {
          do
          {
            if ( (**(unsigned __int8 (__thiscall ***)(void *, vostok::input::world *, int, int))*M_start)(
                   *M_start,
                   this->m_world,
                   v15,
                   2) )
            {
              break;
            }
            ++M_start;
          }
          while ( M_start != v10 );
        }
      }
      else if ( M_start != M_finish )
      {
        do
        {
          if ( (**(unsigned __int8 (__thiscall ***)(void *, vostok::input::world *, int, int))*M_start)(
                 *M_start,
                 this->m_world,
                 v15,
                 1) )
          {
            break;
          }
          ++M_start;
        }
        while ( M_start != v10 );
      }
      ++v13;
      p_dwData = v12 + 5;
      v12 += 5;
    }
    while ( v13 < this->m_current_events_count );
  }
  v16 = 0;
  m_current_key_state = this->m_current_key_state;
  do
  {
    if ( *m_current_key_state )
    {
      v9 = handlers->_M_impl._M_start;
      v11 = handlers->_M_impl._M_finish;
      if ( handlers->_M_impl._M_start != v11 )
      {
        do
        {
          if ( (**(unsigned __int8 (__thiscall ***)(void *, vostok::input::world *, unsigned int, int))*v9)(
                 *v9,
                 this->m_world,
                 v16,
                 3) )
          {
            break;
          }
          ++v9;
        }
        while ( v9 != v11 );
      }
    }
    ++v16;
    ++m_current_key_state;
  }
  while ( v16 < 0x100 );
  this->m_current_events_count = 0;
}
