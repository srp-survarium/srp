void __thiscall vostok::render::stage_shadow_mask::clear_surfaces(vostok::render::stage_shadow_mask *this)
{
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v1; // eax
  vostok::render::backend *v2; // ecx
  vostok::render::render_target *v3; // eax
  vostok::render::render_target *rt; // [esp+Ch] [ebp-4h] BYREF

  rt = (vostok::render::render_target *)this;
  v1 = vostok::render::renderer_context::get_rt(
         this->m_context,
         rt_sun_shadow_and_scattering,
         (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt);
  vostok::render::backend::set_render_targets(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    v1->m_object,
    0,
    0,
    0);
  v3 = rt;
  if ( rt )
  {
    --rt->m_reference_count;
    if ( !v3->m_reference_count )
      vostok::render::resource_manager::release(rt, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
  }
  vostok::render::backend::clear_render_targets(
    v2,
    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    SLODWORD(s_bm_current_air_resistance),
    0.0,
    0.0,
    0.0);
}
