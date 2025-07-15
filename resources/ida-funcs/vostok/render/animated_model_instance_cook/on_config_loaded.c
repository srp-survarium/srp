void __thiscall vostok::render::animated_model_instance_cook::on_config_loaded(
        vostok::render::animated_model_instance_cook *this,
        vostok::resources::queries_result *data)
{
  vostok::resources::query_result_for_cook *m_parent_query; // ebx
  vostok::resources::query_result_for_cook *m_result; // ecx
  vostok::configs::binary_config *m_object; // esi
  vostok::configs::binary_config_value *v5; // eax
  const char *pointer; // esi
  boost::function<void __cdecl(vostok::resources::queries_result &)> *v7; // ecx
  void (__cdecl *v8)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::configs::binary_config *v9; // eax
  vostok::resources::unmanaged_intrusive_base *v10; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v11; // [esp-10h] [ebp-288h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::animated_model_instance_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::list3<boost::_bi::value<vostok::render::animated_model_instance_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > > > v12; // [esp-Ch] [ebp-284h] BYREF
  int v13; // [esp+0h] [ebp-278h]
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> config; // [esp+Ch] [ebp-26Ch] BYREF
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v15; // [esp+10h] [ebp-268h] BYREF
  void (__thiscall *f)(vostok::render::animated_model_instance_cook *, vostok::resources::queries_result *, vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>); // [esp+14h] [ebp-264h]
  vostok::resources::request requests[2]; // [esp+18h] [ebp-260h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+28h] [ebp-250h] BYREF
  vostok::fs_new::virtual_path_string skeleton_config_path; // [esp+48h] [ebp-230h] BYREF
  vostok::fs_new::virtual_path_string model_config_path; // [esp+160h] [ebp-118h] BYREF

  m_parent_query = data->m_parent_query;
  f = (void (__thiscall *)(vostok::render::animated_model_instance_cook *, vostok::resources::queries_result *, vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>))this;
  m_result = (vostok::resources::query_result_for_cook *)data->m_result;
  if ( m_result == (vostok::resources::query_result_for_cook *)1 )
  {
    v15.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v15,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[0].m_unmanaged_resource);
    m_object = v15.m_object;
    config.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &config,
      v15.m_object);
    if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &m_object->vostok::resources::unmanaged_intrusive_base,
        m_object);
    v5 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                   config.m_object->m_root,
                                                   "attributes");
    pointer = (const char *)vostok::configs::binary_config_value::operator[](v5, "render_model")->data.pointer;
    skeleton_config_path.m_string.m_begin = skeleton_config_path.m_string.m_buffer;
    skeleton_config_path.m_string.m_end = skeleton_config_path.m_string.m_buffer;
    skeleton_config_path.m_string.m_max_end = &skeleton_config_path.m_separator;
    skeleton_config_path.m_string.m_buffer[0] = 0;
    skeleton_config_path.m_separator = 47;
    vostok::fs_new::path_string_impl::assignf(
      &skeleton_config_path,
      "resources/models/%s.skinned_model/skeleton",
      pointer);
    model_config_path.m_string.m_begin = model_config_path.m_string.m_buffer;
    model_config_path.m_string.m_end = model_config_path.m_string.m_buffer;
    model_config_path.m_string.m_max_end = &model_config_path.m_separator;
    model_config_path.m_string.m_buffer[0] = 0;
    model_config_path.m_separator = 47;
    vostok::fs_new::path_string_impl::assignf(&model_config_path, "resources/models/%s.skinned_model/settings", pointer);
    requests[0].id = binary_config_class_impl;
    requests[1].id = binary_config_class_impl;
    requests[0].path = skeleton_config_path.m_string.m_begin;
    requests[1].path = model_config_path.m_string.m_begin;
    v11.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v11,
      &config);
    boost::bind<void,vostok::render::animated_model_instance_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,vostok::render::animated_model_instance_cook *,boost::arg<1>,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>(
      (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v12,
      (boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::animated_model_instance_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::list3<boost::_bi::value<vostok::render::animated_model_instance_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > > > *)vostok::render::animated_model_instance_cook::on_skeleton_config_loaded,
      (vostok::render::animated_model_instance_cook *)f,
      (boost::_bi::list3<boost::_bi::value<vostok::render::animated_model_instance_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > > *)*(unsigned __int8 *)&1_68,
      (vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>)v11.m_object);
    boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
      v7,
      v12,
      v13);
    vostok::resources::query_resources(
      requests,
      2u,
      (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
      &vostok::memory::g_resources_unmanaged_allocator,
      0,
      m_parent_query,
      assert_on_fail_true);
    if ( callback.vtable )
    {
      if ( ((int)callback.vtable & 1) == 0 )
      {
        v8 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
        if ( v8 )
          v8(&callback.functor, &callback.functor, 2);
      }
    }
    v9 = config.m_object;
    v10 = &config.m_object->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&config.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v10, v9);
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      m_result,
      result_error,
      assert_on_fail_true,
      error_type_cook_failed);
  }
}
