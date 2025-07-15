void __thiscall vostok::render::stage_sun::execute(vostok::render::stage_sun *this)
{
  vostok::render::lights_db *m_object; // eax
  vostok::render::light *v3; // ecx
  const vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *p_m_sun; // eax
  vostok::render::light *v5; // ecx
  vostok::render::light *v6; // ebp
  vostok::render::grass_render_model *v7; // esi
  vostok::render::renderer_context *m_context; // eax
  float z; // xmm0_4
  float y; // xmm1_4
  float x; // xmm2_4
  float v12; // edx
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm3_4
  float v16; // xmm4_4
  float v17; // xmm3_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  __int64 v20; // xmm0_8
  vostok::render::res_effect *v21; // eax
  int v22; // ecx
  vostok::render::constants_handler<1> *m_conflicted_key_name; // ebp
  vostok::render::shader_constant_host *m_c_light_direction; // eax
  int v25; // ecx
  unsigned __int16 m_buffer_index; // cx
  float v27; // xmm0_4
  vostok::render::shader_constant_host *m_c_light_color; // eax
  unsigned int m_diff_range_start; // ecx
  unsigned __int16 v30; // cx
  vostok::render::light *v31; // edi
  unsigned int i; // edi
  vostok::render::renderer_context *v33; // eax
  const vostok::math::float4x4 *p_m_v2shadow1; // eax
  const char *v35; // eax
  vostok::render::shader_constant_host *v36; // ecx
  unsigned __int16 v37; // dx
  vostok::render::shader_constant_host *m_c_clouds_offset; // eax
  unsigned __int16 v39; // cx
  const char *v40; // eax
  vostok::render::shader_constant_host *m_c_world_to_cloud; // ecx
  unsigned __int16 v42; // dx
  vostok::render::shader_constant_host *m_c_cloud_interp_alpha; // eax
  unsigned __int16 v44; // cx
  const vostok::math::float4x4 *v45; // edx
  const char *v46; // eax
  vostok::render::shader_constant_host *m_c_inverted_view_projection_matrix; // ecx
  unsigned __int16 v48; // dx
  float v49; // xmm1_4
  float v50; // xmm2_4
  const vostok::math::float4x4 *v51; // edx
  const char *v52; // eax
  vostok::render::shader_constant_host *m_c_sun_fixed_matrix; // ecx
  unsigned __int16 v54; // dx
  vostok::render::shader_constant_host *m_c_shadow_transparency; // eax
  unsigned __int16 v56; // cx
  vostok::render::shader_constant_host *m_c_eye_ray_corner; // eax
  unsigned __int16 v58; // cx
  const vostok::render::renderer_context_targets *m_targets; // eax
  vostok::render::render_target *v60; // eax
  const vostok::render::renderer_context_targets *v61; // eax
  vostok::render::render_target *v62; // eax
  const vostok::render::renderer_context_targets *v63; // eax
  vostok::render::render_target *v64; // eax
  const vostok::math::float4x4 *v65; // eax
  const char *v66; // esi
  vostok::render::backend *v67; // ecx
  int v68; // eax
  bool v69; // zf
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v70; // [esp-1Ch] [ebp-134h] BYREF
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v71; // [esp-18h] [ebp-130h]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v72; // [esp-14h] [ebp-12Ch]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v73; // [esp-10h] [ebp-128h]
  BOOL v74; // [esp-Ch] [ebp-124h]
  int v75; // [esp-8h] [ebp-120h]
  float v76; // [esp-4h] [ebp-11Ch]
  float pos_y; // [esp+0h] [ebp-118h]
  float size_x; // [esp+4h] [ebp-114h]
  float size_y; // [esp+8h] [ebp-110h]
  float v80; // [esp+Ch] [ebp-10Ch]
  unsigned int v81; // [esp+10h] [ebp-108h]
  vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> object; // [esp+24h] [ebp-F4h] BYREF
  vostok::math::float3 sun_dir; // [esp+28h] [ebp-F0h] BYREF
  vostok::math::float3 sun_clr; // [esp+34h] [ebp-E4h] BYREF
  vostok::math::float3 src_ptr; // [esp+40h] [ebp-D8h] BYREF
  const vostok::math::float4x4 *v86; // [esp+4Ch] [ebp-CCh]
  const vostok::math::float3 *eye_rays; // [esp+50h] [ebp-C8h]
  vostok::math::float3 *view; // [esp+54h] [ebp-C4h]
  vostok::math::float4x4 sun_fixed_matrix; // [esp+58h] [ebp-C0h] BYREF
  vostok::math::float4x4 result; // [esp+98h] [ebp-80h] BYREF
  vostok::math::float4x4 v91; // [esp+D8h] [ebp-40h] BYREF

  if ( this->m_sun_effect.m_object )
  {
    m_object = this->m_context->m_scene->m_lights.m_object;
    v3 = m_object->m_sun.m_object;
    p_m_sun = &m_object->m_sun;
    if ( !v3
      || !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
      || v3->m_enabled )
    {
      object.m_object = 0;
      vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
        (vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v3,
        &object,
        p_m_sun);
      v6 = object.m_object;
      if ( object.m_object )
      {
        --object.m_object->m_reference_count;
        if ( !v6->m_reference_count )
        {
          v7 = vostok::render::g_allocator.m_object;
          vostok::render::light::~light(v5, (int)v6);
          BYTE2(v7->m_children_resources.m_lock) = 0;
          vostok_mspace_free((void *)HIDWORD(v7->m_reconstruction_info_actuality_tick), v6);
        }
        m_context = this->m_context;
        z = v6->direction.z;
        y = v6->direction.y;
        x = v6->direction.x;
        v12 = v6->color.z;
        v13 = (float)(m_context->m_v.j.x * y) + (float)(m_context->m_v.k.x * z);
        v14 = m_context->m_v.i.x;
        eye_rays = m_context->m_eye_rays;
        v15 = v13 + (float)(v14 * x);
        v16 = m_context->m_v.j.y;
        sun_dir.x = v15;
        sun_dir.y = (float)((float)(m_context->m_v.i.y * x) + (float)(v16 * y)) + (float)(m_context->m_v.k.y * z);
        v17 = m_context->m_v.i.z * x;
        v18 = m_context->m_v.j.z * y;
        v19 = m_context->m_v.k.z * z;
        v20 = *(_QWORD *)&v6->color.x;
        view = &v6->direction;
        sun_dir.z = (float)(v17 + v18) + v19;
        *(_QWORD *)&sun_clr.x = v20;
        sun_clr.z = v12;
        vostok::math::float3_pod::normalize(&sun_dir);
        v21 = this->m_sun_effect.m_object;
        v22 = v21->m_techniques._M_impl._M_finish - v21->m_techniques._M_impl._M_start;
        if ( v22 )
        {
          v21->m_cur_technique = 0;
          vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v22, v81);
        }
        m_conflicted_key_name = (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        m_c_light_direction = this->m_c_light_direction;
        v25 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 573);
        src_ptr = sun_dir;
        v86 = 0;
        if ( m_c_light_direction->m_update_markers[1] == v25 )
        {
          m_buffer_index = m_c_light_direction->m_shader_slots[1].m_buffer_index;
          if ( m_buffer_index != 0xFFFF )
            vostok::render::shader_constant_buffer::set_memory(
              m_c_light_direction->m_shader_slots[1].m_slot_index,
              (unsigned __int8)m_c_light_direction->m_shader_slots[1].m_class_id,
              *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                       + 371)
                                                                     + 16)
                                                         + 4 * m_buffer_index),
              (const char *)&src_ptr);
        }
        src_ptr.x = sun_clr.x;
        v27 = sun_clr.y;
        ++m_conflicted_key_name[7].m_current.m_object;
        m_c_light_color = this->m_c_light_color;
        m_diff_range_start = m_conflicted_key_name[191].m_diff_range_start;
        *(_QWORD *)&src_ptr.elements[1] = __PAIR64__(LODWORD(sun_clr.z), LODWORD(v27));
        v86 = clear_value;
        if ( m_c_light_color->m_update_markers[1] == m_diff_range_start )
        {
          v30 = m_c_light_color->m_shader_slots[1].m_buffer_index;
          if ( v30 != 0xFFFF )
            vostok::render::shader_constant_buffer::set_memory(
              m_c_light_color->m_shader_slots[1].m_slot_index,
              (unsigned __int8)m_c_light_color->m_shader_slots[1].m_class_id,
              m_conflicted_key_name[123].m_current.m_object->m_const_buffers._M_impl._M_start[v30].m_object,
              (const char *)&src_ptr);
        }
        ++m_conflicted_key_name[7].m_current.m_object;
        v31 = object.m_object;
        vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
          this->m_c_light_intensity,
          m_conflicted_key_name + 123,
          (const vostok::math::float3 *)&object.m_object->intensity);
        ++m_conflicted_key_name[7].m_current.m_object;
        vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
          this->m_c_diffuse_influence_factor,
          m_conflicted_key_name + 123,
          (const vostok::math::float3 *)&v31->diffuse_influence_factor);
        ++m_conflicted_key_name[7].m_current.m_object;
        vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
          this->m_c_specular_influence_factor,
          m_conflicted_key_name + 123,
          (const vostok::math::float3 *)&v31->specular_influence_factor);
        ++m_conflicted_key_name[7].m_current.m_object;
        for ( i = 0; i < 4; ++i )
        {
          v33 = this->m_context;
          switch ( i )
          {
            case 1u:
              p_m_v2shadow1 = &v33->m_v2shadow1;
              break;
            case 2u:
              p_m_v2shadow1 = &v33->m_v2shadow2;
              break;
            case 3u:
              p_m_v2shadow1 = &v33->m_v2shadow3;
              break;
            default:
              p_m_v2shadow1 = &v33->m_v2shadow0;
              break;
          }
          v35 = (const char *)vostok::math::transpose(&result, p_m_v2shadow1);
          v36 = this->m_shadow[i];
          if ( v36->m_update_markers[1] == m_conflicted_key_name[191].m_diff_range_start )
          {
            v37 = v36->m_shader_slots[1].m_buffer_index;
            if ( v37 != 0xFFFF )
              vostok::render::shader_constant_buffer::set_memory(
                v36->m_shader_slots[1].m_slot_index,
                (unsigned __int8)v36->m_shader_slots[1].m_class_id,
                m_conflicted_key_name[123].m_current.m_object->m_const_buffers._M_impl._M_start[v37].m_object,
                v35);
          }
          ++m_conflicted_key_name[7].m_current.m_object;
        }
        m_c_clouds_offset = this->m_c_clouds_offset;
        if ( m_c_clouds_offset->m_update_markers[1] == m_conflicted_key_name[191].m_diff_range_start )
        {
          v39 = m_c_clouds_offset->m_shader_slots[1].m_buffer_index;
          if ( v39 != 0xFFFF )
            vostok::render::shader_constant_buffer::set_memory(
              m_c_clouds_offset->m_shader_slots[1].m_slot_index,
              (unsigned __int8)m_c_clouds_offset->m_shader_slots[1].m_class_id,
              m_conflicted_key_name[123].m_current.m_object->m_const_buffers._M_impl._M_start[v39].m_object,
              (const char *)this->m_simulation);
        }
        ++m_conflicted_key_name[7].m_current.m_object;
        v40 = (const char *)vostok::math::transpose(&sun_fixed_matrix, &this->m_simulation->world_to_cloud);
        m_c_world_to_cloud = this->m_c_world_to_cloud;
        if ( m_c_world_to_cloud->m_update_markers[1] == m_conflicted_key_name[191].m_diff_range_start )
        {
          v42 = m_c_world_to_cloud->m_shader_slots[1].m_buffer_index;
          if ( v42 != 0xFFFF )
            vostok::render::shader_constant_buffer::set_memory(
              m_c_world_to_cloud->m_shader_slots[1].m_slot_index,
              (unsigned __int8)m_c_world_to_cloud->m_shader_slots[1].m_class_id,
              m_conflicted_key_name[123].m_current.m_object->m_const_buffers._M_impl._M_start[v42].m_object,
              v40);
        }
        ++m_conflicted_key_name[7].m_current.m_object;
        m_c_cloud_interp_alpha = this->m_c_cloud_interp_alpha;
        if ( m_c_cloud_interp_alpha->m_update_markers[1] == m_conflicted_key_name[191].m_diff_range_start )
        {
          v44 = m_c_cloud_interp_alpha->m_shader_slots[1].m_buffer_index;
          if ( v44 != 0xFFFF )
            vostok::render::shader_constant_buffer::set_memory(
              m_c_cloud_interp_alpha->m_shader_slots[1].m_slot_index,
              (unsigned __int8)m_c_cloud_interp_alpha->m_shader_slots[1].m_class_id,
              m_conflicted_key_name[123].m_current.m_object->m_const_buffers._M_impl._M_start[v44].m_object,
              (const char *)&this->m_simulation->interp_alpha);
        }
        ++m_conflicted_key_name[7].m_current.m_object;
        vostok::math::try_invert4x4(&this->m_context->m_vp, &sun_fixed_matrix);
        v46 = (const char *)vostok::math::transpose(&result, v45);
        m_c_inverted_view_projection_matrix = this->m_c_inverted_view_projection_matrix;
        if ( m_c_inverted_view_projection_matrix->m_update_markers[1] == m_conflicted_key_name[191].m_diff_range_start )
        {
          v48 = m_c_inverted_view_projection_matrix->m_shader_slots[1].m_buffer_index;
          if ( v48 != 0xFFFF )
            vostok::render::shader_constant_buffer::set_memory(
              m_c_inverted_view_projection_matrix->m_shader_slots[1].m_slot_index,
              (unsigned __int8)m_c_inverted_view_projection_matrix->m_shader_slots[1].m_class_id,
              m_conflicted_key_name[123].m_current.m_object->m_const_buffers._M_impl._M_start[v48].m_object,
              v46);
        }
        ++m_conflicted_key_name[7].m_current.m_object;
        v49 = view->y;
        v50 = view->z;
        *(_QWORD *)&sun_dir.x = (unsigned int)clear_value;
        sun_dir.z = 0.0;
        sun_clr.x = view->x * -10000.0;
        sun_clr.y = v49 * -10000.0;
        sun_clr.z = v50 * -10000.0;
        vostok::math::create_camera_direction(&sun_clr, view, &sun_dir);
        vostok::math::try_invert4x4(&sun_fixed_matrix, &result);
        v52 = (const char *)vostok::math::transpose(&v91, v51);
        m_c_sun_fixed_matrix = this->m_c_sun_fixed_matrix;
        if ( m_c_sun_fixed_matrix->m_update_markers[1] == m_conflicted_key_name[191].m_diff_range_start )
        {
          v54 = m_c_sun_fixed_matrix->m_shader_slots[1].m_buffer_index;
          if ( v54 != 0xFFFF )
            vostok::render::shader_constant_buffer::set_memory(
              m_c_sun_fixed_matrix->m_shader_slots[1].m_slot_index,
              (unsigned __int8)m_c_sun_fixed_matrix->m_shader_slots[1].m_class_id,
              m_conflicted_key_name[123].m_current.m_object->m_const_buffers._M_impl._M_start[v54].m_object,
              v52);
        }
        ++m_conflicted_key_name[7].m_current.m_object;
        m_c_shadow_transparency = this->m_c_shadow_transparency;
        if ( m_c_shadow_transparency->m_update_markers[1] == m_conflicted_key_name[191].m_diff_range_start )
        {
          v56 = m_c_shadow_transparency->m_shader_slots[1].m_buffer_index;
          if ( v56 != 0xFFFF )
            vostok::render::shader_constant_buffer::set_memory(
              m_c_shadow_transparency->m_shader_slots[1].m_slot_index,
              (unsigned __int8)m_c_shadow_transparency->m_shader_slots[1].m_class_id,
              m_conflicted_key_name[123].m_current.m_object->m_const_buffers._M_impl._M_start[v56].m_object,
              (const char *)&object.m_object->shadow_transparency);
        }
        ++m_conflicted_key_name[7].m_current.m_object;
        m_c_eye_ray_corner = this->m_c_eye_ray_corner;
        if ( m_c_eye_ray_corner->m_update_markers[1] == m_conflicted_key_name[191].m_diff_range_start )
        {
          v58 = m_c_eye_ray_corner->m_shader_slots[1].m_buffer_index;
          if ( v58 != 0xFFFF )
            vostok::render::shader_constant_buffer::set_memory(
              m_c_eye_ray_corner->m_shader_slots[1].m_slot_index,
              (unsigned __int8)m_c_eye_ray_corner->m_shader_slots[1].m_class_id,
              m_conflicted_key_name[123].m_current.m_object->m_const_buffers._M_impl._M_start[v58].m_object,
              (const char *)eye_rays);
        }
        ++m_conflicted_key_name[7].m_current.m_object;
        v80 = 1.0;
        size_y = 1.0;
        size_x = 0.0;
        pos_y = 0.0;
        v76 = 0.0;
        v75 = 1;
        v74 = 0;
        v73.m_object = 0;
        m_targets = this->m_context->m_targets;
        v72.m_object = 0;
        v60 = m_targets->m_family[8].target.m_object;
        if ( v60 )
        {
          v72.m_object = v60;
          ++v60->m_reference_count;
        }
        v61 = this->m_context->m_targets;
        v71.m_object = 0;
        v62 = v61->m_family[28].target.m_object;
        if ( v62 )
        {
          v71.m_object = v62;
          ++v62->m_reference_count;
        }
        v63 = this->m_context->m_targets;
        v70.m_object = 0;
        v64 = v63->m_family[26].target.m_object;
        if ( v64 )
        {
          v70.m_object = v64;
          ++v64->m_reference_count;
        }
        vostok::render::system_renderer::fill_surface(
          (vostok::render::system_renderer *)&v70,
          (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.x,
          v70,
          v71,
          v72,
          v73,
          v74,
          (D3D11_VIEWPORT *)v75,
          v76,
          pos_y,
          size_x,
          size_y);
        v65 = vostok::math::float4x4::identity(&v91);
        vostok::render::renderer_context::set_w(this->m_context, v65);
        v66 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        vostok::render::backend::reset_render_targets(
          v67,
          (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
        v68 = *((_DWORD *)v66 + 547);
        v69 = *((_DWORD *)v66 + 539) == v68;
        *((_DWORD *)v66 + 539) = v68;
        *((_BYTE *)v66 + 167) |= !v69;
      }
    }
  }
}
