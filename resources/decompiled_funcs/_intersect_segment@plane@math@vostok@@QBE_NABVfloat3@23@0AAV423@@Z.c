BOOL __userpurge vostok::math::plane::intersect_segment@<eax>(
        const vostok::math::float3 *first@<ecx>,
        const vostok::math::float3 *second@<edx>,
        vostok::math::float3 *intersection_position@<esi>,
        vostok::math::plane *this)
{
  float y; // xmm6_4
  float x; // xmm5_4
  float v7; // xmm3_4
  float v8; // xmm4_4
  float z; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  int v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm3_4
  float v16; // ecx
  __int64 v18; // [esp+0h] [ebp-Ch]
  float thisa; // [esp+10h] [ebp+4h]

  y = this->normal.y;
  x = first->x;
  v7 = second->y - first->y;
  v8 = second->z - first->z;
  z = this->normal.z;
  thisa = this->normal.x;
  v10 = second->x - first->x;
  v11 = (float)((float)(thisa * v10) + (float)(y * v7)) + (float)(z * v8);
  v12 = (float)((float)((float)(z * first->z) + (float)(y * first->y)) + (float)(thisa * first->x)) + this->d;
  if ( v11 == 0.0 )
    v13 = LODWORD(v12) & 0x7FFFFFFF;
  else
    *(float *)&v13 = v12 / v11;
  v14 = -*(float *)&v13;
  v15 = (float)(v7 * v14) + first->y;
  v16 = first->z + (float)(v8 * v14);
  *(float *)&v18 = x + (float)(v10 * v14);
  *((float *)&v18 + 1) = v15;
  *(_QWORD *)&intersection_position->x = v18;
  intersection_position->z = v16;
  return v14 >= 0.0 && *(float *)&clear_value >= v14;
}
