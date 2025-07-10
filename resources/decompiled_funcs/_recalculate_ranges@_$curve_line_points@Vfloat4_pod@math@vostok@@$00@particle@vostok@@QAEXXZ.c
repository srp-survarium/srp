void __thiscall vostok::particle::curve_line_points<vostok::math::float4_pod,1>::recalculate_ranges(
        vostok::particle::curve_line_points<vostok::math::float4_pod,1> *this)
{
  vostok::particle::curve_point<vostok::math::float4_pod> *pointer; // ecx
  vostok::particle::curve_point<vostok::math::float4_pod> *point; // [esp+4h] [ebp-8h]
  unsigned int i; // [esp+8h] [ebp-4h]

  if ( this->num_points )
  {
    this->curve_time_min = this->points.pointer->time;
    this->curve_time_max = this->points.pointer->time;
    this->curve_value_min = this->points.pointer->lower_value;
    pointer = this->points.pointer;
    this->curve_value_max.x = pointer->upper_value.x;
    this->curve_value_max.y = pointer->upper_value.y;
    this->curve_value_max.z = pointer->upper_value.z;
    this->curve_value_max.w = pointer->upper_value.w;
    for ( i = 1; i < this->num_points; ++i )
    {
      point = &this->points.pointer[i];
      if ( this->curve_time_min > point->time )
        this->curve_time_min = point->time;
      if ( point->time > this->curve_time_max )
        this->curve_time_max = point->time;
      if ( vostok::math::operator<(&point->lower_value, &this->curve_value_min) )
      {
        this->curve_value_min.x = point->lower_value.x;
        this->curve_value_min.y = point->lower_value.y;
        this->curve_value_min.z = point->lower_value.z;
        this->curve_value_min.w = point->lower_value.w;
      }
      if ( vostok::math::operator>(&point->upper_value, &this->curve_value_max) )
      {
        this->curve_value_max.x = point->upper_value.x;
        this->curve_value_max.y = point->upper_value.y;
        this->curve_value_max.z = point->upper_value.z;
        this->curve_value_max.w = point->upper_value.w;
      }
    }
  }
}
