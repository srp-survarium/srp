void __thiscall vostok::network::http_client::create_client_impl(vostok::network::http_client *this)
{
  survarium::game_camera *v1; // ecx
  vostok::memory::doug_lea_allocator *v2; // eax
  vostok::network_core::http_client *v3; // eax
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v4; // ecx
  vostok::network_core::http_client *v5; // [esp+0h] [ebp-ACh]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::jump_logic_state_landing,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::jump_logic_state_landing *>,boost::arg<1> > > f; // [esp+54h] [ebp-58h]
  int *_Where; // [esp+74h] [ebp-38h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > result; // [esp+7Ch] [ebp-30h] BYREF
  boost::function<void __cdecl(boost::system::error_code)> callback; // [esp+84h] [ebp-28h] BYREF
  vostok::network_core::http_client *v11; // [esp+A4h] [ebp-8h]
  char v12; // [esp+ABh] [ebp-1h]

  v12 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v1);
  _Where = vostok::memory::doug_lea_allocator::malloc_impl(v2, 0x108u);
  v11 = (vostok::network_core::http_client *)operator new(0x108u, _Where);
  if ( v11 )
  {
    vostok::network_core::http_client::http_client(v11, this->m_world->m_io_service);
    v5 = v3;
  }
  else
  {
    v5 = 0;
  }
  this->m_client = v5;
  f = (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::jump_logic_state_landing,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::jump_logic_state_landing *>,boost::arg<1> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&result, (void (__thiscall *)(vostok::sound::sound_debug_stats *))vostok::network::http_client::on_error, (vostok::sound::sound_debug_stats *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v4, &callback);
  if ( boost::detail::function::basic_vtable1<void,boost::system::error_code>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::http_client,boost::system::error_code>,boost::_bi::list2<boost::_bi::value<vostok::network::http_client *>,boost::arg<1>>>>(
         (boost::detail::function::basic_vtable1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &> *)&`boost::function1<void,boost::system::error_code>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::http_client,boost::system::error_code>,boost::_bi::list2<boost::_bi::value<vostok::network::http_client *>,boost::arg<1>>>>'::`2'::stored_vtable,
         f,
         &callback.functor) )
  {
    callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,boost::system::error_code>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::http_client,boost::system::error_code>,boost::_bi::list2<boost::_bi::value<vostok::network::http_client *>,boost::arg<1>>>>'::`2'::stored_vtable.base.manager
                                                             + 1);
  }
  else
  {
    callback.vtable = 0;
  }
  vostok::network_core::http_client::set_on_error(this->m_client, &callback);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&callback);
  this->m_busy = 0;
}
