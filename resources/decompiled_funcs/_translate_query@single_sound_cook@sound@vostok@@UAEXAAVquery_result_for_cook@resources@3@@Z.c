void __thiscall vostok::sound::single_sound_cook::translate_query(
        vostok::sound::single_sound_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  vostok::memory::base_allocator *v2; // eax
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v4; // [esp+14h] [ebp-16Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > result; // [esp+68h] [ebp-118h] BYREF
  void (__thiscall *f)(vostok::sound::single_sound_cook *, vostok::resources::queries_result *); // [esp+78h] [ebp-108h]
  int f_4; // [esp+7Ch] [ebp-104h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+80h] [ebp-100h] BYREF
  vostok::math::float4x4 v9; // [esp+A4h] [ebp-DCh] BYREF
  const vostok::math::float4x4 *matrix_pointers[3]; // [esp+E4h] [ebp-9Ch] BYREF
  vostok::resources::request request_array[3]; // [esp+F0h] [ebp-90h] BYREF
  vostok::resources::query_resource_params params; // [esp+108h] [ebp-78h] BYREF
  const char *req_path; // [esp+170h] [ebp-10h]
  vostok::resources::autoselect_quality_bool autoselect_quality[3]; // [esp+174h] [ebp-Ch] BYREF

  req_path = vostok::resources::query_result_for_user::get_requested_path(parent);
  request_array[0].path = req_path;
  request_array[0].id = encoded_sound_interface_class;
  request_array[1].path = req_path;
  request_array[1].id = sound_rms_class;
  request_array[2].path = req_path;
  request_array[2].id = sound_spl_class;
  autoselect_quality[0] = autoselect_quality_true;
  autoselect_quality[1] = autoselect_quality_false;
  autoselect_quality[2] = autoselect_quality_false;
  matrix_pointers[0] = vostok::math::float4x4::identity(&v9);
  matrix_pointers[1] = 0;
  matrix_pointers[2] = 0;
  f = vostok::sound::single_sound_cook::on_sub_resources_loaded;
  f_4 = 0;
  v4 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
          (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&result,
          (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)vostok::sound::single_sound_cook::on_sub_resources_loaded,
          (survarium::weapon_core_animation_end_aware_state *)this);
  callback.vtable = 0;
  if ( boost::detail::function::basic_vtable1<void,vostok::sound::create_sound_propagator_params const &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_scene,vostok::sound::create_sound_propagator_params const &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_scene *>,boost::arg<1>>>>(
         &`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::single_sound_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::single_sound_cook *>,boost::arg<1>>>>'::`2'::stored_vtable,
         (boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > >)v4,
         &callback.functor) )
  {
    callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::single_sound_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::single_sound_cook *>,boost::arg<1>>>>'::`2'::stored_vtable.base.manager
                                                             + 1);
  }
  else
  {
    callback.vtable = 0;
  }
  v2 = vostok::resources::unmanaged_allocator();
  vostok::resources::query_resource_params::query_resource_params(
    &params,
    request_array,
    0,
    3u,
    &callback,
    v2,
    0,
    matrix_pointers,
    0,
    parent,
    0,
    0,
    0,
    0,
    query_type_normal,
    0,
    autoselect_quality,
    assert_on_fail_true);
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&callback);
  vostok::resources::query_resources(&params);
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&params.callback);
}
