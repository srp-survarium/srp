void __thiscall vostok::network::http_client::on_error(
        vostok::network::http_client *this,
        boost::system::error_code error_code)
{
  vostok::network::http_client *v2; // edi
  boost::function<void __cdecl(void)> *v3; // ecx
  char *v4; // ebx
  vostok::network::network_world *m_world; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::http_client,boost::system::error_code>,boost::_bi::list2<boost::_bi::value<vostok::network::http_client *>,boost::_bi::value<boost::system::error_code> > > v7; // [esp-14h] [ebp-64h]
  const char *v8; // [esp+0h] [ebp-50h]
  const char *v9; // [esp+4h] [ebp-4Ch]
  unsigned int v10; // [esp+8h] [ebp-48h]
  char v11; // [esp+Ch] [ebp-44h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> f; // [esp+30h] [ebp-20h] BYREF

  v11 = 0;
  v2 = this;
  if ( this->m_on_error.vtable )
  {
    v4 = (char *)vostok::memory::new_helper<vostok::network::functor_response>::call<vostok::memory::doug_lea_allocator>(
                   vostok::network::g_allocator,
                   v8,
                   v9,
                   v10);
    if ( v4 )
    {
      v7.l_.a1_.t_ = (vostok::network::http_client *)vostok::network::http_client::on_error_impl;
      v7.l_.a2_ = (boost::_bi::value<boost::system::error_code>)__PAIR64__(error_code.m_val, (unsigned int)v2);
      v7.f_.f_ = (void (__thiscall *)(vostok::network::http_client *, boost::system::error_code))&f;
      boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v3, v7, (int)error_code.m_cat);
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
}
