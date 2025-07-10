void __thiscall vostok::render::skeleton_model_instance_cook::on_skeleton_config_loaded(
        vostok::render::skeleton_model_instance_cook *this,
        vostok::resources::queries_result *result,
        vostok::render::skeleton_model_instance_cook_data *cook_data)
{
  vostok::resources::query_result_for_cook *m_result; // ecx
  vostok::configs::binary_config *m_object; // edi
  vostok::configs::binary_config *v5; // ebx
  vostok::resources::query_result_for_cook *parent_query; // edx
  void (__cdecl *v7)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::skeleton_model_instance_cook,vostok::resources::queries_result &,vostok::render::skeleton_model_instance_cook_data *>,boost::_bi::list3<boost::_bi::value<vostok::render::skeleton_model_instance_cook *>,boost::arg<1>,boost::_bi::value<vostok::render::skeleton_model_instance_cook_data *> > > v8; // [esp-Ch] [ebp-17Ch]
  int v9; // [esp+0h] [ebp-170h]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v10; // [esp+10h] [ebp-160h] BYREF
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> config; // [esp+14h] [ebp-15Ch] BYREF
  vostok::variant<32> *user_data; // [esp+18h] [ebp-158h] BYREF
  vostok::render::skeleton_model_instance_cook *v13; // [esp+1Ch] [ebp-154h]
  char *other; // [esp+20h] [ebp-150h] BYREF
  vostok::resources::request requests; // [esp+24h] [ebp-14Ch] BYREF
  __int64 v16; // [esp+2Ch] [ebp-144h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+38h] [ebp-138h] BYREF
  vostok::fs_new::virtual_path_string path; // [esp+58h] [ebp-118h] BYREF

  v13 = this;
  m_result = (vostok::resources::query_result_for_cook *)result->m_result;
  if ( m_result == (vostok::resources::query_result_for_cook *)1 )
  {
    v10.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v10,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&result->m_queries[0].m_unmanaged_resource);
    m_object = v10.m_object;
    config.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &config,
      v10.m_object);
    if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &m_object->vostok::resources::unmanaged_intrusive_base,
        m_object);
    v5 = config.m_object;
    other = (char *)vostok::configs::binary_config_value::operator[](config.m_object->m_root, "skeleton")->data.pointer;
    vostok::fs_new::virtual_path_string::virtual_path_string(&path, (const char **)&other);
    HIDWORD(v16) = v13;
    LODWORD(v16) = vostok::render::skeleton_model_instance_cook::on_skeleton_loaded;
    *(_QWORD *)&v8.f_.f_ = v16;
    v8.l_.a3_.t_ = cook_data;
    boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
      (boost::function<void __cdecl(vostok::resources::queries_result &)> *)cook_data,
      (int)&callback,
      (unsigned int)cook_data,
      v8,
      v9);
    parent_query = cook_data->parent_query;
    requests.path = path.m_string.m_begin;
    requests.id = skeleton_class;
    user_data = 0;
    vostok::resources::query_resources(
      &requests,
      1u,
      (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
      (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object,
      (const vostok::variant<32> **)&user_data,
      parent_query,
      assert_on_fail_true);
    if ( callback.vtable )
    {
      if ( ((int)callback.vtable & 1) == 0 )
      {
        v7 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
        if ( v7 )
          v7(&callback.functor, &callback.functor, 2);
      }
    }
    if ( !_InterlockedExchangeAdd(&v5->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v5->vostok::resources::unmanaged_intrusive_base, v5);
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      m_result,
      (int)cook_data->parent_query,
      result_error,
      assert_on_fail_true,
      (vostok::resources::query_result_for_cook *)0xB);
  }
}
