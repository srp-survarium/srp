btVector3 *__userpurge character_step_down_sweep_test_callback::get_normal_via_ray_test@<eax>(
        character_step_down_sweep_test_callback *this@<ecx>,
        int a2@<eax>,
        btVector3 *result,
        btCollisionWorld::LocalConvexResult *convexResult,
        const btVector3 *hit_normal_world)
{
  float v6; // xmm7_4
  float *v7; // ebx
  float v8; // xmm1_4
  float v9; // xmm2_4
  const btQuaternion *Identity; // eax
  const btQuaternion *v11; // eax
  btVector3 *v12; // eax
  const btVector3 *v13; // esi
  int *v14; // esi
  __int64 v15; // [esp+Ch] [ebp-108h]
  btVector3 v16; // [esp+14h] [ebp-100h] BYREF
  btVector3 v17; // [esp+24h] [ebp-F0h] BYREF
  btCollisionWorld::RayResultCallback v18[2]; // [esp+34h] [ebp-E0h] BYREF
  float v19[8]; // [esp+74h] [ebp-A0h] BYREF
  btTransform v20; // [esp+94h] [ebp-80h] BYREF
  btTransform v21; // [esp+D4h] [ebp-40h] BYREF

  v6 = hit_normal_world->mVec128.m128_f32[0];
  v15 = *(__int64 *)((char *)hit_normal_world->mVec128.m128_i64 + 4);
  v7 = (float *)(a2 + 96);
  v8 = convexResult->m_hitPointLocal.mVec128.m128_f32[1]
     + (float)(*(float *)(a2 + 100) * s_cc_ground_normal_via_ray_offset);
  v9 = convexResult->m_hitPointLocal.mVec128.m128_f32[2]
     + (float)(*(float *)(a2 + 104) * s_cc_ground_normal_via_ray_offset);
  v16.mVec128.m128_f32[0] = (float)(convexResult->m_hitPointLocal.mVec128.m128_f32[0]
                                  + (float)(*(float *)(a2 + 96) * s_cc_ground_normal_via_ray_offset))
                          + (float)(hit_normal_world->mVec128.m128_f32[0] * 0.5);
  v16.mVec128.m128_f32[1] = v8 + (float)(*(float *)&v15 * 0.5);
  v16.mVec128.m128_f32[2] = v9 + (float)(*((float *)&v15 + 1) * 0.5);
  v16.mVec128.m128_i32[3] = 0;
  v17.mVec128.m128_f32[0] = v16.mVec128.m128_f32[0] - v6;
  v17.mVec128.m128_f32[1] = v16.mVec128.m128_f32[1] - *(float *)&v15;
  v17.mVec128.m128_f32[2] = v16.mVec128.m128_f32[2] - *((float *)&v15 + 1);
  v17.mVec128.m128_i32[3] = 0;
  btCollisionWorld::ClosestRayResultCallback::ClosestRayResultCallback(
    (btCollisionWorld::ClosestRayResultCallback *)this,
    (const btVector3 *)v18,
    &v16,
    &v17);
  v18[0].m_collisionFilterGroup = *(_WORD *)(a2 + 8);
  v18[0].m_collisionFilterMask = *(_WORD *)(a2 + 10);
  HIDWORD(v15) = &convexResult->m_hitCollisionObject->m_worldTransform;
  LODWORD(v15) = convexResult->m_hitCollisionObject->m_rootCollisionShape;
  Identity = btQuaternion::getIdentity();
  btMatrix3x3::setRotation(Identity, &v20.m_basis);
  v20.m_origin = (btVector3)v17.mVec128;
  v11 = btQuaternion::getIdentity();
  btMatrix3x3::setRotation(v11, &v21.m_basis);
  v21.m_origin = (btVector3)v16.mVec128;
  btCollisionWorld::rayTestSingle(
    &v21,
    &v20,
    convexResult->m_hitCollisionObject,
    (btVoronoiSimplexSolver *)v15,
    (const btTransform *)HIDWORD(v15),
    v18);
  v12 = result;
  if ( v18[0].m_collisionObject )
  {
    v13 = hit_normal_world;
    if ( (float)((float)((float)(v7[1] * v19[1]) + (float)(v7[2] * v19[2])) + (float)(*v7 * v19[0])) > (float)((float)((float)(v7[2] * hit_normal_world->mVec128.m128_f32[2]) + (float)(v7[1] * hit_normal_world->mVec128.m128_f32[1])) + (float)(*v7 * hit_normal_world->mVec128.m128_f32[0])) )
      v13 = (const btVector3 *)v19;
  }
  else
  {
    v13 = (const btVector3 *)v7;
  }
  result->mVec128.m128_i32[0] = v13->mVec128.m128_i32[0];
  v14 = &v13->mVec128.m128_i32[1];
  result->mVec128.m128_i32[1] = *v14;
  result->mVec128.m128_u64[1] = *(_QWORD *)(v14 + 1);
  return v12;
}
