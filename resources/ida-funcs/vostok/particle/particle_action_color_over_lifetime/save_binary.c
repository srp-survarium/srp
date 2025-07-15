unsigned int __thiscall vostok::particle::particle_action_color_over_lifetime::save_binary(
        vostok::particle::particle_action_color_over_lifetime *this,
        vostok::mutable_buffer *buffer,
        bool calc_size)
{
  return vostok::particle::color_matrix::save_binary(&this->m_color_over_life, buffer, calc_size);
}
