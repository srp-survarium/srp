void __thiscall vostok::sound::sound_spl_cook::translate_query(
        vostok::sound::sound_spl_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  const char *requested_path; // eax
  vostok::memory::base_allocator *v3; // eax
  const char *request_path; // [esp+Ch] [ebp-190h]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::game_material_manager_cook,vostok::resources::queries_result &,survarium::vector<survarium::game_material_manager_cook::query_ext_data> *>,boost::_bi::list3<boost::_bi::value<survarium::game_material_manager_cook *>,boost::arg<1>,boost::_bi::value<survarium::vector<survarium::game_material_manager_cook::query_ext_data> *> > > v6; // [esp+10h] [ebp-18Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > result; // [esp+4Ch] [ebp-150h] BYREF
  void (__thiscall *f)(vostok::sound::sound_spl_cook *, vostok::resources::queries_result *, vostok::resources::query_result_for_cook *); // [esp+5Ch] [ebp-140h]
  int f_4; // [esp+60h] [ebp-13Ch]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+64h] [ebp-138h] BYREF
  vostok::fs_new::virtual_path_string source_path; // [esp+84h] [ebp-118h] BYREF

  vostok::fixed_string<260>::fixed_string<260>(&source_path.m_string);
  source_path.m_separator = 47;
  requested_path = vostok::resources::query_result_for_user::get_requested_path(parent);
  vostok::fs_new::path_string_impl::assignf(
    &source_path,
    "resources/sounds/single/%s.single_sound_options",
    requested_path);
  f = vostok::sound::sound_spl_cook::on_config_loaded;
  f_4 = 0;
  v6 = *boost::bind<void,vostok::ai::brain_unit_cook,vostok::resources::queries_result &,vostok::ai::brain_unit *,vostok::ai::brain_unit_cook *,boost::arg<1>,vostok::ai::brain_unit *>(
          (boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::game_material_manager_cook,vostok::resources::queries_result &,survarium::vector<survarium::game_material_manager_cook::query_ext_data> *>,boost::_bi::list3<boost::_bi::value<survarium::game_material_manager_cook *>,boost::arg<1>,boost::_bi::value<survarium::vector<survarium::game_material_manager_cook::query_ext_data> *> > > *)&result,
          (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *, vostok::math::float4x4 *))(unsigned int)vostok::sound::sound_spl_cook::on_config_loaded,
          (survarium::game_material_manager_cook *)this,
          1_3,
          (vostok::math::float4x4 *)parent);
  callback.vtable = 0;
  if ( boost::detail::function::basic_vtable1<void,vostok::sound::create_sound_propagator_params const &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_scene,vostok::sound::create_sound_propagator_params const &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_scene *>,boost::arg<1>>>>(
         &`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_spl_cook,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_spl_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *>>>>'::`2'::stored_vtable,
         (boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > >)v6,
         &callback.functor) )
  {
    callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_spl_cook,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_spl_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *>>>>'::`2'::stored_vtable.base.manager
                                                             + 1);
  }
  else
  {
    callback.vtable = 0;
  }
  request_path = source_path.m_string.m_begin;
  v3 = vostok::resources::unmanaged_allocator();
  vostok::resources::query_resource(
    request_path,
    binary_config_class_impl,
    &callback,
    v3,
    0,
    parent,
    assert_on_fail_true);
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&callback);
}
