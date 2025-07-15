void __thiscall vostok::render::shader_binary_source_cook::converted_shader_loaded(
        vostok::render::shader_binary_source_cook *this,
        vostok::render::conveted_shader_loaded_data *data,
        vostok::resources::queries_result *result)
{
  vostok::resources::query_result *m_queries; // esi
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *managed_resource; // eax
  vostok::resources::managed_resource *new_resource; // ecx
  vostok::resources::pinned_ptr_mutable<unsigned char> *v6; // ecx
  int v7; // ecx
  int v8; // eax
  vostok::render::binary_shader_cook_data *cook_data; // esi
  vostok::render::shader_configuration *p_configuration; // edi
  survarium::pure_game_effect_emitter_base *v11; // ecx
  vostok::render::enum_shader_type shader_type; // eax
  vostok::resources::query_result_for_cook *v13; // ecx
  vostok::resources::query_result_for_cook *v14; // ecx
  vostok::memory::doug_lea_allocator *v15; // ecx
  vostok::resources::pinned_ptr_const<unsigned char> *v16; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v17; // [esp-Ch] [ebp-24h] BYREF
  const vostok::resources::memory_type *v18; // [esp-8h] [ebp-20h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v19[4]; // [esp-4h] [ebp-1Ch] BYREF
  _BYTE v20[4]; // [esp+Ch] [ebp-Ch] BYREF
  _DWORD *v21; // [esp+10h] [ebp-8h]
  int v22; // [esp+14h] [ebp-4h]

  m_queries = result->m_queries;
  managed_resource = vostok::resources::query_result_for_user::get_managed_resource(
                       &result->m_queries[0],
                       (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&result);
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
    managed_resource,
    &data->new_resource->shader_source);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&result);
  new_resource = (vostok::resources::managed_resource *)data->new_resource;
  if ( !new_resource[1].m_children_resources.m_lock )
    MessageBoxA(0, "data->new_resource->shader_source == 0", "Debug Break", 0);
  v19[0].m_object = new_resource;
  vostok::resources::query_result_for_user::get_managed_resource(m_queries, v19);
  vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
    v6,
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)v20,
    v19[0]);
  v7 = v22;
  v8 = 264 * *v21 + 4;
  data->new_resource->m_shader_byte_code = (char *)v21 + v8;
  data->new_resource->m_shader_byte_code_size = v7 - v8;
  cook_data = data->cook_data;
  p_configuration = &data->new_resource->configuration;
  *(_DWORD *)&p_configuration->0 = cook_data->configuration.0;
  cook_data = (vostok::render::binary_shader_cook_data *)((char *)cook_data + 4);
  p_configuration = (vostok::render::shader_configuration *)((char *)p_configuration + 4);
  *(_DWORD *)&p_configuration->0 = cook_data->configuration.0;
  cook_data = (vostok::render::binary_shader_cook_data *)((char *)cook_data + 4);
  p_configuration = (vostok::render::shader_configuration *)((char *)p_configuration + 4);
  *(_DWORD *)&p_configuration->0 = cook_data->configuration.0;
  HIDWORD(p_configuration->configuration[0]) = HIDWORD(cook_data->configuration.configuration[0]);
  vostok::shared_string::operator=(&data->new_resource->shader_name, &data->cook_data->shader_name);
  v11 = (survarium::pure_game_effect_emitter_base *)data->new_resource;
  shader_type = data->cook_data->shader_type;
  v19[0].m_object = (vostok::resources::managed_resource *)312;
  v18 = &vostok::resources::nocache_memory;
  v17.m_object = v11;
  v11[1].m_children_resources.m_lock = shader_type;
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    &v17,
    (survarium::pure_game_effect_emitter_base *)data->new_resource);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    v13,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)data->in_out_query,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v17.m_object,
    v18,
    (unsigned int)v19[0].m_object);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v14,
    (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)data->in_out_query,
    result_out_of_memory,
    assert_on_fail_true,
    result_fail);
  vostok::memory::doug_lea_allocator::free_impl(
    v15,
    (int)vostok::render::g_allocator,
    (char *)data,
    (const char *const)v19[1].m_object,
    (const char *const)v19[2].m_object,
    (const unsigned int)v19[3].m_object);
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>(
    v16,
    (int)v20);
}
