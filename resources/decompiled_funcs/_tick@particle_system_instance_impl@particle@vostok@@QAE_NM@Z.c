bool __thiscall vostok::particle::particle_system_instance_impl::tick(
        vostok::particle::particle_system_instance_impl *this,
        float time_delta)
{
  float m_lods_lerp_alpha; // [esp+Ch] [ebp-Ch]
  vostok::particle::particle_emitter_instance *instance; // [esp+14h] [ebp-4h]

  if ( this->m_paused )
    return 0;
  this->m_particle_system_time = this->m_particle_system_time + time_delta;
  if ( !this->m_lerped )
    vostok::particle::particle_system_instance_impl::process_lods_lerping(this, time_delta);
  for ( instance = this->m_lods[this->m_current_lod].m_emitter_instance_list.m_first; instance; instance = instance->m_next )
  {
    if ( this->m_lerped )
      m_lods_lerp_alpha = *(float *)&clear_value;
    else
      m_lods_lerp_alpha = this->m_lods_lerp_alpha;
    ((void (__thiscall *)(vostok::particle::particle_emitter_instance *, _DWORD, bool, float))instance->tick)(
      instance,
      LODWORD(time_delta),
      !this->m_no_more_create,
      COERCE_FLOAT(LODWORD(m_lods_lerp_alpha)));
  }
  return this->is_finished(this);
}
