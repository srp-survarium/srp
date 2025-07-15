unsigned int __thiscall vostok::particle::particle_action_light::save_binary(
        vostok::particle::particle_action_light *this,
        vostok::mutable_buffer *buffer,
        bool calc_size)
{
  unsigned int calc_sizea; // [esp+18h] [ebp+Ch]
  unsigned int calc_sizeb; // [esp+18h] [ebp+Ch]
  unsigned int calc_sizec; // [esp+18h] [ebp+Ch]
  unsigned int calc_sized; // [esp+18h] [ebp+Ch]
  unsigned int calc_sizee; // [esp+18h] [ebp+Ch]

  calc_sizea = vostok::math::curve_line_ranged_base::save_binary(&this->m_radius.m_line, buffer, calc_size);
  calc_sizeb = vostok::math::curve_line_ranged_base::save_binary(&this->m_attenuation.m_line, buffer, calc_size)
             + calc_sizea;
  calc_sizec = vostok::math::curve_line_ranged_base::save_binary(&this->m_intensity.m_line, buffer, calc_size)
             + calc_sizeb;
  calc_sized = vostok::math::curve_line_ranged_base::save_binary(&this->m_diffuse_factor.m_line, buffer, calc_size)
             + calc_sizec;
  calc_sizee = vostok::math::curve_line_ranged_base::save_binary(&this->m_specular_factor.m_line, buffer, calc_size)
             + calc_sized;
  return calc_sizee
       + vostok::math::curve_line_points<vostok::math::float4_pod,1>::save_binary(&this->m_color, buffer, calc_size);
}
