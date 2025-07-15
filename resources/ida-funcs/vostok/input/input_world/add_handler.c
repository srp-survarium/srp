void __thiscall vostok::input::input_world::add_handler(
        vostok::input::input_world *this,
        vostok::input::handler *handler)
{
  vostok::input::handler *v2; // ebx
  int v4; // eax
  vostok::input::vector<vostok::input::handler *> *p_m_handlers; // ecx
  void **M_start; // edi
  int v7; // esi
  int v8; // eax
  const stlp_std::__true_type *v9; // [esp+0h] [ebp-18h]
  unsigned int v10; // [esp+4h] [ebp-14h]
  bool v11; // [esp+8h] [ebp-10h]
  stlp_std::priv::_Impl_vector<void *,vostok::input::std_allocator<void *> > *p_M_impl; // [esp+Ch] [ebp-Ch]
  int v13; // [esp+14h] [ebp-4h]

  v2 = handler;
  v4 = handler->input_priority(handler);
  p_m_handlers = &this->m_handlers;
  M_start = this->m_handlers._M_impl._M_start;
  v7 = this->m_handlers._M_impl._M_finish - M_start;
  v13 = v4;
  p_M_impl = &p_m_handlers->_M_impl;
  if ( v7 > 0 )
  {
    do
    {
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)M_start[v7 >> 1] + 16))(M_start[v7 >> 1]) >= v13 )
      {
        v7 >>= 1;
      }
      else
      {
        M_start += (v7 >> 1) + 1;
        v7 += -1 - (v7 >> 1);
      }
    }
    while ( v7 > 0 );
    v2 = handler;
    p_m_handlers = (vostok::input::vector<vostok::input::handler *> *)p_M_impl;
  }
  v8 = (char *)p_m_handlers->_M_impl._M_end_of_storage._M_data - (char *)p_m_handlers->_M_impl._M_finish;
  handler = v2;
  if ( v8 >> 2 )
    stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::_M_fill_insert_aux(
      &p_m_handlers->_M_impl,
      M_start,
      1u,
      (void **)&handler,
      (const stlp_std::__false_type *)&handler + 3);
  else
    stlp_std::priv::_Impl_vector<void *,vostok::input::std_allocator<void *>>::_M_insert_overflow(
      &p_m_handlers->_M_impl,
      (int)p_m_handlers,
      M_start,
      (void **)&handler,
      v9,
      v10,
      v11);
}
