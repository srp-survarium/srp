void __thiscall vostok::render::stage_rain::execute(vostok::render::stage_rain *this)
{
  vostok::render::base_scene_view *v2; // ecx
  int y; // esi
  ID3D11Resource *m_surface; // edi
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *t; // eax
  vostok::render::renderer_context *m_context; // eax
  vostok::render::renderer_context *v7; // eax
  vostok::render::render_target *m_object; // eax
  ID3D11RenderTargetView *m_rt; // ecx
  const char *m_conflicted_key_name; // eax
  vostok::render::renderer_context *v11; // ebx
  float z; // xmm0_4
  float v13; // xmm3_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm3_4
  long double v17; // st7
  long double v18; // st7
  float m_camera_offset_view; // xmm0_4
  float v20; // xmm5_4
  long double v21; // st7
  long double v22; // st7
  float m_camera_offset_right; // xmm0_4
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v24; // ecx
  unsigned int Height; // eax
  float v26; // xmm0_4
  unsigned int BindFlags; // ebx
  float v28; // xmm1_4
  float *v29; // eax
  float v30; // xmm7_4
  float v31; // xmm2_4
  float v32; // xmm3_4
  float v33; // xmm4_4
  vostok::math::float2 *m_rain_offsets; // eax
  float v35; // xmm6_4
  float *p_x; // edi
  long double v37; // st7
  long double v38; // st7
  vostok::math::float4x4 *v39; // eax
  const vostok::math::float4x4 *v40; // eax
  const vostok::math::float4x4 *v41; // eax
  const vostok::math::float4x4 *v42; // eax
  vostok::render::shader_constant_host *m_radius_parameter; // eax
  vostok::render::backend *v44; // esi
  unsigned int v45; // edx
  int m_buffer_index; // ecx
  vostok::render::shader_constant_host *m_rain_speed_parameter; // eax
  int v48; // ecx
  vostok::render::shader_constant_host *m_rain_density_parameter; // eax
  int v50; // ecx
  vostok::render::shader_constant_host *m_rain_uv_scales_parameter; // eax
  int v52; // ecx
  const vostok::math::float3 *v53; // eax
  vostok::render::res_texture *v54; // eax
  vostok::render::renderer_context *v55; // esi
  const vostok::math::float4x4 *v56; // eax
  const char *v57; // esi
  vostok::render::backend *v58; // ecx
  int v59; // eax
  bool v60; // zf
  vostok::render::vector<vostok::render::render_surface_instance *> *v61; // ecx
  float range; // [esp+Ch] [ebp-318h]
  vostok::math::float4x4 *rangea; // [esp+Ch] [ebp-318h]
  vostok::math::float4x4 *v64; // [esp+10h] [ebp-314h]
  vostok::math::float4x4 *v65; // [esp+10h] [ebp-314h]
  const vostok::math::float4x4 *rotation_x; // [esp+10h] [ebp-314h]
  vostok::math::float4x4 *rotation_z; // [esp+14h] [ebp-310h]
  vostok::render::renderer_context *_X; // [esp+18h] [ebp-30Ch]
  const vostok::math::float4x4 *_Xa; // [esp+18h] [ebp-30Ch]
  vostok::render::enum_render_target_index v70; // [esp+1Ch] [ebp-308h]
  vostok::render::enum_render_target_index v71; // [esp+1Ch] [ebp-308h]
  vostok::render::enum_render_target_index v72; // [esp+1Ch] [ebp-308h]
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v73; // [esp+2Ch] [ebp-2F8h] BYREF
  unsigned int num_cones; // [esp+30h] [ebp-2F4h] BYREF
  float v75; // [esp+34h] [ebp-2F0h]
  float cone_scale; // [esp+38h] [ebp-2ECh] BYREF
  float abs_ov_dot_dir_ground2; // [esp+3Ch] [ebp-2E8h]
  float rain_density; // [esp+40h] [ebp-2E4h] BYREF
  float x; // [esp+44h] [ebp-2E0h]
  vostok::math::float2 right_dir_2d; // [esp+48h] [ebp-2DCh] BYREF
  float v81; // [esp+50h] [ebp-2D4h]
  float v82; // [esp+54h] [ebp-2D0h]
  vostok::math::float2 view_dir_2d; // [esp+58h] [ebp-2CCh] BYREF
  vostok::math::float2 offset_direction_ground; // [esp+60h] [ebp-2C4h] BYREF
  char src_ptr[4]; // [esp+68h] [ebp-2BCh] BYREF
  vostok::math::random32 r; // [esp+6Ch] [ebp-2B8h] BYREF
  float rain_angle_x; // [esp+70h] [ebp-2B4h]
  float rain_angle_y; // [esp+74h] [ebp-2B0h]
  vostok::math::float2 rain_uv_scales; // [esp+78h] [ebp-2ACh] BYREF
  vostok::math::float3 scale; // [esp+80h] [ebp-2A4h] BYREF
  vostok::math::float3 position; // [esp+8Ch] [ebp-298h] BYREF
  vostok::render::vector<vostok::render::render_surface_instance *> m_caster_model; // [esp+98h] [ebp-28Ch] BYREF
  vostok::math::float4x4 cone_transform; // [esp+A4h] [ebp-280h] BYREF
  vostok::math::float4x4 v94; // [esp+E4h] [ebp-240h] BYREF
  vostok::math::float4x4 view_to_shadow; // [esp+124h] [ebp-200h] BYREF
  _QWORD v96[8]; // [esp+164h] [ebp-1C0h] BYREF
  _BYTE v97[64]; // [esp+1A4h] [ebp-180h] BYREF
  vostok::math::float4x4 v98; // [esp+1E4h] [ebp-140h] BYREF
  vostok::math::float4x4 result; // [esp+224h] [ebp-100h] BYREF
  vostok::math::float4x4 v100; // [esp+264h] [ebp-C0h] BYREF
  _QWORD v101[8]; // [esp+2A4h] [ebp-80h] BYREF
  _BYTE v102[64]; // [esp+2E4h] [ebp-40h] BYREF

  if ( this->m_rain_effect.m_object && this->m_effect_shadow_direct.m_object )
  {
    if ( this->is_enabled(this)
      && (v2 = this->m_context->m_scene_view.m_object, LOBYTE(v2[2].m_children_resources.m_thread_id))
      && *(float *)&v2[2].m_children_resources.m_size >= 0.0099999998
      && LOBYTE(v2[4].m_memory_usage_self.size)
      && *((_DWORD *)&v2[4].m_parent_resources + 6) != 2 )
    {
      y = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y;
      _X = this->m_context;
      memset(&m_caster_model, 0, sizeof(m_caster_model));
      m_surface = vostok::render::renderer_context::get_t(
                    (vostok::render::renderer_context *)0x2F,
                    (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&cone_scale,
                    _X,
                    v70)->m_object->m_surface;
      t = vostok::render::renderer_context::get_t((vostok::render::renderer_context *)0x30, &v73, this->m_context, v71);
      (*(void (__stdcall **)(int, ID3D11Resource *, ID3D11Resource *))(*(_DWORD *)y + 188))(
        y,
        t->m_object->m_surface,
        m_surface);
      vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(&v73);
      vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&cone_scale);
      if ( s_first_pass_0 )
      {
        m_context = this->m_context;
        *(_QWORD *)&this->m_previous_view_position.x = *(_QWORD *)&m_context->m_view_pos.x;
        this->m_previous_view_position.z = m_context->m_view_pos.z;
        s_first_pass_0 = 0;
      }
      v7 = this->m_context;
      qmemcpy((void *)&view_to_shadow, &this->m_renderer->m_view_to_rain_shadow, sizeof(view_to_shadow));
      m_object = vostok::render::renderer_context::get_rt(
                   (vostok::render::renderer_context *)0x2F,
                   (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v73,
                   v7,
                   v72)->m_object;
      if ( m_object )
        m_rt = m_object->m_rt;
      else
        m_rt = 0;
      m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      if ( *((ID3D11RenderTargetView **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
           + 535) != m_rt )
      {
        *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) = m_rt;
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
      vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v73);
      v11 = this->m_context;
      qmemcpy((void *)&cone_transform, &v11->m_v, sizeof(cone_transform));
      right_dir_2d = 0;
      num_cones = LODWORD(v11->m_view_dir.x);
      z = v11->m_view_dir.z;
      r.m_seed = 1000;
      v75 = z;
      vostok::math::normalize_safe((const vostok::math::float2_pod *)&num_cones, &view_dir_2d, &right_dir_2d);
      *(float *)&num_cones = 0.0;
      v75 = 0.0;
      rain_density = cone_transform.i.x;
      x = cone_transform.k.x;
      vostok::math::normalize_safe(
        (const vostok::math::float2_pod *)&rain_density,
        &right_dir_2d,
        (vostok::math::float2 *)&num_cones);
      v13 = this->m_previous_view_position.z;
      v14 = v11->m_view_pos.z;
      *(float *)&num_cones = v11->m_view_pos.x - this->m_previous_view_position.x;
      v75 = v14 - v13;
      rain_density = 0.0;
      x = 0.0;
      vostok::math::normalize_safe(
        (const vostok::math::float2_pod *)&num_cones,
        &offset_direction_ground,
        (vostok::math::float2 *)&rain_density);
      v15 = (float)(view_dir_2d.y * offset_direction_ground.y) + (float)(view_dir_2d.x * offset_direction_ground.x);
      v16 = (float)(right_dir_2d.y * offset_direction_ground.y) + (float)(right_dir_2d.x * offset_direction_ground.x);
      cone_scale = v15;
      abs_ov_dot_dir_ground2 = v16;
      if ( v15 > 0.0 )
      {
        *(float *)&v73.m_object = fabs(
                                    (float)(view_dir_2d.y * offset_direction_ground.y)
                                  + (float)(view_dir_2d.x * offset_direction_ground.x));
        v17 = sqrtf((float)(v75 * v75) + (float)(*(float *)&num_cones * *(float *)&num_cones));
        v16 = abs_ov_dot_dir_ground2;
        v15 = cone_scale;
        this->m_camera_offset_view = v17 * *(float *)&v73.m_object * 0.5 + this->m_camera_offset_view;
      }
      if ( v15 < 0.0 )
      {
        v73.m_object = (vostok::render::res_texture *)(LODWORD(v15) & 0x7FFFFFFF);
        v18 = sqrtf((float)(v75 * v75) + (float)(*(float *)&num_cones * *(float *)&num_cones));
        v16 = abs_ov_dot_dir_ground2;
        this->m_camera_offset_view = this->m_camera_offset_view - v18 * *(float *)&v73.m_object * 0.5;
      }
      m_camera_offset_view = this->m_camera_offset_view;
      v20 = *(float *)&clear_value;
      if ( m_camera_offset_view < *(float *)&clear_value )
      {
        if ( m_camera_offset_view < 0.0 )
        {
          v73.m_object = (vostok::render::res_texture *)(LODWORD(m_camera_offset_view) & 0x7FFFFFFF);
          if ( COERCE_FLOAT(LODWORD(m_camera_offset_view) & 0x7FFFFFFF) >= *(float *)&clear_value )
          {
            vostok::render::frac_2(m_camera_offset_view);
            this->m_camera_offset_view = v20 - m_camera_offset_view;
          }
        }
      }
      else
      {
        vostok::render::frac_2(m_camera_offset_view);
        this->m_camera_offset_view = m_camera_offset_view;
      }
      if ( v16 > 0.0 )
      {
        v73.m_object = (vostok::render::res_texture *)(LODWORD(v16) & 0x7FFFFFFF);
        v21 = sqrtf((float)(v75 * v75) + (float)(*(float *)&num_cones * *(float *)&num_cones));
        v16 = abs_ov_dot_dir_ground2;
        v20 = *(float *)&clear_value;
        this->m_camera_offset_right = v21 * *(float *)&v73.m_object * 0.5 + this->m_camera_offset_right;
      }
      if ( v16 < 0.0 )
      {
        v73.m_object = (vostok::render::res_texture *)(LODWORD(v16) & 0x7FFFFFFF);
        v22 = sqrtf((float)(v75 * v75) + (float)(*(float *)&num_cones * *(float *)&num_cones));
        v20 = *(float *)&clear_value;
        this->m_camera_offset_right = this->m_camera_offset_right - v22 * *(float *)&v73.m_object * 0.5;
      }
      m_camera_offset_right = this->m_camera_offset_right;
      if ( m_camera_offset_right < v20 )
      {
        if ( m_camera_offset_right < 0.0 )
        {
          v73.m_object = (vostok::render::res_texture *)(LODWORD(m_camera_offset_right) & 0x7FFFFFFF);
          if ( COERCE_FLOAT(LODWORD(m_camera_offset_right) & 0x7FFFFFFF) >= v20 )
          {
            vostok::render::frac_2(m_camera_offset_right);
            this->m_camera_offset_right = v20 - m_camera_offset_right;
          }
        }
      }
      else
      {
        vostok::render::frac_2(m_camera_offset_right);
        this->m_camera_offset_right = m_camera_offset_right;
      }
      v24.m_object = (vostok::render::res_texture *)v11->m_scene_view.m_object;
      Height = v24.m_object[2].m_desc.Height;
      rain_angle_x = *(float *)&v24.m_object[1].m_name.m_string.m_begin;
      rain_angle_y = *(float *)&v24.m_object[1].m_name.m_string.m_end;
      rain_density = *(float *)&v24.m_object[1].m_name.m_string.m_max_end;
      offset_direction_ground.x = *(float *)v24.m_object[1].m_name.m_string.m_buffer;
      rain_uv_scales = *(vostok::math::float2 *)&v24.m_object[2].m_desc.MipLevels;
      v26 = v20;
      v73.m_object = v24.m_object;
      abs_ov_dot_dir_ground2 = v20;
      num_cones = Height;
      if ( s_rain_debug2 )
      {
        BindFlags = v24.m_object[2].m_desc.BindFlags;
        if ( BindFlags < Height )
        {
          while ( 1 )
          {
            cone_scale = (float)BindFlags;
            if ( BindFlags != 1 )
              v20 = retry_to_increase_quality_period_sec;
            v28 = this->m_camera_offset_view;
            v82 = *(float *)&v24.m_object[2].m_desc.SampleDesc.Count;
            v29 = (float *)this->m_context;
            v81 = *(float *)&v24.m_object[2].m_desc.SampleDesc.Quality;
            v29 += 4225;
            v30 = this->m_camera_offset_right * 0.0;
            v31 = *v29 - (float)(v28 * view_dir_2d.x);
            v32 = v29[1] - (float)(v28 * 0.0);
            v33 = v29[2];
            m_rain_offsets = this->m_rain_offsets;
            v35 = this->m_camera_offset_right;
            position.x = v31 - (float)(v35 * right_dir_2d.x);
            position.y = v32 - v30;
            position.z = (float)(v33 - (float)(v28 * view_dir_2d.y)) - (float)(v35 * right_dir_2d.y);
            scale.x = (float)(v20 * cone_scale) * v26;
            scale.y = scale.x * 10.0;
            scale.z = scale.x;
            p_x = &m_rain_offsets[BindFlags].x;
            _Xa = vostok::math::create_translation(&result, &position);
            v37 = sinf(this->m_rain_rotation_y[BindFlags]);
            *(float *)&v64 = v37 * v82 + p_x[1] * v81 + rain_angle_y;
            rotation_z = vostok::math::create_rotation_z((int)v102, v64);
            v38 = cosf(this->m_rain_rotation_x[BindFlags]);
            *(float *)&v65 = v38 * v82 + v81 * *p_x + rain_angle_x;
            rotation_x = vostok::math::create_rotation_x(v101, v65);
            range = vostok::math::random32::random_f(&r, 1.0) * 6.2831855;
            rangea = vostok::math::create_rotation_y(v96, (vostok::math::float4x4 *)LODWORD(range));
            v39 = vostok::math::create_scale(&scale, (int)v97);
            v40 = vostok::math::operator*(&v98, v39, rangea);
            v41 = vostok::math::operator*(&v100, v40, rotation_x);
            v42 = vostok::math::operator*(&v94, v41, rotation_z);
            vostok::math::operator*(&cone_transform, v42, _Xa);
            vostok::render::res_effect::apply(0, &this->m_rain_effect.m_object->__vftable);
            vostok::render::renderer_context::set_w(this->m_context, &cone_transform);
            m_radius_parameter = this->m_radius_parameter;
            v44 = (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
            v45 = m_radius_parameter->m_update_markers[1];
            *(float *)src_ptr = cone_scale * abs_ov_dot_dir_ground2;
            if ( v45 == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                        + 573) )
            {
              m_buffer_index = m_radius_parameter->m_shader_slots[1].m_buffer_index;
              if ( m_buffer_index != 0xFFFF )
                vostok::render::shader_constant_buffer::set_memory(
                  m_radius_parameter->m_shader_slots[1].m_slot_index,
                  (unsigned __int8)m_radius_parameter->m_shader_slots[1].m_class_id,
                  *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                           + 371)
                                                                         + 16)
                                                             + 4 * m_buffer_index),
                  src_ptr);
            }
            ++v44->num_setted_shader_constants;
            m_rain_speed_parameter = this->m_rain_speed_parameter;
            if ( m_rain_speed_parameter->m_update_markers[1] == v44->m_constant_update_markers[1] )
            {
              v48 = m_rain_speed_parameter->m_shader_slots[1].m_buffer_index;
              if ( v48 != 0xFFFF )
                vostok::render::shader_constant_buffer::set_memory(
                  m_rain_speed_parameter->m_shader_slots[1].m_slot_index,
                  (unsigned __int8)m_rain_speed_parameter->m_shader_slots[1].m_class_id,
                  v44->m_ps_constants_handler.m_current.m_object->m_const_buffers._M_impl._M_start[v48].m_object,
                  (const char *)&offset_direction_ground);
            }
            ++v44->num_setted_shader_constants;
            m_rain_density_parameter = this->m_rain_density_parameter;
            if ( m_rain_density_parameter->m_update_markers[1] == v44->m_constant_update_markers[1] )
            {
              v50 = m_rain_density_parameter->m_shader_slots[1].m_buffer_index;
              if ( v50 != 0xFFFF )
                vostok::render::shader_constant_buffer::set_memory(
                  m_rain_density_parameter->m_shader_slots[1].m_slot_index,
                  (unsigned __int8)m_rain_density_parameter->m_shader_slots[1].m_class_id,
                  v44->m_ps_constants_handler.m_current.m_object->m_const_buffers._M_impl._M_start[v50].m_object,
                  (const char *)&rain_density);
            }
            ++v44->num_setted_shader_constants;
            m_rain_uv_scales_parameter = this->m_rain_uv_scales_parameter;
            if ( m_rain_uv_scales_parameter->m_update_markers[1] == v44->m_constant_update_markers[1] )
            {
              v52 = m_rain_uv_scales_parameter->m_shader_slots[1].m_buffer_index;
              if ( v52 != 0xFFFF )
                vostok::render::shader_constant_buffer::set_memory(
                  m_rain_uv_scales_parameter->m_shader_slots[1].m_slot_index,
                  (unsigned __int8)m_rain_uv_scales_parameter->m_shader_slots[1].m_class_id,
                  v44->m_ps_constants_handler.m_current.m_object->m_const_buffers._M_impl._M_start[v52].m_object,
                  (const char *)&rain_uv_scales);
            }
            ++v44->num_setted_shader_constants;
            v53 = (const vostok::math::float3 *)vostok::math::transpose(&v94, &view_to_shadow);
            vostok::render::backend::set_ps_constant<vostok::math::float4x4>(v44, v53, this->m_view_to_shadow_parameter);
            vostok::render::sphere_geometry::draw(&this->m_rain_geometry);
            v54 = v73.m_object;
            this->m_rain_rotation_x[BindFlags] = (float)(this->m_context->m_time_delta
                                                       * *(float *)&v73.m_object[2].m_desc.Format)
                                               + this->m_rain_rotation_x[BindFlags];
            this->m_rain_rotation_y[BindFlags] = (float)(this->m_context->m_time_delta * *(float *)&v54[2].m_desc.Format)
                                               + this->m_rain_rotation_y[BindFlags];
            v26 = *(float *)&v54[2].m_desc.Usage * abs_ov_dot_dir_ground2;
            ++BindFlags;
            abs_ov_dot_dir_ground2 = v26;
            if ( BindFlags >= num_cones )
              break;
            v20 = *(float *)&clear_value;
            v24.m_object = v54;
          }
        }
      }
      v55 = this->m_context;
      *(_QWORD *)&this->m_previous_view_position.x = *(_QWORD *)&v55->m_view_pos.x;
      this->m_previous_view_position.z = v55->m_view_pos.z;
      v56 = vostok::math::float4x4::identity(&v94);
      vostok::render::renderer_context::set_w(v55, v56);
      v57 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      vostok::render::backend::reset_render_targets(
        v58,
        (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
      v59 = *((_DWORD *)v57 + 547);
      v60 = *((_DWORD *)v57 + 539) == v59;
      *((_DWORD *)v57 + 539) = v59;
      LOBYTE(v61) = !v60;
      *((_BYTE *)v57 + 167) |= !v60;
      vostok::render::vector<vostok::render::render_surface_instance *>::~vector<vostok::render::render_surface_instance *>(
        v61,
        (void **)&m_caster_model._M_impl._M_start);
    }
    else
    {
      this->execute_disabled(this);
    }
  }
}
