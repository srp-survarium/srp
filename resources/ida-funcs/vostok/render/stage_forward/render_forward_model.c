void __userpurge vostok::render::stage_forward::render_forward_model(
        vostok::render::render_surface_instance *instance@<eax>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        vostok::render::stage_forward *this)
{
  vostok::render::render_model_instance_impl *m_parent; // ecx
  vostok::render::render_surface *m_render_surface; // edi
  vostok::render::render_model_instance_impl_vtbl *v9; // eax
  vostok::render::res_geometry *v10; // ecx
  vostok::render::renderer_context *m_context; // eax
  float v12; // xmm0_4
  float z; // esi
  vostok::math::float4x4 *v14; // eax
  vostok::render::backend *v15; // ecx
  vostok::render::backend *v16; // ecx
  vostok::render::shader_constant_host **m_shadow; // edi
  const vostok::math::float4x4 *view2shadow; // eax
  vostok::math::float4x4 *v19; // eax
  vostok::render::backend *v20; // ecx
  vostok::render::backend *v21; // ecx
  vostok::render::backend *v22; // ecx
  vostok::render::shader_constant_host *m_eye_ray_corner_parameter; // [esp-8h] [ebp-58h]
  vostok::math::float4x4 v27; // [esp+4h] [ebp-4Ch] BYREF
  vostok::render::render_geometry *p_m_render_geometry; // [esp+44h] [ebp-Ch]
  float v29; // [esp+48h] [ebp-8h] BYREF
  unsigned int v30; // [esp+58h] [ebp+8h]

  m_parent = instance->m_parent;
  m_render_surface = instance->m_render_surface;
  instance->m_last_render_time = 0.0;
  v9 = m_parent->__vftable;
  p_m_render_geometry = &m_render_surface->m_render_geometry;
  ((void (__thiscall *)(vostok::render::render_model_instance_impl *, _DWORD, int, int, int))v9->set_constants)(
    m_parent,
    0,
    a3,
    a4,
    a2);
  vostok::render::renderer_context::set_w(instance->m_transform, this->m_context);
  vostok::render::res_geometry::apply(v10, (int)m_render_surface->m_render_geometry.geom.m_object);
  m_context = this->m_context;
  if ( LOBYTE(m_context->m_scene_view.m_object[2].grm_satisfaction_tree_hook.left_) )
    v12 = s_bm_current_air_resistance;
  else
    v12 = 0.0;
  z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  m_eye_ray_corner_parameter = this->m_eye_ray_corner_parameter;
  v29 = v12;
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    (vostok::render::backend *)m_context->m_eye_rays,
    (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    m_eye_ray_corner_parameter,
    m_context->m_eye_rays);
  v14 = vostok::math::transpose(&this->m_renderer->m_view_to_rain_shadow, &v27);
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v15,
    (vostok::render::constants_handler<1> *)LODWORD(z),
    this->m_view_to_shadow_parameter,
    (const vostok::math::float3 *)v14);
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v16,
    (vostok::render::constants_handler<1> *)LODWORD(z),
    this->m_rain_offset_parameter,
    (const vostok::math::float3 *)&this->m_rain_offset);
  v30 = 0;
  m_shadow = this->m_shadow;
  do
  {
    view2shadow = vostok::render::renderer_context::get_view2shadow(this->m_context, v30);
    v19 = vostok::math::transpose(view2shadow, &v27);
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v20,
      (vostok::render::constants_handler<1> *)LODWORD(z),
      *m_shadow,
      (const vostok::math::float3 *)v19);
    ++v30;
    ++m_shadow;
  }
  while ( v30 < 4 );
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v21,
    (vostok::render::constants_handler<1> *)LODWORD(z),
    this->m_use_rain_parameter,
    (const vostok::math::float3 *)&v29);
  vostok::render::backend::render_indexed(
    (vostok::render::backend *)LODWORD(z),
    3 * p_m_render_geometry->primitive_count,
    v22,
    D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
    0,
    0);
}
