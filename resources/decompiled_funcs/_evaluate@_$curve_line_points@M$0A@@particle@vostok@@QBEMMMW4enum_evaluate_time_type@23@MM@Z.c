double __thiscall vostok::particle::curve_line_points<float,0>::evaluate(
        vostok::particle::curve_line_points<float,0> *this,
        float time,
        float default_value,
        vostok::particle::enum_evaluate_time_type time_type,
        float left_range_alpha,
        float right_range_alpha)
{
  float dist; // [esp+2Ch] [ebp-20h]
  float a_value; // [esp+30h] [ebp-1Ch]
  vostok::particle::curve_point<float> *b; // [esp+34h] [ebp-18h]
  float b_value; // [esp+38h] [ebp-14h]
  vostok::particle::curve_point<float> *a; // [esp+3Ch] [ebp-10h]
  unsigned int i; // [esp+40h] [ebp-Ch]
  vostok::particle::curve_point<float> *last_point; // [esp+44h] [ebp-8h]
  vostok::particle::curve_point<float> *first_point; // [esp+48h] [ebp-4h]

  if ( !this->num_points )
    return default_value;
  first_point = this->points.pointer;
  last_point = &first_point[this->num_points - 1];
  if ( this->num_points == 1 )
    return vostok::particle::linear_interpolation<float>(
             first_point->lower_value,
             first_point->upper_value,
             left_range_alpha);
  if ( time_type == linear_time_type )
    time = vostok::particle::linear_interpolation<float>(this->curve_time_min, this->curve_time_max, time);
  if ( first_point->time >= time )
    return vostok::particle::linear_interpolation<float>(
             first_point->lower_value,
             first_point->upper_value,
             left_range_alpha);
  if ( time >= last_point->time )
    return vostok::particle::linear_interpolation<float>(
             last_point->lower_value,
             last_point->upper_value,
             right_range_alpha);
  for ( i = 1; i < this->num_points; ++i )
  {
    a = &this->points.pointer[i - 1];
    b = &this->points.pointer[i];
    if ( a->time <= time && time <= b->time )
    {
      dist = b->time - a->time;
      vostok::math::abs();
      if ( dist > 0.0000099999997 )
      {
        a_value = vostok::particle::linear_interpolation<float>(a->lower_value, a->upper_value, left_range_alpha);
        b_value = vostok::particle::linear_interpolation<float>(b->lower_value, b->upper_value, right_range_alpha);
        if ( a->interp_type == curve_interp_type )
          return vostok::particle::cubic_interpolation<float,float>(
                   a_value,
                   a->tangent_out,
                   b_value,
                   b->tangent_in,
                   (float)(time - a->time) / dist);
        if ( a->interp_type == linear_interp_type )
          return vostok::particle::linear_interpolation<float>(a_value, b_value, (float)(time - a->time) / dist);
      }
    }
  }
  return default_value;
}
