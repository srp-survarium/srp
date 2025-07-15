void __userpurge btManifoldResult::addContactPoint(
        btManifoldResult *this@<ecx>,
        const struct btVector3 *a2@<edi>,
        float a3@<esi>,
        const btVector3 *normalOnBInWorld,
        const btVector3 *pointInWorld,
        float depth)
{
  btPersistentManifold *m_manifoldPtr; // eax
  bool v8; // zf
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  unsigned int v12; // xmm1_4
  unsigned int v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  unsigned int v18; // xmm1_4
  unsigned int v19; // xmm2_4
  float v20; // xmm0_4
  float v21; // xmm0_4
  btPersistentManifold *v22; // ecx
  int m_cachedPoints; // edx
  float m_contactBreakingThreshold; // xmm3_4
  int v25; // esi
  int v26; // eax
  float v27; // xmm3_4
  float *v28; // edi
  btCollisionObject *m_body0; // edi
  btCollisionObject *m_body1; // edx
  float v31; // xmm0_4
  int m_index0; // eax
  btCollisionObject *v33; // edx
  btCollisionObject *v34; // ecx
  bool v35; // [esp+1h] [ebp-191h]
  btVector3 v36; // [esp+2h] [ebp-190h] BYREF
  unsigned __int64 v37; // [esp+12h] [ebp-180h]
  float v38; // [esp+1Ah] [ebp-178h]
  int v39; // [esp+1Eh] [ebp-174h]
  btMatrix3x3 v40; // [esp+22h] [ebp-170h] BYREF
  unsigned __int64 v41; // [esp+52h] [ebp-140h]
  unsigned __int64 v42; // [esp+5Ah] [ebp-138h]
  btManifoldPoint v43; // [esp+62h] [ebp-130h] BYREF

  m_manifoldPtr = this->m_manifoldPtr;
  if ( depth <= m_manifoldPtr->m_contactBreakingThreshold )
  {
    v8 = m_manifoldPtr->m_body0 == this->m_body0;
    v9 = (float)(normalOnBInWorld->mVec128.m128_f32[1] * depth) + pointInWorld->mVec128.m128_f32[1];
    v10 = (float)(normalOnBInWorld->mVec128.m128_f32[2] * depth) + pointInWorld->mVec128.m128_f32[2];
    v35 = m_manifoldPtr->m_body0 != this->m_body0;
    v11 = pointInWorld->mVec128.m128_f32[0] + (float)(normalOnBInWorld->mVec128.m128_f32[0] * depth);
    *(float *)&v41 = v11;
    *((float *)&v41 + 1) = v9;
    v42 = LODWORD(v10);
    if ( v8 )
    {
      *(float *)&v18 = v9 - this->m_rootTransA.m_origin.mVec128.m128_f32[1];
      *(float *)&v19 = v10 - this->m_rootTransA.m_origin.mVec128.m128_f32[2];
      v36.mVec128.m128_f32[0] = v11 - this->m_rootTransA.m_origin.mVec128.m128_f32[0];
      *(unsigned __int64 *)((char *)v36.mVec128.m128_u64 + 4) = __PAIR64__(v19, v18);
      btMatrix3x3::btMatrix3x3(
        &this->m_rootTransA.m_basis,
        &v40,
        this->m_rootTransA.m_basis.m_el[1].mVec128.m128_f32,
        this->m_rootTransA.m_basis.m_el[2].mVec128.m128_f32,
        &this->m_rootTransA.m_basis.m_el[0].mVec128.m128_f32[1],
        &this->m_rootTransA.m_basis.m_el[1].mVec128.m128_f32[1],
        &this->m_rootTransA.m_basis.m_el[2].mVec128.m128_f32[1],
        &this->m_rootTransA.m_basis.m_el[0].mVec128.m128_f32[2],
        &this->m_rootTransA.m_basis.m_el[1].mVec128.m128_f32[2],
        &this->m_rootTransA.m_basis.m_el[2].mVec128.m128_f32[2]);
      *(float *)&v37 = (float)((float)(v40.m_el[0].mVec128.m128_f32[2] * *(float *)&v19)
                             + (float)(v40.m_el[0].mVec128.m128_f32[1] * *(float *)&v18))
                     + (float)(v40.m_el[0].mVec128.m128_f32[0] * v36.mVec128.m128_f32[0]);
      *((float *)&v37 + 1) = (float)((float)(v40.m_el[1].mVec128.m128_f32[2] * *(float *)&v19)
                                   + (float)(v40.m_el[1].mVec128.m128_f32[1] * *(float *)&v18))
                           + (float)(v40.m_el[1].mVec128.m128_f32[0] * v36.mVec128.m128_f32[0]);
      v38 = (float)((float)(v40.m_el[2].mVec128.m128_f32[2] * *(float *)&v19)
                  + (float)(v40.m_el[2].mVec128.m128_f32[1] * *(float *)&v18))
          + (float)(v40.m_el[2].mVec128.m128_f32[0] * v36.mVec128.m128_f32[0]);
      v39 = 0;
      v36.mVec128.m128_f32[0] = pointInWorld->mVec128.m128_f32[0] - this->m_rootTransB.m_origin.mVec128.m128_f32[0];
      v20 = pointInWorld->mVec128.m128_f32[1] - this->m_rootTransB.m_origin.mVec128.m128_f32[1];
      v43.m_localPointA.mVec128.m128_u64[0] = v37;
      v36.mVec128.m128_f32[1] = v20;
      v21 = pointInWorld->mVec128.m128_f32[2] - this->m_rootTransB.m_origin.mVec128.m128_f32[2];
      v43.m_localPointA.mVec128.m128_u64[1] = LODWORD(v38);
      v36.mVec128.m128_f32[2] = v21;
      btMatrix3x3::btMatrix3x3(
        &this->m_rootTransB.m_basis,
        &v40,
        this->m_rootTransB.m_basis.m_el[1].mVec128.m128_f32,
        this->m_rootTransB.m_basis.m_el[2].mVec128.m128_f32,
        &this->m_rootTransB.m_basis.m_el[0].mVec128.m128_f32[1],
        &this->m_rootTransB.m_basis.m_el[1].mVec128.m128_f32[1],
        &this->m_rootTransB.m_basis.m_el[2].mVec128.m128_f32[1],
        &this->m_rootTransB.m_basis.m_el[0].mVec128.m128_f32[2],
        &this->m_rootTransB.m_basis.m_el[1].mVec128.m128_f32[2],
        &this->m_rootTransB.m_basis.m_el[2].mVec128.m128_f32[2]);
      v16 = v40.m_el[1].mVec128.m128_f32[1] * v36.mVec128.m128_f32[1];
      *(float *)&v37 = (float)((float)(v40.m_el[0].mVec128.m128_f32[2] * v21)
                             + (float)(v40.m_el[0].mVec128.m128_f32[1] * v36.mVec128.m128_f32[1]))
                     + (float)(v40.m_el[0].mVec128.m128_f32[0] * v36.mVec128.m128_f32[0]);
      v17 = v40.m_el[1].mVec128.m128_f32[2] * v21;
    }
    else
    {
      *(float *)&v12 = v9 - this->m_rootTransB.m_origin.mVec128.m128_f32[1];
      *(float *)&v13 = v10 - this->m_rootTransB.m_origin.mVec128.m128_f32[2];
      v36.mVec128.m128_f32[0] = v11 - this->m_rootTransB.m_origin.mVec128.m128_f32[0];
      *(unsigned __int64 *)((char *)v36.mVec128.m128_u64 + 4) = __PAIR64__(v13, v12);
      btMatrix3x3::btMatrix3x3(
        &this->m_rootTransB.m_basis,
        &v40,
        this->m_rootTransB.m_basis.m_el[1].mVec128.m128_f32,
        this->m_rootTransB.m_basis.m_el[2].mVec128.m128_f32,
        &this->m_rootTransB.m_basis.m_el[0].mVec128.m128_f32[1],
        &this->m_rootTransB.m_basis.m_el[1].mVec128.m128_f32[1],
        &this->m_rootTransB.m_basis.m_el[2].mVec128.m128_f32[1],
        &this->m_rootTransB.m_basis.m_el[0].mVec128.m128_f32[2],
        &this->m_rootTransB.m_basis.m_el[1].mVec128.m128_f32[2],
        &this->m_rootTransB.m_basis.m_el[2].mVec128.m128_f32[2]);
      *(float *)&v37 = (float)((float)(v40.m_el[0].mVec128.m128_f32[0] * v36.mVec128.m128_f32[0])
                             + (float)(v40.m_el[0].mVec128.m128_f32[2] * *(float *)&v13))
                     + (float)(v40.m_el[0].mVec128.m128_f32[1] * *(float *)&v12);
      *((float *)&v37 + 1) = (float)((float)(v40.m_el[1].mVec128.m128_f32[0] * v36.mVec128.m128_f32[0])
                                   + (float)(v40.m_el[1].mVec128.m128_f32[2] * *(float *)&v13))
                           + (float)(v40.m_el[1].mVec128.m128_f32[1] * *(float *)&v12);
      v38 = (float)((float)(v40.m_el[2].mVec128.m128_f32[0] * v36.mVec128.m128_f32[0])
                  + (float)(v40.m_el[2].mVec128.m128_f32[2] * *(float *)&v13))
          + (float)(v40.m_el[2].mVec128.m128_f32[1] * *(float *)&v12);
      v39 = 0;
      v36.mVec128.m128_f32[0] = pointInWorld->mVec128.m128_f32[0] - this->m_rootTransA.m_origin.mVec128.m128_f32[0];
      v14 = pointInWorld->mVec128.m128_f32[1] - this->m_rootTransA.m_origin.mVec128.m128_f32[1];
      v43.m_localPointA.mVec128.m128_u64[0] = v37;
      v36.mVec128.m128_f32[1] = v14;
      v15 = pointInWorld->mVec128.m128_f32[2] - this->m_rootTransA.m_origin.mVec128.m128_f32[2];
      v43.m_localPointA.mVec128.m128_u64[1] = LODWORD(v38);
      v36.mVec128.m128_f32[2] = v15;
      btMatrix3x3::btMatrix3x3(
        &this->m_rootTransA.m_basis,
        &v40,
        this->m_rootTransA.m_basis.m_el[1].mVec128.m128_f32,
        this->m_rootTransA.m_basis.m_el[2].mVec128.m128_f32,
        &this->m_rootTransA.m_basis.m_el[0].mVec128.m128_f32[1],
        &this->m_rootTransA.m_basis.m_el[1].mVec128.m128_f32[1],
        &this->m_rootTransA.m_basis.m_el[2].mVec128.m128_f32[1],
        &this->m_rootTransA.m_basis.m_el[0].mVec128.m128_f32[2],
        &this->m_rootTransA.m_basis.m_el[1].mVec128.m128_f32[2],
        &this->m_rootTransA.m_basis.m_el[2].mVec128.m128_f32[2]);
      v16 = v40.m_el[1].mVec128.m128_f32[2] * v15;
      *(float *)&v37 = (float)((float)(v40.m_el[0].mVec128.m128_f32[0] * v36.mVec128.m128_f32[0])
                             + (float)(v40.m_el[0].mVec128.m128_f32[2] * v15))
                     + (float)(v40.m_el[0].mVec128.m128_f32[1] * v36.mVec128.m128_f32[1]);
      v17 = v40.m_el[1].mVec128.m128_f32[1] * v36.mVec128.m128_f32[1];
    }
    *((float *)&v37 + 1) = (float)(v17 + v16) + (float)(v40.m_el[1].mVec128.m128_f32[0] * v36.mVec128.m128_f32[0]);
    v38 = (float)((float)(v40.m_el[2].mVec128.m128_f32[2] * v36.mVec128.m128_f32[2])
                + (float)(v40.m_el[2].mVec128.m128_f32[1] * v36.mVec128.m128_f32[1]))
        + (float)(v40.m_el[2].mVec128.m128_f32[0] * v36.mVec128.m128_f32[0]);
    v39 = 0;
    v36.mVec128.m128_u64[0] = v37;
    v36.mVec128.m128_u64[1] = LODWORD(v38);
    btManifoldPoint::btManifoldPoint(&v43, (btManifoldPoint *)&v43.m_localPointB, depth, &v36, normalOnBInWorld, a2, a3);
    v43.m_normalWorldOnB.mVec128.m128_u64[0] = v41;
    v22 = this->m_manifoldPtr;
    m_cachedPoints = v22->m_cachedPoints;
    v43.m_normalWorldOnB.mVec128.m128_u64[1] = v42;
    m_contactBreakingThreshold = v22->m_contactBreakingThreshold;
    v43.m_positionWorldOnA = (btVector3)pointInWorld->mVec128;
    v25 = -1;
    v26 = 0;
    v27 = m_contactBreakingThreshold * m_contactBreakingThreshold;
    if ( m_cachedPoints > 0 )
    {
      v28 = &v22->m_pointCache[0].m_localPointA.mVec128.m128_f32[2];
      do
      {
        if ( v27 > (float)((float)((float)((float)(*(v28 - 2) - v43.m_localPointB.mVec128.m128_f32[0])
                                         * (float)(*(v28 - 2) - v43.m_localPointB.mVec128.m128_f32[0]))
                                 + (float)((float)(*v28 - v43.m_localPointB.mVec128.m128_f32[2])
                                         * (float)(*v28 - v43.m_localPointB.mVec128.m128_f32[2])))
                         + (float)((float)(*(v28 - 1) - v43.m_localPointB.mVec128.m128_f32[1])
                                 * (float)(*(v28 - 1) - v43.m_localPointB.mVec128.m128_f32[1]))) )
        {
          v27 = (float)((float)((float)(*(v28 - 2) - v43.m_localPointB.mVec128.m128_f32[0])
                              * (float)(*(v28 - 2) - v43.m_localPointB.mVec128.m128_f32[0]))
                      + (float)((float)(*v28 - v43.m_localPointB.mVec128.m128_f32[2])
                              * (float)(*v28 - v43.m_localPointB.mVec128.m128_f32[2])))
              + (float)((float)(*(v28 - 1) - v43.m_localPointB.mVec128.m128_f32[1])
                      * (float)(*(v28 - 1) - v43.m_localPointB.mVec128.m128_f32[1]));
          v25 = v26;
        }
        ++v26;
        v28 += 72;
      }
      while ( v26 < m_cachedPoints );
    }
    m_body0 = this->m_body0;
    m_body1 = this->m_body1;
    v31 = m_body0->m_friction * m_body1->m_friction;
    if ( v31 < -10.0 )
      v31 = FLOAT_N10_0;
    if ( v31 > 10.0 )
      v31 = FLOAT_10_0;
    *(float *)&v43.m_index0 = v31;
    *(float *)&v43.m_index1 = m_body0->m_restitution * m_body1->m_restitution;
    if ( v35 )
    {
      v43.m_userPersistentData = (void *)this->m_partId1;
      LODWORD(v43.m_appliedImpulse) = this->m_partId0;
      *(_DWORD *)&v43.m_lateralFrictionInitialized = this->m_index1;
      m_index0 = this->m_index0;
    }
    else
    {
      v43.m_userPersistentData = (void *)this->m_partId0;
      LODWORD(v43.m_appliedImpulse) = this->m_partId1;
      *(_DWORD *)&v43.m_lateralFrictionInitialized = this->m_index0;
      m_index0 = this->m_index1;
    }
    LODWORD(v43.m_appliedImpulseLateral1) = m_index0;
    if ( v25 < 0 )
      v25 = btPersistentManifold::addManifoldPoint(v22, (int)v22, (btPersistentManifold *)&v43.m_localPointB);
    else
      btPersistentManifold::replaceContactPoint(v22, v25, (const btManifoldPoint *)&v43.m_localPointB);
    if ( gContactAddedCallback
      && ((this->m_body0->m_collisionFlags & 8) != 0 || (this->m_body1->m_collisionFlags & 8) != 0) )
    {
      if ( v35 )
        v33 = this->m_body1;
      else
        v33 = this->m_body0;
      v34 = this->m_body0;
      if ( !v35 )
        v34 = this->m_body1;
      gContactAddedCallback(
        &this->m_manifoldPtr->m_pointCache[v25],
        v33,
        (int)v43.m_userPersistentData,
        *(int *)&v43.m_lateralFrictionInitialized,
        v34,
        SLODWORD(v43.m_appliedImpulse),
        SLODWORD(v43.m_appliedImpulseLateral1));
    }
  }
}
