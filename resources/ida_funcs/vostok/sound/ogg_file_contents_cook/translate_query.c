void __thiscall vostok::sound::ogg_file_contents_cook::translate_query(
        vostok::sound::ogg_file_contents_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v3; // [esp+10h] [ebp-58h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > result; // [esp+28h] [ebp-40h] BYREF
  void (__thiscall *f)(vostok::sound::ogg_file_contents_cook *, vostok::resources::queries_result *); // [esp+38h] [ebp-30h]
  int f_4; // [esp+3Ch] [ebp-2Ch]
  boost::function1<void,vostok::resources::queries_result &> v7; // [esp+40h] [ebp-28h] BYREF
  vostok::resources::request request_array[1]; // [esp+60h] [ebp-8h] BYREF

  request_array[0].path = vostok::resources::query_result_for_user::get_requested_path(parent);
  request_array[0].id = ogg_raw_file;
  f = vostok::sound::ogg_file_contents_cook::on_sub_resources_loaded;
  f_4 = 0;
  v3 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
          (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&result,
          (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)vostok::sound::ogg_file_contents_cook::on_sub_resources_loaded,
          (survarium::weapon_core_animation_end_aware_state *)this);
  v7.vtable = 0;
  boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::ogg_file_contents_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::ogg_file_contents_cook *>,boost::arg<1>>>>(
    &v7,
    (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::ogg_file_contents_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::ogg_file_contents_cook *>,boost::arg<1> > >)v3);
  vostok::resources::query_resources(
    request_array,
    1u,
    (const boost::function<void __cdecl(vostok::resources::queries_result &)> *)&v7,
    parent->m_user_allocator,
    0,
    parent,
    assert_on_fail_true);
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v7);
}
