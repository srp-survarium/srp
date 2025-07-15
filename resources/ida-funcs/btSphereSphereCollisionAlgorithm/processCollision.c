void __thiscall btSphereSphereCollisionAlgorithm::processCollision(
        btSphereSphereCollisionAlgorithm *this,
        btCollisionObject *col0,
        btCollisionObject *col1,
        const btDispatcherInfo *dispatchInfo,
        btManifoldResult *resultOut)
{
  btPersistentManifold *m_manifoldPtr; // edi
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm1_4
  float v9; // xmm6_4
  float v10; // xmm5_4
  float v11; // xmm4_4
  bool v12; // zf
  btTransform *p_m_rootTransB; // ecx
  btTransform *p_m_rootTransA; // edx
  float v15; // xmm7_4
  btManifoldResult_vtbl *v16; // eax
  btPersistentManifold *v17; // eax
  btPersistentManifold *v18; // [esp+0h] [ebp-34h]
  float v19; // [esp+14h] [ebp-20h] BYREF
  float v20; // [esp+18h] [ebp-1Ch]
  float v21; // [esp+1Ch] [ebp-18h]
  int v22; // [esp+20h] [ebp-14h]
  float v23; // [esp+24h] [ebp-10h] BYREF
  float v24; // [esp+28h] [ebp-Ch]
  float v25; // [esp+2Ch] [ebp-8h]
  int v26; // [esp+30h] [ebp-4h]

  m_manifoldPtr = this->m_manifoldPtr;
  if ( !m_manifoldPtr )
    return;
  resultOut->m_manifoldPtr = m_manifoldPtr;
  v6 = col0->m_worldTransform.m_origin.mVec128.m128_f32[1] - col1->m_worldTransform.m_origin.mVec128.m128_f32[1];
  v7 = col0->m_worldTransform.m_origin.mVec128.m128_f32[2] - col1->m_worldTransform.m_origin.mVec128.m128_f32[2];
  v8 = col0->m_worldTransform.m_origin.mVec128.m128_f32[0] - col1->m_worldTransform.m_origin.mVec128.m128_f32[0];
  v9 = *(float *)&col1->m_collisionShape[2].m_userPointer * *(float *)&col1->m_collisionShape[1].m_shapeType;
  v10 = fsqrt((float)((float)(v7 * v7) + (float)(v6 * v6)) + (float)(v8 * v8));
  v11 = v9
      + (float)(*(float *)&col0->m_collisionShape[2].m_userPointer * *(float *)&col0->m_collisionShape[1].m_shapeType);
  if ( v10 > v11 )
  {
    if ( !m_manifoldPtr->m_cachedPoints )
      return;
    v12 = m_manifoldPtr->m_body0 == resultOut->m_body0;
    v18 = m_manifoldPtr;
    goto LABEL_5;
  }
  v15 = 0.0;
  v19 = s_bm_current_air_resistance;
  v20 = 0.0;
  v21 = 0.0;
  v22 = 0;
  if ( v10 > 0.00000011920929 )
  {
    v26 = 0;
    v23 = v8 * (float)(s_bm_current_air_resistance / v10);
    v24 = v6 * (float)(s_bm_current_air_resistance / v10);
    v25 = v7 * (float)(s_bm_current_air_resistance / v10);
    v19 = v23;
    v20 = v24;
    v21 = v25;
    v22 = 0;
    v15 = v25;
  }
  v23 = (float)(v19 * v9) + col1->m_worldTransform.m_origin.mVec128.m128_f32[0];
  v24 = col1->m_worldTransform.m_origin.mVec128.m128_f32[1] + (float)(v20 * v9);
  v16 = resultOut->__vftable;
  v25 = col1->m_worldTransform.m_origin.mVec128.m128_f32[2] + (float)(v15 * v9);
  v26 = 0;
  ((void (__thiscall *)(btManifoldResult *, float *, float *, _DWORD))v16->addContactPoint)(
    resultOut,
    &v19,
    &v23,
    v10 - v11);
  v17 = resultOut->m_manifoldPtr;
  if ( v17->m_cachedPoints )
  {
    v12 = v17->m_body0 == resultOut->m_body0;
    v18 = resultOut->m_manifoldPtr;
LABEL_5:
    if ( v12 )
    {
      p_m_rootTransA = &resultOut->m_rootTransA;
      p_m_rootTransB = &resultOut->m_rootTransB;
    }
    else
    {
      p_m_rootTransB = &resultOut->m_rootTransA;
      p_m_rootTransA = &resultOut->m_rootTransB;
    }
    btPersistentManifold::refreshContactPoints((btPersistentManifold *)p_m_rootTransB, p_m_rootTransA, v18);
  }
}
