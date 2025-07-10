bool __thiscall vostok::collision::aabb_object::ray_test(
        vostok::collision::aabb_object *this,
        const vostok::math::float3 *origin,
        const vostok::math::float3 *direction,
        float max_distance,
        float *distance)
{
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  float v10; // xmm6_4
  vostok::collision::colliders::ray_aabb_collider *v11; // eax
  __int64 v13; // [esp+64h] [ebp-5Ch]
  float v14; // [esp+6Ch] [ebp-54h]
  vostok::collision::colliders::sse::aabb_a16 v15; // [esp+70h] [ebp-50h] BYREF
  vostok::collision::colliders::ray_aabb_collider v16; // [esp+90h] [ebp-30h] BYREF

  v5 = (float)(this->m_aabb.max.x - this->m_aabb.min.x) * 0.5;
  v6 = (float)(this->m_aabb.max.y - this->m_aabb.min.y) * 0.5;
  v7 = (float)(this->m_aabb.max.z - this->m_aabb.min.z) * 0.5;
  v8 = (float)(this->m_aabb.max.x + this->m_aabb.min.x) * 0.5;
  v9 = (float)(this->m_aabb.max.y + this->m_aabb.min.y) * 0.5;
  v10 = (float)(this->m_aabb.max.z + this->m_aabb.min.z) * 0.5;
  *(float *)&v13 = v8 - v5;
  *((float *)&v13 + 1) = v9 - v6;
  v14 = v10 + v7;
  *(_QWORD *)&v15.min.x = v13;
  v15.min.z = v10 - v7;
  *(float *)&v13 = v8 + v5;
  *((float *)&v13 + 1) = v9 + v6;
  v15.max.z = v10 + v7;
  v15.min.padding = 0.0;
  *(_QWORD *)&v15.max.x = v13;
  v15.max.padding = 0.0;
  vostok::collision::colliders::ray_aabb_collider::ray_aabb_collider(&v16, origin, direction);
  return vostok::collision::colliders::ray_aabb_collider::intersects_aabb_sse(v11, &v15, distance)
      && max_distance >= *distance;
}
