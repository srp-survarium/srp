void __thiscall vostok::particle::particle_action_beam::set_defaults(
        vostok::particle::particle_action_beam *this,
        bool mt_alloc)
{
  vostok::particle::particle_action::set_defaults(this, mt_alloc);
  this->m_beamtrail_parameters.num_sheets = 1;
  this->m_beamtrail_parameters.num_texture_tiles = 1;
  this->m_beamtrail_parameters.num_beams = 1;
  this->m_speed = *(float *)&FLOAT_0_0;
  LODWORD(this->m_noise) = clear_value;
  this->m_frequency = *(float *)&FLOAT_0_0;
}
