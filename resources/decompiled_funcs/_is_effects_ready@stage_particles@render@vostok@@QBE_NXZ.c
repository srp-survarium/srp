BOOL __thiscall vostok::render::stage_particles::is_effects_ready(vostok::render::stage_particles *this)
{
  return this->m_resolve_particles_effect.m_object != 0;
}
