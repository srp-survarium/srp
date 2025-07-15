void __thiscall vostok::network::tcp_packet_client::send(
        vostok::network::tcp_packet_client *this,
        const vostok::network_core::tcp_packet *packet,
        const vostok::network_core::tcp_packet *a3)
{
  int v4; // esi
  char *v5; // eax
  int v6; // eax
  vostok::network_core::tcp_packet *v7; // ecx
  vostok::network_core::mutable_buffer *v8; // eax
  int v9; // esi
  char *v10; // eax
  __int32 v11; // edi
  _DWORD *m_capacity; // ebx
  volatile __int32 *v13; // ecx
  bool v14; // zf
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network_core::tcp_packet_client,vostok::network_core::tcp_packet const &>,boost::_bi::list2<boost::_bi::value<vostok::network_core::tcp_packet_client *>,boost::arg<1> > > v15; // [esp-8h] [ebp-40h]
  int v16; // [esp+0h] [ebp-38h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v17; // [esp+10h] [ebp-28h] BYREF
  int v18; // [esp+34h] [ebp-4h]
  vostok::network_core::mutable_buffer *v19; // [esp+40h] [ebp+8h]

  v18 = 0;
  v4 = *(_DWORD *)(packet[3].m_buffer.m_capacity + 284);
  v5 = type_info::raw_name(&vostok::network_core::tcp_packet `RTTI Type Descriptor');
  v6 = (*(int (__thiscall **)(int, int, char *, const char *, const char *, int))(*(_DWORD *)v4 + 16))(
         v4,
         40,
         v5,
         "vostok::network::tcp_packet_client::send",
         ".\\tcp_packet_client.cpp",
         88);
  if ( v6 )
  {
    vostok::network_core::tcp_packet::tcp_packet(
      *(vostok::network_core::tcp_packet **)(packet[3].m_buffer.m_capacity + 284),
      v6);
    v19 = v8;
  }
  else
  {
    v19 = 0;
  }
  vostok::network_core::tcp_packet::clone(v7, v19, a3);
  v9 = *(_DWORD *)(packet[3].m_buffer.m_capacity + 284);
  v10 = type_info::raw_name(&vostok::network::send_order `RTTI Type Descriptor');
  v11 = (*(int (__thiscall **)(int, int, char *, const char *, const char *, int))(*(_DWORD *)v9 + 16))(
          v9,
          56,
          v10,
          "vostok::network::tcp_packet_client::send",
          ".\\tcp_packet_client.cpp",
          91);
  if ( v11 )
  {
    v15.l_.a1_.t_ = (vostok::network_core::tcp_packet_client *)packet[3].m_buffer.m_size;
    v15.f_.f_ = vostok::network_core::tcp_packet_client::send;
    boost::function<void __cdecl (vostok::network_core::tcp_packet const &)>::function<void __cdecl (vostok::network_core::tcp_packet const &)>(
      (boost::function<void __cdecl(vostok::network_core::tcp_packet const &)> *)vostok::network_core::tcp_packet_client::send,
      (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network_core::tcp_packet_client,vostok::network_core::tcp_packet const &>,boost::_bi::list2<boost::_bi::value<vostok::network_core::tcp_packet_client *>,boost::arg<1> > > *)&v17,
      v15,
      v16);
    *(_DWORD *)(v11 + 4) = *(_DWORD *)(packet[3].m_buffer.m_capacity + 284);
    v18 = 1;
    *(_DWORD *)v11 = &vostok::network::send_order::`vftable';
    boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
      &v17,
      (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)(v11 + 16));
    *(_DWORD *)(v11 + 48) = v19;
  }
  else
  {
    v11 = 0;
  }
  m_capacity = (_DWORD *)packet[3].m_buffer.m_capacity;
  *(_DWORD *)(v11 + 8) = 0;
  m_capacity += 37;
  v13 = (volatile __int32 *)(*m_capacity + 8);
  _InterlockedExchange(v13, v11);
  v14 = (v18 & 1) == 0;
  *m_capacity = v11;
  if ( !v14 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v13,
      (int *)&v17);
}
