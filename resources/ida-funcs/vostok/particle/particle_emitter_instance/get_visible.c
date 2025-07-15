bool __thiscall vostok::particle::particle_emitter_instance::get_visible(
        vostok::particle::particle_emitter_instance *this)
{
  return this->m_visible && this->m_emitter->m_visibility;
}
