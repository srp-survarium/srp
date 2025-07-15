void __userpurge vostok::math::curve_line_ranged_base::evaluate(
        vostok::math::curve_line_ranged_base *this@<esi>,
        unsigned int seed@<eax>,
        float time,
        float default_value,
        vostok::math::enum_evaluate_type evaluate_type,
        vostok::math::enum_evaluate_time_type time_type)
{
  unsigned int num_points; // eax
  vostok::math::curve_point<float> *pointer; // ecx
  unsigned int v8; // eax
  unsigned int v9; // edx
  float *p_time; // ecx
  vostok::math::curve_line_points<float,0> *v11; // ecx
  double v12; // st7
  double v13; // st7
  vostok::math::curve_line_points<float,0> *v14; // ecx
  vostok::math::curve_line_points<float,0> *v15; // ecx
  float v16; // [esp+14h] [ebp-Ch]
  float v17; // [esp+18h] [ebp-8h]
  vostok::math::random32 v18; // [esp+1Ch] [ebp-4h] BYREF
  float curve_time_min; // [esp+28h] [ebp+8h]
  float v20; // [esp+28h] [ebp+8h]
  float curve_time_max; // [esp+30h] [ebp+10h]

  v18.m_seed = seed;
  num_points = this->m_upper.num_points;
  if ( !num_points )
    goto LABEL_10;
  pointer = this->m_upper.points.pointer;
  if ( pointer->time >= time )
    goto LABEL_10;
  if ( time >= pointer[num_points - 1].time )
  {
    v8 = num_points - 1;
    goto LABEL_11;
  }
  v9 = 1;
  if ( num_points > 1 )
  {
    p_time = &pointer[1].time;
    while ( *(p_time - 6) > time || time > *p_time )
    {
      ++v9;
      p_time += 6;
      if ( v9 >= num_points )
        goto LABEL_10;
    }
    v8 = v9;
  }
  else
  {
LABEL_10:
    v8 = 0;
  }
LABEL_11:
  while ( v8 )
  {
    --v8;
    v18.m_seed = 134775813 * v18.m_seed + 1;
  }
  v17 = vostok::math::random32::random_f(&v18, 1.0);
  v12 = vostok::math::random32::random_f(&v18, 1.0);
  if ( evaluate_type )
  {
    if ( this->m_upper.curve_time_max <= this->m_lower.curve_time_max )
      curve_time_max = this->m_lower.curve_time_max;
    else
      curve_time_max = this->m_upper.curve_time_max;
    if ( this->m_lower.curve_time_min <= this->m_upper.curve_time_min )
      curve_time_min = this->m_lower.curve_time_min;
    else
      curve_time_min = this->m_upper.curve_time_min;
    v13 = vostok::math::random_float(0.0, 1.0);
    v20 = v13 * curve_time_max + (1.0 - v13) * curve_time_min;
    vostok::math::curve_line_points<float,0>::evaluate(
      v14,
      (int)&this->m_lower,
      v20,
      default_value,
      range_time_type,
      0.0,
      0.0);
    vostok::math::random_float(0.0, 1.0);
    vostok::math::curve_line_points<float,0>::evaluate(v15, (int)this, v20, default_value, range_time_type, 0.0, 0.0);
  }
  else
  {
    v16 = v12;
    vostok::math::curve_line_points<float,0>::evaluate(v11, (int)this, time, default_value, time_type, v17, v16);
  }
}
