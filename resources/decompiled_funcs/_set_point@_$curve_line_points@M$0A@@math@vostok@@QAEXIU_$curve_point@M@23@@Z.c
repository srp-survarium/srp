void __thiscall vostok::math::curve_line_points<float,0>::set_point(
        vostok::math::curve_line_points<float,0> *this,
        unsigned int index,
        vostok::math::curve_point<float> point)
{
  this->points.pointer[index] = point;
}
