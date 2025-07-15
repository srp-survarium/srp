void __thiscall vostok::network::tcp_packet_client::tcp_packet_client(
        vostok::network::tcp_packet_client *this,
        vostok::network::network_world *world)
{
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v2; // ecx
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v3; // ecx
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v4; // ecx
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v5; // ecx
  vostok::memory::base_allocator *v6; // eax
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v7; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::tcp_packet_client>,boost::_bi::list1<boost::_bi::value<vostok::network::tcp_packet_client *> > > f; // [esp+8h] [ebp-58h]
  void *_Where; // [esp+18h] [ebp-48h]
  vostok::network::network_world *m_world; // [esp+20h] [ebp-40h]
  char v12; // [esp+2Ch] [ebp-34h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > result; // [esp+30h] [ebp-30h] BYREF
  boost::function0<void> v14; // [esp+38h] [ebp-28h] BYREF
  vostok::network::response *v15; // [esp+5Ch] [ebp-4h]

  v12 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v2, this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v3, &this->m_on_connected.vtable);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v4, &this->m_on_disconnected.vtable);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v5, &this->m_on_error.vtable);
  this->m_world = world;
  this->m_client = 0;
  m_world = this->m_world;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)m_world);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)m_world->m_channel.orders.m_owner_allocator);
  _Where = vostok::memory::base_allocator::malloc_impl(v6, 0x28u);
  v15 = (vostok::network::response *)operator new(0x28u, _Where);
  if ( v15 )
  {
    f = (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::tcp_packet_client>,boost::_bi::list1<boost::_bi::value<vostok::network::tcp_packet_client *> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&result, (void (__thiscall *)(vostok::sound::sound_debug_stats *))vostok::network::tcp_packet_client::create_client, (vostok::sound::sound_debug_stats *)this);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v7, &v14);
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::tcp_packet_client>,boost::_bi::list1<boost::_bi::value<vostok::network::tcp_packet_client *>>>>(
      &v14,
      f);
    v12 = 1;
    survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v15->next_for_responses);
    v15->__vftable = (vostok::network::response_vtbl *)&vostok::network::order::`vftable';
    v15->__vftable = (vostok::network::response_vtbl *)&vostok::network::functor_order::`vftable';
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function<void __cdecl(void)> *)&v15[1],
      (const boost::function<void __cdecl(void)> *)&v14);
    vostok::network::network_world::add_order(this->m_world, v15);
  }
  else
  {
    vostok::network::network_world::add_order(this->m_world, 0);
  }
  if ( (v12 & 1) != 0 )
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v14);
}
