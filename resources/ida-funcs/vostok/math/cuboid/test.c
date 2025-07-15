int __usercall vostok::math::cuboid::test@<eax>(
        vostok::math::cuboid *this@<ecx>,
        const vostok::math::sphere *sphere@<eax>)
{
  bool v2; // bl
  float x; // xmm3_4
  float y; // xmm4_4
  float z; // xmm5_4
  float w; // xmm2_4
  float *p_y; // eax
  float v8; // xmm0_4

  v2 = 1;
  x = sphere->vector.x;
  y = sphere->vector.y;
  z = sphere->vector.z;
  w = sphere->vector.w;
  p_y = &this->m_planes[0].plane.normal.y;
  do
  {
    v8 = (float)((float)((float)(*(p_y - 1) * x) + (float)(p_y[1] * z)) + (float)(*p_y * y)) + p_y[2];
    if ( (float)(w + v8) < 0.0 )
      return 2;
    v2 = v2 && (float)(v8 - w) <= 0.0;
    p_y += 5;
  }
  while ( p_y - 1 != (float *)&this[1] );
  if ( v2 )
    return 1;
  return 3;
}
