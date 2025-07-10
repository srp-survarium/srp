void __thiscall btManifoldResult::addContactPoint(
        btManifoldResult *this,
        const btVector3 *normalOnBInWorld,
        const btVector3 *pointInWorld,
        float depth)
{
  btPersistentManifold *m_manifoldPtr; // ecx
  bool v6; // zf
  float v7; // xmm3_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  unsigned int v13; // xmm1_4
  unsigned int v14; // xmm2_4
  int v15; // xmm7_4
  float v16; // xmm6_4
  int v17; // xmm0_4
  float v18; // xmm6_4
  int v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm6_4
  float v22; // xmm3_4
  float v23; // xmm4_4
  float v24; // xmm5_4
  int v25; // xmm7_4
  int v26; // xmm1_4
  float v27; // xmm1_4
  float v28; // xmm6_4
  int v29; // xmm2_4
  float v30; // xmm7_4
  int v31; // xmm1_4
  __m128 v32; // xmm0
  int v33; // xmm1_4
  int v34; // xmm2_4
  float v35; // xmm1_4
  float v36; // xmm2_4
  float v37; // xmm0_4
  float v38; // xmm7_4
  float v39; // xmm6_4
  float v40; // xmm1_4
  unsigned int v41; // xmm2_4
  float v42; // xmm6_4
  float v43; // xmm7_4
  int v44; // xmm1_4
  float v45; // xmm6_4
  float v46; // xmm0_4
  float v47; // xmm1_4
  float v48; // xmm6_4
  float v49; // xmm1_4
  int v50; // xmm2_4
  float v51; // xmm7_4
  int v52; // xmm1_4
  __m128 si128; // xmm0
  int v54; // xmm1_4
  int v55; // xmm2_4
  btPersistentManifold *v56; // ebx
  int CacheEntry; // eax
  btCollisionObject *m_body0; // ecx
  float v59; // xmm1_4
  int v60; // esi
  btCollisionObject *m_body1; // eax
  float v62; // xmm0_4
  int m_partId0; // edx
  int m_index1; // eax
  int m_index0; // ecx
  int m_partId1; // eax
  int v67; // ecx
  int v68; // edx
  btCollisionObject *v69; // eax
  btCollisionObject *v70; // ecx
  bool isSwapped; // [esp+541h] [ebp-181h]
  btVector3 pointB; // [esp+542h] [ebp-180h] BYREF
  btVector3 v73; // [esp+552h] [ebp-170h]
  float v74; // [esp+562h] [ebp-160h]
  float v75; // [esp+56Ah] [ebp-158h]
  float v76; // [esp+572h] [ebp-150h]
  float v77; // [esp+576h] [ebp-14Ch]
  float v78; // [esp+57Ah] [ebp-148h]
  float v79; // [esp+582h] [ebp-140h]
  float v80; // [esp+586h] [ebp-13Ch]
  float v81; // [esp+58Ah] [ebp-138h]
  __m128i v82; // [esp+592h] [ebp-130h] BYREF
  btManifoldPoint newPoint; // [esp+5A2h] [ebp-120h] BYREF

  m_manifoldPtr = this->m_manifoldPtr;
  if ( depth <= m_manifoldPtr->m_contactBreakingThreshold )
  {
    v6 = m_manifoldPtr->m_body0 == this->m_body0;
    v7 = pointInWorld->mVec128.m128_f32[0];
    v8 = pointInWorld->mVec128.m128_f32[1];
    v9 = pointInWorld->mVec128.m128_f32[2];
    v10 = pointInWorld->mVec128.m128_f32[0] + (float)(normalOnBInWorld->mVec128.m128_f32[0] * depth);
    v11 = v8 + (float)(normalOnBInWorld->mVec128.m128_f32[1] * depth);
    v12 = v9 + (float)(normalOnBInWorld->mVec128.m128_f32[2] * depth);
    isSwapped = m_manifoldPtr->m_body0 != this->m_body0;
    *(float *)v82.m128i_i32 = v10;
    *(float *)&v82.m128i_i32[1] = v11;
    v82.m128i_i64[1] = LODWORD(v12);
    if ( v6 )
    {
      v40 = v11 - this->m_rootTransA.m_origin.mVec128.m128_f32[1];
      *(float *)&v41 = v12 - this->m_rootTransA.m_origin.mVec128.m128_f32[2];
      v42 = this->m_rootTransA.m_basis.m_el[1].mVec128.m128_f32[0];
      v73.mVec128.m128_f32[0] = v10 - this->m_rootTransA.m_origin.mVec128.m128_f32[0];
      v75 = this->m_rootTransA.m_basis.m_el[2].mVec128.m128_f32[0];
      v43 = v40;
      v44 = this->m_rootTransA.m_basis.m_el[0].mVec128.m128_i32[2];
      v76 = this->m_rootTransA.m_basis.m_el[0].mVec128.m128_f32[1];
      v22 = v7 - this->m_rootTransB.m_origin.mVec128.m128_f32[0];
      v23 = v8 - this->m_rootTransB.m_origin.mVec128.m128_f32[1];
      v24 = v9 - this->m_rootTransB.m_origin.mVec128.m128_f32[2];
      v45 = (float)(v42 * v43)
          + (float)(this->m_rootTransA.m_basis.m_el[0].mVec128.m128_f32[0] * v73.mVec128.m128_f32[0]);
      v77 = this->m_rootTransA.m_basis.m_el[1].mVec128.m128_f32[1];
      v46 = this->m_rootTransA.m_basis.m_el[2].mVec128.m128_f32[1];
      *(unsigned __int64 *)((char *)v73.mVec128.m128_u64 + 4) = __PAIR64__(v41, LODWORD(v43));
      pointB.mVec128.m128_f32[0] = v45 + (float)(v75 * *(float *)&v41);
      v79 = *(float *)&v44;
      v80 = this->m_rootTransA.m_basis.m_el[1].mVec128.m128_f32[2];
      v47 = this->m_rootTransA.m_basis.m_el[2].mVec128.m128_f32[2];
      v48 = this->m_rootTransB.m_basis.m_el[1].mVec128.m128_f32[0];
      pointB.mVec128.m128_f32[1] = (float)((float)(v46 * *(float *)&v41) + (float)(v77 * v43))
                                 + (float)(v76 * v73.mVec128.m128_f32[0]);
      v49 = v47 * *(float *)&v41;
      v50 = this->m_rootTransB.m_basis.m_el[0].mVec128.m128_i32[2];
      v51 = this->m_rootTransB.m_basis.m_el[2].mVec128.m128_f32[0];
      pointB.mVec128.m128_f32[2] = (float)(v49 + (float)(v80 * v73.mVec128.m128_f32[1]))
                                 + (float)(v79 * v73.mVec128.m128_f32[0]);
      v52 = this->m_rootTransB.m_basis.m_el[0].mVec128.m128_i32[1];
      pointB.mVec128.m128_i32[3] = 0;
      si128 = (__m128)_mm_load_si128((const __m128i *)&pointB);
      v76 = *(float *)&v52;
      v54 = this->m_rootTransB.m_basis.m_el[1].mVec128.m128_i32[1];
      v79 = *(float *)&v50;
      v55 = this->m_rootTransB.m_basis.m_el[1].mVec128.m128_i32[2];
      v73.mVec128 = si128;
      si128.m128_i32[0] = this->m_rootTransB.m_basis.m_el[0].mVec128.m128_i32[0];
      v77 = *(float *)&v54;
      v35 = this->m_rootTransB.m_basis.m_el[2].mVec128.m128_f32[1];
      v80 = *(float *)&v55;
      v36 = this->m_rootTransB.m_basis.m_el[2].mVec128.m128_f32[2];
      v37 = si128.m128_f32[0] * v22;
      v38 = v51 * v24;
      v39 = v48 * v23;
    }
    else
    {
      *(float *)&v13 = v11 - this->m_rootTransB.m_origin.mVec128.m128_f32[1];
      *(float *)&v14 = v12 - this->m_rootTransB.m_origin.mVec128.m128_f32[2];
      v15 = this->m_rootTransB.m_basis.m_el[1].mVec128.m128_i32[2];
      v16 = this->m_rootTransB.m_basis.m_el[1].mVec128.m128_f32[0];
      v73.mVec128.m128_f32[0] = v10 - this->m_rootTransB.m_origin.mVec128.m128_f32[0];
      v17 = this->m_rootTransB.m_basis.m_el[0].mVec128.m128_i32[0];
      *(unsigned __int64 *)((char *)v73.mVec128.m128_u64 + 4) = __PAIR64__(v14, v13);
      v18 = v16 * *(float *)&v13;
      v19 = this->m_rootTransB.m_basis.m_el[1].mVec128.m128_i32[1];
      v74 = *(float *)&v17;
      v20 = this->m_rootTransB.m_basis.m_el[0].mVec128.m128_f32[1];
      v21 = v18 + (float)(this->m_rootTransB.m_basis.m_el[2].mVec128.m128_f32[0] * *(float *)&v14);
      v22 = v7 - this->m_rootTransA.m_origin.mVec128.m128_f32[0];
      v23 = v8 - this->m_rootTransA.m_origin.mVec128.m128_f32[1];
      v24 = v9 - this->m_rootTransA.m_origin.mVec128.m128_f32[2];
      v80 = *(float *)&v15;
      v25 = this->m_rootTransB.m_basis.m_el[2].mVec128.m128_i32[2];
      v77 = *(float *)&v19;
      v26 = this->m_rootTransB.m_basis.m_el[2].mVec128.m128_i32[1];
      v81 = *(float *)&v25;
      v78 = *(float *)&v26;
      v27 = this->m_rootTransB.m_basis.m_el[0].mVec128.m128_f32[2];
      pointB.mVec128.m128_f32[0] = v21 + (float)(v74 * v73.mVec128.m128_f32[0]);
      v28 = this->m_rootTransA.m_basis.m_el[0].mVec128.m128_f32[0];
      pointB.mVec128.m128_f32[1] = (float)((float)(v20 * v73.mVec128.m128_f32[0]) + (float)(v78 * *(float *)&v14))
                                 + (float)(v77 * v73.mVec128.m128_f32[1]);
      v29 = this->m_rootTransA.m_basis.m_el[0].mVec128.m128_i32[2];
      v30 = this->m_rootTransA.m_basis.m_el[1].mVec128.m128_f32[0];
      pointB.mVec128.m128_f32[2] = (float)((float)(v27 * v73.mVec128.m128_f32[0])
                                         + (float)(v81 * v73.mVec128.m128_f32[2]))
                                 + (float)(v80 * v73.mVec128.m128_f32[1]);
      v31 = this->m_rootTransA.m_basis.m_el[0].mVec128.m128_i32[1];
      pointB.mVec128.m128_i32[3] = 0;
      v32 = (__m128)_mm_load_si128((const __m128i *)&pointB);
      v76 = *(float *)&v31;
      v33 = this->m_rootTransA.m_basis.m_el[1].mVec128.m128_i32[1];
      v79 = *(float *)&v29;
      v34 = this->m_rootTransA.m_basis.m_el[1].mVec128.m128_i32[2];
      v73.mVec128 = v32;
      v32.m128_i32[0] = this->m_rootTransA.m_basis.m_el[2].mVec128.m128_i32[0];
      v77 = *(float *)&v33;
      v35 = this->m_rootTransA.m_basis.m_el[2].mVec128.m128_f32[1];
      v80 = *(float *)&v34;
      v36 = this->m_rootTransA.m_basis.m_el[2].mVec128.m128_f32[2];
      v37 = v32.m128_f32[0] * v24;
      v38 = v30 * v23;
      v39 = v28 * v22;
    }
    pointB.mVec128.m128_f32[0] = (float)(v37 + v38) + v39;
    pointB.mVec128.m128_f32[1] = (float)((float)(v35 * v24) + (float)(v77 * v23)) + (float)(v76 * v22);
    pointB.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT((float)((float)(v36 * v24) + (float)(v80 * v23)) + (float)(v79 * v22));
    pointB.mVec128 = (__m128)_mm_load_si128((const __m128i *)&pointB);
    btManifoldPoint::btManifoldPoint(&newPoint, depth);
    newPoint.m_positionWorldOnA = (btVector3)_mm_load_si128(&v82);
    newPoint.m_positionWorldOnB.mVec128.m128_u64[0] = pointInWorld->mVec128.m128_u64[0];
    v56 = this->m_manifoldPtr;
    newPoint.m_positionWorldOnB.mVec128.m128_u64[1] = pointInWorld->mVec128.m128_u64[1];
    CacheEntry = btPersistentManifold::getCacheEntry(&newPoint, v56);
    m_body0 = this->m_body0;
    v59 = -10.0;
    v60 = CacheEntry;
    m_body1 = this->m_body1;
    v62 = m_body0->m_friction * m_body1->m_friction;
    if ( v62 < -10.0 || (v59 = FLOAT_10_0, v62 > 10.0) )
      v62 = v59;
    m_partId0 = this->m_partId0;
    newPoint.m_combinedFriction = v62;
    newPoint.m_combinedRestitution = m_body0->m_restitution * m_body1->m_restitution;
    if ( isSwapped )
    {
      m_index1 = this->m_index1;
      newPoint.m_partId0 = this->m_partId1;
      m_index0 = this->m_index0;
      newPoint.m_partId1 = m_partId0;
      newPoint.m_index0 = m_index1;
      newPoint.m_index1 = m_index0;
    }
    else
    {
      m_partId1 = this->m_partId1;
      v67 = this->m_index0;
      newPoint.m_partId0 = m_partId0;
      v68 = this->m_index1;
      newPoint.m_partId1 = m_partId1;
      newPoint.m_index0 = v67;
      newPoint.m_index1 = v68;
    }
    if ( v60 < 0 )
      v60 = btPersistentManifold::addManifoldPoint(v56, (btPersistentManifold *)&newPoint);
    else
      btPersistentManifold::replaceContactPoint(v56, v60, &newPoint);
    if ( gContactAddedCallback )
    {
      v69 = this->m_body0;
      if ( (v69->m_collisionFlags & 8) != 0 || (this->m_body1->m_collisionFlags & 8) != 0 )
      {
        if ( isSwapped )
        {
          v70 = this->m_body1;
        }
        else
        {
          v70 = this->m_body0;
          v69 = this->m_body1;
        }
        gContactAddedCallback(
          &this->m_manifoldPtr->m_pointCache[v60],
          v70,
          newPoint.m_partId0,
          newPoint.m_index0,
          v69,
          newPoint.m_partId1,
          newPoint.m_index1);
      }
    }
  }
}
