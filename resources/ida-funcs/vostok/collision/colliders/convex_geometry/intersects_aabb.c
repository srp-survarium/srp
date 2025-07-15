vostok::math::intersection __userpurge vostok::collision::colliders::convex_geometry::intersects_aabb@<eax>(
        const Opcode::AABBNoLeafNode *node@<eax>,
        vostok::collision::colliders::convex_geometry *this)
{
  float x; // xmm3_4
  float v3; // xmm0_4
  float y; // xmm4_4
  float v5; // xmm1_4
  float z; // xmm5_4
  float v7; // xmm2_4
  __int64 v8; // xmm6_8
  __int64 v10; // [esp+4h] [ebp-24h]
  vostok::math::convex *v11; // [esp+Ch] [ebp-1Ch]
  vostok::math::aabb aabb; // [esp+10h] [ebp-18h] BYREF

  x = node->mAABB.mCenter.x;
  v3 = node->mAABB.mExtents.x;
  y = node->mAABB.mCenter.y;
  v5 = node->mAABB.mExtents.y;
  z = node->mAABB.mCenter.z;
  v7 = node->mAABB.mExtents.z;
  *(float *)&v10 = node->mAABB.mCenter.x - v3;
  *((float *)&v10 + 1) = y - v5;
  v8 = v10;
  aabb.min.z = z - v7;
  *(float *)&v11 = v7 + z;
  *(float *)&v10 = v3 + x;
  *((float *)&v10 + 1) = v5 + y;
  *(_QWORD *)&aabb.min.x = v8;
  *(_QWORD *)&aabb.max.x = v10;
  aabb.max.z = v7 + z;
  return vostok::math::convex::test_inexact(COERCE_VOSTOK_MATH_CONVEX_(v7 + z), &aabb);
}
