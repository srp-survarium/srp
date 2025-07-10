void __thiscall vostok::sound::ogg_sound_cook::translate_query(
        vostok::sound::ogg_sound_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  const char *requested_path; // eax
  vostok::memory::base_allocator *v3; // eax
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v5; // [esp+Ch] [ebp-19Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > result; // [esp+48h] [ebp-160h] BYREF
  void (__thiscall *f)(vostok::sound::ogg_sound_cook *, vostok::resources::queries_result *); // [esp+58h] [ebp-150h]
  int f_4; // [esp+5Ch] [ebp-14Ch]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+60h] [ebp-148h] BYREF
  vostok::resources::request request_array[2]; // [esp+80h] [ebp-128h] BYREF
  vostok::fs_new::virtual_path_string req_path; // [esp+90h] [ebp-118h] BYREF

  vostok::fixed_string<260>::fixed_string<260>(&req_path.m_string);
  req_path.m_separator = 47;
  requested_path = vostok::resources::query_result_for_user::get_requested_path(parent);
  vostok::fs_new::path_string_impl::assignf(&req_path, "%s%s%s", "resources/sounds/single/", requested_path, ".ogg");
  request_array[0].path = req_path.m_string.m_begin;
  request_array[0].id = ogg_file_contents_class;
  request_array[1].path = req_path.m_string.m_begin;
  request_array[1].id = sound_rms_class;
  f = vostok::sound::ogg_sound_cook::on_sub_resources_loaded;
  f_4 = 0;
  v5 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
          (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&result,
          (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)vostok::sound::ogg_sound_cook::on_sub_resources_loaded,
          (survarium::weapon_core_animation_end_aware_state *)this);
  callback.vtable = 0;
  if ( boost::detail::function::basic_vtable1<void,vostok::sound::create_sound_propagator_params const &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_scene,vostok::sound::create_sound_propagator_params const &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_scene *>,boost::arg<1>>>>(
         &`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::ogg_sound_cook *>,boost::arg<1>>>>'::`2'::stored_vtable,
         (boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > >)v5,
         &callback.functor) )
  {
    callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::ogg_sound_cook *>,boost::arg<1>>>>'::`2'::stored_vtable.base.manager
                                                             + 1);
  }
  else
  {
    callback.vtable = 0;
  }
  v3 = vostok::resources::unmanaged_allocator();
  vostok::resources::query_resources(request_array, 2u, &callback, v3, 0, parent, assert_on_fail_true);
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&callback);
}
