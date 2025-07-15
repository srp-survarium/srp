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


void __thiscall vostok::math::curve_line_points<vostok::math::float4_pod,1>::recalculate_ranges(
        vostok::math::curve_line_points<vostok::math::float4_pod,1> *this)
{
  unsigned int num_points; // edx
  vostok::math::curve_point<vostok::math::float4_pod> *pointer; // eax
  unsigned int v3; // esi
  vostok::math::float4_pod *p_upper_value; // eax
  float x; // xmm0_4
  float v6; // xmm0_4

  num_points = this->num_points;
  if ( num_points )
  {
    pointer = this->points.pointer;
    this->curve_time_min = pointer->time;
    v3 = 1;
    this->curve_time_max = pointer->time;
    this->curve_value_min = pointer->lower_value;
    this->curve_value_max = pointer->upper_value;
    if ( num_points > 1 )
    {
      p_upper_value = &pointer[1].upper_value;
      do
      {
        x = p_upper_value[4].x;
        if ( this->curve_time_min > x )
          this->curve_time_min = x;
        v6 = p_upper_value[4].x;
        if ( v6 > this->curve_time_max )
          this->curve_time_max = v6;
        if ( this->curve_value_min.x > p_upper_value[1].x
          && this->curve_value_min.y > p_upper_value[1].y
          && this->curve_value_min.z > p_upper_value[1].z
          && this->curve_value_min.w > p_upper_value[1].w )
        {
          this->curve_value_min = p_upper_value[1];
        }
        if ( p_upper_value->x > this->curve_value_max.x
          && p_upper_value->y > this->curve_value_max.y
          && p_upper_value->z > this->curve_value_max.z
          && p_upper_value->w > this->curve_value_max.w )
        {
          this->curve_value_max = *p_upper_value;
        }
        ++v3;
        p_upper_value = (vostok::math::float4_pod *)((char *)p_upper_value + 72);
      }
      while ( v3 < num_points );
    }
  }
}
