void __thiscall vostok::render::stage_light_propagation_volumes::execute_smoothed_impl(
        vostok::render::stage_light_propagation_volumes *this,
        int current_cascade_index,
        int stage_index,
        unsigned int propagation_iteration_index,
        float render_stage_index,
        vostok::math::float4x4 *num_render_stages,
        float smaller_cascade_grid_size)
{
  int v7; // ebp
  const vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v8; // eax
  vostok::render::light *m_object; // ecx
  const vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v10; // eax
  vostok::render::light *v11; // ebx
  vostok::render::light *v12; // ecx
  vostok::render::grass_render_model *v13; // esi
  bool v14; // zf
  int v15; // ecx
  int v16; // ecx
  const stlp_std::pair<unsigned int,vostok::math::float4x4> *v17; // edx
  stlp_std::pair<unsigned int,vostok::math::float4x4> *p_second; // ecx
  vostok::math::float4x4 *v19; // eax
  vostok::render::grass_render_model *v20; // esi
  unsigned int v21; // edi
  unsigned int v22; // eax
  int *v23; // ecx
  unsigned int v24; // ebx
  int *v25; // eax
  unsigned int v26; // ecx
  bool v27; // al
  unsigned __int8 *v28; // eax
  int v29; // eax
  vostok::math::float4x4 *v30; // edi
  vostok::math::float4x4 *M_start; // eax
  unsigned int v32; // esi
  vostok::render::radiance_volume *v33; // ecx
  _DWORD *v34; // eax
  vostok::render::resource_manager *v35; // ecx
  int v36; // esi
  const char *m_conflicted_key_name; // eax
  int v38; // ecx
  vostok::render::radiance_volume *v39; // ecx
  unsigned int v40; // edi
  float v41; // esi
  int v42; // eax
  vostok::render::stage_light_propagation_volumes *v43; // ecx
  _DWORD *v44; // eax
  vostok::render::resource_manager *v45; // ecx
  int v46; // edx
  const char *v47; // eax
  int y; // eax
  const char *v49; // esi
  _DWORD *v50; // eax
  char *v51; // ecx
  int v52; // eax
  _DWORD *v53; // eax
  _DWORD *v54; // eax
  int v55; // ecx
  _DWORD *v56; // eax
  survarium::options_tab *v57; // ecx
  _DWORD *v58; // eax
  vostok::render::resource_manager *v59; // ecx
  int v60; // eax
  _DWORD *v61; // eax
  int v62; // ecx
  int v63; // edx
  _DWORD *v64; // eax
  int v65; // ecx
  int v66; // edx
  _DWORD *v67; // eax
  int v68; // ecx
  const char *v69; // eax
  unsigned int v70; // ebx
  const char *v71; // esi
  char v72; // al
  const char *v73; // ecx
  const char *v74; // esi
  const char *v75; // esi
  vostok::render::constants_handler<1> *v76; // edi
  float *v77; // eax
  double v78; // st7
  double v79; // st7
  const vostok::render::shader_constant_host *v80; // eax
  const vostok::render::shader_constant_host *v81; // eax
  double v82; // st7
  unsigned int v83; // eax
  __int64 v84; // xmm0_8
  double v85; // st6
  float v86; // edx
  const vostok::render::shader_constant_host *v87; // eax
  survarium::game_action_id *v88; // eax
  vostok::render::stage_light_propagation_volumes *v89; // ecx
  vostok::render::backend *v90; // ecx
  int v91; // eax
  vostok::math::float4x4 *v92; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::render::vector<vostok::math::float4x4> v94; // [esp+8h] [ebp-94h] BYREF
  vostok::math::float3 *g; // [esp+14h] [ebp-88h] BYREF
  vostok::render::vector<vostok::math::float4x4> _X; // [esp+18h] [ebp-84h]
  vostok::math::float4x4 *v97; // [esp+30h] [ebp-6Ch]
  vostok::math::float4x4 *v98; // [esp+34h] [ebp-68h] BYREF
  const stlp_std::pair<unsigned int,vostok::math::float4x4> *it; // [esp+38h] [ebp-64h]
  int v100; // [esp+3Ch] [ebp-60h] BYREF
  const stlp_std::pair<unsigned int,vostok::math::float4x4> *end; // [esp+40h] [ebp-5Ch]
  vostok::render::vector<vostok::math::float4x4> box_occluder_transforms; // [esp+44h] [ebp-58h] BYREF
  vostok::math::float3 arg; // [esp+50h] [ebp-4Ch] BYREF
  vostok::math::float3 smaller_cascade_grid_origin; // [esp+5Ch] [ebp-40h] BYREF
  D3D11_VIEWPORT tmp_viewport; // [esp+68h] [ebp-34h] BYREF
  D3D11_VIEWPORT orig_viewport; // [esp+80h] [ebp-1Ch] BYREF

  v7 = current_cascade_index;
  v8 = *(const vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)(*(_DWORD *)(*(_DWORD *)(current_cascade_index + 4) + 12388) + 944);
  m_object = v8[3].m_object;
  v10 = v8 + 3;
  if ( m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
    && !m_object->m_enabled )
  {
    v11 = 0;
    current_cascade_index = 0;
  }
  else
  {
    current_cascade_index = 0;
    vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
      (vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)m_object,
      (const vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&current_cascade_index,
      v10);
    v11 = (vostok::render::light *)current_cascade_index;
    if ( current_cascade_index )
    {
      --*(_DWORD *)current_cascade_index;
      if ( !v11->m_reference_count )
      {
        v13 = vostok::render::g_allocator.m_object;
        vostok::render::light::~light(v12, (int)v11);
        BYTE2(v13->m_children_resources.m_lock) = 0;
        vostok_mspace_free((void *)HIDWORD(v13->m_reconstruction_info_actuality_tick), v11);
      }
    }
  }
  *(_BYTE *)(v7 + 64) = 0;
  if ( v11 && v11->use_with_lpv )
    *(_BYTE *)(v7 + 64) = 1;
  v14 = *(_BYTE *)(v7 + 64) == 0;
  box_occluder_transforms._M_impl._M_start = 0;
  box_occluder_transforms._M_impl._M_end_of_storage._M_data = 0;
  v15 = *(_DWORD *)(v7 + 4);
  *(_BYTE *)(v7 + 64) = !v14;
  v16 = *(_DWORD *)(v15 + 12388);
  v17 = *(const stlp_std::pair<unsigned int,vostok::math::float4x4> **)(v16 + 916);
  p_second = *(stlp_std::pair<unsigned int,vostok::math::float4x4> **)(v16 + 920);
  v19 = 0;
  box_occluder_transforms._M_impl._M_finish = 0;
  it = v17;
  end = p_second;
  if ( v17 != p_second )
  {
    v20 = vostok::render::g_allocator.m_object;
    p_second = (stlp_std::pair<unsigned int,vostok::math::float4x4> *)&v17->second;
    v97 = &v17->second;
    do
    {
      if ( v19 == box_occluder_transforms._M_impl._M_end_of_storage._M_data )
      {
        v21 = (char *)v19 - (char *)box_occluder_transforms._M_impl._M_start;
        v22 = v19 - box_occluder_transforms._M_impl._M_start;
        v100 = 1;
        v98 = (vostok::math::float4x4 *)v22;
        if ( &vostok::memory::s_CRT_arena[55905847] == (unsigned __int8 *)v22 )
          stlp_std::__stl_throw_length_error("vector");
        v23 = (int *)&v98;
        if ( v22 <= 1 )
          v23 = &v100;
        v24 = v22 + *v23;
        if ( v24 > (unsigned int)&vostok::memory::s_CRT_arena[55905847] || v24 < v22 )
          v24 = (unsigned int)&vostok::memory::s_CRT_arena[55905847];
        v98 = (vostok::math::float4x4 *)v24;
        v100 = 1;
        v25 = &v100;
        if ( v24 )
          v25 = (int *)&v98;
        v26 = *v25 << 6;
        v27 = BYTE2(v20->m_children_resources.m_lock) && v26;
        BYTE2(v20->m_children_resources.m_lock) = v27;
        if ( v26 )
          v28 = (unsigned __int8 *)vostok_mspace_malloc((void *)HIDWORD(v20->m_reconstruction_info_actuality_tick), v26);
        else
          v28 = 0;
        v98 = (vostok::math::float4x4 *)v28;
        if ( v21 )
        {
          memmove(v28, (unsigned __int8 *)box_occluder_transforms._M_impl._M_start, v21);
          v28 = (unsigned __int8 *)(v21 + v29);
        }
        v14 = box_occluder_transforms._M_impl._M_start == 0;
        qmemcpy(v28, v97, 0x40u);
        v20 = vostok::render::g_allocator.m_object;
        v30 = (vostok::math::float4x4 *)(v28 + 64);
        p_second = (stlp_std::pair<unsigned int,vostok::math::float4x4> *)vostok::render::g_allocator.m_object;
        if ( !v14 )
        {
          M_start = box_occluder_transforms._M_impl._M_start;
          BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
          vostok_mspace_free((void *)LODWORD(p_second->second.j.x), (void *)M_start);
          v20 = vostok::render::g_allocator.m_object;
        }
        v17 = it;
        box_occluder_transforms._M_impl._M_start = v98;
        box_occluder_transforms._M_impl._M_end_of_storage._M_data = &v98[v24];
        v11 = (vostok::render::light *)current_cascade_index;
        v19 = v30;
      }
      else
      {
        if ( v19 )
        {
          qmemcpy((void *)v19, v97, sizeof(vostok::math::float4x4));
          p_second = 0;
          v20 = vostok::render::g_allocator.m_object;
        }
        ++v19;
      }
      v97 = (vostok::math::float4x4 *)((char *)v97 + 68);
      ++v17;
      box_occluder_transforms._M_impl._M_finish = v19;
      it = v17;
    }
    while ( v17 != end );
  }
  if ( *(_BYTE *)(v7 + 64) )
  {
    if ( !propagation_iteration_index )
    {
      v32 = 476 * stage_index;
      vostok::render::radiance_volume::prepare_gv((vostok::render::radiance_volume *)p_second);
      vostok::render::radiance_volume::prepare(
        v33,
        (vostok::render::radiance_volume *)(v32 + *(_DWORD *)(v7 + 44)),
        (const vostok::math::float3 *)(*(_DWORD *)(v7 + 4) + 16900),
        (float *)(*(_DWORD *)(v7 + 4) + 16932));
    }
    v34 = *(_DWORD **)(**(_DWORD **)(v7 + 4) + 8952);
    v35 = 0;
    if ( v34 )
    {
      v35 = *(vostok::render::resource_manager **)(**(_DWORD **)(v7 + 4) + 8952);
      ++*v34;
      v36 = v34[5];
    }
    else
    {
      v36 = 0;
    }
    m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    v14 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 539) == v36;
    *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 539) = v36;
    *((_BYTE *)m_conflicted_key_name + 167) |= !v14;
    if ( v35 )
    {
      if ( !--v35->sh_created )
      {
        vostok::render::resource_manager::release(
          v35,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (const char *)v35);
        m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      }
    }
    if ( s_debug_enabled_ds_clearing_value )
    {
      v38 = *((_DWORD *)m_conflicted_key_name + 539);
      if ( v38 )
      {
        (*(void (__stdcall **)(int, int, int, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                             + 212))(
          `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
          v38,
          3,
          1.0,
          0);
        m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      }
    }
    v39 = (vostok::render::radiance_volume *)*((_DWORD *)m_conflicted_key_name + 547);
    v40 = stage_index;
    *((_BYTE *)m_conflicted_key_name + 167) |= *((_DWORD *)m_conflicted_key_name + 539) != (_DWORD)v39;
    LODWORD(v41) = 476 * v40;
    *((_DWORD *)m_conflicted_key_name + 539) = v39;
    vostok::render::radiance_volume::inject_camera_occluders(
      v39,
      476 * v40 + *(_DWORD *)(v7 + 44),
      *(vostok::render::renderer_context **)(v7 + 4));
    if ( v11 && v11->use_with_lpv )
    {
      if ( !propagation_iteration_index )
      {
        v42 = *(_DWORD *)(v7 + 4);
        *(_QWORD *)(v7 + 16) = *(_QWORD *)(v42 + 16900);
        p_second = *(stlp_std::pair<unsigned int,vostok::math::float4x4> **)(v42 + 16908);
        *(_DWORD *)(v7 + 24) = p_second;
      }
      if ( !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
            + 277) )
      {
        *(float *)&_X._M_impl._M_finish = smaller_cascade_grid_size;
        _X._M_impl._M_start = num_render_stages;
        stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4>>::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4>>(
          (stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4> > *)num_render_stages,
          (unsigned __int8 **)&v94._M_impl._M_finish,
          &box_occluder_transforms._M_impl);
        v94._M_impl._M_start = (vostok::math::float4x4 *)stage_index;
        vostok::render::stage_light_propagation_volumes::render_to_sun_rms_smoothed(
          v43,
          *(float *)&v11,
          *(float *)&v7,
          COERCE_FLOAT((vostok::render::vector<vostok::math::float4x4> *)&v94._M_impl._M_finish),
          v41,
          (vostok::render::stage_light_propagation_volumes *)v7,
          v11,
          v94,
          (const unsigned int)g,
          (vostok::math *)_X._M_impl._M_start,
          (unsigned int)_X._M_impl._M_finish);
        v40 = stage_index;
      }
      if ( propagation_iteration_index )
      {
        if ( propagation_iteration_index == 1 )
        {
          if ( !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                + 279) )
            vostok::render::stage_light_propagation_volumes::inject_lighting(
              (vostok::render::stage_light_propagation_volumes *)v7,
              v40,
              &v11->position,
              &v11->direction,
              1.0);
        }
        else if ( propagation_iteration_index == 2
               && !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                   + 280) )
        {
          stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4>>::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4>>(
            (stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4> > *)p_second,
            (unsigned __int8 **)&g,
            &box_occluder_transforms._M_impl);
          vostok::render::stage_light_propagation_volumes::inject_occluders(
            (vostok::render::stage_light_propagation_volumes *)stage_index,
            v7,
            &v11->position,
            &v11->direction,
            g,
            _X);
          v40 = stage_index;
        }
      }
      else
      {
        p_second = (stlp_std::pair<unsigned int,vostok::math::float4x4> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start;
        if ( !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
              + 278) )
          vostok::render::stage_light_propagation_volumes::downsample_rsm(
            (vostok::render::stage_light_propagation_volumes *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start,
            v7,
            &v11->direction,
            (const vostok::math::float3 *)(LODWORD(v41) + *(_DWORD *)(v7 + 44) + 204),
            *(float *)(LODWORD(v41) + *(_DWORD *)(v7 + 44) + 192),
            v40);
      }
      *(_BYTE *)(v7 + 64) = 1;
    }
    if ( propagation_iteration_index > 2
      && !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
          + 281) )
    {
      vostok::render::radiance_volume::propagate_lighting_iter(
        (vostok::render::radiance_volume *)(LODWORD(v41) + *(_DWORD *)(v7 + 44)),
        COERCE_FLOAT(LODWORD(v41) + *(_DWORD *)(v7 + 44)),
        v40,
        LODWORD(render_stage_index));
    }
    if ( blend_alpha.x > *(float *)&clear_value )
      blend_alpha.x = 0.0;
  }
  else
  {
    v40 = stage_index;
  }
  if ( LODWORD(render_stage_index) == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                                      + 35)
                                    - 1 )
    vostok::render::radiance_volume::prepare_final(
      (vostok::render::radiance_volume *)p_second,
      (vostok::render::radiance_volume *)(*(_DWORD *)(v7 + 44) + 476 * v40));
  v44 = *(_DWORD **)(**(_DWORD **)(v7 + 4) + 4792);
  v45 = 0;
  if ( v44 )
  {
    v45 = *(vostok::render::resource_manager **)(**(_DWORD **)(v7 + 4) + 4792);
    ++*v44;
    v46 = v44[4];
  }
  else
  {
    v46 = 0;
  }
  v47 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  if ( *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) != v46 )
  {
    *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) = v46;
    *((_BYTE *)v47 + 163) = 1;
  }
  if ( *((_DWORD *)v47 + 536) )
  {
    *((_DWORD *)v47 + 536) = 0;
    *((_BYTE *)v47 + 164) = 1;
  }
  if ( *((_DWORD *)v47 + 537) )
  {
    *((_DWORD *)v47 + 537) = 0;
    *((_BYTE *)v47 + 165) = 1;
  }
  if ( *((_DWORD *)v47 + 538) )
  {
    *((_DWORD *)v47 + 538) = 0;
    *((_BYTE *)v47 + 166) = 1;
  }
  if ( v45 )
  {
    v14 = v45->sh_created-- == 1;
    if ( v14 )
    {
      vostok::render::resource_manager::release(
        v45,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)v45);
      v47 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    }
  }
  vostok::render::backend::clear_render_targets(
    (vostok::render::backend *)v45,
    (int)v47,
    0.0,
    0.0,
    0.0,
    0.0,
    *(float *)&_X._M_impl._M_end_of_storage._M_data);
  if ( *(_BYTE *)(v7 + 64)
    && !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
        + 282) )
  {
    y = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y;
    current_cascade_index = 1;
    (*(void (__stdcall **)(int, int *, D3D11_VIEWPORT *))(*(_DWORD *)y + 380))(
      y,
      &current_cascade_index,
      &orig_viewport);
    v49 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    tmp_viewport.TopLeftX = 0.0;
    tmp_viewport.TopLeftY = 0.0;
    tmp_viewport.MinDepth = 0.0;
    LODWORD(tmp_viewport.MaxDepth) = clear_value;
    propagation_iteration_index = 0;
    do
    {
      for ( stage_index = *(_DWORD *)(v7 + 48) - 1; stage_index >= 0; --stage_index )
      {
        if ( propagation_iteration_index == 1 )
        {
          v50 = *(_DWORD **)(**(_DWORD **)(v7 + 4) + 632);
          v51 = 0;
          if ( v50 )
          {
            v51 = *(char **)(**(_DWORD **)(v7 + 4) + 632);
            ++*v50;
            v52 = v50[4];
          }
          else
          {
            v52 = 0;
          }
          if ( *((_DWORD *)v49 + 535) != v52 )
          {
            *((_DWORD *)v49 + 535) = v52;
            *((_BYTE *)v49 + 163) = 1;
          }
          if ( *((_DWORD *)v49 + 536) )
          {
            *((_DWORD *)v49 + 536) = 0;
            *((_BYTE *)v49 + 164) = 1;
          }
          if ( *((_DWORD *)v49 + 537) )
          {
            *((_DWORD *)v49 + 537) = 0;
            *((_BYTE *)v49 + 165) = 1;
          }
          if ( *((_DWORD *)v49 + 538) )
          {
            *((_DWORD *)v49 + 538) = 0;
            *((_BYTE *)v49 + 166) = 1;
          }
          if ( v51 )
          {
            v14 = (*(_DWORD *)v51)-- == 1;
            if ( v14 )
              vostok::render::resource_manager::release(
                (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                v51);
          }
          v53 = *(_DWORD **)(v7 + 716);
          if ( (unsigned int)((v53[71] - v53[70]) >> 2) > 1 )
          {
            v53[69] = 1;
            vostok::render::res_effect::apply_pass(
              (vostok::render::res_effect *)v51,
              (unsigned int)_X._M_impl._M_end_of_storage._M_data);
          }
          v54 = *(_DWORD **)(**(_DWORD **)(v7 + 4) + 632);
          v55 = 0;
          if ( v54 )
          {
            v55 = *(_DWORD *)(**(_DWORD **)(v7 + 4) + 632);
            ++*v54;
          }
          tmp_viewport.Width = (float)*(unsigned int *)(v55 + 28);
          v14 = (*(_DWORD *)v55)-- == 1;
          if ( v14 )
            vostok::render::resource_manager::release(
              (vostok::render::resource_manager *)v55,
              (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
              (const char *)v55);
          v56 = *(_DWORD **)(**(_DWORD **)(v7 + 4) + 632);
          v57 = 0;
          if ( v56 )
          {
            v57 = *(survarium::options_tab **)(**(_DWORD **)(v7 + 4) + 632);
            ++*v56;
          }
          tmp_viewport.Height = (float)(unsigned int)v57[1].m_game;
          v14 = v57->m_options-- == (survarium::options_item_base **)1;
          if ( !v14 )
            goto LABEL_142;
          _X._M_impl._M_finish = (vostok::math::float4x4 *)v57;
          _X._M_impl._M_start = (vostok::math::float4x4 *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
        }
        else
        {
          v58 = *(_DWORD **)(**(_DWORD **)(v7 + 4) + 4792);
          v59 = 0;
          if ( v58 )
          {
            v59 = *(vostok::render::resource_manager **)(**(_DWORD **)(v7 + 4) + 4792);
            ++*v58;
            v60 = v58[4];
          }
          else
          {
            v60 = 0;
          }
          if ( *((_DWORD *)v49 + 535) != v60 )
          {
            *((_DWORD *)v49 + 535) = v60;
            *((_BYTE *)v49 + 163) = 1;
          }
          if ( *((_DWORD *)v49 + 536) )
          {
            *((_DWORD *)v49 + 536) = 0;
            *((_BYTE *)v49 + 164) = 1;
          }
          if ( *((_DWORD *)v49 + 537) )
          {
            *((_DWORD *)v49 + 537) = 0;
            *((_BYTE *)v49 + 165) = 1;
          }
          if ( *((_DWORD *)v49 + 538) )
          {
            *((_DWORD *)v49 + 538) = 0;
            *((_BYTE *)v49 + 166) = 1;
          }
          if ( v59 )
          {
            v14 = v59->sh_created-- == 1;
            if ( v14 )
              vostok::render::resource_manager::release(
                v59,
                (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                (const char *)v59);
          }
          v61 = *(_DWORD **)(v7 + 716);
          v62 = (v61[71] - v61[70]) >> 2;
          if ( v62 )
          {
            v61[69] = 0;
            vostok::render::res_effect::apply_pass(
              (vostok::render::res_effect *)v62,
              (unsigned int)_X._M_impl._M_end_of_storage._M_data);
          }
          v63 = *(_DWORD *)(v7 + 4);
          v64 = *(_DWORD **)(*(_DWORD *)v63 + 4792);
          v65 = 0;
          if ( v64 )
          {
            v65 = *(_DWORD *)(*(_DWORD *)v63 + 4792);
            ++*v64;
          }
          tmp_viewport.Width = (float)*(unsigned int *)(v65 + 28);
          v14 = (*(_DWORD *)v65)-- == 1;
          if ( v14 )
            vostok::render::resource_manager::release(
              (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
              (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
              (const char *)v65);
          v66 = *(_DWORD *)(v7 + 4);
          v67 = *(_DWORD **)(*(_DWORD *)v66 + 4792);
          v68 = 0;
          if ( v67 )
          {
            v68 = *(_DWORD *)(*(_DWORD *)v66 + 4792);
            ++*v67;
          }
          tmp_viewport.Height = (float)*(unsigned int *)(v68 + 32);
          v14 = (*(_DWORD *)v68)-- == 1;
          if ( !v14 )
            goto LABEL_142;
          _X._M_impl._M_finish = (vostok::math::float4x4 *)v68;
          v57 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
          _X._M_impl._M_start = (vostok::math::float4x4 *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
        }
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)v57,
          (vostok::render::resource_manager *)_X._M_impl._M_start,
          (const char *)_X._M_impl._M_finish);
LABEL_142:
        (*(void (__stdcall **)(int, int, D3D11_VIEWPORT *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                          + 176))(
          `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
          1,
          &tmp_viewport);
        v69 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        v70 = 476 * stage_index;
        *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 167) |= *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 539) != 0;
        *((_DWORD *)v69 + 539) = 0;
        _X._M_impl._M_finish = *(vostok::math::float4x4 **)(*(_DWORD *)(v7 + 44) + v70 + 328);
        v71 = v69;
        v72 = vostok::render::textures_handler<0>::set_overwrite(
                (vostok::render::textures_handler<0> *)_X._M_impl._M_finish,
                (char *)v69 + 1488,
                (vostok::render::res_texture *)&stru_964DF4.m_desc.ArraySize,
                (vostok::render::res_texture *)_X._M_impl._M_finish);
        v73 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        *((_BYTE *)v71 + 159) = v72;
        *((_BYTE *)v73 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                                  (vostok::render::textures_handler<0> *)(v73 + 1488),
                                  (char *)v73 + 1488,
                                  (vostok::render::res_texture *)&stru_964DF4.m_desc.Usage,
                                  *(vostok::render::res_texture **)(*(_DWORD *)(v7 + 44) + v70 + 332));
        _X._M_impl._M_finish = *(vostok::math::float4x4 **)(*(_DWORD *)(v7 + 44) + v70 + 336);
        v74 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        *((_BYTE *)v74 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                                  (vostok::render::textures_handler<0> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                        + 1488),
                                  (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                + 1488,
                                  (vostok::render::res_texture *)&stru_964DF4.m_desc_3d,
                                  (vostok::render::res_texture *)_X._M_impl._M_finish);
        v75 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        v76 = (vostok::render::constants_handler<1> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                     + 1476);
        vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
          *(const vostok::render::shader_constant_host **)(v7 + 832),
          (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
        + 123,
          (const vostok::math::float3 *)&stage_index);
        ++*((_DWORD *)v75 + 23);
        vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
          *(const vostok::render::shader_constant_host **)(v7 + 836),
          v76,
          (const vostok::math::float3 *)(v7 + 48));
        ++*((_DWORD *)v75 + 23);
        v77 = (float *)(*(_DWORD *)(*(_DWORD *)(v7 + 4) + 12392) + 460);
        *(float *)&_X._M_impl._M_finish = 2.2;
        v78 = *v77;
        render_stage_index = *(float *)&v77;
        *(float *)&_X._M_impl._M_start = v78;
        arg.x = powf(*(float *)&_X._M_impl._M_start, 2.2);
        arg.y = powf(*(float *)(LODWORD(render_stage_index) + 4), 2.2);
        arg.z = powf(*(float *)(LODWORD(render_stage_index) + 8), 2.2);
        vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
          *(const vostok::render::shader_constant_host **)(v7 + 840),
          v76,
          &arg);
        ++*((_DWORD *)v75 + 23);
        v79 = *(float *)(*(_DWORD *)(v7 + 44) + v70 + 192) / (double)*(unsigned int *)(v7 + 60);
        _X._M_impl._M_finish = (vostok::math::float4x4 *)&render_stage_index;
        v80 = *(const vostok::render::shader_constant_host **)(v7 + 820);
        render_stage_index = v79;
        vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
          v80,
          v76,
          (const vostok::math::float3 *)&render_stage_index);
        ++*((_DWORD *)v75 + 23);
        v81 = *(const vostok::render::shader_constant_host **)(v7 + 856);
        render_stage_index = (float)*(unsigned int *)(v7 + 60);
        vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
          v81,
          v76,
          (const vostok::math::float3 *)&render_stage_index);
        ++*((_DWORD *)v75 + 23);
        vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
          *(const vostok::render::shader_constant_host **)(v7 + 816),
          v76,
          (const vostok::math::float3 *)(*(_DWORD *)(v7 + 44) + v70 + 228));
        ++*((_DWORD *)v75 + 23);
        blend_alpha.x = *(float *)(*(_DWORD *)(v7 + 4) + 11240) + blend_alpha.x;
        vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
          *(const vostok::render::shader_constant_host **)(v7 + 732),
          v76,
          &blend_alpha);
        ++*((_DWORD *)v75 + 23);
        v82 = (double)*(unsigned int *)(v7 + 60);
        v83 = 476 * (stage_index - (stage_index != 0)) + *(_DWORD *)(v7 + 44);
        v84 = *(_QWORD *)(v83 + 228);
        v85 = *(float *)(v83 + 192) / v82;
        v86 = *(float *)(v83 + 236);
        _X._M_impl._M_finish = (vostok::math::float4x4 *)&render_stage_index;
        v87 = *(const vostok::render::shader_constant_host **)(v7 + 844);
        *(_QWORD *)&smaller_cascade_grid_origin.x = v84;
        smaller_cascade_grid_origin.z = v86;
        render_stage_index = v85;
        smaller_cascade_grid_size = v82;
        vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
          v87,
          v76,
          (const vostok::math::float3 *)&render_stage_index);
        ++*((_DWORD *)v75 + 23);
        vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
          *(const vostok::render::shader_constant_host **)(v7 + 848),
          v76,
          (const vostok::math::float3 *)&smaller_cascade_grid_size);
        ++*((_DWORD *)v75 + 23);
        vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
          *(const vostok::render::shader_constant_host **)(v7 + 852),
          v76,
          &smaller_cascade_grid_origin);
        v88 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start;
        ++*((_DWORD *)v75 + 23);
        vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
          *(const vostok::render::shader_constant_host **)(v7 + 828),
          v76,
          (const vostok::math::float3 *)(v88 + 5));
        ++*((_DWORD *)v75 + 23);
        vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
          *(const vostok::render::shader_constant_host **)(v7 + 860),
          v76,
          (const vostok::math::float3 *)(*(_DWORD *)(v7 + 4) + 16772));
        ++*((_DWORD *)v75 + 23);
        vostok::render::stage_light_propagation_volumes::render_quad(
          v89,
          (vostok::render::stage_light_propagation_volumes *)v7);
        v49 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        vostok::render::backend::reset_render_targets(
          v90,
          (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
        v91 = *((_DWORD *)v49 + 547);
        v14 = *((_DWORD *)v49 + 539) == v91;
        *((_DWORD *)v49 + 539) = v91;
        *((_BYTE *)v49 + 167) |= !v14;
      }
      ++propagation_iteration_index;
    }
    while ( !propagation_iteration_index );
    (*(void (__stdcall **)(int, int, D3D11_VIEWPORT *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                      + 176))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      1,
      &orig_viewport);
  }
  v92 = box_occluder_transforms._M_impl._M_start;
  if ( box_occluder_transforms._M_impl._M_start )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, (void *)v92);
  }
}
