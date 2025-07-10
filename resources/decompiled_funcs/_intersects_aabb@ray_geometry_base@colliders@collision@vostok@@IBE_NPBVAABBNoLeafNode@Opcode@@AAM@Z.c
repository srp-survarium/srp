bool __userpurge vostok::collision::colliders::ray_geometry_base::intersects_aabb@<al>(
        vostok::collision::colliders::ray_geometry_base *this@<esi>,
        const Opcode::AABBNoLeafNode *node@<eax>,
        float *distance)
{
  float z; // ecx
  float v4; // edx
  __int64 v6; // [esp+A8h] [ebp-44h]
  __int64 v7; // [esp+B4h] [ebp-38h]
  __int64 v8; // [esp+C0h] [ebp-2Ch]
  float v9; // [esp+C8h] [ebp-24h]
  vostok::collision::colliders::sse::aabb_a16 v10; // [esp+CCh] [ebp-20h] BYREF

  z = node->mAABB.mCenter.z;
  v4 = node->mAABB.mExtents.z;
  v6 = *(_QWORD *)&node->mAABB.mCenter.x;
  v7 = *(_QWORD *)&node->mAABB.mExtents.x;
  *(float *)&v8 = node->mAABB.mCenter.x - *(float *)&v7;
  *((float *)&v8 + 1) = *((float *)&v6 + 1) - *((float *)&v7 + 1);
  v9 = z + v4;
  *(_QWORD *)&v10.min.x = v8;
  v10.min.z = z - v4;
  *(float *)&v8 = *(float *)&v7 + *(float *)&v6;
  *((float *)&v8 + 1) = *((float *)&v6 + 1) + *((float *)&v7 + 1);
  v10.min.padding = 0.0;
  *(_QWORD *)&v10.max.x = v8;
  v10.max.z = z + v4;
  v10.max.padding = 0.0;
  return vostok::collision::colliders::ray_aabb_collider::intersects_aabb_sse(
           &this->m_ray_aabb_collider,
           &v10,
           distance);
}
