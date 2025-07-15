void __userpurge btBridgedManifoldResult::addContactPoint(
        btBridgedManifoldResult *this@<ecx>,
        const struct btVector3 *a2@<edi>,
        float a3@<esi>,
        const btVector3 *normalOnBInWorld,
        const btVector3 *pointInWorld,
        float depth)
{
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm0_4
  unsigned int v10; // xmm1_4
  unsigned int v11; // xmm2_4
  btTransform *p_m_rootTransA; // ecx
  unsigned int v13; // xmm1_4
  unsigned int v14; // xmm2_4
  unsigned int v15; // xmm0_4
  void *m_partId1; // eax
  float v17; // esi
  int m_index1; // edi
  int m_index0; // ecx
  btCollisionObject *m_body1; // ecx
  btCollisionObject *m_body0; // edx
  bool v22; // [esp+7h] [ebp-1A1h]
  btVector3 v23; // [esp+8h] [ebp-1A0h] BYREF
  unsigned __int64 v24; // [esp+18h] [ebp-190h]
  float v25; // [esp+20h] [ebp-188h]
  int v26; // [esp+24h] [ebp-184h]
  btMatrix3x3 v27; // [esp+28h] [ebp-180h] BYREF
  const btCollisionObject *v28; // [esp+64h] [ebp-144h]
  btVector3 v29; // [esp+68h] [ebp-140h]
  btManifoldPoint v30; // [esp+78h] [ebp-130h] BYREF

  v7 = (float)(normalOnBInWorld->mVec128.m128_f32[1] * depth) + pointInWorld->mVec128.m128_f32[1];
  v8 = (float)(normalOnBInWorld->mVec128.m128_f32[2] * depth) + pointInWorld->mVec128.m128_f32[2];
  v22 = this->m_manifoldPtr->m_body0 != this->m_body0;
  v9 = pointInWorld->mVec128.m128_f32[0] + (float)(normalOnBInWorld->mVec128.m128_f32[0] * depth);
  v29.mVec128.m128_f32[0] = v9;
  v29.mVec128.m128_f32[1] = v7;
  v29.mVec128.m128_u64[1] = LODWORD(v8);
  if ( v22 )
  {
    *(float *)&v10 = v7 - this->m_rootTransB.m_origin.mVec128.m128_f32[1];
    *(float *)&v11 = v8 - this->m_rootTransB.m_origin.mVec128.m128_f32[2];
    v23.mVec128.m128_f32[0] = v9 - this->m_rootTransB.m_origin.mVec128.m128_f32[0];
    *(unsigned __int64 *)((char *)v23.mVec128.m128_u64 + 4) = __PAIR64__(v11, v10);
    btMatrix3x3::btMatrix3x3(
      &this->m_rootTransB.m_basis,
      &v27,
      this->m_rootTransB.m_basis.m_el[1].mVec128.m128_f32,
      this->m_rootTransB.m_basis.m_el[2].mVec128.m128_f32,
      &this->m_rootTransB.m_basis.m_el[0].mVec128.m128_f32[1],
      &this->m_rootTransB.m_basis.m_el[1].mVec128.m128_f32[1],
      &this->m_rootTransB.m_basis.m_el[2].mVec128.m128_f32[1],
      &this->m_rootTransB.m_basis.m_el[0].mVec128.m128_f32[2],
      &this->m_rootTransB.m_basis.m_el[1].mVec128.m128_f32[2],
      &this->m_rootTransB.m_basis.m_el[2].mVec128.m128_f32[2]);
    p_m_rootTransA = &this->m_rootTransA;
  }
  else
  {
    *(float *)&v13 = v7 - this->m_rootTransA.m_origin.mVec128.m128_f32[1];
    *(float *)&v14 = v8 - this->m_rootTransA.m_origin.mVec128.m128_f32[2];
    v23.mVec128.m128_f32[0] = v9 - this->m_rootTransA.m_origin.mVec128.m128_f32[0];
    *(unsigned __int64 *)((char *)v23.mVec128.m128_u64 + 4) = __PAIR64__(v14, v13);
    btMatrix3x3::btMatrix3x3(
      &this->m_rootTransA.m_basis,
      &v27,
      this->m_rootTransA.m_basis.m_el[1].mVec128.m128_f32,
      this->m_rootTransA.m_basis.m_el[2].mVec128.m128_f32,
      &this->m_rootTransA.m_basis.m_el[0].mVec128.m128_f32[1],
      &this->m_rootTransA.m_basis.m_el[1].mVec128.m128_f32[1],
      &this->m_rootTransA.m_basis.m_el[2].mVec128.m128_f32[1],
      &this->m_rootTransA.m_basis.m_el[0].mVec128.m128_f32[2],
      &this->m_rootTransA.m_basis.m_el[1].mVec128.m128_f32[2],
      &this->m_rootTransA.m_basis.m_el[2].mVec128.m128_f32[2]);
    p_m_rootTransA = &this->m_rootTransB;
  }
  *(float *)&v24 = (float)((float)(v27.m_el[0].mVec128.m128_f32[2] * v23.mVec128.m128_f32[2])
                         + (float)(v27.m_el[0].mVec128.m128_f32[1] * v23.mVec128.m128_f32[1]))
                 + (float)(v27.m_el[0].mVec128.m128_f32[0] * v23.mVec128.m128_f32[0]);
  *((float *)&v24 + 1) = (float)((float)(v27.m_el[1].mVec128.m128_f32[2] * v23.mVec128.m128_f32[2])
                               + (float)(v27.m_el[1].mVec128.m128_f32[1] * v23.mVec128.m128_f32[1]))
                       + (float)(v27.m_el[1].mVec128.m128_f32[0] * v23.mVec128.m128_f32[0]);
  v25 = (float)((float)(v27.m_el[2].mVec128.m128_f32[2] * v23.mVec128.m128_f32[2])
              + (float)(v27.m_el[2].mVec128.m128_f32[1] * v23.mVec128.m128_f32[1]))
      + (float)(v27.m_el[2].mVec128.m128_f32[0] * v23.mVec128.m128_f32[0]);
  v26 = 0;
  v23.mVec128.m128_f32[0] = pointInWorld->mVec128.m128_f32[0] - p_m_rootTransA->m_origin.mVec128.m128_f32[0];
  v23.mVec128.m128_f32[1] = pointInWorld->mVec128.m128_f32[1] - p_m_rootTransA->m_origin.mVec128.m128_f32[1];
  *(float *)&v15 = pointInWorld->mVec128.m128_f32[2] - p_m_rootTransA->m_origin.mVec128.m128_f32[2];
  v30.m_localPointA.mVec128.m128_u64[0] = v24;
  v30.m_localPointA.mVec128.m128_u64[1] = LODWORD(v25);
  btMatrix3x3::btMatrix3x3(
    &p_m_rootTransA->m_basis,
    &v27,
    p_m_rootTransA->m_basis.m_el[1].mVec128.m128_f32,
    p_m_rootTransA->m_basis.m_el[2].mVec128.m128_f32,
    &p_m_rootTransA->m_basis.m_el[0].mVec128.m128_f32[1],
    &p_m_rootTransA->m_basis.m_el[1].mVec128.m128_f32[1],
    &p_m_rootTransA->m_basis.m_el[2].mVec128.m128_f32[1],
    &p_m_rootTransA->m_basis.m_el[0].mVec128.m128_f32[2],
    &p_m_rootTransA->m_basis.m_el[1].mVec128.m128_f32[2],
    &p_m_rootTransA->m_basis.m_el[2].mVec128.m128_f32[2]);
  *(float *)&v24 = (float)((float)(v27.m_el[0].mVec128.m128_f32[2] * *(float *)&v15)
                         + (float)(v27.m_el[0].mVec128.m128_f32[1] * v23.mVec128.m128_f32[1]))
                 + (float)(v27.m_el[0].mVec128.m128_f32[0] * v23.mVec128.m128_f32[0]);
  *((float *)&v24 + 1) = (float)((float)(v27.m_el[1].mVec128.m128_f32[2] * *(float *)&v15)
                               + (float)(v27.m_el[1].mVec128.m128_f32[1] * v23.mVec128.m128_f32[1]))
                       + (float)(v27.m_el[1].mVec128.m128_f32[0] * v23.mVec128.m128_f32[0]);
  v25 = (float)((float)(v27.m_el[2].mVec128.m128_f32[2] * *(float *)&v15)
              + (float)(v27.m_el[2].mVec128.m128_f32[1] * v23.mVec128.m128_f32[1]))
      + (float)(v27.m_el[2].mVec128.m128_f32[0] * v23.mVec128.m128_f32[0]);
  v26 = 0;
  v23.mVec128.m128_f32[0] = *(float *)&v24;
  *(unsigned __int64 *)((char *)v23.mVec128.m128_u64 + 4) = __PAIR64__(v15, HIDWORD(v24));
  v23.mVec128.m128_u64[1] = LODWORD(v25);
  btManifoldPoint::btManifoldPoint(&v30, (btManifoldPoint *)&v30.m_localPointB, depth, &v23, normalOnBInWorld, a2, a3);
  v30.m_normalWorldOnB = (btVector3)v29.mVec128;
  v30.m_positionWorldOnA = (btVector3)pointInWorld->mVec128;
  if ( v22 )
  {
    m_partId1 = (void *)this->m_partId1;
    v17 = *(float *)&this->m_partId0;
    m_index1 = this->m_index1;
    m_index0 = this->m_index0;
  }
  else
  {
    m_partId1 = (void *)this->m_partId0;
    v17 = *(float *)&this->m_partId1;
    m_index1 = this->m_index0;
    m_index0 = this->m_index1;
  }
  LODWORD(v30.m_appliedImpulseLateral1) = m_index0;
  *(_DWORD *)&v30.m_lateralFrictionInitialized = m_index1;
  v30.m_appliedImpulse = v17;
  v30.m_userPersistentData = m_partId1;
  if ( v22 )
    m_body1 = this->m_body1;
  else
    m_body1 = this->m_body0;
  v28 = m_body1;
  if ( v22 )
    m_body0 = this->m_body0;
  else
    m_body0 = this->m_body1;
  this->m_resultCallback->addSingleResult(
    this->m_resultCallback,
    (btManifoldPoint *)&v30.m_localPointB,
    v28,
    (int)m_partId1,
    m_index1,
    m_body0,
    LODWORD(v17),
    LODWORD(v30.m_appliedImpulseLateral1));
}
