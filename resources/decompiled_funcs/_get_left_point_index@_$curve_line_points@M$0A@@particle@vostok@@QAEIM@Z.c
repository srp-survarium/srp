unsigned int __thiscall vostok::particle::curve_line_points<float,0>::get_left_point_index(
        vostok::particle::curve_line_points<float,0> *this,
        float time)
{
  unsigned int i; // [esp+Ch] [ebp-4h]

  if ( !this->num_points || this->points.pointer->time >= time )
    return 0;
  if ( time >= this->points.pointer[this->num_points - 1].time )
    return this->num_points - 1;
  for ( i = 1; i < this->num_points; ++i )
  {
    if ( this->points.pointer[i - 1].time <= time && time <= this->points.pointer[i].time )
      return i;
  }
  return 0;
}
