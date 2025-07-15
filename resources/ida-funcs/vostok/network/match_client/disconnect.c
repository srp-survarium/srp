void __thiscall vostok::network::match_client::disconnect(vostok::network::match_client *this)
{
  vostok::memory::base_allocator *v1; // eax
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v2; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::jump_logic_state_landing,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::jump_logic_state_landing *>,boost::arg<1> > > f; // [esp+8h] [ebp-7Ch]
  void *_Where; // [esp+38h] [ebp-4Ch]
  vostok::network::network_world *m_world; // [esp+40h] [ebp-44h]
  char v7; // [esp+4Ch] [ebp-38h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::match_client_impl>,boost::_bi::list1<boost::reference_wrapper<vostok::network::match_client_impl *> > > result; // [esp+50h] [ebp-34h] BYREF
  boost::reference_wrapper<vostok::network::match_client_impl *> a1; // [esp+58h] [ebp-2Ch]
  boost::function<void __cdecl(void)> v10; // [esp+5Ch] [ebp-28h] BYREF
  vostok::network::response *v11; // [esp+80h] [ebp-4h]

  v7 = 0;
  m_world = this->m_world;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)m_world);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)m_world->m_channel.orders.m_owner_allocator);
  _Where = vostok::memory::base_allocator::malloc_impl(v1, 0x28u);
  v11 = (vostok::network::response *)operator new(0x28u, _Where);
  if ( v11 )
  {
    a1.t_ = (vostok::network::match_client_impl **)boost::addressof<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::vfs::async_callbacks_data,vostok::vfs::mount_result>,boost::_bi::list2<boost::_bi::value<vostok::vfs::async_callbacks_data *>,boost::arg<1>>>>((boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > *)this->m_client);
    f = (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::jump_logic_state_landing,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::jump_logic_state_landing *>,boost::arg<1> > >)*boost::bind<void,vostok::network::match_client_impl,boost::reference_wrapper<vostok::network::match_client_impl *>>(&result, vostok::network::match_client_impl::disconnect, a1);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v2, &v10);
    if ( boost::detail::function::basic_vtable1<void,boost::system::error_code>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::http_client,boost::system::error_code>,boost::_bi::list2<boost::_bi::value<vostok::network::http_client *>,boost::arg<1>>>>(
           (boost::detail::function::basic_vtable1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &> *)&`boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::match_client_impl>,boost::_bi::list1<boost::reference_wrapper<vostok::network::match_client_impl *>>>>'::`2'::stored_vtable,
           f,
           &v10.functor) )
    {
      v10.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::match_client_impl>,boost::_bi::list1<boost::reference_wrapper<vostok::network::match_client_impl *>>>>'::`2'::stored_vtable.base.manager
                                                          + 1);
    }
    else
    {
      v10.vtable = 0;
    }
    v7 = 1;
    survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v11->next_for_responses);
    v11->__vftable = (vostok::network::response_vtbl *)&vostok::network::order::`vftable';
    v11->__vftable = (vostok::network::response_vtbl *)&vostok::network::functor_order::`vftable';
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function<void __cdecl(void)> *)&v11[1],
      &v10);
    vostok::network::network_world::add_order(this->m_world, v11);
  }
  else
  {
    vostok::network::network_world::add_order(this->m_world, 0);
  }
  if ( (v7 & 1) != 0 )
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v10);
}
