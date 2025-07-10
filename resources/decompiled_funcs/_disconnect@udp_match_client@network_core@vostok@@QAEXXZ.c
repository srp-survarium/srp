void __thiscall vostok::network_core::udp_match_client::disconnect(vostok::network_core::udp_match_client *this)
{
  vostok::network_core::udp_match_connection::disconnect(&this->m_connection);
}
