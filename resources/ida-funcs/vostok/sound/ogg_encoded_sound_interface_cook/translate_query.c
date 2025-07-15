void __thiscall vostok::sound::ogg_encoded_sound_interface_cook::translate_query(
        vostok::sound::ogg_encoded_sound_interface_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  const char *requested_path; // eax
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v4; // [esp+10h] [ebp-188h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > result; // [esp+38h] [ebp-160h] BYREF
  void (__thiscall *f)(vostok::sound::ogg_encoded_sound_interface_cook *, vostok::resources::queries_result *); // [esp+48h] [ebp-150h]
  int f_4; // [esp+4Ch] [ebp-14Ch]
  boost::function1<void,vostok::resources::queries_result &> v8; // [esp+50h] [ebp-148h] BYREF
  vostok::resources::request request_array[1]; // [esp+74h] [ebp-124h] BYREF
  vostok::resources::class_id_enum type; // [esp+7Ch] [ebp-11Ch]
  vostok::fs_new::virtual_path_string req_path; // [esp+80h] [ebp-118h] BYREF

  vostok::fixed_string<260>::fixed_string<260>(&req_path.m_string);
  req_path.m_separator = 47;
  requested_path = vostok::resources::query_result_for_user::get_requested_path(parent);
  vostok::fs_new::path_string_impl::assignf(&req_path, "%s%s%s", "resources/sounds/single/", requested_path, ".ogg");
  type = ogg_raw_file;
  request_array[0].path = req_path.m_string.m_begin;
  request_array[0].id = ogg_raw_file;
  f = vostok::sound::ogg_encoded_sound_interface_cook::on_sub_resources_loaded;
  f_4 = 0;
  v4 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
          (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&result,
          (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)vostok::sound::ogg_encoded_sound_interface_cook::on_sub_resources_loaded,
          (survarium::weapon_core_animation_end_aware_state *)this);
  v8.vtable = 0;
  boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::ogg_encoded_sound_interface_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::ogg_encoded_sound_interface_cook *>,boost::arg<1>>>>(
    &v8,
    (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::ogg_encoded_sound_interface_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::ogg_encoded_sound_interface_cook *>,boost::arg<1> > >)v4);
  vostok::resources::query_resources(
    request_array,
    1u,
    (const boost::function<void __cdecl(vostok::resources::queries_result &)> *)&v8,
    parent->m_user_allocator,
    0,
    parent,
    assert_on_fail_true);
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v8);
}
