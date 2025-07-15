void __thiscall vostok::render::stage_postprocess::clear_surfaces(vostok::render::stage_postprocess *this)
{
  vostok::render::stage_postprocess *v2; // ecx
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v3; // eax
  vostok::render::backend *v4; // ecx
  vostok::render::render_target *v5; // eax
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v6; // [esp+8h] [ebp-10h] BYREF
  vostok::render::render_target *rt; // [esp+14h] [ebp-4h] BYREF

  if ( !s_debug_pp_5 || !LOBYTE(this->m_context->m_scene_view.m_object[2].m_raw_resource_ptr.m_object) )
  {
    v6.m_object = (vostok::render::render_target *)this;
    vostok::render::renderer_context::get_rt(this->m_context, rt_lens_flares, &v6);
    vostok::render::stage_postprocess::clear_surface(v2, v6.m_object);
  }
  if ( vostok::quasi_singleton<vostok::render::options>::pinst->current.m_motion_blur_quality )
  {
    if ( vostok::quasi_singleton<vostok::render::options>::pinst->current.m_antialiasing_method != 2
      && !vostok::quasi_singleton<vostok::render::options>::pinst->current.m_post_process_quality )
    {
      return;
    }
  }
  else if ( !vostok::quasi_singleton<vostok::render::options>::pinst->current.m_use_motion_vectors_in_taa
         || vostok::quasi_singleton<vostok::render::options>::pinst->current.m_antialiasing_method != 2 )
  {
    return;
  }
  v3 = vostok::render::renderer_context::get_rt(
         this->m_context,
         rt_object_motion_vectors,
         (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt);
  vostok::render::backend::set_render_targets(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    v3->m_object,
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
  vostok::render::backend::clear_render_targets(
    v4,
    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    0,
    0.0,
    0.0,
    0.0);
}
