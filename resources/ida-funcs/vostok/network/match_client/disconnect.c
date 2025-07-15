void __thiscall vostok::network::match_client::disconnect(vostok::network::match_client *this, int a2)
{
  int v2; // esi
  char *v3; // eax
  __int32 v4; // edi
  int v5; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::match_client_impl>,boost::_bi::list1<boost::reference_wrapper<vostok::network::match_client_impl *> > > v7; // [esp+0h] [ebp-38h]
  int v8; // [esp+8h] [ebp-30h]
  char v9; // [esp+14h] [ebp-24h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v10; // [esp+18h] [ebp-20h] BYREF

  v9 = 0;
  v2 = *(_DWORD *)(*(_DWORD *)(a2 + 236) + 284);
  v3 = type_info::raw_name(&vostok::network::functor_order `RTTI Type Descriptor');
  v4 = (*(int (__thiscall **)(int, int, char *, const char *, const char *, int))(*(_DWORD *)v2 + 16))(
         v2,
         48,
         v3,
         "vostok::network::match_client::disconnect",
         ".\\match_client.cpp",
         196);
  if ( v4 )
  {
    v7.l_.a1_.t_ = *(vostok::network::match_client_impl ***)(a2 + 240);
    v7.f_.f_ = vostok::network::match_client_impl::disconnect;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function<void __cdecl(void)> *)vostok::network::match_client_impl::disconnect,
      (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::match_client_impl>,boost::_bi::list1<boost::reference_wrapper<vostok::network::match_client_impl *> > > *)&v10,
      v7,
      v8);
    *(_DWORD *)(v4 + 4) = *(_DWORD *)(*(_DWORD *)(a2 + 236) + 284);
    v9 = 1;
    *(_DWORD *)v4 = &vostok::network::functor_order::`vftable';
    boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
      &v10,
      (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)(v4 + 16));
  }
  else
  {
    v4 = 0;
  }
  v5 = *(_DWORD *)(a2 + 236);
  *(_DWORD *)(v4 + 8) = 0;
  v5 += 148;
  v6 = (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)_InterlockedExchange(
                                                                                         (volatile __int32 *)(*(_DWORD *)v5 + 8),
                                                                                         v4);
  *(_DWORD *)v5 = v4;
  if ( (v9 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v6,
      (int *)&v10);
}
