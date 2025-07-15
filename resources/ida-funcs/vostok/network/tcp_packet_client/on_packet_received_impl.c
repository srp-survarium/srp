void __thiscall vostok::network::tcp_packet_client::on_packet_received_impl(
        vostok::network::tcp_packet_client *this,
        const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *reader)
{
  int v2; // ecx

  v2 = -(this->m_on_packet_received.vtable != 0);
  if ( ((unsigned int)vostok::memory::process_allocator::finalize_impl & v2) != 0 )
    boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
      (boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *)v2,
      reader);
}
