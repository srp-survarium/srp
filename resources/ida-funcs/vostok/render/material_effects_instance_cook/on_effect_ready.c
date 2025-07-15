void __thiscall vostok::render::material_effects_instance_cook::on_effect_ready(
        vostok::render::material_effects_instance_cook *this,
        vostok::resources::queries_result *data,
        vostok::render::material_effects_instance_cook_data *cook_data)
{
  vostok::resources::unmanaged_resource *v3; // ebp
  void *v4; // eax
  vostok::render::material_effects_instance *v5; // ecx
  int v6; // eax
  int v7; // edi
  vostok::resources::unmanaged_resource *m_object; // eax
  vostok::resources::unmanaged_resource_vtbl *v9; // eax
  unsigned int v10; // ebx
  vostok::resources::queries_result *v11; // eax
  bool v12; // al
  vostok::resources::unmanaged_resource *v13; // eax
  vostok::resources::unmanaged_resource *v14; // ebp
  vostok::configs::binary_config_value *v15; // esi
  vostok::configs::binary_config_value *v16; // eax
  vostok::configs::binary_config_value *v17; // eax
  vostok::configs::binary_config_value *v18; // eax
  vostok::configs::binary_config_value *v19; // eax
  vostok::configs::binary_config_value *v20; // eax
  vostok::configs::binary_config_value *v21; // eax
  vostok::configs::binary_config_value *v22; // eax
  vostok::configs::binary_config_value *v23; // eax
  vostok::configs::binary_config_value *v24; // eax
  vostok::configs::binary_config_value *v25; // eax
  vostok::configs::binary_config_value *v26; // eax
  vostok::configs::binary_config_value *v27; // eax
  vostok::configs::binary_config_value *v28; // eax
  vostok::configs::binary_config_value *v29; // eax
  vostok::configs::binary_config_value *v30; // eax
  vostok::configs::binary_config_value *v31; // eax
  vostok::configs::binary_config_value *v32; // eax
  vostok::configs::binary_config_value *v33; // eax
  vostok::configs::binary_config_value *v34; // eax
  vostok::configs::binary_config_value *v35; // eax
  vostok::configs::binary_config_value *v36; // eax
  vostok::configs::binary_config_value *v37; // eax
  vostok::configs::binary_config_value *v38; // eax
  vostok::configs::binary_config_value *v39; // eax
  vostok::configs::binary_config_value *v40; // eax
  vostok::configs::binary_config_value *v41; // eax
  vostok::configs::binary_config_value *v42; // eax
  vostok::configs::binary_config_value *v43; // eax
  vostok::configs::binary_config_value *v44; // eax
  vostok::configs::binary_config_value *v45; // eax
  vostok::configs::binary_config_value *v46; // eax
  vostok::configs::binary_config_value *v47; // eax
  vostok::configs::binary_config_value *v48; // eax
  vostok::configs::binary_config_value *v49; // eax
  vostok::configs::binary_config_value *v50; // eax
  vostok::configs::binary_config_value *v51; // eax
  vostok::configs::binary_config_value *v52; // eax
  vostok::configs::binary_config_value *v53; // eax
  vostok::configs::binary_config_value *v54; // eax
  vostok::configs::binary_config_value *v55; // eax
  vostok::configs::binary_config_value *v56; // eax
  vostok::configs::binary_config_value *v57; // eax
  vostok::resources::unmanaged_resource *v58; // eax
  vostok::resources::unmanaged_resource *v59; // ebp
  vostok::configs::binary_config_value *v60; // esi
  vostok::configs::binary_config_value *v61; // eax
  vostok::configs::binary_config_value *v62; // eax
  vostok::configs::binary_config_value *v63; // eax
  vostok::configs::binary_config_value *v64; // eax
  vostok::configs::binary_config_value *v65; // eax
  vostok::configs::binary_config_value *v66; // eax
  _QWORD *pointer; // eax
  __int64 v68; // xmm1_8
  vostok::resources::unmanaged_resource *v69; // eax
  vostok::resources::unmanaged_resource *v70; // ebp
  vostok::configs::binary_config_value *v71; // esi
  vostok::configs::binary_config_value *v72; // eax
  vostok::configs::binary_config_value *v73; // eax
  vostok::configs::binary_config_value *v74; // eax
  vostok::configs::binary_config_value *v75; // eax
  vostok::configs::binary_config_value *v76; // eax
  vostok::configs::binary_config_value *v77; // eax
  vostok::configs::binary_config_value *v78; // eax
  vostok::configs::binary_config_value *v79; // eax
  vostok::configs::binary_config_value *v80; // eax
  vostok::configs::binary_config_value *v81; // eax
  vostok::configs::binary_config_value *v82; // eax
  vostok::configs::binary_config_value *v83; // eax
  vostok::configs::binary_config_value *v84; // eax
  vostok::configs::binary_config_value *v85; // eax
  vostok::configs::binary_config_value *v86; // eax
  vostok::configs::binary_config_value *v87; // eax
  vostok::configs::binary_config_value *v88; // eax
  vostok::configs::binary_config_value *v89; // eax
  vostok::configs::binary_config_value *v90; // eax
  vostok::configs::binary_config_value *v91; // eax
  vostok::configs::binary_config_value *v92; // eax
  vostok::resources::unmanaged_resource *v93; // eax
  vostok::resources::unmanaged_resource *v94; // ebp
  vostok::resources::unmanaged_resource *v95; // esi
  vostok::resources::unmanaged_resource *v96; // eax
  vostok::resources::unmanaged_resource *v97; // ecx
  vostok::resources::unmanaged_resource *v98; // eax
  bool v99; // al
  vostok::resources::query_result_for_cook *v100; // ecx
  vostok::resources::unmanaged_resource *v101; // eax
  vostok::render::grass_render_model *v102; // esi
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v103; // [esp-Ch] [ebp-38h]
  const char *v104; // [esp-4h] [ebp-30h]
  vostok::resources::queries_result *v105; // [esp+18h] [ebp-14h]
  unsigned int i; // [esp+1Ch] [ebp-10h]
  vostok::resources::query_result_for_cook *parent; // [esp+20h] [ebp-Ch]

  v3 = 0;
  parent = data->m_parent_query;
  v4 = vostok::memory::doug_lea_allocator::malloc_impl(
         (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
         0x5B0u);
  if ( v4 )
  {
    vostok::render::material_effects_instance::material_effects_instance(v5, (int)v4);
    v7 = v6;
  }
  else
  {
    v7 = 0;
  }
  m_object = cook_data->material.m_object;
  if ( m_object )
  {
    v3 = cook_data->material.m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  v9 = *(vostok::resources::unmanaged_resource_vtbl **)(v7 + 1176);
  if ( v9 != v3[1].__vftable )
  {
    v104 = (const char *)v3[1].__vftable;
    *(_DWORD *)(v7 + 1180) = v9;
    LOBYTE(v9->~vostok::resources::resource_base) = 0;
    vostok::buffer_string::operator+=((vostok::buffer_string *)(v7 + 1176), v104);
  }
  if ( !_InterlockedExchangeAdd(&v3->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v3->vostok::resources::unmanaged_intrusive_base, v3);
  v10 = 0;
  *(_DWORD *)(v7 + 1052) = cook_data->vertex_input_type;
  i = 0;
  do
  {
    v11 = data + 9 * v10;
    v105 = v11;
    v12 = v11->m_queries[0].m_error_type == error_type_unset
       && v11->m_queries[0].m_create_resource_result != result_error;
    *(_BYTE *)(v7 + v10 + 988) = v12;
    if ( v10 )
    {
      if ( v10 == 22 )
      {
        v58 = cook_data->material.m_object;
        v59 = 0;
        if ( v58 )
        {
          v59 = cook_data->material.m_object;
          _InterlockedExchangeAdd(&v58->m_reference_count, 1u);
        }
        v60 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                        (vostok::configs::binary_config_value *)v59[1].grm_satisfaction_tree_hook.left_[16].right_,
                                                        "material");
        if ( !_InterlockedExchangeAdd(&v59->m_reference_count, 0xFFFFFFFF) )
          vostok::resources::unmanaged_intrusive_base::destroy(&v59->vostok::resources::unmanaged_intrusive_base, v59);
        if ( vostok::configs::binary_config_value::value_exists(v60, (const char *)&stru_960A90.type) )
        {
          v61 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                          v60,
                                                          (const char *)&stru_960A90.type);
          if ( vostok::configs::binary_config_value::value_exists(v61, "is_organic") )
          {
            v62 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                            v60,
                                                            (const char *)&stru_960A90.type);
            v63 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                            v62,
                                                            "is_organic");
            *(_BYTE *)(v7 + 1018) = vostok::configs::binary_config_value::operator[](v63, (const char *)&stru_955964)->data.pointer != 0;
          }
        }
        if ( vostok::configs::binary_config_value::value_exists(v60, (const char *)&stru_960A90.type) )
        {
          v64 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                          v60,
                                                          (const char *)&stru_960A90.type);
          if ( vostok::configs::binary_config_value::value_exists(v64, "constant_clear_color") )
          {
            v65 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                            v60,
                                                            (const char *)&stru_960A90.type);
            v66 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                            v65,
                                                            "constant_clear_color");
            pointer = vostok::configs::binary_config_value::operator[](v66, (const char *)&stru_955964)->data.pointer;
            v68 = pointer[1];
            *(_QWORD *)(v7 + 1036) = *pointer;
            *(_QWORD *)(v7 + 1044) = v68;
          }
        }
      }
      else if ( v10 == 17 )
      {
        v69 = cook_data->material.m_object;
        v70 = 0;
        if ( v69 )
        {
          v70 = cook_data->material.m_object;
          _InterlockedExchangeAdd(&v69->m_reference_count, 1u);
        }
        v71 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                        (vostok::configs::binary_config_value *)v70[1].grm_satisfaction_tree_hook.left_[16].right_,
                                                        "material");
        if ( !_InterlockedExchangeAdd(&v70->m_reference_count, 0xFFFFFFFF) )
          vostok::resources::unmanaged_intrusive_base::destroy(&v70->vostok::resources::unmanaged_intrusive_base, v70);
        if ( vostok::configs::binary_config_value::value_exists(v71, "forward") )
        {
          v72 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v71, "forward");
          if ( vostok::configs::binary_config_value::value_exists(v72, (const char *)&stru_9609EC) )
          {
            v73 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                            v71,
                                                            "forward");
            v74 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                            v73,
                                                            (const char *)&stru_9609EC);
            if ( vostok::configs::binary_config_value::value_exists(v74, "effect_id") )
            {
              v75 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                              v71,
                                                              "forward");
              v76 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                              v75,
                                                              (const char *)&stru_9609EC);
              *(_BYTE *)(v7 + 1024) = strcmp(
                                        (const char *)vostok::configs::binary_config_value::operator[](v76, "effect_id")->data.pointer,
                                        (const char *)&stru_960AE0.m_is_effects_query_processing) == 0;
            }
          }
        }
        if ( vostok::configs::binary_config_value::value_exists(v71, "forward") )
        {
          v77 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v71, "forward");
          if ( vostok::configs::binary_config_value::value_exists(v77, (const char *)&stru_9609EC) )
          {
            v78 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                            v71,
                                                            "forward");
            v79 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                            v78,
                                                            (const char *)&stru_9609EC);
            if ( vostok::configs::binary_config_value::value_exists(v79, "effect_id") )
            {
              v80 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                              v71,
                                                              "forward");
              v81 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                              v80,
                                                              (const char *)&stru_9609EC);
              if ( !strcmp(
                      (const char *)vostok::configs::binary_config_value::operator[](v81, "effect_id")->data.pointer,
                      (const char *)&stru_960AE0.m_shader_cache_info._M_impl._M_end_of_storage) )
                *(_BYTE *)(v7 + 1025) = 1;
            }
          }
        }
        if ( vostok::configs::binary_config_value::value_exists(v71, "forward") )
        {
          v82 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v71, "forward");
          if ( vostok::configs::binary_config_value::value_exists(v82, (const char *)&stru_9609EC) )
          {
            v83 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                            v71,
                                                            "forward");
            v84 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                            v83,
                                                            (const char *)&stru_9609EC);
            if ( vostok::configs::binary_config_value::value_exists(v84, "effect_id") )
            {
              v85 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                              v71,
                                                              "forward");
              v86 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                              v85,
                                                              (const char *)&stru_9609EC);
              if ( !strcmp(
                      (const char *)vostok::configs::binary_config_value::operator[](v86, "effect_id")->data.pointer,
                      (const char *)&stru_960AE0.m_passes._M_t._M_node_count) )
                *(_BYTE *)(v7 + 1028) = 1;
            }
          }
        }
        if ( vostok::configs::binary_config_value::value_exists(v71, "forward") )
        {
          v87 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v71, "forward");
          if ( vostok::configs::binary_config_value::value_exists(v87, (const char *)&stru_9609EC) )
          {
            v88 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                            v71,
                                                            "forward");
            v89 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                            v88,
                                                            (const char *)&stru_9609EC);
            if ( vostok::configs::binary_config_value::value_exists(
                   v89,
                   (const char *)&stru_960AE0.m_techniques._M_t._M_header._M_data._M_left) )
            {
              v90 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                              v71,
                                                              "forward");
              v91 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                              v90,
                                                              (const char *)&stru_9609EC);
              v92 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                              v91,
                                                              (const char *)&stru_960AE0.m_techniques._M_t._M_header._M_data._M_left);
              *(_DWORD *)(v7 + 1032) = vostok::configs::binary_config_value::operator[](v92, (const char *)&stru_955964)->data.pointer;
            }
          }
        }
      }
    }
    else
    {
      v13 = cook_data->material.m_object;
      v14 = 0;
      if ( v13 )
      {
        v14 = cook_data->material.m_object;
        _InterlockedExchangeAdd(&v13->m_reference_count, 1u);
      }
      v15 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                      (vostok::configs::binary_config_value *)v14[1].grm_satisfaction_tree_hook.left_[16].right_,
                                                      "material");
      if ( !_InterlockedExchangeAdd(&v14->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v14->vostok::resources::unmanaged_intrusive_base, v14);
      if ( vostok::configs::binary_config_value::value_exists(v15, (const char *)&stru_960978) )
      {
        v16 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                        v15,
                                                        (const char *)&stru_960978);
        if ( vostok::configs::binary_config_value::value_exists(v16, (const char *)&stru_9609EC) )
        {
          v17 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                          v15,
                                                          (const char *)&stru_960978);
          v18 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                          v17,
                                                          (const char *)&stru_9609EC);
          if ( vostok::configs::binary_config_value::value_exists(v18, (const char *)&stru_960A14.type) )
          {
            v19 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                            v15,
                                                            (const char *)&stru_960978);
            v20 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                            v19,
                                                            (const char *)&stru_9609EC);
            v21 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                            v20,
                                                            (const char *)&stru_960A14.type);
            *(_BYTE *)(v7 + 1017) = vostok::configs::binary_config_value::operator[](v21, (const char *)&stru_955964)->data.pointer != 0;
          }
        }
      }
      if ( vostok::configs::binary_config_value::value_exists(v15, (const char *)&stru_960978) )
      {
        v22 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                        v15,
                                                        (const char *)&stru_960978);
        if ( vostok::configs::binary_config_value::value_exists(v22, (const char *)&stru_9555EC.configuration[1]) )
        {
          v23 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                          v15,
                                                          (const char *)&stru_960978);
          v24 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                          v23,
                                                          (const char *)&stru_9555EC.configuration[1]);
          *(_BYTE *)(v7 + 1020) = vostok::configs::binary_config_value::operator[](v24, (const char *)&stru_955964)->data.pointer != 0;
        }
      }
      if ( vostok::configs::binary_config_value::value_exists(v15, (const char *)&stru_960978) )
      {
        v25 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                        v15,
                                                        (const char *)&stru_960978);
        if ( vostok::configs::binary_config_value::value_exists(v25, (const char *)&stru_960A30) )
        {
          v26 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                          v15,
                                                          (const char *)&stru_960978);
          v27 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                          v26,
                                                          (const char *)&stru_960A30);
          *(_BYTE *)(v7 + 1021) = vostok::configs::binary_config_value::operator[](v27, (const char *)&stru_955964)->data.pointer != 0;
        }
      }
      if ( vostok::configs::binary_config_value::value_exists(v15, (const char *)&stru_960978) )
      {
        v28 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                        v15,
                                                        (const char *)&stru_960978);
        if ( vostok::configs::binary_config_value::value_exists(v28, (const char *)&stru_9609EC) )
        {
          v29 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                          v15,
                                                          (const char *)&stru_960978);
          v30 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                          v29,
                                                          (const char *)&stru_9609EC);
          if ( vostok::configs::binary_config_value::value_exists(v30, (const char *)&stru_960A44) )
          {
            v31 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                            v15,
                                                            (const char *)&stru_960978);
            v32 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                            v31,
                                                            (const char *)&stru_9609EC);
            v33 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                            v32,
                                                            (const char *)&stru_960A44);
            *(_BYTE *)(v7 + 1022) = vostok::configs::binary_config_value::operator[](v33, (const char *)&stru_955964)->data.pointer != 0;
          }
        }
      }
      if ( vostok::configs::binary_config_value::value_exists(v15, (const char *)&stru_960978) )
      {
        v34 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                        v15,
                                                        (const char *)&stru_960978);
        if ( vostok::configs::binary_config_value::value_exists(v34, (const char *)&stru_9609EC) )
        {
          v35 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                          v15,
                                                          (const char *)&stru_960978);
          v36 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                          v35,
                                                          (const char *)&stru_9609EC);
          if ( vostok::configs::binary_config_value::value_exists(v36, (const char *)&stru_960A44.destroyer) )
          {
            v37 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                            v15,
                                                            (const char *)&stru_960978);
            v38 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                            v37,
                                                            (const char *)&stru_9609EC);
            v39 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                            v38,
                                                            (const char *)&stru_960A44.destroyer);
            *(_BYTE *)(v7 + 1023) = vostok::configs::binary_config_value::operator[](v39, (const char *)&stru_955964)->data.pointer != 0;
          }
        }
      }
      if ( vostok::configs::binary_config_value::value_exists(v15, (const char *)&stru_960978) )
      {
        v40 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                        v15,
                                                        (const char *)&stru_960978);
        if ( vostok::configs::binary_config_value::value_exists(v40, (const char *)&stru_9609EC) )
        {
          v41 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                          v15,
                                                          (const char *)&stru_960978);
          v42 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                          v41,
                                                          (const char *)&stru_9609EC);
          if ( vostok::configs::binary_config_value::value_exists(v42, "use_ttranslucency") )
          {
            v43 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                            v15,
                                                            (const char *)&stru_960978);
            v44 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                            v43,
                                                            (const char *)&stru_9609EC);
            v45 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                            v44,
                                                            "use_ttranslucency");
            *(_BYTE *)(v7 + 1026) = vostok::configs::binary_config_value::operator[](v45, (const char *)&stru_955964)->data.pointer != 0;
          }
        }
      }
      if ( vostok::configs::binary_config_value::value_exists(v15, (const char *)&stru_960978) )
      {
        v46 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                        v15,
                                                        (const char *)&stru_960978);
        if ( vostok::configs::binary_config_value::value_exists(v46, (const char *)&stru_9609EC) )
        {
          v47 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                          v15,
                                                          (const char *)&stru_960978);
          v48 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                          v47,
                                                          (const char *)&stru_9609EC);
          if ( vostok::configs::binary_config_value::value_exists(v48, "use_subsurface_scattering") )
          {
            v49 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                            v15,
                                                            (const char *)&stru_960978);
            v50 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                            v49,
                                                            (const char *)&stru_9609EC);
            v51 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                            v50,
                                                            "use_subsurface_scattering");
            *(_BYTE *)(v7 + 1019) = vostok::configs::binary_config_value::operator[](v51, (const char *)&stru_955964)->data.pointer != 0;
          }
        }
      }
      if ( vostok::configs::binary_config_value::value_exists(v15, (const char *)&stru_960978) )
      {
        v52 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                        v15,
                                                        (const char *)&stru_960978);
        if ( vostok::configs::binary_config_value::value_exists(v52, (const char *)&stru_9609EC) )
        {
          v53 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                          v15,
                                                          (const char *)&stru_960978);
          v54 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                          v53,
                                                          (const char *)&stru_9609EC);
          if ( vostok::configs::binary_config_value::value_exists(v54, (const char *)&stru_960A90) )
          {
            v55 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                            v15,
                                                            (const char *)&stru_960978);
            v56 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                            v55,
                                                            (const char *)&stru_9609EC);
            v57 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                            v56,
                                                            (const char *)&stru_960A90);
            *(_BYTE *)(v7 + 1027) = vostok::configs::binary_config_value::operator[](v57, (const char *)&stru_955964)->data.pointer != 0;
          }
        }
      }
    }
    if ( v105->m_queries[0].m_error_type == error_type_unset
      && v105->m_queries[0].m_create_resource_result != result_error )
    {
      v93 = v105->m_queries[0].m_unmanaged_resource.m_object;
      v94 = 0;
      if ( v93 )
      {
        v94 = v105->m_queries[0].m_unmanaged_resource.m_object;
        _InterlockedExchangeAdd(&v93->m_reference_count, 1u);
      }
      v95 = 0;
      if ( v94 )
      {
        v95 = v94;
        _InterlockedExchangeAdd(&v94->m_reference_count, 1u);
      }
      v96 = 0;
      if ( v95 )
      {
        v96 = v95;
        _InterlockedExchangeAdd(&v95->m_reference_count, 1u);
      }
      v97 = v96;
      v98 = *(vostok::resources::unmanaged_resource **)(v7 + 4 * v10 + 1060);
      *(_DWORD *)(v7 + 4 * v10 + 1060) = v97;
      if ( v98 )
      {
        if ( !_InterlockedExchangeAdd(&v98->m_reference_count, 0xFFFFFFFF) )
          vostok::resources::unmanaged_intrusive_base::destroy(&v98->vostok::resources::unmanaged_intrusive_base, v98);
        v10 = i;
      }
      if ( v95 && !_InterlockedExchangeAdd(&v95->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v95->vostok::resources::unmanaged_intrusive_base, v95);
      if ( v94 && !_InterlockedExchangeAdd(&v94->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v94->vostok::resources::unmanaged_intrusive_base, v94);
    }
    v99 = *(_BYTE *)(v7 + v10 + 988) && *(_DWORD *)(v7 + 4 * v10 + 1060);
    *(_BYTE *)(v7 + v10++ + 988) = v99;
    i = v10;
  }
  while ( v10 < 0x1D );
  v103.m_object = 0;
  if ( v7 )
  {
    v103.m_object = (vostok::resources::unmanaged_resource *)v7;
    _InterlockedExchangeAdd((volatile signed __int32 *)(v7 + 208), 1u);
  }
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    parent,
    v103,
    &vostok::resources::nocache_memory,
    0x5B0u);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v100,
    result_success,
    assert_on_fail_true,
    error_type_unset);
  if ( cook_data->delete_in_cook )
  {
    v101 = cook_data->material.m_object;
    v102 = vostok::render::g_allocator.m_object;
    if ( v101 )
    {
      if ( !_InterlockedExchangeAdd(&v101->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(
          &cook_data->material.m_object->vostok::resources::unmanaged_intrusive_base,
          cook_data->material.m_object);
    }
    BYTE2(v102->m_children_resources.m_lock) = 0;
    vostok_mspace_free((void *)HIDWORD(v102->m_reconstruction_info_actuality_tick), cook_data);
  }
}
