void __thiscall vostok::math::curve_line_ranged_xyz_float::load_binary(
        vostok::math::curve_line_ranged_xyz_float *this,
        vostok::math::curve_line_ranged_base *buffer,
        vostok::mutable_buffer *a3)
{
  char *v4; // eax
  vostok::math::curve_line_points<float,0> *v5; // ecx
  vostok::math::curve_line_points<float,0> *v6; // ecx
  unsigned __int8 v7; // [esp+1Bh] [ebp+Fh]

  v4 = a3->m_data + 1;
  v7 = *a3->m_data;
  --a3->m_size;
  a3->m_data = v4;
  LODWORD(buffer[3].m_upper.curve_time_min) = v7;
  vostok::math::curve_line_ranged_base::load_binary(buffer, a3, &this->m_line_x.m_upper);
  vostok::math::curve_line_ranged_base::load_binary(buffer + 1, a3, v5);
  vostok::math::curve_line_ranged_base::load_binary(buffer + 2, a3, v6);
}
