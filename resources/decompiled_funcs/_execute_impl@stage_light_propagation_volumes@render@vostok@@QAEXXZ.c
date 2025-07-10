void __thiscall vostok::render::stage_light_propagation_volumes::execute_impl(
        vostok::render::stage_light_propagation_volumes *this,
        vostok::render::stage_light_propagation_volumes *thisa)
{
  vostok::render::lights_db *m_object; // eax
  vostok::render::light *v3; // ecx
  const vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *p_m_sun; // eax
  vostok::render::light *v5; // edi
  vostok::render::light *v6; // ecx
  bool v7; // zf
  vostok::render::grass_render_model *v8; // esi
  vostok::render::lights_db *v9; // eax
  vostok::collision::space_partitioning_tree *m_lights_tree; // ecx
  vostok::render::renderer_context *m_context; // ebp
  vostok::render::radiance_volume *M_start; // ecx
  int v13; // edx
  const void **v14; // eax
  const void **i; // edi
  int v16; // esi
  vostok::render::scene *m_scene; // eax
  int v18; // ebp
  vostok::render::grass_render_model *v19; // esi
  const vostok::collision::object *const *M_finish; // eax
  vostok::math::float4x4 *v21; // edx
  unsigned int v22; // edi
  unsigned int v23; // eax
  unsigned int *p_pass_index; // ecx
  unsigned int v25; // ebp
  unsigned int *v26; // eax
  unsigned int v27; // ecx
  bool v28; // al
  unsigned __int8 *v29; // eax
  int v30; // eax
  vostok::math::float4x4 *v31; // edi
  vostok::math::float4x4 *v32; // eax
  int v33; // esi
  int v34; // edi
  vostok::render::renderer_context *v35; // edx
  vostok::render::resource_manager *v36; // ecx
  const char *v37; // eax
  ID3D11DeviceContext *m_deferred_context; // esi
  const char *m_conflicted_key_name; // edi
  const char *v40; // esi
  int v41; // eax
  int v42; // esi
  int v43; // edi
  signed int v44; // esi
  int v45; // edi
  vostok::render::light *v46; // ebp
  int v47; // edi
  unsigned int v48; // ebp
  int v49; // esi
  const vostok::collision::object *const **p_e; // eax
  const vostok::collision::object *const *v51; // ecx
  vostok::render::grass_render_model *v52; // eax
  unsigned int v53; // ecx
  bool v54; // dl
  unsigned __int8 *v55; // eax
  float v56; // esi
  int v57; // eax
  unsigned int v58; // ebp
  int v59; // esi
  const vostok::collision::object *const **v60; // eax
  const vostok::collision::object *const *v61; // ecx
  vostok::render::grass_render_model *v62; // eax
  unsigned int v63; // ecx
  bool v64; // dl
  unsigned __int8 *v65; // eax
  int v66; // eax
  float y; // ecx
  int v68; // ebp
  int v69; // eax
  vostok::render::stage_light_propagation_volumes *v70; // ecx
  int v71; // edi
  int v72; // edi
  vostok::math::float4_pod *p_k; // eax
  bool v74; // cc
  signed int v75; // esi
  int v76; // edi
  int v77; // eax
  const char *v78; // esi
  vostok::render::render_target *v79; // eax
  vostok::render::resource_manager *v80; // ecx
  ID3D11RenderTargetView *m_rt; // eax
  _DWORD *v82; // eax
  unsigned int v83; // ecx
  vostok::render::renderer_context *v84; // edx
  vostok::render::render_target *v85; // eax
  vostok::render::render_target *v86; // ecx
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *p_target; // eax
  vostok::render::renderer_context *v88; // edx
  vostok::render::render_target *v89; // eax
  vostok::render::resource_manager *v90; // ecx
  ID3D11RenderTargetView *v91; // eax
  _DWORD *v92; // eax
  int v93; // ecx
  vostok::render::renderer_context *v94; // edx
  vostok::render::render_target *v95; // eax
  vostok::render::render_target *v96; // ecx
  vostok::render::render_target *v97; // eax
  const char *v98; // ecx
  const char *v99; // eax
  unsigned int v100; // esi
  const char *v101; // ebp
  char v102; // al
  const char *v103; // ecx
  vostok::render::textures_handler<0> *m_radiance_volume; // ecx
  const char *v105; // ebp
  vostok::render::constants_handler<1> *v106; // ebp
  vostok::render::constants_handler<1> *v107; // esi
  vostok::math::float3 *v108; // eax
  const vostok::render::shader_constant_host *m_c_grid_cell_size; // eax
  double m_grid_size; // st7
  vostok::render::radiance_volume *v111; // eax
  __int64 v112; // xmm0_8
  double v113; // st6
  float z; // edx
  const vostok::render::shader_constant_host *m_c_smaller_cascade_grid_cell_size; // eax
  survarium::game_action_id *v116; // eax
  vostok::render::stage_light_propagation_volumes *v117; // ecx
  vostok::render::backend *v118; // ecx
  int v119; // eax
  vostok::math::float4x4 *v120; // eax
  _BYTE v121[20]; // [esp+2Ch] [ebp-120h] BYREF
  int smaller_cascade_grid_size; // [esp+50h] [ebp-FCh] BYREF
  __int64 cascade_index; // [esp+54h] [ebp-F8h] BYREF
  unsigned int pass_index; // [esp+5Ch] [ebp-F0h] BYREF
  const vostok::collision::object *const *e; // [esp+60h] [ebp-ECh] BYREF
  vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> object; // [esp+64h] [ebp-E8h] BYREF
  vostok::render::vector<vostok::math::float4x4> box_occluder_transforms; // [esp+6Ch] [ebp-E0h] BYREF
  float v128; // [esp+78h] [ebp-D4h]
  vostok::vectora<vostok::collision::object const *> objects; // [esp+7Ch] [ebp-D0h] BYREF
  vostok::math::float3 smaller_cascade_grid_origin; // [esp+8Ch] [ebp-C0h] BYREF
  D3D11_VIEWPORT tmp_viewport; // [esp+98h] [ebp-B4h] BYREF
  D3D11_VIEWPORT orig_viewport; // [esp+B0h] [ebp-9Ch] BYREF
  float v133[3]; // [esp+C8h] [ebp-84h] BYREF
  vostok::math::frustum frustum; // [esp+D4h] [ebp-78h] BYREF

  m_object = thisa->m_context->m_scene->m_lights.m_object;
  v3 = m_object->m_sun.m_object;
  p_m_sun = &m_object->m_sun;
  if ( v3
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
    && !v3->m_enabled )
  {
    object.m_object = 0;
    v5 = 0;
  }
  else
  {
    object.m_object = 0;
    vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
      (vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v3,
      &object,
      p_m_sun);
    v5 = object.m_object;
    if ( object.m_object )
    {
      v7 = object.m_object->m_reference_count-- == 1;
      if ( v7 )
      {
        v8 = vostok::render::g_allocator.m_object;
        vostok::render::light::~light(v6, (int)v5);
        BYTE2(v8->m_children_resources.m_lock) = 0;
        vostok_mspace_free((void *)HIDWORD(v8->m_reconstruction_info_actuality_tick), v5);
      }
    }
  }
  v9 = thisa->m_context->m_scene->m_lights.m_object;
  objects._M_impl._M_start = 0;
  objects._M_impl._M_finish = 0;
  objects._M_impl._M_end_of_storage.m_allocator = (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object;
  objects._M_impl._M_end_of_storage._M_data = 0;
  stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *>>::reserve(
    (stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *> > *)vostok::render::g_allocator.m_object,
    &objects._M_impl,
    v9->m_lights._M_impl._M_finish - v9->m_lights._M_impl._M_start);
  vostok::math::frustum::frustum(&frustum, &thisa->m_context->m_vp);
  m_lights_tree = thisa->m_context->m_scene->m_lights.m_object->m_lights_tree;
  m_lights_tree->cuboid_query(m_lights_tree, -1u, &frustum, &objects);
  m_context = thisa->m_context;
  M_start = (vostok::render::radiance_volume *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start;
  v13 = LODWORD(m_context->m_scene_view.m_object[4].m_current_satisfaction_update_tick)
      % *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
        + 37);
  thisa->m_has_indirect_lighting = 0;
  HIBYTE(v128) = v13 == 0;
  if ( v5 && v5->use_with_lpv )
    thisa->m_has_indirect_lighting = 1;
  v14 = objects._M_impl._M_start;
  for ( i = objects._M_impl._M_finish; v14 != i; ++v14 )
  {
    v16 = *((_DWORD *)*v14 + 9);
    if ( *(_BYTE *)(v16 + 349) )
    {
      M_start = *(vostok::render::radiance_volume **)(v16 + 380);
      LOBYTE(M_start) = (unsigned __int8)M_start & 0xF;
      if ( (unsigned __int8)M_start <= 1u )
        thisa->m_has_indirect_lighting = 1;
    }
  }
  thisa->m_has_indirect_lighting = thisa->m_has_indirect_lighting;
  m_scene = m_context->m_scene;
  v18 = (int)m_scene->m_lpv_occluders._M_impl._M_start;
  v19 = vostok::render::g_allocator.m_object;
  M_finish = (const vostok::collision::object *const *)m_scene->m_lpv_occluders._M_impl._M_finish;
  v21 = 0;
  memset(&box_occluder_transforms, 0, sizeof(box_occluder_transforms));
  smaller_cascade_grid_size = v18;
  e = M_finish;
  if ( (const vostok::collision::object *const *)v18 != M_finish )
  {
    M_start = (vostok::render::radiance_volume *)(v18 + 4);
    LODWORD(cascade_index) = v18 + 4;
    do
    {
      if ( v21 == box_occluder_transforms._M_impl._M_end_of_storage._M_data )
      {
        v22 = (char *)v21 - (char *)box_occluder_transforms._M_impl._M_start;
        v23 = v21 - box_occluder_transforms._M_impl._M_start;
        pass_index = 1;
        HIDWORD(cascade_index) = v23;
        if ( &vostok::memory::s_CRT_arena[55905847] == (unsigned __int8 *)v23 )
          stlp_std::__stl_throw_length_error("vector");
        p_pass_index = (unsigned int *)&cascade_index + 1;
        if ( v23 <= 1 )
          p_pass_index = &pass_index;
        v25 = v23 + *p_pass_index;
        if ( v25 > (unsigned int)&vostok::memory::s_CRT_arena[55905847] || v25 < v23 )
          v25 = (unsigned int)&vostok::memory::s_CRT_arena[55905847];
        pass_index = v25;
        HIDWORD(cascade_index) = 1;
        v26 = (unsigned int *)&cascade_index + 1;
        if ( v25 )
          v26 = &pass_index;
        v27 = *v26 << 6;
        v28 = BYTE2(v19->m_children_resources.m_lock) && v27;
        BYTE2(v19->m_children_resources.m_lock) = v28;
        if ( v27 )
          v29 = (unsigned __int8 *)vostok_mspace_malloc((void *)HIDWORD(v19->m_reconstruction_info_actuality_tick), v27);
        else
          v29 = 0;
        pass_index = (unsigned int)v29;
        if ( v22 )
        {
          memmove(v29, (unsigned __int8 *)box_occluder_transforms._M_impl._M_start, v22);
          v29 = (unsigned __int8 *)(v22 + v30);
        }
        v7 = box_occluder_transforms._M_impl._M_start == 0;
        qmemcpy(v29, (const void *)cascade_index, 0x40u);
        v19 = vostok::render::g_allocator.m_object;
        v31 = (vostok::math::float4x4 *)(v29 + 64);
        M_start = (vostok::render::radiance_volume *)vostok::render::g_allocator.m_object;
        if ( !v7 )
        {
          v32 = box_occluder_transforms._M_impl._M_start;
          BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
          vostok_mspace_free(M_start->m_t_rms_position_source.m_object, (void *)v32);
          v19 = vostok::render::g_allocator.m_object;
        }
        box_occluder_transforms._M_impl._M_start = (vostok::math::float4x4 *)pass_index;
        M_finish = e;
        box_occluder_transforms._M_impl._M_end_of_storage._M_data = (vostok::math::float4x4 *)(pass_index + (v25 << 6));
        v18 = smaller_cascade_grid_size;
        box_occluder_transforms._M_impl._M_finish = v31;
        v21 = v31;
      }
      else
      {
        if ( v21 )
        {
          qmemcpy((void *)v21, (const void *)cascade_index, sizeof(vostok::math::float4x4));
          M_start = 0;
          v19 = vostok::render::g_allocator.m_object;
        }
        box_occluder_transforms._M_impl._M_finish = ++v21;
      }
      LODWORD(cascade_index) = cascade_index + 68;
      v18 += 68;
      smaller_cascade_grid_size = v18;
    }
    while ( (const vostok::collision::object *const *)v18 != M_finish );
  }
  if ( HIBYTE(v128) )
  {
    if ( !thisa->m_has_indirect_lighting )
      goto LABEL_192;
    v33 = thisa->m_num_cascades - 1;
    if ( v33 >= 0 )
    {
      v34 = 476 * v33;
      do
      {
        vostok::render::radiance_volume::prepare_gv(M_start);
        --v33;
        v34 -= 476;
      }
      while ( v33 >= 0 );
    }
    v35 = thisa->m_context;
    v36 = (vostok::render::resource_manager *)v35->m_targets->m_family[55].target.m_object;
    v37 = 0;
    if ( v36 )
    {
      v37 = (const char *)v35->m_targets->m_family[55].target.m_object;
      ++v36->sh_created;
      m_deferred_context = v36->m_deferred_context;
    }
    else
    {
      m_deferred_context = 0;
    }
    m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    v7 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 539) == (_DWORD)m_deferred_context;
    *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 539) = m_deferred_context;
    LOBYTE(v36) = !v7;
    *((_BYTE *)m_conflicted_key_name + 167) |= !v7;
    if ( v37 )
    {
      v7 = (*(_DWORD *)v37)-- == 1;
      if ( v7 )
        vostok::render::resource_manager::release(
          v36,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          v37);
    }
    if ( s_debug_enabled_ds_clearing_value )
    {
      v36 = (vostok::render::resource_manager *)*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                + 539);
      if ( v36 )
        (*(void (__stdcall **)(int, vostok::render::resource_manager *, int, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                                            + 212))(
          `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
          v36,
          3,
          1.0,
          0);
    }
    v40 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    v41 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 547);
    v7 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 539) == v41;
    *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 539) = v41;
    LOBYTE(v36) = !v7;
    *((_BYTE *)v40 + 167) |= !v7;
    v42 = thisa->m_num_cascades - 1;
    if ( v42 >= 0 )
    {
      v43 = v42;
      do
      {
        vostok::render::radiance_volume::prepare(
          (vostok::render::radiance_volume *)v36,
          &thisa->m_radiance_volume[v43],
          (const vostok::math::float3 *)&thisa->m_context->m_view_pos,
          &thisa->m_context->m_view_dir.x);
        --v42;
        --v43;
      }
      while ( v42 >= 0 );
    }
    v44 = thisa->m_num_cascades - 1;
    if ( v44 >= 0 )
    {
      v45 = v44;
      do
      {
        vostok::render::radiance_volume::inject_camera_occluders(
          (vostok::render::radiance_volume *)thisa->m_context,
          (int)&thisa->m_radiance_volume[v45],
          thisa->m_context);
        --v44;
        --v45;
      }
      while ( v44 >= 0 );
    }
    v46 = object.m_object;
    if ( object.m_object && object.m_object->use_with_lpv )
    {
      v44 = thisa->m_num_cascades - 1;
      LODWORD(cascade_index) = v44;
      if ( v44 >= 0 )
      {
        v47 = 476 * v44;
        smaller_cascade_grid_size = 476 * v44;
        do
        {
          if ( !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                + 277) )
          {
            v48 = (char *)box_occluder_transforms._M_impl._M_finish - (char *)box_occluder_transforms._M_impl._M_start;
            v49 = box_occluder_transforms._M_impl._M_finish - box_occluder_transforms._M_impl._M_start;
            memset(&v121[4], 0, 12);
            HIDWORD(cascade_index) = v49;
            e = (const vostok::collision::object *const *)1;
            p_e = &e;
            if ( v49 )
              p_e = (const vostok::collision::object *const **)&cascade_index + 1;
            v51 = *p_e;
            v52 = vostok::render::g_allocator.m_object;
            v53 = (_DWORD)v51 << 6;
            v54 = BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) && v53;
            BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = v54;
            if ( v53 )
              v55 = (unsigned __int8 *)vostok_mspace_malloc(
                                         (void *)HIDWORD(v52->m_reconstruction_info_actuality_tick),
                                         v53);
            else
              v55 = 0;
            LODWORD(v56) = &v55[64 * v49];
            *(_DWORD *)&v121[4] = v55;
            *(_DWORD *)&v121[8] = v55;
            *(float *)&v121[12] = v56;
            if ( box_occluder_transforms._M_impl._M_finish != box_occluder_transforms._M_impl._M_start )
            {
              memcpy(v55, (unsigned __int8 *)box_occluder_transforms._M_impl._M_start, v48);
              v55 = (unsigned __int8 *)(v48 + v57);
            }
            *(_DWORD *)&v121[8] = v55;
            *(_DWORD *)v121 = cascade_index;
            vostok::render::stage_light_propagation_volumes::render_to_sun_rms(
              (vostok::render::stage_light_propagation_volumes *)object.m_object,
              *(float *)&thisa,
              *(float *)&v48,
              COERCE_FLOAT(&v121[4]),
              v56,
              thisa,
              object.m_object,
              *(vostok::render::vector<vostok::math::float4x4> *)v121,
              *(int *)&v121[12]);
            v44 = cascade_index;
            v47 = smaller_cascade_grid_size;
            v46 = object.m_object;
          }
          if ( !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                + 278) )
            vostok::render::stage_light_propagation_volumes::downsample_rsm(
              (vostok::render::stage_light_propagation_volumes *)&v46->direction,
              (int)thisa,
              &v46->direction,
              (const vostok::math::float3 *)((char *)&thisa->m_radiance_volume->m_bbox.min + v47),
              *(float *)((char *)&thisa->m_radiance_volume->m_scale + v47),
              v44);
          if ( !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                + 279) )
            vostok::render::radiance_volume::inject_lighting(
              (vostok::render::radiance_volume *)&v46->direction,
              COERCE_FLOAT((int)thisa->m_radiance_volume + v47),
              COERCE_FLOAT((vostok::render::light *)&v46->position),
              &v46->direction,
              1.0,
              thisa->m_rsm_downsampled_size);
          if ( !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                + 280) )
          {
            v58 = (char *)box_occluder_transforms._M_impl._M_finish - (char *)box_occluder_transforms._M_impl._M_start;
            v59 = box_occluder_transforms._M_impl._M_finish - box_occluder_transforms._M_impl._M_start;
            memset(&v121[4], 0, 12);
            HIDWORD(cascade_index) = v59;
            e = (const vostok::collision::object *const *)1;
            v60 = &e;
            if ( v59 )
              v60 = (const vostok::collision::object *const **)&cascade_index + 1;
            v61 = *v60;
            v62 = vostok::render::g_allocator.m_object;
            v63 = (_DWORD)v61 << 6;
            v64 = BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) && v63;
            BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = v64;
            if ( v63 )
              v65 = (unsigned __int8 *)vostok_mspace_malloc(
                                         (void *)HIDWORD(v62->m_reconstruction_info_actuality_tick),
                                         v63);
            else
              v65 = 0;
            *(_DWORD *)&v121[4] = v65;
            *(_DWORD *)&v121[8] = v65;
            *(_DWORD *)&v121[12] = &v65[64 * v59];
            if ( box_occluder_transforms._M_impl._M_finish != box_occluder_transforms._M_impl._M_start )
            {
              memcpy(v65, (unsigned __int8 *)box_occluder_transforms._M_impl._M_start, v58);
              v65 = (unsigned __int8 *)(v58 + v66);
            }
            *(_DWORD *)&v121[8] = v65;
            vostok::render::stage_light_propagation_volumes::inject_occluders(
              (vostok::render::stage_light_propagation_volumes *)cascade_index,
              (int)thisa,
              &object.m_object->position,
              &object.m_object->direction,
              *(vostok::math::float3 **)&v121[4],
              *(vostok::render::vector<vostok::math::float4x4> *)&v121[8]);
            v44 = cascade_index;
            v47 = smaller_cascade_grid_size;
            v46 = object.m_object;
          }
          --v44;
          v47 -= 476;
          LODWORD(cascade_index) = v44;
          smaller_cascade_grid_size = v47;
        }
        while ( v44 >= 0 );
      }
      thisa->m_has_indirect_lighting = 1;
    }
    y = *(float *)&objects._M_impl._M_start;
    pass_index = (unsigned int)objects._M_impl._M_start;
    for ( e = (const vostok::collision::object *const *)objects._M_impl._M_finish;
          (const vostok::collision::object *const *)pass_index != e;
          pass_index += 4 )
    {
      v68 = *(_DWORD *)(*(_DWORD *)pass_index + 36);
      if ( *(_BYTE *)(v68 + 349) )
      {
        v69 = *(_DWORD *)(v68 + 380) & 0xF;
        if ( v69 )
        {
          if ( v69 == 1 )
          {
            y = *(float *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start;
            if ( !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                  + 277) )
            {
              stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4>>::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4>>(
                (stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4> > *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start,
                (unsigned __int8 **)&v121[4],
                &box_occluder_transforms._M_impl);
              *(_DWORD *)v121 = v68;
              vostok::render::stage_light_propagation_volumes::render_to_spot_rms(
                v70,
                COERCE_FLOAT(&v121[4]),
                *(float *)&v44,
                thisa,
                *(vostok::render::vector<vostok::math::float4x4> *)v121,
                *(int *)&v121[12]);
            }
            v44 = thisa->m_num_cascades - 1;
            if ( v44 >= 0 )
            {
              v71 = 476 * v44;
              smaller_cascade_grid_size = 476 * v44;
              do
              {
                vostok::render::backend::flush_rt_shader_resources(
                  (vostok::render::backend *)LODWORD(y),
                  (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
                if ( !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                      + 278) )
                  vostok::render::stage_light_propagation_volumes::downsample_rsm(
                    (vostok::render::stage_light_propagation_volumes *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start,
                    (int)thisa,
                    (const vostok::math::float3 *)(v68 + 164),
                    (const vostok::math::float3 *)((char *)&thisa->m_radiance_volume->m_bbox.min + v71),
                    *(float *)((char *)&thisa->m_radiance_volume->m_scale + v71),
                    v44);
                y = *(float *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start;
                if ( !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                      + 279) )
                {
                  if ( *(float *)(v68 + 160) <= *(float *)(v68 + 188) )
                    HIDWORD(cascade_index) = *(_DWORD *)(v68 + 188);
                  else
                    HIDWORD(cascade_index) = *(_DWORD *)(v68 + 160);
                  vostok::render::radiance_volume::inject_lighting(
                    (vostok::render::radiance_volume *)(v68 + 148),
                    COERCE_FLOAT((int)thisa->m_radiance_volume + v71),
                    COERCE_FLOAT(v68 + 148),
                    (const vostok::math::float3 *)(v68 + 164),
                    *((float *)&cascade_index + 1),
                    thisa->m_rsm_downsampled_size);
                }
                if ( !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                      + 280) )
                {
                  stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4>>::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4>>(
                    &box_occluder_transforms._M_impl,
                    (unsigned __int8 **)&v121[4],
                    &box_occluder_transforms._M_impl);
                  vostok::render::stage_light_propagation_volumes::inject_occluders(
                    (vostok::render::stage_light_propagation_volumes *)v44,
                    (int)thisa,
                    (const vostok::math::float3 *)(v68 + 148),
                    (const vostok::math::float3 *)(v68 + 164),
                    *(vostok::math::float3 **)&v121[4],
                    *(vostok::render::vector<vostok::math::float4x4> *)&v121[8]);
                  v71 = smaller_cascade_grid_size;
                }
                --v44;
                v71 -= 476;
                smaller_cascade_grid_size = v71;
              }
              while ( v44 >= 0 );
            }
            thisa->m_has_indirect_lighting = 1;
          }
        }
        else
        {
          LODWORD(cascade_index) = 0;
          object.m_object = (vostok::render::light *)&dword_A57A6C;
          do
          {
            v7 = *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                 + 277) == 0;
            y = object.m_object->m_xform.i.y;
            *(_QWORD *)&smaller_cascade_grid_origin.x = *(_QWORD *)&object.m_object->m_reference_count;
            smaller_cascade_grid_origin.z = y;
            if ( v7 )
            {
              stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4>>::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4>>(
                (stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4> > *)LODWORD(y),
                (unsigned __int8 **)&v121[4],
                &box_occluder_transforms._M_impl);
              vostok::render::stage_light_propagation_volumes::render_to_point_rms(
                cascade_index,
                COERCE_FLOAT(&v121[4]),
                *(float *)&v44,
                thisa,
                (vostok::render::light *)v68,
                *(vostok::render::vector<vostok::math::float4x4> *)&v121[4]);
            }
            v44 = thisa->m_num_cascades - 1;
            if ( v44 >= 0 )
            {
              smaller_cascade_grid_size = 476 * v44;
              v72 = 476 * v44;
              do
              {
                vostok::render::backend::flush_rt_shader_resources(
                  (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                  (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
                if ( !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                      + 278) )
                  vostok::render::stage_light_propagation_volumes::downsample_rsm(
                    (vostok::render::stage_light_propagation_volumes *)&smaller_cascade_grid_origin,
                    (int)thisa,
                    &smaller_cascade_grid_origin,
                    (const vostok::math::float3 *)((char *)&thisa->m_radiance_volume->m_bbox.min + v72),
                    *(float *)((char *)&thisa->m_radiance_volume->m_scale + v72),
                    v44);
                if ( !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                      + 279) )
                  vostok::render::radiance_volume::inject_lighting(
                    (vostok::render::radiance_volume *)&smaller_cascade_grid_origin,
                    COERCE_FLOAT((int)thisa->m_radiance_volume + v72),
                    COERCE_FLOAT(v68 + 148),
                    &smaller_cascade_grid_origin,
                    1.5707964,
                    thisa->m_rsm_downsampled_size);
                y = *(float *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start;
                if ( !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                      + 280) )
                {
                  stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4>>::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4>>(
                    (stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4> > *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start,
                    (unsigned __int8 **)&v121[4],
                    &box_occluder_transforms._M_impl);
                  vostok::render::stage_light_propagation_volumes::inject_occluders(
                    (vostok::render::stage_light_propagation_volumes *)v44,
                    (int)thisa,
                    (const vostok::math::float3 *)(v68 + 148),
                    &smaller_cascade_grid_origin,
                    *(vostok::math::float3 **)&v121[4],
                    *(vostok::render::vector<vostok::math::float4x4> *)&v121[8]);
                  v72 = smaller_cascade_grid_size;
                }
                --v44;
                v72 -= 476;
                smaller_cascade_grid_size = v72;
              }
              while ( v44 >= 0 );
            }
            LODWORD(cascade_index) = cascade_index + 1;
            p_k = &object.m_object->m_xform.k;
            v74 = (int)&object.m_object->m_xform.k.0 < (int)&randomizer_20;
            thisa->m_has_indirect_lighting = 1;
            object.m_object = (vostok::render::light *)p_k;
          }
          while ( v74 );
        }
      }
    }
    if ( !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
          + 281) )
    {
      v75 = thisa->m_num_cascades - 1;
      if ( v75 >= 0 )
      {
        v76 = v75;
        do
          vostok::render::radiance_volume::propagate_lighting(
            (vostok::render::radiance_volume *)LODWORD(y),
            (unsigned int)&thisa->m_radiance_volume[v76--],
            v75--);
        while ( v75 >= 0 );
      }
    }
    v19 = vostok::render::g_allocator.m_object;
    if ( blend_alpha.x > *(float *)&clear_value )
      blend_alpha.x = 0.0;
  }
  if ( thisa->m_has_indirect_lighting
    && !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
        + 282) )
  {
    v77 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y;
    e = (const vostok::collision::object *const *)1;
    (*(void (__stdcall **)(int, const vostok::collision::object *const **, D3D11_VIEWPORT *))(*(_DWORD *)v77 + 380))(
      v77,
      &e,
      &orig_viewport);
    v78 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    tmp_viewport.TopLeftX = 0.0;
    tmp_viewport.TopLeftY = 0.0;
    tmp_viewport.MinDepth = 0.0;
    LODWORD(tmp_viewport.MaxDepth) = clear_value;
    pass_index = 0;
    do
    {
      for ( LODWORD(cascade_index) = thisa->m_num_cascades - 1;
            (int)cascade_index >= 0;
            LODWORD(cascade_index) = cascade_index - 1 )
      {
        if ( pass_index == 1 )
        {
          v79 = thisa->m_context->m_targets->m_family[3].target.m_object;
          v80 = 0;
          if ( v79 )
          {
            v80 = (vostok::render::resource_manager *)thisa->m_context->m_targets->m_family[3].target.m_object;
            ++v79->m_reference_count;
            m_rt = v79->m_rt;
          }
          else
          {
            m_rt = 0;
          }
          if ( *((ID3D11RenderTargetView **)v78 + 535) != m_rt )
          {
            *((_DWORD *)v78 + 535) = m_rt;
            *((_BYTE *)v78 + 163) = 1;
          }
          if ( *((_DWORD *)v78 + 536) )
          {
            *((_DWORD *)v78 + 536) = 0;
            *((_BYTE *)v78 + 164) = 1;
          }
          if ( *((_DWORD *)v78 + 537) )
          {
            *((_DWORD *)v78 + 537) = 0;
            *((_BYTE *)v78 + 165) = 1;
          }
          if ( *((_DWORD *)v78 + 538) )
          {
            *((_DWORD *)v78 + 538) = 0;
            *((_BYTE *)v78 + 166) = 1;
          }
          if ( v80 )
          {
            v7 = v80->sh_created-- == 1;
            if ( v7 )
              vostok::render::resource_manager::release(
                v80,
                (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                (const char *)v80);
          }
          v82 = &thisa->m_apply_indirect_lighting_effect.m_object->__vftable;
          v83 = (v82[71] - v82[70]) >> 2;
          if ( v83 > 1 )
          {
            v82[69] = 1;
            vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v83, *(unsigned int *)&v121[16]);
          }
          v84 = thisa->m_context;
          v85 = v84->m_targets->m_family[3].target.m_object;
          v86 = 0;
          if ( v85 )
          {
            v86 = v84->m_targets->m_family[3].target.m_object;
            ++v85->m_reference_count;
          }
          tmp_viewport.Width = (float)v86->m_width;
          v7 = v86->m_reference_count-- == 1;
          if ( v7 )
            vostok::render::resource_manager::release(
              (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
              (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
              (const char *)v86);
          p_target = &thisa->m_context->m_targets->m_family[3].target;
        }
        else
        {
          v88 = thisa->m_context;
          v89 = v88->m_targets->m_family[26].target.m_object;
          v90 = 0;
          if ( v89 )
          {
            v90 = (vostok::render::resource_manager *)v88->m_targets->m_family[26].target.m_object;
            ++v89->m_reference_count;
            v91 = v89->m_rt;
          }
          else
          {
            v91 = 0;
          }
          if ( *((ID3D11RenderTargetView **)v78 + 535) != v91 )
          {
            *((_DWORD *)v78 + 535) = v91;
            *((_BYTE *)v78 + 163) = 1;
          }
          if ( *((_DWORD *)v78 + 536) )
          {
            *((_DWORD *)v78 + 536) = 0;
            *((_BYTE *)v78 + 164) = 1;
          }
          if ( *((_DWORD *)v78 + 537) )
          {
            *((_DWORD *)v78 + 537) = 0;
            *((_BYTE *)v78 + 165) = 1;
          }
          if ( *((_DWORD *)v78 + 538) )
          {
            *((_DWORD *)v78 + 538) = 0;
            *((_BYTE *)v78 + 166) = 1;
          }
          if ( v90 )
          {
            v7 = v90->sh_created-- == 1;
            if ( v7 )
              vostok::render::resource_manager::release(
                v90,
                (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                (const char *)v90);
          }
          v92 = &thisa->m_apply_indirect_lighting_effect.m_object->__vftable;
          v93 = (v92[71] - v92[70]) >> 2;
          if ( v93 )
          {
            v92[69] = 0;
            vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v93, *(unsigned int *)&v121[16]);
          }
          v94 = thisa->m_context;
          v95 = v94->m_targets->m_family[26].target.m_object;
          v96 = 0;
          if ( v95 )
          {
            v96 = v94->m_targets->m_family[26].target.m_object;
            ++v95->m_reference_count;
          }
          tmp_viewport.Width = (float)v96->m_width;
          v7 = v96->m_reference_count-- == 1;
          if ( v7 )
            vostok::render::resource_manager::release(
              (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
              (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
              (const char *)v96);
          p_target = &thisa->m_context->m_targets->m_family[26].target;
        }
        v97 = p_target->m_object;
        v98 = 0;
        if ( v97 )
        {
          v98 = (const char *)v97;
          ++v97->m_reference_count;
        }
        tmp_viewport.Height = (float)*((unsigned int *)v98 + 8);
        v7 = (*(_DWORD *)v98)-- == 1;
        if ( v7 )
          vostok::render::resource_manager::release(
            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            v98);
        (*(void (__stdcall **)(int, int, D3D11_VIEWPORT *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                          + 176))(
          `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
          1,
          &tmp_viewport);
        v99 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        v100 = 119 * cascade_index;
        *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 167) |= *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 539) != 0;
        *((_DWORD *)v99 + 539) = 0;
        *(_DWORD *)&v121[12] = thisa->m_radiance_volume[v100 / 0x77].m_3d_t_radiance_r_apply.m_object;
        v101 = v99;
        HIDWORD(cascade_index) = v100 * 4;
        v102 = vostok::render::textures_handler<0>::set_overwrite(
                 *(vostok::render::textures_handler<0> **)&v121[12],
                 (char *)v99 + 1488,
                 (vostok::render::res_texture *)&stru_964DF4.m_desc.ArraySize,
                 *(vostok::render::res_texture **)&v121[12]);
        v103 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        *((_BYTE *)v101 + 159) = v102;
        *((_BYTE *)v103 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                                   (vostok::render::textures_handler<0> *)(v103 + 1488),
                                   (char *)v103 + 1488,
                                   (vostok::render::res_texture *)&stru_964DF4.m_desc.Usage,
                                   thisa->m_radiance_volume[v100 / 0x77].m_3d_t_radiance_g_apply.m_object);
        m_radiance_volume = (vostok::render::textures_handler<0> *)thisa->m_radiance_volume;
        *(_DWORD *)&v121[12] = m_radiance_volume->m_tmp_buffer[v100 + 81];
        v105 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        *((_BYTE *)v105 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                                   m_radiance_volume,
                                   (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                 + 1488,
                                   (vostok::render::res_texture *)&stru_964DF4.m_desc_3d,
                                   *(vostok::render::res_texture **)&v121[12]);
        v106 = (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        v107 = (vostok::render::constants_handler<1> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                      + 1476);
        vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
          thisa->m_c_cascade_index,
          (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
        + 123,
          (const vostok::math::float3 *)&cascade_index);
        ++v106[7].m_current.m_object;
        vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
          thisa->m_c_num_cascades,
          v107,
          (const vostok::math::float3 *)&thisa->m_num_cascades);
        ++v106[7].m_current.m_object;
        v108 = vostok::math::pow(
                 (const vostok::math::float3_pod *)&thisa->m_context->m_scene_view.m_object[1].180,
                 v133,
                 2.2);
        vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
          thisa->m_c_ambient_color,
          v106 + 123,
          v108);
        ++v106[7].m_current.m_object;
        m_c_grid_cell_size = thisa->m_c_grid_cell_size;
        *(float *)&smaller_cascade_grid_size = *(float *)((char *)&thisa->m_radiance_volume->m_scale
                                                        + HIDWORD(cascade_index))
                                             / (double)thisa->m_grid_size;
        vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
          m_c_grid_cell_size,
          v106 + 123,
          (const vostok::math::float3 *)&smaller_cascade_grid_size);
        ++v106[7].m_current.m_object;
        *(float *)&smaller_cascade_grid_size = (float)thisa->m_grid_size;
        vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
          thisa->m_c_grid_size,
          v106 + 123,
          (const vostok::math::float3 *)&smaller_cascade_grid_size);
        ++v106[7].m_current.m_object;
        vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
          thisa->m_c_grid_origin,
          v106 + 123,
          (const vostok::math::float3 *)((char *)&thisa->m_radiance_volume->m_bbox.min + HIDWORD(cascade_index)));
        ++v106[7].m_current.m_object;
        blend_alpha.x = thisa->m_context->m_time_delta + blend_alpha.x;
        vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
          thisa->m_c_radiance_blend_factor,
          v106 + 123,
          &blend_alpha);
        ++v106[7].m_current.m_object;
        m_grid_size = (double)thisa->m_grid_size;
        v111 = &thisa->m_radiance_volume[cascade_index - ((_DWORD)cascade_index != 0)];
        v112 = *(_QWORD *)&v111->m_bbox.min.x;
        v113 = v111->m_scale / m_grid_size;
        z = v111->m_bbox.min.z;
        *(_DWORD *)&v121[12] = (char *)&cascade_index + 4;
        m_c_smaller_cascade_grid_cell_size = thisa->m_c_smaller_cascade_grid_cell_size;
        *(_QWORD *)&smaller_cascade_grid_origin.x = v112;
        smaller_cascade_grid_origin.z = z;
        *((float *)&cascade_index + 1) = v113;
        *(float *)&smaller_cascade_grid_size = m_grid_size;
        vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
          m_c_smaller_cascade_grid_cell_size,
          v106 + 123,
          (const vostok::math::float3 *)((char *)&cascade_index + 4));
        ++v106[7].m_current.m_object;
        vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
          thisa->m_c_smaller_cascade_grid_size,
          v106 + 123,
          (const vostok::math::float3 *)&smaller_cascade_grid_size);
        ++v106[7].m_current.m_object;
        vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
          thisa->m_c_smaller_cascade_grid_origin,
          v106 + 123,
          &smaller_cascade_grid_origin);
        v116 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start;
        ++v106[7].m_current.m_object;
        vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
          thisa->m_c_interreflection_contribution,
          v106 + 123,
          (const vostok::math::float3 *)(v116 + 5));
        ++v106[7].m_current.m_object;
        vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
          thisa->m_c_eye_ray_corner,
          v106 + 123,
          thisa->m_context->m_eye_rays);
        ++v106[7].m_current.m_object;
        vostok::render::stage_light_propagation_volumes::render_quad(v117, thisa);
        v78 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        vostok::render::backend::reset_render_targets(
          v118,
          (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
        v119 = *((_DWORD *)v78 + 547);
        v7 = *((_DWORD *)v78 + 539) == v119;
        *((_DWORD *)v78 + 539) = v119;
        *((_BYTE *)v78 + 167) |= !v7;
      }
      ++pass_index;
    }
    while ( !pass_index );
    (*(void (__stdcall **)(int, int, D3D11_VIEWPORT *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                      + 176))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      1,
      &orig_viewport);
    v19 = vostok::render::g_allocator.m_object;
  }
LABEL_192:
  v120 = box_occluder_transforms._M_impl._M_start;
  if ( box_occluder_transforms._M_impl._M_start )
  {
    BYTE2(v19->m_children_resources.m_lock) = 0;
    vostok_mspace_free((void *)HIDWORD(v19->m_reconstruction_info_actuality_tick), (void *)v120);
  }
  if ( objects._M_impl._M_start )
    objects._M_impl._M_end_of_storage.m_allocator->call_free(
      objects._M_impl._M_end_of_storage.m_allocator,
      objects._M_impl._M_start);
}
