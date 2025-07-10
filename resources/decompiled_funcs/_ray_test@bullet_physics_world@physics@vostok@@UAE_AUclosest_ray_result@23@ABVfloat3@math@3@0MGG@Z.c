vostok::physics::closest_ray_result *__userpurge vostok::physics::bullet_physics_world::ray_test@<eax>(
        vostok::physics::bullet_physics_world *this@<ecx>,
        int a2@<esi>,
        vostok::physics::closest_ray_result *result,
        const vostok::math::float3 *ray_from,
        const vostok::math::float3 *ray_dir,
        float ray_length,
        unsigned __int16 filter_group,
        unsigned __int16 filter_mask)
{
  float z; // xmm2_4
  float x; // xmm0_4
  float y; // xmm1_4
  float v11; // xmm4_4
  float v12; // xmm5_4
  float v13; // xmm3_4
  vostok::physics::closest_ray_result *v15; // eax
  int v16; // ecx
  vostok::physics::base_physics_object *v17; // ecx
  float v18; // edx
  float v19; // xmm1_4
  int v20; // edx
  btCollisionObject *m_collisionObject; // xmm0_4
  __int64 v23; // [esp+184h] [ebp-98h]
  btVector3 rayToWorld; // [esp+18Ch] [ebp-90h] BYREF
  btVector3 rayFromWorld; // [esp+19Ch] [ebp-80h] BYREF
  vostok::physics::closest_ray_result_callback v26; // [esp+1ACh] [ebp-70h] BYREF

  z = ray_from->z;
  x = ray_from->x;
  y = ray_from->y;
  v11 = ray_dir->y;
  v12 = ray_dir->z;
  rayFromWorld.mVec128.m128_f32[2] = -z;
  rayFromWorld.mVec128.m128_i32[3] = 0;
  v13 = ray_dir->x;
  rayFromWorld.mVec128.m128_u64[0] = __PAIR64__(LODWORD(y), LODWORD(x));
  rayToWorld.mVec128.m128_f32[0] = x + (float)(v13 * ray_length);
  rayToWorld.mVec128.m128_f32[1] = y + (float)(v11 * ray_length);
  rayToWorld.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(-(float)(z + (float)(v12 * ray_length)));
  vostok::physics::closest_ray_result_callback::closest_ray_result_callback(&rayToWorld, &rayFromWorld, &v26);
  v26.m_flags |= 2u;
  v26.m_collisionFilterMask = filter_mask;
  v26.m_collisionFilterGroup = filter_group;
  ((void (__thiscall *)(btSoftRigidDynamicsWorld *, btVector3 *, btVector3 *, vostok::physics::closest_ray_result_callback *, int))this->m_dynamicsWorld->rayTest)(
    this->m_dynamicsWorld,
    &rayFromWorld,
    &rayToWorld,
    &v26,
    a2);
  v15 = result;
  v16 = *(_DWORD *)&v26.m_collisionFilterGroup;
  result->object = 0;
  result->triangle_index = -1;
  result->is_shape_index = 0;
  result->fraction = 0.0;
  if ( v16 )
  {
    v17 = *(vostok::physics::base_physics_object **)(v16 + 248);
    v18 = -v26.m_hitPointWorld.mVec128.m128_f32[3];
    *(_QWORD *)&result->hit_point_world.x = *(unsigned __int64 *)((char *)v26.m_hitPointWorld.mVec128.m128_u64 + 4);
    v23 = *(__int64 *)((char *)v26.m_hitNormalWorld.mVec128.m128_i64 + 4);
    v19 = v26.m_hitNormalWorld.mVec128.m128_f32[3];
    result->hit_point_world.z = v18;
    v20 = *(_DWORD *)&v26.m_is_shape_index;
    result->object = v17;
    LOBYTE(v17) = *(&v26.m_is_shape_index + 4);
    result->triangle_index = v20;
    *(_QWORD *)&result->hit_normal_world.x = v23;
    m_collisionObject = v26.m_collisionObject;
    result->is_shape_index = (char)v17;
    result->hit_normal_world.z = -v19;
    LODWORD(result->fraction) = m_collisionObject;
  }
  return v15;
}
