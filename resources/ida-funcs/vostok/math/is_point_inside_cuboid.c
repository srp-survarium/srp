char __usercall vostok::math::is_point_inside_cuboid@<al>(
        const vostok::math::float3 *p@<eax>,
        const vostok::math::cuboid *c@<ecx>)
{
  float z; // xmm1_4
  float y; // xmm2_4
  float x; // xmm3_4
  float *p_y; // eax

  z = p->z;
  y = p->y;
  x = p->x;
  p_y = &c->m_planes[0].plane.normal.y;
  while ( fabs((float)((float)((float)(*(p_y - 1) * x) + (float)(p_y[1] * z)) + (float)(*p_y * y)) + p_y[2]) < 0.0000099999997
       || (float)((float)((float)((float)(*(p_y - 1) * x) + (float)(p_y[1] * z)) + (float)(*p_y * y)) + p_y[2]) >= 0.0 )
  {
    p_y += 5;
    if ( p_y - 1 == (float *)&c[1] )
      return 1;
  }
  return 0;
}
