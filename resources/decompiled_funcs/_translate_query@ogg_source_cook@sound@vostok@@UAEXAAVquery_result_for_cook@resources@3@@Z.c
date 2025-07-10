void __thiscall vostok::sound::ogg_source_cook::translate_query(
        vostok::sound::ogg_source_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::game_material_manager_cook,vostok::resources::queries_result &,survarium::vector<survarium::game_material_manager_cook::query_ext_data> *>,boost::_bi::list3<boost::_bi::value<survarium::game_material_manager_cook *>,boost::arg<1>,boost::_bi::value<survarium::vector<survarium::game_material_manager_cook::query_ext_data> *> > > v3; // [esp+Ch] [ebp-184h]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > result; // [esp+38h] [ebp-158h] BYREF
  void (__thiscall *f)(vostok::sound::ogg_source_cook *, vostok::resources::queries_result *, vostok::resources::query_result_for_cook *); // [esp+48h] [ebp-148h]
  int f_4; // [esp+4Ch] [ebp-144h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+50h] [ebp-140h] BYREF
  char *src; // [esp+74h] [ebp-11Ch] BYREF
  vostok::fs_new::virtual_path_string ogg_path; // [esp+78h] [ebp-118h] BYREF

  src = (char *)vostok::resources::query_result_for_user::get_requested_path(parent);
  vostok::fs_new::path_string_impl::path_string_impl(&ogg_path, 47, (const char **)&src);
  f = vostok::sound::ogg_source_cook::on_ogg_file_loaded;
  f_4 = 0;
  v3 = *boost::bind<void,vostok::ai::brain_unit_cook,vostok::resources::queries_result &,vostok::ai::brain_unit *,vostok::ai::brain_unit_cook *,boost::arg<1>,vostok::ai::brain_unit *>(
          (boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::game_material_manager_cook,vostok::resources::queries_result &,survarium::vector<survarium::game_material_manager_cook::query_ext_data> *>,boost::_bi::list3<boost::_bi::value<survarium::game_material_manager_cook *>,boost::arg<1>,boost::_bi::value<survarium::vector<survarium::game_material_manager_cook::query_ext_data> *> > > *)&result,
          (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *, vostok::math::float4x4 *))(unsigned int)vostok::sound::ogg_source_cook::on_ogg_file_loaded,
          (survarium::game_material_manager_cook *)this,
          1_12,
          (vostok::math::float4x4 *)parent);
  callback.vtable = 0;
  if ( boost::detail::function::basic_vtable1<void,vostok::sound::create_sound_propagator_params const &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_scene,vostok::sound::create_sound_propagator_params const &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_scene *>,boost::arg<1>>>>(
         &`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::ogg_source_cook,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *>,boost::_bi::list3<boost::_bi::value<vostok::sound::ogg_source_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *>>>>'::`2'::stored_vtable,
         (boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > >)v3,
         &callback.functor) )
  {
    callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::ogg_source_cook,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *>,boost::_bi::list3<boost::_bi::value<vostok::sound::ogg_source_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *>>>>'::`2'::stored_vtable.base.manager
                                                             + 1);
  }
  else
  {
    callback.vtable = 0;
  }
  vostok::resources::query_resource(
    ogg_path.m_string.m_begin,
    raw_data_class,
    &callback,
    &vostok::memory::g_mt_allocator,
    0,
    parent,
    assert_on_fail_true);
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&callback);
}
