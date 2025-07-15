bool __usercall vostok::collision::is_inside_obb@<al>(
        const vostok::math::float3 *obb@<edx>,
        const vostok::math::float4x4 *obb_transform@<eax>,
        const vostok::math::float3 *vertex)
{
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm0_4

  v3 = vertex->y - obb_transform->c.y;
  v4 = vertex->z - obb_transform->c.z;
  v5 = vertex->x - obb_transform->c.x;
  return fabs(
           (float)((float)(obb_transform->i.z * v4) + (float)(obb_transform->i.y * v3))
         + (float)(obb_transform->i.x * v5)) <= obb->x
      && fabs(
           (float)((float)(obb_transform->j.z * v4) + (float)(obb_transform->j.y * v3))
         + (float)(obb_transform->j.x * v5)) <= obb->y
      && fabs(
           (float)((float)(obb_transform->k.z * v4) + (float)(obb_transform->k.y * v3))
         + (float)(obb_transform->k.x * v5)) <= obb->z;
}
