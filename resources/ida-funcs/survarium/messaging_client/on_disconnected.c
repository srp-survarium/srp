void __thiscall survarium::messaging_client::on_disconnected(survarium::messaging_client *this)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v1; // ecx
  boost::function<void __cdecl(vostok::network_core::buffer_reader &)> v2; // [esp+8h] [ebp-20h] BYREF

  v2.vtable = 0;
  this->m_connection_state = client_disconnected;
  boost::function<void __cdecl (boost::system::error_code)>::operator=(
    &v2,
    (boost::function1<void,vostok::physics::contact_point const &> *)&this->m_network_client);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v1,
    (int *)&v2);
}
