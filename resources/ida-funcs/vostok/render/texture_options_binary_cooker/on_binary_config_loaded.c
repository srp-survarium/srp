void __thiscall vostok::render::texture_options_binary_cooker::on_binary_config_loaded(
        vostok::render::texture_options_binary_cooker *this,
        vostok::resources::queries_result *result)
{
  vostok::resources::query_result_for_cook *m_parent_query; // ebx
  vostok::resources::unmanaged_resource *m_object; // esi
  vostok::resources::memory_usage_type *p_m_memory_usage_self; // edi
  vostok::resources::query_result_for_cook *v6; // ecx
  vostok::buffer_string *m_requery_path; // ecx
  char *m_buffer; // eax
  boost::function1<void,vostok::resources::queries_result &> *v9; // ecx
  void (__cdecl *v10)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::texture_options_binary_cooker,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::render::texture_options_binary_cooker *>,boost::arg<1> > > v11; // [esp-8h] [ebp-158h] BYREF
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> resource; // [esp+Ch] [ebp-144h] BYREF
  vostok::resources::request requests; // [esp+10h] [ebp-140h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+18h] [ebp-138h] BYREF
  vostok::fs_new::virtual_path_string path; // [esp+38h] [ebp-118h] BYREF

  resource.m_object = 0;
  m_parent_query = result->m_parent_query;
  if ( result->m_queries[0].m_error_type || result->m_queries[0].m_create_resource_result == result_error )
  {
    path.m_string.m_begin = path.m_string.m_buffer;
    m_requery_path = (vostok::buffer_string *)m_parent_query->m_requery_path;
    path.m_string.m_max_end = &path.m_separator;
    path.m_separator = 47;
    if ( !m_requery_path )
      m_requery_path = (vostok::buffer_string *)m_parent_query->m_request_path;
    m_buffer = path.m_string.m_buffer;
    path.m_string.m_end = path.m_string.m_buffer;
    path.m_string.m_buffer[0] = 0;
    if ( m_requery_path )
    {
      for ( ; LOBYTE(m_requery_path->m_begin); ++path.m_string.m_end )
      {
        if ( m_buffer >= path.m_string.m_max_end )
          break;
        *m_buffer = (char)m_requery_path->m_begin;
        m_buffer = path.m_string.m_end + 1;
        m_requery_path = (vostok::buffer_string *)((char *)m_requery_path + 1);
      }
      *m_buffer = 0;
    }
    vostok::buffer_string::replace(m_requery_path, "resources/", "resources.sources/");
    v11.l_.a1_.t_ = this;
    v11.f_.f_ = vostok::render::texture_options_binary_cooker::on_lua_options_loaded;
    callback.vtable = 0;
    boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::texture_options_binary_cooker,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::render::texture_options_binary_cooker *>,boost::arg<1>>>>(
      v9,
      (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::texture_options_binary_cooker,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::render::texture_options_binary_cooker *>,boost::arg<1> > > *)&callback,
      v11);
    requests.path = path.m_string.m_begin;
    requests.id = texture_options_lua_class;
    resource.m_object = 0;
    vostok::resources::query_resources(
      &requests,
      1u,
      &callback,
      &vostok::memory::g_resources_unmanaged_allocator,
      (const vostok::variant<32> **)&resource,
      m_parent_query,
      assert_on_fail_true);
    if ( callback.vtable )
    {
      if ( ((int)callback.vtable & 1) == 0 )
      {
        v10 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
        if ( v10 )
          v10(&callback.functor, &callback.functor, 2);
      }
    }
  }
  else
  {
    resource.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&resource,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&result->m_queries[0].m_unmanaged_resource);
    m_object = resource.m_object;
    p_m_memory_usage_self = &resource.m_object->m_memory_usage_self;
    v11.l_.a1_.t_ = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v11.l_,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&resource);
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      m_parent_query,
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v11.l_.a1_.t_,
      p_m_memory_usage_self);
    vostok::resources::query_result_for_cook::finish_query_impl(
      v6,
      result_success,
      assert_on_fail_true,
      error_type_unset);
    if ( m_object )
    {
      if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(
          &m_object->vostok::resources::unmanaged_intrusive_base,
          m_object);
    }
  }
}
