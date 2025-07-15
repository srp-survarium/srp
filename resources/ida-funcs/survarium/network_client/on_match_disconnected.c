void __thiscall survarium::network_client::on_match_disconnected(
        survarium::network_client *this,
        vostok::network_core::disconnect_event_types_enum disconnect_event_type)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  int v4[9]; // [esp+8h] [ebp-24h] BYREF

  v4[0] = 0;
  this->m_match_client->set_on_disconnect(
    this->m_match_client,
    (const boost::function<void __cdecl(enum vostok::network_core::disconnect_event_types_enum)> *)v4);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v3, v4);
  this->close_current_match(this, disconnect_event_type);
}
