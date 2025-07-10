vostok::math::intersection __usercall vostok::math::aabb_plane::test@<eax>(
        vostok::math::aabb_plane *this@<ecx>,
        const vostok::math::aabb *aabb@<eax>)
{
  float z; // xmm2_4
  float y; // xmm1_4
  float d; // xmm3_4
  const unsigned int *v5; // edx
  vostok::math::intersection result; // eax
  float v7; // xmm0_4

  z = this->plane.normal.z;
  y = this->plane.normal.y;
  d = this->plane.d;
  v5 = aabb_lut[this->m_lut_id & 7];
  if ( (float)((float)((float)((float)(this->plane.normal.x * *(&aabb->min.x + *v5))
                             + (float)(z * *(&aabb->min.x + v5[2])))
                     + (float)(y * *(&aabb->min.x + v5[1])))
             + d) < 0.0 )
    return 2;
  v7 = (float)((float)((float)(this->plane.normal.x * *(&aabb->min.x + aabb_lut[this->m_lut_id >> 3][0]))
                     + (float)(z * *(&aabb->min.x + aabb_lut[this->m_lut_id >> 3][2])))
             + (float)(y * *(&aabb->min.x + dword_9436E4[3 * (this->m_lut_id >> 3)])))
     + d;
  result = intersection_intersect;
  if ( v7 >= 0.0 )
    return 1;
  return result;
}
