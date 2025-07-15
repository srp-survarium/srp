void __thiscall vostok::network::http_client::http_client(
        vostok::network::http_client *this,
        vostok::network::network_world *world)
{
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v2; // ecx
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v3; // ecx
  vostok::memory::base_allocator *v4; // eax
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v5; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > f; // [esp+8h] [ebp-60h]
  void *_Where; // [esp+18h] [ebp-50h]
  vostok::network::network_world *m_world; // [esp+20h] [ebp-48h]
  char v10; // [esp+34h] [ebp-34h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > result; // [esp+38h] [ebp-30h] BYREF
  boost::function0<void> v12; // [esp+40h] [ebp-28h] BYREF
  vostok::network::response *v13; // [esp+64h] [ebp-4h]

  v10 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->m_world = world;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)world,
    &this->m_on_content_downloaded.vtable);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v2, &this->m_on_error.vtable);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v3, &this->m_client_on_error.vtable);
  this->m_client = 0;
  this->m_busy = 1;
  m_world = this->m_world;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this->m_world);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)m_world->m_channel.orders.m_owner_allocator);
  _Where = vostok::memory::base_allocator::malloc_impl(v4, 0x28u);
  v13 = (vostok::network::response *)operator new(0x28u, _Where);
  if ( v13 )
  {
    f = *boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>(
           (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&result,
           (void (__thiscall *)(vostok::sound::sound_debug_stats *))vostok::network::http_client::create_client_impl,
           (vostok::sound::sound_debug_stats *)this);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v5, &v12);
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::http_client>,boost::_bi::list1<boost::_bi::value<vostok::network::http_client *>>>>(
      &v12,
      (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::http_client>,boost::_bi::list1<boost::_bi::value<vostok::network::http_client *> > >)f);
    v10 = 1;
    survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v13->next_for_responses);
    v13->__vftable = (vostok::network::response_vtbl *)&vostok::network::order::`vftable';
    v13->__vftable = (vostok::network::response_vtbl *)&vostok::network::functor_order::`vftable';
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function<void __cdecl(void)> *)&v13[1],
      (const boost::function<void __cdecl(void)> *)&v12);
    vostok::network::network_world::add_order(this->m_world, v13);
  }
  else
  {
    vostok::network::network_world::add_order(this->m_world, 0);
  }
  if ( (v10 & 1) != 0 )
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v12);
}
