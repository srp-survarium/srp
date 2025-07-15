void __thiscall vostok::particle::particle_action_color_over_lifetime::load_binary(
        vostok::particle::particle_action_color_over_lifetime *this,
        vostok::mutable_buffer *buffer)
{
  vostok::particle::color_matrix *p_m_color_over_life; // [esp+4h] [ebp-Ch]

  p_m_color_over_life = &this->m_color_over_life;
  this->m_color_over_life.m_points.pointer = (vostok::particle::color_matrix_point_type *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                                                                            (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)this,
                                                                                            (int)buffer);
  vostok::mutable_buffer::operator+=(
    (vostok::mutable_buffer *)(24 * p_m_color_over_life->m_num_columns * p_m_color_over_life->m_num_rows),
    buffer);
}
