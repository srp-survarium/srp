void __thiscall vostok::network::match_client_impl::~match_client_impl(
        vostok::network::match_client_impl *this,
        int a2)
{
  char *v2; // esi
  vostok::memory::doug_lea_allocator *v3; // edi
  vostok::memory::doug_lea_allocator *v4; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  vostok::network_core::udp_match_client *v6; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v7; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v8; // ecx
  const char *v9; // [esp+0h] [ebp-Ch]
  const char *v10; // [esp+4h] [ebp-8h]
  unsigned int v11; // [esp+8h] [ebp-4h]

  v2 = *(char **)((char *)&loc_55457 + a2 + 1);
  v3 = vostok::network::g_allocator;
  if ( v2 )
  {
    vostok::network_core::udp_network_flow_emulator::~udp_network_flow_emulator(
      (vostok::network_core::udp_network_flow_emulator *)this,
      (int)v2);
    vostok::memory::doug_lea_allocator::free_impl(v4, (int)v3, v2, v9, v10, v11);
    *(_DWORD *)((char *)&loc_55457 + a2 + 1) = 0;
  }
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
    (int *)((char *)&loc_6EF60 + a2));
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v5,
    (int *)((char *)&loc_6EF3F + a2 + 1));
  vostok::network_core::udp_match_client::~udp_match_client(v6, (int *)((char *)&loc_5545C + a2 + 4));
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v7,
    (int *)((char *)&off_55438 + a2));
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v8,
    (int *)((char *)&loc_553FD + a2 + 3));
}
