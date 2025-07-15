void __cdecl vostok::animation::skeleton_animation_cook::on_bi_spline_animation_arrived(
        vostok::resources::queries_result *result)
{
  vostok::resources::query_result_for_cook *m_result; // ecx
  vostok::configs::binary_config *v2; // edi
  vostok::configs::binary_config *m_object; // eax
  vostok::resources::unmanaged_intrusive_base *v4; // ecx
  boost::function<void __cdecl(vostok::resources::queries_result &)> *v5; // ecx
  vostok::resources::query_result_for_cook *m_parent_query; // ecx
  void (__cdecl *v7)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v8)(vostok::resources::queries_result *, vostok::resources::resource_ptr<vostok::animation::bi_spline_skeleton_animation_baked,vostok::resources::unmanaged_intrusive_base>); // [esp-Ch] [ebp-54h]
  boost::arg<1> v9; // [esp-8h] [ebp-50h]
  boost::_bi::bind_t<void,void (__cdecl*)(vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::animation::bi_spline_skeleton_animation_baked,vostok::resources::unmanaged_intrusive_base>),boost::_bi::list2<boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::animation::bi_spline_skeleton_animation_baked,vostok::resources::unmanaged_intrusive_base> > > > v10; // [esp-8h] [ebp-50h]
  vostok::resources::resource_ptr<vostok::animation::bi_spline_skeleton_animation_baked,vostok::resources::unmanaged_intrusive_base> v11; // [esp-4h] [ebp-4Ch]
  int v12; // [esp+0h] [ebp-48h]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v13; // [esp+10h] [ebp-38h] BYREF
  vostok::variant<32> *user_data; // [esp+14h] [ebp-34h] BYREF
  vostok::resources::creation_request requests; // [esp+18h] [ebp-30h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+28h] [ebp-20h] BYREF

  m_result = (vostok::resources::query_result_for_cook *)result->m_result;
  if ( m_result == (vostok::resources::query_result_for_cook *)1 )
  {
    v2 = 0;
    v13.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v13,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&result->m_queries[0].m_unmanaged_resource);
    m_object = v13.m_object;
    if ( v13.m_object )
    {
      v4 = &v13.m_object->vostok::resources::unmanaged_intrusive_base;
      v2 = v13.m_object;
      _InterlockedExchangeAdd(&v13.m_object->m_reference_count, 1u);
      if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(v4, m_object);
    }
    v8 = 0;
    if ( v2 )
    {
      v8 = (void (__cdecl *)(vostok::resources::queries_result *, vostok::resources::resource_ptr<vostok::animation::bi_spline_skeleton_animation_baked,vostok::resources::unmanaged_intrusive_base>))v2;
      _InterlockedExchangeAdd(&v2->m_reference_count, 1u);
    }
    boost::bind<void,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::animation::bi_spline_skeleton_animation_baked,vostok::resources::unmanaged_intrusive_base>,boost::arg<1>,vostok::resources::resource_ptr<vostok::animation::bi_spline_skeleton_animation_baked,vostok::resources::unmanaged_intrusive_base>>(
      (boost::_bi::bind_t<void,void (__cdecl*)(vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::animation::bi_spline_skeleton_animation_baked,vostok::resources::unmanaged_intrusive_base>),boost::_bi::list2<boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::animation::bi_spline_skeleton_animation_baked,vostok::resources::unmanaged_intrusive_base> > > > *)*(unsigned __int8 *)&1_263,
      v8,
      v9,
      v11);
    boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
      v5,
      v10,
      v12);
    m_parent_query = result->m_parent_query;
    requests.m_name = (const char *)&buf;
    requests.m_data.m_data = (const char *)v2;
    requests.m_data.m_size = 4;
    requests.m_id = cubic_spline_skeleton_animation_class;
    user_data = 0;
    vostok::resources::query_create_resources(
      &requests,
      1u,
      &callback,
      &vostok::memory::g_resources_helper_allocator,
      (const vostok::variant<32> **)&user_data,
      m_parent_query,
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
    if ( v2 )
    {
      if ( !_InterlockedExchangeAdd(&v2->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v2->vostok::resources::unmanaged_intrusive_base, v2);
    }
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
