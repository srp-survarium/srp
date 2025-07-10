double __thiscall vostok::particle::particle_emitter_instance::get_max_particle_lifetime(
        vostok::particle::particle_emitter_instance *this)
{
  float curve_value_max; // xmm0_4

  curve_value_max = this->m_emitter->m_particle_lifetime_curve.m_line.m_upper.curve_value_max;
  vostok::math::max();
  return curve_value_max;
}
