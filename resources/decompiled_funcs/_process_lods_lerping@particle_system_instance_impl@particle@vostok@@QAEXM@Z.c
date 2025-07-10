void __thiscall vostok::particle::particle_system_instance_impl::process_lods_lerping(
        vostok::particle::particle_system_instance_impl *this,
        float time_delta)
{
  vostok::particle::particle_emitter_instance *i; // [esp+14h] [ebp-8h]
  vostok::particle::particle_emitter_instance *instance; // [esp+18h] [ebp-4h]

  if ( *(float *)&clear_value <= this->m_lods_lerp_alpha )
  {
    this->m_lerped = 1;
    for ( i = this->m_lods[this->m_old_lod].m_emitter_instance_list.m_first; i; i = i->m_next )
      vostok::particle::particle_emitter_instance::remove_particles(i, 0xFFFFFFFF);
  }
  else
  {
    this->m_lods_lerp_alpha = (float)((float)(time_delta * 0.5) * 0.5) + this->m_lods_lerp_alpha;
    vostok::math::clamp<float>(&this->m_lods_lerp_alpha, 0.0, 1.0);
    for ( instance = this->m_lods[this->m_old_lod].m_emitter_instance_list.m_first; instance; instance = instance->m_next )
      ((void (__thiscall *)(vostok::particle::particle_emitter_instance *, _DWORD, bool, _DWORD))instance->tick)(
        instance,
        LODWORD(time_delta),
        !this->m_no_more_create,
        *(float *)&clear_value - this->m_lods_lerp_alpha);
  }
}
