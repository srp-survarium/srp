void __thiscall vostok::render::material_effects_instance_cook::on_material_ready(
        vostok::render::material_effects_instance_cook *this,
        vostok::resources::queries_result *data,
        vostok::render::material_effects_instance_cook_data *cook_data)
{
  char v3; // bl
  vostok::configs::binary_config *m_object; // esi
  vostok::render::material_effects_instance_cook_data *v5; // edi
  vostok::configs::binary_config *v6; // eax
  vostok::configs::binary_config *v7; // ecx
  vostok::resources::unmanaged_resource *v8; // eax
  vostok::resources::query_result_for_cook *v9; // ecx
  void (__cdecl *v10)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  vostok::resources::query_result_for_cook *m_parent_query; // eax
  char *m_requery_path; // eax
  void (__cdecl *v13)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v14; // [esp+10h] [ebp-28h] BYREF
  vostok::resources::query_result_for_cook *parent; // [esp+14h] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+18h] [ebp-20h] BYREF

  v3 = 0;
  v14.m_object = 0;
  parent = (vostok::resources::query_result_for_cook *)this;
  if ( data->m_queries[0].m_error_type || data->m_queries[0].m_create_resource_result == result_error )
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render_pc_dx11:", error) )
    {
      v10 = vostok::core::g_log_callback;
      log_callback.vtable = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          &log_callback.functor,
          &log_callback.functor,
          destroy_functor_tag);
      if ( v10 )
      {
        log_callback.functor.obj_ptr = v10;
        log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                     + 1);
      }
      else
      {
        log_callback.vtable = 0;
      }
      m_parent_query = data->m_parent_query;
      v3 = 1;
      if ( m_parent_query->m_requery_path )
        m_requery_path = m_parent_query->m_requery_path;
      else
        m_requery_path = m_parent_query->m_request_path;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\material_effects_instance_cook.cpp",
        0xA1u,
        "void __thiscall vostok::render::material_effects_instance_cook::on_material_ready(class vostok::resources::queri"
        "es_result &,struct vostok::render::material_effects_instance_cook_data *)",
        "render_pc_dx11:",
        error,
        (const char *)&stru_960860.destroyer,
        m_requery_path);
    }
    if ( (v3 & 1) != 0 )
    {
      if ( log_callback.vtable )
      {
        if ( ((int)log_callback.vtable & 1) == 0 )
        {
          v13 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
          if ( v13 )
            v13(&log_callback.functor, &log_callback.functor, 2);
        }
      }
    }
    vostok::resources::query_result_for_cook::finish_query_impl(
      v9,
      result_error,
      assert_on_fail_false,
      error_type_cook_failed);
    if ( cook_data->delete_in_cook )
      vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,vostok::render::material_effects_instance_cook_data,vostok::memory::detail::call_destructor_predicate>(
        (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
        (vostok::resources::unmanaged_resource ***)&cook_data);
  }
  else
  {
    v14.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v14,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[0].m_unmanaged_resource);
    m_object = v14.m_object;
    v5 = cook_data;
    v6 = 0;
    if ( v14.m_object )
    {
      v6 = v14.m_object;
      _InterlockedExchangeAdd(&v14.m_object->m_reference_count, 1u);
    }
    v7 = v6;
    v8 = v5->material.m_object;
    v5->material.m_object = v7;
    if ( v8 && !_InterlockedExchangeAdd(&v8->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v8->vostok::resources::unmanaged_intrusive_base, v8);
    if ( m_object )
    {
      if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(
          &m_object->vostok::resources::unmanaged_intrusive_base,
          m_object);
    }
    vostok::render::material_effects_instance_cook::query_effects(
      (vostok::render::material_effects_instance_cook *)data->m_parent_query,
      (vostok::render::material_effects_instance_cook *)parent,
      data->m_parent_query,
      v5);
  }
}
