void __thiscall vostok::particle::particle_action_beam::set_defaults(
        vostok::particle::particle_action_beam *this,
        bool mt_alloc)
{
  float v2; // xmm1_4

  this->m_next.pointer = 0;
  v2 = s_bm_current_air_resistance;
  this->m_visibility = 1;
  this->m_beamtrail_parameters.num_sheets = 1;
  this->m_beamtrail_parameters.num_texture_tiles = 1;
  this->m_beamtrail_parameters.continuous_uv = 1;
  this->m_beamtrail_parameters.num_beams = 1;
  this->m_speed = 0.0;
  this->m_noise = v2;
  this->m_frequency = 0.0;
}
