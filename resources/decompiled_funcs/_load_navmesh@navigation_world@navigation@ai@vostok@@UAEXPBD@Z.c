void __thiscall vostok::ai::navigation::navigation_world::load_navmesh(
        vostok::ai::navigation::navigation_world *this,
        const char *project_name)
{
  _BYTE *v2; // eax
  vostok::strings::detail::tuples *v3; // ecx
  void *v4; // esp
  vostok::strings::detail::tuples *v5; // ecx
  survarium::game_camera *v6; // ecx
  char *v7; // eax
  _DWORD v8[3]; // [esp+0h] [ebp-D0h] BYREF
  vostok::ai::navigation::navigation_world *thisa; // [esp+Ch] [ebp-C4h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_core_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_cook *>,boost::arg<1> > > v10; // [esp+10h] [ebp-C0h]
  char *v11; // [esp+20h] [ebp-B0h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > result; // [esp+58h] [ebp-78h] BYREF
  void (__thiscall *f)(vostok::ai::navigation::navigation_world *, vostok::resources::queries_result *); // [esp+68h] [ebp-68h]
  int f_4; // [esp+6Ch] [ebp-64h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+70h] [ebp-60h] BYREF
  char v16; // [esp+97h] [ebp-39h]
  vostok::strings::detail::tuples STR_JOINA_tuples_unique_identifier; // [esp+98h] [ebp-38h] BYREF
  char *full_path; // [esp+CCh] [ebp-4h]

  thisa = this;
  full_path = 0;
  v16 = 1;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v2 )
  {
    vostok::strings::detail::tuples::tuples(
      &STR_JOINA_tuples_unique_identifier,
      "resources/projects/",
      project_name,
      "/navmesh.lua");
    v4 = alloca(vostok::strings::detail::tuples::size(v3, (unsigned int *)&STR_JOINA_tuples_unique_identifier));
    v8[2] = v8;
    vostok::strings::detail::tuples::size(v5, (unsigned int *)&STR_JOINA_tuples_unique_identifier);
    survarium::weapon_user_dead_state::finalize(v6);
    full_path = v7;
    vostok::strings::detail::tuples::concat(v7, &STR_JOINA_tuples_unique_identifier);
  }
  f = vostok::ai::navigation::navigation_world::on_binary_config_resource;
  f_4 = 0;
  v10 = *(boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_core_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_cook *>,boost::arg<1> > > *)boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>((boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&result, (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)vostok::ai::navigation::navigation_world::on_binary_config_resource, (survarium::weapon_core_animation_end_aware_state *)thisa);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)HIDWORD(v10.f_.f_),
    &callback);
  if ( boost::detail::function::basic_vtable2<bool,char const *,enum survarium::hit_affects_type_enum>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::mf2<bool,survarium::artefact_lifebone_core,char const *,enum survarium::hit_affects_type_enum>,boost::_bi::list3<boost::_bi::value<survarium::artefact_lifebone_core *>,boost::arg<1>,boost::arg<2>>>>(
         (boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::navigation::navigation_world,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::ai::navigation::navigation_world *>,boost::arg<1>>>>'::`2'::stored_vtable,
         v10,
         &callback.functor) )
  {
    v11 = (char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::navigation::navigation_world,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::ai::navigation::navigation_world *>,boost::arg<1>>>>'::`2'::stored_vtable.base.manager
        + 1;
    callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::navigation::navigation_world,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::ai::navigation::navigation_world *>,boost::arg<1>>>>'::`2'::stored_vtable.base.manager
                                                             + 1);
  }
  else
  {
    callback.vtable = 0;
  }
  vostok::resources::query_resource(
    full_path,
    binary_config_class_impl,
    &callback,
    vostok::ai::navigation::g_allocator,
    0,
    0,
    assert_on_fail_true);
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&callback);
}
