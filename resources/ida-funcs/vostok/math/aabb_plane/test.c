int __usercall vostok::math::aabb_plane::test@<eax>(vostok::math::aabb_plane *this@<ecx>, int a2@<esi>)
{
  float v2; // xmm3_4
  float v3; // xmm2_4
  float v4; // xmm4_4
  const unsigned int *v5; // eax

  v2 = *(float *)(a2 + 8);
  v3 = *(float *)(a2 + 4);
  v4 = *(float *)(a2 + 12);
  v5 = aabb_lut[*(_DWORD *)(a2 + 16) & 7];
  if ( (float)((float)((float)((float)(*(float *)a2 * *(&this->plane.normal.x + *v5))
                             + (float)(v2 * *(&this->plane.normal.x + v5[2])))
                     + (float)(v3 * *(&this->plane.normal.x + v5[1])))
             + v4) < 0.0 )
    return 2;
  if ( (float)((float)((float)((float)(*(float *)a2 * *(&this->plane.normal.x + aabb_lut[*(_DWORD *)(a2 + 16) >> 3][0]))
                             + (float)(v2 * *(&this->plane.normal.x + aabb_lut[*(_DWORD *)(a2 + 16) >> 3][2])))
                     + (float)(v3 * *(&this->plane.normal.x + aabb_lut[*(_DWORD *)(a2 + 16) >> 3][1])))
             + v4) < 0.0 )
    return 3;
  return 1;
}
