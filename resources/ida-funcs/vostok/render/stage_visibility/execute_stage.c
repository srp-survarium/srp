void __usercall vostok::render::stage_visibility::execute_stage(
        vostok::render::stage_visibility *this@<ecx>,
        vostok::render::stage_visibility *a2@<eax>,
        int a3@<ebx>)
{
  vostok::render::hw_hiz_occlusion_manager *v4; // ecx
  vostok::render::stage_visibility *v5; // ecx
  vostok::render::stage_visibility *v6; // ecx
  vostok::render::base_scene_view *m_object; // eax
  int *m_target_quality_level; // edx
  int *m_class_id; // edi
  int v10; // edx
  vostok::render::stage_visibility *v11; // ecx
  unsigned int v12; // ebx
  vostok::fixed_string<128> *v13; // ecx
  int v14; // eax
  unsigned int v15; // eax
  int v16; // eax
  unsigned int v17; // eax
  int v18; // eax
  unsigned int v19; // eax
  int v20; // eax
  unsigned int v21; // eax
  int v22; // eax
  unsigned int v23; // eax
  int v24; // eax
  unsigned int v25; // eax
  int v26; // eax
  unsigned int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  int v31; // eax
  char v32; // al
  int v33; // eax
  unsigned int v34; // eax
  int v35; // eax
  unsigned int v36; // eax
  int v37; // eax
  unsigned int v38; // eax
  int v39; // eax
  unsigned int v40; // eax
  int v41; // eax
  int v42; // eax
  int v43; // eax
  unsigned int v44; // eax
  int v45; // eax
  unsigned int v46; // eax
  int v47; // eax
  unsigned int v48; // eax
  int v49; // eax
  unsigned int v50; // eax
  vostok::fixed_string<128> *v51; // [esp-4h] [ebp-144h]
  vostok::fixed_string<128> *v52; // [esp-4h] [ebp-144h]
  vostok::fixed_string<128> *v53; // [esp-4h] [ebp-144h]
  vostok::fixed_string<128> *v54; // [esp-4h] [ebp-144h]
  vostok::fixed_string<128> *v55; // [esp-4h] [ebp-144h]
  vostok::fixed_string<128> *v56; // [esp-4h] [ebp-144h]
  vostok::fixed_string<128> *v57; // [esp-4h] [ebp-144h]
  vostok::fixed_string<128> *v58; // [esp-4h] [ebp-144h]
  vostok::fixed_string<128> *v59; // [esp-4h] [ebp-144h]
  vostok::fixed_string<128> *v60; // [esp-4h] [ebp-144h]
  vostok::fixed_string<128> *v61; // [esp-4h] [ebp-144h]
  vostok::fixed_string<128> *v62; // [esp-4h] [ebp-144h]
  vostok::fixed_string<128> *v63; // [esp-4h] [ebp-144h]
  vostok::fixed_string<128> *v64; // [esp-4h] [ebp-144h]
  vostok::fixed_string<128> *v65; // [esp-4h] [ebp-144h]
  vostok::fixed_string<128> *v66; // [esp-4h] [ebp-144h]
  vostok::fixed_string<128> *v67; // [esp-4h] [ebp-144h]
  vostok::fixed_string<128> *v68; // [esp-4h] [ebp-144h]
  char v69; // [esp+9Ch] [ebp-A4h] BYREF
  vostok::buffer_string str1[12]; // [esp+A0h] [ebp-A0h] BYREF
  vostok::resources::class_id_enum i; // [esp+134h] [ebp-Ch]
  int v72; // [esp+138h] [ebp-8h]
  wchar_t wszName; // [esp+13Fh] [ebp-1h] BYREF

  pix_event_wrapper_dx11::pix_event_wrapper_dx11(
    (pix_event_wrapper_dx11 *)this,
    (pix_event_wrapper_dx11 *)&wszName,
    (int)L"stage_visibility");
  if ( vostok::quasi_singleton<vostok::render::options>::pinst->current.m_use_hiz_occlusion_culling
    && a2->m_use_hiz_culling )
  {
    a2->m_data_ready = vostok::render::hw_hiz_occlusion_manager::quary_and_get_results_if_ready(
                         v4,
                         (int)a2->m_occlusion_manager,
                         (unsigned int *)a2,
                         a2->m_static_results_array,
                         a2->m_current_occlusion_buffer_size);
    vostok::render::stage_visibility::frustum_culling(v5, (int)a2);
    if ( a2->m_data_ready )
    {
      vostok::render::stage_visibility::occlusion_culling(v6, (int)a2);
      a2->m_data_ready = 0;
    }
  }
  else
  {
    vostok::render::stage_visibility::frustum_culling((vostok::render::stage_visibility *)v4, (int)a2);
  }
  m_object = a2->m_context->m_scene_view.m_object;
  m_target_quality_level = (int *)m_object[33].m_target_quality_level;
  m_class_id = (int *)m_object[33].m_class_id;
  while ( m_target_quality_level != m_class_id )
  {
    a3 = *m_target_quality_level;
    if ( !vostok::render::render_surface_instance::is_occluded(
            (vostok::render::render_surface_instance *)v6,
            *m_target_quality_level) )
    {
      v6 = (vostok::render::stage_visibility *)(*(_DWORD *)(a3 + 20) + 272);
      _InterlockedExchange((volatile __int32 *)v6, a2->m_renderer->m_engine_world->m_frame_id + 1);
    }
    m_target_quality_level = (int *)(v10 + 4);
  }
  vostok::render::stage_visibility::gather_statistics(a2);
  vostok::render::stage_visibility::filter_and_sort(
    v11,
    (const stlp_std::random_access_iterator_tag *)a3,
    (vostok::render::ambient_light **)a2,
    0);
  if ( s_calc_screen_factors )
    vostok::render::scene::calculate_screen_factors(
      (vostok::render::scene *)&a2->m_context->m_p,
      (const vostok::math::float4x4 *)a2->m_context->m_scene,
      (const vostok::math::float3 *)&a2->m_context->m_p,
      &a2->m_context->m_view_pos.x);
  if ( s_no_trees_value
    || s_no_bushes_value
    || s_no_terrain_value
    || s_no_house_value
    || s_no_background_value
    || s_no_flora_value
    || s_no_other_value )
  {
    v12 = a2->m_context->m_scene_view.m_object[33].m_target_quality_level;
    v13 = (vostok::fixed_string<128> *)&v69;
    for ( i = a2->m_context->m_scene_view.m_object[33].m_class_id; v12 != i; v12 += 4 )
    {
      v72 = *(_DWORD *)(*(_DWORD *)v12 + 20);
      vostok::fixed_string<128>::fixed_string<128>(v13, str1, "<unknown>");
      if ( !s_no_other_value )
        goto LABEL_111;
      strstr((unsigned __int8 *)str1[0].m_begin, "flora");
      v13 = v51;
      v15 = v14 ? v14 - (unsigned int)str1[0].m_begin : -1;
      if ( v15 != -1 )
        goto LABEL_59;
      strstr((unsigned __int8 *)str1[0].m_begin, "terrain");
      v13 = v52;
      v17 = v16 ? v16 - (unsigned int)str1[0].m_begin : -1;
      if ( v17 != -1 )
        goto LABEL_59;
      strstr((unsigned __int8 *)str1[0].m_begin, "house");
      v13 = v53;
      v19 = v18 ? v18 - (unsigned int)str1[0].m_begin : -1;
      if ( v19 != -1 )
        goto LABEL_59;
      strstr((unsigned __int8 *)str1[0].m_begin, "background");
      v13 = v54;
      v21 = v20 ? v20 - (unsigned int)str1[0].m_begin : -1;
      if ( v21 != -1 )
        goto LABEL_59;
      strstr((unsigned __int8 *)str1[0].m_begin, "cane");
      v13 = v55;
      v23 = v22 ? v22 - (unsigned int)str1[0].m_begin : -1;
      if ( v23 != -1 )
        goto LABEL_59;
      strstr((unsigned __int8 *)str1[0].m_begin, "poplar");
      v13 = v56;
      v25 = v24 ? v24 - (unsigned int)str1[0].m_begin : -1;
      if ( v25 != -1 )
        goto LABEL_59;
      strstr((unsigned __int8 *)str1[0].m_begin, "fruit");
      v13 = v57;
      v27 = v26 ? v26 - (unsigned int)str1[0].m_begin : -1;
      if ( v27 == -1
        && ((strstr((unsigned __int8 *)str1[0].m_begin, "tree"), v13 = v58, !v28)
          ? (v29 = -1)
          : (v29 = v28 - (unsigned int)str1[0].m_begin),
            v29 == -1
         && ((strstr((unsigned __int8 *)str1[0].m_begin, "elka"), v13 = v59, !v30)
           ? (v31 = -1)
           : (v31 = v30 - (unsigned int)str1[0].m_begin),
             v31 == -1)) )
      {
        v32 = 1;
      }
      else
      {
LABEL_59:
        v32 = 0;
      }
      if ( !s_no_other_value || !v32 )
      {
LABEL_111:
        if ( s_no_flora_value )
        {
          strstr((unsigned __int8 *)str1[0].m_begin, "flora");
          v13 = v60;
          v34 = v33 ? v33 - (unsigned int)str1[0].m_begin : -1;
          if ( v34 != -1 )
            *(_BYTE *)(*(_DWORD *)v12 + 53) = 1;
        }
        if ( s_no_terrain_value )
        {
          strstr((unsigned __int8 *)str1[0].m_begin, "terrain");
          v13 = v61;
          v36 = v35 ? v35 - (unsigned int)str1[0].m_begin : -1;
          if ( v36 != -1 )
            *(_BYTE *)(*(_DWORD *)v12 + 53) = 1;
        }
        if ( s_no_house_value )
        {
          strstr((unsigned __int8 *)str1[0].m_begin, "house");
          v13 = v62;
          v38 = v37 ? v37 - (unsigned int)str1[0].m_begin : -1;
          if ( v38 != -1 )
            *(_BYTE *)(*(_DWORD *)v12 + 53) = 1;
        }
        if ( s_no_background_value )
        {
          strstr((unsigned __int8 *)str1[0].m_begin, "background");
          v13 = v63;
          v40 = v39 ? v39 - (unsigned int)str1[0].m_begin : -1;
          if ( v40 != -1 )
            *(_BYTE *)(*(_DWORD *)v12 + 53) = 1;
        }
        if ( !s_no_bushes_value )
          goto LABEL_95;
        strstr((unsigned __int8 *)str1[0].m_begin, "cane");
        v13 = v64;
        if ( v41 )
          v42 = v41 - (unsigned int)str1[0].m_begin;
        else
          v42 = -1;
        if ( v42 != -1 )
          *(_BYTE *)(*(_DWORD *)v12 + 53) = 1;
        if ( !s_no_bushes_value || (*(int (__thiscall **)(int))(*(_DWORD *)v72 + 48))(v72) != 1 )
        {
LABEL_95:
          if ( !s_no_trees_value || (unsigned int)(*(int (__thiscall **)(int))(*(_DWORD *)v72 + 48))(v72) <= 1 )
            continue;
        }
        strstr((unsigned __int8 *)str1[0].m_begin, "poplar");
        v13 = v65;
        v44 = v43 ? v43 - (unsigned int)str1[0].m_begin : -1;
        if ( v44 == -1 )
        {
          strstr((unsigned __int8 *)str1[0].m_begin, "fruit");
          v13 = v66;
          v46 = v45 ? v45 - (unsigned int)str1[0].m_begin : -1;
          if ( v46 == -1 )
          {
            strstr((unsigned __int8 *)str1[0].m_begin, "tree");
            v13 = v67;
            v48 = v47 ? v47 - (unsigned int)str1[0].m_begin : -1;
            if ( v48 == -1 )
            {
              strstr((unsigned __int8 *)str1[0].m_begin, "elka");
              v13 = v68;
              v50 = v49 ? v49 - (unsigned int)str1[0].m_begin : -1;
              if ( v50 == -1 )
                continue;
            }
          }
        }
      }
      *(_BYTE *)(*(_DWORD *)v12 + 53) = 1;
    }
  }
  D3DPERF_EndEvent();
}
