void __thiscall survarium::match_client::set_on_packet_received(
        survarium::match_client *this,
        boost::function<void __cdecl(void)> *on_packet_received)
{
  boost::function<void __cdecl (void)>::operator=(
    on_packet_received,
    (boost::function1<void,vostok::physics::contact_point const &> *)&this->m_client.m_on_packet_received);
}
