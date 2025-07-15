void __thiscall vostok::network::match_client::on_disconnect_impl(
        vostok::network::match_client *this,
        const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *type)
{
  boost::function<void __cdecl(enum vostok::network_core::disconnect_event_types_enum)> *p_m_on_disconnected; // eax
  int v3; // ecx

  p_m_on_disconnected = &this->m_on_disconnected;
  v3 = -(this->m_on_disconnected.vtable != 0);
  if ( ((unsigned int)vostok::memory::process_allocator::finalize_impl & v3) != 0 )
    boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
      (boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *)v3,
      p_m_on_disconnected,
      type);
}
