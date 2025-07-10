void __thiscall vostok::math::curve_line_points<float,0>::~curve_line_points<float,0>(
        vostok::math::curve_line_points<float,0> *this)
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
}
