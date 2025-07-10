void __thiscall btBridgedManifoldResult::addContactPoint(
        btBridgedManifoldResult *this,
        const btVector3 *normalOnBInWorld,
        const btVector3 *pointInWorld,
        float depth)
{
  float v4; // xmm3_4
  float v5; // xmm4_4
  float v6; // xmm5_4
  bool v8; // zf
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  unsigned int v12; // xmm1_4
  unsigned int v13; // xmm2_4
  float v14; // xmm6_4
  int v15; // xmm0_4
  int v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm3_4
  float v19; // xmm5_4
  float v20; // xmm4_4
  float v21; // xmm1_4
  float v22; // xmm6_4
  float v23; // xmm7_4
  float v24; // xmm2_4
  int v25; // xmm1_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  unsigned int v30; // xmm1_4
  unsigned int v31; // xmm2_4
  float v32; // xmm6_4
  float v33; // xmm7_4
  float v34; // xmm0_4
  int v35; // xmm1_4
  float v36; // xmm5_4
  float v37; // xmm6_4
  float v38; // xmm3_4
  float v39; // xmm4_4
  int v40; // xmm1_4
  float v41; // xmm1_4
  float v42; // xmm6_4
  float v43; // xmm2_4
  float v44; // xmm0_4
  float v45; // xmm7_4
  int v46; // xmm1_4
  float v47; // xmm0_4
  float v48; // xmm1_4
  int m_partId1; // eax
  int m_partId0; // edx
  int m_index1; // esi
  btCollisionObject *m_body0; // ebx
  btCollisionObject *m_body1; // ecx
  bool v54; // [esp+859h] [ebp-191h]
  btVector3 pointB; // [esp+85Ah] [ebp-190h] BYREF
  btVector3 v56; // [esp+86Ah] [ebp-180h]
  float v57; // [esp+88Ah] [ebp-160h]
  float v58; // [esp+88Eh] [ebp-15Ch]
  float v59; // [esp+89Ah] [ebp-150h]
  float v60; // [esp+89Eh] [ebp-14Ch]
  float v61; // [esp+8AAh] [ebp-140h]
  float v62; // [esp+8AEh] [ebp-13Ch]
  __m128i v63; // [esp+8BAh] [ebp-130h] BYREF
  btManifoldPoint v64; // [esp+8CAh] [ebp-120h] BYREF

  v4 = pointInWorld->mVec128.m128_f32[0];
  v5 = pointInWorld->mVec128.m128_f32[1];
  v6 = pointInWorld->mVec128.m128_f32[2];
  v8 = this->m_manifoldPtr->m_body0 == this->m_body0;
  v9 = pointInWorld->mVec128.m128_f32[0] + (float)(normalOnBInWorld->mVec128.m128_f32[0] * depth);
  v10 = v5 + (float)(normalOnBInWorld->mVec128.m128_f32[1] * depth);
  v11 = v6 + (float)(normalOnBInWorld->mVec128.m128_f32[2] * depth);
  v54 = this->m_manifoldPtr->m_body0 != this->m_body0;
  *(float *)v63.m128i_i32 = v9;
  *(float *)&v63.m128i_i32[1] = v10;
  v63.m128i_i64[1] = LODWORD(v11);
  if ( v8 )
  {
    *(float *)&v30 = v10 - this->m_rootTransA.m_origin.mVec128.m128_f32[1];
    *(float *)&v31 = v11 - this->m_rootTransA.m_origin.mVec128.m128_f32[2];
    v32 = this->m_rootTransA.m_basis.m_el[0].mVec128.m128_f32[0];
    v33 = v9 - this->m_rootTransA.m_origin.mVec128.m128_f32[0];
    v58 = this->m_rootTransA.m_basis.m_el[1].mVec128.m128_f32[0];
    v59 = this->m_rootTransA.m_basis.m_el[0].mVec128.m128_f32[1];
    v60 = this->m_rootTransA.m_basis.m_el[1].mVec128.m128_f32[1];
    v34 = this->m_rootTransA.m_basis.m_el[2].mVec128.m128_f32[1];
    *(unsigned __int64 *)((char *)v56.mVec128.m128_u64 + 4) = __PAIR64__(v31, v30);
    v35 = this->m_rootTransA.m_basis.m_el[0].mVec128.m128_i32[2];
    v36 = v6 - this->m_rootTransB.m_origin.mVec128.m128_f32[2];
    v37 = (float)(v32 * v33) + (float)(this->m_rootTransA.m_basis.m_el[2].mVec128.m128_f32[0] * *(float *)&v31);
    v38 = v4 - this->m_rootTransB.m_origin.mVec128.m128_f32[0];
    v39 = v5 - this->m_rootTransB.m_origin.mVec128.m128_f32[1];
    v56.mVec128.m128_f32[0] = v33;
    v61 = *(float *)&v35;
    v40 = this->m_rootTransA.m_basis.m_el[1].mVec128.m128_i32[2];
    pointB.mVec128.m128_f32[0] = v37 + (float)(v58 * v56.mVec128.m128_f32[1]);
    v62 = *(float *)&v40;
    v41 = this->m_rootTransA.m_basis.m_el[2].mVec128.m128_f32[2] * *(float *)&v31;
    v42 = this->m_rootTransB.m_basis.m_el[1].mVec128.m128_f32[0];
    pointB.mVec128.m128_f32[1] = (float)((float)(v34 * *(float *)&v31) + (float)(v60 * v56.mVec128.m128_f32[1]))
                               + (float)(v59 * v33);
    v43 = this->m_rootTransB.m_basis.m_el[0].mVec128.m128_f32[2];
    v44 = v61 * v33;
    v45 = this->m_rootTransB.m_basis.m_el[2].mVec128.m128_f32[0];
    pointB.mVec128.m128_i32[3] = 0;
    pointB.mVec128.m128_f32[2] = (float)(v41 + (float)(v62 * v56.mVec128.m128_f32[1])) + v44;
    v46 = this->m_rootTransB.m_basis.m_el[0].mVec128.m128_i32[1];
    v56.mVec128 = (__m128)_mm_load_si128((const __m128i *)&pointB);
    v47 = this->m_rootTransB.m_basis.m_el[0].mVec128.m128_f32[0] * v38;
    v59 = *(float *)&v46;
    v60 = this->m_rootTransB.m_basis.m_el[1].mVec128.m128_f32[1];
    v48 = this->m_rootTransB.m_basis.m_el[2].mVec128.m128_f32[1];
    pointB.mVec128.m128_f32[0] = (float)(v47 + (float)(v45 * v36)) + (float)(v42 * v39);
    v61 = v43;
    v62 = this->m_rootTransB.m_basis.m_el[1].mVec128.m128_f32[2];
    v28 = (float)((float)(v48 * v36) + (float)(v60 * v39)) + (float)(v59 * v38);
    v29 = (float)((float)(this->m_rootTransB.m_basis.m_el[2].mVec128.m128_f32[2] * v36) + (float)(v62 * v39))
        + (float)(v43 * v38);
  }
  else
  {
    *(float *)&v12 = v10 - this->m_rootTransB.m_origin.mVec128.m128_f32[1];
    *(float *)&v13 = v11 - this->m_rootTransB.m_origin.mVec128.m128_f32[2];
    v14 = this->m_rootTransB.m_basis.m_el[2].mVec128.m128_f32[0];
    v56.mVec128.m128_f32[0] = v9 - this->m_rootTransB.m_origin.mVec128.m128_f32[0];
    v57 = this->m_rootTransB.m_basis.m_el[0].mVec128.m128_f32[0];
    v59 = this->m_rootTransB.m_basis.m_el[0].mVec128.m128_f32[1];
    v15 = this->m_rootTransB.m_basis.m_el[1].mVec128.m128_i32[1];
    *(unsigned __int64 *)((char *)v56.mVec128.m128_u64 + 4) = __PAIR64__(v13, v12);
    v16 = this->m_rootTransB.m_basis.m_el[0].mVec128.m128_i32[2];
    v60 = *(float *)&v15;
    v17 = this->m_rootTransB.m_basis.m_el[2].mVec128.m128_f32[1];
    v18 = v4 - this->m_rootTransA.m_origin.mVec128.m128_f32[0];
    v19 = v6 - this->m_rootTransA.m_origin.mVec128.m128_f32[2];
    v20 = v5 - this->m_rootTransA.m_origin.mVec128.m128_f32[1];
    pointB.mVec128.m128_f32[0] = (float)((float)(v14 * *(float *)&v13)
                                       + (float)(this->m_rootTransB.m_basis.m_el[1].mVec128.m128_f32[0]
                                               * v56.mVec128.m128_f32[1]))
                               + (float)(v57 * v56.mVec128.m128_f32[0]);
    v61 = *(float *)&v16;
    v62 = this->m_rootTransB.m_basis.m_el[1].mVec128.m128_f32[2];
    v21 = this->m_rootTransB.m_basis.m_el[2].mVec128.m128_f32[2] * *(float *)&v13;
    v22 = this->m_rootTransA.m_basis.m_el[0].mVec128.m128_f32[0];
    pointB.mVec128.m128_f32[1] = (float)((float)(v17 * *(float *)&v13) + (float)(v60 * v56.mVec128.m128_f32[1]))
                               + (float)(v59 * v56.mVec128.m128_f32[0]);
    v23 = this->m_rootTransA.m_basis.m_el[1].mVec128.m128_f32[2];
    v24 = this->m_rootTransA.m_basis.m_el[0].mVec128.m128_f32[2];
    pointB.mVec128.m128_i32[3] = 0;
    pointB.mVec128.m128_f32[2] = (float)(v21 + (float)(v62 * v56.mVec128.m128_f32[1]))
                               + (float)(v61 * v56.mVec128.m128_f32[0]);
    v25 = this->m_rootTransA.m_basis.m_el[0].mVec128.m128_i32[1];
    v56.mVec128 = (__m128)_mm_load_si128((const __m128i *)&pointB);
    v58 = this->m_rootTransA.m_basis.m_el[1].mVec128.m128_f32[0];
    v26 = this->m_rootTransA.m_basis.m_el[2].mVec128.m128_f32[0] * v19;
    v59 = *(float *)&v25;
    v60 = this->m_rootTransA.m_basis.m_el[1].mVec128.m128_f32[1];
    v27 = this->m_rootTransA.m_basis.m_el[2].mVec128.m128_f32[1];
    pointB.mVec128.m128_f32[0] = (float)(v26 + (float)(v22 * v18)) + (float)(v58 * v20);
    v62 = v23;
    v28 = (float)((float)(v27 * v19) + (float)(v59 * v18)) + (float)(v60 * v20);
    v29 = (float)((float)(v24 * v18) + (float)(v23 * v20))
        + (float)(this->m_rootTransA.m_basis.m_el[2].mVec128.m128_f32[2] * v19);
  }
  pointB.mVec128.m128_f32[1] = v28;
  pointB.mVec128.m128_u64[1] = LODWORD(v29);
  pointB.mVec128 = (__m128)_mm_load_si128((const __m128i *)&pointB);
  btManifoldPoint::btManifoldPoint(&v64, depth);
  v64.m_positionWorldOnA = (btVector3)_mm_load_si128(&v63);
  v64.m_positionWorldOnB = (btVector3)pointInWorld->mVec128;
  if ( v54 )
  {
    m_partId1 = this->m_partId1;
    m_partId0 = this->m_partId0;
    m_index1 = this->m_index1;
    m_body0 = this->m_body0;
    v64.m_index1 = this->m_index0;
    m_body1 = this->m_body1;
  }
  else
  {
    m_partId1 = this->m_partId0;
    m_partId0 = this->m_partId1;
    m_index1 = this->m_index0;
    m_body0 = this->m_body1;
    v64.m_index1 = this->m_index1;
    m_body1 = this->m_body0;
  }
  v64.m_partId0 = m_partId1;
  v64.m_partId1 = m_partId0;
  v64.m_index0 = m_index1;
  this->m_resultCallback->addSingleResult(
    this->m_resultCallback,
    &v64,
    m_body1,
    m_partId1,
    m_index1,
    m_body0,
    m_partId0,
    v64.m_index1);
}
