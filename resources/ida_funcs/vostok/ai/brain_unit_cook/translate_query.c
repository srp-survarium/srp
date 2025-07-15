void __thiscall vostok::ai::brain_unit_cook::translate_query(
        vostok::ai::brain_unit_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *v2; // eax
  vostok::resources::query_result_for_cook *v3; // ecx
  const char *requested_path; // eax
  vostok::memory::doug_lea_allocator *v5; // [esp-10h] [ebp-78h]
  vostok::variant<32> *v6; // [esp-Ch] [ebp-74h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_core_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_cook *>,boost::arg<1> > > v7; // [esp+4h] [ebp-64h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > result; // [esp+30h] [ebp-38h] BYREF
  void (__thiscall *f)(vostok::ai::brain_unit_cook *, vostok::resources::queries_result *); // [esp+40h] [ebp-28h]
  int f_4; // [esp+44h] [ebp-24h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+48h] [ebp-20h] BYREF

  f = vostok::ai::brain_unit_cook::on_brain_unit_options_received;
  f_4 = 0;
  v2 = boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
         (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&result,
         (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)vostok::ai::brain_unit_cook::on_brain_unit_options_received,
         (survarium::weapon_core_animation_end_aware_state *)this);
  v7 = *(boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_core_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_cook *>,boost::arg<1> > > *)v2;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)HIDWORD(v2->f_.f_),
    &callback);
  if ( boost::detail::function::basic_vtable2<bool,char const *,enum survarium::hit_affects_type_enum>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::mf2<bool,survarium::artefact_lifebone_core,char const *,enum survarium::hit_affects_type_enum>,boost::_bi::list3<boost::_bi::value<survarium::artefact_lifebone_core *>,boost::arg<1>,boost::arg<2>>>>(
         (boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::brain_unit_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::ai::brain_unit_cook *>,boost::arg<1>>>>'::`2'::stored_vtable,
         v7,
         &callback.functor) )
  {
    v3 = (vostok::resources::query_result_for_cook *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::brain_unit_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::ai::brain_unit_cook *>,boost::arg<1>>>>'::`2'::stored_vtable.base.manager
                                                    + 1);
    callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::brain_unit_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::ai::brain_unit_cook *>,boost::arg<1>>>>'::`2'::stored_vtable.base.manager
                                                             + 1);
  }
  else
  {
    callback.vtable = 0;
  }
  v6 = vostok::resources::query_result_for_cook::user_data(v3, (int)parent);
  v5 = vostok::ai::g_allocator;
  requested_path = vostok::resources::query_result_for_user::get_requested_path(parent);
  vostok::resources::query_resource(
    requested_path,
    binary_config_class_impl,
    (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
    v5,
    v6,
    parent,
    assert_on_fail_true);
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&callback);
}
