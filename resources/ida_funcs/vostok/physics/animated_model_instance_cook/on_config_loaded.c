void __thiscall vostok::physics::animated_model_instance_cook::on_config_loaded(
        vostok::physics::animated_model_instance_cook *this,
        vostok::resources::queries_result *data)
{
  volatile int m_result; // edx
  vostok::resources::query_result_for_cook *m_parent_query; // ecx
  vostok::configs::binary_config *m_object; // esi
  vostok::configs::binary_config_value *v6; // eax
  boost::function1<void,vostok::resources::queries_result &> *v7; // ecx
  void (__cdecl *v8)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::configs::binary_config *v9; // eax
  vostok::resources::unmanaged_intrusive_base *v10; // ecx
  vostok::memory::base_allocator *m_allocator; // [esp-10h] [ebp-170h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::physics::animated_model_instance_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::physics::animated_model_instance_cook *>,boost::arg<1> > > v12; // [esp-8h] [ebp-168h]
  const char *pointer; // [esp-4h] [ebp-164h]
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> config; // [esp+10h] [ebp-150h] BYREF
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v15; // [esp+14h] [ebp-14Ch] BYREF
  vostok::variant<32> *user_data; // [esp+18h] [ebp-148h] BYREF
  vostok::resources::query_result_for_cook *parent; // [esp+1Ch] [ebp-144h]
  vostok::resources::request requests; // [esp+20h] [ebp-140h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+28h] [ebp-138h] BYREF
  vostok::fs_new::virtual_path_string skeleton_config_path; // [esp+48h] [ebp-118h] BYREF

  m_result = data->m_result;
  m_parent_query = data->m_parent_query;
  parent = m_parent_query;
  if ( m_result == 1 )
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
    v6 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                   config.m_object->m_root,
                                                   "attributes");
    pointer = (const char *)vostok::configs::binary_config_value::operator[](v6, "skeleton")->data.pointer;
    skeleton_config_path.m_string.m_end = skeleton_config_path.m_string.m_buffer;
    skeleton_config_path.m_string.m_begin = skeleton_config_path.m_string.m_buffer;
    skeleton_config_path.m_string.m_max_end = &skeleton_config_path.m_separator;
    skeleton_config_path.m_string.m_buffer[0] = 0;
    skeleton_config_path.m_separator = 47;
    vostok::fs_new::path_string_impl::assignf(
      &skeleton_config_path,
      "resources/models/%s.skinned_model/skeleton",
      pointer);
    v12.l_.a1_.t_ = this;
    v12.f_.f_ = vostok::physics::animated_model_instance_cook::on_skeleton_config_loaded;
    callback.vtable = 0;
    boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::physics::animated_model_instance_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::physics::animated_model_instance_cook *>,boost::arg<1>>>>(
      v7,
      (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::physics::animated_model_instance_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::physics::animated_model_instance_cook *>,boost::arg<1> > > *)&callback,
      v12);
    requests.path = skeleton_config_path.m_string.m_begin;
    m_allocator = this->m_allocator;
    requests.id = binary_config_class_impl;
    user_data = 0;
    vostok::resources::query_resources(
      &requests,
      1u,
      (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
      m_allocator,
      (const vostok::variant<32> **)&user_data,
      parent,
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
      m_parent_query,
      result_error,
      assert_on_fail_true,
      error_type_cook_failed);
  }
}
