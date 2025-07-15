void __thiscall survarium::breath_state_holding::initialize(survarium::breath_state_holding *this)
{
  boost::function<void __cdecl(bool)> *p_m_callback; // eax
  int v2; // ecx

  p_m_callback = &this->m_callback;
  v2 = -(this->m_callback.vtable != 0);
  if ( ((unsigned int)vostok::memory::process_allocator::finalize_impl & v2) != 0 )
    boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
      (boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *)v2,
      p_m_callback,
      (const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *)1);
}
