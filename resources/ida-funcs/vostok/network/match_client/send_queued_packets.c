void __thiscall vostok::network::match_client::send_queued_packets(
        vostok::network::match_client *this,
        _DWORD *current_time_in_ms,
        int a3)
{
  _DWORD *v3; // edi
  int v4; // esi
  char *v5; // eax
  boost::function<void __cdecl(void)> *v6; // ecx
  __int32 v7; // ebx
  int v8; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v9; // ecx
  bool v10; // zf
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::match_client_impl,unsigned int>,boost::_bi::list2<boost::reference_wrapper<vostok::network::match_client_impl *>,boost::_bi::value<unsigned int> > > v11; // [esp-10h] [ebp-4Ch]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> f; // [esp+Ch] [ebp-30h] BYREF
  void (__thiscall *v13)(vostok::network::match_client_impl *, boost::function<void __cdecl(vostok::network_core::udp_match_packet &,boost::function<void __cdecl(vostok::network_core::udp_match_packet &,boost::system::error_code const &,unsigned int)> const &)> *); // [esp+2Ch] [ebp-10h]
  unsigned int v14; // [esp+30h] [ebp-Ch]
  int v15; // [esp+34h] [ebp-8h]
  int v16; // [esp+38h] [ebp-4h]
  int v17; // [esp+48h] [ebp+Ch]

  v16 = 0;
  v3 = current_time_in_ms;
  v4 = *(_DWORD *)(current_time_in_ms[59] + 284);
  v5 = type_info::raw_name(&vostok::network::send_queued_order `RTTI Type Descriptor');
  v7 = (*(int (__thiscall **)(int, int, char *, const char *, const char *, int))(*(_DWORD *)v4 + 16))(
         v4,
         184,
         v5,
         "vostok::network::match_client::send_queued_packets",
         ".\\match_client.cpp",
         283);
  if ( v7 )
  {
    v14 = current_time_in_ms[60];
    v15 = a3;
    v13 = vostok::network::match_client_impl::send_queued_packets;
    v11.l_.a1_.t_ = (vostok::network::match_client_impl **)vostok::network::match_client_impl::send_queued_packets;
    v11.l_.a2_.t_ = v14;
    v11.f_.f_ = (void (__thiscall *)(vostok::network::match_client_impl *, unsigned int))&f;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v6, v11, a3);
    v17 = current_time_in_ms[60];
    *(_DWORD *)(v7 + 4) = *(_DWORD *)(current_time_in_ms[59] + 284);
    *(_DWORD *)v7 = &vostok::network::send_queued_order::`vftable';
    qmemcpy((void *)(v7 + 12), current_time_in_ms + 2, 0x80u);
    v16 = 1;
    boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
      &f,
      (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)(v7 + 144));
    v3 = current_time_in_ms;
    *(_DWORD *)(v7 + 176) = current_time_in_ms + 2;
    *(_DWORD *)(v7 + 180) = v17;
  }
  else
  {
    v7 = 0;
  }
  v8 = v3[59];
  *(_DWORD *)(v7 + 8) = 0;
  v8 += 148;
  v9 = (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)_InterlockedExchange(
                                                                                         (volatile __int32 *)(*(_DWORD *)v8 + 8),
                                                                                         v7);
  v10 = (v16 & 1) == 0;
  *(_DWORD *)v8 = v7;
  if ( !v10 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v9,
      (int *)&f);
}
