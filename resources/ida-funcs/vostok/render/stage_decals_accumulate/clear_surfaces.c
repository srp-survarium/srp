void __thiscall vostok::render::stage_decals_accumulate::clear_surfaces(vostok::render::stage_decals_accumulate *this)
{
  bool v2; // al
  vostok::render::renderer_context *m_context; // ecx
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v4; // eax
  vostok::render::render_target *v5; // eax
  vostok::render::backend *v6; // ecx
  vostok::render::render_target *m_object; // edi
  vostok::render::render_target *v8; // ebx
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v9; // eax
  vostok::render::render_target *v10; // eax
  vostok::render::render_target *v11; // eax
  vostok::render::render_target *v12; // eax
  int v13; // esi
  int v14; // eax
  vostok::render::backend *v15; // ecx
  int v16; // [esp-4h] [ebp-20h]
  vostok::render::render_target *v17; // [esp+10h] [ebp-Ch] BYREF
  vostok::render::render_target *v18; // [esp+14h] [ebp-8h] BYREF
  vostok::render::render_target *rt; // [esp+18h] [ebp-4h] BYREF

  v2 = this->is_enabled(this);
  m_context = this->m_context;
  if ( v2 )
  {
    m_object = vostok::render::renderer_context::get_rt(
                 m_context,
                 rt_decals_smoothness,
                 (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v17)->m_object;
    v8 = vostok::render::renderer_context::get_rt(
           this->m_context,
           rt_decals_normal,
           (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v18)->m_object;
    v9 = vostok::render::renderer_context::get_rt(
           this->m_context,
           rt_decals_diffuse,
           (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt);
    vostok::render::backend::set_render_targets(
      (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      v9->m_object,
      v8,
      m_object,
      0);
    v10 = rt;
    if ( rt )
    {
      --rt->m_reference_count;
      if ( !v10->m_reference_count )
        vostok::render::resource_manager::release(rt, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
    }
    v11 = v18;
    if ( v18 )
    {
      --v18->m_reference_count;
      if ( !v11->m_reference_count )
        vostok::render::resource_manager::release(v18, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
    }
    v12 = v17;
    if ( v17 )
    {
      --v17->m_reference_count;
      if ( !v12->m_reference_count )
        vostok::render::resource_manager::release(v17, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
    }
    v13 = vostok::math::color_rgba(0.0, COERCE_VOSTOK_MATH_(0.0), 0.0, 0.0);
    v14 = vostok::math::color_rgba(0.5, COERCE_VOSTOK_MATH_(0.5), 0.5, 0.0);
    vostok::render::backend::clear_render_targets(
      v15,
      (_DWORD *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      (vostok::math::color)v13,
      (vostok::math::color)v14,
      (vostok::math::color)v13,
      (vostok::math::color)v13);
  }
  else
  {
    v4 = vostok::render::renderer_context::get_rt(
           m_context,
           rt_decals_smoothness,
           (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt);
    vostok::render::backend::set_render_targets(
      (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      v4->m_object,
      0,
      0,
      0);
    v5 = rt;
    if ( rt )
    {
      --rt->m_reference_count;
      if ( !v5->m_reference_count )
        vostok::render::resource_manager::release(rt, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
    }
    v16 = vostok::math::color_rgba(0.0, COERCE_VOSTOK_MATH_(0.0), 0.0, 0.0);
    vostok::render::backend::clear_render_targets(
      v6,
      (_DWORD *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      (vostok::math::color)v16,
      (vostok::math::color)v16,
      (vostok::math::color)v16,
      (vostok::math::color)v16);
  }
}
