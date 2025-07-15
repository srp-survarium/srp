BOOL __thiscall vostok::render::render_particle_emitter_instance::is_occluded(
        vostok::render::render_particle_emitter_instance *this)
{
  BOOL result; // eax

  result = 0;
  if ( vostok::quasi_singleton<vostok::render::options>::pinst->current.m_use_hiz_occlusion_culling )
    return this->m_occluded;
  return result;
}
