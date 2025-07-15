void __usercall btSoftRigidDynamicsWorld::rayTestSingle(
        btSoftBody *rayFromTrans@<ecx>,
        btVoronoiSimplexSolver *collisionShape@<eax>,
        const btTransform *rayToTrans,
        btCollisionObject *collisionObject,
        const btTransform *colObjWorldTransform,
        btCollisionWorld::RayResultCallback *resultCallback)
{
  btSoftBody *v6; // edi
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm5_4
  btSoftBody::Face *m_data; // edx
  btCollisionWorld::RayResultCallback_vtbl *v14; // eax
  btVector3 *v15; // [esp+10h] [ebp-70h]
  _DWORD v16[2]; // [esp+14h] [ebp-6Ch] BYREF
  char v17; // [esp+1Ch] [ebp-64h]
  float v18; // [esp+20h] [ebp-60h]
  float v19; // [esp+24h] [ebp-5Ch]
  float v20; // [esp+28h] [ebp-58h]
  int v21; // [esp+2Ch] [ebp-54h]
  float v22; // [esp+30h] [ebp-50h]
  int v23; // [esp+34h] [ebp-4Ch]
  float v24; // [esp+38h] [ebp-48h]
  int v25; // [esp+3Ch] [ebp-44h]
  btSoftBody::sRayCast results; // [esp+40h] [ebp-40h] BYREF
  _DWORD v27[12]; // [esp+50h] [ebp-30h] BYREF

  if ( *(&collisionShape->m_numVertices + 1) == 32 )
  {
    v6 = collisionObject->m_internalType == 8 ? (btSoftBody *)collisionObject : 0;
    if ( v6 )
    {
      v15 = &rayFromTrans->m_worldTransform.m_basis.m_el[2];
      if ( btSoftBody::rayTest(
             v6,
             &results,
             rayFromTrans,
             &rayFromTrans->m_worldTransform.m_basis.m_el[2],
             &rayToTrans->m_origin) )
      {
        if ( resultCallback->m_closestHitFraction >= results.fraction )
        {
          v7 = rayToTrans->m_origin.mVec128.m128_f32[0] - v15->mVec128.m128_f32[0];
          v8 = rayToTrans->m_origin.mVec128.m128_f32[2] - v15->mVec128.m128_f32[2];
          v9 = rayToTrans->m_origin.mVec128.m128_f32[1] - v15->mVec128.m128_f32[1];
          v16[0] = 0;
          v22 = v7;
          LODWORD(v10) = LODWORD(v7) ^ _mask__NegFloat_;
          v24 = v8;
          LODWORD(v11) = LODWORD(v8) ^ _mask__NegFloat_;
          v12 = s_bm_current_air_resistance
              / fsqrt(
                  (float)((float)(v11 * v11) + (float)(v10 * v10))
                + (float)(COERCE_FLOAT(LODWORD(v9) ^ _mask__NegFloat_) * COERCE_FLOAT(LODWORD(v9) ^ _mask__NegFloat_)));
          v18 = v10 * v12;
          v16[1] = results.index;
          v17 = 0;
          v21 = 0;
          v19 = v12 * COERCE_FLOAT(LODWORD(v9) ^ _mask__NegFloat_);
          v20 = v11 * v12;
          if ( results.feature == 3 )
          {
            m_data = v6->m_faces.m_data;
            v18 = m_data[results.index].m_normal.mVec128.m128_f32[0];
            v19 = m_data[results.index].m_normal.mVec128.m128_f32[1];
            v20 = m_data[results.index].m_normal.mVec128.m128_f32[2];
            v21 = m_data[results.index].m_normal.mVec128.m128_i32[3];
            if ( (float)((float)((float)(v20 * v24) + (float)(v18 * v22)) + (float)(v9 * v19)) > 0.0 )
            {
              v25 = 0;
              LODWORD(v22) = LODWORD(v18) ^ _mask__NegFloat_;
              v23 = LODWORD(v19) ^ _mask__NegFloat_;
              LODWORD(v24) = LODWORD(v20) ^ _mask__NegFloat_;
              LODWORD(v18) ^= _mask__NegFloat_;
              LODWORD(v19) ^= _mask__NegFloat_;
              LODWORD(v20) ^= _mask__NegFloat_;
              v21 = 0;
            }
          }
          v27[0] = collisionObject;
          v27[1] = v16;
          v14 = resultCallback->__vftable;
          *(float *)&v27[4] = v18;
          *(float *)&v27[5] = v19;
          *(float *)&v27[6] = v20;
          v27[7] = v21;
          v27[8] = LODWORD(results.fraction);
          ((void (__stdcall *)(_DWORD *, int))v14->addSingleResult)(v27, 1);
        }
      }
    }
  }
  else
  {
    btCollisionWorld::rayTestSingle(
      (const btTransform *)rayFromTrans,
      rayToTrans,
      collisionObject,
      collisionShape,
      colObjWorldTransform,
      resultCallback);
  }
}
