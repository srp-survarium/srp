void __usercall vostok::debug::dump_call_stack(
        unsigned int a1@<ebx>,
        const char *initiator,
        bool use_error_verbosity,
        unsigned int num_first_to_ignore,
        unsigned int num_last_to_ignore,
        _EXCEPTION_POINTERS *pointers,
        void **call_stack)
{
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::jump_logic_state_landing,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::jump_logic_state_landing *>,boost::arg<1> > > f; // [esp+8h] [ebp-264h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > result; // [esp+34h] [ebp-238h] BYREF
  boost::function<bool __cdecl(unsigned int,unsigned int,char const *,char const *,int,char const *,unsigned int)> callback; // [esp+3Ch] [ebp-230h] BYREF
  helper temp; // [esp+5Ch] [ebp-210h] BYREF

  temp.m_use_error_verbosity = use_error_verbosity;
  temp.m_num_first_to_ignore = num_first_to_ignore;
  temp.m_num_last_to_ignore = num_last_to_ignore;
  strcpy_s(temp.m_initiator, 0x200u, initiator);
  strcat_s(temp.m_initiator, 0x200u, (const char *)&stru_95963C.m_max_end);
  f = (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::jump_logic_state_landing,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::jump_logic_state_landing *>,boost::arg<1> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&result, (void (__thiscall *)(vostok::sound::sound_debug_stats *))helper::predicate, (vostok::sound::sound_debug_stats *)&temp);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)f.f_.f_,
    &callback);
  if ( boost::detail::function::basic_vtable1<void,boost::system::error_code>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::http_client,boost::system::error_code>,boost::_bi::list2<boost::_bi::value<vostok::network::http_client *>,boost::arg<1>>>>(
         (boost::detail::function::basic_vtable1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &> *)&`boost::function7<bool,unsigned int,unsigned int,char const *,char const *,int,char const *,unsigned int>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::mf7<bool,helper,unsigned int,unsigned int,char const *,char const *,int,char const *,unsigned int>,boost::_bi::list8<boost::_bi::value<helper *>,boost::arg<1>,boost::arg<2>,boost::arg<3>,boost::arg<4>,boost::arg<5>,boost::arg<6>,boost::arg<7>>>>'::`2'::stored_vtable,
         f,
         &callback.functor) )
  {
    callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function7<bool,unsigned int,unsigned int,char const *,char const *,int,char const *,unsigned int>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::mf7<bool,helper,unsigned int,unsigned int,char const *,char const *,int,char const *,unsigned int>,boost::_bi::list8<boost::_bi::value<helper *>,boost::arg<1>,boost::arg<2>,boost::arg<3>,boost::arg<4>,boost::arg<5>,boost::arg<6>,boost::arg<7>>>>'::`2'::stored_vtable.base.manager
                                                             + 1);
  }
  else
  {
    callback.vtable = 0;
  }
  vostok::debug::call_stack::iterate(
    (vostok::memory::base_allocator *)&callback,
    a1,
    pointers,
    call_stack,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&callback,
    1);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&callback);
}
