void __thiscall vostok::network::match_client::match_client(
        vostok::network::match_client *this,
        vostok::network::network_world *world,
        vostok::network_core::udp_match_packets_orderer *packets_orderer,
        vostok::network_core::tcp_packet *options)
{
  survarium::game_camera *v4; // ecx
  vostok::memory::base_allocator *v5; // eax
  vostok::network_core::udp_match_stats *v6; // ecx
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v7; // ecx
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v8; // ecx
  survarium::game_camera *v9; // ecx
  vostok::memory::base_allocator *v10; // eax
  survarium::game_camera *m_client; // ecx
  survarium::game_camera *v12; // ecx
  vostok::memory::base_allocator *v13; // eax
  survarium::game_camera *v14; // ecx
  survarium::game_camera *v15; // ecx
  vostok::memory::base_allocator *v16; // eax
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::network_core::tcp_packet_socket<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > >,vostok::network_core::tcp_packet const *,boost::system::error_code const &,unsigned int>,boost::_bi::list4<boost::_bi::value<vostok::network_core::tcp_packet_socket<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > > *>,boost::_bi::value<vostok::network_core::tcp_packet *>,boost::arg<1>,boost::arg<2> > > v18; // [esp+10h] [ebp-CCh]
  void *v19; // [esp+1Ch] [ebp-C0h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::match_client>,boost::_bi::list1<boost::_bi::value<vostok::network::match_client *> > > f; // [esp+30h] [ebp-ACh]
  void *v21; // [esp+38h] [ebp-A4h]
  void *v22; // [esp+4Ch] [ebp-90h]
  vostok::memory::base_allocator *allocator; // [esp+5Ch] [ebp-80h]
  void *_Where; // [esp+60h] [ebp-7Ch]
  char v25; // [esp+6Ch] [ebp-70h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_voice,void *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_voice *>,boost::_bi::value<void *> > > v26; // [esp+70h] [ebp-6Ch] BYREF
  boost::function0<void> v27; // [esp+7Ch] [ebp-60h] BYREF
  vostok::network::response *v28; // [esp+A0h] [ebp-3Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > result; // [esp+A4h] [ebp-38h] BYREF
  boost::function0<void> v30; // [esp+ACh] [ebp-30h] BYREF
  vostok::network::order *v31; // [esp+D0h] [ebp-Ch]
  vostok::network::match_client_impl **v32; // [esp+D4h] [ebp-8h]
  vostok::network_core::udp_match_packets_allocator *v33; // [esp+D8h] [ebp-4h]

  v25 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>>::owner_allocator(&world->m_channel.orders);
  survarium::weapon_user_dead_state::finalize(v4);
  _Where = vostok::memory::base_allocator::malloc_impl(v5, (unsigned int)&loc_25800F + 5);
  v33 = (vostok::network_core::udp_match_packets_allocator *)operator new((unsigned int)&loc_25800F + 5, _Where);
  if ( v33 )
  {
    allocator = vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>>::owner_allocator(&world->m_channel.orders);
    vostok::network_core::udp_match_packets_allocator::udp_match_packets_allocator(
      v33,
      allocator,
      &v33[1],
      (unsigned int)&loc_257FFD + 3);
    vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>(
      (vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> *)v33,
      (vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> **)this);
  }
  else
  {
    vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>(
      0,
      (vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> **)this);
  }
  vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>(
    0,
    (vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> **)&this->m_response_packets_allocator);
  vostok::network_core::udp_match_stats::udp_match_stats(v6, &this->m_stats.sent.packets.count);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v7, &this->m_on_connected.vtable);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v8, &this->m_on_packet_received.vtable);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    &this->m_on_disconnected,
    &this->m_on_disconnected.vtable);
  this->m_packets_orderer = packets_orderer;
  this->m_world = world;
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>>::owner_allocator(&world->m_channel.orders);
  survarium::weapon_user_dead_state::finalize(v9);
  v22 = vostok::memory::base_allocator::malloc_impl(v10, 4u);
  v32 = (vostok::network::match_client_impl **)operator new(4u, v22);
  this->m_client = v32;
  m_client = (survarium::game_camera *)this->m_client;
  m_client->__vftable = 0;
  survarium::weapon_user_dead_state::finalize(m_client);
  survarium::weapon_user_dead_state::finalize(v12);
  v21 = vostok::memory::base_allocator::malloc_impl(v13, 0x28u);
  v31 = (vostok::network::order *)operator new(0x28u, v21);
  if ( v31 )
  {
    f = (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::match_client>,boost::_bi::list1<boost::_bi::value<vostok::network::match_client *> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&result, (void (__thiscall *)(vostok::sound::sound_debug_stats *))vostok::network::match_client::create_responses_packets_allocator, (vostok::sound::sound_debug_stats *)this);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)f.f_.f_,
      &v30);
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::match_client>,boost::_bi::list1<boost::_bi::value<vostok::network::match_client *>>>>(
      &v30,
      f);
    v25 = 1;
    vostok::network::order::order(v31);
    v31->__vftable = (vostok::network::order_vtbl *)&vostok::network::functor_order::`vftable';
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function<void __cdecl(void)> *)&v31[1],
      (const boost::function<void __cdecl(void)> *)&v30);
    vostok::network::network_world::add_order(this->m_world, (vostok::network::response *)v31);
  }
  else
  {
    vostok::network::network_world::add_order(this->m_world, 0);
  }
  v14 = (survarium::game_camera *)(v25 & 1);
  if ( (v25 & 1) != 0 )
  {
    v25 &= ~1u;
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v30);
  }
  survarium::weapon_user_dead_state::finalize(v14);
  survarium::weapon_user_dead_state::finalize(v15);
  v19 = vostok::memory::base_allocator::malloc_impl(v16, 0x28u);
  v28 = (vostok::network::response *)operator new(0x28u, v19);
  if ( v28 )
  {
    v18 = *boost::bind<void,vostok::network::match_client,vostok::network_core::udp_network_flow_emulator_options const *,vostok::network::match_client *,vostok::network_core::udp_network_flow_emulator_options const *>(
             (boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::network_core::tcp_packet_socket<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > >,vostok::network_core::tcp_packet const *,boost::system::error_code const &,unsigned int>,boost::_bi::list4<boost::_bi::value<vostok::network_core::tcp_packet_socket<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > > *>,boost::_bi::value<vostok::network_core::tcp_packet *>,boost::arg<1>,boost::arg<2> > > *)&v26,
             (void (__thiscall *)(vostok::sound::sound_voice *, void *))vostok::network::match_client::create_client,
             (vostok::sound::sound_voice *)this,
             options);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v18.l_.a1_.t_,
      &v27);
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::match_client,vostok::network_core::udp_network_flow_emulator_options const *>,boost::_bi::list2<boost::_bi::value<vostok::network::match_client *>,boost::_bi::value<vostok::network_core::udp_network_flow_emulator_options const *>>>>(
      &v27,
      (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::match_client,vostok::network_core::udp_network_flow_emulator_options const *>,boost::_bi::list2<boost::_bi::value<vostok::network::match_client *>,boost::_bi::value<vostok::network_core::udp_network_flow_emulator_options const *> > >)v18);
    v25 |= 2u;
    survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v28->next_for_responses);
    v28->__vftable = (vostok::network::response_vtbl *)&vostok::network::order::`vftable';
    v28->__vftable = (vostok::network::response_vtbl *)&vostok::network::functor_order::`vftable';
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function<void __cdecl(void)> *)&v28[1],
      (const boost::function<void __cdecl(void)> *)&v27);
    vostok::network::network_world::add_order(this->m_world, v28);
  }
  else
  {
    vostok::network::network_world::add_order(this->m_world, 0);
  }
  if ( (v25 & 2) != 0 )
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v27);
}
