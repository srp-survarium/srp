void __thiscall vostok::particle::particle_action_trail::set_defaults(
        vostok::particle::particle_action_trail *this,
        bool mt_alloc)
{
  vostok::particle::particle_action::set_defaults(this, mt_alloc);
  this->m_screen_alignment = particle_screen_alignment_rectangle;
  this->m_beamtrail_parameters.num_sheets = 0;
  this->m_beamtrail_parameters.num_texture_tiles = 0;
}
