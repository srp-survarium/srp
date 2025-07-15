void __thiscall vostok::render::stage_composition::execute(vostok::render::stage_composition *this)
{
  vostok::render::renderer_context *m_context; // eax
  vostok::render::res_effect *m_eye_rays; // ecx
  int v4; // eax
  vostok::render::renderer_context *v5; // eax
  float v6; // xmm3_4
  vostok::render::renderer_context *v7; // ecx
  float v8; // xmm1_4
  float v9; // xmm2_4
  int v10; // esi
  vostok::render::base_scene_view *m_object; // eax
  float v12; // xmm4_4
  float v13; // xmm1_4
  vostok::render::scene_view_mode m_view_mode; // eax
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *rt; // eax
  vostok::render::backend *v16; // ecx
  _DWORD *v17; // eax
  vostok::render::res_effect *v18; // eax
  vostok::render::res_effect *v19; // ecx
  vostok::render::system_renderer *v20; // esi
  vostok::render::render_target *v21; // ecx
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v22; // eax
  vostok::render::backend *v23; // ecx
  _DWORD *v24; // eax
  vostok::render::res_effect *v25; // eax
  vostok::render::res_effect *v26; // ecx
  vostok::render::render_target *v27; // ecx
  vostok::render::system_renderer *v28; // esi
  vostok::render::res_effect *v29; // eax
  vostok::render::system_renderer *v30; // esi
  BOOL v31; // ecx
  vostok::render::res_effect *v32; // eax
  float z; // esi
  vostok::render::backend *v34; // ecx
  vostok::render::backend *v35; // ecx
  vostok::render::backend *v36; // ecx
  vostok::render::backend *v37; // ecx
  vostok::render::backend *v38; // ecx
  vostok::render::backend *v39; // ecx
  const vostok::math::float4x4 *v40; // edx
  vostok::math::float4x4 *v41; // eax
  vostok::render::backend *v42; // ecx
  vostok::render::backend *v43; // ecx
  vostok::render::backend *v44; // ecx
  vostok::render::system_renderer *v45; // esi
  vostok::render::render_target *v46; // ecx
  float v47; // eax
  int v48; // edi
  bool v49; // zf
  vostok::render::stage_composition *v50; // ecx
  vostok::render::backend *v51; // ecx
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v52; // eax
  _DWORD *v53; // eax
  vostok::render::system_renderer *v54; // [esp-10h] [ebp-18Ch]
  vostok::render::system_renderer *v55; // [esp-10h] [ebp-18Ch]
  vostok::render::system_renderer *v56; // [esp-10h] [ebp-18Ch]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v57; // [esp-Ch] [ebp-188h] BYREF
  vostok::render::system_renderer v58; // [esp-8h] [ebp-184h] BYREF

  pix_event_wrapper_dx11::pix_event_wrapper_dx11(
    (pix_event_wrapper_dx11 *)this,
    (pix_event_wrapper_dx11 *)&v58.m_selection_rate + 3,
    (int)L"stage_composition");
  if ( this->is_effects_ready(this) )
  {
    if ( vostok::quasi_singleton<vostok::render::options>::pinst->current.m_composition_stage && this->is_enabled(this) )
    {
      m_context = this->m_context;
      m_eye_rays = (vostok::render::res_effect *)m_context->m_eye_rays;
      v4 = (int)&m_context->m_scene_view.m_object[1];
      v58.m_block_compression_effect.m_object = m_eye_rays;
      vostok::render::environment_properties::get_sun_direction(
        (vostok::render::environment_properties *)m_eye_rays,
        v4,
        &v58.m_selection_color.y);
      v5 = this->m_context;
      v6 = (float)((float)(v5->m_v.k.x * v58.m_selection_color.w) + (float)(v5->m_v.j.x * v58.m_selection_color.z))
         + (float)(v58.m_selection_color.y * v5->m_v.i.x);
      v7 = v5;
      v8 = (float)((float)(v5->m_v.k.y * v58.m_selection_color.w) + (float)(v5->m_v.j.y * v58.m_selection_color.z))
         + (float)(v5->m_v.i.y * v58.m_selection_color.y);
      v9 = (float)((float)(v5->m_v.k.z * v58.m_selection_color.w) + (float)(v5->m_v.j.z * v58.m_selection_color.z))
         + (float)(v5->m_v.i.z * v58.m_selection_color.y);
      v10 = (int)&v5->m_scene_view.m_object[1].m_parent_resources.gapC;
      m_object = v5->m_scene_view.m_object;
      v58.m_colored_geom_sl.m_object = *(vostok::render::res_geometry **)v10;
      v10 += 4;
      v12 = s_bm_current_air_resistance / fsqrt((float)((float)(v6 * v6) + (float)(v9 * v9)) + (float)(v8 * v8));
      v58.m_selection_color.z = v8 * v12;
      v13 = *(float *)&m_object[1].m_parent_resources.m_thread_id;
      m_view_mode = this->m_view_mode;
      v58.m_WVP_sl = *(vostok::render::shader_constant_host **)v10;
      v58.m_selection_color.x = v13;
      v58.m_c_start_corner = *(vostok::render::shader_constant_host **)(v10 + 4);
      v58.m_selection_color.y = v12 * v6;
      v58.m_selection_color.w = v9 * v12;
      *(float *)&v58.m_add_border_padding_effect.m_object = s_bm_current_air_resistance;
      *(float *)&v58.m_sh_sl.m_object = s_bm_current_air_resistance;
      v58.m_ghost_model_color.x = 0.0;
      v58.m_ghost_model_color.y = s_bm_current_air_resistance;
      v58.m_ghost_model_color.z = s_bm_current_air_resistance;
      v58.m_ghost_model_color.w = s_bm_current_air_resistance;
      *(float *)&v58.m_renderer_context = s_bm_current_air_resistance;
      switch ( m_view_mode )
      {
        case lighting_view_mode:
          rt = vostok::render::renderer_context::get_rt(
                 v7,
                 rt_albedo,
                 (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v58.m_render_model_to_material._M_t._M_key_compare);
          vostok::render::backend::set_render_targets(
            (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
            rt->m_object,
            0,
            0,
            0);
          v17 = *(_DWORD **)&v58.m_render_model_to_material._M_t._M_key_compare.gap0;
          if ( *(_DWORD *)&v58.m_render_model_to_material._M_t._M_key_compare.gap0 )
          {
            --**(_DWORD **)&v58.m_render_model_to_material._M_t._M_key_compare.gap0;
            if ( !*v17 )
              vostok::render::resource_manager::release(
                *(vostok::render::render_target **)&v58.m_render_model_to_material._M_t._M_key_compare.gap0,
                vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
          }
          vostok::render::backend::clear_render_targets(
            v16,
            SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
            SLODWORD(s_bm_current_air_resistance),
            1.0,
            1.0,
            1.0);
          v18 = this->m_debug_modify_gbuffer_effect.m_object;
          v18->m_cur_technique = 2;
          vostok::render::res_effect::apply_pass(v19, (int)v18);
          v58.m_render_model_to_material._M_t._M_header._M_data._M_parent = (stlp_std::priv::_Rb_tree_node_base *)1;
          v20 = vostok::quasi_singleton<vostok::render::system_renderer>::pinst;
          v57.m_object = v21;
          memset(&v58, 0, 16);
          v54 = (vostok::render::system_renderer *)v21;
          vostok::render::renderer_context::get_rt(this->m_context, rt_surface_parameters, &v57);
          vostok::render::system_renderer::fill_surface(
            v54,
            (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v20,
            v57.m_object,
            (vostok::render::render_target *)v58.m_cook_data_to_delete,
            (vostok::render::render_target *)v58.m_screen_vertex_ib.m_object,
            (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v58.m_screen_vertex_geometry.m_object,
            *(vostok::render::render_target **)&v58.m_render_model_to_material._M_t._M_header._M_data._M_color,
            (D3D11_VIEWPORT *)v58.m_render_model_to_material._M_t._M_header._M_data._M_parent,
            *(float *)&v58.m_render_model_to_material._M_t._M_header._M_data._M_left,
            *(float *)&v58.m_render_model_to_material._M_t._M_header._M_data._M_right,
            *(float *)&v58.m_render_model_to_material._M_t._M_node_count,
            *(float *)&v58.m_render_model_to_material._M_t._M_key_compare.gap0);
          break;
        case lighting_diffuse_view_mode:
          v22 = vostok::render::renderer_context::get_rt(
                  v7,
                  rt_albedo,
                  (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v58.m_render_model_to_material._M_t._M_key_compare);
          vostok::render::backend::set_render_targets(
            (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
            v22->m_object,
            0,
            0,
            0);
          v24 = *(_DWORD **)&v58.m_render_model_to_material._M_t._M_key_compare.gap0;
          if ( *(_DWORD *)&v58.m_render_model_to_material._M_t._M_key_compare.gap0 )
          {
            --**(_DWORD **)&v58.m_render_model_to_material._M_t._M_key_compare.gap0;
            if ( !*v24 )
              vostok::render::resource_manager::release(
                *(vostok::render::render_target **)&v58.m_render_model_to_material._M_t._M_key_compare.gap0,
                vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
          }
          vostok::render::backend::clear_render_targets(
            v23,
            SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
            SLODWORD(s_bm_current_air_resistance),
            1.0,
            1.0,
            1.0);
          v25 = this->m_debug_modify_gbuffer_effect.m_object;
          v25->m_cur_technique = 1;
          vostok::render::res_effect::apply_pass(v26, (int)v25);
          v58.m_render_model_to_material._M_t._M_header._M_data._M_parent = (stlp_std::priv::_Rb_tree_node_base *)1;
          v57.m_object = v27;
          memset(&v58, 0, 16);
          v28 = vostok::quasi_singleton<vostok::render::system_renderer>::pinst;
          v55 = (vostok::render::system_renderer *)v27;
          vostok::render::renderer_context::get_rt(this->m_context, rt_surface_parameters, &v57);
          vostok::render::system_renderer::fill_surface(
            v55,
            (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v28,
            v57.m_object,
            (vostok::render::render_target *)v58.m_cook_data_to_delete,
            (vostok::render::render_target *)v58.m_screen_vertex_ib.m_object,
            (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v58.m_screen_vertex_geometry.m_object,
            *(vostok::render::render_target **)&v58.m_render_model_to_material._M_t._M_header._M_data._M_color,
            (D3D11_VIEWPORT *)v58.m_render_model_to_material._M_t._M_header._M_data._M_parent,
            *(float *)&v58.m_render_model_to_material._M_t._M_header._M_data._M_left,
            *(float *)&v58.m_render_model_to_material._M_t._M_header._M_data._M_right,
            *(float *)&v58.m_render_model_to_material._M_t._M_node_count,
            *(float *)&v58.m_render_model_to_material._M_t._M_key_compare.gap0);
          v58.m_ghost_model_color.z = 0.0;
          break;
        case lighting_specular_view_mode:
          v29 = this->m_debug_modify_gbuffer_effect.m_object;
          v58.m_ghost_model_color.y = 0.0;
          v29->m_cur_technique = 2;
          vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v7, (int)v29);
          v58.m_render_model_to_material._M_t._M_header._M_data._M_parent = (stlp_std::priv::_Rb_tree_node_base *)1;
          v30 = vostok::quasi_singleton<vostok::render::system_renderer>::pinst;
          v57.m_object = (vostok::render::render_target *)&v58;
          memset(&v58, 0, 16);
          vostok::render::renderer_context::get_rt(this->m_context, rt_surface_parameters, &v57);
          vostok::render::system_renderer::fill_surface(
            &v58,
            (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v30,
            v57.m_object,
            (vostok::render::render_target *)v58.m_cook_data_to_delete,
            (vostok::render::render_target *)v58.m_screen_vertex_ib.m_object,
            (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v58.m_screen_vertex_geometry.m_object,
            *(vostok::render::render_target **)&v58.m_render_model_to_material._M_t._M_header._M_data._M_color,
            (D3D11_VIEWPORT *)v58.m_render_model_to_material._M_t._M_header._M_data._M_parent,
            *(float *)&v58.m_render_model_to_material._M_t._M_header._M_data._M_left,
            *(float *)&v58.m_render_model_to_material._M_t._M_header._M_data._M_right,
            *(float *)&v58.m_render_model_to_material._M_t._M_node_count,
            *(float *)&v58.m_render_model_to_material._M_t._M_key_compare.gap0);
          break;
        case lighting_specular_mul_intensity_view_mode:
          v58.m_ghost_model_color.y = 0.0;
          break;
      }
      v31 = LOBYTE(this->m_context->m_scene_view.m_object[1].m_children_resources.m_last) != 0;
      v32 = this->m_composition_effect[v31].m_object;
      v32->m_cur_technique = 0;
      vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v31, (int)v32);
      v58.m_render_model_to_material._M_t._M_header._M_data._M_parent = (stlp_std::priv::_Rb_tree_node_base *)v58.m_block_compression_effect.m_object;
      z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v34,
        (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
        this->m_eye_ray_corner_parameter,
        (const vostok::math::float3 *)v58.m_block_compression_effect.m_object);
      *(_QWORD *)&v58.m_current_selection_color.x = *(_QWORD *)&v58.m_selection_color.elements[1];
      v58.m_render_model_to_material._M_t._M_header._M_data._M_parent = (stlp_std::priv::_Rb_tree_node_base *)&v58.m_current_selection_color;
      *(_DWORD *)&v58.m_render_model_to_material._M_t._M_header._M_data._M_color = this->m_c_light_direction;
      *(_QWORD *)&v58.m_current_selection_color.elements[2] = LODWORD(v58.m_selection_color.w);
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v35,
        (vostok::render::constants_handler<1> *)LODWORD(z),
        *(const vostok::render::shader_constant_host **)&v58.m_render_model_to_material._M_t._M_header._M_data._M_color,
        (const vostok::math::float3 *)&v58.m_current_selection_color);
      v58.m_render_model_to_material._M_t._M_header._M_data._M_parent = (stlp_std::priv::_Rb_tree_node_base *)&v58.m_current_selection_color;
      *(_DWORD *)&v58.m_render_model_to_material._M_t._M_header._M_data._M_color = this->m_c_light_color;
      v58.m_current_selection_color.x = *(float *)&v58.m_colored_geom_sl.m_object * v58.m_selection_color.x;
      v58.m_current_selection_color.y = *(float *)&v58.m_WVP_sl * v58.m_selection_color.x;
      v58.m_current_selection_color.z = *(float *)&v58.m_c_start_corner * v58.m_selection_color.x;
      v58.m_current_selection_color.w = s_bm_current_air_resistance;
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v36,
        (vostok::render::constants_handler<1> *)LODWORD(z),
        *(const vostok::render::shader_constant_host **)&v58.m_render_model_to_material._M_t._M_header._M_data._M_color,
        (const vostok::math::float3 *)&v58.m_current_selection_color);
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v37,
        (vostok::render::constants_handler<1> *)LODWORD(z),
        this->m_c_light_intensity,
        (const vostok::math::float3 *)&v58.m_selection_color);
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v38,
        (vostok::render::constants_handler<1> *)LODWORD(z),
        this->m_c_diffuse_influence_factor,
        (const vostok::math::float3 *)&v58.m_add_border_padding_effect);
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v39,
        (vostok::render::constants_handler<1> *)LODWORD(z),
        this->m_c_specular_influence_factor,
        (const vostok::math::float3 *)&v58.m_sh_sl);
      vostok::math::try_invert4x4(&this->m_context->m_vp, (vostok::math::float4x4 *)&v58.m_editor_selection_shader[8]);
      v41 = vostok::math::transpose(v40, (vostok::math::float4x4 *)&v58.m_grid_density);
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v42,
        (vostok::render::constants_handler<1> *)LODWORD(z),
        this->m_c_inverted_view_projection_matrix,
        (const vostok::math::float3 *)v41);
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v43,
        (vostok::render::constants_handler<1> *)LODWORD(z),
        this->m_c_shadow_transparency,
        (const vostok::math::float3 *)&v58.m_ghost_model_color);
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v44,
        (vostok::render::constants_handler<1> *)LODWORD(z),
        this->m_c_debug_multipliers,
        (const vostok::math::float3 *)&v58.m_ghost_model_color.elements[1]);
      v58.m_render_model_to_material._M_t._M_header._M_data._M_parent = (stlp_std::priv::_Rb_tree_node_base *)1;
      v45 = vostok::quasi_singleton<vostok::render::system_renderer>::pinst;
      v57.m_object = v46;
      memset(&v58, 0, 16);
      v56 = (vostok::render::system_renderer *)v46;
      vostok::render::renderer_context::get_rt(this->m_context, rt_generic_0, &v57);
      vostok::render::system_renderer::fill_surface(
        v56,
        (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v45,
        v57.m_object,
        (vostok::render::render_target *)v58.m_cook_data_to_delete,
        (vostok::render::render_target *)v58.m_screen_vertex_ib.m_object,
        (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v58.m_screen_vertex_geometry.m_object,
        *(vostok::render::render_target **)&v58.m_render_model_to_material._M_t._M_header._M_data._M_color,
        (D3D11_VIEWPORT *)v58.m_render_model_to_material._M_t._M_header._M_data._M_parent,
        *(float *)&v58.m_render_model_to_material._M_t._M_header._M_data._M_left,
        *(float *)&v58.m_render_model_to_material._M_t._M_header._M_data._M_right,
        *(float *)&v58.m_render_model_to_material._M_t._M_node_count,
        *(float *)&v58.m_render_model_to_material._M_t._M_key_compare.gap0);
      v47 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
      v48 = *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7440);
      v49 = *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7384) == v48;
      *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7384) = v48;
      LOBYTE(v50) = !v49;
      *(_BYTE *)(LODWORD(v47) + 117) |= !v49;
      v58.m_vertex_stream.m_buffer.m_object = (vostok::render::untyped_buffer *)&v58.m_vertex_stream.m_discard_id;
      v58.m_vertex_stream.m_size = (unsigned int)&v58.m_vertex_stream.m_discard_id;
      v58.m_vertex_stream.m_position = (unsigned int)&v58.m_editor_selection_shader[7];
      vostok::render::stage_composition::gather_subsurface_scattering_models(
        v50,
        (int)this,
        (vostok::buffer_vector<vostok::render::render_surface_instance *> *)&v58.m_vertex_stream);
      if ( ((v58.m_vertex_stream.m_size - (unsigned int)v58.m_vertex_stream.m_buffer.m_object) & 0xFFFFFFFC) != 0 )
      {
        v52 = vostok::render::renderer_context::get_rt(
                this->m_context,
                rt_generic_0,
                (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v58.m_render_model_to_material._M_t._M_key_compare);
        vostok::render::backend::set_render_targets(
          (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          v52->m_object,
          0,
          0,
          0);
        v53 = *(_DWORD **)&v58.m_render_model_to_material._M_t._M_key_compare.gap0;
        if ( *(_DWORD *)&v58.m_render_model_to_material._M_t._M_key_compare.gap0 )
        {
          --**(_DWORD **)&v58.m_render_model_to_material._M_t._M_key_compare.gap0;
          if ( !*v53 )
            vostok::render::resource_manager::release(
              *(vostok::render::render_target **)&v58.m_render_model_to_material._M_t._M_key_compare.gap0,
              vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
        }
        *(float *)&v58.m_render_model_to_material._M_t._M_header._M_data._M_parent = 0.0;
        *(float *)&v58.m_render_model_to_material._M_t._M_header._M_data._M_color = v58.m_selection_color.x;
        vostok::render::stage_composition::render_models(
          (vostok::buffer_vector<vostok::render::render_surface_instance *> *)&v58.m_vertex_stream,
          this,
          (const vostok::math::float3 *)&v58.m_selection_color.elements[1],
          (const vostok::math::float3 *)&v58.m_colored_geom_sl,
          *(_OWORD *)&v58.m_render_model_to_material._M_t.stlp_std::priv::_Rb_tree_base<stlp_std::pair<vostok::render::render_model_instance * const,vostok::render::material_effects>,vostok::render::std_allocator<stlp_std::pair<vostok::render::render_model_instance *,vostok::render::material_effects> > >);
      }
      vostok::render::backend::reset_render_targets(
        v51,
        SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
      v58.m_vertex_stream.m_size = (unsigned int)v58.m_vertex_stream.m_buffer.m_object;
    }
    else
    {
      this->execute_disabled(this);
    }
  }
  D3DPERF_EndEvent();
}
