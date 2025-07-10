void __thiscall vostok::render::stage_clouds::execute(vostok::render::stage_clouds *this)
{
  vostok::render::scene *m_scene; // eax
  vostok::render::clouds *m_clouds; // ecx
  vostok::render::stage_clouds *v4; // ecx
  vostok::render::renderer_context *m_context; // edx
  vostok::render::clouds *v6; // eax
  float m_interp_alpha; // xmm2_4
  survarium::game_action_id *M_start; // esi
  unsigned int v9; // xmm2_4
  float v10; // xmm0_4
  const vostok::math::float4x4 *v11; // eax
  float v12; // xmm0_4
  float v13; // xmm2_4
  const vostok::math::float4x4 *v14; // eax
  vostok::render::renderer_context *v15; // edx
  vostok::render::render_target *m_object; // eax
  vostok::render::resource_manager *v17; // ecx
  ID3D11RenderTargetView *m_rt; // edx
  const char *m_conflicted_key_name; // eax
  bool v20; // zf
  vostok::render::render_target *v21; // eax
  vostok::render::renderer_context *v22; // edx
  vostok::render::render_target *v23; // eax
  ID3D11RenderTargetView *v24; // ebx
  char *v25; // ecx
  int v26; // eax
  vostok::render::renderer_context *v27; // eax
  vostok::render::renderer_context *v28; // ebx
  float v29; // xmm3_4
  float v30; // xmm1_4
  float v31; // xmm0_4
  float v32; // xmm0_4
  survarium::game_action_id *v33; // esi
  float v34; // xmm0_4
  char v35; // bl
  float v36; // xmm1_4
  float v37; // xmm2_4
  float v38; // edx
  float v39; // xmm0_4
  long double v40; // st7
  long double v41; // st7
  float m_clouds_scale_multiplier; // xmm0_4
  float v43; // xmm2_4
  float v44; // xmm3_4
  float m_camera_offset; // xmm0_4
  const vostok::math::float4x4 *v46; // xmm2_4
  int v47; // ebx
  int v48; // xmm1_4
  vostok::render::cloud_simulation *m_simulation; // eax
  float v50; // xmm0_4
  vostok::render::lights_db *v51; // ecx
  const vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *p_light; // eax
  vostok::render::light *v53; // esi
  vostok::render::renderer_context *v54; // eax
  vostok::render::renderer_context *v55; // ecx
  vostok::render::res_effect *v56; // eax
  int v57; // ecx
  float v58; // xmm1_4
  float v59; // xmm2_4
  int v60; // ecx
  vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v61; // xmm0_4
  const vostok::math::float4x4 *translation; // eax
  const vostok::math::float3 *v63; // eax
  const char *v64; // esi
  signed int m_clouds_size_y; // ecx
  double v66; // st7
  signed int m_clouds_size_z; // edx
  double v68; // st7
  vostok::render::shader_constant_host *m_c_clouds_grid_size; // eax
  int m_buffer_index; // ecx
  vostok::render::shader_constant_host *m_c_clouds_offset; // eax
  unsigned int v72; // edx
  int v73; // ecx
  vostok::render::shader_constant_host *m_c_interp_alpha; // eax
  int v75; // ecx
  vostok::render::shader_constant_host *m_c_layer_height; // eax
  int v77; // ecx
  vostok::render::shader_constant_host *m_c_cloud_base; // eax
  int v79; // ecx
  vostok::render::shader_constant_host *m_c_light_multiplier_parameters; // eax
  int v81; // ecx
  vostok::render::shader_constant_host *m_to_sun_direction_parameter; // eax
  int v83; // ecx
  const vostok::math::float4x4 *v84; // edx
  const vostok::math::float3 *v85; // eax
  char v86; // al
  const char *v87; // ecx
  vostok::render::res_effect *v88; // eax
  int v89; // ecx
  const vostok::math::float4x4 *v90; // eax
  const vostok::math::float3 *v91; // eax
  const char *v92; // esi
  vostok::render::constants_handler<1> *v93; // edi
  vostok::render::shader_constant_host *v94; // eax
  vostok::render::textures_handler<0> *v95; // ecx
  vostok::render::shader_constant_host *v96; // eax
  char v97; // al
  const char *v98; // ecx
  vostok::render::shader_constant_host *v99; // eax
  const char *v100; // esi
  int v101; // ecx
  vostok::render::renderer_context *v102; // esi
  const char *v103; // eax
  vostok::render::backend *v104; // ecx
  vostok::render::res_texture *v105; // ecx
  vostok::render::cloud_interp_textures *m_interp_textures; // edx
  vostok::render::res_texture *v107; // eax
  const vostok::render::res_texture *v108; // esi
  vostok::render::res_texture *v109; // edx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *p_cloud_density_1; // eax
  vostok::render::res_texture *v111; // ecx
  const vostok::render::res_texture *v112; // esi
  float v113; // [esp+Ch] [ebp-228h]
  unsigned int v114; // [esp+Ch] [ebp-228h]
  float abs_ov_dot_dir_grounda; // [esp+20h] [ebp-214h]
  float abs_ov_dot_dir_ground; // [esp+20h] [ebp-214h]
  const vostok::render::render_target *i; // [esp+24h] [ebp-210h]
  float ib; // [esp+24h] [ebp-210h]
  int ic; // [esp+24h] [ebp-210h]
  int ia; // [esp+24h] [ebp-210h]
  vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> scale; // [esp+28h] [ebp-20Ch] BYREF
  float z; // [esp+2Ch] [ebp-208h]
  vostok::math::float3 position; // [esp+30h] [ebp-204h] BYREF
  vostok::math::float3 to_sun_direction; // [esp+3Ch] [ebp-1F8h] BYREF
  vostok::math::float2 offset_vector_ground; // [esp+48h] [ebp-1ECh] BYREF
  vostok::math::float2 view_dir_2d; // [esp+50h] [ebp-1E4h] BYREF
  float interp_alpha; // [esp+58h] [ebp-1DCh] BYREF
  vostok::math::float2 offset_direction_ground; // [esp+5Ch] [ebp-1D8h] BYREF
  vostok::math::float3_pod object; // [esp+64h] [ebp-1D0h] BYREF
  float cloud_base; // [esp+70h] [ebp-1C4h] BYREF
  char v131[4]; // [esp+74h] [ebp-1C0h] BYREF
  float v132; // [esp+78h] [ebp-1BCh]
  float v133; // [esp+7Ch] [ebp-1B8h]
  char src_ptr[4]; // [esp+80h] [ebp-1B4h] BYREF
  float v135; // [esp+84h] [ebp-1B0h]
  float v136; // [esp+88h] [ebp-1ACh]
  char v137[4]; // [esp+8Ch] [ebp-1A8h] BYREF
  float indirect_light; // [esp+90h] [ebp-1A4h]
  float ambient; // [esp+94h] [ebp-1A0h]
  int v140; // [esp+98h] [ebp-19Ch]
  vostok::math::float4x4 dst; // [esp+9Ch] [ebp-198h] BYREF
  vostok::render::cloud_key_parameters interp_key; // [esp+DCh] [ebp-158h] BYREF
  vostok::math::float4x4 proj_matrix; // [esp+124h] [ebp-110h] BYREF
  vostok::math::float3 horizont_down_offset; // [esp+168h] [ebp-CCh]
  vostok::math::float4x4 world_matrix; // [esp+174h] [ebp-C0h] BYREF
  vostok::math::float4x4 world_to_god_rays_matrix; // [esp+1B4h] [ebp-80h] BYREF
  vostok::math::float4x4 sphere_to_clouds_matrix; // [esp+1F4h] [ebp-40h] BYREF

  if ( this->m_clouds_effect.m_object && this->m_read_cloud_base_effect.m_object && this->m_god_rays_effect.m_object )
  {
    if ( !this->is_enabled(this) )
    {
      this->execute_disabled(this);
      return;
    }
    m_scene = this->m_context->m_scene;
    if ( m_scene->m_clouds )
    {
      if ( m_scene )
      {
        m_clouds = m_scene->m_clouds;
        if ( m_clouds->m_is_updated )
        {
          vostok::render::stage_clouds::fill_cloud_texture((vostok::render::stage_clouds *)m_clouds, this, 0);
          vostok::render::stage_clouds::fill_cloud_texture(v4, this, 1u);
        }
      }
      m_context = this->m_context;
      this->m_fixed_time = 0.0;
      v6 = m_context->m_scene->m_clouds;
      m_interp_alpha = v6->m_interp_alpha;
      qmemcpy(&interp_key, &v6->m_interp_key, sizeof(interp_key));
      M_start = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start;
      interp_alpha = m_interp_alpha;
      *(float *)&v9 = *((float *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                      + 13)
                    * interp_key.cloud_base;
      position.x = 0.0;
      cloud_base = interp_key.cloud_base;
      *(_QWORD *)&position.elements[1] = v9;
      v10 = (float)(interp_key.layer_height * 1000.0)
          * *((float *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
            + 13);
      to_sun_direction.x = *((float *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                           + 13)
                         * 60000.0;
      to_sun_direction.y = v10;
      to_sun_direction.z = to_sun_direction.x;
      memset((int)&dst, 0, sizeof(dst));
      dst.j.y = v10;
      dst.i.x = to_sun_direction.x;
      dst.k.z = to_sun_direction.x;
      LODWORD(dst.c.w) = clear_value;
      v11 = vostok::math::create_translation(&world_to_god_rays_matrix, &position);
      vostok::math::mul4x3(&proj_matrix, &dst, v11);
      vostok::math::try_invert4x4(&proj_matrix, &sphere_to_clouds_matrix);
      memset(&position, 0, sizeof(position));
      v12 = interp_key.cloud_base * 2.0;
      if ( (float)(interp_key.cloud_base * 2.0) <= 0.0099999998 )
        v12 = 0.0099999998;
      v13 = *((float *)M_start + 13);
      to_sun_direction.x = v13 * 60000.0;
      to_sun_direction.y = v12 * v13;
      to_sun_direction.z = v13 * 60000.0;
      memset((int)&dst, 0, sizeof(dst));
      dst.j.y = v12 * v13;
      dst.i.x = v13 * 60000.0;
      dst.k.z = v13 * 60000.0;
      LODWORD(dst.c.w) = clear_value;
      v14 = vostok::math::create_translation(&world_matrix, &position);
      vostok::math::mul4x3(&proj_matrix, &dst, v14);
      vostok::math::try_invert4x4(&proj_matrix, &world_to_god_rays_matrix);
      v15 = this->m_context;
      m_object = v15->m_targets->m_family[48].target.m_object;
      v17 = 0;
      if ( m_object )
      {
        v17 = (vostok::render::resource_manager *)v15->m_targets->m_family[48].target.m_object;
        ++m_object->m_reference_count;
        m_rt = m_object->m_rt;
      }
      else
      {
        m_rt = 0;
      }
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
      if ( v17 )
      {
        v20 = v17->sh_created-- == 1;
        if ( v20 )
        {
          vostok::render::resource_manager::release(
            v17,
            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            (const char *)v17);
          m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        }
      }
      vostok::render::backend::clear_render_targets(
        (vostok::render::backend *)v17,
        (int)m_conflicted_key_name,
        0.0,
        0.0,
        0.0,
        0.0,
        v113);
      v21 = this->m_context->m_targets->m_family[48].target.m_object;
      i = 0;
      if ( v21 )
      {
        ++v21->m_reference_count;
        i = v21;
      }
      v22 = this->m_context;
      v23 = v22->m_targets->m_family[47].target.m_object;
      v24 = 0;
      if ( v23 )
      {
        v24 = (ID3D11RenderTargetView *)v22->m_targets->m_family[47].target.m_object;
        ++v23->m_reference_count;
      }
      vostok::render::backend::set_render_targets(
        v24,
        i,
        0,
        0,
        (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
      if ( v24 )
      {
        v20 = v24->lpVtbl-- == (ID3D11RenderTargetView_vtbl *)1;
        if ( v20 )
          vostok::render::resource_manager::release(
            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            (const char *)v24);
      }
      v25 = (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      if ( i )
      {
        v20 = i->m_reference_count-- == 1;
        if ( v20 )
        {
          vostok::render::resource_manager::release(
            (vostok::render::resource_manager *)v25,
            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            (const char *)i);
          v25 = (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        }
      }
      v26 = *((_DWORD *)v25 + 547);
      v20 = *((_DWORD *)v25 + 539) == v26;
      *((_DWORD *)v25 + 539) = v26;
      v25[167] |= !v20;
      if ( s_first_pass )
      {
        v27 = this->m_context;
        *(_QWORD *)&this->m_previous_view_position.x = *(_QWORD *)&v27->m_view_pos.x;
        this->m_previous_view_position.z = v27->m_view_pos.z;
        s_first_pass = 0;
      }
      v28 = this->m_context;
      offset_vector_ground = 0;
      scale.m_object = (vostok::render::light *)LODWORD(v28->m_view_dir.x);
      z = v28->m_view_dir.z;
      vostok::math::normalize_safe((const vostok::math::float2_pod *)&scale, &view_dir_2d, &offset_vector_ground);
      v29 = this->m_previous_view_position.z;
      v30 = v28->m_view_pos.z;
      offset_vector_ground.x = v28->m_view_pos.x - this->m_previous_view_position.x;
      offset_vector_ground.y = v30 - v29;
      *(float *)&scale.m_object = 0.0;
      z = 0.0;
      vostok::math::normalize_safe(&offset_vector_ground, &offset_direction_ground, (vostok::math::float2 *)&scale);
      v31 = (float)(view_dir_2d.y * offset_direction_ground.y) + (float)(view_dir_2d.x * offset_direction_ground.x);
      if ( v31 > 0.0 )
      {
        ib = fabs((float)(view_dir_2d.y * offset_direction_ground.y) + (float)(view_dir_2d.x * offset_direction_ground.x));
        v31 = (float)(view_dir_2d.y * offset_direction_ground.y) + (float)(view_dir_2d.x * offset_direction_ground.x);
        this->m_camera_offset = sqrtf(
                                  (float)(offset_vector_ground.y * offset_vector_ground.y)
                                + (float)(offset_vector_ground.x * offset_vector_ground.x))
                              / this->m_clouds_scale_multiplier
                              * ib
                              + this->m_camera_offset;
      }
      if ( v31 < 0.0 )
        this->m_camera_offset = this->m_camera_offset
                              - sqrtf(
                                  (float)(offset_vector_ground.y * offset_vector_ground.y)
                                + (float)(offset_vector_ground.x * offset_vector_ground.x))
                              / this->m_clouds_scale_multiplier
                              * COERCE_FLOAT(LODWORD(v31) & 0x7FFFFFFF);
      *(_QWORD *)&this->m_previous_view_position.x = *(_QWORD *)&v28->m_view_pos.x;
      this->m_previous_view_position.z = v28->m_view_pos.z;
      *(_QWORD *)&object.x = LODWORD(v28->m_view_dir.x);
      v32 = v28->m_view_dir.z;
      memset(&position, 0, sizeof(position));
      object.z = v32;
      vostok::math::normalize_safe(&object, &to_sun_direction, &position);
      v33 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start;
      if ( *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
           + 285) )
      {
        v34 = (float)((float)(this->m_wind_direction.y * to_sun_direction.y)
                    + (float)(this->m_wind_direction.z * to_sun_direction.z))
            + (float)(to_sun_direction.x * this->m_wind_direction.x);
        if ( fabs(v34) > 0.0 )
        {
          if ( v34 <= 0.0 )
          {
            if ( v34 >= 0.0 )
              v35 = 0;
            else
              v35 = -1;
          }
          else
          {
            v35 = 1;
          }
          v36 = this->m_wind_direction.y * 0.0125;
          v37 = this->m_wind_direction.z * 0.0125;
          v38 = (float)((float)(this->m_wind_direction.y * to_sun_direction.y)
                      + (float)(this->m_wind_direction.z * to_sun_direction.z))
              + (float)(to_sun_direction.x * this->m_wind_direction.x);
          v39 = this->m_wind_direction.x * 0.0125;
          offset_direction_ground.x = this->m_wind_direction.z;
          ic = SLODWORD(this->m_wind_direction.y);
          abs_ov_dot_dir_grounda = this->m_wind_direction.x;
          scale.m_object = (vostok::render::light *)(LODWORD(v38) & 0x7FFFFFFF);
          view_dir_2d.x = sqrtf((float)((float)(v37 * v37) + (float)(v36 * v36)) + (float)(v39 * v39));
          v40 = sqrtf(
                  (float)((float)(abs_ov_dot_dir_grounda * abs_ov_dot_dir_grounda)
                        + (float)(*(float *)&ic * *(float *)&ic))
                + (float)(offset_direction_ground.x * offset_direction_ground.x));
          v41 = view_dir_2d.x / v40;
          LODWORD(view_dir_2d.x) = v35;
          this->m_camera_offset = v41 * (double)v35 * *(float *)&scale.m_object * interp_key.wind_speed
                                + this->m_camera_offset;
        }
        m_clouds_scale_multiplier = this->m_clouds_scale_multiplier;
        v43 = (float)((float)(this->m_wind_direction.y * (float)(interp_key.wind_speed * 0.0125))
                    * m_clouds_scale_multiplier)
            + this->m_wind_offset.y;
        v44 = (float)((float)(this->m_wind_direction.z * (float)(interp_key.wind_speed * 0.0125))
                    * m_clouds_scale_multiplier)
            + this->m_wind_offset.z;
        this->m_wind_offset.x = (float)((float)(this->m_wind_direction.x * (float)(interp_key.wind_speed * 0.0125))
                                      * m_clouds_scale_multiplier)
                              + this->m_wind_offset.x;
        this->m_wind_offset.y = v43;
        this->m_wind_offset.z = v44;
      }
      m_camera_offset = this->m_camera_offset;
      v46 = clear_value;
      v47 = *((_DWORD *)v33 + 26);
      if ( m_camera_offset < *(float *)&clear_value )
      {
        if ( m_camera_offset >= 0.0 )
          goto LABEL_57;
        scale.m_object = (vostok::render::light *)(LODWORD(m_camera_offset) & 0x7FFFFFFF);
        if ( COERCE_FLOAT(LODWORD(m_camera_offset) & 0x7FFFFFFF) < *(float *)&clear_value )
          goto LABEL_57;
        vostok::render::frac_3(m_camera_offset);
        v48 = (int)v46;
      }
      else
      {
        scale.m_object = (vostok::render::light *)(LODWORD(m_camera_offset) & 0x7FFFFFFF);
        v48 = LODWORD(m_camera_offset) & 0x7FFFFFFF;
        m_camera_offset = (float)(((int)m_camera_offset >> 31) ^ (((int)m_camera_offset >> 31) + (int)m_camera_offset));
      }
      this->m_camera_offset = *(float *)&v48 - m_camera_offset;
LABEL_57:
      m_simulation = this->m_simulation;
      *(_QWORD *)&m_simulation->cloud_offset.x = *(_QWORD *)&this->m_wind_offset.x;
      v50 = interp_alpha;
      m_simulation->cloud_offset.z = this->m_wind_offset.z;
      qmemcpy(
        (void *)&this->m_simulation->world_to_cloud,
        &sphere_to_clouds_matrix,
        sizeof(this->m_simulation->world_to_cloud));
      this->m_simulation->interp_alpha = v50;
      vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
        &this->m_3d_clouds_density_texture_left,
        &this->m_interp_textures->cloud_density_0.m_object);
      vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
        &this->m_3d_clouds_density_texture_right,
        &this->m_interp_textures->cloud_density_1.m_object);
      v51 = (vostok::render::lights_db *)this->m_context->m_scene;
      p_light = &v51[47].m_lights._M_impl._M_finish->light;
      to_sun_direction.x = 0.0;
      *(_QWORD *)&to_sun_direction.elements[1] = (unsigned int)clear_value;
      v53 = vostok::render::lights_db::get_sun(v51, p_light, &scale)->m_object;
      vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(&scale);
      if ( v53 )
      {
        position.x = -v53->direction.x;
        position.y = -v53->direction.y;
        position.z = -v53->direction.z;
        to_sun_direction = position;
      }
      v54 = this->m_context;
      qmemcpy((void *)&proj_matrix, &v54->m_p, sizeof(proj_matrix));
      proj_matrix.k.z = 1.0000001;
      proj_matrix.c.z = -1.0000001;
      vostok::render::renderer_context::push_set_p(
        (vostok::render::renderer_context *)&proj_matrix,
        (int)v54,
        (vostok::render::renderer_context *)&proj_matrix);
      ia = v47;
      if ( v47 > 0 )
      {
        scale.m_object = (vostok::render::light *)(LODWORD(interp_key.cloud_base) & 0x7FFFFFFF);
        horizont_down_offset.y = (float)(COERCE_FLOAT(LODWORD(interp_key.cloud_base) & 0x7FFFFFFF) * 0.0) * 1.25;
        vostok::math::max();
        view_dir_2d.x = FLOAT_0_5;
        *(float *)v137 = interp_key.direct_light;
        indirect_light = interp_key.indirect_light;
        ambient = interp_key.ambient;
        v140 = 0;
        do
        {
          v56 = this->m_clouds_effect.m_object;
          v57 = (char *)v56->m_techniques._M_impl._M_finish - (char *)v56->m_techniques._M_impl._M_start;
          v58 = this->m_clouds_scale_multiplier;
          v59 = this->m_camera_offset;
          offset_direction_ground.x = (float)ia;
          v60 = v57 >> 2;
          *(float *)&v61.m_object = (float)((float)ia * v58) - (float)(v59 * v58);
          scale.m_object = v61.m_object;
          if ( v60 )
          {
            v56->m_cur_technique = 0;
            vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v60, v114);
            v61.m_object = scale.m_object;
          }
          LODWORD(object.x) = (vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v61.m_object;
          LODWORD(object.elements[1]) = (vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v61.m_object;
          LODWORD(object.elements[2]) = (vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v61.m_object;
          memset((int)&dst, 0, sizeof(dst));
          LODWORD(dst.lines[1].elements[1]) = (vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v61.m_object;
          LODWORD(dst.i.x) = (vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v61.m_object;
          LODWORD(dst.lines[2].elements[2]) = (vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v61.m_object;
          LODWORD(dst.c.w) = clear_value;
          translation = vostok::math::create_translation(
                          (vostok::math::float4x4 *)&interp_key,
                          &this->m_previous_view_position);
          vostok::math::mul4x3(&world_matrix, &dst, translation);
          vostok::render::renderer_context::set_w(this->m_context, &world_matrix);
          v63 = (const vostok::math::float3 *)vostok::math::transpose(
                                                (vostok::math::float4x4 *)&interp_key,
                                                &sphere_to_clouds_matrix);
          v64 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
          vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
            this->m_c_sphere_to_sky_matrix,
            (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
          + 123,
            v63);
          ++*((_DWORD *)v64 + 23);
          m_clouds_size_y = this->m_clouds_size_y;
          *(float *)src_ptr = (float)this->m_clouds_size_x;
          v66 = (double)(int)this->m_clouds_size_y;
          if ( m_clouds_size_y < 0 )
            v66 = v66 + 4294967300.0;
          m_clouds_size_z = this->m_clouds_size_z;
          v135 = v66;
          v68 = (double)(int)this->m_clouds_size_z;
          if ( m_clouds_size_z < 0 )
            v68 = v68 + 4294967300.0;
          m_c_clouds_grid_size = this->m_c_clouds_grid_size;
          v136 = v68;
          if ( m_c_clouds_grid_size->m_update_markers[1] == *((_DWORD *)v64 + 573) )
          {
            m_buffer_index = m_c_clouds_grid_size->m_shader_slots[1].m_buffer_index;
            if ( m_buffer_index != 0xFFFF )
              vostok::render::shader_constant_buffer::set_memory(
                m_c_clouds_grid_size->m_shader_slots[1].m_slot_index,
                (unsigned __int8)m_c_clouds_grid_size->m_shader_slots[1].m_class_id,
                *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v64 + 371) + 16)
                                                           + 4 * m_buffer_index),
                src_ptr);
          }
          ++*((_DWORD *)v64 + 23);
          m_c_clouds_offset = this->m_c_clouds_offset;
          v72 = m_c_clouds_offset->m_update_markers[1];
          *(float *)v131 = this->m_wind_offset.x;
          v132 = this->m_wind_offset.y + horizont_down_offset.y;
          v133 = this->m_wind_offset.z;
          if ( v72 == *((_DWORD *)v64 + 573) )
          {
            v73 = m_c_clouds_offset->m_shader_slots[1].m_buffer_index;
            if ( v73 != 0xFFFF )
              vostok::render::shader_constant_buffer::set_memory(
                m_c_clouds_offset->m_shader_slots[1].m_slot_index,
                (unsigned __int8)m_c_clouds_offset->m_shader_slots[1].m_class_id,
                *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v64 + 371) + 16) + 4 * v73),
                v131);
          }
          ++*((_DWORD *)v64 + 23);
          m_c_interp_alpha = this->m_c_interp_alpha;
          if ( m_c_interp_alpha->m_update_markers[1] == *((_DWORD *)v64 + 573) )
          {
            v75 = m_c_interp_alpha->m_shader_slots[1].m_buffer_index;
            if ( v75 != 0xFFFF )
              vostok::render::shader_constant_buffer::set_memory(
                m_c_interp_alpha->m_shader_slots[1].m_slot_index,
                (unsigned __int8)m_c_interp_alpha->m_shader_slots[1].m_class_id,
                *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v64 + 371) + 16) + 4 * v75),
                (const char *)&interp_alpha);
          }
          ++*((_DWORD *)v64 + 23);
          m_c_layer_height = this->m_c_layer_height;
          if ( m_c_layer_height->m_update_markers[1] == *((_DWORD *)v64 + 573) )
          {
            v77 = m_c_layer_height->m_shader_slots[1].m_buffer_index;
            if ( v77 != 0xFFFF )
              vostok::render::shader_constant_buffer::set_memory(
                m_c_layer_height->m_shader_slots[1].m_slot_index,
                (unsigned __int8)m_c_layer_height->m_shader_slots[1].m_class_id,
                *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v64 + 371) + 16) + 4 * v77),
                (const char *)&view_dir_2d);
          }
          ++*((_DWORD *)v64 + 23);
          m_c_cloud_base = this->m_c_cloud_base;
          if ( m_c_cloud_base->m_update_markers[1] == *((_DWORD *)v64 + 573) )
          {
            v79 = m_c_cloud_base->m_shader_slots[1].m_buffer_index;
            if ( v79 != 0xFFFF )
              vostok::render::shader_constant_buffer::set_memory(
                m_c_cloud_base->m_shader_slots[1].m_slot_index,
                (unsigned __int8)m_c_cloud_base->m_shader_slots[1].m_class_id,
                *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v64 + 371) + 16) + 4 * v79),
                (const char *)&cloud_base);
          }
          ++*((_DWORD *)v64 + 23);
          m_c_light_multiplier_parameters = this->m_c_light_multiplier_parameters;
          if ( m_c_light_multiplier_parameters->m_update_markers[1] == *((_DWORD *)v64 + 573) )
          {
            v81 = m_c_light_multiplier_parameters->m_shader_slots[1].m_buffer_index;
            if ( v81 != 0xFFFF )
              vostok::render::shader_constant_buffer::set_memory(
                m_c_light_multiplier_parameters->m_shader_slots[1].m_slot_index,
                (unsigned __int8)m_c_light_multiplier_parameters->m_shader_slots[1].m_class_id,
                *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v64 + 371) + 16) + 4 * v81),
                v137);
          }
          ++*((_DWORD *)v64 + 23);
          m_to_sun_direction_parameter = this->m_to_sun_direction_parameter;
          if ( m_to_sun_direction_parameter->m_update_markers[1] == *((_DWORD *)v64 + 573) )
          {
            v83 = m_to_sun_direction_parameter->m_shader_slots[1].m_buffer_index;
            if ( v83 != 0xFFFF )
              vostok::render::shader_constant_buffer::set_memory(
                m_to_sun_direction_parameter->m_shader_slots[1].m_slot_index,
                (unsigned __int8)m_to_sun_direction_parameter->m_shader_slots[1].m_class_id,
                *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v64 + 371) + 16) + 4 * v83),
                (const char *)&to_sun_direction);
          }
          ++*((_DWORD *)v64 + 23);
          vostok::math::try_invert4x4(&this->m_context->m_vp, &world_matrix);
          v85 = (const vostok::math::float3 *)vostok::math::transpose((vostok::math::float4x4 *)&interp_key, v84);
          vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
            this->m_c_inverted_view_projection_matrix,
            (vostok::render::constants_handler<1> *)v64 + 123,
            v85);
          ++*((_DWORD *)v64 + 23);
          v86 = vostok::render::textures_handler<0>::set_overwrite(
                  (vostok::render::textures_handler<0> *)(v64 + 1488),
                  (char *)v64 + 1488,
                  (vostok::render::res_texture *)&stru_965008,
                  this->m_3d_clouds_density_texture_left.m_object);
          v87 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
          *((_BYTE *)v64 + 159) = v86;
          *((_BYTE *)v87 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                                    (vostok::render::textures_handler<0> *)(v87 + 1488),
                                    (char *)v87 + 1488,
                                    (vostok::render::res_texture *)&stru_965008.num_mips,
                                    this->m_3d_clouds_density_texture_right.m_object);
          vostok::render::sphere_geometry::draw(&this->m_evaluate_geometry);
          if ( *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
               + 287) )
          {
            v88 = this->m_god_rays_effect.m_object;
            v89 = v88->m_techniques._M_impl._M_finish - v88->m_techniques._M_impl._M_start;
            abs_ov_dot_dir_ground = (float)(offset_direction_ground.x * this->m_clouds_scale_multiplier)
                                  - (float)(this->m_camera_offset * this->m_clouds_scale_multiplier);
            if ( v89 )
            {
              v88->m_cur_technique = 0;
              vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v89, v114);
            }
            position.x = abs_ov_dot_dir_ground;
            position.y = abs_ov_dot_dir_ground;
            position.z = abs_ov_dot_dir_ground;
            memset((int)&proj_matrix, 0, sizeof(proj_matrix));
            proj_matrix.j.y = abs_ov_dot_dir_ground;
            proj_matrix.i.x = abs_ov_dot_dir_ground;
            proj_matrix.k.z = abs_ov_dot_dir_ground;
            LODWORD(proj_matrix.c.w) = clear_value;
            v90 = vostok::math::create_translation(
                    (vostok::math::float4x4 *)&interp_key,
                    &this->m_previous_view_position);
            vostok::math::mul4x3(&world_matrix, &proj_matrix, v90);
            vostok::render::renderer_context::set_w(this->m_context, &world_matrix);
            v91 = (const vostok::math::float3 *)vostok::math::transpose(
                                                  (vostok::math::float4x4 *)&interp_key,
                                                  &world_to_god_rays_matrix);
            v92 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
            v93 = (vostok::render::constants_handler<1> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                         + 1476);
            vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
              this->m_c_sphere_to_sky_matrix,
              (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
            + 123,
              v91);
            ++*((_DWORD *)v92 + 23);
            vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
              this->m_c_clouds_offset,
              v93,
              &this->m_wind_offset);
            ++*((_DWORD *)v92 + 23);
            v94 = this->m_c_interp_alpha;
            v95 = (vostok::render::textures_handler<0> *)v94->m_update_markers[1];
            if ( v95 == *((vostok::render::textures_handler<0> **)v92 + 573) )
            {
              v95 = (vostok::render::textures_handler<0> *)v94->m_shader_slots[1].m_buffer_index;
              if ( v95 != (vostok::render::textures_handler<0> *)0xFFFF )
                vostok::render::shader_constant_buffer::set_memory(
                  v94->m_shader_slots[1].m_slot_index,
                  (unsigned __int8)v94->m_shader_slots[1].m_class_id,
                  *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v92 + 371) + 16) + 4 * (_DWORD)v95),
                  (const char *)&interp_alpha);
            }
            ++*((_DWORD *)v92 + 23);
            v96 = this->m_c_cloud_base;
            if ( v96->m_update_markers[1] == *((_DWORD *)v92 + 573) )
            {
              v95 = (vostok::render::textures_handler<0> *)v96->m_shader_slots[1].m_buffer_index;
              if ( v95 != (vostok::render::textures_handler<0> *)0xFFFF )
                vostok::render::shader_constant_buffer::set_memory(
                  v96->m_shader_slots[1].m_slot_index,
                  (unsigned __int8)v96->m_shader_slots[1].m_class_id,
                  *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v92 + 371) + 16) + 4 * (_DWORD)v95),
                  (const char *)&cloud_base);
            }
            ++*((_DWORD *)v92 + 23);
            v97 = vostok::render::textures_handler<0>::set_overwrite(
                    v95,
                    (char *)v92 + 1488,
                    (vostok::render::res_texture *)&stru_965008,
                    this->m_3d_clouds_density_texture_left.m_object);
            v98 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
            *((_BYTE *)v92 + 159) = v97;
            *((_BYTE *)v98 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                                      (vostok::render::textures_handler<0> *)(v98 + 1488),
                                      (char *)v98 + 1488,
                                      (vostok::render::res_texture *)&stru_965008.num_mips,
                                      this->m_3d_clouds_density_texture_right.m_object);
            v99 = this->m_to_sun_direction_parameter;
            v100 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
            if ( v99->m_update_markers[1] == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                             + 573) )
            {
              v101 = v99->m_shader_slots[1].m_buffer_index;
              if ( v101 != 0xFFFF )
                vostok::render::shader_constant_buffer::set_memory(
                  v99->m_shader_slots[1].m_slot_index,
                  (unsigned __int8)v99->m_shader_slots[1].m_class_id,
                  *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                           + 371)
                                                                         + 16)
                                                             + 4 * v101),
                  (const char *)&to_sun_direction);
            }
            ++*((_DWORD *)v100 + 23);
            vostok::render::sphere_geometry::draw(&this->m_evaluate_geometry);
          }
          --ia;
        }
        while ( ia > 0 );
      }
      v102 = this->m_context;
      vostok::render::renderer_context::set_p(v55, (const vostok::math::float4x4 *)v102);
      v103 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      --v102->m_p_stack.m_end;
      vostok::render::backend::reset_render_targets(v104, (int)v103);
      v105 = this->m_3d_clouds_density_texture_left.m_object;
      m_interp_textures = this->m_interp_textures;
      v107 = 0;
      if ( v105 )
      {
        v107 = this->m_3d_clouds_density_texture_left.m_object;
        ++v105->m_reference_count;
      }
      v108 = m_interp_textures->cloud_density_0.m_object;
      m_interp_textures->cloud_density_0.m_object = v107;
      if ( v108 )
      {
        v20 = v108->m_reference_count-- == 1;
        if ( v20 )
          vostok::render::res_texture::destroy_impl(v105, v108);
      }
      v109 = this->m_3d_clouds_density_texture_right.m_object;
      p_cloud_density_1 = &this->m_interp_textures->cloud_density_1;
      v111 = 0;
      if ( v109 )
      {
        v111 = this->m_3d_clouds_density_texture_right.m_object;
        ++v109->m_reference_count;
      }
      v112 = p_cloud_density_1->m_object;
      p_cloud_density_1->m_object = v111;
      if ( v112 )
      {
        v20 = v112->m_reference_count-- == 1;
        if ( v20 )
          vostok::render::res_texture::destroy_impl(v111, v112);
      }
      this->m_fixed_time = this->m_fixed_time + 0.0125;
    }
  }
}
