bool __userpurge vostok::math::plane::intersect_ray@<al>(
        const vostok::math::float3 *position@<esi>,
        const vostok::math::float3 *direction@<edx>,
        float *distance@<eax>,
        vostok::math::plane *this)
{
  vostok::math::plane *v4; // ecx
  float z; // xmm2_4
  float y; // xmm3_4
  float x; // xmm4_4
  float v8; // xmm1_4
  bool result; // al
  float v10; // xmm0_4

  v4 = this;
  z = this->normal.z;
  y = this->normal.y;
  x = this->normal.x;
  v8 = (float)((float)(direction->y * y) + (float)(direction->z * z)) + (float)(direction->x * this->normal.x);
  this = (vostok::math::plane *)(LODWORD(v8) & 0x7FFFFFFF);
  if ( COERCE_FLOAT(LODWORD(v8) & 0x7FFFFFFF) < 0.0000001 )
    return 0;
  LODWORD(v10) = COERCE_UNSIGNED_INT(
                   (float)((float)((float)((float)(position->y * y) + (float)(position->z * z))
                                 + (float)(position->x * x))
                         + v4->d)
                 / v8)
               ^ _mask__NegFloat_;
  *distance = v10;
  result = 1;
  if ( v10 <= 0.0 )
  {
    this = 0;
    if ( !vostok::math::is_similar<float>(distance, (const float *)&this, 0.0000099999997) )
      return 0;
  }
  return result;
}
