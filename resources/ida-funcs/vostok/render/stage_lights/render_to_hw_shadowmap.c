void __userpurge vostok::render::stage_lights::render_to_hw_shadowmap(
        vostok::render::stage_lights *this@<ecx>,
        vostok::render::light *l,
        unsigned int shadow_quality,
        float z_bias,
        const vostok::math::float4x4 *smap_size,
        vostok::render::render_surface_instance **smap_size_index,
        const vostok::math::float4x4 *view_matrix,
        const vostok::math::float4x4 *projection_matrix,
        unsigned int marge,
        unsigned int face_index)
{
  pix_event_wrapper_dx11 *v11; // ecx
  unsigned int v12; // edi
  int z_low; // esi
  vostok::render::backend *v14; // ecx
  vostok::render::backend *v15; // ecx
  int x_low; // esi
  vostok::render::renderer_context *v17; // ecx
  vostok::render::renderer_context *v18; // ecx
  bool v19; // zf
  vostok::render::render_surface *v20; // ecx
  unsigned int v21; // eax
  unsigned int v22; // esi
  int *v23; // ecx
  int *v24; // edx
  int v25; // eax
  const vostok::render::render_target *v26; // eax
  int v27; // esi
  vostok::render::backend *v28; // ecx
  unsigned int v29; // eax
  unsigned int v30; // edx
  vostok::render::render_surface_instance **m_begin; // ecx
  int v32; // edi
  int m_render_surface; // esi
  vostok::render::material_effects *material_effects; // eax
  int v35; // edx
  int v36; // edx
  int y_low; // eax
  int v38; // eax
  vostok::render::renderer_context *v39; // ecx
  float v40; // xmm0_4
  int v41; // eax
  vostok::render::res_geometry *v42; // ecx
  vostok::render::backend *v43; // ecx
  int v44; // eax
  vostok::render::renderer_context *v45; // ecx
  _BYTE *v46; // esi
  float v47; // xmm0_4
  int v48; // eax
  const D3D11_VIEWPORT *v49; // [esp+0h] [ebp-2098h]
  bool v50; // [esp+0h] [ebp-2098h]
  const D3D11_VIEWPORT *v51; // [esp+0h] [ebp-2098h]
  float v52; // [esp+0h] [ebp-2098h]
  unsigned __int8 v53; // [esp+4h] [ebp-2094h]
  vostok::buffer_vector<vostok::render::render_surface_instance *> v54; // [esp+10h] [ebp-2088h] BYREF
  _BYTE v55[8192]; // [esp+1Ch] [ebp-207Ch] BYREF
  char v56; // [esp+201Ch] [ebp-7Ch] BYREF
  _BYTE v57[68]; // [esp+2020h] [ebp-78h] BYREF
  D3D11_VIEWPORT v58; // [esp+2064h] [ebp-34h] BYREF
  D3D11_VIEWPORT v59; // [esp+207Ch] [ebp-1Ch] BYREF
  float v60; // [esp+2094h] [ebp-4h]
  vostok::render::render_surface_instance **v61; // [esp+20A0h] [ebp+8h]
  char v62; // [esp+20A3h] [ebp+Bh]
  char has_models_for_shadow_pass; // [esp+20A3h] [ebp+Bh]

  vostok::render::backend::flush_rt_shader_resources(
    (vostok::render::backend *)this,
    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
  pix_event_wrapper_dx11::pix_event_wrapper_dx11(
    v11,
    (pix_event_wrapper_dx11 *)&shadow_quality + 3,
    (int)L"render_to_hw_shadowmap");
  qmemcpy(
    (void *)&v58,
    (const void *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 120),
    sizeof(v58));
  vostok::render::backend::set_render_targets(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    0,
    0,
    0,
    0);
  v12 = shadow_quality;
  z_low = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
  if ( *(_BYTE *)(shadow_quality + 625) )
  {
    vostok::render::backend::set_depth_stencil_target(
      (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      *(const vostok::render::render_target **)(shadow_quality + 4 * marge + 700));
  }
  else
  {
    vostok::render::backend::set_depth_stencil_target(
      (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      *((const vostok::render::render_target **)&l->m_view_to_light[1].c.x + (_DWORD)smap_size_index));
    vostok::render::backend::clear_depth_stencil(v15, z_low, 1u, *(float *)&v49, v53);
  }
  v59.TopLeftX = 0.0;
  v59.TopLeftY = 0.0;
  v60 = (float)(unsigned int)smap_size;
  v59.MinDepth = 0.0;
  v59.Width = v60;
  v59.Height = v60;
  v59.MaxDepth = s_bm_current_air_resistance;
  vostok::render::backend::set_viewports(
    v14,
    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    &v59,
    v49);
  x_low = LODWORD(l->m_view_to_light[0].i.x);
  smap_size_index = (vostok::render::render_surface_instance **)(x_low + 21132);
  smap_size = (const vostok::math::float4x4 *)(x_low + 20148);
  vostok::render::renderer_context::push_set_v(v17, x_low, view_matrix);
  vostok::render::renderer_context::push_set_p(v18, LODWORD(l->m_view_to_light[0].i.x), projection_matrix);
  v19 = *(_BYTE *)(v12 + 625) == 0;
  v54.m_begin = (vostok::render::render_surface_instance **)v55;
  v54.m_end = (vostok::render::render_surface_instance **)v55;
  v54.m_max_end = (vostok::render::render_surface_instance **)&v56;
  if ( v19 || *(_BYTE *)(v12 + 680) )
    vostok::render::scene::select_models(
      (vostok::render::scene *)(LODWORD(l->m_view_to_light[0].i.x) + 20148),
      *(_DWORD *)(LODWORD(l->m_view_to_light[0].i.x) + 16264),
      (vostok::math::float4x4 *)(LODWORD(l->m_view_to_light[0].i.x) + 20148),
      smap_size,
      &v54,
      (vostok::math::float4x4 *)smap_size_index,
      (const vostok::math::float3 *)2,
      0,
      v50);
  else
    vostok::render::scene::select_models(
      (vostok::render::scene *)(LODWORD(l->m_view_to_light[0].i.x) + 20148),
      *(_DWORD *)(LODWORD(l->m_view_to_light[0].i.x) + 16264),
      (vostok::math::float4x4 *)(LODWORD(l->m_view_to_light[0].i.x) + 20148),
      smap_size,
      &v54,
      (vostok::math::float4x4 *)smap_size_index,
      (const vostok::math::float3 *)2,
      1u,
      v50);
  v21 = shadow_quality;
  v62 = 0;
  if ( *(_BYTE *)(shadow_quality + 680)
    || !*(_DWORD *)(shadow_quality + 620)
    && (v20 = (vostok::render::render_surface *)vostok::quasi_singleton<vostok::render::options>::pinst,
        vostok::quasi_singleton<vostok::render::options>::pinst->current.m_shadow_quality) )
  {
    has_models_for_shadow_pass = vostok::render::stage_lights::has_models_for_shadow_pass(&v54, v20);
    vostok::render::scene::select_models(
      (vostok::render::scene *)(LODWORD(l->m_view_to_light[0].i.x) + 20148),
      *(_DWORD *)(LODWORD(l->m_view_to_light[0].i.x) + 16264),
      (vostok::math::float4x4 *)(LODWORD(l->m_view_to_light[0].i.x) + 20148),
      smap_size,
      &v54,
      (vostok::math::float4x4 *)smap_size_index,
      (const vostok::math::float3 *)2,
      0,
      (bool)v51);
    v22 = marge;
    v23 = (int *)(shadow_quality + 4 * marge + 656);
    v24 = (int *)(shadow_quality + 4 * marge + 632);
    *v24 = *v23;
    v25 = v54.m_end - v54.m_begin;
    v19 = *v24 == v25;
    *v23 = v25;
    v62 = !v19 | has_models_for_shadow_pass;
    v21 = shadow_quality;
  }
  else
  {
    v22 = marge;
  }
  if ( *(_BYTE *)(v21 + 625) )
  {
    if ( !v62 && !*(_BYTE *)(v21 + v22 + 626) )
    {
      v38 = LODWORD(l->m_view_to_light[0].i.x);
      qmemcpy(v57, (const void *)(v38 + 20148), 0x40u);
      vostok::render::renderer_context::pop_v(0, v38);
      vostok::render::renderer_context::pop_p(
        v39,
        (vostok::render::renderer_context *)LODWORD(l->m_view_to_light[0].i.x));
      l[2].m_color_curve.curve_value_min.x = z_bias * 0.1;
      v40 = v60;
      v41 = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
      qmemcpy(&l[2].previous_static_shadow_visible_objects_count[2], v57, 0x40u);
      l[2].m_color_curve.curve_value_min.y = v40;
      vostok::render::backend::set_viewports(0, v41, &v58, v51);
      v54.m_end = v54.m_begin;
      goto LABEL_33;
    }
    vostok::render::scene::select_models(
      (vostok::render::scene *)(LODWORD(l->m_view_to_light[0].i.x) + 20148),
      *(_DWORD *)(LODWORD(l->m_view_to_light[0].i.x) + 16264),
      (vostok::math::float4x4 *)(LODWORD(l->m_view_to_light[0].i.x) + 20148),
      smap_size,
      &v54,
      (vostok::math::float4x4 *)smap_size_index,
      (const vostok::math::float3 *)2,
      0,
      (bool)v51);
    v26 = *(const vostok::render::render_target **)(shadow_quality + 4 * v22 + 700);
    v27 = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
    vostok::render::backend::set_depth_stencil_target(
      (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      v26);
    vostok::render::backend::clear_depth_stencil(v28, v27, 1u, v52, v53);
    v29 = shadow_quality;
    v30 = marge;
    *(_BYTE *)(shadow_quality + marge + 626) = 0;
    qmemcpy(v57, (const void *)(LODWORD(l->m_view_to_light[0].i.x) + 20148), 0x40u);
    qmemcpy((void *)((v30 << 6) + v29 + 4), v57, 0x40u);
  }
  m_begin = v54.m_begin;
  v61 = v54.m_begin;
  for ( smap_size_index = v54.m_end; v61 != smap_size_index; ++v61 )
  {
    v32 = (int)*v61;
    m_render_surface = (int)(*v61)->m_render_surface;
    material_effects = vostok::render::render_surface::get_material_effects(
                         (vostok::render::render_surface *)m_begin,
                         m_render_surface);
    if ( material_effects->is_cast_shadow
      && *(_DWORD *)(m_render_surface + 4)
      && material_effects->m_effects[1].m_object
      && (!vostok::render::render_surface_instance::is_occluded((vostok::render::render_surface_instance *)m_begin, v32)
       || *(_BYTE *)(shadow_quality + 680)) )
    {
      v36 = *(_DWORD *)(v35 + 148);
      if ( v36 )
      {
        *(_DWORD *)(v36 + 22048) = 0;
        y_low = v36;
      }
      else
      {
        y_low = LODWORD(l[2].m_view_to_light[5].k.y);
        *(_DWORD *)(y_low + 22048) = 0;
      }
      vostok::render::res_effect::apply_pass((vostok::render::res_effect *)m_begin, y_low);
      vostok::render::renderer_context::set_w(
        *(const vostok::math::float4x4 **)(v32 + 36),
        (vostok::render::renderer_context *)LODWORD(l->m_view_to_light[0].i.x));
      (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(v32 + 20) + 68))(*(_DWORD *)(v32 + 20), 0);
      vostok::render::res_geometry::apply(v42, *(_DWORD *)(m_render_surface + 4));
      vostok::render::backend::render_indexed(
        (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
        3 * *(_DWORD *)(m_render_surface + 24),
        v43,
        D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
        0,
        0);
    }
  }
  v44 = LODWORD(l->m_view_to_light[0].i.x);
  qmemcpy(v57, (const void *)(v44 + 20148), 0x40u);
  vostok::render::renderer_context::pop_v(0, v44);
  vostok::render::renderer_context::pop_p(v45, (vostok::render::renderer_context *)LODWORD(l->m_view_to_light[0].i.x));
  if ( *(_BYTE *)(shadow_quality + 625) )
    v46 = (_BYTE *)((marge << 6) + shadow_quality + 4);
  else
    v46 = v57;
  v47 = ::z_bias;
  qmemcpy(&l[2].previous_static_shadow_visible_objects_count[2], v46, 0x40u);
  l[2].m_color_curve.curve_value_min.x = v47;
  v48 = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
  l[2].m_color_curve.curve_value_min.y = v60;
  vostok::render::backend::set_viewports(0, v48, &v58, v51);
LABEL_33:
  D3DPERF_EndEvent();
}
