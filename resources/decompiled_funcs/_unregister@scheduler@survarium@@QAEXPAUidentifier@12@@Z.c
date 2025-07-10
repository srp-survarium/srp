void __thiscall survarium::scheduler::unregister(
        survarium::scheduler *this,
        survarium::scheduler::identifier *identifier)
{
  unsigned int m_current_index; // edx
  vostok::vectora<survarium::scheduler::record> *v3; // ebx
  survarium::scheduler::record *M_finish; // esi
  survarium::scheduler::identifier *m_id; // eax
  int v6; // ebp
  survarium::scheduler::record *v7; // ebx
  boost::detail::function::vtable_base *vtable; // eax
  void (__cdecl *v9)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax

  m_current_index = this->m_current_index;
  if ( m_current_index >= (*(_DWORD *)identifier & 0x7FFFFFFFu) )
    this->m_current_index = m_current_index - 1;
  v3 = this->m_objects[*(unsigned int *)identifier >> 31];
  M_finish = v3->_M_impl._M_finish;
  m_id = M_finish[-1].m_id;
  v6 = (int)&v3->_M_impl._M_start[*(_DWORD *)identifier & 0x7FFFFFFF];
  --M_finish;
  *(_DWORD *)v6 = m_id;
  boost::function<void __cdecl (unsigned char,vostok::network_core::packet_reader &)>::operator=(
    &M_finish->m_callback,
    (boost::function2<void,unsigned int,unsigned int> *)(v6 + 8));
  *(_QWORD *)(v6 + 40) = M_finish->survarium::scheduler::scheduler_record;
  *(_DWORD *)(v6 + 48) = M_finish->m_last_update_time;
  **(_DWORD **)v6 ^= (*(_DWORD *)identifier ^ **(_DWORD **)v6) & 0x7FFFFFFF;
  v7 = --v3->_M_impl._M_finish;
  vtable = v7->m_callback.vtable;
  if ( vtable )
  {
    if ( ((unsigned __int8)vtable & 1) == 0 )
    {
      v9 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((unsigned int)vtable & 0xFFFFFFFE);
      if ( v9 )
        v9(&v7->m_callback.functor, &v7->m_callback.functor, 2);
    }
    v7->m_callback.vtable = 0;
  }
  *(_DWORD *)identifier &= ~0x80000000;
}
