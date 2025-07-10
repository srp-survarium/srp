void __thiscall vostok::network::tcp_packet_client::set_on_connected(
        vostok::network::tcp_packet_client *this,
        const boost::function<void __cdecl(void)> *on_connected)
{
  boost::function<void __cdecl (void)>::operator=(&this->m_on_connected, on_connected);
}
