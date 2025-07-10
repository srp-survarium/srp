void __thiscall vostok::particle::particle_emitter_instance::update_render_buffers(
        vostok::particle::particle_emitter_instance *this,
        vostok::particle::enum_particle_data_type *data_type,
        bool use_subuv)
{
  unsigned int num_sheets; // [esp+0h] [ebp-8h]

  if ( this->m_beamtrail_parameters )
    num_sheets = this->m_beamtrail_parameters->num_sheets;
  else
    num_sheets = 0;
  this->m_render_instance->update_render_buffers(
    this->m_render_instance,
    *data_type,
    use_subuv,
    this->m_max_num_particles,
    num_sheets);
}
