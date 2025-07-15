void __userpurge vostok::network::match_client::enqueue(
        vostok::network::match_client *this@<ecx>,
        int a2@<eax>,
        vostok::network_core::udp_match_packet *packet)
{
  int v4; // esi
  char *v5; // eax
  __int32 v6; // eax
  int v7; // edi
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v8; // ecx
  boost::_bi::bind_t<void,void (__cdecl*)(vostok::network::match_client_impl * *,vostok::network_core::udp_match_packet &),boost::_bi::list2<boost::_bi::value<vostok::network::match_client_impl * *>,boost::arg<1> > > v9; // [esp-4h] [ebp-40h]
  int v10; // [esp+4h] [ebp-38h]
  char v11; // [esp+14h] [ebp-28h]
  vostok::network::enqueue_order *v12; // [esp+18h] [ebp-24h]
  boost::function<void __cdecl(vostok::network_core::udp_match_packet &)> v13; // [esp+1Ch] [ebp-20h] BYREF

  v11 = 0;
  v4 = *(_DWORD *)(*(_DWORD *)(a2 + 236) + 284);
  v5 = type_info::raw_name(&vostok::network::enqueue_order `RTTI Type Descriptor');
  v12 = (vostok::network::enqueue_order *)(*(int (__thiscall **)(int, int, char *, const char *, const char *, int))(*(_DWORD *)v4 + 16))(
                                            v4,
                                            192,
                                            v5,
                                            "vostok::network::match_client::enqueue",
                                            ".\\match_client.cpp",
                                            243);
  if ( v12 )
  {
    v9.l_.a1_.t_ = *(vostok::network::match_client_impl ***)(a2 + 240);
    v9.f_ = (void (__cdecl *)(vostok::network::match_client_impl **, vostok::network_core::udp_match_packet *))vostok::network::enqueue_impl;
    boost::function<void __cdecl (vostok::network_core::udp_match_packet &)>::function<void __cdecl (vostok::network_core::udp_match_packet &)>(
      (boost::function<void __cdecl(vostok::network_core::udp_match_packet &)> *)vostok::network::enqueue_impl,
      (boost::_bi::bind_t<void,void (__cdecl*)(vostok::network::match_client_impl * *,vostok::network_core::udp_match_packet &),boost::_bi::list2<boost::_bi::value<vostok::network::match_client_impl * *>,boost::arg<1> > > *)&v13,
      v9,
      v10);
    v11 = 1;
    vostok::network::enqueue_order::enqueue_order(
      *(vostok::memory::base_allocator **)(*(_DWORD *)(a2 + 236) + 284),
      &v13,
      v12,
      packet,
      (const vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> *)a2,
      (const vostok::network_core::udp_match_stats *)((char *)&loc_55E22 + **(_DWORD **)(a2 + 240) + 2),
      (vostok::network_core::udp_match_stats *)(a2 + 8));
  }
  else
  {
    v6 = 0;
  }
  v7 = *(_DWORD *)(a2 + 236);
  *(_DWORD *)(v6 + 8) = 0;
  v7 += 148;
  v8 = (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)_InterlockedExchange(
                                                                                         (volatile __int32 *)(*(_DWORD *)v7 + 8),
                                                                                         v6);
  *(_DWORD *)v7 = v6;
  if ( (v11 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v8,
      (int *)&v13);
}
