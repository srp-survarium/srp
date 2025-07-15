bool __thiscall vostok::collision::aabb_object::ray_test(
        vostok::collision::aabb_object *this,
        const vostok::math::float3 *origin,
        const vostok::math::float3 *direction,
        float max_distance,
        float *distance)
{
  unsigned int v5; // xmm2_4
  unsigned int v6; // xmm3_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  vostok::collision::colliders::ray_aabb_collider *v10; // eax
  vostok::math::float3 v12; // [esp+4h] [ebp-68h] BYREF
  vostok::math::float3 v13; // [esp+10h] [ebp-5Ch] BYREF
  vostok::collision::colliders::sse::aabb_a16 aabb; // [esp+1Ch] [ebp-50h] BYREF
  vostok::collision::colliders::ray_aabb_collider v15; // [esp+3Ch] [ebp-30h] BYREF

  *(float *)&v5 = (float)(this->m_aabb.max.y - this->m_aabb.min.y) * 0.5;
  *(float *)&v6 = (float)(this->m_aabb.max.z - this->m_aabb.min.z) * 0.5;
  v12.x = (float)(this->m_aabb.max.x - this->m_aabb.min.x) * 0.5;
  v7 = this->m_aabb.max.x + this->m_aabb.min.x;
  *(_QWORD *)&v12.elements[1] = __PAIR64__(v6, v5);
  v8 = this->m_aabb.max.y + this->m_aabb.min.y;
  v9 = (float)(this->m_aabb.max.z + this->m_aabb.min.z) * 0.5;
  v13.x = v7 * 0.5;
  v13.y = v8 * 0.5;
  v13.z = v9;
  vostok::collision::colliders::sse::construct_aabb_a16(&v13, &v12, &aabb);
  vostok::collision::colliders::ray_aabb_collider::ray_aabb_collider(&v15, direction, origin);
  return vostok::collision::colliders::ray_aabb_collider::intersects_aabb_sse(&aabb, v10, distance)
      && max_distance >= *distance;
}
