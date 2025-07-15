void __usercall vostok::render::renderer::render_stages(vostok::render::renderer *this@<ecx>, int a2@<eax>)
{
  float z; // eax
  int v4; // esi
  bool v5; // zf
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v6; // eax
  vostok::render::render_target *v7; // eax
  vostok::render::render_target *rt; // [esp+Ch] [ebp-4h] BYREF

  vostok::render::renderer::execute_stages(this, a2);
  z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  v4 = *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7440);
  v5 = *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7384) == v4;
  *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7384) = v4;
  *(_BYTE *)(LODWORD(z) + 117) |= !v5;
  v6 = vostok::render::renderer_context::get_rt(
         *(vostok::render::renderer_context **)(a2 + 480),
         rt_present,
         (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt);
  vostok::render::backend::set_render_targets(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    v6->m_object,
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
}
