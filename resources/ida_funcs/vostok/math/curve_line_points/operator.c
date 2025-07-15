void __thiscall vostok::math::curve_line_points<vostok::math::float4_pod,1>::operator=(
        vostok::math::curve_line_points<vostok::math::float4_pod,1> *this,
        const vostok::math::curve_line_points<vostok::math::float4_pod,1> *other)
{
  vostok::math::curve_line_points<vostok::math::float4_pod,1> *v2; // esi
  unsigned int v3; // edx
  int v4; // eax
  _BYTE v6[72]; // [esp+10h] [ebp-48h] BYREF

  v2 = this;
  this->curve_time_min = other->curve_time_min;
  this->curve_time_max = other->curve_time_max;
  this->curve_value_min = other->curve_value_min;
  this->curve_value_max = other->curve_value_max;
  vostok::math::curve_line_points<vostok::math::float4_pod,1>::reserve(this, other->num_points, 1);
  v3 = 0;
  if ( other->num_points )
  {
    v4 = 0;
    do
    {
      qmemcpy(v6, &other->points.pointer[v4], sizeof(v6));
      ++v3;
      qmemcpy(&this->points.pointer[v4], v6, sizeof(this->points.pointer[v4]));
      ++v4;
    }
    while ( v3 < other->num_points );
    v2 = this;
  }
  vostok::math::curve_line_points<vostok::math::float4_pod,1>::recalculate_ranges(v2);
}
