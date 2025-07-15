void __thiscall vostok::render::stage_rain::execute(vostok::render::stage_rain *this)
{
  vostok::render::renderer_context *m_context; // ecx
  vostok::render::base_scene_view *m_object; // eax
  ID3D11DeviceContext *v4; // esi
  ID3D11Resource *m_surface; // edi
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *t; // eax
  vostok::render::resource_manager *v7; // ecx
  bool v8; // zf
  vostok::math::float4 *p_m_view_pos; // esi
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v10; // eax
  float z; // esi
  vostok::render::render_target *v12; // eax
  int v13; // edi
  vostok::render::renderer_context *v14; // eax
  float x; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm3_4
  float v18; // xmm2_4
  vostok::render::renderer_context *v19; // eax
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm2_4
  long double v23; // rdi
  float m_camera_offset_view; // xmm0_4
  double v25; // st7
  float v26; // eax
  float m_camera_offset_right; // xmm2_4
  float v28; // xmm0_4
  double v29; // st7
  vostok::render::base_scene_view *v30; // eax
  vostok::math::float4x4 *m_node; // ecx
  __m128i v32; // xmm3
  float *v33; // eax
  float v34; // xmm4_4
  float v35; // xmm5_4
  float v36; // xmm2_4
  float v37; // xmm6_4
  float v38; // xmm0_4
  float v39; // xmm2_4
  float v40; // xmm1_4
  vostok::math::float4x4 *v41; // eax
  long double v42; // rdi
  vostok::math::float2 *m_rain_offsets; // ecx
  __m128i v44; // xmm0
  vostok::math::float4x4 *v45; // eax
  __m128i v46; // xmm0
  vostok::math::float4x4 *v47; // eax
  vostok::math::float4x4 *v48; // eax
  vostok::render::res_effect *v49; // eax
  vostok::render::res_effect *v50; // ecx
  vostok::render::backend *v51; // ecx
  vostok::render::backend *v52; // ecx
  vostok::render::backend *v53; // ecx
  vostok::render::backend *v54; // ecx
  vostok::math::float4x4 *v55; // eax
  vostok::render::backend *v56; // ecx
  vostok::render::sky_dome_geometry *v57; // ecx
  vostok::render::res_texture *v58; // eax
  float v59; // edx
  vostok::render::renderer_context *v60; // ebx
  float v61; // edi
  vostok::math::float4x4 *v62; // eax
  float v63; // esi
  vostok::render::backend *v64; // ecx
  int v65; // ecx
  vostok::render::shader_constant_host *m_radius_parameter; // [esp+8h] [ebp-320h]
  _BYTE v67[12]; // [esp+Ch] [ebp-31Ch]
  float v68; // [esp+1Ch] [ebp-30Ch] BYREF
  vostok::render::render_target *rt; // [esp+20h] [ebp-308h] BYREF
  vostok::math::float2_pod v70; // [esp+24h] [ebp-304h] BYREF
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v71; // [esp+2Ch] [ebp-2FCh] BYREF
  vostok::math::float2_pod object; // [esp+30h] [ebp-2F8h] BYREF
  vostok::math::float2_pod result_in_case_of_zero; // [esp+38h] [ebp-2F0h] BYREF
  pix_event_wrapper_dx11 wszName; // [esp+43h] [ebp-2E5h] BYREF
  vostok::math::float3 wszName_1; // [esp+44h] [ebp-2E4h] BYREF
  float v76; // [esp+50h] [ebp-2D8h]
  const vostok::math::float4x4 *v77; // [esp+54h] [ebp-2D4h]
  float v78; // [esp+58h] [ebp-2D0h]
  vostok::math::float3 v79; // [esp+5Ch] [ebp-2CCh] BYREF
  float v80; // [esp+68h] [ebp-2C0h]
  vostok::math::float3 v81; // [esp+6Ch] [ebp-2BCh] BYREF
  vostok::math::random32 v82; // [esp+78h] [ebp-2B0h] BYREF
  vostok::math::float3 v83; // [esp+7Ch] [ebp-2ACh] BYREF
  float v84; // [esp+88h] [ebp-2A0h]
  int v85; // [esp+8Ch] [ebp-29Ch]
  vostok::math::float3 v86; // [esp+90h] [ebp-298h] BYREF
  float v87; // [esp+A4h] [ebp-284h]
  vostok::math::float4x4 v88; // [esp+A8h] [ebp-280h] BYREF
  vostok::math::float4x4 v89; // [esp+E8h] [ebp-240h] BYREF
  vostok::math::float4x4 v90; // [esp+128h] [ebp-200h] BYREF
  vostok::math::float4x4 v91; // [esp+168h] [ebp-1C0h] BYREF
  vostok::math::float4x4 v92; // [esp+1A8h] [ebp-180h] BYREF
  vostok::math::float4x4 v93; // [esp+1E8h] [ebp-140h] BYREF
  vostok::math::float4x4 v94; // [esp+228h] [ebp-100h] BYREF
  vostok::math::float4x4 v95; // [esp+268h] [ebp-C0h] BYREF
  vostok::math::float4x4 v96; // [esp+2A8h] [ebp-80h] BYREF
  vostok::math::float4x4 v97; // [esp+2E8h] [ebp-40h] BYREF

  pix_event_wrapper_dx11::pix_event_wrapper_dx11((pix_event_wrapper_dx11 *)this, &wszName, (int)L"stage_rain");
  if ( !this->is_effects_ready(this) )
    goto LABEL_47;
  if ( !this->is_enabled(this)
    || (m_context = this->m_context,
        m_object = m_context->m_scene_view.m_object,
        !LOBYTE(m_object[2].grm_satisfaction_tree_hook.left_))
    || *(float *)&m_object[2].m_fat_it.m_hashset < 0.0099999998
    || !vostok::quasi_singleton<vostok::render::options>::pinst->current.m_rain_stage
    || !byte_10E2C[(_DWORD)m_object]
    || m_object[4].type == 2 )
  {
    this->execute_disabled(this);
    goto LABEL_47;
  }
  v4 = vostok::quasi_singleton<vostok::render::device>::pinst->m_context;
  m_surface = vostok::render::renderer_context::get_t(m_context, rt_generic_0, &v71)->m_object->m_surface;
  t = vostok::render::renderer_context::get_t(
        this->m_context,
        rt_generic_1,
        (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt);
  v4->CopyResource(v4, t->m_object->m_surface, m_surface);
  if ( *(float *)&rt != 0.0 )
  {
    v8 = rt->m_name.m_pointer.m_object-- == (vostok::strings::shared::profile *)1;
    if ( v8 )
      vostok::render::resource_manager::release(
        v7,
        (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        (vostok::render::res_texture *)rt);
  }
  if ( v71.m_object )
  {
    v8 = v71.m_object->m_reference_count-- == 1;
    if ( v8 )
      vostok::render::resource_manager::release(
        v7,
        (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        v71.m_object);
  }
  if ( s_first_pass )
  {
    p_m_view_pos = &this->m_context->m_view_pos;
    this->m_previous_view_position.x = p_m_view_pos->x;
    p_m_view_pos = (vostok::math::float4 *)((char *)p_m_view_pos + 4);
    this->m_previous_view_position.y = p_m_view_pos->x;
    this->m_previous_view_position.z = p_m_view_pos->y;
    s_first_pass = 0;
  }
  qmemcpy(&v91, &this->m_renderer->m_view_to_rain_shadow, sizeof(v91));
  v10 = vostok::render::renderer_context::get_rt(
          this->m_context,
          rt_generic_0,
          (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt);
  z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  vostok::render::backend::set_render_targets(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    v10->m_object,
    0,
    0,
    0);
  v12 = rt;
  if ( *(float *)&rt != 0.0 )
  {
    --rt->m_reference_count;
    if ( !v12->m_reference_count )
    {
      vostok::render::resource_manager::release(rt, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
      z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    }
  }
  v13 = *(_DWORD *)(LODWORD(z) + 7440);
  v8 = *(_DWORD *)(LODWORD(z) + 7384) == v13;
  *(_DWORD *)(LODWORD(z) + 7384) = v13;
  *(_BYTE *)(LODWORD(z) + 117) |= !v8;
  v14 = this->m_context;
  result_in_case_of_zero = 0;
  x = v14->m_view_dir.x;
  qmemcpy(&v88, &v14->m_v, sizeof(v88));
  object.x = x;
  v16 = v14->m_view_dir.z;
  v82.m_seed = 1000;
  object.y = v16;
  vostok::math::normalize_safe(
    &object,
    (vostok::math::float2 *)&result_in_case_of_zero,
    (vostok::math::float2 *)&v79.elements[2]);
  object = 0;
  v70 = (vostok::math::float2_pod)__PAIR64__(LODWORD(v88.k.x), LODWORD(v88.i.x));
  vostok::math::normalize_safe(&v70, (vostok::math::float2 *)&object, (vostok::math::float2 *)&result_in_case_of_zero);
  v17 = this->m_previous_view_position.z;
  v18 = this->m_previous_view_position.x;
  LODWORD(object.x) = &this->m_previous_view_position;
  v19 = this->m_context;
  v20 = v19->m_view_pos.z;
  v70.x = v19->m_view_pos.x - v18;
  LODWORD(v23) = &v79;
  v70.y = v20 - v17;
  *(_QWORD *)&v79.x = 0;
  vostok::math::normalize_safe(&v70, (vostok::math::float2 *)&v79, (vostok::math::float2 *)&wszName_1);
  v21 = (float)(v80 * wszName_1.y) + (float)(v79.z * wszName_1.x);
  v22 = (float)(result_in_case_of_zero.y * wszName_1.y) + (float)(result_in_case_of_zero.x * wszName_1.x);
  *(float *)&rt = v22;
  HIDWORD(v23) = 0x7FFFFFFF;
  if ( v21 > 0.0 )
  {
    v68 = fabs((float)(v80 * wszName_1.y) + (float)(v79.z * wszName_1.x));
    this->m_camera_offset_view = (float)((float)(fsqrt((float)(v70.x * v70.x) + (float)(v70.y * v70.y)) * v68) * 0.5)
                               + this->m_camera_offset_view;
  }
  if ( v21 < 0.0 )
  {
    LODWORD(v68) = LODWORD(v21) & 0x7FFFFFFF;
    this->m_camera_offset_view = this->m_camera_offset_view
                               - (float)((float)(fsqrt((float)(v70.x * v70.x) + (float)(v70.y * v70.y))
                                               * COERCE_FLOAT(LODWORD(v21) & 0x7FFFFFFF))
                                       * 0.5);
  }
  m_camera_offset_view = this->m_camera_offset_view;
  if ( m_camera_offset_view >= s_bm_current_air_resistance )
  {
    *(_DWORD *)v67 = &v68;
    v68 = this->m_camera_offset_view;
    v25 = modf(m_camera_offset_view, *(double *)v67);
LABEL_28:
    v22 = *(float *)&rt;
    this->m_camera_offset_view = v25;
    goto LABEL_29;
  }
  if ( m_camera_offset_view < 0.0 )
  {
    LODWORD(v68) = LODWORD(m_camera_offset_view) & 0x7FFFFFFF;
    if ( COERCE_FLOAT(LODWORD(m_camera_offset_view) & 0x7FFFFFFF) >= s_bm_current_air_resistance )
    {
      *(_DWORD *)v67 = &v68;
      v68 = m_camera_offset_view;
      v25 = 1.0 - modf(m_camera_offset_view, *(double *)v67);
      goto LABEL_28;
    }
  }
LABEL_29:
  if ( v22 > 0.0 )
  {
    LODWORD(v68) = LODWORD(v22) & 0x7FFFFFFF;
    this->m_camera_offset_right = (float)((float)(fsqrt((float)(v70.x * v70.x) + (float)(v70.y * v70.y))
                                                * COERCE_FLOAT(LODWORD(v22) & 0x7FFFFFFF))
                                        * 0.5)
                                + this->m_camera_offset_right;
  }
  if ( v22 < 0.0 )
  {
    v68 = v22;
    v26 = v22;
    m_camera_offset_right = this->m_camera_offset_right;
    LODWORD(v68) = LODWORD(v26) & 0x7FFFFFFF;
    this->m_camera_offset_right = m_camera_offset_right
                                - (float)((float)(fsqrt((float)(v70.x * v70.x) + (float)(v70.y * v70.y))
                                                * COERCE_FLOAT(LODWORD(v26) & 0x7FFFFFFF))
                                        * 0.5);
  }
  v28 = this->m_camera_offset_right;
  if ( v28 < s_bm_current_air_resistance )
  {
    if ( v28 >= 0.0 )
      goto LABEL_39;
    LODWORD(v68) = LODWORD(v28) & 0x7FFFFFFF;
    if ( COERCE_FLOAT(LODWORD(v28) & 0x7FFFFFFF) < s_bm_current_air_resistance )
      goto LABEL_39;
    *(_DWORD *)v67 = &v68;
    v68 = v28;
    v29 = 1.0 - modf(v28, *(double *)v67);
  }
  else
  {
    *(_DWORD *)v67 = &v68;
    v68 = this->m_camera_offset_right;
    v29 = modf(v28, *(double *)v67);
  }
  this->m_camera_offset_right = v29;
LABEL_39:
  v30 = this->m_context->m_scene_view.m_object;
  m_node = (vostok::math::float4x4 *)v30[2].m_fat_it.m_node;
  LODWORD(v81.z) = v30[2].grm_satisfaction_tree_hook.color_;
  LODWORD(v81.y) = v30[2].m_next_in_memory_type;
  LODWORD(wszName_1.x) = v30[2].m_fat_it.m_hashset;
  LODWORD(v79.x) = v30[2].m_prev_in_memory_type;
  *(_QWORD *)&v83.x = *(_QWORD *)&v30[2].m_fat_it.m_link_target;
  v68 = *(float *)&v30;
  *(float *)&rt = s_bm_current_air_resistance;
  LODWORD(v70.x) = m_node;
  if ( s_rain_debug2 )
  {
    v71.m_object = (vostok::render::res_texture *)v30[2].m_creation_source;
    if ( v71.m_object < (vostok::render::res_texture *)m_node )
    {
      do
      {
        wszName_1.z = (float)(unsigned int)v71.m_object;
        if ( v71.m_object == (vostok::render::res_texture *)1 )
          v32 = (__m128i)LODWORD(s_bm_current_air_resistance);
        else
          v32 = (__m128i)LODWORD(retry_to_increase_quality_period_sec);
        v33 = (float *)this->m_context;
        *(float *)v32.m128i_i32 = (float)(*(float *)v32.m128i_i32 * wszName_1.z) * *(float *)&rt;
        v34 = this->m_camera_offset_right * result_in_case_of_zero.x;
        v35 = this->m_camera_offset_right;
        v36 = this->m_camera_offset_view * v79.z;
        v37 = this->m_camera_offset_view;
        v87 = v37 * v80;
        v33 += 5283;
        v38 = *v33 - v36;
        v39 = v33[2] - (float)(v37 * v80);
        v40 = v33[1];
        v86.x = v38 - v34;
        v86.y = (float)(v40 - (float)(v37 * 0.0)) - (float)(v35 * 0.0);
        v86.z = v39 - (float)(v35 * result_in_case_of_zero.y);
        LODWORD(v83.z) = v32.m128i_i32[0];
        v84 = *(float *)v32.m128i_i32 * 10.0;
        v85 = v32.m128i_i32[0];
        *(float *)v67 = vostok::math::random32::random_f(&v82, 1.0) * 6.2831855;
        v77 = vostok::math::create_rotation_y(v23, v32, &v97, *(float *)v67);
        v41 = vostok::math::create_scale((vostok::math::float3 *)&v83.elements[2], &v94);
        vostok::math::mul4x3(v77, v41, &v88);
        LODWORD(v42) = v71;
        m_rain_offsets = this->m_rain_offsets;
        v78 = *(float *)(LODWORD(v68) + 740);
        v76 = *(float *)(LODWORD(v68) + 744);
        HIDWORD(v42) = &m_rain_offsets[(int)v71.m_object];
        v44 = (__m128i)_mm_cvtps_pd((__m128)LODWORD(this->m_rain_rotation_x[(int)v71.m_object]));
        __libm_sse2_cos(*(long double *)&v67[4]);
        *(float *)v44.m128i_i32 = *(double *)v44.m128i_i64;
        *(float *)v44.m128i_i32 = (float)((float)(*(float *)v44.m128i_i32 * v78) + (float)(*(float *)HIDWORD(v42) * v76))
                                + v81.z;
        v45 = vostok::math::create_rotation_x(v42, v44, &v96, *(float *)v44.m128i_i32);
        vostok::math::mul4x3(v45, &v88, &v93);
        v46 = (__m128i)_mm_cvtps_pd((__m128)LODWORD(this->m_rain_rotation_y[LODWORD(v42)]));
        __libm_sse2_sin(v46);
        *(float *)v46.m128i_i32 = *(double *)v46.m128i_i64;
        *(float *)v46.m128i_i32 = (float)((float)(*(float *)v46.m128i_i32 * v78)
                                        + (float)(*(float *)(HIDWORD(v42) + 4) * v76))
                                + v81.y;
        v47 = vostok::math::create_rotation_z(v42, v46, &v95, *(float *)v46.m128i_i32);
        vostok::math::mul4x3(v47, &v93, &v92);
        v48 = vostok::math::create_translation(&v86, &v89);
        vostok::math::mul4x3(v48, &v92, &v90);
        v49 = this->m_rain_effect.m_object;
        v49->m_cur_technique = 0;
        vostok::render::res_effect::apply_pass(v50, (int)v49);
        vostok::render::renderer_context::set_w(&v90, this->m_context);
        HIDWORD(v23) = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
        m_radius_parameter = this->m_radius_parameter;
        v81.x = wszName_1.z * *(float *)&rt;
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v51,
          (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          m_radius_parameter,
          &v81);
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v52,
          (vostok::render::constants_handler<1> *)HIDWORD(v23),
          this->m_rain_speed_parameter,
          &v79);
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v53,
          (vostok::render::constants_handler<1> *)HIDWORD(v23),
          this->m_rain_density_parameter,
          &wszName_1);
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v54,
          (vostok::render::constants_handler<1> *)HIDWORD(v23),
          this->m_rain_uv_scales_parameter,
          &v83);
        v55 = vostok::math::transpose(&v91, &v89);
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v56,
          (vostok::render::constants_handler<1> *)HIDWORD(v23),
          this->m_view_to_shadow_parameter,
          (const vostok::math::float3 *)v55);
        LODWORD(v23) = &this->m_rain_geometry;
        vostok::render::sky_dome_geometry::draw(v57, (int)&this->m_rain_geometry);
        v58 = v71.m_object;
        v59 = v68;
        this->m_rain_rotation_x[(int)v71.m_object] = (float)(this->m_context->m_time_delta
                                                           * *(float *)(LODWORD(v68) + 736))
                                                   + this->m_rain_rotation_x[(int)v71.m_object];
        m_node = (vostok::math::float4x4 *)&this->m_rain_rotation_y[(_DWORD)v58];
        m_node->i.x = (float)(this->m_context->m_time_delta * *(float *)(LODWORD(v59) + 736)) + m_node->i.x;
        *(float *)v46.m128i_i32 = *(float *)(LODWORD(v59) + 748) * *(float *)&rt;
        v71.m_object = (vostok::render::res_texture *)((char *)&v58->__vftable + 1);
        rt = (vostok::render::render_target *)v46.m128i_i32[0];
      }
      while ( (unsigned int)&v58->__vftable + 1 < LODWORD(v70.x) );
    }
  }
  v60 = this->m_context;
  v61 = object.x;
  *(_DWORD *)LODWORD(object.x) = LODWORD(v60->m_view_pos.x);
  LODWORD(v61) += 4;
  *(_DWORD *)LODWORD(v61) = LODWORD(v60->m_view_pos.y);
  *(float *)(LODWORD(v61) + 4) = v60->m_view_pos.z;
  v62 = vostok::math::float4x4::identity(m_node, &v89);
  vostok::render::renderer_context::set_w(v62, v60);
  v63 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  vostok::render::backend::reset_render_targets(
    v64,
    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
  v65 = *(_DWORD *)(LODWORD(v63) + 7440);
  v8 = *(_DWORD *)(LODWORD(v63) + 7384) == v65;
  *(_DWORD *)(LODWORD(v63) + 7384) = v65;
  *(_BYTE *)(LODWORD(v63) + 117) |= !v8;
LABEL_47:
  D3DPERF_EndEvent();
}
