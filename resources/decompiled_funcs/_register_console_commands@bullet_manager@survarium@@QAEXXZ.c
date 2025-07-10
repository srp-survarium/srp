void __thiscall survarium::bullet_manager::register_console_commands(survarium::bullet_manager *this)
{
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v1; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v2; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v3; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::jump_logic_state_landing,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::jump_logic_state_landing *>,boost::arg<1> > > v5; // [esp+Ch] [ebp-7Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::bullet_manager,char const *>,boost::_bi::list2<boost::_bi::value<survarium::bullet_manager *>,boost::arg<1> > > f; // [esp+28h] [ebp-60h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > v7; // [esp+38h] [ebp-50h] BYREF
  boost::function<void __cdecl(char const *)> functor; // [esp+40h] [ebp-48h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > result; // [esp+60h] [ebp-28h] BYREF
  boost::function1<void,char const *> v10; // [esp+68h] [ebp-20h] BYREF

  if ( (_S4_8 & 1) == 0 )
  {
    _S4_8 |= 1u;
    f = (boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::bullet_manager,char const *>,boost::_bi::list2<boost::_bi::value<survarium::bullet_manager *>,boost::arg<1> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&result, (void (__thiscall *)(vostok::sound::sound_debug_stats *))survarium::bullet_manager::destroy_all_bullets, (vostok::sound::sound_debug_stats *)this);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v1, &v10);
    boost::function1<void,char const *>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::bullet_manager,char const *>,boost::_bi::list2<boost::_bi::value<survarium::bullet_manager *>,boost::arg<1>>>>(
      &v10,
      f);
    vostok::console_commands::cc_delegate::cc_delegate(
      &displace_all_bullets_cc,
      "bullets_manager_displace_all_bullets",
      (const boost::function<void __cdecl(char const *)> *)&v10,
      1,
      command_type_engine_internal);
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v2,
      (int *)&v10);
    atexit(survarium::bullet_manager::register_console_commands_::_2_::_dynamic_atexit_destructor_for__displace_all_bullets_cc__);
  }
  if ( (_S4_8 & 2) == 0 )
  {
    _S4_8 |= 2u;
    v5 = (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::jump_logic_state_landing,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::jump_logic_state_landing *>,boost::arg<1> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&v7, (void (__thiscall *)(vostok::sound::sound_debug_stats *))survarium::bullet_manager::set_max_bullets, (vostok::sound::sound_debug_stats *)this);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v5.f_.f_,
      &functor);
    if ( boost::detail::function::basic_vtable1<void,boost::system::error_code>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::http_client,boost::system::error_code>,boost::_bi::list2<boost::_bi::value<vostok::network::http_client *>,boost::arg<1>>>>(
           (boost::detail::function::basic_vtable1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &> *)&`boost::function1<void,char const *>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::bullet_manager,char const *>,boost::_bi::list2<boost::_bi::value<survarium::bullet_manager *>,boost::arg<1>>>>'::`2'::stored_vtable,
           v5,
           &functor.functor) )
    {
      functor.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,char const *>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::bullet_manager,char const *>,boost::_bi::list2<boost::_bi::value<survarium::bullet_manager *>,boost::arg<1>>>>'::`2'::stored_vtable.base.manager
                                                              + 1);
    }
    else
    {
      functor.vtable = 0;
    }
    vostok::console_commands::cc_delegate::cc_delegate(
      &set_max_bullets_cc,
      "bullets_manager_set_max_bullets",
      &functor,
      1,
      command_type_engine_internal);
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v3,
      (int *)&functor);
    atexit(survarium::bullet_manager::register_console_commands_::_2_::_dynamic_atexit_destructor_for__set_max_bullets_cc__);
  }
}
