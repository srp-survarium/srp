void __thiscall survarium::weapon_user_animations_container_cook::translate_query(
        survarium::weapon_user_animations_container_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  const char *requested_path; // eax
  const char *v3; // eax
  vostok::memory::base_allocator *v4; // [esp-10h] [ebp-19Ch]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v6; // [esp+4h] [ebp-188h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > result; // [esp+3Ch] [ebp-150h] BYREF
  void (__thiscall *f)(survarium::weapon_user_animations_container_cook *, vostok::resources::queries_result *); // [esp+4Ch] [ebp-140h]
  int f_4; // [esp+50h] [ebp-13Ch]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+54h] [ebp-138h] BYREF
  vostok::fs_new::virtual_path_string config_name; // [esp+74h] [ebp-118h] BYREF

  vostok::fs_new::virtual_path_string::virtual_path_string(&config_name);
  requested_path = vostok::resources::query_result_for_user::get_requested_path(parent);
  vostok::fs_new::path_string_impl::assignf(&config_name, "resources/%s", requested_path);
  f = survarium::weapon_user_animations_container_cook::on_config_loaded;
  f_4 = 0;
  v6 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
          (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&result,
          (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)survarium::weapon_user_animations_container_cook::on_config_loaded,
          (survarium::weapon_core_animation_end_aware_state *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v6.l_.a1_.t_,
    &callback);
  if ( boost::detail::function::basic_vtable2<bool,char const *,enum survarium::hit_affects_type_enum>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::mf2<bool,survarium::artefact_lifebone_core,char const *,enum survarium::hit_affects_type_enum>,boost::_bi::list3<boost::_bi::value<survarium::artefact_lifebone_core *>,boost::arg<1>,boost::arg<2>>>>(
         (boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_user_animations_container_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_user_animations_container_cook *>,boost::arg<1>>>>'::`2'::stored_vtable,
         (boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_core_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_cook *>,boost::arg<1> > >)v6,
         &callback.functor) )
  {
    callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_user_animations_container_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_user_animations_container_cook *>,boost::arg<1>>>>'::`2'::stored_vtable.base.manager
                                                             + 1);
  }
  else
  {
    callback.vtable = 0;
  }
  v4 = (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_;
  v3 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&config_name);
  vostok::resources::query_resource(
    v3,
    binary_config_class_impl,
    (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
    v4,
    0,
    parent,
    assert_on_fail_true);
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&callback);
}
