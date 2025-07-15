void __thiscall vostok::network::http_client::on_content_downloaded(vostok::network::http_client *this)
{
  vostok::memory::doug_lea_allocator *v1; // esi
  char *v3; // eax
  vostok::memory::doug_lea_allocator *v4; // ecx
  boost::function<void __cdecl(char const *)> *v5; // ecx
  char *v6; // edi
  char *M_data; // esi
  char *v8; // eax
  vostok::network::network_world *m_world; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v10; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::http_client,char const *>,boost::_bi::list2<boost::_bi::value<vostok::network::http_client *>,boost::arg<1> > > v11; // [esp-8h] [ebp-40h]
  const char *v12; // [esp+0h] [ebp-38h]
  int v13; // [esp+0h] [ebp-38h]
  const char *v14; // [esp+4h] [ebp-34h]
  unsigned int v15; // [esp+8h] [ebp-30h]
  char v16; // [esp+10h] [ebp-28h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v17; // [esp+18h] [ebp-20h] BYREF

  v16 = 0;
  v1 = vostok::network::g_allocator;
  v3 = type_info::raw_name(&vostok::network::string_response `RTTI Type Descriptor');
  v6 = vostok::memory::doug_lea_allocator::malloc_impl(v4, (int)v1, 0x80u, v3, v12, v14, v15);
  if ( v6 )
  {
    v11.l_.a1_.t_ = this;
    v11.f_.f_ = (void (__thiscall *)(vostok::network::http_client *, const char *))vostok::network::http_client::on_content_downloaded_impl;
    boost::function<void __cdecl (char const *)>::function<void __cdecl (char const *)>(
      v5,
      (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::http_client,char const *>,boost::_bi::list2<boost::_bi::value<vostok::network::http_client *>,boost::arg<1> > > *)&v17,
      v11,
      v13);
    M_data = this->m_client->m_result_content._M_start_of_storage._M_data;
    *((_DWORD *)v6 + 1) = vostok::network::g_allocator;
    v16 = 1;
    *(_DWORD *)v6 = &vostok::network::string_response::`vftable';
    boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
      &v17,
      (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)(v6 + 16));
    *((_DWORD *)v6 + 12) = 0;
    *((_DWORD *)v6 + 20) = 0;
    v8 = vostok::strings::duplicate<vostok::memory::base_allocator>(M_data);
    *((_DWORD *)v6 + 29) = 0;
    *((_DWORD *)v6 + 30) = 0;
    *((_DWORD *)v6 + 28) = v8;
  }
  else
  {
    v6 = 0;
  }
  m_world = this->m_world;
  *((_DWORD *)v6 + 2) = 0;
  m_world = (vostok::network::network_world *)((char *)m_world + 12);
  v10 = (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)_InterlockedExchange(
                                                                                          (volatile __int32 *)&m_world->tick,
                                                                                          (__int32)v6);
  m_world->__vftable = (vostok::network::network_world_vtbl *)v6;
  if ( (v16 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v10,
      (int *)&v17);
}
