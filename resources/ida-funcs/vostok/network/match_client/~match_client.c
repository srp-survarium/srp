void __thiscall vostok::network::match_client::~match_client(vostok::network::match_client *this, int a2)
{
  int v3; // esi
  char *v4; // eax
  vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> *v5; // ecx
  vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> *v6; // ebp
  int v7; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v8; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v9; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v10; // ecx
  vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> *v11; // ecx
  vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> *v12; // ecx
  vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> *v13; // [esp+14h] [ebp+4h]

  v3 = *(_DWORD *)(*(_DWORD *)(a2 + 236) + 284);
  v4 = type_info::raw_name(&client_destroyer `RTTI Type Descriptor');
  v6 = (vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> *)(*(int (__thiscall **)(int, int, char *, const char *, const char *, int))(*(_DWORD *)v3 + 16))(v3, 20, v4, "vostok::network::match_client::~match_client", ".\\match_client.cpp", 137);
  if ( v6 )
  {
    v13 = *(vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> **)(a2 + 240);
    v6[1].m_object = *(vostok::network_core::udp_match_packets_allocator **)(*(_DWORD *)(a2 + 236) + 284);
    v6->m_object = (vostok::network_core::udp_match_packets_allocator *)&client_destroyer::`vftable';
    vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>(
      v6 + 3,
      (const vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> *)(a2 + 4),
      v13);
    v6[4].m_object = (vostok::network_core::udp_match_packets_allocator *)v13;
  }
  else
  {
    v6 = 0;
  }
  vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> *)(a2 + 4),
    0,
    v5);
  v7 = *(_DWORD *)(a2 + 236);
  v6[2].m_object = 0;
  v7 += 148;
  v8 = (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)_InterlockedExchange(
                                                                                         (volatile __int32 *)(*(_DWORD *)v7 + 8),
                                                                                         (__int32)v6);
  *(_DWORD *)v7 = v6;
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v8,
    (int *)(a2 + 200));
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v9,
    (int *)(a2 + 168));
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v10,
    (int *)(a2 + 136));
  vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>::dec(
    v11,
    (int **)(a2 + 4));
  vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>::dec(
    v12,
    (int **)a2);
}
