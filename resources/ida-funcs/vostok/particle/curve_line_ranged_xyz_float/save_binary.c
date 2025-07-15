unsigned int __thiscall vostok::particle::curve_line_ranged_xyz_float::save_binary(
        vostok::particle::curve_line_ranged_xyz_float *this,
        vostok::mutable_buffer *buffer,
        bool calc_size)
{
  unsigned int v3; // esi
  unsigned int v4; // esi
  unsigned int v5; // esi
  unsigned int v6; // edi
  const vostok::variant<32> **v8; // eax
  unsigned int v9; // esi
  unsigned int v10; // esi
  unsigned int v11; // esi
  unsigned int v12; // edi
  unsigned int v14; // [esp+28h] [ebp-38h]
  unsigned int v15; // [esp+50h] [ebp-10h]
  unsigned __int8 tmp; // [esp+5Fh] [ebp-1h] BYREF

  if ( calc_size )
  {
    v3 = vostok::particle::curve_line_points<float,0>::save_binary(&this->m_line_x.m_upper, buffer, calc_size);
    v15 = vostok::particle::curve_line_points<float,0>::save_binary(&this->m_line_x.m_lower, buffer, calc_size) + v3;
    v4 = vostok::particle::curve_line_points<float,0>::save_binary(&this->m_line_y.m_upper, buffer, calc_size);
    v5 = vostok::particle::curve_line_points<float,0>::save_binary(&this->m_line_y.m_lower, buffer, calc_size)
       + v4
       + v15;
    v6 = vostok::particle::curve_line_points<float,0>::save_binary(&this->m_line_z.m_lower, buffer, calc_size);
    return v5
         + v6
         + vostok::particle::curve_line_points<float,0>::save_binary(&this->m_line_z.m_upper, buffer, calc_size)
         + 1;
  }
  else
  {
    tmp = this->m_evaluate_type;
    v8 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
           (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)this,
           (int)buffer);
    vostok::memory::copy(v8, 1u, &tmp, 1u);
    vostok::mutable_buffer::operator+=((vostok::mutable_buffer *)1, buffer);
    v9 = vostok::particle::curve_line_points<float,0>::save_binary(&this->m_line_x.m_upper, buffer, 0);
    v14 = vostok::particle::curve_line_points<float,0>::save_binary(&this->m_line_x.m_lower, buffer, 0) + v9;
    v10 = vostok::particle::curve_line_points<float,0>::save_binary(&this->m_line_y.m_upper, buffer, 0);
    v11 = vostok::particle::curve_line_points<float,0>::save_binary(&this->m_line_y.m_lower, buffer, 0) + v10 + v14;
    v12 = vostok::particle::curve_line_points<float,0>::save_binary(&this->m_line_z.m_lower, buffer, 0);
    return v11 + v12 + vostok::particle::curve_line_points<float,0>::save_binary(&this->m_line_z.m_upper, buffer, 0);
  }
}
