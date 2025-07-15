void __thiscall vostok::network::tcp_packet_client::on_packet_received(
        vostok::network::tcp_packet_client *this,
        const vostok::network_core::tcp_packet *packet)
{
  vostok::network_core::mutable_buffer *v2; // ebx
  vostok::memory::doug_lea_allocator *v3; // esi
  char *v4; // eax
  vostok::memory::doug_lea_allocator *v5; // ecx
  char *v6; // eax
  vostok::network_core::tcp_packet *v7; // ecx
  vostok::network_core::mutable_buffer *v8; // eax
  vostok::memory::doug_lea_allocator *v9; // esi
  char *v10; // eax
  vostok::memory::doug_lea_allocator *v11; // ecx
  boost::function<void __cdecl(vostok::network_core::buffer_reader &)> *v12; // ecx
  char *v13; // edi
  vostok::network::network_world *m_world; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v15; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::tcp_packet_client,vostok::network_core::buffer_reader &>,boost::_bi::list2<boost::_bi::value<vostok::network::tcp_packet_client *>,boost::arg<1> > > v16; // [esp-8h] [ebp-40h]
  const char *v17; // [esp+0h] [ebp-38h]
  const char *v18; // [esp+0h] [ebp-38h]
  int v19; // [esp+0h] [ebp-38h]
  const char *v20; // [esp+4h] [ebp-34h]
  const char *v21; // [esp+4h] [ebp-34h]
  unsigned int v22; // [esp+8h] [ebp-30h]
  unsigned int v23; // [esp+8h] [ebp-30h]
  char v25; // [esp+14h] [ebp-24h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v26; // [esp+18h] [ebp-20h] BYREF

  v2 = 0;
  v25 = 0;
  if ( this->m_on_packet_received.vtable )
  {
    v3 = vostok::network::g_allocator;
    v4 = type_info::raw_name(&vostok::network_core::tcp_packet `RTTI Type Descriptor');
    v6 = vostok::memory::doug_lea_allocator::malloc_impl(v5, (int)v3, 0x28u, v4, v17, v20, v22);
    if ( v6 )
    {
      vostok::network_core::tcp_packet::tcp_packet(
        (vostok::network_core::tcp_packet *)vostok::network::g_allocator,
        (int)v6);
      v2 = v8;
    }
    vostok::network_core::tcp_packet::clone(v7, v2, packet);
    v9 = vostok::network::g_allocator;
    v10 = type_info::raw_name(&vostok::network::receive_response `RTTI Type Descriptor');
    v13 = vostok::memory::doug_lea_allocator::malloc_impl(v11, (int)v9, 0x38u, v10, v18, v21, v23);
    if ( v13 )
    {
      v16.l_.a1_.t_ = this;
      v16.f_.f_ = (void (__thiscall *)(vostok::network::tcp_packet_client *, vostok::network_core::buffer_reader *))vostok::network::tcp_packet_client::on_packet_received_impl;
      boost::function<void __cdecl (vostok::network_core::buffer_reader &)>::function<void __cdecl (vostok::network_core::buffer_reader &)>(
        v12,
        (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::tcp_packet_client,vostok::network_core::buffer_reader &>,boost::_bi::list2<boost::_bi::value<vostok::network::tcp_packet_client *>,boost::arg<1> > > *)&v26,
        v16,
        v19);
      *((_DWORD *)v13 + 1) = vostok::network::g_allocator;
      v25 = 1;
      *(_DWORD *)v13 = &vostok::network::receive_response::`vftable';
      boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
        &v26,
        (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)(v13 + 16));
      *((_DWORD *)v13 + 12) = v2;
    }
    else
    {
      v13 = 0;
    }
    m_world = this->m_world;
    *((_DWORD *)v13 + 2) = 0;
    m_world = (vostok::network::network_world *)((char *)m_world + 12);
    v15 = (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)_InterlockedExchange(
                                                                                            (volatile __int32 *)&m_world->tick,
                                                                                            (__int32)v13);
    m_world->__vftable = (vostok::network::network_world_vtbl *)v13;
    if ( (v25 & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        v15,
        (int *)&v26);
  }
}
