void __userpurge vostok::physics::bullet_character_controller::step_forward_and_strafe(
        vostok::physics::bullet_character_controller *this@<ecx>,
        int a2@<edi>,
        const btVector3 *walkMove)
{
  CProfileNode *Sub_Node; // eax
  CProfileNode *RecursionCounter; // ecx
  float v5; // xmm6_4
  float v6; // xmm5_4
  float v7; // xmm4_4
  float v8; // xmm2_4
  float v9; // xmm7_4
  float v10; // xmm7_4
  int v11; // ebx
  int v12; // edx
  btCollisionObject *v13; // eax
  bool v14; // zf
  __int16 v15; // dx
  btVector3 *updated; // eax
  float v17; // xmm2_4
  float v18; // xmm1_4
  long double v19; // st7
  float v20; // xmm4_4
  const btVector3 *v21; // [esp+71Ch] [ebp-160h]
  float v22; // [esp+720h] [ebp-15Ch]
  float v23; // [esp+724h] [ebp-158h]
  btVector3 hitNormal; // [esp+72Ch] [ebp-150h] BYREF
  float v25; // [esp+740h] [ebp-13Ch]
  float v26; // [esp+744h] [ebp-138h]
  float v27; // [esp+748h] [ebp-134h]
  float v28; // [esp+74Ch] [ebp-130h]
  float v29; // [esp+750h] [ebp-12Ch]
  float v30; // [esp+754h] [ebp-128h]
  btTransform convexToWorld; // [esp+75Ch] [ebp-120h] BYREF
  btVector3 up_vector; // [esp+79Ch] [ebp-E0h] BYREF
  btCollisionWorld::ConvexResultCallback resultCallback; // [esp+7ACh] [ebp-D0h] BYREF
  int v34; // [esp+7B8h] [ebp-C4h]
  int v35; // [esp+7BCh] [ebp-C0h]
  const vostok::math::float4x4 *v36; // [esp+7C0h] [ebp-BCh]
  int v37; // [esp+7C4h] [ebp-B8h]
  int v38; // [esp+7C8h] [ebp-B4h]
  int v39; // [esp+7CCh] [ebp-B0h]
  int v40; // [esp+7D0h] [ebp-ACh]
  const vostok::math::float4x4 *v41; // [esp+7D4h] [ebp-A8h]
  int v42; // [esp+7D8h] [ebp-A4h]
  __m128i si128; // [esp+7DCh] [ebp-A0h]
  vostok::physics::character_move_test_callback v44; // [esp+7ECh] [ebp-90h] BYREF
  _BYTE v45[16]; // [esp+86Ch] [ebp-10h] BYREF

  Sub_Node = CProfileManager::CurrentNode;
  if ( CProfileManager::CurrentNode->Name != "step_forward_and_strafe" )
  {
    Sub_Node = CProfileNode::Get_Sub_Node((const char *)this);
    CProfileManager::CurrentNode = Sub_Node;
  }
  RecursionCounter = (CProfileNode *)Sub_Node->RecursionCounter;
  ++Sub_Node->TotalCalls;
  Sub_Node->RecursionCounter = (int)&RecursionCounter->Name + 1;
  if ( !RecursionCounter )
    Sub_Node->StartTime = btClock::getTimeMicroseconds(0);
  v5 = *(float *)(a2 + 56) + walkMove->mVec128.m128_f32[2];
  v6 = *(float *)(a2 + 52) + walkMove->mVec128.m128_f32[1];
  v7 = *(float *)(a2 + 48) + walkMove->mVec128.m128_f32[0];
  v8 = *(float *)(a2 + 52) - v6;
  v9 = (float)(*(float *)(a2 + 56) - v5) * (float)(*(float *)(a2 + 56) - v5);
  convexToWorld.m_basis.m_el[0].mVec128.m128_u64[0] = (unsigned int)clear_value;
  *(unsigned __int64 *)((char *)convexToWorld.m_basis.m_el[1].mVec128.m128_u64 + 4) = (unsigned int)clear_value;
  convexToWorld.m_basis.m_el[2].mVec128.m128_u64[1] = (unsigned int)clear_value;
  resultCallback.__vftable = (btCollisionWorld::ConvexResultCallback_vtbl *)clear_value;
  v36 = clear_value;
  v41 = clear_value;
  v25 = *(float *)&clear_value;
  v10 = (float)(v9 + (float)(v8 * v8)) + (float)((float)(*(float *)(a2 + 48) - v7) * (float)(*(float *)(a2 + 48) - v7));
  hitNormal.mVec128.m128_u64[0] = __PAIR64__(LODWORD(v6), LODWORD(v7));
  hitNormal.mVec128.m128_u64[1] = LODWORD(v5);
  memset(&convexToWorld.m_basis.m_el[0].m_floats[2], 0, 12);
  memset(&convexToWorld.m_basis.m_el[1].m_floats[3], 0, 12);
  memset(&convexToWorld.m_origin, 0, sizeof(convexToWorld.m_origin));
  resultCallback.m_closestHitFraction = 0.0;
  *(_DWORD *)&resultCallback.m_collisionFilterGroup = 0;
  v34 = 0;
  v35 = 0;
  v37 = 0;
  v38 = 0;
  v39 = 0;
  v40 = 0;
  v42 = 0;
  si128 = 0u;
  if ( v10 >= 0.00000011920929 )
  {
    v11 = 10;
    while ( 1 )
    {
      v12 = v11--;
      if ( v12 <= 0 )
        break;
      v13 = *(btCollisionObject **)(a2 + 136);
      convexToWorld.m_origin = *(btVector3 *)(a2 + 48);
      si128 = _mm_load_si128((const __m128i *)&hitNormal);
      up_vector.mVec128.m128_f32[0] = *(float *)(a2 + 48) - v7;
      up_vector.mVec128.m128_f32[1] = *(float *)(a2 + 52) - v6;
      up_vector.mVec128.m128_f32[2] = *(float *)(a2 + 56) - v5;
      up_vector.mVec128.m128_i32[3] = 0;
      vostok::physics::character_move_test_callback::character_move_test_callback(&v44, &up_vector, v13, 0.0);
      v14 = *(_BYTE *)(a2 + 258) == 0;
      v15 = *(_WORD *)(a2 + 228);
      v44.m_collisionFilterGroup = *(_WORD *)(a2 + 226);
      v44.m_collisionFilterMask = v15;
      if ( v14 )
        btCollisionWorld::convexSweepTest(
          (btCollisionWorld *)&convexToWorld,
          *(const btConvexShape **)(a2 + 4),
          (const btTransform *)(a2 + 144),
          &convexToWorld,
          &resultCallback,
          COERCE_FLOAT(&v44));
      else
        btGhostObject::convexSweepTest(
          *(btGhostObject **)(a2 + 136),
          *(const btConvexShape **)(a2 + 136),
          (const btTransform *)(a2 + 144),
          &convexToWorld,
          &resultCallback,
          COERCE_FLOAT(&v44));
      v25 = v25 - v44.m_closestHitFraction;
      if ( *(float *)&clear_value <= v44.m_closestHitFraction )
      {
        *(btVector3 *)(a2 + 48) = (btVector3)hitNormal.mVec128;
      }
      else
      {
        updated = vostok::physics::bullet_character_controller::updateTargetPositionBasedOnCollision(
                    (vostok::physics::bullet_character_controller *)&hitNormal,
                    a2,
                    (int)v45,
                    &v44.m_hitNormalWorld,
                    &hitNormal,
                    v21,
                    v22,
                    v23);
        hitNormal.mVec128.m128_u64[0] = updated->mVec128.m128_u64[0];
        v17 = hitNormal.mVec128.m128_f32[1] - *(float *)(a2 + 52);
        v18 = hitNormal.mVec128.m128_f32[0] - *(float *)(a2 + 48);
        hitNormal.mVec128.m128_u64[1] = updated->mVec128.m128_u64[1];
        v30 = hitNormal.mVec128.m128_f32[2] - *(float *)(a2 + 56);
        v29 = v17;
        v28 = v18;
        v26 = (float)((float)(v30 * v30) + (float)(v17 * v17)) + (float)(v18 * v18);
        if ( v26 <= 0.00000011920929
          || (v19 = sqrtf(v26),
              v20 = *(float *)(a2 + 40),
              v27 = 1.0 / v19,
              (float)((float)((float)(v20 * (float)(v30 * v27)) + (float)(*(float *)(a2 + 36) * (float)(v29 * v27)))
                    + (float)(*(float *)(a2 + 32) * (float)(v28 * v27))) <= 0.0) )
        {
          v44.__vftable = (vostok::physics::character_move_test_callback_vtbl *)&btCollisionWorld::ConvexResultCallback::`vftable';
          break;
        }
      }
      v44.__vftable = (vostok::physics::character_move_test_callback_vtbl *)&btCollisionWorld::ConvexResultCallback::`vftable';
      if ( v25 <= 0.0099999998 )
        break;
      v5 = hitNormal.mVec128.m128_f32[2];
      v6 = hitNormal.mVec128.m128_f32[1];
      v7 = hitNormal.mVec128.m128_f32[0];
    }
  }
  if ( CProfileNode::Return(RecursionCounter) )
    CProfileManager::CurrentNode = CProfileManager::CurrentNode->Parent;
}
