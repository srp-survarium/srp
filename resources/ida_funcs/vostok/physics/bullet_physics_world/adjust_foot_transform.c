bool __userpurge vostok::physics::bullet_physics_world::adjust_foot_transform@<al>(
        const vostok::math::float3 *half_size@<eax>,
        vostok::console_commands::cc_value<bool> *a2@<ecx>,
        vostok::physics::bullet_physics_world *this,
        const vostok::math::float3 *start,
        const vostok::math::float3 *finish,
        float rotation_koef0,
        const vostok::math::float4x4 *__formal,
        vostok::math::float4x4 *transform)
{
  int x_low; // xmm1_4
  int v10; // xmm2_4
  vostok::math::quaternion *v11; // eax
  __m128i si128; // xmm0
  __m128i v13; // xmm0
  btSoftRigidDynamicsWorld *m_dynamicsWorld; // eax
  float v15; // xmm1_4
  const vostok::math::float4x4 *v16; // xmm5_4
  int v17; // xmm2_4
  float v18; // xmm3_4
  float _X; // xmm0_4
  long double v20; // st7
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm4_4
  float v24; // xmm3_4
  vostok::console_commands::command_type v26; // [esp+764h] [ebp-180h]
  vostok::console_commands::execution_filter v27; // [esp+768h] [ebp-17Ch]
  __m128i object; // [esp+774h] [ebp-170h] BYREF
  btMatrix3x3 q; // [esp+784h] [ebp-160h] BYREF
  btCollisionWorld convexFromWorld; // [esp+7B4h] [ebp-130h] BYREF
  __int16 v31; // [esp+80Ch] [ebp-D8h]
  __int16 v32; // [esp+80Eh] [ebp-D6h]
  __m128i v33; // [esp+814h] [ebp-D0h]
  __m128i v34; // [esp+824h] [ebp-C0h]
  float v35; // [esp+834h] [ebp-B0h]
  float v36; // [esp+838h] [ebp-ACh]
  float v37; // [esp+83Ch] [ebp-A8h]
  int v38; // [esp+854h] [ebp-90h]
  btTransform convexToWorld; // [esp+864h] [ebp-80h] BYREF
  vostok::math::float4x4 resultCallback; // [esp+8A4h] [ebp-40h] BYREF

  if ( (_S4_7 & 1) == 0 )
  {
    _S4_7 |= 1u;
    vostok::console_commands::cc_value<bool>::cc_value<bool>(
      a2,
      (int)&s_ik_change_foot_rotation_cc,
      "ik_change_foot_rotation",
      &s_ik_change_foot_rotation_value,
      0,
      command_type_engine_internal,
      execution_filter_general,
      v26,
      v27);
    s_ik_change_foot_rotation_cc.__vftable = (vostok::console_commands::cc_bool_vtbl *)stru_95AF78.m_key_bindings[45].m_keyboard;
    s_ik_change_foot_rotation_cc.m_need_args = 1;
    atexit(vostok::physics::bullet_physics_world::adjust_foot_transform_::_2_::_dynamic_atexit_destructor_for__s_ik_change_foot_rotation_cc__);
  }
  x_low = LODWORD(half_size->x);
  convexFromWorld.m_dispatchInfo.m_debugDraw = (btIDebugDraw *)1025758986;
  *(float *)&v10 = half_size->y * 0.5;
  convexFromWorld.m_collisionObjects.m_data = (btCollisionObject **)clear_value;
  *(_DWORD *)&convexFromWorld.m_collisionObjects.m_ownsMemory = clear_value;
  *(_QWORD *)&convexFromWorld.m_dispatcher1 = (unsigned int)clear_value;
  convexFromWorld.__vftable = (btCollisionWorld_vtbl *)&btCapsuleShape::`vftable';
  *(_QWORD *)&convexFromWorld.m_collisionObjects.m_allocator = 10;
  LODWORD(convexFromWorld.m_dispatchInfo.m_convexConservativeDistanceThreshold) = 1;
  convexFromWorld.m_dispatchInfo.m_stepCount = x_low;
  convexFromWorld.m_dispatchInfo.m_dispatchFunc = v10;
  *(_QWORD *)&convexFromWorld.m_dispatchInfo.m_timeOfImpact = (unsigned int)x_low;
  v11 = vostok::physics::from_vostok(__formal, (vostok::math::quaternion *)&convexToWorld);
  btMatrix3x3::getRotation(&q, &v11->x, (btQuaternion *)&q);
  q.m_el[1].mVec128.m128_u64[0] = *(_QWORD *)&start->x;
  q.m_el[1].mVec128.m128_f32[2] = -start->z;
  object.m128i_i64[0] = *(_QWORD *)&finish->x;
  *(float *)&object.m128i_i32[2] = -finish->z;
  *(_DWORD *)&convexFromWorld.m_forceUpdateAllAabbs = clear_value;
  q.m_el[1].mVec128.m128_i32[3] = 0;
  si128 = _mm_load_si128((const __m128i *)&q.m_el[1]);
  object.m128i_i32[3] = 0;
  v33 = si128;
  v13 = _mm_load_si128(&object);
  v31 = 36;
  convexFromWorld.m_debugDrawer = (btIDebugDraw *)&btCollisionWorld::ClosestConvexResultCallback::`vftable';
  v34 = v13;
  v38 = 0;
  v32 = 2;
  btMatrix3x3::setRotation(&q, (int)&resultCallback);
  resultCallback.lines[3] = (vostok::math::float4_pod)_mm_load_si128(&object);
  btMatrix3x3::setRotation(&q, (int)&convexToWorld);
  m_dynamicsWorld = this->m_dynamicsWorld;
  convexToWorld.m_origin = (btVector3)_mm_load_si128((const __m128i *)&q.m_el[1]);
  btCollisionWorld::convexSweepTest(
    &convexFromWorld,
    m_dynamicsWorld,
    (btConvexShape *)&convexFromWorld,
    &convexToWorld,
    (const btTransform *)&resultCallback,
    (btCollisionWorld::ConvexResultCallback *)&convexFromWorld.m_debugDrawer,
    0.0);
  v15 = *(float *)&convexFromWorld.m_forceUpdateAllAabbs;
  v16 = clear_value;
  if ( *(float *)&clear_value <= *(float *)&convexFromWorld.m_forceUpdateAllAabbs )
    return 0;
  if ( COERCE_FLOAT(*(_DWORD *)&convexFromWorld.m_forceUpdateAllAabbs & 0x7FFFFFFF) >= 0.0000099999997 )
  {
    *(float *)&v17 = (float)((float)(*(float *)&clear_value - *(float *)&convexFromWorld.m_forceUpdateAllAabbs)
                           * q.m_el[1].mVec128.m128_f32[0])
                   + (float)(*(float *)object.m128i_i32 * *(float *)&convexFromWorld.m_forceUpdateAllAabbs);
    q.m_el[0].mVec128.m128_f32[1] = (float)(q.m_el[1].mVec128.m128_f32[1]
                                          * (float)(*(float *)&clear_value
                                                  - *(float *)&convexFromWorld.m_forceUpdateAllAabbs))
                                  + (float)(*(float *)&object.m128i_i32[1]
                                          * *(float *)&convexFromWorld.m_forceUpdateAllAabbs);
    v18 = (float)(q.m_el[1].mVec128.m128_f32[2]
                * (float)(*(float *)&clear_value - *(float *)&convexFromWorld.m_forceUpdateAllAabbs))
        + (float)(*(float *)&object.m128i_i32[2] * *(float *)&convexFromWorld.m_forceUpdateAllAabbs);
    memset(&object, 0, 12);
    *(_QWORD *)&__formal->lines[3].x = 0;
    __formal->c.z = 0.0;
    q.m_el[0].mVec128.m128_i32[0] = v17;
    q.m_el[0].mVec128.m128_f32[2] = v18;
    if ( s_ik_change_foot_rotation_value )
    {
      _X = (float)((float)((float)-__formal->k.x * v35) + (float)((float)-__formal->k.z * (float)-v37))
         + (float)((float)-__formal->k.y * v36);
      *(float *)&object.m128i_i32[2] = -v37;
      if ( _X > -1.0 )
      {
        if ( *(float *)&v16 < _X )
          v20 = acosf(*(float *)&v16);
        else
          v20 = acosf(_X);
      }
      else
      {
        v20 = acosf(-1.0);
      }
      q.m_el[2].mVec128.m128_f32[3] = v20 * rotation_koef0;
      if ( COERCE_FLOAT(q.m_el[2].mVec128.m128_i32[3] & 0x7FFFFFFF) >= 0.0000099999997 )
      {
        v21 = -__formal->k.y;
        v22 = -__formal->k.z;
        v23 = -__formal->k.x;
        *(float *)object.m128i_i32 = (float)(v22 * v36) - (float)(v21 * *(float *)&object.m128i_i32[2]);
        *(float *)&object.m128i_i32[1] = (float)(*(float *)&object.m128i_i32[2] * v23) - (float)(v22 * v35);
        *(float *)&object.m128i_i32[2] = (float)(v21 * v35) - (float)(v36 * v23);
        vostok::math::normalize((const vostok::math::float3_pod *)&object, q.m_el[1].mVec128.m128_f32);
        vostok::math::create_rotation((const vostok::math::float3 *)&q.m_el[1], q.m_el[2].mVec128.m128_f32[3]);
        vostok::math::mul4x3(&resultCallback, __formal, (const vostok::math::float4x4 *)&convexToWorld);
        qmemcpy((void *)__formal, &resultCallback, sizeof(const vostok::math::float4x4));
      }
      v18 = q.m_el[0].mVec128.m128_f32[2];
      v16 = clear_value;
      v15 = *(float *)&convexFromWorld.m_forceUpdateAllAabbs;
      v17 = q.m_el[0].mVec128.m128_i32[0];
    }
    v24 = -v18;
    object.m128i_i64[0] = __PAIR64__(q.m_el[0].mVec128.m128_u32[1], v17);
    *(float *)&object.m128i_i32[2] = v24;
    *(_QWORD *)&__formal->lines[3].x = __PAIR64__(q.m_el[0].mVec128.m128_u32[1], v17);
    __formal->c.z = v24;
  }
  return *(float *)&v16 > v15;
}
