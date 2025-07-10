void __userpurge vostok::render::stage_shadow_direct::render_models(
        int shadow_map_size@<eax>,
        const unsigned int refresh_rate@<ecx>,
        vostok::render::stage_shadow_direct *this,
        vostok::render::vector<vostok::render::render_surface_instance *> *m_caster_model,
        unsigned int orig_view_projection,
        vostok::render::grass_world *cascade_index,
        const vostok::math::float3 *real_view_pos,
        const unsigned int pass_index)
{
  vostok::render::vector<vostok::render::render_surface_instance *> *v8; // ebp
  const char *m_conflicted_key_name; // eax
  vostok::render::render_target *m_object; // ecx
  ID3D11DepthStencilView *m_zrt; // ecx
  bool v13; // zf
  survarium::game *m_game; // ecx
  void **M_start; // ebx
  int y; // eax
  vostok::render::render_surface_instance *v17; // ebx
  vostok::render::render_surface *m_render_surface; // ebp
  vostok::render::material_effects_instance *v19; // eax
  vostok::render::material_effects *p_m_material_effects; // esi
  vostok::render::res_effect *v21; // eax
  vostok::render::statistics *v22; // eax
  vostok::render::res_geometry *v23; // ecx
  vostok::render::backend *v24; // esi
  vostok::render::base_scene_view *v25; // eax
  float v26; // xmm0_4
  float v27; // xmm0_4
  vostok::render::shader_constant_host *m_wind_info_parameters; // eax
  unsigned int v29; // ecx
  int m_buffer_index; // ecx
  vostok::render::shader_constant_host *m_shadow_cascade_index; // eax
  int v32; // ecx
  void **v33; // eax
  void **v34; // esi
  vostok::render::renderer_context *m_context; // ecx
  float stencil_mask; // [esp+18h] [ebp-B0h]
  bool v37; // [esp+20h] [ebp-A8h]
  unsigned int v38; // [esp+24h] [ebp-A4h]
  vostok::render::render_surface_instance **it_d; // [esp+34h] [ebp-94h]
  unsigned int render_index; // [esp+38h] [ebp-90h]
  void **end_d; // [esp+3Ch] [ebp-8Ch]
  vostok::render::render_surface_instance **begin_d; // [esp+40h] [ebp-88h]
  int v43; // [esp+44h] [ebp-84h] BYREF
  unsigned int num_render; // [esp+48h] [ebp-80h]
  vostok::math::float3 wind_info_parameters; // [esp+4Ch] [ebp-7Ch] BYREF
  vostok::render::stage_shadow_direct::render_models::__l4::int4 shadow_viewport[4]; // [esp+58h] [ebp-70h]
  D3D11_VIEWPORT tmp_viewport; // [esp+98h] [ebp-30h] BYREF
  D3D11_VIEWPORT orig_viewport; // [esp+B0h] [ebp-18h] BYREF

  v8 = m_caster_model;
  render_index = 0;
  num_render = (m_caster_model->_M_impl._M_finish - m_caster_model->_M_impl._M_start)
             / (refresh_rate - (unsigned int)real_view_pos);
  if ( num_render )
  {
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
    m_object = this->m_rt_shadow_map.m_object;
    if ( m_object )
      m_zrt = m_object->m_zrt;
    else
      m_zrt = 0;
    v13 = *((_DWORD *)m_conflicted_key_name + 539) == (_DWORD)m_zrt;
    *((_DWORD *)m_conflicted_key_name + 539) = m_zrt;
    m_game = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game;
    *((_BYTE *)m_conflicted_key_name + 167) |= !v13;
    M_start = m_caster_model->_M_impl._M_start;
    end_d = m_caster_model->_M_impl._M_finish;
    y = m_game->m_game_world.m_mouse_pos.y;
    v43 = 1;
    begin_d = (vostok::render::render_surface_instance **)M_start;
    it_d = (vostok::render::render_surface_instance **)M_start;
    (*(void (__stdcall **)(int, int *, D3D11_VIEWPORT *))(*(_DWORD *)y + 380))(y, &v43, &orig_viewport);
    shadow_viewport[0].x = 0;
    shadow_viewport[0].y = 0;
    shadow_viewport[0].z = shadow_map_size;
    shadow_viewport[0].w = shadow_map_size;
    shadow_viewport[1].x = shadow_map_size;
    shadow_viewport[1].y = 0;
    shadow_viewport[1].z = shadow_map_size;
    shadow_viewport[1].w = shadow_map_size;
    shadow_viewport[2].x = 0;
    shadow_viewport[2].y = shadow_map_size;
    shadow_viewport[2].z = shadow_map_size;
    shadow_viewport[2].w = shadow_map_size;
    shadow_viewport[3].x = shadow_map_size;
    shadow_viewport[3].y = shadow_map_size;
    shadow_viewport[3].z = shadow_map_size;
    shadow_viewport[3].w = shadow_map_size;
    tmp_viewport.TopLeftX = (float)shadow_viewport[orig_view_projection].x;
    tmp_viewport.TopLeftY = (float)shadow_viewport[orig_view_projection].y;
    tmp_viewport.Width = (float)shadow_viewport[orig_view_projection].z;
    tmp_viewport.Height = (float)shadow_viewport[orig_view_projection].w;
    tmp_viewport.MinDepth = 0.0;
    LODWORD(tmp_viewport.MaxDepth) = clear_value;
    (*(void (__stdcall **)(int, int, D3D11_VIEWPORT *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                      + 176))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      1,
      &tmp_viewport);
    if ( M_start != end_d )
    {
      while ( render_index < num_render )
      {
        v17 = *it_d;
        m_render_surface = (*it_d)->m_render_surface;
        v19 = m_render_surface->m_materail_effects_instance.m_object;
        if ( !v19 || s_use_one_material_value )
          p_m_material_effects = s_nomaterial_material_effects[m_render_surface->m_vertex_input_type];
        else
          p_m_material_effects = &v19->m_material_effects;
        if ( (!p_m_material_effects->m_effects[17].m_object
           || !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr)
          && (p_m_material_effects->m_effects[0].m_object
           || !p_m_material_effects->m_effects[22].m_object
           || !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr)
          && p_m_material_effects->is_cast_shadow
          && (m_render_surface->m_render_geometry.geom.m_object
           || m_render_surface->m_render_geometry.shadow_pass_geom.m_object) )
        {
          if ( !p_m_material_effects->stage_enable[28] || (v21 = p_m_material_effects->m_effects[28].m_object) == 0 )
            v21 = this->m_effect_shadow_direct.m_object;
          vostok::render::res_effect::apply(0, v21);
          v22 = vostok::quasi_singleton<vostok::render::statistics>::pinst;
          switch ( orig_view_projection )
          {
            case 0u:
              ++vostok::quasi_singleton<vostok::render::statistics>::pinst->cascaded_sun_shadow_stat_group.num_dips_cascade_1.value;
              break;
            case 1u:
              ++vostok::quasi_singleton<vostok::render::statistics>::pinst->cascaded_sun_shadow_stat_group.num_dips_cascade_2.value;
              break;
            case 2u:
              ++vostok::quasi_singleton<vostok::render::statistics>::pinst->cascaded_sun_shadow_stat_group.num_dips_cascade_3.value;
              break;
            case 3u:
              ++vostok::quasi_singleton<vostok::render::statistics>::pinst->cascaded_sun_shadow_stat_group.num_dips_cascade_4.value;
              break;
            default:
              break;
          }
          ++v22->cascaded_sun_shadow_stat_group.num_dips.value;
          v22->cascaded_sun_shadow_stat_group.num_triangles.value += m_render_surface->m_render_geometry.primitive_count;
          v17->m_parent->set_constants(v17->m_parent);
          v23 = m_render_surface->m_render_geometry.shadow_pass_geom.m_object;
          if ( !v23 )
            v23 = m_render_surface->m_render_geometry.geom.m_object;
          vostok::render::res_geometry::apply(v23);
          v13 = !p_m_material_effects->is_wind_swings;
          v24 = (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
          if ( !v13 )
          {
            v25 = this->m_context->m_scene_view.m_object;
            v26 = *((float *)&v25[2].m_parent_resources + 6);
            ++v25;
            wind_info_parameters.x = v26;
            LODWORD(wind_info_parameters.y) = v25[1].m_memory_usage_self.size;
            v27 = *(float *)&v25[1].m_current_satisfaction_update_tick;
            m_wind_info_parameters = this->m_wind_info_parameters;
            v29 = m_wind_info_parameters->m_update_markers[0];
            wind_info_parameters.z = v27;
            if ( v29 == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                        + 572) )
            {
              m_buffer_index = m_wind_info_parameters->m_shader_slots[0].m_buffer_index;
              if ( m_buffer_index != 0xFFFF )
                vostok::render::shader_constant_buffer::set_memory(
                  m_wind_info_parameters->m_shader_slots[0].m_slot_index,
                  (unsigned __int8)m_wind_info_parameters->m_shader_slots[0].m_class_id,
                  *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                           + 51)
                                                                         + 16)
                                                             + 4 * m_buffer_index),
                  (const char *)&wind_info_parameters);
            }
            ++v24->num_setted_shader_constants;
          }
          m_shadow_cascade_index = this->m_shadow_cascade_index;
          if ( m_shadow_cascade_index->m_update_markers[1] == v24->m_constant_update_markers[1] )
          {
            v32 = m_shadow_cascade_index->m_shader_slots[1].m_buffer_index;
            if ( v32 != 0xFFFF )
              vostok::render::shader_constant_buffer::set_memory(
                m_shadow_cascade_index->m_shader_slots[1].m_slot_index,
                (unsigned __int8)m_shadow_cascade_index->m_shader_slots[1].m_class_id,
                v24->m_ps_constants_handler.m_current.m_object->m_const_buffers._M_impl._M_start[v32].m_object,
                (const char *)&orig_view_projection);
          }
          ++v24->num_setted_shader_constants;
          vostok::render::renderer_context::set_w(this->m_context, v17->m_transform);
          vostok::render::backend::render_indexed(
            v24,
            3 * m_render_surface->m_render_geometry.primitive_count,
            D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
            0,
            0);
        }
        ++render_index;
        if ( ++it_d == (vostok::render::render_surface_instance **)end_d )
          goto LABEL_52;
        v8 = m_caster_model;
        M_start = (void **)begin_d;
      }
      v33 = &M_start[num_render];
      if ( M_start != v33 )
      {
        v34 = stlp_std::priv::__copy_ptrs<void * *,void * *>(v33, v8->_M_impl._M_finish, M_start);
        stlp_std::_Destroy<vostok::fs_new::virtual_path_string>();
        v8->_M_impl._M_finish = v34;
      }
    }
LABEL_52:
    if ( !real_view_pos && s_draw_grass_shadows_value )
    {
      m_context = this->m_context;
      if ( m_context->m_scene->m_grass )
      {
        stencil_mask = 25.0;
        vostok::render::grass_world::render(
          cascade_index,
          (vostok::render::renderer_context *)m_context->m_scene->m_grass,
          (const vostok::math::float3 *)m_context,
          (vostok::render::enum_render_stage_type)cascade_index,
          0x1Cu,
          0.0,
          SLOBYTE(stencil_mask),
          (vostok::render::res_effect *)1,
          v37,
          v38);
      }
    }
    (*(void (__stdcall **)(int, int, D3D11_VIEWPORT *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                      + 176))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      1,
      &orig_viewport);
  }
}
