void __usercall btSoftRigidDynamicsWorld::rayTestSingle(
        btSoftBody *rayFromTrans@<ecx>,
        btBvhTriangleMeshShape *collisionShape@<eax>,
        const btTransform *rayToTrans,
        btSoftBody *collisionObject,
        const btTransform *colObjWorldTransform,
        btCollisionWorld::RayResultCallback *resultCallback)
{
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  int index; // esi
  float v10; // xmm2_4
  float v11; // xmm1_4
  int m_data; // ecx
  int v13; // esi
  __int64 v14; // xmm5_8
  __int64 v15; // xmm4_8
  float (__thiscall *addSingleResult)(btCollisionWorld::RayResultCallback *, btCollisionWorld::LocalRayResult *, bool); // eax
  btVector3 *v17; // [esp+19Ch] [ebp-70h]
  float v18; // [esp+19Ch] [ebp-70h]
  _DWORD v19[2]; // [esp+1A0h] [ebp-6Ch] BYREF
  char v20; // [esp+1A8h] [ebp-64h]
  __int64 v21; // [esp+1ACh] [ebp-60h]
  __int64 v22; // [esp+1B4h] [ebp-58h]
  __int64 v23; // [esp+1BCh] [ebp-50h]
  __int64 v24; // [esp+1C4h] [ebp-48h]
  btSoftBody::sRayCast results; // [esp+1CCh] [ebp-40h] BYREF
  _DWORD v26[4]; // [esp+1DCh] [ebp-30h] BYREF
  __int64 v27; // [esp+1ECh] [ebp-20h]
  __int64 v28; // [esp+1F4h] [ebp-18h]
  float fraction; // [esp+1FCh] [ebp-10h]

  if ( collisionShape->m_shapeType == 32 )
  {
    if ( collisionObject->m_internalType == 8 )
    {
      v17 = &rayFromTrans->m_worldTransform.m_basis.m_el[2];
      if ( btSoftBody::rayTest(
             collisionObject,
             &results,
             rayFromTrans,
             &rayFromTrans->m_worldTransform.m_basis.m_el[2],
             &rayToTrans->m_origin) )
      {
        if ( resultCallback->m_closestHitFraction >= results.fraction )
        {
          v6 = rayToTrans->m_origin.mVec128.m128_f32[0];
          v7 = rayToTrans->m_origin.mVec128.m128_f32[1];
          v8 = rayToTrans->m_origin.mVec128.m128_f32[2];
          index = results.index;
          v19[0] = 0;
          v20 = 0;
          v10 = v8 - v17->mVec128.m128_f32[2];
          v11 = v7 - v17->mVec128.m128_f32[1];
          *(float *)&v23 = v6 - v17->mVec128.m128_f32[0];
          *(float *)&v24 = v10;
          *((float *)&v23 + 1) = v11;
          v22 = COERCE_UNSIGNED_INT(-v10);
          v19[1] = results.index;
          v18 = 1.0
              / sqrtf(
                  (float)((float)((float)-v10 * (float)-v10) + (float)((float)-*(float *)&v23 * (float)-*(float *)&v23))
                + (float)((float)-v11 * (float)-v11));
          *(float *)&v21 = (float)-*(float *)&v23 * v18;
          *((float *)&v21 + 1) = v18 * (float)-v11;
          *(float *)&v22 = (float)-v10 * v18;
          if ( results.feature == SContacts )
          {
            m_data = (int)collisionObject->m_faces.m_data;
            v13 = index << 6;
            v14 = *(_QWORD *)(m_data + v13 + 32);
            v15 = *(_QWORD *)(m_data + v13 + 40);
            v21 = v14;
            v22 = v15;
            if ( (float)((float)((float)(*(float *)&v15 * *(float *)&v24) + (float)(*(float *)&v14 * *(float *)&v23))
                       + (float)(*((float *)&v23 + 1) * *((float *)&v14 + 1))) > 0.0 )
            {
              *(float *)&v23 = -*(float *)&v14;
              *((float *)&v23 + 1) = -*((float *)&v14 + 1);
              v14 = v23;
              *(float *)&v24 = -*(float *)&v15;
              HIDWORD(v24) = 0;
              v15 = v24;
            }
          }
          else
          {
            v15 = v22;
            v14 = v21;
          }
          addSingleResult = resultCallback->addSingleResult;
          v26[1] = v19;
          v26[0] = collisionObject;
          v27 = v14;
          v28 = v15;
          fraction = results.fraction;
          addSingleResult(resultCallback, (btCollisionWorld::LocalRayResult *)v26, 1);
        }
      }
    }
  }
  else
  {
    btCollisionWorld::rayTestSingle(
      (const btTransform *)rayFromTrans,
      colObjWorldTransform,
      rayToTrans,
      collisionObject,
      collisionShape,
      resultCallback);
  }
}
