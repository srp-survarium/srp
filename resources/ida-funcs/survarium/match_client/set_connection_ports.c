void __thiscall survarium::match_client::set_connection_ports(
        survarium::match_client *this,
        char ping_message_type,
        int session_id,
        unsigned __int16 first_port,
        __int16 last_port)
{
  vostok::network::match_client::set_connection_ports(
    &this->m_client,
    (int)&this->m_client,
    ping_message_type,
    session_id,
    first_port,
    last_port);
}
