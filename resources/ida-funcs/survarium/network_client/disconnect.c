void __thiscall survarium::network_client::disconnect(survarium::network_client *this)
{
  survarium::base_match_client *m_match_client; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  boost::function<void __cdecl(enum vostok::network_core::disconnect_event_types_enum)> v4; // [esp+10h] [ebp-20h] BYREF

  if ( this->m_game_status )
  {
    this->m_game_status = game_status_inactive;
    survarium::game_world::unload(
      (survarium::game_world *)this,
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)&this->m_game->m_game_world);
    m_match_client = this->m_match_client;
    v4.vtable = 0;
    m_match_client->set_on_disconnect(m_match_client, &v4);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v3,
      (int *)&v4);
    this->m_match_client->disconnect(this->m_match_client);
  }
  survarium::lobby_client::disconnect((survarium::lobby_client *)this, (int)this->m_lobby_client.account_nickname);
  survarium::messaging_client::disconnect(&this->m_messaging_client);
}
