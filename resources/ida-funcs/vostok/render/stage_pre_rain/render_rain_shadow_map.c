vostok::math::float4x4 *__userpurge vostok::render::stage_pre_rain::render_rain_shadow_map@<eax>(
        vostok::render::stage_pre_rain *this@<ecx>,
        long double a2@<esi:edi>,
        vostok::math::float4x4 *result,
        vostok::math::float4x4 *a3)
{
  vostok::math::float4x4 *v5; // eax
  double x_low; // st7
  float y; // eax
  float v8; // xmm2_4
  float v9; // xmm3_4
  int y_low; // esi
  vostok::render::renderer_context *v11; // ecx
  float z; // esi
  double v13; // st7
  float v14; // xmm0_4
  vostok::render::render_surface_instance **m_begin; // eax
  vostok::render::render_surface_instance **m_end; // ecx
  int v17; // edi
  int *m_render_surface; // esi
  bool v19; // zf
  int v20; // eax
  int w_low; // eax
  vostok::render::res_geometry *v22; // ecx
  vostok::render::backend *v23; // ecx
  int v24; // eax
  vostok::render::renderer_context *v25; // ecx
  float v26; // edx
  vostok::render::backend *v27; // ecx
  vostok::math::float4x4 *v28; // ecx
  vostok::math::float4x4 *v29; // eax
  float v30; // esi
  vostok::render::backend *v31; // ecx
  int v32; // ecx
  float v34; // [esp+4h] [ebp-2170h]
  const D3D11_VIEWPORT *v35; // [esp+Ch] [ebp-2168h]
  bool v36; // [esp+Ch] [ebp-2168h]
  const D3D11_VIEWPORT *v37; // [esp+Ch] [ebp-2168h]
  vostok::buffer_vector<vostok::render::render_surface_instance *> v38; // [esp+1Ch] [ebp-2158h] BYREF
  _BYTE v39[8192]; // [esp+28h] [ebp-214Ch] BYREF
  char v40; // [esp+2028h] [ebp-14Ch] BYREF
  D3D11_VIEWPORT v41; // [esp+202Ch] [ebp-148h] BYREF
  vostok::math::float4x4 v42; // [esp+2044h] [ebp-130h] BYREF
  vostok::math::float4x4 resulta; // [esp+2084h] [ebp-F0h] BYREF
  vostok::math::float4x4 v44; // [esp+20C4h] [ebp-B0h] BYREF
  D3D11_VIEWPORT v45; // [esp+2108h] [ebp-6Ch] BYREF
  int v46; // [esp+2120h] [ebp-54h]
  vostok::render::stage_pre_rain v47; // [esp+2124h] [ebp-50h] BYREF
  int v48; // [esp+2160h] [ebp-14h]
  vostok::math::float3 v49; // [esp+2164h] [ebp-10h] BYREF
  float v50; // [esp+2170h] [ebp-4h]
  float v51; // [esp+217Ch] [ebp+8h]
  vostok::math::float4x4 *v52; // [esp+217Ch] [ebp+8h]
  vostok::render::render_surface_instance **v53; // [esp+217Ch] [ebp+8h]

  HIDWORD(a2) = *(_DWORD *)(LODWORD(result->i.y) + 16268);
  LODWORD(a2) = vostok::math::create_rotation_z(a2, &resulta, *(float *)(HIDWORD(a2) + 712));
  v5 = vostok::math::create_rotation_x(a2, &v42, *(float *)(HIDWORD(a2) + 708));
  vostok::math::mul4x3((const vostok::math::float4x4 *)LODWORD(a2), v5, &v44);
  x_low = (double)LODWORD(result->k.x);
  y = result->i.y;
  v47.m_rain_density_parameter = *(vostok::render::shader_constant_host **)(LODWORD(y) + 21148);
  v47.m_rain_offset = *(float *)(LODWORD(y) + 21152);
  v47.m_rain_offset_counter = *(float *)(LODWORD(y) + 21156);
  v47.m_effect_shadow_direct.m_object = (vostok::render::res_effect *)(LODWORD(v44.j.x) ^ _mask__NegFloat_);
  v47.m_shadow_map_size = LODWORD(v44.j.y) ^ _mask__NegFloat_;
  v47.m_view_to_shadow_parameter = (vostok::render::shader_constant_host *)(LODWORD(v44.j.z) ^ _mask__NegFloat_);
  v50 = x_low;
  LODWORD(y) += 21132;
  v8 = *(float *)(LODWORD(y) + 4) - (float)(COERCE_FLOAT(LODWORD(v44.j.y) ^ _mask__NegFloat_) * s_spot_max_distance);
  v9 = *(float *)(LODWORD(y) + 8);
  *(float *)&v47.m_enabled = (float)(*(float *)LODWORD(y)
                                   - (float)(COERCE_FLOAT(LODWORD(v44.j.x) ^ _mask__NegFloat_) * s_spot_max_distance))
                           + (float)((float)((float)((float)(*(float *)&v47.m_rain_density_parameter * offs) * 0.5) * 0.5)
                                   * v50);
  *(float *)&v47.m_rt_rain_shadow_map.m_object = v8 + (float)((float)((float)((float)(offs * 0.0) * 0.5) * 0.5) * v50);
  *(float *)&v47.m_t_rain_shadow_map.m_object = (float)(v9
                                                      - (float)(COERCE_FLOAT(LODWORD(v44.j.z) ^ _mask__NegFloat_)
                                                              * s_spot_max_distance))
                                              + (float)((float)((float)((float)(v47.m_rain_offset_counter * offs) * 0.5)
                                                              * 0.5)
                                                      * v50);
  *(_QWORD *)&v49.x = LODWORD(s_bm_current_air_resistance);
  v49.z = 0.0;
  vostok::math::create_camera_direction(
    (const vostok::math::float3 *)&v47.m_effect_shadow_direct,
    &v49,
    &v44,
    (float *)&v47.m_enabled);
  v51 = (float)LODWORD(result->k.x);
  v34 = v51 * 0.5;
  vostok::math::create_orthographic_projection(
    (int)&v42,
    (float)(v51 * 1.41421) + 200.0,
    (vostok::math *)LODWORD(v34),
    (struct vostok::math::float4x4 *)LODWORD(v34),
    0.1);
  vostok::math::mul4x3(&v42, &v44, &resulta);
  memset(&v49, 0, sizeof(v49));
  vostok::render::stage_pre_rain::compute_aligment(&v49, v50, &v47);
  *(float *)&v47.m_rain_density_parameter = s_bm_current_air_resistance;
  v47.m_rain_offset = 0.0;
  v47.m_rain_offset_counter = 0.0;
  v49.x = *(float *)&v47.__vftable + *(float *)&v47.m_enabled;
  v49.y = *(float *)&v47.m_context + *(float *)&v47.m_rt_rain_shadow_map.m_object;
  v49.z = *(float *)&v47.m_renderer + *(float *)&v47.m_t_rain_shadow_map.m_object;
  qmemcpy(
    &v44,
    vostok::math::create_camera_direction(
      (const vostok::math::float3 *)&v47.m_effect_shadow_direct,
      (const vostok::math::float3 *)&v47.m_rain_density_parameter,
      &resulta,
      &v49.x),
    sizeof(v44));
  y_low = LODWORD(result->i.y);
  v52 = (vostok::math::float4x4 *)(y_low + 21132);
  LODWORD(v50) = y_low + 20148;
  vostok::render::renderer_context::push_set_v(0, y_low, &v44);
  vostok::render::renderer_context::push_set_p(v11, LODWORD(result->i.y), &v42);
  z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  vostok::render::backend::set_render_targets(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    0,
    0,
    0,
    0);
  vostok::render::backend::set_depth_stencil_target(
    (vostok::render::backend *)LODWORD(z),
    (const vostok::render::render_target *)LODWORD(result->j.x));
  v13 = (double)LODWORD(result->k.x);
  qmemcpy((void *)&v41, (const void *)(LODWORD(z) + 120), sizeof(v41));
  v45.TopLeftX = 0.0;
  v45.TopLeftY = 0.0;
  v45.Width = v13;
  v45.MinDepth = 0.0;
  v45.Height = v13;
  v14 = s_bm_current_air_resistance;
  v45.MaxDepth = s_bm_current_air_resistance;
  vostok::render::backend::set_viewports(
    0,
    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    &v45,
    v35);
  v38.m_begin = (vostok::render::render_surface_instance **)v39;
  v38.m_end = (vostok::render::render_surface_instance **)v39;
  v38.m_max_end = (vostok::render::render_surface_instance **)&v40;
  vostok::render::scene::select_models(
    (vostok::render::scene *)(LODWORD(result->i.y) + 20148),
    *(_DWORD *)(LODWORD(result->i.y) + 16264),
    (vostok::math::float4x4 *)(LODWORD(result->i.y) + 20148),
    (const vostok::math::float4x4 *)LODWORD(v50),
    &v38,
    v52,
    (const vostok::math::float3 *)1,
    0,
    v36);
  m_begin = v38.m_begin;
  m_end = v38.m_end;
  v53 = v38.m_begin;
  v47.m_eye_ray_corner_parameter = (vostok::render::shader_constant_host *)v38.m_end;
  if ( s_rain_debug0 && v38.m_begin != v38.m_end )
  {
    do
    {
      v17 = (int)*m_begin;
      m_render_surface = (int *)(*m_begin)->m_render_surface;
      v19 = m_render_surface[1] == 0;
      v50 = *(float *)m_begin;
      if ( !v19 )
      {
        v20 = m_render_surface[37];
        if ( (v20 == 2 || v20 == 4)
          && !vostok::render::render_surface_instance::is_occluded(
                (vostok::render::render_surface_instance *)m_end,
                v17) )
        {
          vostok::render::render_surface_instance::get_dynamic_screen_factor((vostok::render::render_surface_instance *)m_end);
          if ( v14 >= 10.0 )
          {
            w_low = LODWORD(result->j.w);
            *(_DWORD *)(w_low + 22048) = 0;
            vostok::render::res_effect::apply_pass((vostok::render::res_effect *)m_end, w_low);
            (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(v17 + 20) + 68))(*(_DWORD *)(v17 + 20), 0);
            vostok::render::res_geometry::apply(v22, m_render_surface[1]);
            vostok::render::renderer_context::set_w(
              *(const vostok::math::float4x4 **)(LODWORD(v50) + 36),
              (vostok::render::renderer_context *)LODWORD(result->i.y));
            vostok::render::backend::render_indexed(
              (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
              3 * m_render_surface[6],
              v23,
              D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
              0,
              0);
          }
        }
      }
      m_begin = v53 + 1;
      v53 = m_begin;
    }
    while ( m_begin != (vostok::render::render_surface_instance **)v47.m_eye_ray_corner_parameter );
  }
  v24 = LODWORD(result->i.y);
  qmemcpy(&resulta, (const void *)(v24 + 20148), sizeof(resulta));
  vostok::render::renderer_context::pop_v(0, v24);
  vostok::render::renderer_context::pop_p(v25, (vostok::render::renderer_context *)LODWORD(result->i.y));
  *(float *)&v47.m_shadow_map_size = FLOAT_N0_001;
  *(float *)&v47.m_rain_offset_parameter = c_anim_center;
  memset(&v47.m_rain_density_parameter, 0, 12);
  *(_QWORD *)&v44.i.x = LODWORD(c_anim_center);
  memset(&v44.lines[0].elements[2], 0, 12);
  *(float *)&v47.m_view_to_shadow_parameter = s_bm_current_air_resistance;
  *(_QWORD *)&v49.elements[1] = LODWORD(s_bm_current_air_resistance);
  v46 = 0;
  *(float *)&v47.__vftable = FLOAT_N0_5;
  v47.m_context = 0;
  v47.m_renderer = 0;
  *(_QWORD *)&v44.lines[1].elements[1] = LODWORD(FLOAT_N0_5);
  memset(&v44.lines[1].elements[3], 0, 12);
  v48 = 0;
  v49.x = 0.0;
  v26 = result->i.y;
  *(_QWORD *)&v44.lines[2].elements[2] = LODWORD(s_bm_current_air_resistance);
  *(float *)&v47.m_wet_surface_effect.m_object = c_anim_center;
  *(float *)&v47.m_effect_shadow_direct.m_object = c_anim_center;
  v44.c.x = c_anim_center;
  *(_QWORD *)&v44.lines[3].elements[1] = __PAIR64__(LODWORD(FLOAT_N0_001), LODWORD(c_anim_center));
  v44.c.w = s_bm_current_air_resistance;
  vostok::math::mul4x3(&resulta, (const vostok::math::float4x4 *)(LODWORD(v26) + 19636), &v42);
  vostok::math::mul4x3(&v44, &v42, a3);
  vostok::render::backend::set_viewports(
    v27,
    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    &v41,
    v37);
  v29 = vostok::math::float4x4::identity(v28, &resulta);
  vostok::render::renderer_context::set_w(v29, (vostok::render::renderer_context *)LODWORD(result->i.y));
  v30 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  vostok::render::backend::reset_render_targets(
    v31,
    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
  v32 = *(_DWORD *)(LODWORD(v30) + 7440);
  *(_BYTE *)(LODWORD(v30) + 117) |= *(_DWORD *)(LODWORD(v30) + 7384) != v32;
  *(_DWORD *)(LODWORD(v30) + 7384) = v32;
  return a3;
}
