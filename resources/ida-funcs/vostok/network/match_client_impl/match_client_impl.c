void __userpurge vostok::network::match_client_impl::match_client_impl(
        vostok::network::match_client_impl *this@<ecx>,
        vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy>::node *a2@<edi>,
        vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy> *io_service,
        vostok::network_core::udp_match_packets_orderer *packets_orderer,
        const vostok::network_core::udp_network_flow_emulator_options *options)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  vostok::network_core::udp_match_client *v6; // ecx
  vostok::memory::doug_lea_allocator *v7; // esi
  char *v8; // eax
  vostok::memory::doug_lea_allocator *v9; // ecx
  char *v10; // eax
  boost::asio::detail::service_registry *v11; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v12; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v13; // ecx
  const char *v14; // [esp+0h] [ebp-2Ch]
  vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy> *v15; // [esp+0h] [ebp-2Ch]
  const char *v16; // [esp+4h] [ebp-28h]
  boost::function<void __cdecl(unsigned char,short)> v17; // [esp+8h] [ebp-24h] BYREF

  v17.vtable = 0;
  vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy>::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy>(
    (const boost::function<void __cdecl(vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy> const &)> *)&v17,
    (vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy> *)((char *)a2 + (_DWORD)&loc_553FD + 3),
    a2,
    (unsigned int)&loc_553FD + 3);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v5,
    (int *)&v17);
  *(_UNKNOWN **)((char *)&off_55438 + (_DWORD)a2) = 0;
  if ( options
    && (v7 = vostok::network::g_allocator,
        v8 = type_info::raw_name(&vostok::network_core::udp_network_flow_emulator `RTTI Type Descriptor'),
        (v10 = vostok::memory::doug_lea_allocator::malloc_impl(
                 v9,
                 (int)v7,
                 0x30u,
                 v8,
                 v14,
                 v16,
                 (const unsigned int)v17.vtable)) != 0) )
  {
    vostok::network_core::udp_network_flow_emulator::udp_network_flow_emulator(
      (vostok::network_core::udp_network_flow_emulator *)v10,
      options,
      (vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy> *)((char *)a2 + (_DWORD)&loc_553FD + 3),
      v15);
  }
  else
  {
    v11 = 0;
  }
  *(_DWORD *)&a2->data[(_DWORD)&loc_55457 + 1] = v11;
  vostok::network_core::udp_match_client::udp_match_client(
    v6,
    (boost::asio::io_service *)((char *)a2 + (_DWORD)&loc_5545C + 4),
    (boost::asio::io_service *)io_service,
    (vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy> *)((char *)a2 + (_DWORD)&loc_553FD + 3),
    packets_orderer,
    v11);
  *(_DWORD *)&a2->data[(_DWORD)&loc_6EF3F + 1] = 0;
  *(_DWORD *)((char *)&loc_6EF60 + (_DWORD)a2) = 0;
  *(_DWORD *)((char *)&loc_6EF80 + (_DWORD)a2) = 0;
  v17.vtable = 0;
  boost::function<void __cdecl (void)>::operator=(
    (boost::function<void __cdecl(void)> *)&v17,
    (boost::function1<void,vostok::physics::contact_point const &> *)((char *)&loc_55F88 + (_DWORD)a2));
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v12,
    (int *)&v17);
  v17.vtable = 0;
  boost::function<void __cdecl (enum vostok::network_core::disconnect_event_types_enum)>::operator=(
    &v17,
    (boost::function1<void,vostok::physics::contact_point const &> *)((char *)a2 + (_DWORD)&loc_55FA7 + 1));
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v13,
    (int *)&v17);
}
