void __userpurge vostok::network::http_client::get(
        vostok::network::http_client *this@<eax>,
        boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *callback@<ecx>,
        char *server,
        char *path)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  vostok::memory::base_allocator *m_orders_allocator; // esi
  char *v7; // eax
  boost::function<void __cdecl(char const *,char const *)> *v8; // ecx
  vostok::network::string_order *v9; // ebx
  __int32 v10; // eax
  vostok::network::network_world *m_world; // edi
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v12; // ecx
  bool v13; // zf
  vostok::memory::base_allocator *v14; // [esp-Ch] [ebp-44h]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network::http_client,char const *,char const *>,boost::_bi::list3<boost::_bi::value<vostok::network::http_client *>,boost::arg<1>,boost::arg<2> > > v15; // [esp-8h] [ebp-40h]
  int v16; // [esp+0h] [ebp-38h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> f; // [esp+10h] [ebp-28h] BYREF
  int v18; // [esp+34h] [ebp-4h]

  v18 = 0;
  this->m_busy = 1;
  boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(callback, &f);
  boost::function4<void,char const *,enum survarium::hit_type_enum,float &,float &>::swap(
    (boost::function1<void,vostok::physics::contact_point const &> *)&this->m_on_content_downloaded,
    (boost::function1<void,vostok::physics::contact_point const &> *)&f);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v5, (int *)&f);
  m_orders_allocator = this->m_world->m_orders_allocator;
  v7 = type_info::raw_name(&vostok::network::string_order `RTTI Type Descriptor');
  v9 = (vostok::network::string_order *)m_orders_allocator->call_malloc(
                                          m_orders_allocator,
                                          128u,
                                          v7,
                                          "vostok::network::http_client::get",
                                          ".\\http_client.cpp",
                                          66u);
  if ( v9 )
  {
    v15.l_.a1_.t_ = this;
    v15.f_.f_ = (void (__thiscall *)(vostok::network::http_client *, const char *, const char *))vostok::network::http_client::get_impl;
    boost::function<void __cdecl (char const *,char const *)>::function<void __cdecl (char const *,char const *)>(
      v8,
      (boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network::http_client,char const *,char const *>,boost::_bi::list3<boost::_bi::value<vostok::network::http_client *>,boost::arg<1>,boost::arg<2> > > *)&f,
      v15,
      v16);
    v14 = this->m_world->m_orders_allocator;
    v18 = 1;
    vostok::network::string_order::string_order(
      (const boost::function<void __cdecl(char const *,char const *)> *)&f,
      v9,
      v14,
      server,
      path);
  }
  else
  {
    v10 = 0;
  }
  m_world = this->m_world;
  *(_DWORD *)(v10 + 8) = 0;
  m_world = (vostok::network::network_world *)((char *)m_world + 148);
  v12 = (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)_InterlockedExchange(
                                                                                          (volatile __int32 *)&m_world->tick,
                                                                                          v10);
  v13 = (v18 & 1) == 0;
  m_world->__vftable = (vostok::network::network_world_vtbl *)v10;
  if ( !v13 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v12,
      (int *)&f);
}
