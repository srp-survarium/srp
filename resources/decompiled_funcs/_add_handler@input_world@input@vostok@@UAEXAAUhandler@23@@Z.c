void __thiscall vostok::input::input_world::add_handler(
        vostok::input::input_world *this,
        vostok::input::handler *handler)
{
  vostok::input::handler *v2; // ebx
  vostok::input::handler *v4; // eax
  void **M_start; // ecx
  void **v6; // eax
  int v7; // ecx
  const stlp_std::__true_type *v8; // [esp+0h] [ebp-Ch]
  unsigned int v9; // [esp+4h] [ebp-8h]
  bool v10; // [esp+8h] [ebp-4h]

  v2 = handler;
  v4 = (vostok::input::handler *)handler->input_priority(handler);
  M_start = this->m_handlers._M_impl._M_start;
  handler = v4;
  v6 = (void **)stlp_std::priv::__lower_bound<vostok::input::handler * *,int,handler_prio_less,handler_prio_less,int>(
                  (vostok::input::handler **)this->m_handlers._M_impl._M_finish,
                  (vostok::input::handler **)M_start,
                  (int *)&handler);
  v7 = this->m_handlers._M_impl._M_end_of_storage._M_data - this->m_handlers._M_impl._M_finish;
  handler = v2;
  if ( v7 )
    stlp_std::priv::_Impl_vector<void *,vostok::input::std_allocator<void *>>::_M_fill_insert_aux(
      &this->m_handlers._M_impl,
      v6,
      1u,
      (void **)&handler,
      (const stlp_std::__false_type *)&handler);
  else
    stlp_std::priv::_Impl_vector<void *,vostok::input::std_allocator<void *>>::_M_insert_overflow(
      0,
      (unsigned __int8 **)&this->m_handlers,
      v6,
      (void **)&handler,
      v8,
      v9,
      v10);
}
