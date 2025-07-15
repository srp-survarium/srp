void __thiscall survarium::match_client::set_on_disconnect(
        survarium::match_client *this,
        boost::function<void __cdecl(unsigned char,short)> *on_disconnected)
{
  boost::function<void __cdecl (enum vostok::network_core::disconnect_event_types_enum)>::operator=(
    on_disconnected,
    (boost::function1<void,vostok::physics::contact_point const &> *)&this->m_client.m_on_disconnected);
}
