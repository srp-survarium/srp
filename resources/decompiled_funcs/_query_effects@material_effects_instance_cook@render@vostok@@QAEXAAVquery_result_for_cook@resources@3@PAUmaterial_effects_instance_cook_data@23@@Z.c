void __thiscall vostok::render::material_effects_instance_cook::query_effects(
        vostok::render::material_effects_instance_cook *this,
        vostok::render::material_effects_instance_cook *parent,
        vostok::resources::query_result_for_cook *cook_data,
        vostok::render::material_effects_instance_cook_data *cook_dataa)
{
  vostok::render::material *m_object; // eax
  vostok::resources::unmanaged_resource *v5; // ebp
  vostok::configs::binary_config_value *right; // eax
  const vostok::configs::binary_config_value *v7; // eax
  vostok::configs::binary_config_value *v8; // esi
  vostok::configs::binary_config_value *v9; // esi
  vostok::configs::binary_config_value *v10; // eax
  vostok::configs::binary_config_value *v11; // eax
  vostok::configs::binary_config_value *v12; // eax
  bool v13; // bl
  vostok::configs::binary_config_value *v14; // eax
  vostok::resources::query_result_for_cook *v15; // ecx
  vostok::configs::binary_config_value *v16; // eax
  vostok::render::enum_vertex_input_type vertex_input_type; // eax
  vostok::render::custom_config *v18; // eax
  vostok::render::custom_config *v19; // eax
  vostok::render::custom_config_value *v20; // ecx
  vostok::render::custom_config_value *v21; // ecx
  vostok::render::custom_config_value *v22; // ecx
  vostok::render::custom_config_value *v23; // ecx
  vostok::render::custom_config_value *v24; // ecx
  vostok::render::custom_config_value *v25; // ecx
  vostok::render::custom_config_value *v26; // ecx
  char v27; // bl
  vostok::render::effect_options_descriptor *v28; // eax
  vostok::render::effect_options_descriptor *v29; // ecx
  int cull_mode; // eax
  int v31; // esi
  vostok::render::effect_options_descriptor *v32; // eax
  vostok::variant<32> *v33; // ebp
  unsigned int v34; // edi
  vostok::resources::creation_request *v35; // esi
  vostok::variant<32> *v36; // eax
  const char **v37; // eax
  const char *v38; // ecx
  unsigned int v39; // eax
  vostok::render::enum_vertex_input_type v40; // edi
  vostok::variant<32> **v41; // ebx
  void (__cdecl *v42)(unsigned __int8 **, unsigned __int8 **, int); // eax
  int v43; // ebp
  vostok::render::enum_vertex_input_type v44; // esi
  int v45; // ecx
  vostok::render::grass_render_model *v46; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  void *v48; // esi
  void *v49; // esi
  vostok::render::custom_config *v50; // esi
  vostok::render::grass_render_model *v51; // ecx
  vostok::render::material *v52; // eax
  vostok::resources::unmanaged_intrusive_base *v53; // ecx
  const char *v54; // [esp+0h] [ebp-458h]
  const char *v55; // [esp+0h] [ebp-458h]
  const char *v56; // [esp+0h] [ebp-458h]
  bool with_vegetation; // [esp+10h] [ebp-448h]
  bool with_vegetation_1; // [esp+11h] [ebp-447h]
  char with_vegetation_2; // [esp+12h] [ebp-446h]
  vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> material_config; // [esp+14h] [ebp-444h] BYREF
  vostok::mutable_buffer v61; // [esp+18h] [ebp-440h] BYREF
  vostok::render::material_effects_instance_cook_data *v62; // [esp+20h] [ebp-438h]
  vostok::resources::resource_ptr<vostok::render::material,vostok::resources::unmanaged_intrusive_base> material; // [esp+24h] [ebp-434h] BYREF
  vostok::render::enum_vertex_input_type vertex_type; // [esp+28h] [ebp-430h]
  vostok::resources::creation_request *requests; // [esp+2Ch] [ebp-42Ch]
  unsigned int crc; // [esp+30h] [ebp-428h] BYREF
  vostok::variant<32> **user_data_variants_ptrs; // [esp+34h] [ebp-424h]
  vostok::render::effect_options_descriptor additional_parameters; // [esp+38h] [ebp-420h] BYREF
  unsigned __int8 data[1024]; // [esp+58h] [ebp-400h] BYREF

  v61.m_data = 0;
  m_object = (vostok::render::material *)cook_dataa->material.m_object;
  v5 = 0;
  vertex_type = cook_dataa->vertex_input_type;
  material.m_object = 0;
  if ( m_object )
  {
    v5 = m_object;
    material.m_object = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  right = (vostok::configs::binary_config_value *)v5[1].grm_satisfaction_tree_hook.left_[16].right_;
  crc = 0;
  v7 = vostok::configs::binary_config_value::operator[](right, "material");
  vostok::render::create_custom_config_impl_vostok::configs::binary_config_value__0(v7, &material_config.m_object, &crc);
  with_vegetation_2 = 0;
  v8 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                 (vostok::configs::binary_config_value *)v5[1].grm_satisfaction_tree_hook.left_[16].right_,
                                                 "material");
  if ( vostok::configs::binary_config_value::value_exists(v8, (const char *)&stru_960978) )
  {
    v9 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                   v8,
                                                   (const char *)&stru_960978);
    if ( vostok::configs::binary_config_value::value_exists(v9, (const char *)&stru_960978.id_crc) )
    {
      v10 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                      v9,
                                                      (const char *)&stru_960978.id_crc);
      with_vegetation = vostok::configs::binary_config_value::operator[](v10, (const char *)&stru_955964)->data.pointer != 0;
    }
    else
    {
      with_vegetation = 0;
    }
    if ( vostok::configs::binary_config_value::value_exists(v9, "with_skeletal_meshes") )
    {
      v11 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                      v9,
                                                      "with_skeletal_meshes");
      with_vegetation_1 = vostok::configs::binary_config_value::operator[](v11, (const char *)&stru_955964)->data.pointer != 0;
    }
    else
    {
      with_vegetation_1 = 0;
    }
    if ( vostok::configs::binary_config_value::value_exists(v9, "with_static_vertex_color_meshes") )
    {
      v12 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                      v9,
                                                      "with_static_vertex_color_meshes");
      v13 = vostok::configs::binary_config_value::operator[](v12, (const char *)&stru_955964)->data.pointer != 0;
    }
    else
    {
      v13 = 0;
    }
    if ( vostok::configs::binary_config_value::value_exists(v9, "with_static_meshes") )
    {
      v14 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                      v9,
                                                      "with_static_meshes");
      vostok::configs::binary_config_value::operator[](v14, (const char *)&stru_955964);
    }
    if ( vostok::configs::binary_config_value::value_exists(v9, "with_particles") )
    {
      v16 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                      v9,
                                                      "with_particles");
      LOBYTE(v15) = vostok::configs::binary_config_value::operator[](v16, (const char *)&stru_955964)->data.pointer != 0;
    }
    else
    {
      LOBYTE(v15) = 0;
    }
    vertex_input_type = cook_dataa->vertex_input_type;
    if ( cook_dataa->vertex_input_type == static_mesh_vertex_colored_input_type && !v13 )
    {
      vostok::resources::query_result_for_cook::finish_query_impl(
        v15,
        result_error,
        assert_on_fail_false,
        error_type_cook_failed);
      v18 = material_config.m_object;
      if ( material_config.m_object
        && !_InterlockedExchangeAdd(&material_config.m_object->m_reference_count, 0xFFFFFFFF) )
      {
        vostok::render::custom_config::destroy(v18, v18);
      }
      if ( !_InterlockedExchangeAdd(&v5->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v5->vostok::resources::unmanaged_intrusive_base, v5);
      return;
    }
    if ( vertex_input_type >= skeletal_4_bones_mesh_vertex_input_type
      && vertex_input_type <= skeletal_1_bones_mesh_vertex_input_type
      && !with_vegetation_1 )
    {
LABEL_28:
      vostok::resources::query_result_for_cook::finish_query_impl(
        v15,
        result_error,
        assert_on_fail_false,
        error_type_cook_failed);
      vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock>::~intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock>(&material_config);
      vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&material);
      return;
    }
    if ( vertex_input_type == grassmesh_vertex_input_type && !with_vegetation )
    {
      vostok::resources::query_result_for_cook::finish_query_impl(
        v15,
        result_error,
        assert_on_fail_false,
        error_type_cook_failed);
      v19 = material_config.m_object;
      if ( material_config.m_object
        && !_InterlockedExchangeAdd(&material_config.m_object->m_reference_count, 0xFFFFFFFF) )
      {
        vostok::render::custom_config::destroy(v19, v19);
      }
      vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&material);
      return;
    }
    if ( vertex_input_type >= particle_vertex_input_type
      && vertex_input_type <= particle_beamtrail_vertex_input_type
      && !(_BYTE)v15 )
    {
      goto LABEL_28;
    }
  }
  if ( cook_dataa->cull_mode
    && vostok::render::custom_config_value::value_exists(&stru_960978, v54)
    && (vostok::render::custom_config_value::operator[](v20, (const char *)&stru_960978),
        vostok::render::custom_config_value::value_exists(&stru_9609EC, v55))
    && (vostok::render::custom_config_value::operator[](v21, (const char *)&stru_960978),
        vostok::render::custom_config_value::operator[](v22, (const char *)&stru_9609EC),
        vostok::render::custom_config_value::value_exists(
          (vostok::render::custom_config_value *)&stru_9609EC.id_crc,
          v56)) )
  {
    vostok::render::custom_config_value::operator[](v23, (const char *)&stru_960978);
    vostok::render::custom_config_value::operator[](v24, (const char *)&stru_9609EC);
    vostok::render::custom_config_value::operator[](v25, (const char *)&stru_9609EC.id_crc);
    with_vegetation_2 = (char)vostok::render::custom_config_value::operator[](v26, (const char *)&stru_955964)->data;
    v27 = 1;
  }
  else
  {
    v27 = 0;
  }
  additional_parameters.data = &data[24];
  additional_parameters.type = 3;
  additional_parameters.bytes = 0;
  additional_parameters.count = 0;
  additional_parameters.id = 0;
  additional_parameters.destroyer = 0;
  additional_parameters.memory_size = 1024;
  v28 = vostok::render::effect_options_descriptor::operator[](0, (int)&additional_parameters, (const char *)&key);
  vostok::render::effect_options_descriptor::operator=<enum vostok::render::enum_vertex_input_type>(
    (vostok::render::effect_options_descriptor *)vertex_type,
    v28);
  if ( v27 )
    cull_mode = with_vegetation_2 != 0 ? 0 : 2;
  else
    cull_mode = cook_dataa->cull_mode;
  if ( cull_mode )
  {
    if ( cull_mode == 1 )
      v31 = 2;
    else
      v31 = 3;
  }
  else
  {
    v31 = 1;
  }
  v32 = vostok::render::effect_options_descriptor::operator[](
          v29,
          (int)&additional_parameters,
          (const char *)&stru_960A14);
  vostok::render::effect_options_descriptor::operator=<enum D3D11_CULL_MODE>(
    (vostok::render::effect_options_descriptor *)v31,
    v32);
  crc = (unsigned int)&material_config.m_object->m_root;
  vostok::render::replace_values((const char *)&additional_parameters, &material_config.m_object->m_root);
  v33 = (vostok::variant<32> *)vostok::memory::doug_lea_allocator::malloc_impl(
                                 (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                 0x570u);
  vertex_type = (vostok::render::enum_vertex_input_type)v33;
  user_data_variants_ptrs = (vostok::variant<32> **)vostok::memory::doug_lea_allocator::malloc_impl(
                                                      (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                      0x74u);
  v34 = 0;
  requests = (vostok::resources::creation_request *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                      (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                      0x1D0u);
  v35 = requests;
  do
  {
    if ( v33 )
    {
      v33->m_helper = 0;
      v33->m_type_id = 0;
      v36 = v33;
    }
    else
    {
      v36 = 0;
    }
    user_data_variants_ptrs[v34] = v36;
    if ( v35 )
    {
      boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
        &v61,
        (unsigned __int8 *)&buf,
        1u);
      v38 = *v37;
      v39 = (unsigned int)v37[1];
      v35->m_data.m_data = v38;
      v35->m_name = (const char *)&buf;
      v35->m_data.m_size = v39;
      v35->m_id = render_effect_class;
    }
    ++v34;
    ++v33;
    ++v35;
  }
  while ( v34 < 0x1D );
  v40 = vertex_type;
  vostok::render::material_effects_instance_cook::gather_request_user_data(
    (vostok::render::material_effects_instance_cook *)crc,
    (vostok::variant<32> *)vertex_type,
    (vostok::render::effect_manager::compare_predicate<vostok::render::res_shader_technique> *)crc,
    &additional_parameters);
  if ( s_sync_effects_creation_key.m_type == type_unset )
  {
    LOBYTE(v61.m_data) = 0;
    s_sync_effects_creation_key.m_type = type_recursive;
    vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
  }
  v61.m_data = (char *)vostok::render::material_effects_instance_cook::on_effect_ready;
  if ( s_sync_effects_creation_key.m_type == type_recursive )
  {
    v62 = cook_dataa;
    v61.m_size = (unsigned int)parent;
    if ( survarium::generate_shaders_world::is_loading() )
    {
      additional_parameters.id = 0;
    }
    else
    {
      *(vostok::mutable_buffer *)&additional_parameters.data = v61;
      *(_DWORD *)&additional_parameters.type = v62;
      additional_parameters.id = (char *)&stru_960AE0.m_effect_descriptors._M_t._M_header._M_data._M_parent + 1;
    }
    v41 = user_data_variants_ptrs;
    vostok::resources::query_create_resources(
      requests,
      0x1Du,
      (const boost::function<void __cdecl(vostok::resources::queries_result &)> *)&additional_parameters,
      (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object,
      (const vostok::variant<32> **)user_data_variants_ptrs,
      cook_data,
      assert_on_fail_true);
    if ( additional_parameters.id )
    {
      if ( ((int)additional_parameters.id & 1) == 0 )
      {
        v42 = *(void (__cdecl **)(unsigned __int8 **, unsigned __int8 **, int))((int)additional_parameters.id
                                                                              & 0xFFFFFFFE);
        if ( v42 )
          goto LABEL_75;
      }
    }
  }
  else
  {
    v61.m_size = (unsigned int)parent;
    v62 = cook_dataa;
    if ( survarium::generate_shaders_world::is_loading() )
    {
      additional_parameters.id = 0;
    }
    else
    {
      *(vostok::mutable_buffer *)&additional_parameters.data = v61;
      *(_DWORD *)&additional_parameters.type = v62;
      additional_parameters.id = (char *)&stru_960AE0.m_effect_descriptors._M_t._M_header._M_data._M_parent + 1;
    }
    v41 = user_data_variants_ptrs;
    vostok::resources::query_create_resources_and_wait(
      requests,
      0x1Du,
      (const boost::function<void __cdecl(vostok::resources::queries_result &)> *)&additional_parameters,
      (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object,
      (const vostok::variant<32> **)user_data_variants_ptrs,
      cook_data,
      assert_on_fail_true);
    if ( additional_parameters.id )
    {
      if ( ((int)additional_parameters.id & 1) == 0 )
      {
        v42 = *(void (__cdecl **)(unsigned __int8 **, unsigned __int8 **, int))((int)additional_parameters.id
                                                                              & 0xFFFFFFFE);
        if ( v42 )
LABEL_75:
          v42(&additional_parameters.data, &additional_parameters.data, 2);
      }
    }
  }
  v43 = 29;
  do
  {
    v44 = v40;
    v45 = *(_DWORD *)(v40 + 40);
    v40 += 48;
    if ( v45 )
    {
      (*(void (__thiscall **)(int, __int32))(*(_DWORD *)v45 + 4))(v45, v44 + 8);
      *(_DWORD *)(v44 + 40) = 0;
    }
    --v43;
  }
  while ( v43 );
  v46 = vostok::render::g_allocator.m_object;
  if ( vertex_type )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, (void *)vertex_type);
    v46 = vostok::render::g_allocator.m_object;
  }
  if ( v41 )
  {
    v48 = (void *)HIDWORD(v46->m_reconstruction_info_actuality_tick);
    BYTE2(v46->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v48, v41);
    v46 = vostok::render::g_allocator.m_object;
  }
  if ( requests )
  {
    v49 = (void *)HIDWORD(v46->m_reconstruction_info_actuality_tick);
    BYTE2(v46->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v49, (void *)requests);
  }
  v50 = material_config.m_object;
  if ( material_config.m_object && !_InterlockedExchangeAdd(&material_config.m_object->m_reference_count, 0xFFFFFFFF) )
  {
    if ( v50->call_destructors )
      vostok::render::custom_config_value::call_data_destructor((vostok::render::custom_config_value *)crc);
    if ( v50->own_buffer )
    {
      v51 = vostok::render::g_allocator.m_object;
      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free((void *)HIDWORD(v51->m_reconstruction_info_actuality_tick), v50);
    }
  }
  v52 = material.m_object;
  v53 = &material.m_object->vostok::resources::unmanaged_intrusive_base;
  if ( !_InterlockedExchangeAdd(&material.m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(v53, v52);
}
