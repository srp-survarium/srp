void __thiscall vostok::particle::particle_action_animation_impulse::set_defaults(
        vostok::particle::particle_action_animation_impulse *this,
        bool mt_alloc)
{
  float v2; // xmm0_4

  this->m_next.pointer = 0;
  this->m_fade_time = c_anim_center;
  v2 = s_bm_current_air_resistance;
  this->m_visibility = 1;
  this->m_magnitude = v2;
}
