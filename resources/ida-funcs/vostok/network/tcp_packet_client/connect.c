void __thiscall vostok::network::tcp_packet_client::connect(
        vostok::network::tcp_packet_client *this,
        const char *host,
        char *port,
        __int16 a4)
{
  int v5; // eax
  int v6; // esi
  char *v7; // eax
  boost::function<void __cdecl(char const *)> *v8; // ecx
  __int32 v9; // eax
  int v10; // ebx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v11; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network::tcp_packet_client,char const *,unsigned short>,boost::_bi::list3<boost::_bi::value<vostok::network::tcp_packet_client *>,boost::arg<1>,boost::_bi::value<unsigned short> > > v12; // [esp-10h] [ebp-5Ch]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> f; // [esp+10h] [ebp-3Ch] BYREF
  void (__thiscall *v14)(vostok::network::tcp_packet_client *, char *, boost::asio::ip::tcp); // [esp+30h] [ebp-1Ch]
  const char *v15; // [esp+34h] [ebp-18h]
  int v16; // [esp+38h] [ebp-14h]
  int v17; // [esp+40h] [ebp-Ch]
  vostok::network::string_order *v18; // [esp+44h] [ebp-8h]
  char v19; // [esp+54h] [ebp+8h]

  v5 = *((_DWORD *)host + 32);
  v19 = 0;
  v6 = *(_DWORD *)(v5 + 284);
  v7 = type_info::raw_name(&vostok::network::string_order `RTTI Type Descriptor');
  v18 = (vostok::network::string_order *)(*(int (__thiscall **)(int, int, char *, const char *, const char *, int))(*(_DWORD *)v6 + 16))(
                                           v6,
                                           128,
                                           v7,
                                           "vostok::network::tcp_packet_client::connect",
                                           ".\\tcp_packet_client.cpp",
                                           68);
  if ( v18 )
  {
    LOWORD(v17) = a4;
    v16 = v17;
    v14 = vostok::network::tcp_packet_client::connect_impl;
    v15 = host;
    v12.l_.a1_.t_ = (vostok::network::tcp_packet_client *)vostok::network::tcp_packet_client::connect_impl;
    *(_DWORD *)&v12.l_.a3_.t_ = host;
    v12.f_.f_ = (void (__thiscall *)(vostok::network::tcp_packet_client *, const char *, unsigned __int16))&f;
    boost::function<void __cdecl (char const *)>::function<void __cdecl (char const *)>(v8, v12, v17);
    v19 = 1;
    vostok::network::string_order::string_order(
      v18,
      *(vostok::memory::base_allocator **)(*((_DWORD *)host + 32) + 284),
      &f,
      port);
  }
  else
  {
    v9 = 0;
  }
  v10 = *((_DWORD *)host + 32);
  *(_DWORD *)(v9 + 8) = 0;
  v10 += 148;
  v11 = (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)_InterlockedExchange(
                                                                                          (volatile __int32 *)(*(_DWORD *)v10 + 8),
                                                                                          v9);
  *(_DWORD *)v10 = v9;
  if ( (v19 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v11,
      (int *)&f);
}
