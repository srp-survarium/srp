void __thiscall survarium::damage_model_cook::translate_query(
        survarium::damage_model_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  const char *requested_path; // eax
  vostok::memory::base_allocator *v3; // [esp-10h] [ebp-68h]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::jump_logic_state_landing,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::jump_logic_state_landing *>,boost::arg<1> > > f; // [esp+4h] [ebp-54h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > result; // [esp+30h] [ebp-28h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+38h] [ebp-20h] BYREF

  f = (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::jump_logic_state_landing,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::jump_logic_state_landing *>,boost::arg<1> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&result, (void (__thiscall *)(vostok::sound::sound_debug_stats *))survarium::damage_model_cook::on_hit_params_received, (vostok::sound::sound_debug_stats *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)f.f_.f_,
    &callback);
  if ( boost::detail::function::basic_vtable1<void,boost::system::error_code>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::http_client,boost::system::error_code>,boost::_bi::list2<boost::_bi::value<vostok::network::http_client *>,boost::arg<1>>>>(
         (boost::detail::function::basic_vtable1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &> *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::damage_model_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::damage_model_cook *>,boost::arg<1>>>>'::`2'::stored_vtable,
         f,
         &callback.functor) )
  {
    callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::damage_model_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::damage_model_cook *>,boost::arg<1>>>>'::`2'::stored_vtable.base.manager
                                                             + 1);
  }
  else
  {
    callback.vtable = 0;
  }
  v3 = (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_;
  requested_path = vostok::resources::query_result_for_user::get_requested_path(parent);
  vostok::resources::query_resource(
    requested_path,
    binary_config_class_impl,
    (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
    v3,
    0,
    parent,
    assert_on_fail_true);
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&callback);
}
