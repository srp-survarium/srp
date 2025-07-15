BOOL __fastcall vostok::math::plane::intersect_segment(
        const vostok::math::float3 *first,
        const vostok::math::float3 *second,
        vostok::math::plane *this,
        vostok::math::float3 *intersection_position)
{
  float y; // xmm6_4
  float v6; // xmm2_4
  float v7; // xmm3_4
  float z; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm4_4
  float v11; // xmm0_4
  int v12; // xmm0_4
  float v13; // xmm0_4
  __int64 v15; // [esp+4h] [ebp-8h]
  float x; // [esp+14h] [ebp+8h]

  y = this->normal.y;
  v6 = second->y - first->y;
  v7 = second->z - first->z;
  z = this->normal.z;
  x = this->normal.x;
  v9 = second->x - first->x;
  v10 = (float)((float)(x * v9) + (float)(y * v6)) + (float)(z * v7);
  v11 = (float)((float)((float)(z * first->z) + (float)(y * first->y)) + (float)(x * first->x)) + this->d;
  if ( v10 == 0.0 )
    v12 = LODWORD(v11) & 0x7FFFFFFF;
  else
    *(float *)&v12 = v11 / v10;
  LODWORD(v13) = v12 ^ _mask__NegFloat_;
  *(float *)&v15 = (float)(v6 * v13) + first->y;
  *((float *)&v15 + 1) = first->z + (float)(v7 * v13);
  intersection_position->x = first->x + (float)(v9 * v13);
  *(_QWORD *)&intersection_position->elements[1] = v15;
  return v13 >= 0.0 && s_bm_current_air_resistance >= v13;
}
