void __thiscall vostok::particle::curve_line_ranged_xyz_float::load_binary(
        vostok::particle::curve_line_ranged_xyz_float *this,
        vostok::mutable_buffer *buffer)
{
  const vostok::variant<32> **v2; // eax
  unsigned __int8 tmp; // [esp+6Bh] [ebp-1h] BYREF

  v2 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
         (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)this,
         (int)buffer);
  vostok::memory::copy(&tmp, 1u, v2, 1u);
  vostok::mutable_buffer::operator+=((vostok::mutable_buffer *)1, buffer);
  this->m_evaluate_type = tmp;
  vostok::particle::curve_line_points<float,0>::load_binary(&this->m_line_x.m_upper, buffer);
  vostok::particle::curve_line_points<float,0>::load_binary(&this->m_line_x.m_lower, buffer);
  vostok::particle::curve_line_points<float,0>::load_binary(&this->m_line_y.m_upper, buffer);
  vostok::particle::curve_line_points<float,0>::load_binary(&this->m_line_y.m_lower, buffer);
  vostok::particle::curve_line_points<float,0>::load_binary(&this->m_line_z.m_upper, buffer);
  vostok::particle::curve_line_points<float,0>::load_binary(&this->m_line_z.m_lower, buffer);
}
