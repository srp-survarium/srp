BOOL __usercall vostok::collision::is_inside_capsule@<eax>(
        const vostok::math::float3 *capsule_origin@<ecx>,
        const vostok::math::float3 *capsule_displacement@<eax>,
        const vostok::math::float3 *vertex,
        float squared_capsule_radius)
{
  float y; // xmm4_4
  float x; // xmm2_4
  float v6; // xmm0_4
  const vostok::math::float4x4 *v7; // xmm5_4
  float v8; // xmm1_4
  float v10; // [esp+0h] [ebp-10h]
  float v11; // [esp+4h] [ebp-Ch]
  float z; // [esp+Ch] [ebp-4h]
  float vertexa; // [esp+14h] [ebp+4h]

  y = vertex->y;
  x = vertex->x;
  z = vertex->z;
  v11 = capsule_origin->y;
  v10 = capsule_displacement->z;
  vertexa = capsule_displacement->y;
  v6 = capsule_displacement->x;
  v7 = 0;
  v8 = (float)((float)((float)(v10 * (float)(z - capsule_origin->z))
                     + (float)(capsule_displacement->x * (float)(x - capsule_origin->x)))
             + (float)(vertexa * (float)(y - v11)))
     / (float)((float)((float)(v10 * v10) + (float)(vertexa * vertexa)) + (float)(v6 * v6));
  if ( v8 <= 0.0 || (v7 = clear_value, *(float *)&clear_value < v8) )
    v8 = *(float *)&v7;
  return squared_capsule_radius >= (float)((float)((float)((float)(z - (float)(capsule_origin->z + (float)(v10 * v8)))
                                                         * (float)(z - (float)(capsule_origin->z + (float)(v10 * v8))))
                                                 + (float)((float)(y - (float)(v11 + (float)(vertexa * v8)))
                                                         * (float)(y - (float)(v11 + (float)(vertexa * v8)))))
                                         + (float)((float)(x - (float)(capsule_origin->x + (float)(v6 * v8)))
                                                 * (float)(x - (float)(capsule_origin->x + (float)(v6 * v8)))));
}
