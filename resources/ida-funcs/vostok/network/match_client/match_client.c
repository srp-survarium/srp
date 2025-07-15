void __thiscall vostok::network::match_client::match_client(
        vostok::network::match_client *this,
        vostok::network::match_client *world,
        vostok::network::network_world *packets_orderer,
        vostok::network_core::udp_match_packets_orderer *options,
        int a5)
{
  void (__thiscall *m_orders_allocator)(vostok::network::world *); // esi
  char *v7; // eax
  vostok::network_core::udp_match_packets_allocator *v8; // ecx
  int v9; // esi
  vostok::network_core::udp_match_packets_allocator *v10; // eax
  vostok::network_core::udp_match_stats *v11; // ecx
  void (__thiscall *v12)(vostok::network::world *); // esi
  char *v13; // eax
  vostok::network::match_client_impl **v14; // eax
  vostok::memory::base_allocator *v15; // esi
  char *v16; // eax
  boost::function<void __cdecl(void)> *v17; // ecx
  __int32 v18; // esi
  vostok::network::network_world *m_world; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v20; // ecx
  vostok::memory::base_allocator *v21; // esi
  char *v22; // eax
  boost::function<void __cdecl(void)> *v23; // ecx
  __int32 v24; // esi
  vostok::network::network_world *v25; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v26; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::match_client,vostok::network_core::udp_network_flow_emulator_options const *>,boost::_bi::list2<boost::_bi::value<vostok::network::match_client *>,boost::_bi::value<vostok::network_core::udp_network_flow_emulator_options const *> > > v27; // [esp-10h] [ebp-50h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::match_client>,boost::_bi::list1<boost::_bi::value<vostok::network::match_client *> > > v28; // [esp-8h] [ebp-48h]
  int v29; // [esp+0h] [ebp-40h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v30; // [esp+10h] [ebp-30h] BYREF
  void (__thiscall *v31)(vostok::network::match_client *, const vostok::network_core::udp_network_flow_emulator_options *); // [esp+34h] [ebp-Ch]
  vostok::network::match_client *v32; // [esp+38h] [ebp-8h]
  int v33; // [esp+3Ch] [ebp-4h]
  char v34; // [esp+48h] [ebp+8h]
  int v35; // [esp+4Ch] [ebp+Ch]
  int v36; // [esp+4Ch] [ebp+Ch]

  v34 = 0;
  m_orders_allocator = (void (__thiscall *)(vostok::network::world *))packets_orderer->m_orders_allocator;
  v7 = type_info::raw_name(&vostok::network::udp_match_fixed_packets_allocator<256> `RTTI Type Descriptor');
  v9 = (*(int (__thiscall **)(void (__thiscall *)(vostok::network::world *), _UNKNOWN **, char *, const char *, const char *, int))(*(_DWORD *)m_orders_allocator + 16))(
         m_orders_allocator,
         &off_55440,
         v7,
         "vostok::network::match_client::match_client",
         ".\\match_client.cpp",
         76);
  if ( v9 )
  {
    vostok::network_core::udp_match_packets_allocator::udp_match_packets_allocator(
      v8,
      v9,
      packets_orderer->m_orders_allocator,
      (vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy>::node *)(v9 + 64),
      (unsigned int)&loc_553FD + 3);
    v10 = (vostok::network_core::udp_match_packets_allocator *)v9;
  }
  else
  {
    v10 = 0;
  }
  vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>(
    &world->m_order_packets_allocator,
    v10,
    (vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> *)v8);
  world->m_response_packets_allocator.m_object = 0;
  vostok::network_core::udp_match_stats::udp_match_stats(v11, &world->m_stats.sent.packets.count);
  world->m_on_connected.vtable = 0;
  world->m_on_packet_received.vtable = 0;
  world->m_on_disconnected.vtable = 0;
  world->m_packets_orderer = options;
  world->m_world = packets_orderer;
  v12 = (void (__thiscall *)(vostok::network::world *))packets_orderer->m_orders_allocator;
  v13 = type_info::raw_name(&vostok::network::match_client_impl * `RTTI Type Descriptor');
  v14 = (vostok::network::match_client_impl **)(*(int (__thiscall **)(void (__thiscall *)(vostok::network::world *), int, char *, const char *, const char *, int))(*(_DWORD *)v12 + 16))(
                                                 v12,
                                                 4,
                                                 v13,
                                                 "vostok::network::match_client::match_client",
                                                 ".\\match_client.cpp",
                                                 87);
  world->m_client = v14;
  *v14 = 0;
  v15 = world->m_world->m_orders_allocator;
  v16 = type_info::raw_name(&vostok::network::functor_order `RTTI Type Descriptor');
  v35 = (int)v15->call_malloc(v15, 48u, v16, "vostok::network::match_client::match_client", ".\\match_client.cpp", 92u);
  if ( v35 )
  {
    v28.l_.a1_.t_ = world;
    v28.f_.f_ = vostok::network::match_client::create_responses_packets_allocator;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      v17,
      (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::match_client>,boost::_bi::list1<boost::_bi::value<vostok::network::match_client *> > > *)&v30,
      v28,
      v29);
    v18 = v35;
    *(_DWORD *)(v35 + 4) = world->m_world->m_orders_allocator;
    v34 = 1;
    *(_DWORD *)v35 = &vostok::network::functor_order::`vftable';
    boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
      &v30,
      (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)(v35 + 16));
  }
  else
  {
    v18 = 0;
  }
  m_world = world->m_world;
  *(_DWORD *)(v18 + 8) = 0;
  m_world = (vostok::network::network_world *)((char *)m_world + 148);
  v20 = (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)_InterlockedExchange(
                                                                                          (volatile __int32 *)&m_world->tick,
                                                                                          v18);
  m_world->__vftable = (vostok::network::network_world_vtbl *)v18;
  if ( (v34 & 1) != 0 )
  {
    v34 &= ~1u;
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v20,
      (int *)&v30);
  }
  v21 = world->m_world->m_orders_allocator;
  v22 = type_info::raw_name(&vostok::network::functor_order `RTTI Type Descriptor');
  v36 = (int)v21->call_malloc(v21, 48u, v22, "vostok::network::match_client::match_client", ".\\match_client.cpp", 98u);
  if ( v36 )
  {
    v33 = a5;
    v31 = vostok::network::match_client::create_client;
    v32 = world;
    v27.l_.a1_.t_ = (vostok::network::match_client *)vostok::network::match_client::create_client;
    v27.l_.a2_.t_ = (const vostok::network_core::udp_network_flow_emulator_options *)world;
    v27.f_.f_ = (void (__thiscall *)(vostok::network::match_client *, const vostok::network_core::udp_network_flow_emulator_options *))&v30;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v23, v27, a5);
    v24 = v36;
    v34 |= 2u;
    *(_DWORD *)(v36 + 4) = world->m_world->m_orders_allocator;
    *(_DWORD *)v36 = &vostok::network::functor_order::`vftable';
    boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
      &v30,
      (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)(v36 + 16));
  }
  else
  {
    v24 = 0;
  }
  v25 = world->m_world;
  *(_DWORD *)(v24 + 8) = 0;
  v25 = (vostok::network::network_world *)((char *)v25 + 148);
  v26 = (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)_InterlockedExchange(
                                                                                          (volatile __int32 *)&v25->tick,
                                                                                          v24);
  v25->__vftable = (vostok::network::network_world_vtbl *)v24;
  if ( (v34 & 2) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v26,
      (int *)&v30);
}
