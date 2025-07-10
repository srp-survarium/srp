void __thiscall survarium::game_material_manager_cook::translate_query(
        survarium::game_material_manager_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *v2; // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_core_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_cook *>,boost::arg<1> > > v3; // [esp+4h] [ebp-74h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > result; // [esp+30h] [ebp-48h] BYREF
  void (__userpurge *f)(survarium::game_material_manager_cook *@<ecx>, float@<xmm0>, vostok::resources::queries_result *); // [esp+40h] [ebp-38h]
  int f_4; // [esp+44h] [ebp-34h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+48h] [ebp-30h] BYREF
  vostok::resources::request r[2]; // [esp+68h] [ebp-10h] BYREF

  r[0].path = "resources/game_materials/game.materials";
  r[0].id = binary_config_class_impl;
  r[1].path = "resources/game_materials/material.pairs";
  r[1].id = binary_config_class_impl;
  f = survarium::game_material_manager_cook::on_configs_loaded;
  f_4 = 0;
  v2 = boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
         (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&result,
         (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)survarium::game_material_manager_cook::on_configs_loaded,
         (survarium::weapon_core_animation_end_aware_state *)this);
  v3 = *(boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_core_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_cook *>,boost::arg<1> > > *)v2;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)HIDWORD(v2->f_.f_),
    &callback);
  if ( boost::detail::function::basic_vtable2<bool,char const *,enum survarium::hit_affects_type_enum>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::mf2<bool,survarium::artefact_lifebone_core,char const *,enum survarium::hit_affects_type_enum>,boost::_bi::list3<boost::_bi::value<survarium::artefact_lifebone_core *>,boost::arg<1>,boost::arg<2>>>>(
         (boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::game_material_manager_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::game_material_manager_cook *>,boost::arg<1>>>>'::`2'::stored_vtable,
         v3,
         &callback.functor) )
  {
    callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::game_material_manager_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::game_material_manager_cook *>,boost::arg<1>>>>'::`2'::stored_vtable.base.manager
                                                             + 1);
  }
  else
  {
    callback.vtable = 0;
  }
  vostok::resources::query_resources<2>(
    parent,
    assert_on_fail_true,
    (const vostok::resources::request (*)[2])r,
    &callback,
    (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_,
    0);
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&callback);
}
