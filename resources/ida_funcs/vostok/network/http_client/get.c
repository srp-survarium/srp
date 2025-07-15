void __thiscall vostok::network::http_client::get(
        vostok::network::http_client *this,
        char *server,
        char *path,
        boost::function<void __cdecl(unsigned int,unsigned int)> *callback)
{
  survarium::game_camera *v4; // ecx
  survarium::game_camera *v5; // ecx
  vostok::memory::base_allocator *v6; // eax
  vostok::network::response *v7; // eax
  vostok::network::network_world *m_world; // [esp+18h] [ebp-80h]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::jump_logic_state_landing,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::jump_logic_state_landing *>,boost::arg<1> > > f; // [esp+24h] [ebp-74h]
  void *_Where; // [esp+30h] [ebp-68h]
  char v12; // [esp+64h] [ebp-34h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > result; // [esp+68h] [ebp-30h] BYREF
  boost::function<void __cdecl(char const *,char const *)> functor; // [esp+70h] [ebp-28h] BYREF
  vostok::network::string_order *v15; // [esp+90h] [ebp-8h]
  char v16; // [esp+97h] [ebp-1h]

  v12 = 0;
  v16 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->m_busy = 1;
  boost::function<void __cdecl (unsigned char,vostok::network_core::packet_reader &)>::operator=(
    callback,
    (boost::function2<void,unsigned int,unsigned int> *)&this->m_on_content_downloaded);
  survarium::weapon_user_dead_state::finalize(v4);
  survarium::weapon_user_dead_state::finalize(v5);
  _Where = vostok::memory::base_allocator::malloc_impl(v6, 0x78u);
  v15 = (vostok::network::string_order *)operator new(0x78u, _Where);
  if ( v15 )
  {
    f = (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::jump_logic_state_landing,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::jump_logic_state_landing *>,boost::arg<1> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&result, (void (__thiscall *)(vostok::sound::sound_debug_stats *))vostok::network::http_client::get_impl, (vostok::sound::sound_debug_stats *)this);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)f.f_.f_,
      &functor);
    if ( boost::detail::function::basic_vtable1<void,boost::system::error_code>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::http_client,boost::system::error_code>,boost::_bi::list2<boost::_bi::value<vostok::network::http_client *>,boost::arg<1>>>>(
           (boost::detail::function::basic_vtable1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &> *)&`boost::function2<void,char const *,char const *>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network::http_client,char const *,char const *>,boost::_bi::list3<boost::_bi::value<vostok::network::http_client *>,boost::arg<1>,boost::arg<2>>>>'::`2'::stored_vtable,
           f,
           &functor.functor) )
    {
      functor.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function2<void,char const *,char const *>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network::http_client,char const *,char const *>,boost::_bi::list3<boost::_bi::value<vostok::network::http_client *>,boost::arg<1>,boost::arg<2>>>>'::`2'::stored_vtable.base.manager
                                                              + 1);
    }
    else
    {
      functor.vtable = 0;
    }
    v12 = 1;
    m_world = this->m_world;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
    vostok::network::string_order::string_order(
      v15,
      m_world->m_channel.orders.m_owner_allocator,
      (const boost::function1<void,enum vostok::handshaking_error_types_enum> *)&functor,
      server,
      path);
    vostok::network::network_world::add_order(this->m_world, v7);
  }
  else
  {
    vostok::network::network_world::add_order(this->m_world, 0);
  }
  if ( (v12 & 1) != 0 )
    boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&functor);
}
