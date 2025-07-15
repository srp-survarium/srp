void __thiscall vostok::network::tcp_packet_client::on_disconnected(vostok::network::tcp_packet_client *this)
{
  boost::function<void __cdecl(void)> *v2; // ecx
  char *v3; // edi
  vostok::network::network_world *m_world; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::tcp_packet_client>,boost::_bi::list1<boost::_bi::value<vostok::network::tcp_packet_client *> > > v6; // [esp-8h] [ebp-38h]
  const char *v7; // [esp+0h] [ebp-30h]
  int v8; // [esp+0h] [ebp-30h]
  const char *v9; // [esp+4h] [ebp-2Ch]
  unsigned int v10; // [esp+8h] [ebp-28h]
  char v11; // [esp+Ch] [ebp-24h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v12; // [esp+10h] [ebp-20h] BYREF

  v11 = 0;
  if ( this->m_on_disconnected.vtable )
  {
    v3 = (char *)vostok::memory::new_helper<vostok::network::functor_response>::call<vostok::memory::doug_lea_allocator>(
                   vostok::network::g_allocator,
                   v7,
                   v9,
                   v10);
    if ( v3 )
    {
      v6.l_.a1_.t_ = this;
      v6.f_.f_ = vostok::network::tcp_packet_client::on_disconnected_impl;
      boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
        v2,
        (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::tcp_packet_client>,boost::_bi::list1<boost::_bi::value<vostok::network::tcp_packet_client *> > > *)&v12,
        v6,
        v8);
      *((_DWORD *)v3 + 1) = vostok::network::g_allocator;
      v11 = 1;
      *(_DWORD *)v3 = &vostok::network::functor_response::`vftable';
      boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
        &v12,
        (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)(v3 + 16));
    }
    else
    {
      v3 = 0;
    }
    m_world = this->m_world;
    *((_DWORD *)v3 + 2) = 0;
    m_world = (vostok::network::network_world *)((char *)m_world + 12);
    v5 = (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)_InterlockedExchange(
                                                                                           (volatile __int32 *)&m_world->tick,
                                                                                           (__int32)v3);
    m_world->__vftable = (vostok::network::network_world_vtbl *)v3;
    if ( (v11 & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        v5,
        (int *)&v12);
  }
}
