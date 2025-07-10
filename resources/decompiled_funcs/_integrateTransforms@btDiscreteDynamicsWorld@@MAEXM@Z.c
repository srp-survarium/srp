void __thiscall btDiscreteDynamicsWorld::integrateTransforms(btDiscreteDynamicsWorld *this, float timeStep)
{
  CProfileNode *Sub_Node; // eax
  btDiscreteDynamicsWorld *v3; // edi
  int RecursionCounter; // ecx
  btClock *v5; // ecx
  bool v6; // cc
  btRigidBody *v7; // esi
  int m_activationState1; // ecx
  float v9; // xmm0_4
  CProfileNode *v10; // ecx
  btBroadphaseInterface *m_broadphasePairCache; // ecx
  btDispatcher *m_dispatcher1; // edx
  btBroadphaseInterface_vtbl *v13; // eax
  int v14; // eax
  unsigned __int64 v15; // xmm1_8
  __m128i si128; // xmm2
  float m_allowedCcdPenetration; // xmm0_4
  unsigned __int64 v18; // xmm1_8
  unsigned __int64 v19; // xmm0_8
  btBroadphaseProxy *m_broadphaseHandle; // eax
  __int16 m_collisionFilterMask; // dx
  unsigned __int64 v22; // xmm0_8
  unsigned __int64 v23; // xmm0_8
  float v24; // xmm0_4
  CProfileSample *v25; // ecx
  float v26; // xmm1_4
  float v27; // xmm2_4
  bool v28; // zf
  int *p_RecursionCounter; // edi
  CProfileNode *v30; // esi
  const btTransform *v31; // [esp+826h] [ebp-170h]
  btDispatcher *v33; // [esp+83Eh] [ebp-158h]
  float v34; // [esp+83Eh] [ebp-158h]
  CProfileSample v35; // [esp+845h] [ebp-151h] BYREF
  unsigned __int64 v36; // [esp+846h] [ebp-150h]
  unsigned __int64 v37; // [esp+84Eh] [ebp-148h]
  float v38; // [esp+85Ah] [ebp-13Ch]
  int v39; // [esp+85Eh] [ebp-138h]
  float _X; // [esp+862h] [ebp-134h]
  btTransform convexFromWorld; // [esp+866h] [ebp-130h] BYREF
  btTransform predictedTransform; // [esp+8A6h] [ebp-F0h] BYREF
  void **allowedCcdPenetration; // [esp+8E6h] [ebp-B0h] BYREF
  const vostok::math::float4x4 *v44; // [esp+8EAh] [ebp-ACh]
  __int16 m_collisionFilterGroup; // [esp+8EEh] [ebp-A8h]
  __int16 v46; // [esp+8F0h] [ebp-A6h]
  unsigned __int64 v47; // [esp+8F6h] [ebp-A0h]
  unsigned __int64 v48; // [esp+8FEh] [ebp-98h]
  __m128i v49; // [esp+906h] [ebp-90h]
  int v50; // [esp+936h] [ebp-60h]
  btRigidBody *v51; // [esp+946h] [ebp-50h]
  float v52; // [esp+94Ah] [ebp-4Ch]
  int v53; // [esp+94Eh] [ebp-48h]
  btDispatcher *v54; // [esp+952h] [ebp-44h]
  _QWORD resultCallback[6]; // [esp+956h] [ebp-40h] BYREF
  __m128i v56; // [esp+986h] [ebp-10h]

  Sub_Node = CProfileManager::CurrentNode;
  v3 = this;
  if ( CProfileManager::CurrentNode->Name != "integrateTransforms" )
  {
    Sub_Node = CProfileNode::Get_Sub_Node((const char *)this);
    CProfileManager::CurrentNode = Sub_Node;
  }
  RecursionCounter = Sub_Node->RecursionCounter;
  ++Sub_Node->TotalCalls;
  Sub_Node->RecursionCounter = RecursionCounter + 1;
  if ( !RecursionCounter )
  {
    Sub_Node->StartTime = btClock::getTimeMicroseconds(0);
    Sub_Node = CProfileManager::CurrentNode;
  }
  v5 = 0;
  v6 = v3->m_nonStaticRigidBodies.m_size <= 0;
  v39 = 0;
  if ( !v6 )
  {
    do
    {
      v7 = v3->m_nonStaticRigidBodies.m_data[(_DWORD)v5];
      m_activationState1 = v7->m_activationState1;
      LODWORD(v7->m_hitFraction) = clear_value;
      if ( m_activationState1 == 2 || m_activationState1 == 5 || (v7->m_collisionFlags & 3) != 0 )
        goto LABEL_22;
      btTransformUtil::integrateTransform(
        &v7->m_worldTransform,
        &v7->m_linearVelocity,
        &v7->m_angularVelocity,
        timeStep,
        &predictedTransform);
      if ( this->m_dispatchInfo.m_useContinuous )
      {
        v9 = v7->m_ccdMotionThreshold * v7->m_ccdMotionThreshold;
        if ( v9 > 0.0
          && (float)((float)((float)((float)(predictedTransform.m_origin.mVec128.m128_f32[2]
                                           - v7->m_worldTransform.m_origin.mVec128.m128_f32[2])
                                   * (float)(predictedTransform.m_origin.mVec128.m128_f32[2]
                                           - v7->m_worldTransform.m_origin.mVec128.m128_f32[2]))
                           + (float)((float)(predictedTransform.m_origin.mVec128.m128_f32[1]
                                           - v7->m_worldTransform.m_origin.mVec128.m128_f32[1])
                                   * (float)(predictedTransform.m_origin.mVec128.m128_f32[1]
                                           - v7->m_worldTransform.m_origin.mVec128.m128_f32[1])))
                   + (float)((float)(predictedTransform.m_origin.mVec128.m128_f32[0]
                                   - v7->m_worldTransform.m_origin.mVec128.m128_f32[0])
                           * (float)(predictedTransform.m_origin.mVec128.m128_f32[0]
                                   - v7->m_worldTransform.m_origin.mVec128.m128_f32[0]))) > v9 )
        {
          CProfileSample::CProfileSample((CProfileSample *)&stru_958B94, &v35);
          if ( v7->m_collisionShape->m_shapeType < 20 )
          {
            v3 = this;
            m_broadphasePairCache = this->m_broadphasePairCache;
            m_dispatcher1 = this->m_dispatcher1;
            v13 = m_broadphasePairCache->__vftable;
            ++gNumClampedCcdMotions;
            v33 = m_dispatcher1;
            v14 = (int)v13->getOverlappingPairCache(m_broadphasePairCache);
            v15 = v7->m_worldTransform.m_origin.mVec128.m128_u64[0];
            si128 = _mm_load_si128((const __m128i *)&predictedTransform.m_origin);
            v44 = clear_value;
            convexFromWorld.m_basis.m_el[1].mVec128.m128_i32[0] = (int)clear_value;
            convexFromWorld.m_basis.m_el[1].mVec128.m128_i32[1] = (int)clear_value;
            convexFromWorld.m_basis.m_el[1].mVec128.m128_u64[1] = (unsigned int)clear_value;
            m_allowedCcdPenetration = this->m_dispatchInfo.m_allowedCcdPenetration;
            v53 = v14;
            v47 = v15;
            v18 = v7->m_worldTransform.m_origin.mVec128.m128_u64[1];
            v52 = m_allowedCcdPenetration;
            v19 = v7->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[0];
            m_collisionFilterGroup = 1;
            v54 = v33;
            m_broadphaseHandle = v7->m_broadphaseHandle;
            v48 = v18;
            *(float *)&v18 = v7->m_ccdSweptSphereRadius;
            v46 = -1;
            v50 = 0;
            v49 = si128;
            allowedCcdPenetration = &btClosestNotMeConvexResultCallback::`vftable';
            v51 = v7;
            convexFromWorld.m_basis.m_el[0].mVec128.m128_i32[0] = (int)&btSphereShape::`vftable';
            *(unsigned __int64 *)((char *)convexFromWorld.m_basis.m_el[0].mVec128.m128_u64 + 4) = 8;
            convexFromWorld.m_basis.m_el[2].mVec128.m128_i32[0] = v18;
            convexFromWorld.m_origin.mVec128.m128_i32[0] = v18;
            m_collisionFilterGroup = m_broadphaseHandle->m_collisionFilterGroup;
            m_collisionFilterMask = m_broadphaseHandle->m_collisionFilterMask;
            resultCallback[0] = v19;
            resultCallback[1] = v7->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[1];
            resultCallback[2] = v7->m_worldTransform.m_basis.m_el[1].mVec128.m128_u64[0];
            v22 = v7->m_worldTransform.m_basis.m_el[1].mVec128.m128_u64[1];
            v46 = m_collisionFilterMask;
            resultCallback[3] = v22;
            resultCallback[4] = v7->m_worldTransform.m_basis.m_el[2].mVec128.m128_u64[0];
            v23 = v7->m_worldTransform.m_basis.m_el[2].mVec128.m128_u64[1];
            v56 = si128;
            resultCallback[5] = v23;
            btCollisionWorld::convexSweepTest(
              (btCollisionWorld *)resultCallback,
              (const btConvexShape *)this,
              &convexFromWorld,
              &v7->m_worldTransform,
              (btCollisionWorld::ConvexResultCallback *)resultCallback,
              COERCE_FLOAT(&allowedCcdPenetration));
            v24 = *(float *)&v44;
            if ( *(float *)&clear_value > *(float *)&v44 )
            {
              v7->m_hitFraction = *(float *)&v44;
              btRigidBody::predictIntegratedTransform(v7, v24 * timeStep, &predictedTransform);
              v7->m_hitFraction = 0.0;
              btRigidBody::setCenterOfMassTransform((btRigidBody *)&predictedTransform, v31);
              v26 = v7->m_ccdMotionThreshold / this->m_solverInfo.m_timeStep;
              v36 = v7->m_linearVelocity.mVec128.m128_u64[0];
              v37 = v7->m_linearVelocity.mVec128.m128_u64[1];
              v38 = v26;
              _X = (float)((float)(*((float *)&v36 + 1) * *((float *)&v36 + 1))
                         + (float)(*(float *)&v37 * *(float *)&v37))
                 + (float)(*(float *)&v36 * *(float *)&v36);
              if ( _X > (float)(v26 * v26) )
              {
                v34 = 1.0 / sqrtf(_X);
                *(float *)&v36 = (float)(v34 * *(float *)&v36) * v38;
                *((float *)&v36 + 1) = (float)(*((float *)&v36 + 1) * v34) * v38;
                v27 = (float)(*(float *)&v37 * v34) * v38;
                v7->m_linearVelocity.mVec128.m128_u64[0] = v36;
                *(float *)&v37 = v27;
                v7->m_linearVelocity.mVec128.m128_u64[1] = v37;
                btRigidBody::predictIntegratedTransform(v7, timeStep, &predictedTransform);
                printf(
                  "sm2=%f\n",
                  (float)((float)((float)((float)(predictedTransform.m_origin.mVec128.m128_f32[2]
                                                - v7->m_worldTransform.m_origin.mVec128.m128_f32[2])
                                        * (float)(predictedTransform.m_origin.mVec128.m128_f32[2]
                                                - v7->m_worldTransform.m_origin.mVec128.m128_f32[2]))
                                + (float)((float)(predictedTransform.m_origin.mVec128.m128_f32[1]
                                                - v7->m_worldTransform.m_origin.mVec128.m128_f32[1])
                                        * (float)(predictedTransform.m_origin.mVec128.m128_f32[1]
                                                - v7->m_worldTransform.m_origin.mVec128.m128_f32[1])))
                        + (float)((float)(predictedTransform.m_origin.mVec128.m128_f32[0]
                                        - v7->m_worldTransform.m_origin.mVec128.m128_f32[0])
                                * (float)(predictedTransform.m_origin.mVec128.m128_f32[0]
                                        - v7->m_worldTransform.m_origin.mVec128.m128_f32[0]))));
              }
              convexFromWorld.m_basis.m_el[0].mVec128.m128_i32[0] = (int)&btCollisionShape::`vftable';
              allowedCcdPenetration = &btCollisionWorld::ConvexResultCallback::`vftable';
              CProfileSample::~CProfileSample(v25);
              goto LABEL_21;
            }
            convexFromWorld.m_basis.m_el[0].mVec128.m128_i32[0] = (int)&btCollisionShape::`vftable';
            allowedCcdPenetration = &btCollisionWorld::ConvexResultCallback::`vftable';
          }
          if ( CProfileNode::Return(v10) )
            CProfileManager::CurrentNode = CProfileManager::CurrentNode->Parent;
        }
      }
      btRigidBody::setCenterOfMassTransform((btRigidBody *)&predictedTransform, v31);
      v3 = this;
LABEL_21:
      Sub_Node = CProfileManager::CurrentNode;
LABEL_22:
      v5 = (btClock *)(v39 + 1);
      v6 = ++v39 < v3->m_nonStaticRigidBodies.m_size;
    }
    while ( v6 );
  }
  v28 = Sub_Node->RecursionCounter-- == 1;
  p_RecursionCounter = &Sub_Node->RecursionCounter;
  v30 = Sub_Node;
  if ( v28 && Sub_Node->TotalCalls )
  {
    LODWORD(v38) = btClock::getTimeMicroseconds(v5) - Sub_Node->StartTime;
    Sub_Node = CProfileManager::CurrentNode;
    v30->TotalTime = (double)LODWORD(v38) * 0.001 + v30->TotalTime;
  }
  if ( !*p_RecursionCounter )
    CProfileManager::CurrentNode = Sub_Node->Parent;
}
