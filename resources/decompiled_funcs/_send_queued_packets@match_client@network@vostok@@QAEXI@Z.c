void __thiscall vostok::network::match_client::send_queued_packets(
        vostok::network::match_client *this,
        unsigned int current_time_in_ms)
{
  vostok::memory::base_allocator *v2; // eax
  vostok::network::response *v4; // [esp+14h] [ebp-70h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::match_client_impl,unsigned int>,boost::_bi::list2<boost::reference_wrapper<vostok::network::match_client_impl *>,boost::_bi::value<unsigned int> > > v5; // [esp+1Ch] [ebp-68h]
  void *_Where; // [esp+34h] [ebp-50h]
  vostok::network::network_world *m_world; // [esp+3Ch] [ebp-48h]
  char v8; // [esp+48h] [ebp-3Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::match_client_impl,unsigned int>,boost::_bi::list2<boost::reference_wrapper<vostok::network::match_client_impl *>,boost::_bi::value<unsigned int> > > result; // [esp+4Ch] [ebp-38h] BYREF
  boost::reference_wrapper<vostok::network::match_client_impl *> a1; // [esp+58h] [ebp-2Ch]
  boost::function0<void> v11; // [esp+5Ch] [ebp-28h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > *v12; // [esp+7Ch] [ebp-8h]
  vostok::network::response *v13; // [esp+80h] [ebp-4h]

  v8 = 0;
  m_world = this->m_world;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)m_world);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)m_world->m_channel.orders.m_owner_allocator);
  _Where = vostok::memory::base_allocator::malloc_impl(v2, 0xB0u);
  v13 = (vostok::network::response *)operator new(0xB0u, _Where);
  if ( v13 )
  {
    a1.t_ = (vostok::network::match_client_impl **)boost::addressof<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::vfs::async_callbacks_data,vostok::vfs::mount_result>,boost::_bi::list2<boost::_bi::value<vostok::vfs::async_callbacks_data *>,boost::arg<1>>>>((boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > *)this->m_client);
    v5 = *boost::bind<void,vostok::network::match_client_impl,unsigned int,boost::reference_wrapper<vostok::network::match_client_impl *>,unsigned int>(
            &result,
            vostok::network::match_client_impl::send_queued_packets,
            a1,
            current_time_in_ms);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v5.f_.f_,
      &v11);
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::match_client_impl,unsigned int>,boost::_bi::list2<boost::reference_wrapper<vostok::network::match_client_impl *>,boost::_bi::value<unsigned int>>>>(
      &v11,
      v5);
    v8 = 1;
    v12 = boost::addressof<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::vfs::async_callbacks_data,vostok::vfs::mount_result>,boost::_bi::list2<boost::_bi::value<vostok::vfs::async_callbacks_data *>,boost::arg<1>>>>((boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > *)this->m_client);
    v4 = (vostok::network::response *)v12;
    survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v13->next_for_responses);
    v13->__vftable = (vostok::network::response_vtbl *)&vostok::network::order::`vftable';
    v13->__vftable = (vostok::network::response_vtbl *)&vostok::network::send_queued_order::`vftable';
    qmemcpy(&v13[1], &this->m_stats, 0x80u);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function<void __cdecl(void)> *)&v13[17],
      (const boost::function<void __cdecl(void)> *)&v11);
    v13[21].__vftable = (vostok::network::response_vtbl *)&this->m_stats;
    v13[21].next_for_responses = v4;
    vostok::network::network_world::add_order(this->m_world, v13);
  }
  else
  {
    vostok::network::network_world::add_order(this->m_world, 0);
  }
  if ( (v8 & 1) != 0 )
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v11);
}
