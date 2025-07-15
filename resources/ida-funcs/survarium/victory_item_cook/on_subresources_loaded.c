void __thiscall survarium::victory_item_cook::on_subresources_loaded(
        survarium::victory_item_cook *this,
        vostok::resources::queries_result *data,
        survarium::victory_item *object_to_cook)
{
  volatile int m_result; // ecx
  char v4; // bl
  vostok::resources::query_result_for_cook *v5; // ecx
  void (__cdecl *v6)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // ebx
  char *m_requery_path; // eax
  void (__cdecl *v8)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::configs::binary_config *m_object; // ebx
  vostok::configs::binary_config *v10; // esi
  survarium::victory_item *v11; // edi
  vostok::configs::binary_config *v12; // eax
  vostok::render::static_model_instance *v13; // ecx
  vostok::render::static_model_instance *v14; // eax
  vostok::configs::binary_config *v15; // eax
  vostok::resources::query_result_for_cook *v16; // edi
  vostok::resources::query_result_for_cook *v17; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v18; // [esp-4h] [ebp-44h] BYREF
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v19; // [esp+10h] [ebp-30h] BYREF
  vostok::resources::query_result_for_cook *parent; // [esp+14h] [ebp-2Ch]
  vostok::resources::memory_usage_type memory_usage; // [esp+18h] [ebp-28h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+20h] [ebp-20h] BYREF

  m_result = data->m_result;
  v4 = 0;
  parent = data->m_parent_query;
  if ( m_result == 1 )
  {
    v19.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v19,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[0].m_unmanaged_resource);
    m_object = v19.m_object;
    v10 = 0;
    if ( v19.m_object )
    {
      v10 = v19.m_object;
      _InterlockedExchangeAdd(&v19.m_object->m_reference_count, 1u);
    }
    v11 = object_to_cook;
    v12 = 0;
    if ( v10 )
    {
      v12 = v10;
      _InterlockedExchangeAdd(&v10->m_reference_count, 1u);
    }
    v13 = (vostok::render::static_model_instance *)v12;
    v14 = object_to_cook->m_model.m_object;
    object_to_cook->m_model.m_object = v13;
    if ( v14 )
    {
      if ( !_InterlockedExchangeAdd(&v14->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v14->vostok::resources::unmanaged_intrusive_base, v14);
      v11 = object_to_cook;
    }
    if ( v10 && !_InterlockedExchangeAdd(&v10->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v10->vostok::resources::unmanaged_intrusive_base, v10);
    if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &m_object->vostok::resources::unmanaged_intrusive_base,
        m_object);
    if ( v11 )
      v15 = (vostok::configs::binary_config *)&v11->vostok::resources::unmanaged_resource;
    else
      v15 = 0;
    memory_usage.type = &vostok::resources::nocache_memory;
    memory_usage.size = 376;
    v18.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v18,
      v15);
    v16 = parent;
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      &memory_usage,
      parent,
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v18.m_object);
    vostok::resources::query_result_for_cook::finish_query_impl(v17, (int)v16, result_success, assert_on_fail_true, 0);
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", error) )
    {
      v6 = vostok::core::g_log_callback;
      log_callback.vtable = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          &log_callback.functor,
          &log_callback.functor,
          destroy_functor_tag);
      if ( v6 )
      {
        log_callback.functor.obj_ptr = v6;
        log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                     + 1);
      }
      else
      {
        log_callback.vtable = 0;
      }
      m_requery_path = data->m_queries[0].m_requery_path;
      v4 = 1;
      if ( !m_requery_path )
        m_requery_path = data->m_queries[0].m_request_path;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\victory_item_cooker.cpp",
        0x39u,
        "void __thiscall survarium::victory_item_cook::on_subresources_loaded(class vostok::resources::queries_result &,c"
        "lass survarium::victory_item *)",
        "game:",
        error,
        "Wrong data in [%s]",
        m_requery_path);
    }
    if ( (v4 & 1) != 0 && log_callback.vtable && ((int)log_callback.vtable & 1) == 0 )
    {
      v8 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
      if ( v8 )
        v8(&log_callback.functor, &log_callback.functor, 2);
    }
    vostok::resources::query_result_for_cook::finish_query_impl(
      v5,
      (int)parent,
      result_error,
      assert_on_fail_true,
      (vostok::resources::query_result_for_cook *)0xB);
  }
}
