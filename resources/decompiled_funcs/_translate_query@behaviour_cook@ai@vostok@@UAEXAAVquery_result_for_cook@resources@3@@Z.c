void __thiscall vostok::ai::behaviour_cook::translate_query(
        vostok::ai::behaviour_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  vostok::resources::query_result_for_cook *v2; // ecx
  vostok::variant<32> *v3; // eax
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *v4; // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_core_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_cook *>,boost::arg<1> > > v6; // [esp+4h] [ebp-9Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > result; // [esp+48h] [ebp-58h] BYREF
  void (__thiscall *f)(vostok::ai::behaviour_cook *, vostok::resources::queries_result *); // [esp+58h] [ebp-48h]
  int f_4; // [esp+5Ch] [ebp-44h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+60h] [ebp-40h] BYREF
  vostok::ai::behaviour_cook_params cook_params; // [esp+84h] [ebp-1Ch] BYREF
  const char *persistent_options_path; // [esp+88h] [ebp-18h]
  vostok::resources::request requests[2]; // [esp+8Ch] [ebp-14h] BYREF
  unsigned int requests_size; // [esp+9Ch] [ebp-4h]

  persistent_options_path = "resources/brain_units/persistent/human.persistent_options";
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)this,
    &cook_params);
  v3 = vostok::resources::query_result_for_cook::user_data(v2, (int)parent);
  vostok::variant<32>::try_get<vostok::ai::behaviour_cook_params>(v3, &cook_params);
  requests_size = 2 - (cook_params.behaviour_config != 0);
  requests[0].id = binary_config_class_impl;
  requests[0].path = persistent_options_path;
  if ( !cook_params.behaviour_config )
  {
    requests[1].id = binary_config_class_impl;
    requests[1].path = vostok::resources::query_result_for_user::get_requested_path(parent);
  }
  f = vostok::ai::behaviour_cook::on_behaviour_options_received;
  f_4 = 0;
  v4 = boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
         (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&result,
         (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)vostok::ai::behaviour_cook::on_behaviour_options_received,
         (survarium::weapon_core_animation_end_aware_state *)this);
  v6 = *(boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_core_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_cook *>,boost::arg<1> > > *)v4;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)HIDWORD(v4->f_.f_),
    &callback);
  if ( boost::detail::function::basic_vtable2<bool,char const *,enum survarium::hit_affects_type_enum>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::mf2<bool,survarium::artefact_lifebone_core,char const *,enum survarium::hit_affects_type_enum>,boost::_bi::list3<boost::_bi::value<survarium::artefact_lifebone_core *>,boost::arg<1>,boost::arg<2>>>>(
         (boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::behaviour_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::ai::behaviour_cook *>,boost::arg<1>>>>'::`2'::stored_vtable,
         v6,
         &callback.functor) )
  {
    callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::behaviour_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::ai::behaviour_cook *>,boost::arg<1>>>>'::`2'::stored_vtable.base.manager
                                                             + 1);
  }
  else
  {
    callback.vtable = 0;
  }
  vostok::resources::query_resources(
    requests,
    requests_size,
    (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
    vostok::ai::g_allocator,
    0,
    parent,
    assert_on_fail_true);
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&callback);
}
