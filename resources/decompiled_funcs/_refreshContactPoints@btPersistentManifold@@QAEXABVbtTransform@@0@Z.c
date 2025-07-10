void __fastcall btPersistentManifold::refreshContactPoints(
        const btTransform *trB,
        const btTransform *trA,
        btPersistentManifold *this)
{
  int v3; // esi
  int *v4; // eax
  float v5; // xmm0_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm2_4
  unsigned int v10; // xmm3_4
  float v11; // xmm0_4
  float v12; // xmm3_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  int v15; // edi
  float *v16; // esi
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm5_4
  float v20; // xmm0_4
  __int64 v21; // [esp+10h] [ebp-20h]
  __int64 v22; // [esp+18h] [ebp-18h]
  __int64 v23; // [esp+20h] [ebp-10h]

  v3 = this->m_cachedPoints - 1;
  if ( v3 >= 0 )
  {
    HIDWORD(v22) = 0;
    v4 = &this->m_pointCache[v3].m_localPointB.mVec128.m128_i32[1];
    do
    {
      v5 = *((float *)v4 - 5);
      v6 = *((float *)v4 - 4);
      v7 = *((float *)v4 - 3);
      *(float *)&v21 = (float)((float)((float)(v5 * trA->m_basis.m_el[0].mVec128.m128_f32[0])
                                     + (float)(trA->m_basis.m_el[0].mVec128.m128_f32[1] * v6))
                             + (float)(trA->m_basis.m_el[0].mVec128.m128_f32[2] * v7))
                     + trA->m_origin.mVec128.m128_f32[0];
      *((float *)&v21 + 1) = (float)((float)((float)(v5 * trA->m_basis.m_el[1].mVec128.m128_f32[0])
                                           + (float)(trA->m_basis.m_el[1].mVec128.m128_f32[1] * v6))
                                   + (float)(trA->m_basis.m_el[1].mVec128.m128_f32[2] * v7))
                           + trA->m_origin.mVec128.m128_f32[1];
      *(float *)&v22 = (float)((float)((float)(v5 * trA->m_basis.m_el[2].mVec128.m128_f32[0])
                                     + (float)(v6 * trA->m_basis.m_el[2].mVec128.m128_f32[1]))
                             + (float)(v7 * trA->m_basis.m_el[2].mVec128.m128_f32[2]))
                     + trA->m_origin.mVec128.m128_f32[2];
      *(_QWORD *)(v4 + 7) = v21;
      *(_QWORD *)(v4 + 9) = v22;
      v8 = *((float *)v4 + 1);
      v9 = *((float *)v4 - 1);
      *(float *)&v23 = (float)((float)((float)(trB->m_basis.m_el[0].mVec128.m128_f32[2] * v8)
                                     + (float)(v9 * trB->m_basis.m_el[0].mVec128.m128_f32[0]))
                             + (float)(trB->m_basis.m_el[0].mVec128.m128_f32[1] * *(float *)v4))
                     + trB->m_origin.mVec128.m128_f32[0];
      *((float *)&v23 + 1) = (float)((float)((float)(v9 * trB->m_basis.m_el[1].mVec128.m128_f32[0])
                                           + (float)(v8 * trB->m_basis.m_el[1].mVec128.m128_f32[2]))
                                   + (float)(*(float *)v4 * trB->m_basis.m_el[1].mVec128.m128_f32[1]))
                           + trB->m_origin.mVec128.m128_f32[1];
      *(float *)&v10 = (float)((float)((float)(trB->m_basis.m_el[2].mVec128.m128_f32[2] * v8)
                                     + (float)(trB->m_basis.m_el[2].mVec128.m128_f32[1] * *(float *)v4))
                             + (float)(trB->m_basis.m_el[2].mVec128.m128_f32[0] * v9))
                     + trB->m_origin.mVec128.m128_f32[2];
      *(_QWORD *)(v4 + 3) = v23;
      *(_QWORD *)(v4 + 5) = v10;
      v11 = *((float *)v4 + 7) - *((float *)v4 + 3);
      v12 = *((float *)v4 + 13) * (float)(*((float *)v4 + 9) - *((float *)v4 + 5));
      v13 = *((float *)v4 + 12) * (float)(*((float *)v4 + 8) - *((float *)v4 + 4));
      v14 = *((float *)v4 + 11);
      ++v4[31];
      *((float *)v4 + 15) = (float)(v12 + v13) + (float)(v14 * v11);
      --v3;
      v4 -= 72;
    }
    while ( v3 >= 0 );
  }
  v15 = this->m_cachedPoints - 1;
  if ( v15 >= 0 )
  {
    v16 = &this->m_pointCache[v15].m_normalWorldOnB.mVec128.m128_f32[2];
    do
    {
      v17 = v16[2];
      if ( this->m_contactBreakingThreshold < v17
        || (v18 = *(v16 - 9) - (float)(*(v16 - 5) - (float)(*(v16 - 1) * v17)),
            v19 = *(v16 - 4) - (float)(v17 * *v16),
            v20 = *(v16 - 10) - (float)(*(v16 - 6) - (float)(*(v16 - 2) * v17)),
            (float)((float)((float)((float)(*(v16 - 8) - v19) * (float)(*(v16 - 8) - v19)) + (float)(v18 * v18))
                  + (float)(v20 * v20)) > (float)(this->m_contactBreakingThreshold * this->m_contactBreakingThreshold)) )
      {
        btPersistentManifold::removeContactPoint(v15, this);
      }
      else if ( gContactProcessedCallback )
      {
        gContactProcessedCallback((btManifoldPoint *)(v16 - 18), this->m_body0, this->m_body1);
      }
      --v15;
      v16 -= 72;
    }
    while ( v15 >= 0 );
  }
}
