void __thiscall vostok::sound::sound_environment_cook::translate_query(
        vostok::sound::sound_environment_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v3; // [esp+14h] [ebp-1A4h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > result; // [esp+50h] [ebp-168h] BYREF
  void (__thiscall *f)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *); // [esp+60h] [ebp-158h]
  int f_4; // [esp+64h] [ebp-154h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+68h] [ebp-150h] BYREF
  char v8; // [esp+8Eh] [ebp-12Ah]
  char v9; // [esp+8Fh] [ebp-129h]
  vostok::fixed_string<256> path; // [esp+90h] [ebp-128h] BYREF
  vostok::render::static_model_instance_user_data model_user_data; // [esp+1A4h] [ebp-14h] BYREF
  bool success; // [esp+1B3h] [ebp-5h]
  const char *model_name; // [esp+1B4h] [ebp-4h]

  v9 = 0;
  model_user_data.sound_scene.m_object = 0;
  success = vostok::variant<32>::try_get<vostok::render::static_model_instance_user_data>(
              parent->m_user_data,
              &model_user_data);
  v8 = 0;
  model_name = (const char *)vostok::configs::binary_config_value::operator[](
                               (vostok::configs::binary_config_value *)model_user_data.config,
                               "lib_name")->data.pointer;
  vostok::fixed_string<256>::fixed_string<256>(&path);
  vostok::buffer_string::assignf(&path, "resources/models/%s.model/render/export_properties", model_name);
  f = vostok::sound::sound_environment_cook::on_model_config_loaded;
  f_4 = 0;
  v3 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
          (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&result,
          (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)vostok::sound::sound_environment_cook::on_model_config_loaded,
          (survarium::weapon_core_animation_end_aware_state *)this);
  callback.vtable = 0;
  if ( boost::detail::function::basic_vtable1<void,vostok::sound::create_sound_propagator_params const &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_scene,vostok::sound::create_sound_propagator_params const &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_scene *>,boost::arg<1>>>>(
         &`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>>>>'::`2'::stored_vtable,
         (boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > >)v3,
         &callback.functor) )
  {
    callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>>>>'::`2'::stored_vtable.base.manager
                                                             + 1);
  }
  else
  {
    callback.vtable = 0;
  }
  vostok::resources::query_resource(
    path.m_begin,
    binary_config_class_impl,
    &callback,
    (vostok::memory::base_allocator *)vostok::sound::g_allocator.m_object,
    0,
    parent,
    assert_on_fail_true);
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&callback);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&model_user_data.sound_scene);
}
