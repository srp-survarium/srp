void __thiscall survarium::artefact_container_core::spawn_artefact(survarium::artefact_container_core *this)
{
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+44h] [ebp-88h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_core_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_cook *>,boost::arg<1> > > v2; // [esp+64h] [ebp-68h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > result; // [esp+74h] [ebp-58h] BYREF
  void (__thiscall *f)(survarium::artefact_container_core *, vostok::resources::queries_result *); // [esp+88h] [ebp-44h]
  int f_4; // [esp+8Ch] [ebp-40h]
  unsigned __int16 value; // [esp+92h] [ebp-3Ah] BYREF
  vostok::variant<32> user_data; // [esp+94h] [ebp-38h] BYREF
  vostok::sound::sound_environment_cook *a1; // [esp+C8h] [ebp-4h]

  a1 = (vostok::sound::sound_environment_cook *)this;
  vostok::variant<32>::variant<32>(&user_data);
  value = 57;
  vostok::variant<32>::set<unsigned short>(&user_data, &value);
  f = survarium::artefact_container_core::artefact_spawned;
  f_4 = 0;
  v2 = *(boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_core_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_cook *>,boost::arg<1> > > *)boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>((boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&result, (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)survarium::artefact_container_core::artefact_spawned, (survarium::weapon_core_animation_end_aware_state *)a1);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v2.l_.a1_.t_,
    &callback);
  if ( boost::detail::function::basic_vtable2<bool,char const *,enum survarium::hit_affects_type_enum>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::mf2<bool,survarium::artefact_lifebone_core,char const *,enum survarium::hit_affects_type_enum>,boost::_bi::list3<boost::_bi::value<survarium::artefact_lifebone_core *>,boost::arg<1>,boost::arg<2>>>>(
         (boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::artefact_container_core,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::artefact_container_core *>,boost::arg<1>>>>'::`2'::stored_vtable,
         v2,
         &callback.functor) )
  {
    callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::artefact_container_core,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::artefact_container_core *>,boost::arg<1>>>>'::`2'::stored_vtable.base.manager
                                                             + 1);
  }
  else
  {
    callback.vtable = 0;
  }
  vostok::resources::query_resource(
    "gameplay/items/artefacts/lifebone",
    item_class,
    (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
    (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_,
    &user_data,
    0,
    assert_on_fail_true);
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&callback);
  vostok::variant<32>::~variant<32>(&user_data);
}
