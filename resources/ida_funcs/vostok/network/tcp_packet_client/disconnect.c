void __thiscall vostok::network::tcp_packet_client::disconnect(vostok::network::tcp_packet_client *this)
{
  vostok::memory::base_allocator *v1; // eax
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::jump_logic_state_landing,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::jump_logic_state_landing *>,boost::arg<1> > > f; // [esp+8h] [ebp-74h]
  void *_Where; // [esp+34h] [ebp-48h]
  vostok::network::network_world *m_world; // [esp+3Ch] [ebp-40h]
  char v6; // [esp+48h] [ebp-34h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > result; // [esp+4Ch] [ebp-30h] BYREF
  boost::function<void __cdecl(void)> v8; // [esp+54h] [ebp-28h] BYREF
  vostok::network::response *v9; // [esp+78h] [ebp-4h]

  v6 = 0;
  m_world = this->m_world;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)m_world);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)m_world->m_channel.orders.m_owner_allocator);
  _Where = vostok::memory::base_allocator::malloc_impl(v1, 0x28u);
  v9 = (vostok::network::response *)operator new(0x28u, _Where);
  if ( v9 )
  {
    f = (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::jump_logic_state_landing,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::jump_logic_state_landing *>,boost::arg<1> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&result, (void (__thiscall *)(vostok::sound::sound_debug_stats *))vostok::network_core::tcp_packet_client::disconnect, (vostok::sound::sound_debug_stats *)this->m_client);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)f.f_.f_,
      &v8);
    if ( boost::detail::function::basic_vtable1<void,boost::system::error_code>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::http_client,boost::system::error_code>,boost::_bi::list2<boost::_bi::value<vostok::network::http_client *>,boost::arg<1>>>>(
           (boost::detail::function::basic_vtable1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &> *)&`boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network_core::tcp_packet_client>,boost::_bi::list1<boost::_bi::value<vostok::network_core::tcp_packet_client *>>>>'::`2'::stored_vtable,
           f,
           &v8.functor) )
    {
      v8.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network_core::tcp_packet_client>,boost::_bi::list1<boost::_bi::value<vostok::network_core::tcp_packet_client *>>>>'::`2'::stored_vtable.base.manager
                                                         + 1);
    }
    else
    {
      v8.vtable = 0;
    }
    v6 = 1;
    survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v9->next_for_responses);
    v9->__vftable = (vostok::network::response_vtbl *)&vostok::network::order::`vftable';
    v9->__vftable = (vostok::network::response_vtbl *)&vostok::network::functor_order::`vftable';
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function<void __cdecl(void)> *)&v9[1],
      &v8);
    vostok::network::network_world::add_order(this->m_world, v9);
  }
  else
  {
    vostok::network::network_world::add_order(this->m_world, 0);
  }
  if ( (v6 & 1) != 0 )
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v8);
}
