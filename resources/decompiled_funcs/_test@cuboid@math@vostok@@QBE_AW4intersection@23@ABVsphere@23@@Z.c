int __usercall vostok::math::cuboid::test@<eax>(
        vostok::math::cuboid *this@<eax>,
        const vostok::math::sphere *sphere@<edx>)
{
  vostok::math::cuboid *v2; // esi
  bool v3; // cl
  float w; // xmm1_4
  float *p_y; // eax
  float v6; // xmm0_4

  v2 = this + 1;
  v3 = 1;
  w = sphere->vector.w;
  p_y = &this->m_planes[0].plane.normal.y;
  do
  {
    v6 = (float)((float)((float)(*(p_y - 1) * sphere->vector.x) + (float)(p_y[1] * sphere->vector.z))
               + (float)(*p_y * sphere->vector.y))
       + p_y[2];
    if ( (float)(w + v6) < 0.0 )
      return 2;
    v3 = v3 && (float)(v6 - w) <= 0.0;
    p_y += 5;
  }
  while ( p_y - 1 != (float *)v2 );
  if ( v3 )
    return 1;
  else
    return 3;
}
