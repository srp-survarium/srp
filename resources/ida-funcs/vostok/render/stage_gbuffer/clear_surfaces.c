void __thiscall vostok::render::stage_gbuffer::clear_surfaces(vostok::render::stage_gbuffer *this)
{
  vostok::render::render_target *m_object; // edi
  vostok::render::render_target *v3; // ebx
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v4; // eax
  vostok::render::render_target *v5; // eax
  vostok::render::render_target *v6; // eax
  vostok::render::render_target *v7; // eax
  int v8; // ebx
  int v9; // eax
  vostok::render::backend *v10; // ecx
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v11; // eax
  vostok::render::render_target *v12; // eax
  unsigned __int8 v13; // al
  vostok::render::backend *v14; // ecx
  vostok::render::render_target *v15; // [esp+18h] [ebp-Ch] BYREF
  vostok::render::render_target *v16; // [esp+1Ch] [ebp-8h] BYREF
  vostok::render::render_target *rt; // [esp+20h] [ebp-4h] BYREF

  if ( vostok::quasi_singleton<vostok::render::options>::pinst->current.m_clear_surfaces )
  {
    m_object = vostok::render::renderer_context::get_rt(
                 this->m_context,
                 rt_surface_parameters,
                 (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v15)->m_object;
    v3 = vostok::render::renderer_context::get_rt(
           this->m_context,
           rt_albedo,
           (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v16)->m_object;
    v4 = vostok::render::renderer_context::get_rt(
           this->m_context,
           rt_normal,
           (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt);
    vostok::render::backend::set_render_targets(
      (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      v4->m_object,
      v3,
      m_object,
      0);
    v5 = rt;
    if ( rt )
    {
      --rt->m_reference_count;
      if ( !v5->m_reference_count )
        vostok::render::resource_manager::release(rt, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
    }
    v6 = v16;
    if ( v16 )
    {
      --v16->m_reference_count;
      if ( !v6->m_reference_count )
        vostok::render::resource_manager::release(v16, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
    }
    v7 = v15;
    if ( v15 )
    {
      --v15->m_reference_count;
      if ( !v7->m_reference_count )
        vostok::render::resource_manager::release(v15, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
    }
    v8 = vostok::math::color_rgba(0.0, COERCE_VOSTOK_MATH_(0.0), 0.0, 0.0);
    v9 = vostok::math::color_rgba(0.0, COERCE_VOSTOK_MATH_(0.0), 0.0, 1.0);
    vostok::render::backend::clear_render_targets(
      v10,
      (_DWORD *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      (vostok::math::color)v8,
      (vostok::math::color)v9,
      (vostok::math::color)v8,
      (vostok::math::color)v8);
  }
  v11 = vostok::render::renderer_context::get_rt(
          this->m_context,
          rt_position,
          (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v15);
  vostok::render::backend::set_render_targets(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    v11->m_object,
    0,
    0,
    0);
  v12 = v15;
  if ( v15 )
  {
    --v15->m_reference_count;
    if ( !v12->m_reference_count )
      vostok::render::resource_manager::release(v15, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
  }
  v13 = vostok::math::color_rgba(s_bm_current_air_resistance, COERCE_VOSTOK_MATH_(1.0), 1.0, 0.0);
  vostok::render::backend::clear_render_targets(
    v14,
    LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.elements[2]),
    v13);
}
