void __thiscall vostok::network::tcp_packet_client::set_on_disconnected(
        vostok::network::tcp_packet_client *this,
        const boost::function<void __cdecl(void)> *on_disconnected)
{
  boost::function<void __cdecl (void)>::operator=(&this->m_on_disconnected, on_disconnected);
}
