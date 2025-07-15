bool __userpurge vostok::collision::colliders::ray_object::intersects_aabb@<al>(
        vostok::collision::colliders::ray_object *this@<esi>,
        const vostok::math::float3 *node_center@<ecx>,
        const vostok::math::float3 *extents@<eax>,
        float *distance)
{
  float x; // xmm0_4
  float v5; // xmm3_4
  float y; // xmm4_4
  float z; // xmm5_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  __int64 v11; // [esp+24h] [ebp-2Ch]
  float v12; // [esp+2Ch] [ebp-24h]
  vostok::collision::colliders::sse::aabb_a16 v13; // [esp+30h] [ebp-20h] BYREF

  x = extents->x;
  v5 = node_center->x;
  y = node_center->y;
  z = node_center->z;
  *(float *)&v11 = node_center->x - extents->x;
  v8 = extents->y;
  *((float *)&v11 + 1) = y - v8;
  v9 = extents->z;
  v12 = v9 + z;
  *(_QWORD *)&v13.min.x = v11;
  v13.min.z = z - v9;
  *(float *)&v11 = x + v5;
  *((float *)&v11 + 1) = v8 + y;
  v13.min.padding = 0.0;
  *(_QWORD *)&v13.max.x = v11;
  v13.max.z = v9 + z;
  v13.max.padding = 0.0;
  return vostok::collision::colliders::ray_aabb_collider::intersects_aabb_sse(
           &this->m_ray_aabb_collider,
           &v13,
           distance);
}
