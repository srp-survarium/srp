void __userpurge vostok::render::stage_lights::render_to_hw_shadowmap(
        unsigned int smap_size@<eax>,
        vostok::render::backend *a2@<ecx>,
        vostok::render::stage_lights *this,
        vostok::render::light *l,
        float shadow_quality,
        float z_bias,
        const vostok::math::float4x4 *smap_size_index,
        vostok::render::renderer_context *view_matrix,
        const vostok::math::float4x4 *projection_matrix,
        unsigned int marge)
{
  vostok::render::stage_lights *v10; // ebx
  int y; // eax
  const char *m_conflicted_key_name; // eax
  vostok::render::render_target *m_object; // ecx
  ID3D11DepthStencilView *m_zrt; // esi
  bool v16; // zf
  vostok::render::render_target *v17; // ecx
  ID3D11DepthStencilView *v18; // esi
  vostok::render::renderer_context *m_context; // eax
  vostok::math::float4x4 *m_end; // edi
  vostok::render::renderer_context *z_low; // ecx
  vostok::render::renderer_context *v22; // eax
  vostok::math::float4x4 *v23; // edi
  vostok::render::renderer_context *v24; // eax
  vostok::render::render_target *v25; // eax
  ID3D11DepthStencilView *v26; // eax
  const char *v27; // esi
  vostok::render::render_surface_instance **M_start; // ecx
  vostok::render::render_surface_instance *v29; // edi
  vostok::render::render_surface *m_render_surface; // esi
  vostok::render::material_effects_instance *v31; // eax
  vostok::render::material_effects *p_m_material_effects; // eax
  vostok::render::res_effect *v33; // eax
  vostok::render::backend *v34; // ecx
  const char *v35; // edi
  unsigned int v36; // ebp
  bool v37; // al
  const char *v38; // esi
  vostok::render::renderer_context *v39; // eax
  vostok::render::speedtree_forest *m_speedtree_forest; // ecx
  vostok::render::speedtree_forest::tree_render_info *v41; // esi
  vostok::render::speedtree_tree_component **p_tree_component; // esi
  vostok::render::material_effects_instance *v43; // eax
  vostok::render::material_effects *v44; // eax
  vostok::render::material_effects_instance *v45; // eax
  vostok::render::material_effects *v46; // eax
  vostok::render::material_effects_instance *v47; // eax
  vostok::render::material_effects *v48; // eax
  vostok::render::material_effects_instance *v49; // eax
  vostok::render::material_effects *v50; // eax
  _DWORD *v51; // eax
  int v52; // ecx
  vostok::render::speedtree_wind_parameters *p_m_speedtree_wind_parameters; // edi
  const SpeedTree::CWind *Wind; // eax
  vostok::render::speedtree_forest *v55; // ecx
  vostok::render::renderer_context *v56; // edi
  vostok::math::float4x4 *instance_transform; // eax
  const vostok::math::float4x4 *v58; // eax
  int v59; // eax
  vostok::render::speedtree_tree_component *v60; // ecx
  vostok::render::backend *v61; // ecx
  const char *v62; // edi
  const char *v63; // ebp
  vostok::render::render_surface_instance **v64; // edi
  const char *v65; // edi
  int v66; // eax
  vostok::render::render_surface_instance **v67; // ecx
  unsigned int v68; // ebx
  const char *v69; // ebp
  vostok::render::statistics *v70; // ecx
  unsigned int v71; // kr00_4
  vostok::render::grass_render_model *v72; // ecx
  vostok::render::renderer_context *v73; // ebp
  vostok::render::renderer_context *v74; // esi
  vostok::render::renderer_context *v75; // ecx
  survarium::game *m_game; // eax
  float v77; // xmm0_4
  void **v78; // eax
  vostok::render::grass_render_model *v79; // ecx
  vostok::render::vector<vostok::render::speedtree_forest::tree_render_info> *v80; // [esp+40h] [ebp-B4h]
  const SpeedTree::CInstance *v81; // [esp+40h] [ebp-B4h]
  vostok::render::render_surface_instance **it_d; // [esp+50h] [ebp-A4h] BYREF
  vostok::render::render_surface_instance *const *end_d; // [esp+54h] [ebp-A0h]
  vostok::render::vector<vostok::render::render_surface_instance *> m_dynamic_visuals_to_shadow; // [esp+58h] [ebp-9Ch] BYREF
  float v85; // [esp+64h] [ebp-90h]
  vostok::render::vector<vostok::render::speedtree_forest::tree_render_info> visible_trees; // [esp+68h] [ebp-8Ch] BYREF
  vostok::math::float3 view_position; // [esp+74h] [ebp-80h] BYREF
  D3D11_VIEWPORT tmp_viewport; // [esp+80h] [ebp-74h] BYREF
  D3D11_VIEWPORT orig_viewport; // [esp+98h] [ebp-5Ch] BYREF
  vostok::math::float4x4 shadow_transform; // [esp+B0h] [ebp-44h] BYREF

  v10 = this;
  vostok::render::backend::flush_rt_shader_resources(
    a2,
    (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
  y = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y;
  it_d = (vostok::render::render_surface_instance **)1;
  (*(void (__stdcall **)(int, vostok::render::render_surface_instance ***, D3D11_VIEWPORT *))(*(_DWORD *)y + 380))(
    y,
    &it_d,
    &orig_viewport);
  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  if ( *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) )
  {
    *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) = 0;
    *((_BYTE *)m_conflicted_key_name + 163) = 1;
  }
  if ( *((_DWORD *)m_conflicted_key_name + 536) )
  {
    *((_DWORD *)m_conflicted_key_name + 536) = 0;
    *((_BYTE *)m_conflicted_key_name + 164) = 1;
  }
  if ( *((_DWORD *)m_conflicted_key_name + 537) )
  {
    *((_DWORD *)m_conflicted_key_name + 537) = 0;
    *((_BYTE *)m_conflicted_key_name + 165) = 1;
  }
  if ( *((_DWORD *)m_conflicted_key_name + 538) )
  {
    *((_DWORD *)m_conflicted_key_name + 538) = 0;
    *((_BYTE *)m_conflicted_key_name + 166) = 1;
  }
  if ( l->static_shadows )
  {
    m_object = l->m_shadow_depth_stencil.m_object;
    if ( m_object )
      m_zrt = m_object->m_zrt;
    else
      m_zrt = 0;
    v16 = *((_DWORD *)m_conflicted_key_name + 539) == (_DWORD)m_zrt;
    *((_DWORD *)m_conflicted_key_name + 539) = m_zrt;
    *((_BYTE *)m_conflicted_key_name + 167) |= !v16;
    smap_size = 256;
  }
  else
  {
    v17 = this->m_shadow_depth_stencil[LODWORD(z_bias)].m_object;
    if ( v17 )
      v18 = v17->m_zrt;
    else
      v18 = 0;
    v16 = *((_DWORD *)m_conflicted_key_name + 539) == (_DWORD)v18;
    *((_DWORD *)m_conflicted_key_name + 539) = v18;
    *((_BYTE *)m_conflicted_key_name + 167) |= !v16;
    if ( s_debug_enabled_ds_clearing_value && v18 )
      (*(void (__stdcall **)(int, ID3D11DepthStencilView *, int, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                                + 212))(
        `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
        v18,
        3,
        1.0,
        0);
  }
  end_d = (vostok::render::render_surface_instance *const *)smap_size;
  tmp_viewport.TopLeftX = 0.0;
  tmp_viewport.TopLeftY = 0.0;
  v85 = (float)smap_size;
  tmp_viewport.MinDepth = 0.0;
  tmp_viewport.Width = v85;
  tmp_viewport.Height = v85;
  LODWORD(tmp_viewport.MaxDepth) = clear_value;
  (*(void (__stdcall **)(int, int, D3D11_VIEWPORT *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                    + 176))(
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
    1,
    &tmp_viewport);
  m_context = this->m_context;
  m_end = m_context->m_v_stack.m_end;
  z_low = (vostok::render::renderer_context *)LODWORD(m_context->m_v_inverted.c.z);
  *(_QWORD *)&view_position.x = *(_QWORD *)&m_context->m_v_inverted.lines[3].x;
  LODWORD(view_position.z) = z_low;
  if ( m_end )
  {
    qmemcpy((void *)m_end, &m_context->m_v, sizeof(vostok::math::float4x4));
    z_low = 0;
  }
  ++m_context->m_v_stack.m_end;
  vostok::render::renderer_context::set_v(z_low, (const vostok::math::float4x4 *)m_context);
  v22 = this->m_context;
  v23 = v22->m_p_stack.m_end;
  if ( v23 )
    qmemcpy((void *)v23, &v22->m_p, sizeof(vostok::math::float4x4));
  ++v22->m_p_stack.m_end;
  vostok::render::renderer_context::set_p(view_matrix, (const vostok::math::float4x4 *)v22);
  v16 = !l->static_shadows;
  v24 = this->m_context;
  memset(&m_dynamic_visuals_to_shadow, 0, sizeof(m_dynamic_visuals_to_shadow));
  if ( v16 )
    vostok::render::scene::select_models(
      v24->m_scene,
      &v24->m_vp,
      &m_dynamic_visuals_to_shadow,
      (const vostok::math::float3 *)&v24->m_view_pos,
      1u,
      0);
  else
    vostok::render::scene::select_models(
      v24->m_scene,
      &v24->m_vp,
      &m_dynamic_visuals_to_shadow,
      (const vostok::math::float3 *)&v24->m_view_pos,
      1u,
      1);
  if ( l->static_shadows )
  {
    if ( (((char *)m_dynamic_visuals_to_shadow._M_impl._M_finish - (char *)m_dynamic_visuals_to_shadow._M_impl._M_start)
        & 0xFFFFFFFC) == 0
      && !l->need_refresh_static_shadows )
    {
      goto LABEL_103;
    }
    vostok::render::scene::select_models(
      this->m_context->m_scene,
      &this->m_context->m_vp,
      &m_dynamic_visuals_to_shadow,
      (const vostok::math::float3 *)&this->m_context->m_view_pos,
      1u,
      0);
    v25 = l->m_shadow_depth_stencil.m_object;
    if ( v25 )
      v26 = v25->m_zrt;
    else
      v26 = 0;
    v27 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    v16 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 539) == (_DWORD)v26;
    *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 539) = v26;
    *((_BYTE *)v27 + 167) |= !v16;
    if ( s_debug_enabled_ds_clearing_value && v26 )
      (*(void (__stdcall **)(int, ID3D11DepthStencilView *, int, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                                + 212))(
        `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
        v26,
        3,
        1.0,
        0);
    if ( l->need_refresh_static_shadows )
      l->need_refresh_static_shadows = 0;
  }
  M_start = (vostok::render::render_surface_instance **)m_dynamic_visuals_to_shadow._M_impl._M_start;
  it_d = (vostok::render::render_surface_instance **)m_dynamic_visuals_to_shadow._M_impl._M_start;
  for ( end_d = (vostok::render::render_surface_instance *const *)m_dynamic_visuals_to_shadow._M_impl._M_finish;
        M_start != end_d;
        it_d = M_start )
  {
    v29 = *M_start;
    m_render_surface = (*M_start)->m_render_surface;
    v31 = m_render_surface->m_materail_effects_instance.m_object;
    if ( !v31 || s_use_one_material_value )
      p_m_material_effects = s_nomaterial_material_effects[m_render_surface->m_vertex_input_type];
    else
      p_m_material_effects = &v31->m_material_effects;
    if ( p_m_material_effects->is_cast_shadow
      && m_render_surface->m_render_geometry.geom.m_object
      && p_m_material_effects->m_effects[0].m_object
      && (!*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
           + 288)
       || !v29->m_occluded) )
    {
      v33 = p_m_material_effects->m_effects[28].m_object;
      if ( !v33 )
        v33 = this->m_shadow_effect.m_object;
      vostok::render::res_effect::apply(0, v33);
      vostok::render::renderer_context::set_w(this->m_context, v29->m_transform);
      v29->m_parent->set_constants(v29->m_parent);
      vostok::render::res_geometry::apply(m_render_surface->m_render_geometry.geom.m_object);
      v35 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      v36 = 3 * m_render_surface->m_render_geometry.primitive_count;
      v37 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 529) != 4;
      v38 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 162) = v37;
      if ( v37 )
        *((_DWORD *)v35 + 529) = 4;
      vostok::render::backend::flush(v34, (int)v35);
      if ( v38[104] )
      {
        ++*((_DWORD *)v38 + 25);
        v36 += 3 * s_max_triagles_per_dip_value < v36 ? 3 * s_max_triagles_per_dip_value - v36 : 0;
      }
      if ( !v38[37] )
        (*(void (__stdcall **)(int, unsigned int, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                 + 48))(
          `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
          v36,
          0,
          0);
      M_start = it_d;
      *((_DWORD *)v38 + 21) += v36 / 3;
    }
    ++M_start;
  }
  if ( *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
       + 261) )
  {
    v39 = this->m_context;
    m_speedtree_forest = v39->m_scene->m_speedtree_forest;
    if ( m_speedtree_forest )
    {
      memset(&visible_trees, 0, sizeof(visible_trees));
      vostok::render::speedtree_forest::get_visible_tree_components(
        v39,
        &view_position,
        m_speedtree_forest,
        &visible_trees,
        v80);
      v41 = visible_trees._M_impl._M_start;
      if ( visible_trees._M_impl._M_start != visible_trees._M_impl._M_finish )
      {
        p_tree_component = &visible_trees._M_impl._M_start->tree_component;
        do
        {
          v43 = (*p_tree_component)->m_materail_effects_instance.m_object;
          if ( v43 )
            v44 = &v43->m_material_effects;
          else
            v44 = s_nomaterial_material_effects[(*p_tree_component)->get_vertex_input_type(*p_tree_component)];
          if ( v44->stage_enable[28] )
          {
            v45 = (*p_tree_component)->m_materail_effects_instance.m_object;
            v46 = v45
                ? &v45->m_material_effects
                : s_nomaterial_material_effects[(*p_tree_component)->get_vertex_input_type(*p_tree_component)];
            if ( v46->m_effects[28].m_object )
            {
              v47 = (*p_tree_component)->m_materail_effects_instance.m_object;
              v48 = v47
                  ? &v47->m_material_effects
                  : s_nomaterial_material_effects[(*p_tree_component)->get_vertex_input_type(*p_tree_component)];
              if ( v48->is_cast_shadow )
              {
                v49 = (*p_tree_component)->m_materail_effects_instance.m_object;
                if ( v49 )
                  v50 = &v49->m_material_effects;
                else
                  v50 = s_nomaterial_material_effects[(*p_tree_component)->get_vertex_input_type(*p_tree_component)];
                v51 = &v50->m_effects[28].m_object->__vftable;
                v52 = (v51[71] - v51[70]) >> 2;
                if ( v52 )
                {
                  v51[69] = 0;
                  vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v52, (unsigned int)v81);
                }
                p_m_speedtree_wind_parameters = &v10->m_context->m_scene->m_speedtree_forest->m_speedtree_wind_parameters;
                Wind = SpeedTree::CCore::GetWind(&(*p_tree_component)->m_parent->SpeedTree::CCore);
                vostok::render::speedtree_wind_parameters::set(p_m_speedtree_wind_parameters, Wind);
                vostok::render::speedtree_common_parameters::set(
                  &v10->m_context->m_scene->m_speedtree_forest->m_speedtree_common_parameters,
                  v10->m_context,
                  *p_tree_component,
                  &view_position);
                v55 = (vostok::render::speedtree_forest *)*(p_tree_component - 2);
                if ( v55 )
                {
                  v56 = v10->m_context;
                  instance_transform = vostok::render::speedtree_forest::get_instance_transform(
                                         v55,
                                         (int)v56->m_scene->m_speedtree_forest,
                                         &shadow_transform,
                                         v81);
                  vostok::render::renderer_context::set_w(v56, instance_transform);
                }
                else
                {
                  v58 = vostok::math::float4x4::identity(&shadow_transform);
                  vostok::render::renderer_context::set_w(v10->m_context, v58);
                }
                v59 = (*p_tree_component)->get_geometry_type(*p_tree_component);
                v60 = *p_tree_component;
                if ( v59 == 4 )
                {
                  vostok::render::speedtree_billboard_parameters::set(
                    (vostok::render::speedtree_billboard_parameters *)v60,
                    (vostok::render::renderer_context *)&v10->m_context->m_scene->m_speedtree_forest->m_speedtree_billboard_parameters,
                    (vostok::render::speedtree_tree_component *)v10->m_context);
                  vostok::render::res_geometry::apply((*p_tree_component)->m_render_geometry.geom.m_object);
                  v62 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
                  v16 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                        + 529) == 4;
                  it_d = (vostok::render::render_surface_instance **)(*p_tree_component)->m_render_geometry.index_count;
                  v63 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
                  *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                  + 162) = !v16;
                  if ( !v16 )
                    *((_DWORD *)v62 + 529) = 4;
                  vostok::render::backend::flush(v61, (int)v62);
                  if ( v63[104] )
                  {
                    ++*((_DWORD *)v63 + 25);
                    v64 = (vostok::render::render_surface_instance **)((char *)it_d
                                                                     + (3 * s_max_triagles_per_dip_value < (unsigned int)it_d
                                                                      ? 3 * s_max_triagles_per_dip_value - (_DWORD)it_d
                                                                      : 0));
                  }
                  else
                  {
                    v64 = it_d;
                  }
                  if ( !v63[37] )
                    (*(void (__stdcall **)(int, vostok::render::render_surface_instance **, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y + 48))(
                      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
                      v64,
                      0,
                      0);
                  *((_DWORD *)v63 + 21) += (unsigned int)v64 / 3;
                }
                else
                {
                  vostok::render::speedtree_tree_parameters::set(
                    &this->m_context->m_scene->m_speedtree_forest->m_speedtree_tree_parameters,
                    v60,
                    (const SpeedTree::CInstance *)*(p_tree_component - 2),
                    (const SpeedTree::SInstanceLod *)*(p_tree_component - 1));
                  vostok::render::res_geometry::apply((*p_tree_component)->m_render_geometry.geom.m_object);
                  v65 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
                  v66 = (int)*(p_tree_component - 3);
                  v67 = *(vostok::render::render_surface_instance ***)v66;
                  v68 = *(_DWORD *)(v66 + 4);
                  LOBYTE(v66) = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                + 529) != 4;
                  end_d = v67;
                  v69 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
                  *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                  + 162) = v66;
                  if ( (_BYTE)v66 )
                    *((_DWORD *)v65 + 529) = 4;
                  vostok::render::backend::flush((vostok::render::backend *)v67, (int)v65);
                  if ( v69[104] )
                  {
                    ++*((_DWORD *)v69 + 25);
                    v68 += 3 * s_max_triagles_per_dip_value < v68 ? 3 * s_max_triagles_per_dip_value - v68 : 0;
                  }
                  if ( !v69[37] )
                    (*(void (__stdcall **)(int, unsigned int, vostok::render::render_surface_instance *const *, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y + 48))(
                      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
                      v68,
                      end_d,
                      0);
                  v70 = vostok::quasi_singleton<vostok::render::statistics>::pinst;
                  v71 = v68;
                  v10 = this;
                  *((_DWORD *)v69 + 21) += v71 / 3;
                  v70->visibility_stat_group.num_triangles.value += (unsigned int)(*(p_tree_component - 3))->m_parent
                                                                  / 3;
                  ++v70->visibility_stat_group.num_speedtree_instances.value;
                }
              }
            }
          }
          p_tree_component += 4;
        }
        while ( p_tree_component - 3 != (vostok::render::speedtree_tree_component **)visible_trees._M_impl._M_finish );
        v41 = visible_trees._M_impl._M_start;
      }
      if ( v41 )
      {
        v72 = vostok::render::g_allocator.m_object;
        BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
        vostok_mspace_free((void *)HIDWORD(v72->m_reconstruction_info_actuality_tick), v41);
      }
    }
  }
LABEL_103:
  v73 = v10->m_context;
  qmemcpy((void *)&shadow_transform, &v73->m_vp, sizeof(shadow_transform));
  vostok::render::renderer_context::set_v(
    (vostok::render::renderer_context *)&v73->m_v_stack.m_end[-1],
    (const vostok::math::float4x4 *)v73);
  --v73->m_v_stack.m_end;
  v74 = v10->m_context;
  vostok::render::renderer_context::set_p(v75, (const vostok::math::float4x4 *)v74);
  --v74->m_p_stack.m_end;
  m_game = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game;
  v10->m_shadow_z_bias = shadow_quality * 0.1;
  v77 = v85;
  qmemcpy((void *)&v10->m_view_to_light_matrix, &shadow_transform, sizeof(v10->m_view_to_light_matrix));
  v10->m_shadow_map_size = v77;
  (*(void (__stdcall **)(int, int, D3D11_VIEWPORT *))(*(_DWORD *)m_game->m_game_world.m_mouse_pos.y + 176))(
    m_game->m_game_world.m_mouse_pos.y,
    1,
    &orig_viewport);
  v78 = m_dynamic_visuals_to_shadow._M_impl._M_start;
  if ( m_dynamic_visuals_to_shadow._M_impl._M_start )
  {
    v79 = vostok::render::g_allocator.m_object;
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free((void *)HIDWORD(v79->m_reconstruction_info_actuality_tick), v78);
  }
}
