void __thiscall stlp_std::priv::_Impl_vector<vostok::sound::unique_propagator_info,vostok::vectora_allocator<vostok::sound::unique_propagator_info>>::~_Impl_vector<vostok::sound::unique_propagator_info,vostok::vectora_allocator<vostok::sound::unique_propagator_info>>(
        stlp_std::priv::_Impl_vector<vostok::sound::unique_propagator_info,vostok::vectora_allocator<vostok::sound::unique_propagator_info> > *this)
{
  vostok::sound::unique_propagator_info *v1; // [esp-8h] [ebp-B0h] BYREF
  void *current; // [esp-4h] [ebp-ACh] BYREF
  stlp_std::priv::_Impl_vector<vostok::sound::unique_propagator_info,vostok::vectora_allocator<vostok::sound::unique_propagator_info> > *thisa; // [esp+0h] [ebp-A8h]
  int v4; // [esp+4h] [ebp-A4h]
  vostok::sound::unique_propagator_info **v5; // [esp+90h] [ebp-18h]
  stlp_std::reverse_iterator<vostok::sound::unique_propagator_info *> v6; // [esp+94h] [ebp-14h]
  void **v7; // [esp+98h] [ebp-10h]
  stlp_std::reverse_iterator<vostok::sound::unique_propagator_info *> v8; // [esp+9Ch] [ebp-Ch]

  thisa = this;
  current = this;
  v7 = &current;
  v8.current = this->_M_start;
  current = v8.current;
  v1 = v8.current;
  v5 = &v1;
  v6.current = this->_M_finish;
  stlp_std::_Destroy_Moved_Range<stlp_std::reverse_iterator<vostok::sound::unique_propagator_info *>>(v6, v8);
  if ( thisa->_M_start )
  {
    v4 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
    vostok::memory::base_allocator::free_impl(thisa->_M_end_of_storage.m_allocator, thisa->_M_start);
  }
}
