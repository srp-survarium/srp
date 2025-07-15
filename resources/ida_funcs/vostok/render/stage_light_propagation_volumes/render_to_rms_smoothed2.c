void __thiscall vostok::render::stage_light_propagation_volumes::render_to_rms_smoothed2(
        vostok::render::stage_light_propagation_volumes *this,
        vostok::render::stage_light_propagation_volumes *light_color,
        const char *light_intensity,
        const vostok::math::float4x4 *view_matrix,
        vostok::render::renderer_context *projection_matrix,
        vostok::render::vector<vostok::math::float4x4> transforms,
        const unsigned int cascade_index,
        unsigned int render_stage_index,
        unsigned int num_render_stages,
        unsigned int num_render_stagesa)
{
  int y; // eax
  double m_rsm_source_size; // st7
  float v12; // eax
  void *v13; // edi
  vostok::render::renderer_context *v14; // ecx
  vostok::render::renderer_context *v15; // ecx
  float v16; // eax
  void *v17; // edi
  unsigned int v18; // esi
  const char *m_conflicted_key_name; // ebp
  vostok::render::backend *v20; // ecx
  vostok::render::backend *v21; // ecx
  unsigned int v22; // edi
  vostok::render::render_target *m_object; // eax
  ID3D11DepthStencilView *m_zrt; // esi
  const char *v25; // eax
  bool v26; // zf
  float v27; // eax
  void **M_start; // esi
  stlp_std::reverse_iterator<survarium::game_world::bullet_tracer *> *v29; // edi
  survarium::bullet *v30; // edx
  vostok::render::render_model_instance_impl *v31; // eax
  vostok::render::render_model_instance_impl *v32; // ecx
  survarium::game_world::bullet_tracer *current; // eax
  unsigned int v34; // edi
  float v35; // esi
  vostok::render::lpv_render_surface **p_M_start; // ebp
  vostok::render::lpv_render_surface *v37; // eax
  vostok::render::lpv_render_surface *v38; // eax
  vostok::render::lpv_render_surface *v39; // esi
  float v40; // esi
  stlp_std::vector<vostok::render::lpv_render_surface,vostok::render::std_allocator<vostok::render::lpv_render_surface> > *v41; // edi
  vostok::render::lpv_render_surface *v42; // eax
  void **v43; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  unsigned int v45; // edi
  vostok::render::render_surface_instance **v46; // edx
  vostok::render::render_target *v47; // ecx
  ID3D11DepthStencilView *v48; // eax
  ID3D11RenderTargetView *m_rt; // ecx
  const char *v50; // esi
  vostok::render::render_target *v51; // ecx
  vostok::math::float4x4 *M_finish; // edi
  vostok::math::float4x4 *M_data; // ebp
  float v54; // eax
  unsigned int v55; // ecx
  float v56; // eax
  int v57; // ecx
  char *v58; // eax
  int v59; // edx
  int v60; // eax
  int v61; // eax
  int v62; // eax
  float v63; // ebp
  unsigned int v64; // eax
  vostok::render::lpv_render_surface *v65; // ecx
  float v66; // edi
  vostok::render::render_surface_instance **p_surface; // edx
  vostok::render::render_surface *m_render_surface; // edi
  vostok::render::material_effects_instance *v69; // eax
  vostok::render::material_effects *p_m_material_effects; // eax
  _DWORD *v71; // eax
  unsigned int v72; // ecx
  float v73; // eax
  const char *v74; // ebp
  int v75; // ecx
  float v76; // eax
  int v77; // ecx
  vostok::render::render_surface_instance *v78; // esi
  vostok::render::res_geometry *v79; // ecx
  vostok::render::statistics *v80; // eax
  unsigned int v81; // ecx
  unsigned int v82; // ecx
  const char *v83; // edi
  unsigned int v84; // ebp
  bool v85; // al
  const char *v86; // esi
  unsigned int v87; // kr00_4
  vostok::render::statistics *v88; // eax
  vostok::render::lpv_render_surface *v89; // edx
  vostok::render::lpv_render_surface *v90; // esi
  int v91; // eax
  survarium::game *m_game; // edx
  float v93; // esi
  float v94; // esi
  vostok::render::renderer_context *v95; // ecx
  vostok::math::float4x4 *v96; // eax
  vostok::render::grass_render_model *v97; // ecx
  const stlp_std::__false_type *v98; // [esp+48h] [ebp-128h]
  unsigned int v99; // [esp+4Ch] [ebp-124h]
  bool v100; // [esp+50h] [ebp-120h]
  vostok::render::render_surface_instance **end; // [esp+58h] [ebp-118h] BYREF
  vostok::render::render_surface *v102; // [esp+5Ch] [ebp-114h]
  unsigned int render_index; // [esp+60h] [ebp-110h]
  vostok::render::lpv_render_surface surface; // [esp+64h] [ebp-10Ch] BYREF
  vostok::render::vector<vostok::render::render_surface_instance *> caster_models; // [esp+6Ch] [ebp-104h] BYREF
  vostok::render::lpv_render_surface *begin_d; // [esp+78h] [ebp-F8h]
  vostok::render::render_surface_instance *instance; // [esp+7Ch] [ebp-F4h]
  unsigned int num_render; // [esp+80h] [ebp-F0h]
  float v109; // [esp+84h] [ebp-ECh]
  D3D11_VIEWPORT tmp_viewport; // [esp+88h] [ebp-E8h] BYREF
  D3D11_VIEWPORT orig_viewport; // [esp+A0h] [ebp-D0h] BYREF
  vostok::math::float4x4 real_view_projection; // [esp+B8h] [ebp-B8h] BYREF
  vostok::math::frustum prev_cascade_frustum; // [esp+F8h] [ebp-78h] BYREF

  if ( s_draw_to_rsm_value )
  {
    y = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y;
    end = (vostok::render::render_surface_instance **)1;
    (*(void (__stdcall **)(int, vostok::render::render_surface_instance ***, D3D11_VIEWPORT *))(*(_DWORD *)y + 380))(
      y,
      &end,
      &orig_viewport);
    m_rsm_source_size = (double)light_color->m_rsm_source_size;
    tmp_viewport.TopLeftX = 0.0;
    tmp_viewport.TopLeftY = 0.0;
    tmp_viewport.Width = m_rsm_source_size;
    tmp_viewport.MinDepth = 0.0;
    tmp_viewport.Height = m_rsm_source_size;
    LODWORD(tmp_viewport.MaxDepth) = clear_value;
    (*(void (__stdcall **)(int, int, D3D11_VIEWPORT *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                      + 176))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      1,
      &tmp_viewport);
    qmemcpy((void *)&real_view_projection, &light_color->m_context->m_vp, sizeof(real_view_projection));
    vostok::math::frustum::frustum(&prev_cascade_frustum, &real_view_projection);
    v12 = *(float *)&light_color->m_context;
    v13 = *(void **)(LODWORD(v12) + 13432);
    if ( v13 )
      qmemcpy(v13, (const void *)(LODWORD(v12) + 15620), 0x40u);
    v14 = projection_matrix;
    *(_DWORD *)(LODWORD(v12) + 13432) += 64;
    vostok::render::renderer_context::set_v(v14, (const vostok::math::float4x4 *)LODWORD(v12));
    v16 = *(float *)&light_color->m_context;
    v17 = *(void **)(LODWORD(v16) + 14464);
    if ( v17 )
    {
      qmemcpy(v17, (const void *)(LODWORD(v16) + 15940), 0x40u);
      v15 = 0;
    }
    *(_DWORD *)(LODWORD(v16) + 14464) += 64;
    vostok::render::renderer_context::set_p(v15, (const vostok::math::float4x4 *)LODWORD(v16));
    if ( !num_render_stages )
    {
      v18 = render_stage_index;
      (*(void (__stdcall **)(int, ID3D11Resource *, ID3D11Resource *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                     + 188))(
        `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
        light_color->m_radiance_volume[render_stage_index].m_t_rms_albedo_source.m_object->m_surface,
        light_color->m_radiance_volume[render_stage_index].m_t_rms_albedo_source_temp.m_object->m_surface);
      (*(void (__stdcall **)(int, ID3D11Resource *, ID3D11Resource *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                     + 188))(
        `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
        light_color->m_radiance_volume[v18].m_t_rms_normal_source.m_object->m_surface,
        light_color->m_radiance_volume[v18].m_t_rms_normal_source_temp.m_object->m_surface);
      (*(void (__stdcall **)(int, ID3D11Resource *, ID3D11Resource *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                     + 188))(
        `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
        light_color->m_radiance_volume[v18].m_t_rms_position_source.m_object->m_surface,
        light_color->m_radiance_volume[v18].m_t_rms_position_source_temp.m_object->m_surface);
      m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      vostok::render::backend::set_render_targets(
        (ID3D11RenderTargetView *)light_color->m_radiance_volume[v18].m_rt_rms_albedo_source_temp.m_object,
        light_color->m_radiance_volume[v18].m_rt_rms_normal_source_temp.m_object,
        light_color->m_radiance_volume[v18].m_rt_rms_position_source_temp.m_object,
        0,
        (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
      vostok::render::backend::clear_render_targets(v20, (int)m_conflicted_key_name, 0.0, 0.0, 0.0, 0.0, *(float *)&v98);
      v22 = render_stage_index;
      m_object = light_color->m_rms_depth_stencil_source[render_stage_index].m_object;
      if ( m_object )
        m_zrt = m_object->m_zrt;
      else
        m_zrt = 0;
      v25 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      v26 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 539) == (_DWORD)m_zrt;
      *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 539) = m_zrt;
      LOBYTE(v21) = !v26;
      *((_BYTE *)v25 + 167) |= !v26;
      vostok::render::backend::clear_depth_stencil(v21, (int)v25);
      v27 = *(float *)&light_color->m_context;
      memset(&caster_models, 0, sizeof(caster_models));
      vostok::render::scene::select_models(
        *(vostok::render::scene **)(LODWORD(v27) + 12388),
        (const vostok::math::float4x4 *)(LODWORD(v27) + 16260),
        &caster_models,
        (const vostok::math::float3 *)(LODWORD(v27) + 16900),
        1u,
        0);
      M_start = caster_models._M_impl._M_start;
      if ( (((char *)caster_models._M_impl._M_finish - (char *)caster_models._M_impl._M_start) & 0xFFFFFFFC) != 0 )
      {
        end = (vostok::render::render_surface_instance **)caster_models._M_impl._M_finish;
        if ( caster_models._M_impl._M_start != caster_models._M_impl._M_finish )
        {
          v29 = (stlp_std::reverse_iterator<survarium::game_world::bullet_tracer *> *)&light_color->m_caster_models[v22];
          do
          {
            v30 = (survarium::bullet *)*M_start;
            v31 = (vostok::render::render_model_instance_impl *)*((_DWORD *)*M_start + 2);
            v32 = 0;
            surface.surface = (vostok::render::render_surface_instance *)*M_start;
            if ( v31 )
            {
              v32 = v31;
              _InterlockedExchangeAdd(&v31->m_reference_count, 1u);
            }
            current = v29[1].current;
            surface.model.m_object = v32;
            if ( current == v29[2].current )
            {
              stlp_std::priv::_Impl_vector<vostok::render::lpv_render_surface,vostok::render::std_allocator<vostok::render::lpv_render_surface>>::_M_insert_overflow_aux(
                (stlp_std::priv::_Impl_vector<vostok::render::lpv_render_surface,vostok::render::std_allocator<vostok::render::lpv_render_surface> > *)&surface,
                v29,
                current,
                &surface,
                v98,
                v99,
                v100);
              v32 = surface.model.m_object;
            }
            else
            {
              if ( current )
              {
                current->bullet = v30;
                current->tracer.m_object = 0;
                if ( v32 )
                {
                  current->tracer.m_object = (vostok::render::tracer_model_instance *)v32;
                  _InterlockedExchangeAdd(&v32->m_reference_count, 1u);
                }
              }
              ++v29[1].current;
            }
            if ( v32 && !_InterlockedExchangeAdd(&v32->m_reference_count, 0xFFFFFFFF) )
              vostok::resources::unmanaged_intrusive_base::destroy(
                &v32->vostok::resources::unmanaged_intrusive_base,
                v32);
            ++M_start;
          }
          while ( M_start != (void **)end );
        }
      }
      v34 = render_stage_index;
      if ( s_lpv_dips_skipping0_value )
      {
        v35 = *(float *)&light_color->m_caster_models[render_stage_index]._M_impl._M_finish;
        p_M_start = &light_color->m_caster_models[render_stage_index]._M_impl._M_start;
        v37 = stlp_std::priv::__find_if<vostok::render::lpv_render_surface *,vostok::render::remove_lpv_inappropriate_models>(
                *p_M_start,
                (vostok::render::lpv_render_surface *)LODWORD(v35));
        if ( v37 != (vostok::render::lpv_render_surface *)LODWORD(v35) )
        {
          v38 = stlp_std::remove_copy_if<vostok::render::lpv_render_surface *,vostok::render::lpv_render_surface *,vostok::render::remove_lpv_inappropriate_models>(
                  v37 + 1,
                  v37,
                  (vostok::render::lpv_render_surface *)LODWORD(v35));
          if ( v38 != (vostok::render::lpv_render_surface *)LODWORD(v35) )
          {
            v39 = stlp_std::priv::__copy<vostok::render::lpv_render_surface *,vostok::render::lpv_render_surface *,int>(
                    p_M_start[1],
                    v38,
                    (vostok::render::lpv_render_surface *)LODWORD(v35));
            stlp_std::__destroy_range_aux<vostok::render::lpv_render_surface *,vostok::render::lpv_render_surface>(
              v39,
              p_M_start[1]);
            v34 = render_stage_index;
            p_M_start[1] = v39;
          }
        }
      }
      if ( v34 && s_lpv_dips_skipping1_value )
      {
        vostok::math::mul4x3(
          &real_view_projection,
          (const vostok::math::float4x4 *)&light_color->m_enabled + v34,
          &light_color->m_previous_view_matrix[v34 + 3]);
        vostok::math::frustum::frustum(&prev_cascade_frustum, &real_view_projection);
        v40 = *(float *)&light_color->m_caster_models[v34]._M_impl._M_finish;
        v41 = &light_color->m_caster_models[v34];
        v42 = stlp_std::priv::__find_if<vostok::render::lpv_render_surface *,vostok::render::remove_model_if_in_frustum_predicate>(
                v41->_M_impl._M_start,
                (vostok::render::lpv_render_surface *)LODWORD(v40),
                (vostok::render::remove_model_if_in_frustum_predicate)&prev_cascade_frustum);
        if ( v42 != (vostok::render::lpv_render_surface *)LODWORD(v40) )
          v42 = stlp_std::remove_copy_if<vostok::render::lpv_render_surface *,vostok::render::lpv_render_surface *,vostok::render::remove_model_if_in_frustum_predicate>(
                  v42 + 1,
                  v42,
                  (vostok::render::lpv_render_surface *)LODWORD(v40));
        stlp_std::vector<vostok::render::lpv_render_surface,vostok::render::std_allocator<vostok::render::lpv_render_surface>>::erase(
          (vostok::render::lpv_render_surface *)LODWORD(v40),
          v41,
          v42);
      }
      v43 = caster_models._M_impl._M_start;
      if ( caster_models._M_impl._M_start )
      {
        m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
        BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
        vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v43);
      }
    }
    v45 = render_stage_index;
    v46 = (vostok::render::render_surface_instance **)(476 * render_stage_index);
    v47 = light_color->m_radiance_volume[render_stage_index].m_rt_rms_position_source_temp.m_object;
    v48 = 0;
    end = (vostok::render::render_surface_instance **)(476 * render_stage_index);
    if ( v47 )
      m_rt = v47->m_rt;
    else
      m_rt = 0;
    v50 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    if ( *((ID3D11RenderTargetView **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
         + 535) != m_rt )
    {
      *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) = m_rt;
      *((_BYTE *)v50 + 163) = 1;
    }
    if ( *((_DWORD *)v50 + 536) )
    {
      *((_DWORD *)v50 + 536) = 0;
      *((_BYTE *)v50 + 164) = 1;
    }
    if ( *((_DWORD *)v50 + 537) )
    {
      *((_DWORD *)v50 + 537) = 0;
      *((_BYTE *)v50 + 165) = 1;
    }
    if ( *((_DWORD *)v50 + 538) )
    {
      *((_DWORD *)v50 + 538) = 0;
      *((_BYTE *)v50 + 166) = 1;
    }
    v51 = light_color->m_rms_depth_stencil_source[v45].m_object;
    if ( v51 )
      v48 = v51->m_zrt;
    v26 = *((_DWORD *)v50 + 539) == (_DWORD)v48;
    *((_DWORD *)v50 + 539) = v48;
    *((_BYTE *)v50 + 167) |= !v26;
    M_finish = transforms._M_impl._M_finish;
    M_data = transforms._M_impl._M_end_of_storage._M_data;
    if ( transforms._M_impl._M_finish != transforms._M_impl._M_end_of_storage._M_data )
    {
      do
      {
        vostok::render::renderer_context::set_w(light_color->m_context, M_finish);
        v54 = *(float *)&light_color->m_fill_rsm_effect[0].m_object;
        v55 = (*(_DWORD *)(LODWORD(v54) + 284) - *(_DWORD *)(LODWORD(v54) + 280)) >> 2;
        if ( v55 > 1 )
        {
          *(_DWORD *)(LODWORD(v54) + 276) = 1;
          vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v55, (unsigned int)v98);
        }
        vostok::render::box_geometry::draw((vostok::render::box_geometry *)v55);
        ++M_finish;
      }
      while ( M_finish != M_data );
      v50 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      v46 = end;
    }
    v56 = *(float *)&light_color->m_radiance_volume;
    v57 = *(int *)((char *)v46 + LODWORD(v56) + 32);
    v58 = (char *)v46 + LODWORD(v56);
    v59 = *((_DWORD *)v58 + 10);
    v60 = *((_DWORD *)v58 + 6);
    if ( v60 )
      v60 = *(_DWORD *)(v60 + 16);
    if ( *((_DWORD *)v50 + 535) != v60 )
    {
      *((_DWORD *)v50 + 535) = v60;
      *((_BYTE *)v50 + 163) = 1;
    }
    if ( v57 )
      v61 = *(_DWORD *)(v57 + 16);
    else
      v61 = 0;
    if ( *((_DWORD *)v50 + 536) != v61 )
    {
      *((_DWORD *)v50 + 536) = v61;
      *((_BYTE *)v50 + 164) = 1;
    }
    if ( v59 )
      v62 = *(_DWORD *)(v59 + 16);
    else
      v62 = 0;
    if ( *((_DWORD *)v50 + 537) != v62 )
    {
      *((_DWORD *)v50 + 537) = v62;
      *((_BYTE *)v50 + 165) = 1;
    }
    if ( *((_DWORD *)v50 + 538) )
    {
      *((_DWORD *)v50 + 538) = 0;
      *((_BYTE *)v50 + 166) = 1;
    }
    LODWORD(v63) = &light_color->m_caster_models[render_stage_index];
    v64 = ((*(_DWORD *)(LODWORD(v63) + 4) - *(_DWORD *)LODWORD(v63)) >> 3) / (num_render_stagesa - num_render_stages);
    v65 = *(vostok::render::lpv_render_surface **)LODWORD(v63);
    v66 = *(float *)&light_color->m_caster_models[render_stage_index]._M_impl._M_finish;
    p_surface = &v65->surface;
    render_index = 0;
    v109 = v63;
    begin_d = v65;
    end = &v65->surface;
    *(float *)&surface.surface = v66;
    num_render = v64;
    if ( v65 != (vostok::render::lpv_render_surface *)LODWORD(v66) )
    {
      while ( 1 )
      {
        if ( render_index >= v64 )
        {
          v89 = &v65[v64];
          if ( v65 != v89 )
          {
            v90 = stlp_std::priv::__copy<vostok::render::lpv_render_surface *,vostok::render::lpv_render_surface *,int>(
                    *(vostok::render::lpv_render_surface **)(LODWORD(v63) + 4),
                    v65,
                    v89);
            stlp_std::__destroy_range_aux<vostok::render::lpv_render_surface *,vostok::render::lpv_render_surface>(
              v90,
              *(vostok::render::lpv_render_surface **)(LODWORD(v63) + 4));
            *(_DWORD *)(LODWORD(v63) + 4) = v90;
            v50 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
          }
          goto LABEL_113;
        }
        m_render_surface = (*p_surface)->m_render_surface;
        instance = *p_surface;
        v69 = m_render_surface->m_materail_effects_instance.m_object;
        v102 = m_render_surface;
        if ( !v69 || s_use_one_material_value )
          p_m_material_effects = s_nomaterial_material_effects[m_render_surface->m_vertex_input_type];
        else
          p_m_material_effects = &v69->m_material_effects;
        if ( m_render_surface->m_vertex_input_type == static_mesh_vertex_input_type )
        {
          v71 = &p_m_material_effects->m_effects[0].m_object->__vftable;
          if ( v71 )
          {
            if ( m_render_surface->m_render_geometry.lpv_pass_geom.m_object || v102->m_render_geometry.geom.m_object )
              break;
          }
        }
LABEL_109:
        ++render_index;
        p_surface += 2;
        end = p_surface;
        if ( p_surface == (vostok::render::render_surface_instance **)surface.surface )
          goto LABEL_113;
        v64 = num_render;
      }
      v72 = (unsigned int)v102->m_render_geometry.lpv_pass_geom.m_object;
      if ( v72 )
      {
        if ( (unsigned int)((v71[71] - v71[70]) >> 2) <= 2 )
          goto LABEL_88;
        v71[69] = 2;
      }
      else
      {
        v72 = (v71[71] - v71[70]) >> 2;
        if ( v72 <= 4 )
          goto LABEL_88;
        v71[69] = 4;
      }
      vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v72, (unsigned int)v98);
      v50 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
LABEL_88:
      v73 = *(float *)&light_color->m_c_light_color;
      v74 = v50;
      if ( *(_DWORD *)(LODWORD(v73) + 40) == *((_DWORD *)v50 + 573) )
      {
        v75 = *(unsigned __int16 *)(LODWORD(v73) + 20);
        if ( v75 != 0xFFFF )
        {
          vostok::render::shader_constant_buffer::set_memory(
            *(unsigned __int16 *)(LODWORD(v73) + 22),
            (unsigned __int8)*(_WORD *)(LODWORD(v73) + 16),
            *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v50 + 371) + 16) + 4 * v75),
            light_intensity);
          v50 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        }
      }
      ++*((_DWORD *)v74 + 23);
      v76 = *(float *)&light_color->m_c_light_intensity;
      if ( *(_DWORD *)(LODWORD(v76) + 40) == *((_DWORD *)v50 + 573) )
      {
        v77 = *(unsigned __int16 *)(LODWORD(v76) + 20);
        if ( v77 != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            *(unsigned __int16 *)(LODWORD(v76) + 22),
            (unsigned __int8)*(_WORD *)(LODWORD(v76) + 16),
            *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v50 + 371) + 16) + 4 * v77),
            (const char *)&view_matrix);
      }
      ++*((_DWORD *)v50 + 23);
      v78 = instance;
      vostok::render::renderer_context::set_w(light_color->m_context, instance->m_transform);
      v78->m_parent->set_constants(v78->m_parent);
      v79 = v102->m_render_geometry.lpv_pass_geom.m_object;
      if ( !v79 )
        v79 = v102->m_render_geometry.geom.m_object;
      vostok::render::res_geometry::apply(v79);
      v80 = vostok::quasi_singleton<vostok::render::statistics>::pinst;
      v81 = render_stage_index;
      ++vostok::quasi_singleton<vostok::render::statistics>::pinst->lpv_stat_group.num_dips.value;
      if ( v81 )
      {
        v82 = v81 - 1;
        if ( v82 )
        {
          if ( v82 == 1 )
            ++v80->lpv_stat_group.num_dips_in_cascade_2.value;
        }
        else
        {
          ++v80->lpv_stat_group.num_dips_in_cascade_1.value;
        }
      }
      else
      {
        ++v80->lpv_stat_group.num_dips_in_cascade_0.value;
      }
      v83 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      v84 = 3 * v102->m_render_geometry.primitive_count;
      v85 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 529) != 4;
      v86 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 162) = v85;
      if ( v85 )
        *((_DWORD *)v83 + 529) = 4;
      vostok::render::backend::flush((vostok::render::backend *)4, (int)v83);
      if ( v86[104] )
      {
        ++*((_DWORD *)v86 + 25);
        v84 += 3 * s_max_triagles_per_dip_value < v84 ? 3 * s_max_triagles_per_dip_value - v84 : 0;
      }
      if ( !v86[37] )
        (*(void (__stdcall **)(int, unsigned int, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                 + 48))(
          `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
          v84,
          0,
          0);
      v65 = begin_d;
      v87 = v84;
      v88 = vostok::quasi_singleton<vostok::render::statistics>::pinst;
      v63 = v109;
      *((_DWORD *)v86 + 21) += v87 / 3;
      ++v88->debug_stat_group.num_dips_in_lpv.value;
      v50 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      p_surface = end;
      goto LABEL_109;
    }
LABEL_113:
    vostok::render::backend::reset_render_targets((vostok::render::backend *)v65, (int)v50);
    v91 = *((_DWORD *)v50 + 547);
    m_game = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game;
    *((_BYTE *)v50 + 167) |= *((_DWORD *)v50 + 539) != v91;
    *((_DWORD *)v50 + 539) = v91;
    (*(void (__stdcall **)(int, int, D3D11_VIEWPORT *))(*(_DWORD *)m_game->m_game_world.m_mouse_pos.y + 176))(
      m_game->m_game_world.m_mouse_pos.y,
      1,
      &orig_viewport);
    v93 = *(float *)&light_color->m_context;
    vostok::render::renderer_context::set_v(
      (vostok::render::renderer_context *)(*(_DWORD *)(LODWORD(v93) + 13432) - 64),
      (const vostok::math::float4x4 *)LODWORD(v93));
    *(_DWORD *)(LODWORD(v93) + 13432) -= 64;
    v94 = *(float *)&light_color->m_context;
    vostok::render::renderer_context::set_p(v95, (const vostok::math::float4x4 *)LODWORD(v94));
    *(_DWORD *)(LODWORD(v94) + 14464) -= 64;
  }
  v96 = transforms._M_impl._M_finish;
  if ( transforms._M_impl._M_finish )
  {
    v97 = vostok::render::g_allocator.m_object;
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free((void *)HIDWORD(v97->m_reconstruction_info_actuality_tick), (void *)v96);
  }
}
