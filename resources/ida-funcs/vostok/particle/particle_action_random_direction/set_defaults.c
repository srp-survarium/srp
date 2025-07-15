void __thiscall vostok::particle::particle_action_random_direction::set_defaults(
        vostok::particle::particle_action_random_direction *this,
        bool mt_alloc)
{
  float v3; // xmm1_4

  this->m_next.pointer = 0;
  this->m_visibility = 1;
  vostok::particle::particle_domain_complex::set_defaults(
    (vostok::particle::particle_domain_complex *)this,
    (int)&this->m_domain);
  v3 = s_bm_current_air_resistance;
  this->m_domain.m_translate.x = 0.0;
  this->m_domain.m_translate.y = FLOAT_10_0;
  this->m_domain.m_translate.z = 0.0;
  this->m_domain.m_scale.x = v3;
  this->m_domain.m_scale.y = v3;
  this->m_domain.m_scale.z = v3;
  this->m_domain.m_rotate.x = 0.0;
  this->m_domain.m_rotate.y = 0.0;
  this->m_domain.m_rotate.z = 0.0;
  this->m_domain.m_inner_radius = c_anim_center;
  this->m_domain.m_outer_radius = c_anim_center;
  this->m_domain.m_domain_type = 5;
  this->m_is_reverse = 0;
}
