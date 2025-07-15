void __thiscall vostok::particle::particle_action_light::set_defaults(
        vostok::particle::particle_action_light *this,
        bool mt_alloc)
{
  vostok::math::curve_line_ranged_float *p_m_radius; // edi

  p_m_radius = &this->m_radius;
  this->m_next.pointer = 0;
  this->m_visibility = 1;
  vostok::math::curve_line_ranged_base::set_defaults(&this->m_radius.m_line);
  p_m_radius->m_evaluate_type = age_evaluate_type;
  vostok::math::curve_line_ranged_base::set_defaults(&this->m_attenuation.m_line);
  this->m_attenuation.m_evaluate_type = age_evaluate_type;
  vostok::math::curve_line_ranged_base::set_defaults(&this->m_intensity.m_line);
  this->m_intensity.m_evaluate_type = age_evaluate_type;
  vostok::math::curve_line_ranged_base::set_defaults(&this->m_diffuse_factor.m_line);
  this->m_diffuse_factor.m_evaluate_type = age_evaluate_type;
  vostok::math::curve_line_ranged_base::set_defaults(&this->m_specular_factor.m_line);
  this->m_specular_factor.m_evaluate_type = age_evaluate_type;
  vostok::math::curve_line_color::set_defaults(&this->m_color);
  this->m_static_shadows = 0;
}
