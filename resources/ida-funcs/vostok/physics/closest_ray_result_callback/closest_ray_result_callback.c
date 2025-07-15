void __fastcall vostok::physics::closest_ray_result_callback::closest_ray_result_callback(
        const btVector3 *rayToWorld,
        const btVector3 *rayFromWorld,
        vostok::physics::closest_ray_result_callback *this)
{
  const vostok::math::float4x4 *v3; // xmm0_4
  unsigned __int64 v4; // xmm0_8

  v3 = clear_value;
  this->m_collisionFilterGroup = 1;
  this->m_collisionFilterMask = -1;
  this->m_shape_id = -1;
  LODWORD(this->m_closestHitFraction) = v3;
  this->m_collisionObject = 0;
  this->m_flags = 0;
  this->__vftable = (vostok::physics::closest_ray_result_callback_vtbl *)&vostok::physics::closest_ray_result_callback::`vftable';
  this->m_rayFromWorld = (btVector3)rayFromWorld->mVec128;
  this->m_rayToWorld.mVec128.m128_u64[0] = rayToWorld->mVec128.m128_u64[0];
  v4 = rayToWorld->mVec128.m128_u64[1];
  this->m_triangleIndex = -1;
  this->m_rayToWorld.mVec128.m128_u64[1] = v4;
  this->m_is_shape_index = 0;
}
