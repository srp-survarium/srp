void __thiscall vostok::network::tcp_packet_client::on_error(
        vostok::network::tcp_packet_client *this,
        vostok::network_core::client_error_codes_enum client_error_code,
        const boost::system::error_code error_code)
{
  vostok::network::tcp_packet_client *v3; // edi
  bool v4; // zf
  vostok::network::network_world_vtbl *v5; // ebx
  vostok::network::network_world *m_world; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v7; // ecx
  _BYTE v8[24]; // [esp-18h] [ebp-70h] BYREF
  const char *v9; // [esp+0h] [ebp-58h]
  const char *v10; // [esp+4h] [ebp-54h]
  unsigned int v11; // [esp+8h] [ebp-50h]
  int v12; // [esp+Ch] [ebp-4Ch]
  vostok::network::tcp_packet_client *v13; // [esp+10h] [ebp-48h]
  vostok::network::tcp_packet_client *v14; // [esp+14h] [ebp-44h]
  vostok::network_core::client_error_codes_enum v15; // [esp+18h] [ebp-40h]
  boost::system::error_code v16; // [esp+1Ch] [ebp-3Ch]
  _DWORD v17[5]; // [esp+24h] [ebp-34h] BYREF
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> f; // [esp+38h] [ebp-20h] BYREF

  v12 = 0;
  v3 = this;
  v4 = this->m_on_error.vtable == 0;
  v13 = this;
  if ( !v4 )
  {
    v5 = (vostok::network::network_world_vtbl *)vostok::memory::new_helper<vostok::network::functor_response>::call<vostok::memory::doug_lea_allocator>(
                                                  vostok::network::g_allocator,
                                                  v9,
                                                  v10,
                                                  v11);
    if ( v5 )
    {
      v15 = client_error_code;
      v16 = error_code;
      v14 = v3;
      v17[0] = vostok::network::tcp_packet_client::on_error_impl;
      v17[1] = v3;
      v17[2] = client_error_code;
      *(boost::system::error_code *)&v17[3] = error_code;
      *(_DWORD *)v8 = &f;
      qmemcpy(&v8[4], v17, 0x14u);
      boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
        0,
        *(boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network::tcp_packet_client,enum vostok::network_core::client_error_codes_enum,boost::system::error_code>,boost::_bi::list3<boost::_bi::value<vostok::network::tcp_packet_client *>,boost::_bi::value<enum vostok::network_core::client_error_codes_enum>,boost::_bi::value<boost::system::error_code> > > *)v8,
        *(int *)&v8[20]);
      v5->finalize = (void (__thiscall *)(struct vostok::network::network_world *))vostok::network::g_allocator;
      *(_DWORD *)&v8[20] = &v5->dispatch_callbacks;
      v12 = 1;
      v5->initialize = (void (__thiscall *)(struct vostok::network::network_world *))&vostok::network::functor_response::`vftable';
      boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
        &f,
        *(const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> **)&v8[20]);
      v3 = v13;
    }
    else
    {
      v5 = 0;
    }
    m_world = v3->m_world;
    v5->tick = 0;
    m_world = (vostok::network::network_world *)((char *)m_world + 12);
    v7 = (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)_InterlockedExchange(
                                                                                           (volatile __int32 *)&m_world->tick,
                                                                                           (__int32)v5);
    v4 = (v12 & 1) == 0;
    m_world->__vftable = v5;
    if ( !v4 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        v7,
        (int *)&f);
  }
}
