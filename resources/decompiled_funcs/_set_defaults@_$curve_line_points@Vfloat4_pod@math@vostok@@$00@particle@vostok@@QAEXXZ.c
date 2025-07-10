void __thiscall vostok::particle::curve_line_points<vostok::math::float4_pod,1>::set_defaults(
        vostok::particle::curve_line_points<vostok::math::float4_pod,1> *this)
{
  this->points.pointer = 0;
  this->num_points = 0;
  vostok::memory::zero(&this->curve_value_min, 0x10u);
  vostok::memory::zero(&this->curve_value_max, 0x10u);
  vostok::memory::zero(this, 4u);
  vostok::memory::zero(&this->curve_time_max, 4u);
}
