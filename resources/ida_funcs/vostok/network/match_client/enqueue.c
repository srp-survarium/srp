void __thiscall vostok::network::match_client::enqueue(
        vostok::network::match_client *this,
        vostok::network_core::udp_match_packet *packet)
{
  vostok::memory::base_allocator *v2; // eax
  boost::function1<void,enum vostok::handshaking_error_types_enum> *v4; // [esp+1Ch] [ebp-5Ch]
  vostok::network::response_vtbl *v5; // [esp+20h] [ebp-58h]
  vostok::network::response_vtbl *v6; // [esp+24h] [ebp-54h]
  boost::_bi::bind_t<void,void (__cdecl*)(vostok::network::match_client_impl * *,vostok::network_core::udp_match_packet &),boost::_bi::list2<boost::_bi::value<vostok::network::match_client_impl * *>,boost::arg<1> > > f; // [esp+28h] [ebp-50h]
  void *_Where; // [esp+30h] [ebp-48h]
  vostok::network::network_world *m_world; // [esp+38h] [ebp-40h]
  char v10; // [esp+44h] [ebp-34h]
  boost::_bi::bind_t<void,void (__cdecl*)(vostok::network_core::tcp_packet_client *),boost::_bi::list1<boost::_bi::value<vostok::network_core::tcp_packet_client *> > > result; // [esp+48h] [ebp-30h] BYREF
  boost::function1<void,vostok::network_core::udp_match_packet &> v12; // [esp+50h] [ebp-28h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > *v13; // [esp+70h] [ebp-8h]
  vostok::network::response *v14; // [esp+74h] [ebp-4h]

  v10 = 0;
  m_world = this->m_world;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)m_world);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)m_world->m_channel.orders.m_owner_allocator);
  _Where = vostok::memory::base_allocator::malloc_impl(v2, 0xB8u);
  v14 = (vostok::network::response *)operator new(0xB8u, _Where);
  if ( v14 )
  {
    f = (boost::_bi::bind_t<void,void (__cdecl*)(vostok::network::match_client_impl * *,vostok::network_core::udp_match_packet &),boost::_bi::list2<boost::_bi::value<vostok::network::match_client_impl * *>,boost::arg<1> > >)*boost::bind<void,vostok::network::match_client_impl * *,vostok::network_core::udp_match_packet &,vostok::network::match_client_impl * *,boost::arg<1>>((boost::_bi::bind_t<void,void (__cdecl*)(vostok::network_core::http_client *),boost::_bi::list1<boost::_bi::value<vostok::network_core::http_client *> > > *)&result, (void (__cdecl *)(vostok::network_core::tcp_packet_client *))enqueue_impl, (vostok::network_core::tcp_packet_client *)this->m_client);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)f.f_,
      &v12);
    boost::function1<void,vostok::network_core::udp_match_packet &>::assign_to<boost::_bi::bind_t<void,void (__cdecl *)(vostok::network::match_client_impl * *,vostok::network_core::udp_match_packet &),boost::_bi::list2<boost::_bi::value<vostok::network::match_client_impl * *>,boost::arg<1>>>>(
      &v12,
      f);
    v10 = 1;
    v6 = (vostok::network::response_vtbl *)((char *)&loc_258034 + (unsigned int)*this->m_client + 4);
    v13 = boost::addressof<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::vfs::async_callbacks_data,vostok::vfs::mount_result>,boost::_bi::list2<boost::_bi::value<vostok::vfs::async_callbacks_data *>,boost::arg<1>>>>((boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > *)packet);
    v5 = (vostok::network::response_vtbl *)v13;
    survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v14->next_for_responses);
    v14->__vftable = (vostok::network::response_vtbl *)&vostok::network::order::`vftable';
    v14->__vftable = (vostok::network::response_vtbl *)&vostok::network::enqueue_order::`vftable';
    qmemcpy(&v14[1], &this->m_stats, 0x80u);
    v4 = (boost::function1<void,enum vostok::handshaking_error_types_enum> *)&v14[17];
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)&v14[17],
      &v14[17].__vftable);
    boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::assign_to_own(
      v4,
      (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v12);
    v14[21].__vftable = v5;
    vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>(
      &this->m_order_packets_allocator,
      (vostok::network_core::udp_match_packets_allocator **)&v14[21].next_for_responses);
    v14[22].__vftable = v6;
    v14[22].next_for_responses = (vostok::network::response *)&this->m_stats;
    vostok::network::network_world::add_order(this->m_world, v14);
  }
  else
  {
    vostok::network::network_world::add_order(this->m_world, 0);
  }
  if ( (v10 & 1) != 0 )
    boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v12);
}
