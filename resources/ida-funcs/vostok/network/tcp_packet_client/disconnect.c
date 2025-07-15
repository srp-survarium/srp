void __thiscall vostok::network::tcp_packet_client::disconnect(vostok::network::tcp_packet_client *this, int a2)
{
  int v3; // eax
  int v4; // esi
  char *v5; // eax
  __int32 v6; // edi
  int v7; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v8; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network_core::tcp_packet_client>,boost::_bi::list1<boost::_bi::value<vostok::network_core::tcp_packet_client *> > > v9; // [esp-8h] [ebp-3Ch]
  int v10; // [esp+0h] [ebp-34h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v11; // [esp+10h] [ebp-24h] BYREF
  char v12; // [esp+3Ch] [ebp+8h]

  v3 = *(_DWORD *)(a2 + 128);
  v12 = 0;
  v4 = *(_DWORD *)(v3 + 284);
  v5 = type_info::raw_name(&vostok::network::functor_order `RTTI Type Descriptor');
  v6 = (*(int (__thiscall **)(int, int, char *, const char *, const char *, int))(*(_DWORD *)v4 + 16))(
         v4,
         48,
         v5,
         "vostok::network::tcp_packet_client::disconnect",
         ".\\tcp_packet_client.cpp",
         79);
  if ( v6 )
  {
    v9.l_.a1_.t_ = *(vostok::network_core::tcp_packet_client **)(a2 + 132);
    v9.f_.f_ = vostok::network_core::tcp_packet_client::disconnect;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function<void __cdecl(void)> *)vostok::network_core::tcp_packet_client::disconnect,
      (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network_core::tcp_packet_client>,boost::_bi::list1<boost::_bi::value<vostok::network_core::tcp_packet_client *> > > *)&v11,
      v9,
      v10);
    *(_DWORD *)(v6 + 4) = *(_DWORD *)(*(_DWORD *)(a2 + 128) + 284);
    v12 = 1;
    *(_DWORD *)v6 = &vostok::network::functor_order::`vftable';
    boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
      &v11,
      (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)(v6 + 16));
  }
  else
  {
    v6 = 0;
  }
  v7 = *(_DWORD *)(a2 + 128);
  *(_DWORD *)(v6 + 8) = 0;
  v7 += 148;
  v8 = (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)_InterlockedExchange(
                                                                                         (volatile __int32 *)(*(_DWORD *)v7 + 8),
                                                                                         v6);
  *(_DWORD *)v7 = v6;
  if ( (v12 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v8,
      (int *)&v11);
}
