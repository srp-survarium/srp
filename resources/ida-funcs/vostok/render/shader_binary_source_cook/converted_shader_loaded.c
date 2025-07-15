void __thiscall vostok::render::shader_binary_source_cook::converted_shader_loaded(
        vostok::render::shader_binary_source_cook *this,
        vostok::render::conveted_shader_loaded_data *data,
        vostok::resources::queries_result *result)
{
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *p_m_managed_resource; // esi
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *p_shader_source; // eax
  vostok::resources::managed_resource *m_object; // ecx
  vostok::resources::queries_result *v6; // edx
  int v7; // eax
  unsigned int v8; // ecx
  vostok::render::enum_shader_type shader_type; // ecx
  vostok::render::binary_shader_source *new_resource; // eax
  vostok::resources::query_result_for_cook *v11; // ecx
  vostok::render::binary_shader_cook_data *cook_data; // eax
  vostok::render::grass_render_model *v13; // ecx
  void *m_reconstruction_info_actuality_tick_high; // esi
  void *v15; // esi
  vostok::configs::binary_config *v16; // [esp-10h] [ebp-34h]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v17; // [esp-Ch] [ebp-30h] BYREF
  const vostok::resources::memory_type *v18; // [esp-8h] [ebp-2Ch]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v19; // [esp-4h] [ebp-28h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v20; // [esp+14h] [ebp-10h] BYREF
  vostok::resources::pinned_ptr_const<unsigned char> ptr_managed; // [esp+18h] [ebp-Ch] BYREF

  p_m_managed_resource = &result->m_queries[0].m_managed_resource;
  v20.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &v20,
    &result->m_queries[0].m_managed_resource);
  p_shader_source = &data->new_resource->shader_source;
  m_object = 0;
  if ( v20.m_object )
  {
    m_object = v20.m_object;
    _InterlockedExchangeAdd(&v20.m_object->m_reference_count, 1u);
  }
  v6 = (vostok::resources::queries_result *)p_shader_source->m_object;
  p_shader_source->m_object = m_object;
  result = v6;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&result);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v20);
  if ( !data->new_resource->shader_source.m_object )
    vostok::debug::debug_message_box("data->new_resource->shader_source == 0");
  result = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&result,
    p_m_managed_resource);
  v19.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &v19,
    (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&result);
  vostok::resources::pinned_ptr_base<unsigned char const>::pinned_ptr_base<unsigned char const>(
    &ptr_managed,
    (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)v19.m_object);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&result);
  v7 = 264 * *(_DWORD *)ptr_managed.m_data + 4;
  v8 = ptr_managed.m_size - v7;
  data->new_resource->m_shader_byte_code = (void *)&ptr_managed.m_data[v7];
  data->new_resource->m_shader_byte_code_size = v8;
  data->new_resource->configuration = data->cook_data->configuration;
  vostok::fs_new::virtual_path_string::operator=(&data->new_resource->shader_name, &data->cook_data->shader_name);
  shader_type = data->cook_data->shader_type;
  new_resource = data->new_resource;
  v19.m_object = (vostok::resources::managed_resource *)584;
  v18 = &vostok::resources::nocache_memory;
  new_resource->shader_type = shader_type;
  v16 = (vostok::configs::binary_config *)data->new_resource;
  v17.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v17,
    v16);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    data->in_out_query,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v17.m_object,
    v18,
    (unsigned int)v19.m_object);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v11,
    result_success,
    assert_on_fail_true,
    error_type_unset);
  cook_data = data->cook_data;
  v13 = vostok::render::g_allocator.m_object;
  if ( cook_data )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, cook_data);
    data->cook_data = 0;
    v13 = vostok::render::g_allocator.m_object;
  }
  v15 = (void *)HIDWORD(v13->m_reconstruction_info_actuality_tick);
  BYTE2(v13->m_children_resources.m_lock) = 0;
  vostok_mspace_free(v15, data);
  vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>((vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)&ptr_managed);
}
