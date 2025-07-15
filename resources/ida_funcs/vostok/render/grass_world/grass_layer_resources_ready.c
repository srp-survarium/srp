void __thiscall vostok::render::grass_world::grass_layer_resources_ready(
        vostok::render::grass_world *this,
        vostok::resources::queries_result *data,
        vostok::render::grass_layer_desc *desc,
        vostok::render::grass_layer_data *layer_data,
        bool do_populate)
{
  int v5; // ecx
  int v6; // ebx
  int v7; // esi
  void *v8; // esp
  vostok::resources::unmanaged_intrusive_base *p_m_target_quality_level; // ecx
  vostok::resources::queries_result *v10; // eax
  vostok::resources::unmanaged_resource *v11; // edi
  vostok::render::grass_world *v12; // esi
  vostok::sound::sound_world_vtbl *v13; // eax
  vostok::render::grass_world *v14; // ecx
  unsigned int v15; // eax
  void *v16; // esp
  float v17; // xmm0_4
  _BYTE *v18; // esi
  int v19; // eax
  float *v20; // ecx
  int v21; // edx
  float v22; // xmm1_4
  float *v23; // edi
  unsigned __int64 v24; // rax
  unsigned __int8 v25; // al
  unsigned __int8 v26; // bl
  double v27; // st7
  float v28; // edx
  bool v29; // zf
  vostok::math::float3 *instances_normals; // eax
  float v31; // edx
  float v32; // xmm0_4
  float v33; // xmm1_4
  double v34; // st7
  double random_scale; // st6
  vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base> *v36; // eax
  vostok::math::float4x4 *result; // [esp+0h] [ebp-9Ch]
  _BYTE v38[16]; // [esp+4h] [ebp-98h] BYREF
  vostok::math::float4x4 m; // [esp+14h] [ebp-88h] BYREF
  vostok::math::float3 scale; // [esp+54h] [ebp-48h] BYREF
  __int64 v41; // [esp+60h] [ebp-3Ch]
  float v42; // [esp+68h] [ebp-34h]
  __int64 v43; // [esp+6Ch] [ebp-30h]
  float v44; // [esp+74h] [ebp-28h]
  vostok::render::grass_world *v45; // [esp+78h] [ebp-24h]
  vostok::math::color clr; // [esp+7Ch] [ebp-20h] BYREF
  float orient; // [esp+80h] [ebp-1Ch]
  _BYTE *v48; // [esp+84h] [ebp-18h]
  vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base> *in_render_model; // [esp+88h] [ebp-14h]
  float prob_sum; // [esp+8Ch] [ebp-10h]
  unsigned int i; // [esp+90h] [ebp-Ch]
  unsigned __int8 models_count; // [esp+97h] [ebp-5h]
  float v53; // [esp+98h] [ebp-4h]

  in_render_model = (vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base> *)this;
  v5 = (char *)desc->models_list.m_end - (char *)desc->models_list.m_begin;
  v6 = v5 / 280;
  v7 = 4 * (unsigned __int8)(v5 / 280);
  models_count = v5 / 280;
  v48 = (_BYTE *)v7;
  v8 = alloca(v7);
  v45 = (vostok::render::grass_world *)v38;
  if ( models_count )
  {
    v53 = COERCE_FLOAT(v38);
    i = (unsigned int)&data->m_queries[0].m_unmanaged_resource;
    LODWORD(prob_sum) = (unsigned __int8)(v5 / 280);
    do
    {
      p_m_target_quality_level = *(vostok::resources::unmanaged_intrusive_base **)i;
      v10 = 0;
      if ( *(_DWORD *)i )
      {
        v10 = *(vostok::resources::queries_result **)i;
        p_m_target_quality_level += 26;
        _InterlockedExchangeAdd(&p_m_target_quality_level->m_reference_count, 1u);
      }
      v11 = 0;
      data = 0;
      if ( v10 )
      {
        v11 = (vostok::resources::unmanaged_resource *)v10;
        p_m_target_quality_level = (vostok::resources::unmanaged_intrusive_base *)&v10->m_queries[0].m_target_quality_level;
        data = v10;
        _InterlockedExchangeAdd((volatile signed __int32 *)&v10->m_queries[0].m_target_quality_level, 1u);
        if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v10->m_queries[0].m_target_quality_level, 0xFFFFFFFF) )
          vostok::resources::unmanaged_intrusive_base::destroy(
            p_m_target_quality_level,
            (vostok::resources::unmanaged_resource *)v10);
      }
      v12 = (vostok::render::grass_world *)in_render_model;
      v13 = vostok::render::grass_world::find_template(
              (vostok::render::grass_world *)p_m_target_quality_level,
              (int)in_render_model,
              (const vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base> *)&data);
      if ( v13 )
      {
        *(_DWORD *)LODWORD(v53) = v13->clear_resources;
      }
      else
      {
        v15 = vostok::render::grass_world::add_template(
                v14,
                (bool)v11,
                v12,
                (const vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base> *)&data);
        *(_DWORD *)LODWORD(v53) = v15;
      }
      if ( v11 && !_InterlockedExchangeAdd(&v11->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v11->vostok::resources::unmanaged_intrusive_base, v11);
      i += 720;
      LODWORD(v53) += 4;
      --LODWORD(prob_sum);
    }
    while ( prob_sum != 0.0 );
    v7 = (int)v48;
  }
  v16 = alloca(v7);
  v17 = 0.0;
  v18 = v38;
  v48 = v38;
  prob_sum = 0.0;
  if ( (_BYTE)v6 )
  {
    v19 = 0;
    v20 = (float *)v38;
    v21 = (unsigned __int8)v6;
    do
    {
      v22 = desc->models_list.m_begin[v19].probability_ + v17;
      v17 = v22;
      *v20 = v22;
      ++v19;
      ++v20;
      --v21;
    }
    while ( v21 );
    prob_sum = v22;
  }
  clr = (vostok::math::color)-3618616;
  i = 0;
  if ( layer_data->instances_count )
  {
    data = 0;
    while ( 1 )
    {
      v23 = (float *)((char *)data + (unsigned int)layer_data->instances_positions);
      model_index_random.m_seed = 134775813 * model_index_random.m_seed + 1;
      v24 = (unsigned __int64)model_index_random.m_seed << 20;
      v25 = 0;
      v53 = (double)HIDWORD(v24) * 0.00000095367432 * prob_sum;
      if ( (_BYTE)v6 )
      {
        while ( *(float *)&v18[4 * v25] <= v53 )
        {
          if ( ++v25 >= (unsigned __int8)v6 )
            goto LABEL_26;
        }
        v26 = v25;
      }
      else
      {
LABEL_26:
        v26 = v6 - 1;
      }
      if ( desc->random_orient )
      {
        model_orientation_random.m_seed = 134775813 * model_orientation_random.m_seed + 1;
        LODWORD(v53) = (unsigned __int64)model_orientation_random.m_seed >> 12;
        v27 = 0.00000095367432 * (double)LODWORD(v53) * 6.2831855;
      }
      else
      {
        orient = 0.0;
        v27 = 0.0;
      }
      *(float *)&result = v27;
      vostok::math::create_rotation_y(&m, result);
      v28 = v23[2];
      v29 = !desc->use_face_normal;
      *(_QWORD *)&m.lines[3].x = *(_QWORD *)v23;
      m.c.z = v28;
      if ( !v29 )
      {
        instances_normals = layer_data->instances_normals;
        v31 = *(float *)((char *)&instances_normals->z + (_DWORD)data);
        *(_QWORD *)&m.lines[1].x = *(_QWORD *)((char *)&instances_normals->x + (_DWORD)data);
        m.j.z = v31;
        v32 = (float)(m.j.x * m.i.z) - (float)(v31 * m.i.x);
        *((float *)&v43 + 1) = v32;
        v33 = (float)(m.j.y * m.i.x) - (float)(m.j.x * m.i.y);
        *(float *)&v43 = (float)(v31 * m.i.y) - (float)(m.j.y * m.i.z);
        *(_QWORD *)&m.lines[2].x = v43;
        v44 = v33;
        v42 = (float)(v32 * m.j.x) - (float)(m.j.y * *(float *)&v43);
        *(float *)&v41 = (float)(v33 * m.j.y) - (float)(v32 * v31);
        *((float *)&v41 + 1) = (float)(v31 * *(float *)&v43) - (float)(v33 * m.j.x);
        m.k.z = v33;
        *(_QWORD *)&m.i.x = v41;
        m.i.z = v42;
      }
      v34 = desc->models_list.m_begin[v26].scale;
      random_scale = desc->random_scale;
      model_scale_random.m_seed = 134775813 * model_scale_random.m_seed + 1;
      LODWORD(v53) = (unsigned __int64)model_scale_random.m_seed >> 12;
      scale.x = (double)LODWORD(v53) * 0.00000095367432 * random_scale
              + (double)LODWORD(v53) * 0.00000095367432 * random_scale
              + v34
              - random_scale;
      scale.y = scale.x;
      scale.z = scale.x;
      vostok::math::float4x4::set_scale(&m, &scale);
      vostok::render::grass_world::add_instance(
        *((_DWORD *)&v45->__vftable + v26),
        v45,
        (vostok::render::grass_world *)in_render_model,
        &clr,
        &m,
        (vostok::render::grass_instance *)desc->id,
        desc->wind_factor);
      data = (vostok::resources::queries_result *)((char *)data + 12);
      if ( ++i >= layer_data->instances_count )
        break;
      v18 = v48;
      LOBYTE(v6) = models_count;
    }
  }
  v29 = !do_populate;
  v36 = in_render_model;
  LOBYTE(in_render_model[89].m_object) = 1;
  if ( !v29 )
    LOBYTE(v36[89].m_object) = 1;
}
