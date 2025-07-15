void __thiscall vostok::render::stage_ambient_lighting::clear_surfaces(vostok::render::stage_ambient_lighting *this)
{
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v2; // eax
  vostok::render::backend *v3; // ecx
  vostok::render::render_target *v4; // eax
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v5; // eax
  vostok::render::backend *v6; // ecx
  vostok::render::render_target *v7; // eax
  vostok::render::render_target *rt; // [esp+14h] [ebp-4h] BYREF

  v2 = vostok::render::renderer_context::get_rt(
         this->m_context,
         rt_probe_indices,
         (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt);
  vostok::render::backend::set_render_targets(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    v2->m_object,
    0,
    0,
    0);
  v4 = rt;
  if ( rt )
  {
    --rt->m_reference_count;
    if ( !v4->m_reference_count )
      vostok::render::resource_manager::release(rt, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
  }
  vostok::render::backend::clear_render_targets(
    v3,
    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    0,
    0.0,
    0.0,
    0.0);
  v5 = vostok::render::renderer_context::get_rt(
         this->m_context,
         rt_accumulator_ambient_lights,
         (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt);
  vostok::render::backend::set_render_targets(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    v5->m_object,
    0,
    0,
    0);
  v7 = rt;
  if ( rt )
  {
    --rt->m_reference_count;
    if ( !v7->m_reference_count )
      vostok::render::resource_manager::release(rt, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
  }
  vostok::render::backend::clear_render_targets(
    v6,
    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    SLODWORD(s_bm_current_air_resistance),
    1.0,
    1.0,
    1.0);
}
