unsigned int __thiscall vostok::math::curve_line_ranged_xyz_float::save_binary(
        vostok::math::curve_line_ranged_xyz_float *this,
        vostok::math::curve_line_ranged_base *buffer,
        vostok::mutable_buffer *calc_size,
        bool calc_sizea)
{
  vostok::math::curve_line_ranged_base *v6; // [esp+14h] [ebp+8h]
  vostok::math::curve_line_ranged_base *v7; // [esp+14h] [ebp+8h]
  unsigned int calc_sizeb; // [esp+1Ch] [ebp+10h]
  unsigned int calc_sizec; // [esp+1Ch] [ebp+10h]

  if ( calc_sizea )
  {
    v6 = (vostok::math::curve_line_ranged_base *)vostok::math::curve_line_ranged_base::save_binary(
                                                   buffer + 2,
                                                   calc_size,
                                                   calc_sizea);
    v7 = (vostok::math::curve_line_ranged_base *)((char *)v6
                                                + vostok::math::curve_line_ranged_base::save_binary(
                                                    buffer + 1,
                                                    calc_size,
                                                    calc_sizea));
    return (unsigned int)&v7->m_upper.curve_time_min
         + vostok::math::curve_line_ranged_base::save_binary(buffer, calc_size, calc_sizea)
         + 1;
  }
  else
  {
    *calc_size->m_data++ = LOBYTE(buffer[3].m_upper.curve_time_min);
    --calc_size->m_size;
    calc_sizeb = vostok::math::curve_line_ranged_base::save_binary(buffer + 2, calc_size, 0);
    calc_sizec = vostok::math::curve_line_ranged_base::save_binary(buffer + 1, calc_size, 0) + calc_sizeb;
    return calc_sizec + vostok::math::curve_line_ranged_base::save_binary(buffer, calc_size, 0);
  }
}
