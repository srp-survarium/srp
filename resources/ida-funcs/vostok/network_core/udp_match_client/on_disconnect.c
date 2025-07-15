void __thiscall vostok::network_core::udp_match_client::on_disconnect(
        vostok::network_core::udp_match_client *this,
        const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *disconnect_type)
{
  bool *p_m_is_receiving; // edi
  int v4; // ecx

  p_m_is_receiving = &this->m_is_receiving;
  if ( this->m_is_receiving )
  {
    boost::asio::basic_socket<boost::asio::ip::udp,boost::asio::datagram_socket_service<boost::asio::ip::udp>>::cancel(
      (boost::asio::basic_socket<boost::asio::ip::udp,boost::asio::datagram_socket_service<boost::asio::ip::udp> > *)this,
      (int *)&this->m_socket);
    *p_m_is_receiving = 0;
  }
  v4 = -(this->m_on_disconnect.vtable != 0);
  if ( ((unsigned int)vostok::memory::process_allocator::finalize_impl & v4) != 0 )
    boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
      (boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *)v4,
      &this->m_on_disconnect.vtable,
      disconnect_type);
}
