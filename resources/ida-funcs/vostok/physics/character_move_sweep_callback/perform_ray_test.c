btVector3 *__userpurge vostok::physics::character_move_sweep_callback::perform_ray_test@<eax>(
        const btVector3 *ray_end@<eax>,
        btCollisionWorld::ClosestRayResultCallback *a2@<ecx>,
        vostok::physics::character_move_sweep_callback *this,
        btVector3 *hit_normal,
        btVector3 *convexResult,
        const btVector3 *ray_start,
        const btVector3 *a7)
{
  const btVector3 *v7; // esi
  const btQuaternion *Identity; // eax
  const btQuaternion *v9; // eax
  float v10; // xmm1_4
  float v11; // xmm3_4
  float v12; // xmm2_4
  btVector3 *v13; // esi
  btVector3 *result; // eax
  btVector3 *v15; // edi
  int *v16; // edi
  int *v17; // esi
  btCollisionObject *v18; // [esp-10h] [ebp-140h]
  const btTransform *v19; // [esp+18h] [ebp-118h]
  btVoronoiSimplexSolver *v20; // [esp+1Ch] [ebp-114h]
  btVector3 v21; // [esp+20h] [ebp-110h] BYREF
  btVector3 v22; // [esp+30h] [ebp-100h] BYREF
  btVector3 v23; // [esp+40h] [ebp-F0h] BYREF
  btCollisionWorld::RayResultCallback v24[2]; // [esp+50h] [ebp-E0h] BYREF
  float v25; // [esp+90h] [ebp-A0h]
  float v26; // [esp+94h] [ebp-9Ch]
  float v27; // [esp+98h] [ebp-98h]
  btTransform v28; // [esp+B0h] [ebp-80h] BYREF
  btTransform v29; // [esp+F0h] [ebp-40h] BYREF

  v7 = ray_end;
  btCollisionWorld::ClosestRayResultCallback::ClosestRayResultCallback(a2, (const btVector3 *)v24, a7, ray_end);
  v24[0].m_collisionFilterGroup = this->m_collisionFilterGroup;
  v24[0].m_collisionFilterMask = this->m_collisionFilterMask;
  v19 = (const btTransform *)(ray_start->mVec128.m128_i32[0] + 16);
  v20 = *(btVoronoiSimplexSolver **)(ray_start->mVec128.m128_i32[0] + 212);
  Identity = btQuaternion::getIdentity();
  btMatrix3x3::setRotation(Identity, &v28.m_basis);
  v28.m_origin.mVec128.m128_i32[0] = v7->mVec128.m128_i32[0];
  v7 = (const btVector3 *)((char *)v7 + 4);
  v28.m_origin.mVec128.m128_i32[1] = v7->mVec128.m128_i32[0];
  v28.m_origin.mVec128.m128_u64[1] = *(unsigned __int64 *)((char *)v7->mVec128.m128_u64 + 4);
  v9 = btQuaternion::getIdentity();
  btMatrix3x3::setRotation(v9, &v29.m_basis);
  v18 = (btCollisionObject *)ray_start->mVec128.m128_i32[0];
  v29.m_origin = (btVector3)a7->mVec128;
  btCollisionWorld::rayTestSingle(&v29, &v28, v18, v20, v19, v24);
  if ( v24[0].m_collisionObject )
  {
    v23.mVec128.m128_i32[0] = this->m_move_direction.mVec128.m128_i32[0] ^ _mask__NegFloat_;
    v23.mVec128.m128_i32[1] = this->m_move_direction.mVec128.m128_i32[1] ^ _mask__NegFloat_;
    v23.mVec128.m128_u64[1] = this->m_move_direction.mVec128.m128_u32[2]
                            ^ (unsigned __int64)(unsigned int)_mask__NegFloat_;
    v10 = (float)((float)(this->m_up_vector.mVec128.m128_f32[2] * v27)
                + (float)(this->m_up_vector.mVec128.m128_f32[1] * v26))
        + (float)(this->m_up_vector.mVec128.m128_f32[0] * v25);
    v11 = this->m_up_vector.mVec128.m128_f32[2] * v10;
    v12 = this->m_up_vector.mVec128.m128_f32[1] * v10;
    v21.mVec128.m128_f32[0] = v25 - (float)(this->m_up_vector.mVec128.m128_f32[0] * v10);
    v21.mVec128.m128_f32[1] = v26 - v12;
    v21.mVec128.m128_f32[2] = v27 - v11;
    v21.mVec128.m128_i32[3] = 0;
    vostok::physics::normalized_safe(&v21, &v22, &v23);
    v13 = convexResult;
    result = hit_normal;
    v15 = hit_normal;
    if ( (float)((float)((float)(this->m_move_direction.mVec128.m128_f32[1] * v22.mVec128.m128_f32[1])
                       + (float)(this->m_move_direction.mVec128.m128_f32[2] * v22.mVec128.m128_f32[2]))
               + (float)(this->m_move_direction.mVec128.m128_f32[0] * v22.mVec128.m128_f32[0])) > (float)((float)((float)(this->m_move_direction.mVec128.m128_f32[2] * convexResult->mVec128.m128_f32[2]) + (float)(this->m_move_direction.mVec128.m128_f32[1] * convexResult->mVec128.m128_f32[1])) + (float)(convexResult->mVec128.m128_f32[0] * this->m_move_direction.mVec128.m128_f32[0])) )
      v13 = &v22;
  }
  else
  {
    result = hit_normal;
    v13 = convexResult;
    v15 = hit_normal;
  }
  v15->mVec128.m128_i32[0] = v13->mVec128.m128_i32[0];
  v17 = &v13->mVec128.m128_i32[1];
  v16 = &v15->mVec128.m128_i32[1];
  *v16 = *v17++;
  *++v16 = *v17;
  v16[1] = v17[1];
  return result;
}
