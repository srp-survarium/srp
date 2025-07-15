void __thiscall survarium::network_client::~network_client(survarium::network_client *this)
{
  survarium::base_match_client *m_match_client; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v7; // ecx
  vostok::memory::doug_lea_allocator *v8; // esi
  vostok::memory::doug_lea_allocator *v9; // ecx
  survarium::game_statistics_handler *v10; // ecx
  vostok::network::http_client *v11; // ecx
  survarium::messaging_client *v12; // ecx
  survarium::lobby_client *v13; // ecx
  vostok::network::login_client *v14; // ecx
  const char *v15; // [esp+0h] [ebp-30h]
  const char *v16; // [esp+4h] [ebp-2Ch]
  unsigned int v17; // [esp+8h] [ebp-28h]
  char *v18; // [esp+Ch] [ebp-24h]
  boost::function<void __cdecl(void)> v19; // [esp+10h] [ebp-20h] BYREF

  m_match_client = this->m_match_client;
  this->__vftable = (survarium::network_client_vtbl *)&survarium::network_client::`vftable';
  v19.vtable = 0;
  m_match_client->set_on_packet_received(
    m_match_client,
    (const boost::function<void __cdecl(unsigned char,vostok::network_core::buffer_reader &)> *)&v19);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v3,
    (int *)&v19);
  v19.vtable = 0;
  boost::function<void __cdecl (boost::system::error_code)>::operator=(
    (boost::function<void __cdecl(vostok::network_core::buffer_reader &)> *)&v19,
    (boost::function1<void,vostok::physics::contact_point const &> *)&this->m_lobby_client.m_on_packet_received);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v4,
    (int *)&v19);
  v19.vtable = 0;
  boost::function<void __cdecl (void)>::operator=(
    &v19,
    (boost::function1<void,vostok::physics::contact_point const &> *)&this->m_lobby_client.m_on_connected);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v5,
    (int *)&v19);
  v19.vtable = 0;
  boost::function<void __cdecl (void)>::operator=(
    &v19,
    (boost::function1<void,vostok::physics::contact_point const &> *)&this->m_lobby_client.m_on_disconnected);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v6,
    (int *)&v19);
  v19.vtable = 0;
  boost::function<void __cdecl (boost::system::error_code)>::operator=(
    (boost::function<void __cdecl(vostok::network_core::buffer_reader &)> *)&v19,
    (boost::function1<void,vostok::physics::contact_point const &> *)&this->m_http_client.m_on_error);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v7,
    (int *)&v19);
  v8 = survarium::g_allocator;
  if ( this->m_match_client )
  {
    v18 = __RTCastToVoid((void **)&this->m_match_client->__vftable);
    ((void (__thiscall *)(survarium::base_match_client *, _DWORD))this->m_match_client->~survarium::base_match_client)(
      this->m_match_client,
      0);
    vostok::memory::doug_lea_allocator::free_impl(v9, (int)v8, v18, v15, v16, v17);
    this->m_match_client = 0;
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_local_player);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_match);
  survarium::game_statistics_handler::~game_statistics_handler(v10, (int)&this->m_game_statistics);
  vostok::network::http_client::~http_client(v11, (int *)&this->m_http_client);
  survarium::messaging_client::~messaging_client(v12, (int)&this->m_messaging_client);
  survarium::lobby_client::~lobby_client(v13, (int)this->m_lobby_client.account_nickname);
  vostok::network::login_client::~login_client(v14, (int)&this->m_login_client);
  survarium::base_network_client::~base_network_client(this);
}
