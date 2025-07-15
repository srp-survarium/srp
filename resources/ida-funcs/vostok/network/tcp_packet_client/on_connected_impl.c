void __thiscall vostok::network::tcp_packet_client::on_connected_impl(vostok::network::tcp_packet_client *this)
{
  int v1; // ecx

  v1 = -(this->m_on_connected.vtable != 0);
  if ( ((unsigned int)vostok::memory::process_allocator::finalize_impl & v1) != 0 )
    boost::function0<void>::operator()((boost::function0<bool> *)v1);
}
