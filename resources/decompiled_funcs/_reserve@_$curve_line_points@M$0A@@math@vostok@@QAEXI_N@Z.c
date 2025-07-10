void __thiscall vostok::math::curve_line_points<float,0>::reserve(
        vostok::math::curve_line_points<float,0> *this,
        unsigned int num,
        bool __formal)
{
  vostok::math::curve_point<float> *pointer; // eax

  if ( this->num_points )
  {
    pointer = this->points.pointer;
    if ( pointer )
      pt3free(pointer);
    this->points.pointer = 0;
    this->num_points = 0;
  }
  this->num_points = num;
  if ( num )
  {
    this->points.pointer = (vostok::math::curve_point<float> *)pt3malloc(24 * num);
    vostok::math::curve_line_points<float,0>::recalculate_ranges(this);
  }
}
