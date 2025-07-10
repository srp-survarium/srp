void __thiscall btSphereSphereCollisionAlgorithm::processCollision(
        btSphereSphereCollisionAlgorithm *this,
        btCollisionObject *col0,
        btCollisionObject *col1,
        const btDispatcherInfo *dispatchInfo,
        btManifoldResult *resultOut)
{
  btPersistentManifold *m_manifoldPtr; // ebx
  float v6; // xmm0_4
  btCollisionShape *m_collisionShape; // ecx
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  const vostok::math::float4x4 *v12; // xmm1_4
  float v13; // xmm4_4
  float v14; // xmm3_4
  void (__thiscall *addContactPoint)(struct btManifoldResult *, const btVector3 *, const btVector3 *, float); // eax
  float v16; // xmm1_4
  unsigned int v17; // xmm0_4
  btPersistentManifold *v18; // eax
  btPersistentManifold *_X; // [esp+FCh] [ebp-54h]
  btCollisionShape *v20; // [esp+118h] [ebp-38h]
  float v21; // [esp+11Ch] [ebp-34h]
  __m128i v22; // [esp+120h] [ebp-30h] BYREF
  float v23; // [esp+130h] [ebp-20h]
  float v24; // [esp+134h] [ebp-1Ch]
  float v25; // [esp+138h] [ebp-18h]
  __m128i v26; // [esp+140h] [ebp-10h] BYREF

  m_manifoldPtr = this->m_manifoldPtr;
  if ( m_manifoldPtr )
  {
    resultOut->m_manifoldPtr = m_manifoldPtr;
    v6 = col0->m_worldTransform.m_origin.mVec128.m128_f32[0] - col1->m_worldTransform.m_origin.mVec128.m128_f32[0];
    m_collisionShape = col0->m_collisionShape;
    v8 = col0->m_worldTransform.m_origin.mVec128.m128_f32[1] - col1->m_worldTransform.m_origin.mVec128.m128_f32[1];
    v25 = col0->m_worldTransform.m_origin.mVec128.m128_f32[2] - col1->m_worldTransform.m_origin.mVec128.m128_f32[2];
    v23 = v6;
    v20 = m_collisionShape;
    v24 = v8;
    v21 = sqrtf((float)((float)(v25 * v25) + (float)(v6 * v6)) + (float)(v8 * v8));
    v9 = *(float *)&col1->m_collisionShape[2].m_userPointer * *(float *)&col1->m_collisionShape[1].m_shapeType;
    v10 = v9 + (float)(*(float *)&v20[2].m_userPointer * *(float *)&v20[1].m_shapeType);
    if ( v21 > v10 )
    {
      if ( !m_manifoldPtr->m_cachedPoints )
        return;
      _X = m_manifoldPtr;
      if ( m_manifoldPtr->m_body0 != resultOut->m_body0 )
      {
        btPersistentManifold::refreshContactPoints(m_manifoldPtr, &resultOut->m_rootTransB, &resultOut->m_rootTransA);
        return;
      }
LABEL_11:
      btPersistentManifold::refreshContactPoints(_X, &resultOut->m_rootTransA, &resultOut->m_rootTransB);
      return;
    }
    v11 = v21 - v10;
    v12 = clear_value;
    v13 = 0.0;
    v14 = 0.0;
    v22.m128i_i64[0] = (unsigned int)clear_value;
    v22.m128i_i64[1] = 0;
    if ( v21 > 0.00000011920929 )
    {
      *(float *)v26.m128i_i32 = v23 * (float)(*(float *)&clear_value / v21);
      *(float *)&v26.m128i_i32[1] = v24 * (float)(*(float *)&clear_value / v21);
      *(float *)&v26.m128i_i32[2] = v25 * (float)(*(float *)&clear_value / v21);
      v26.m128i_i32[3] = 0;
      v22 = _mm_load_si128(&v26);
      v14 = *(float *)&v22.m128i_i32[2];
      v13 = *(float *)&v22.m128i_i32[1];
      v12 = (const vostok::math::float4x4 *)v22.m128i_i32[0];
    }
    addContactPoint = resultOut->addContactPoint;
    v16 = (float)(*(float *)&v12 * v9) + col1->m_worldTransform.m_origin.mVec128.m128_f32[0];
    *(float *)&v26.m128i_i32[1] = col1->m_worldTransform.m_origin.mVec128.m128_f32[1] + (float)(v13 * v9);
    *(float *)&v17 = col1->m_worldTransform.m_origin.mVec128.m128_f32[2] + (float)(v14 * v9);
    *(float *)v26.m128i_i32 = v16;
    v26.m128i_i64[1] = v17;
    ((void (__thiscall *)(btManifoldResult *, __m128i *, __m128i *, _DWORD))addContactPoint)(
      resultOut,
      &v22,
      &v26,
      LODWORD(v11));
    v18 = resultOut->m_manifoldPtr;
    if ( v18->m_cachedPoints )
    {
      _X = resultOut->m_manifoldPtr;
      if ( v18->m_body0 != resultOut->m_body0 )
      {
        btPersistentManifold::refreshContactPoints(_X, &resultOut->m_rootTransB, &resultOut->m_rootTransA);
        return;
      }
      goto LABEL_11;
    }
  }
}
