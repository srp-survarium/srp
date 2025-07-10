void __thiscall vostok::math::curve_line_points<float,0>::recalculate_ranges(
        vostok::math::curve_line_points<float,0> *this)
{
  unsigned int num_points; // esi
  vostok::math::curve_point<float> *pointer; // eax
  unsigned int v3; // edx
  float *p_upper_value; // eax
  float v5; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm0_4

  num_points = this->num_points;
  if ( num_points )
  {
    pointer = this->points.pointer;
    v3 = 1;
    this->curve_time_min = pointer->time;
    this->curve_time_max = pointer->time;
    this->curve_value_min = pointer->lower_value;
    this->curve_value_max = pointer->upper_value;
    if ( num_points > 1 )
    {
      p_upper_value = &pointer[1].upper_value;
      do
      {
        v5 = p_upper_value[4];
        if ( this->curve_time_min > v5 )
          this->curve_time_min = v5;
        v6 = p_upper_value[4];
        if ( v6 > this->curve_time_max )
          this->curve_time_max = v6;
        v7 = p_upper_value[1];
        if ( this->curve_value_min > v7 )
          this->curve_value_min = v7;
        if ( *p_upper_value > this->curve_value_max )
          this->curve_value_max = *p_upper_value;
        ++v3;
        p_upper_value += 6;
      }
      while ( v3 < num_points );
    }
  }
}
