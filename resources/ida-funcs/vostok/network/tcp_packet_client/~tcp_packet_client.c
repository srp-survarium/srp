void __usercall vostok::network::tcp_packet_client::~tcp_packet_client(
        vostok::network::tcp_packet_client *this@<ecx>,
        int a2@<edi>)
{
  int v2; // eax
  int v3; // esi
  char *v4; // eax
  __int32 v5; // ebx
  int v6; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v7; // ecx
  bool v8; // zf
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v9; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v10; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v11; // ecx
  boost::_bi::bind_t<void,void (__cdecl*)(vostok::network_core::tcp_packet_client *),boost::_bi::list1<boost::_bi::value<vostok::network_core::tcp_packet_client *> > > v12; // [esp-8h] [ebp-38h]
  int v13; // [esp+0h] [ebp-30h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v14; // [esp+8h] [ebp-28h] BYREF
  int v15; // [esp+2Ch] [ebp-4h]

  v2 = *(_DWORD *)(a2 + 128);
  v15 = 0;
  v3 = *(_DWORD *)(v2 + 284);
  v4 = type_info::raw_name(&vostok::network::functor_order `RTTI Type Descriptor');
  v5 = (*(int (__thiscall **)(int, int, char *, const char *, const char *, int))(*(_DWORD *)v3 + 16))(
         v3,
         48,
         v4,
         "vostok::network::tcp_packet_client::~tcp_packet_client",
         ".\\tcp_packet_client.cpp",
         43);
  if ( v5 )
  {
    v12.l_.a1_.t_ = *(vostok::network_core::tcp_packet_client **)(a2 + 132);
    v12.f_ = destroy_client_0;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function<void __cdecl(void)> *)destroy_client_0,
      (boost::_bi::bind_t<void,void (__cdecl*)(vostok::network_core::tcp_packet_client *),boost::_bi::list1<boost::_bi::value<vostok::network_core::tcp_packet_client *> > > *)&v14,
      v12,
      v13);
    *(_DWORD *)(v5 + 4) = *(_DWORD *)(*(_DWORD *)(a2 + 128) + 284);
    v15 = 1;
    *(_DWORD *)v5 = &vostok::network::functor_order::`vftable';
    boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
      &v14,
      (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)(v5 + 16));
  }
  else
  {
    v5 = 0;
  }
  v6 = *(_DWORD *)(a2 + 128);
  *(_DWORD *)(v5 + 8) = 0;
  v6 += 148;
  v7 = (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)_InterlockedExchange(
                                                                                         (volatile __int32 *)(*(_DWORD *)v6 + 8),
                                                                                         v5);
  v8 = (v15 & 1) == 0;
  *(_DWORD *)v6 = v5;
  if ( !v8 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v7,
      (int *)&v14);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v7,
    (int *)(a2 + 96));
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v9,
    (int *)(a2 + 64));
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v10,
    (int *)(a2 + 32));
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v11,
    (int *)a2);
}
