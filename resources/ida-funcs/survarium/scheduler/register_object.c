survarium::scheduler::record *__thiscall survarium::scheduler::register_object(
        survarium::scheduler *this,
        survarium::scheduler *identifier,
        survarium::scheduler::identifier *callback,
        boost::function<void __cdecl(unsigned int,unsigned int)> *active,
        bool activea)
{
  int v5; // eax
  unsigned int v6; // ecx
  vostok::vectora<survarium::scheduler::record> *v7; // edi
  void (__cdecl *v8)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  int v9; // esi
  survarium::scheduler::record __x; // [esp+10h] [ebp-38h] BYREF

  v5 = *(_DWORD *)callback & 0x7FFFFFFF;
  __x.m_callback.vtable = 0;
  v6 = v5 | (activea << 31);
  *callback = (survarium::scheduler::identifier)v6;
  v7 = identifier->m_objects[v6 >> 31];
  *callback = (survarium::scheduler::identifier)(v6 ^ (v6 ^ (v7->_M_impl._M_finish - v7->_M_impl._M_start)) & 0x7FFFFFFF);
  stlp_std::priv::_Impl_vector<survarium::scheduler::record,vostok::vectora_allocator<survarium::scheduler::record>>::push_back(
    (stlp_std::priv::_Impl_vector<survarium::scheduler::record,vostok::vectora_allocator<survarium::scheduler::record> > *)&__x,
    &__x);
  if ( __x.m_callback.vtable )
  {
    if ( ((int)__x.m_callback.vtable & 1) == 0 )
    {
      v8 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)__x.m_callback.vtable & 0xFFFFFFFE);
      if ( v8 )
        v8(&__x.m_callback.functor, &__x.m_callback.functor, 2);
    }
  }
  v9 = (int)&v7->_M_impl._M_finish[-1];
  *(_DWORD *)v9 = callback;
  boost::function<void __cdecl (unsigned char,vostok::network_core::packet_reader &)>::operator=(
    active,
    (boost::function2<void,unsigned int,unsigned int> *)(v9 + 8));
  return (survarium::scheduler::record *)v9;
}
