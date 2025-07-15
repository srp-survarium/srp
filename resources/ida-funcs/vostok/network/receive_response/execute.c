void __thiscall vostok::network::receive_response::execute(vostok::network::receive_response *this)
{
  const vostok::network_core::tcp_packet *m_packet; // eax
  unsigned int m_size; // edx
  _DWORD v3[3]; // [esp+0h] [ebp-Ch] BYREF

  m_packet = this->m_packet;
  m_size = m_packet->m_buffer.m_size;
  v3[0] = m_packet->m_buffer.m_buffer + 3;
  v3[1] = v3[0];
  v3[2] = m_size - 3;
  boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
    (boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *)this,
    &this->m_receiver.vtable,
    (const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *)v3);
}
