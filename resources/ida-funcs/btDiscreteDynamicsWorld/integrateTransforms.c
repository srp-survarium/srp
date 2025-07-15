void __userpurge btDiscreteDynamicsWorld::integrateTransforms(
        btDiscreteDynamicsWorld *this@<ecx>,
        long double a2@<esi:edi>,
        float timeStep)
{
  int v3; // ebx
  int v4; // eax
  float v5; // xmm0_4
  int v6; // eax
  int v7; // ecx
  double v8; // st7
  btSphereShape *v9; // ecx
  int v10; // xmm0_4
  int v11; // eax
  float m_closestHitFraction; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  float radius; // [esp+4h] [ebp-174h]
  int v18; // [esp+24h] [ebp-154h]
  float v19; // [esp+28h] [ebp-150h]
  float v20; // [esp+2Ch] [ebp-14Ch]
  float v21; // [esp+30h] [ebp-148h]
  int v22; // [esp+34h] [ebp-144h]
  _BYTE v23[8]; // [esp+38h] [ebp-140h] BYREF
  int v24; // [esp+40h] [ebp-138h]
  int v25; // [esp+44h] [ebp-134h]
  btTransform v26; // [esp+48h] [ebp-130h] BYREF
  btCollisionWorld::ClosestConvexResultCallback v27; // [esp+88h] [ebp-F0h] BYREF
  int v28; // [esp+E8h] [ebp-90h]
  int v29; // [esp+ECh] [ebp-8Ch]
  int v30; // [esp+F0h] [ebp-88h]
  int v31; // [esp+F4h] [ebp-84h]
  btCollisionWorld v32; // [esp+F8h] [ebp-80h] BYREF

  v18 = 0;
  for ( HIDWORD(a2) = this; v18 < *(_DWORD *)(HIDWORD(a2) + 208); ++v18 )
  {
    v3 = *(_DWORD *)(*(_DWORD *)(HIDWORD(a2) + 216) + 4 * v18);
    v4 = *(_DWORD *)(v3 + 228);
    *(float *)(v3 + 252) = s_bm_current_air_resistance;
    if ( v4 != 2 && v4 != 5 && (*(_BYTE *)(v3 + 216) & 3) == 0 )
    {
      btRigidBody::predictIntegratedTransform((btRigidBody *)v3, a2, timeStep, &v26);
      LODWORD(a2) = v3 + 64;
      if ( *(_BYTE *)(HIDWORD(a2) + 44) )
      {
        v5 = *(float *)(v3 + 260) * *(float *)(v3 + 260);
        if ( v5 > 0.0
          && (float)((float)((float)((float)(v26.m_origin.mVec128.m128_f32[1] - *(float *)(v3 + 68))
                                   * (float)(v26.m_origin.mVec128.m128_f32[1] - *(float *)(v3 + 68)))
                           + (float)((float)(v26.m_origin.mVec128.m128_f32[2] - *(float *)(v3 + 72))
                                   * (float)(v26.m_origin.mVec128.m128_f32[2] - *(float *)(v3 + 72))))
                   + (float)((float)(v26.m_origin.mVec128.m128_f32[0] - *(float *)(v3 + 64))
                           * (float)(v26.m_origin.mVec128.m128_f32[0] - *(float *)(v3 + 64)))) > v5
          && *(int *)(*(_DWORD *)(v3 + 204) + 4) < 20 )
        {
          v6 = *(_DWORD *)(HIDWORD(a2) + 24);
          v7 = *(_DWORD *)(HIDWORD(a2) + 76);
          ++gNumClampedCcdMotions;
          v24 = v6;
          v25 = (*(int (__thiscall **)(int))(*(_DWORD *)v7 + 36))(v7);
          btCollisionWorld::ClosestConvexResultCallback::ClosestConvexResultCallback(
            &v27,
            (const btVector3 *)(v3 + 64),
            &v26.m_origin);
          v8 = *(float *)(v3 + 256);
          v30 = v25;
          v31 = v24;
          radius = v8;
          v27.__vftable = (btCollisionWorld::ClosestConvexResultCallback_vtbl *)&btClosestNotMeConvexResultCallback::`vftable';
          v28 = v3;
          btSphereShape::btSphereShape(v9, radius);
          v10 = *(_DWORD *)(HIDWORD(a2) + 56);
          v11 = *(_DWORD *)(v3 + 200);
          *(btVector3 *)&v32.m_dispatchInfo.m_debugDraw = v26.m_origin;
          v29 = v10;
          v27.m_collisionFilterGroup = *(_WORD *)(v11 + 4);
          v27.m_collisionFilterMask = *(_WORD *)(v11 + 6);
          v32.__vftable = *(btCollisionWorld_vtbl **)(v3 + 16);
          v32.m_collisionObjects = *(btAlignedObjectArray<btCollisionObject *> *)(v3 + 20);
          v32.m_dispatcher1 = *(btDispatcher **)(v3 + 40);
          v32.m_dispatchInfo.m_timeStep = *(float *)(v3 + 44);
          v32.m_dispatchInfo.m_stepCount = *(_DWORD *)(v3 + 48);
          v32.m_dispatchInfo.m_dispatchFunc = *(_DWORD *)(v3 + 52);
          v32.m_dispatchInfo.m_timeOfImpact = *(float *)(v3 + 56);
          *(_DWORD *)&v32.m_dispatchInfo.m_useContinuous = *(_DWORD *)(v3 + 60);
          HIDWORD(a2) = v3 + 64;
          LODWORD(a2) = &v32.m_dispatchInfo.m_debugDraw;
          btCollisionWorld::convexSweepTest(
            &v32,
            this,
            (btConvexShape *)&v32.m_dispatchInfo.m_convexConservativeDistanceThreshold,
            (const btTransform *)(v3 + 16),
            (btCollisionWorld::ConvexResultCallback *)&v32,
            &v27,
            0.0);
          m_closestHitFraction = v27.m_closestHitFraction;
          if ( s_bm_current_air_resistance > v27.m_closestHitFraction )
          {
            *(float *)(v3 + 252) = v27.m_closestHitFraction;
            btRigidBody::predictIntegratedTransform((btRigidBody *)v3, a2, m_closestHitFraction * timeStep, &v26);
            *(_DWORD *)(v3 + 252) = 0;
            btRigidBody::setCenterOfMassTransform((btRigidBody *)&v26, v3);
            v13 = *(float *)(v3 + 260) / this->m_solverInfo.m_timeStep;
            v19 = *(float *)(v3 + 320);
            v20 = *(float *)(v3 + 324);
            v21 = *(float *)(v3 + 328);
            v22 = *(_DWORD *)(v3 + 332);
            LODWORD(a2) = v23;
            v14 = (float)((float)(v20 * v20) + (float)(v21 * v21)) + (float)(v19 * v19);
            if ( v14 > (float)(v13 * v13) )
            {
              v15 = s_bm_current_air_resistance / fsqrt(v14);
              *(float *)(v3 + 320) = (float)(v15 * v19) * v13;
              *(float *)(v3 + 324) = (float)(v20 * v15) * v13;
              *(float *)(v3 + 328) = (float)(v21 * v15) * v13;
              *(_DWORD *)(v3 + 332) = v22;
              HIDWORD(a2) = v23;
              LODWORD(a2) = v3 + 336;
              btRigidBody::predictIntegratedTransform((btRigidBody *)v3, a2, timeStep, &v26);
            }
            HIDWORD(a2) = this;
            continue;
          }
          HIDWORD(a2) = this;
        }
      }
      btRigidBody::setCenterOfMassTransform((btRigidBody *)&v26, v3);
    }
  }
}
