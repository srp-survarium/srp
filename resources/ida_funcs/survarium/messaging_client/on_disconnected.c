void __thiscall survarium::messaging_client::on_disconnected(survarium::messaging_client *this)
{
  void (__cdecl *v1)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function<void __cdecl(vostok::network_core::packet_reader &)> on_packet_received; // [esp+0h] [ebp-20h] BYREF

  this->m_connection_state = client_disconnected;
  on_packet_received.vtable = 0;
  vostok::network::tcp_packet_client::set_on_packet_received(
    &this->m_network_client,
    (boost::function<void __cdecl(unsigned int,unsigned int)> *)&on_packet_received);
  if ( on_packet_received.vtable && ((int)on_packet_received.vtable & 1) == 0 )
  {
    v1 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)on_packet_received.vtable & 0xFFFFFFFE);
    if ( v1 )
      v1(&on_packet_received.functor, &on_packet_received.functor, 2);
  }
}
