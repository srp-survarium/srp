void __usercall vostok::network::http_client::~http_client(vostok::network::http_client *this@<ecx>, int *a2@<edi>)
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
  boost::_bi::bind_t<void,void (__cdecl*)(vostok::network_core::http_client *),boost::_bi::list1<boost::_bi::value<vostok::network_core::http_client *> > > v11; // [esp-8h] [ebp-38h]
  int v12; // [esp+0h] [ebp-30h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v13; // [esp+8h] [ebp-28h] BYREF
  int v14; // [esp+2Ch] [ebp-4h]

  v2 = *a2;
  v14 = 0;
  *((_BYTE *)a2 + 108) = 1;
  v3 = *(_DWORD *)(v2 + 284);
  v4 = type_info::raw_name(&vostok::network::functor_order `RTTI Type Descriptor');
  v5 = (*(int (__thiscall **)(int, int, char *, const char *, const char *, int))(*(_DWORD *)v3 + 16))(
         v3,
         48,
         v4,
         "vostok::network::http_client::~http_client",
         ".\\http_client.cpp",
         45);
  if ( v5 )
  {
    v11.l_.a1_.t_ = (vostok::network_core::http_client *)a2[26];
    v11.f_ = vostok::network::destroy_http_client;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function<void __cdecl(void)> *)vostok::network::destroy_http_client,
      (boost::_bi::bind_t<void,void (__cdecl*)(vostok::network_core::http_client *),boost::_bi::list1<boost::_bi::value<vostok::network_core::http_client *> > > *)&v13,
      v11,
      v12);
    *(_DWORD *)(v5 + 4) = *(_DWORD *)(*a2 + 284);
    v14 = 1;
    *(_DWORD *)v5 = &vostok::network::functor_order::`vftable';
    boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
      &v13,
      (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)(v5 + 16));
  }
  else
  {
    v5 = 0;
  }
  v6 = *a2;
  *(_DWORD *)(v5 + 8) = 0;
  v6 += 148;
  v7 = (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)_InterlockedExchange(
                                                                                         (volatile __int32 *)(*(_DWORD *)v6 + 8),
                                                                                         v5);
  v8 = (v14 & 1) == 0;
  *(_DWORD *)v6 = v5;
  if ( !v8 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v7,
      (int *)&v13);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v7, a2 + 18);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v9, a2 + 10);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v10, a2 + 2);
}
