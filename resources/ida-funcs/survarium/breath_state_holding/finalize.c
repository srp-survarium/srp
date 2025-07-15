void __thiscall survarium::breath_state_holding::finalize(survarium::breath_state_holding *this)
{
  boost::function<void __cdecl(bool)> *p_m_callback; // eax
  int v2; // ecx

  p_m_callback = &this->m_callback;
  *this->m_breath_holding_reserve = this->m_user->m_breath_vibration_params.max_breath_holding_time;
  v2 = -(this->m_callback.vtable != 0);
  if ( ((unsigned int)vostok::memory::process_allocator::finalize_impl & v2) != 0 )
    boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
      (boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *)v2,
      p_m_callback,
      0);
}
