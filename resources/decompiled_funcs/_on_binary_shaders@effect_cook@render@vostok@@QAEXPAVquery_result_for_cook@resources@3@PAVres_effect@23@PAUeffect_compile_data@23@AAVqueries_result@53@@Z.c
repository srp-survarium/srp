void __thiscall vostok::render::effect_cook::on_binary_shaders(
        vostok::render::effect_cook *this,
        vostok::resources::query_result_for_cook *in_out_query,
        vostok::render::res_effect *effect_resource,
        vostok::render::effect_compile_data *compile_data,
        vostok::resources::query_result_for_cook *data)
{
  vostok::resources::query_result_for_cook *p_m_transform; // ecx
  vostok::render::binary_shader_source *v6; // esi
  unsigned int m_last; // eax
  char v8; // bl
  vostok::resources::unmanaged_resource *v9; // ecx
  vostok::resources::unmanaged_resource *v10; // eax
  unsigned __int64 v11; // xmm0_8
  unsigned __int64 v12; // xmm1_8
  vostok::render::enum_shader_type shader_type; // edi
  vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base> *v14; // eax
  vostok::resources::unmanaged_resource *m_object; // edx
  vostok::render::grass_render_model *v16; // ebx
  vostok::render::custom_config *v17; // eax
  vostok::render::custom_config *v18; // esi
  vostok::render::grass_render_model *v19; // ecx
  malloc_state *v20; // esi
  vostok::render::grass_render_model *v21; // ecx
  vostok::render::res_effect *v22; // ecx
  vostok::render::texture_named_instance *M_start; // esi
  vostok::render::texture_named_instance *i; // edi
  vostok::resources::query_result_for_cook *v25; // ecx
  vostok::render::custom_config *v26; // eax
  vostok::render::grass_render_model *v27; // ebx
  vostok::render::custom_config *v28; // esi
  vostok::render::grass_render_model *v29; // ecx
  malloc_state *m_reconstruction_info_actuality_tick_high; // esi
  vostok::render::effect_compiler *v31; // ecx
  char *v32; // eax
  vostok::render::grass_render_model *v33; // ecx
  vostok::render::res_effect *v34; // [esp-Ch] [ebp-91FCh]
  char v35; // [esp+13h] [ebp-91DDh]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v36; // [esp+14h] [ebp-91DCh]
  char *other; // [esp+18h] [ebp-91D8h] BYREF
  associative_vector<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,vostok::render::vector,stlp_std::less<vostok::render::binary_shader_key_type> > in_shader_sources; // [esp+1Ch] [ebp-91D4h] BYREF
  unsigned int v39; // [esp+2Ch] [ebp-91C4h]
  vostok::render::binary_shader_key_type key; // [esp+30h] [ebp-91C0h] BYREF
  vostok::render::effect_compiler v41; // [esp+158h] [ebp-9098h] BYREF

  p_m_transform = data;
  v6 = 0;
  other = 0;
  in_shader_sources.gap0 = v35;
  m_last = (unsigned int)data->m_children_resources.m_last;
  v8 = 0;
  memset(&in_shader_sources, 0, 12);
  v39 = 0;
  if ( !m_last )
    goto LABEL_19;
  p_m_transform = (vostok::resources::query_result_for_cook *)&data->m_transform;
  v36 = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&data->m_transform;
  while ( 1 )
  {
    if ( !p_m_transform->m_children_resources.m_size && p_m_transform->m_children_resources.m_lock != 1 )
    {
      v9 = (vostok::resources::unmanaged_resource *)p_m_transform->__vftable;
      v10 = 0;
      if ( v9 )
      {
        v10 = v9;
        _InterlockedExchangeAdd(&v9->m_reference_count, 1u);
      }
      if ( v10 )
      {
        v6 = (vostok::render::binary_shader_source *)v10;
        _InterlockedExchangeAdd(&v10->m_reference_count, 1u);
        if ( !_InterlockedExchangeAdd(&v10->m_reference_count, 0xFFFFFFFF) )
          vostok::resources::unmanaged_intrusive_base::destroy(&v10->vostok::resources::unmanaged_intrusive_base, v10);
      }
      v11 = v6->configuration.configuration[0];
      v12 = v6->configuration.configuration[1];
      shader_type = v6->shader_type;
      other = v6->shader_name.m_string.m_begin;
      key.configuration.configuration[0] = v11;
      key.configuration.configuration[1] = v12;
      vostok::fs_new::virtual_path_string::virtual_path_string(&key.shader_name, (const char **)&other);
      key.type = shader_type;
      v14 = associative_vector<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,vostok::render::vector,stlp_std::less<vostok::render::binary_shader_key_type>>::operator[](
              &key,
              &in_shader_sources);
      _InterlockedExchangeAdd(&v6->m_reference_count, 1u);
      m_object = v14->m_object;
      v14->m_object = v6;
      if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(
          &m_object->vostok::resources::unmanaged_intrusive_base,
          m_object);
      v8 = 1;
      if ( !_InterlockedExchangeAdd(&v6->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v6->vostok::resources::unmanaged_intrusive_base, v6);
      p_m_transform = (vostok::resources::query_result_for_cook *)v36;
    }
    p_m_transform = (vostok::resources::query_result_for_cook *)((char *)p_m_transform + 720);
    ++v39;
    v36 = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)p_m_transform;
    if ( (vostok::resources::resource_link *)v39 >= data->m_children_resources.m_last )
      break;
    v6 = 0;
  }
  if ( v8 )
  {
    vostok::render::effect_compiler::effect_compiler(&v41, effect_resource, in_out_query, 0, &in_shader_sources);
    compile_data->descriptor->compile(compile_data->descriptor, &v41, &compile_data->config.m_object->m_root);
    M_start = v41.m_ps_used_textures._M_impl._M_start;
    for ( i = v41.m_ps_used_textures._M_impl._M_finish; M_start != i; ++M_start )
      vostok::render::res_effect::push_texture_unique(
        v22,
        (int)effect_resource,
        M_start->texture,
        M_start->path.m_begin);
    v34 = 0;
    if ( effect_resource )
    {
      v34 = effect_resource;
      _InterlockedExchangeAdd(&effect_resource->m_reference_count, 1u);
    }
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      in_out_query,
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v34,
      &vostok::resources::nocache_memory,
      0x128u);
    vostok::resources::query_result_for_cook::finish_query_impl(
      v25,
      (int)in_out_query,
      result_success,
      assert_on_fail_true,
      0);
    if ( compile_data->add_to_array )
      vostok::render::effect_manager::add_effect(
        (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
        compile_data->descriptor,
        &compile_data->config,
        effect_resource);
    v26 = compile_data->config.m_object;
    v27 = vostok::render::g_allocator.m_object;
    if ( v26 && !_InterlockedExchangeAdd(&v26->m_reference_count, 0xFFFFFFFF) )
    {
      v28 = compile_data->config.m_object;
      if ( v28->call_destructors )
        vostok::render::custom_config_value::call_data_destructor(&v28->m_root);
      if ( v28->own_buffer )
      {
        v29 = vostok::render::g_allocator.m_object;
        if ( v28 )
        {
          BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
          vostok_mspace_free((malloc_state *)HIDWORD(v29->m_reconstruction_info_actuality_tick), (char *)v28);
        }
      }
    }
    m_reconstruction_info_actuality_tick_high = (malloc_state *)HIDWORD(v27->m_reconstruction_info_actuality_tick);
    BYTE2(v27->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, (char *)compile_data);
    vostok::render::effect_compiler::~effect_compiler(v31);
  }
  else
  {
LABEL_19:
    vostok::resources::query_result_for_cook::finish_query_impl(
      p_m_transform,
      (int)in_out_query,
      result_error,
      assert_on_fail_true,
      (vostok::resources::query_result_for_cook *)0xB);
    v16 = vostok::render::g_allocator.m_object;
    if ( compile_data )
    {
      v17 = compile_data->config.m_object;
      if ( v17 && !_InterlockedExchangeAdd(&v17->m_reference_count, 0xFFFFFFFF) )
      {
        v18 = compile_data->config.m_object;
        if ( v18->call_destructors )
          vostok::render::custom_config_value::call_data_destructor(&v18->m_root);
        if ( v18->own_buffer )
        {
          v19 = vostok::render::g_allocator.m_object;
          if ( v18 )
          {
            BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
            vostok_mspace_free((malloc_state *)HIDWORD(v19->m_reconstruction_info_actuality_tick), (char *)v18);
          }
        }
      }
      v20 = (malloc_state *)HIDWORD(v16->m_reconstruction_info_actuality_tick);
      BYTE2(v16->m_children_resources.m_lock) = 0;
      vostok_mspace_free(v20, (char *)compile_data);
    }
    ((void (__thiscall *)(vostok::render::res_effect *, _DWORD))effect_resource->~vostok::resources::resource_base)(
      effect_resource,
      0);
    v21 = vostok::render::g_allocator.m_object;
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free((malloc_state *)HIDWORD(v21->m_reconstruction_info_actuality_tick), (char *)effect_resource);
  }
  stlp_std::__destroy_range_aux<stlp_std::reverse_iterator<stlp_std::pair<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>> *>,stlp_std::pair<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>>>(
    (stlp_std::reverse_iterator<stlp_std::pair<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base> > *>)in_shader_sources._M_impl._M_finish,
    (stlp_std::reverse_iterator<stlp_std::pair<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base> > *>)in_shader_sources._M_impl._M_start);
  v32 = (char *)in_shader_sources._M_impl._M_start;
  if ( in_shader_sources._M_impl._M_start )
  {
    v33 = vostok::render::g_allocator.m_object;
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free((malloc_state *)HIDWORD(v33->m_reconstruction_info_actuality_tick), v32);
  }
}
