vostok::math::intersection __userpurge vostok::collision::colliders::cuboid_object::intersects_aabb@<eax>(
        const vostok::math::float3 *aabb_center@<ecx>,
        const vostok::math::float3 *aabb_extents@<eax>,
        vostok::collision::colliders::cuboid_object *this)
{
  float x; // xmm0_4
  float v4; // xmm3_4
  float y; // xmm4_4
  float z; // xmm5_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  __int64 v9; // xmm6_8
  __int64 v11; // [esp+4h] [ebp-24h]
  vostok::math::cuboid *v12; // [esp+Ch] [ebp-1Ch]
  vostok::math::aabb aabb; // [esp+10h] [ebp-18h] BYREF

  x = aabb_extents->x;
  v4 = aabb_center->x;
  y = aabb_center->y;
  z = aabb_center->z;
  *(float *)&v11 = aabb_center->x - aabb_extents->x;
  v7 = aabb_extents->y;
  *((float *)&v11 + 1) = y - v7;
  v8 = aabb_extents->z;
  v9 = v11;
  aabb.min.z = z - v8;
  *(float *)&v12 = v8 + z;
  *(float *)&v11 = x + v4;
  *((float *)&v11 + 1) = v7 + y;
  *(_QWORD *)&aabb.min.x = v9;
  *(_QWORD *)&aabb.max.x = v11;
  aabb.max.z = v8 + z;
  return vostok::math::cuboid::test_inexact(COERCE_VOSTOK_MATH_CUBOID_(v8 + z), &aabb);
}
