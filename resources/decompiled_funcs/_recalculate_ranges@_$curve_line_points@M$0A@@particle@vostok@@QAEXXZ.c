void __thiscall vostok::particle::curve_line_points<float,0>::recalculate_ranges(
        vostok::particle::curve_line_points<float,0> *this)
{
  vostok::particle::curve_point<float> *point; // [esp+4h] [ebp-8h]
  unsigned int i; // [esp+8h] [ebp-4h]

  if ( this->num_points )
  {
    this->curve_time_min = this->points.pointer->time;
    this->curve_time_max = this->points.pointer->time;
    this->curve_value_min = this->points.pointer->lower_value;
    this->curve_value_max = this->points.pointer->upper_value;
    for ( i = 1; i < this->num_points; ++i )
    {
      point = &this->points.pointer[i];
      if ( this->curve_time_min > point->time )
        this->curve_time_min = point->time;
      if ( point->time > this->curve_time_max )
        this->curve_time_max = point->time;
      if ( this->curve_value_min > point->lower_value )
        this->curve_value_min = point->lower_value;
      if ( point->upper_value > this->curve_value_max )
        this->curve_value_max = point->upper_value;
    }
  }
}
