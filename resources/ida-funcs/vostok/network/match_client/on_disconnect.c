void __thiscall vostok::network::match_client::on_disconnect(vostok::network::match_client *this, int type)
{
  vostok::network::match_client *v2; // edi
  boost::function<void __cdecl(void)> *v3; // ecx
  char *v4; // ebx
  vostok::network::network_world *m_world; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::match_client,enum vostok::network_core::disconnect_event_types_enum>,boost::_bi::list2<boost::_bi::value<vostok::network::match_client *>,boost::_bi::value<enum vostok::network_core::disconnect_event_types_enum> > > v7; // [esp-10h] [ebp-50h]
  const char *v8; // [esp+0h] [ebp-40h]
  const char *v9; // [esp+4h] [ebp-3Ch]
  unsigned int v10; // [esp+8h] [ebp-38h]
  char v11; // [esp+Ch] [ebp-34h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> f; // [esp+20h] [ebp-20h] BYREF

  v11 = 0;
  v2 = this;
  v4 = (char *)vostok::memory::new_helper<vostok::network::functor_response>::call<vostok::memory::doug_lea_allocator>(
                 vostok::network::g_allocator,
                 v8,
                 v9,
                 v10);
  if ( v4 )
  {
    v7.l_.a1_.t_ = (vostok::network::match_client *)vostok::network::match_client::on_disconnect_impl;
    v7.l_.a2_.t_ = (vostok::network_core::disconnect_event_types_enum)v2;
    v7.f_.f_ = (void (__thiscall *)(vostok::network::match_client *, vostok::network_core::disconnect_event_types_enum))&f;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v3, v7, type);
    *((_DWORD *)v4 + 1) = vostok::network::g_allocator;
    v11 = 1;
    *(_DWORD *)v4 = &vostok::network::functor_response::`vftable';
    boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
      &f,
      (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)(v4 + 16));
    v2 = this;
  }
  else
  {
    v4 = 0;
  }
  m_world = v2->m_world;
  *((_DWORD *)v4 + 2) = 0;
  m_world = (vostok::network::network_world *)((char *)m_world + 12);
  v6 = (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)_InterlockedExchange(
                                                                                         (volatile __int32 *)&m_world->tick,
                                                                                         (__int32)v4);
  m_world->__vftable = (vostok::network::network_world_vtbl *)v4;
  if ( (v11 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v6,
      (int *)&f);
}
