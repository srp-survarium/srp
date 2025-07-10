double __thiscall vostok::math::curve_line_points<float,0>::evaluate(
        vostok::math::curve_line_points<float,0> *this,
        float time,
        float default_value,
        vostok::math::enum_evaluate_time_type time_type,
        float left_range_alpha,
        float right_range_alpha)
{
  unsigned int num_points; // esi
  vostok::math::curve_point<float> *pointer; // edx
  float *p_upper_value; // edi
  float v10; // xmm1_4
  unsigned int v11; // edx
  vostok::math::curve_point<float> *v12; // eax
  vostok::math::curve_point<float> *v13; // ecx
  float *i; // eax
  float v15; // xmm0_4
  float v16; // xmm0_4
  double v17; // st7
  float a_value; // [esp+2Ch] [ebp+8h]
  float b_value; // [esp+34h] [ebp+10h]

  num_points = this->num_points;
  if ( !num_points )
    return default_value;
  pointer = this->points.pointer;
  p_upper_value = &pointer[num_points - 1].upper_value;
  if ( num_points == 1 )
    return left_range_alpha * pointer->upper_value + (1.0 - left_range_alpha) * pointer->lower_value;
  if ( time_type )
  {
    v10 = time;
  }
  else
  {
    v10 = (float)((float)(*(float *)&clear_value - time) * this->curve_time_min) + (float)(this->curve_time_max * time);
    time = v10;
  }
  if ( pointer->time >= v10 )
    return left_range_alpha * pointer->upper_value + (1.0 - left_range_alpha) * pointer->lower_value;
  if ( v10 >= p_upper_value[4] )
    return (1.0 - right_range_alpha) * p_upper_value[1] + right_range_alpha * *p_upper_value;
  v11 = 1;
  v12 = this->points.pointer;
  v13 = v12 + 1;
  for ( i = &v12->time; ; i += 6 )
  {
    if ( *i <= v10 )
    {
      v15 = i[6];
      if ( v10 <= v15 )
      {
        v16 = v15 - *i;
        if ( COERCE_FLOAT(LODWORD(v16) & 0x7FFFFFFF) > 0.0000099999997 )
          break;
      }
    }
    ++v11;
    ++v13;
    if ( v11 >= num_points )
      return default_value;
  }
  a_value = (float)((float)(*(float *)&clear_value - left_range_alpha) * *(i - 3))
          + (float)(*(i - 4) * left_range_alpha);
  b_value = (float)((float)(*(float *)&clear_value - right_range_alpha) * v13->lower_value)
          + (float)(v13->upper_value * right_range_alpha);
  if ( *((_DWORD *)i + 1) || v13->interp_type )
    return vostok::math::cubic_interpolation<float,float>(
             a_value,
             *(i - 1),
             b_value,
             v13->tangent_in,
             (float)(v10 - *i) / v16);
  v17 = (time - *i) / v16;
  return (1.0 - v17) * a_value + v17 * b_value;
}
