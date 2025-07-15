bool __fastcall vostok::math::plane::intersect_ray(
        const vostok::math::float3 *direction,
        const vostok::math::float3 *position,
        vostok::math::plane *this,
        float *distance)
{
  float z; // xmm2_4
  float y; // xmm3_4
  float v7; // xmm0_4

  z = this->normal.z;
  y = this->normal.y;
  if ( fabs((float)((float)(direction->y * y) + (float)(direction->z * z)) + (float)(direction->x * this->normal.x)) < 0.0000001 )
    return 0;
  v7 = -(float)((float)((float)((float)((float)(position->y * y) + (float)(position->z * z))
                              + (float)(position->x * this->normal.x))
                      + this->d)
              / (float)((float)((float)(direction->y * y) + (float)(direction->z * z))
                      + (float)(direction->x * this->normal.x)));
  *distance = v7;
  return v7 > 0.0 || COERCE_FLOAT(LODWORD(v7) & 0x7FFFFFFF) < 0.0000099999997;
}
