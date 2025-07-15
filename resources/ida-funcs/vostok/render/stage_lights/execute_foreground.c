void __thiscall vostok::render::stage_lights::execute_foreground(vostok::render::stage_lights *this)
{
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v2; // eax
  vostok::render::stage_lights *v3; // ecx
  vostok::render::render_target *v4; // eax
  vostok::render::render_target *rt; // [esp+4h] [ebp-4h] BYREF

  v2 = vostok::render::renderer_context::get_rt(
         this->m_context,
         rt_generic_0,
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
  vostok::render::stage_lights::render_forward_lighting(v3, (vostok::render::backend *)this, 1);
}
