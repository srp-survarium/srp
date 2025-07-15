void __thiscall vostok::render::material_cook::translate_query(
        vostok::render::material_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  vostok::variant<32> *m_user_data; // eax
  vostok::configs::binary_config *m_object; // esi
  char *m_requery_path; // eax
  boost::function1<void,vostok::resources::queries_result &> *v6; // ecx
  void (__cdecl *v7)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::material_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::render::material_cook *>,boost::arg<1> > > v8; // [esp-8h] [ebp-158h]
  vostok::configs::binary_config *v9; // [esp+0h] [ebp-150h]
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> cfg; // [esp+Ch] [ebp-144h] BYREF
  vostok::resources::request requests; // [esp+10h] [ebp-140h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+18h] [ebp-138h] BYREF
  vostok::fs_new::virtual_path_string path; // [esp+38h] [ebp-118h] BYREF

  m_user_data = parent->m_user_data;
  if ( m_user_data )
  {
    cfg.m_object = 0;
    vostok::variant<32>::try_get<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>(
      (vostok::variant<32> *)&cfg,
      (const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)m_user_data,
      &cfg);
    m_object = cfg.m_object;
    vostok::render::material_cook::on_material_binary_config_loaded(
      parent,
      (vostok::render::material_cook *)cfg.m_object,
      v9);
    if ( m_object )
    {
      if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(
          &m_object->vostok::resources::unmanaged_intrusive_base,
          m_object);
    }
  }
  else
  {
    path.m_string.m_max_end = &path.m_separator;
    m_requery_path = parent->m_requery_path;
    path.m_string.m_begin = path.m_string.m_buffer;
    path.m_string.m_end = path.m_string.m_buffer;
    path.m_string.m_buffer[0] = 0;
    path.m_separator = 47;
    if ( !m_requery_path )
      m_requery_path = parent->m_request_path;
    vostok::fs_new::path_string_impl::assignf(&path, "resources/material_instances/%s.material", m_requery_path);
    v8.l_.a1_.t_ = this;
    v8.f_.f_ = (void (__thiscall *)(vostok::render::material_cook *, vostok::resources::queries_result *))vostok::render::material_cook::on_material_config_loaded;
    callback.vtable = 0;
    boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::material_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::render::material_cook *>,boost::arg<1>>>>(
      v6,
      (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::material_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::render::material_cook *>,boost::arg<1> > > *)&callback,
      v8);
    requests.path = path.m_string.m_begin;
    requests.id = binary_config_class_impl;
    cfg.m_object = 0;
    vostok::resources::query_resources(
      &requests,
      1u,
      (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
      (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object,
      (const vostok::variant<32> **)&cfg,
      parent,
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
  }
}
