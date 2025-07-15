void __thiscall survarium::bullet_manager::allocate_bullets_memory(
        survarium::bullet_manager *this,
        unsigned int new_max_bullets_count)
{
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v2; // ecx
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v3; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::jump_logic_state_landing,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::jump_logic_state_landing *>,boost::arg<1> > > v5; // [esp+4h] [ebp-8Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::bullet_manager,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::bullet_manager *>,boost::arg<1> > > f; // [esp+20h] [ebp-70h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > v7; // [esp+30h] [ebp-60h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+38h] [ebp-58h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > result; // [esp+58h] [ebp-38h] BYREF
  boost::function1<void,vostok::resources::queries_result &> v10; // [esp+60h] [ebp-30h] BYREF
  vostok::resources::creation_request request; // [esp+80h] [ebp-10h] BYREF

  this->m_max_bullets_count = new_max_bullets_count;
  vostok::resources::creation_request::creation_request(
    &request,
    "bullets_memory",
    660 * this->m_max_bullets_count,
    unmanaged_allocation_class);
  if ( this->m_bullets_allocator_ref.m_initialized )
  {
    f = (boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::bullet_manager,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::bullet_manager *>,boost::arg<1> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&result, (void (__thiscall *)(vostok::sound::sound_debug_stats *))survarium::bullet_manager::bullets_memory_allocated, (vostok::sound::sound_debug_stats *)this);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v2, &v10);
    boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::bullet_manager,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::bullet_manager *>,boost::arg<1>>>>(
      &v10,
      f);
    vostok::resources::query_create_resources(
      &request,
      1u,
      (const boost::function<void __cdecl(vostok::resources::queries_result &)> *)&v10,
      (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_,
      0,
      0,
      assert_on_fail_true);
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v10);
  }
  else
  {
    v5 = (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::jump_logic_state_landing,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::jump_logic_state_landing *>,boost::arg<1> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&v7, (void (__thiscall *)(vostok::sound::sound_debug_stats *))survarium::bullet_manager::bullets_memory_allocated, (vostok::sound::sound_debug_stats *)this);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v3, &callback);
    if ( boost::detail::function::basic_vtable1<void,boost::system::error_code>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::http_client,boost::system::error_code>,boost::_bi::list2<boost::_bi::value<vostok::network::http_client *>,boost::arg<1>>>>(
           (boost::detail::function::basic_vtable1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &> *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::bullet_manager,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::bullet_manager *>,boost::arg<1>>>>'::`2'::stored_vtable,
           v5,
           &callback.functor) )
    {
      callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::bullet_manager,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::bullet_manager *>,boost::arg<1>>>>'::`2'::stored_vtable.base.manager
                                                               + 1);
    }
    else
    {
      callback.vtable = 0;
    }
    vostok::resources::query_create_resources_and_wait(
      &request,
      1u,
      &callback,
      (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_,
      0,
      0,
      assert_on_fail_true);
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&callback);
  }
}
