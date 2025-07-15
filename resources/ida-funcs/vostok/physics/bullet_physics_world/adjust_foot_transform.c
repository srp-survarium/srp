bool __userpurge vostok::physics::bullet_physics_world::adjust_foot_transform@<al>(
        vostok::console_commands::cc_bool *start@<ecx>,
        const vostok::math::float3 *finish@<eax>,
        vostok::physics::bullet_physics_world *this,
        const vostok::math::float3 *half_size,
        float rotation_koef0,
        vostok::math::float4x4 *__formal,
        vostok::math::float4x4 *transform)
{
  vostok::console_commands::cc_bool *v9; // edi
  btTransform *v10; // eax
  float x; // xmm1_4
  vostok::console_commands::console_command *m_next; // xmm0_4
  float z; // xmm1_4
  btCollisionWorld *v14; // ecx
  float v15; // xmm5_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm3_4
  float v19; // xmm0_4
  float v20; // xmm2_4
  float v21; // xmm6_4
  float v22; // xmm4_4
  float v23; // xmm0_4
  float v24; // xmm2_4
  float v25; // xmm1_4
  vostok::math::float4_pod *v26; // edi
  btSoftRigidDynamicsWorld *m_dynamicsWorld; // [esp-14h] [ebp-198h]
  vostok::console_commands::cc_bool *radius; // [esp+0h] [ebp-184h]
  vostok::console_commands::execution_filter v30; // [esp+4h] [ebp-180h]
  float v31; // [esp+10h] [ebp-174h] BYREF
  btVector3 axis; // [esp+14h] [ebp-170h] BYREF
  btQuaternion q; // [esp+24h] [ebp-160h] BYREF
  btVector3 v34; // [esp+34h] [ebp-150h] BYREF
  float v35; // [esp+4Ch] [ebp-138h]
  vostok::math::float4_pod *p_c; // [esp+50h] [ebp-134h]
  btCollisionWorld::ClosestConvexResultCallback allowedCcdPenetration; // [esp+54h] [ebp-130h] BYREF
  btTransform convexToWorld; // [esp+B4h] [ebp-D0h] BYREF
  vostok::math::float4x4 resultCallback; // [esp+F4h] [ebp-90h] BYREF
  btCapsuleShape v40; // [esp+134h] [ebp-50h] BYREF

  v9 = start;
  if ( (_S9_2 & 1) == 0 )
  {
    _S9_2 |= 1u;
    vostok::console_commands::cc_bool::cc_bool(
      start,
      (int)&s_ik_change_foot_rotation_cc,
      "ik_change_foot_rotation",
      &s_ik_change_foot_rotation_value,
      0,
      command_type_engine_internal,
      v30);
    atexit((int (__cdecl *)())vostok::physics::bullet_physics_world::adjust_foot_transform_::_2_::_dynamic_atexit_destructor_for__s_ik_change_foot_rotation_cc__);
    start = radius;
  }
  btCapsuleShape::btCapsuleShape(&v40, (btConvexInternalShape *)start, half_size->y, half_size->x);
  v10 = vostok::physics::from_vostok(__formal, &convexToWorld.m_basis);
  btMatrix3x3::getRotation(&v10->m_basis, &q);
  x = finish->x;
  axis.mVec128.m128_u64[0] = *(_QWORD *)&v9->__vftable;
  m_next = v9->m_next;
  v34.mVec128.m128_f32[0] = x;
  v34.mVec128.m128_i32[1] = LODWORD(finish->y);
  z = finish->z;
  axis.mVec128.m128_u64[1] = (unsigned int)m_next ^ (unsigned __int64)(unsigned int)_mask__NegFloat_;
  v34.mVec128.m128_u64[1] = LODWORD(z) ^ (unsigned __int64)(unsigned int)_mask__NegFloat_;
  btCollisionWorld::ClosestConvexResultCallback::ClosestConvexResultCallback(&allowedCcdPenetration, &axis, &v34);
  allowedCcdPenetration.m_collisionFilterMask = 2;
  allowedCcdPenetration.m_collisionFilterGroup = 36;
  btMatrix3x3::setRotation(&q, (btMatrix3x3 *)&resultCallback);
  resultCallback.lines[3] = (vostok::math::float4_pod)v34.mVec128;
  btMatrix3x3::setRotation(&q, &convexToWorld.m_basis);
  convexToWorld.m_origin.mVec128.m128_u64[0] = axis.mVec128.m128_u64[0];
  m_dynamicsWorld = this->m_dynamicsWorld;
  convexToWorld.m_origin.mVec128.m128_u64[1] = axis.mVec128.m128_u64[1];
  btCollisionWorld::convexSweepTest(
    v14,
    m_dynamicsWorld,
    &v40,
    &convexToWorld,
    (btCollisionWorld::ConvexResultCallback *)&resultCallback,
    &allowedCcdPenetration,
    0.0);
  if ( s_bm_current_air_resistance <= allowedCcdPenetration.m_closestHitFraction )
    return 0;
  v31 = 0.0;
  if ( !vostok::math::is_similar<float>(&allowedCcdPenetration.m_closestHitFraction, &v31, 0.0000099999997) )
  {
    v15 = s_bm_current_air_resistance;
    q.m_floats[0] = (float)(axis.mVec128.m128_f32[0]
                          * (float)(s_bm_current_air_resistance - allowedCcdPenetration.m_closestHitFraction))
                  + (float)(v34.mVec128.m128_f32[0] * allowedCcdPenetration.m_closestHitFraction);
    q.m_floats[1] = (float)(axis.mVec128.m128_f32[1]
                          * (float)(s_bm_current_air_resistance - allowedCcdPenetration.m_closestHitFraction))
                  + (float)(v34.mVec128.m128_f32[1] * allowedCcdPenetration.m_closestHitFraction);
    v16 = (float)(axis.mVec128.m128_f32[2]
                * (float)(s_bm_current_air_resistance - allowedCcdPenetration.m_closestHitFraction))
        + (float)(v34.mVec128.m128_f32[2] * allowedCcdPenetration.m_closestHitFraction);
    memset(&axis, 0, 12);
    p_c = &__formal->c;
    __formal->c.x = 0.0;
    *(_QWORD *)&__formal->lines[3].elements[1] = *(unsigned __int64 *)((char *)axis.mVec128.m128_u64 + 4);
    q.m_floats[2] = v16;
    if ( s_ik_change_foot_rotation_value )
    {
      v17 = (float)((float)(COERCE_FLOAT(LODWORD(__formal->k.z) ^ _mask__NegFloat_)
                          * COERCE_FLOAT(allowedCcdPenetration.m_hitNormalWorld.mVec128.m128_i32[2] ^ _mask__NegFloat_))
                  + (float)(COERCE_FLOAT(LODWORD(__formal->k.y) ^ _mask__NegFloat_)
                          * allowedCcdPenetration.m_hitNormalWorld.mVec128.m128_f32[1]))
          + (float)(COERCE_FLOAT(LODWORD(__formal->k.x) ^ _mask__NegFloat_)
                  * allowedCcdPenetration.m_hitNormalWorld.mVec128.m128_f32[0]);
      axis.mVec128.m128_i32[2] = allowedCcdPenetration.m_hitNormalWorld.mVec128.m128_i32[2] ^ _mask__NegFloat_;
      if ( v17 > -1.0 )
      {
        if ( v15 < v17 )
          v17 = v15;
      }
      else
      {
        v17 = FLOAT_N1_0;
      }
      __libm_sse2_acos();
      v35 = v17 * rotation_koef0;
      v31 = fabs(v17 * rotation_koef0);
      if ( v31 >= 0.0000099999997 )
      {
        LODWORD(v18) = LODWORD(__formal->k.x) ^ _mask__NegFloat_;
        LODWORD(v19) = LODWORD(__formal->k.y) ^ _mask__NegFloat_;
        LODWORD(v20) = LODWORD(__formal->k.z) ^ _mask__NegFloat_;
        v21 = v19 * axis.mVec128.m128_f32[2];
        v22 = (float)(axis.mVec128.m128_f32[2] * v18)
            - (float)(v20 * allowedCcdPenetration.m_hitNormalWorld.mVec128.m128_f32[0]);
        v23 = (float)(v19 * allowedCcdPenetration.m_hitNormalWorld.mVec128.m128_f32[0])
            - (float)(allowedCcdPenetration.m_hitNormalWorld.mVec128.m128_f32[1] * v18);
        v24 = (float)(v20 * allowedCcdPenetration.m_hitNormalWorld.mVec128.m128_f32[1]) - v21;
        v25 = s_bm_current_air_resistance / fsqrt((float)((float)(v23 * v23) + (float)(v22 * v22)) + (float)(v24 * v24));
        axis.mVec128.m128_f32[0] = v25 * v24;
        axis.mVec128.m128_f32[1] = v25 * v22;
        axis.mVec128.m128_f32[2] = v25 * v23;
        vostok::math::create_rotation((const vostok::math::float3 *)&axis, (int)&convexToWorld, v35);
        vostok::math::mul4x3((const vostok::math::float4x4 *)&convexToWorld, __formal, &resultCallback);
        qmemcpy(__formal, &resultCallback, sizeof(vostok::math::float4x4));
      }
      v16 = q.m_floats[2];
    }
    v26 = p_c;
    axis.mVec128.m128_u64[0] = *(_QWORD *)q.m_floats;
    axis.mVec128.m128_i32[2] = LODWORD(v16) ^ _mask__NegFloat_;
    p_c->x = q.m_floats[0];
    *(_QWORD *)&v26->elements[1] = *(unsigned __int64 *)((char *)axis.mVec128.m128_u64 + 4);
  }
  return s_bm_current_air_resistance > allowedCcdPenetration.m_closestHitFraction;
}
