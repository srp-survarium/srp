void __fastcall btPersistentManifold::refreshContactPoints(
        btPersistentManifold *trB,
        const btTransform *trA,
        btPersistentManifold *this)
{
  btPersistentManifold *v3; // edi
  int v4; // ebx
  int *v5; // eax
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  float v12; // xmm3_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  int v15; // ebx
  float *v16; // esi
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm2_4
  float v21; // xmm1_4
  float v22; // [esp+14h] [ebp-1Ch]
  float v23; // [esp+18h] [ebp-18h]
  float v24; // [esp+24h] [ebp-Ch]
  float v25; // [esp+28h] [ebp-8h]

  v3 = this;
  v4 = this->m_cachedPoints - 1;
  if ( v4 >= 0 )
  {
    v5 = &this->m_pointCache[v4].m_localPointB.mVec128.m128_i32[1];
    do
    {
      v6 = *((float *)v5 - 5);
      v7 = *((float *)v5 - 3);
      v8 = *((float *)v5 - 4);
      v22 = (float)((float)((float)(v6 * trA->m_basis.m_el[1].mVec128.m128_f32[0])
                          + (float)(trA->m_basis.m_el[1].mVec128.m128_f32[1] * v8))
                  + (float)(trA->m_basis.m_el[1].mVec128.m128_f32[2] * v7))
          + trA->m_origin.mVec128.m128_f32[1];
      v23 = (float)((float)((float)(v6 * trA->m_basis.m_el[2].mVec128.m128_f32[0])
                          + (float)(v8 * trA->m_basis.m_el[2].mVec128.m128_f32[1]))
                  + (float)(v7 * trA->m_basis.m_el[2].mVec128.m128_f32[2]))
          + trA->m_origin.mVec128.m128_f32[2];
      *((float *)v5 + 7) = (float)((float)((float)(trA->m_basis.m_el[0].mVec128.m128_f32[2] * v7)
                                         + (float)(v6 * trA->m_basis.m_el[0].mVec128.m128_f32[0]))
                                 + (float)(trA->m_basis.m_el[0].mVec128.m128_f32[1] * v8))
                         + trA->m_origin.mVec128.m128_f32[0];
      *((float *)v5 + 8) = v22;
      *((float *)v5 + 9) = v23;
      v5[10] = 0;
      v9 = *((float *)v5 - 1);
      v10 = *((float *)v5 + 1);
      v24 = (float)((float)((float)(v9 * trB->m_pointCache[0].m_localPointA.mVec128.m128_f32[0])
                          + (float)(v10 * trB->m_pointCache[0].m_localPointA.mVec128.m128_f32[2]))
                  + (float)(*(float *)v5 * trB->m_pointCache[0].m_localPointA.mVec128.m128_f32[1]))
          + trB->m_pointCache[0].m_positionWorldOnB.mVec128.m128_f32[1];
      v25 = (float)((float)((float)(trB->m_pointCache[0].m_localPointB.mVec128.m128_f32[2] * v10)
                          + (float)(trB->m_pointCache[0].m_localPointB.mVec128.m128_f32[0] * v9))
                  + (float)(trB->m_pointCache[0].m_localPointB.mVec128.m128_f32[1] * *(float *)v5))
          + trB->m_pointCache[0].m_positionWorldOnB.mVec128.m128_f32[2];
      *((float *)v5 + 3) = (float)((float)((float)(*((float *)&trB->btTypedObject + 2) * v10)
                                         + (float)(v9 * *(float *)&trB->m_objectType))
                                 + (float)(*((float *)&trB->btTypedObject + 1) * *(float *)v5))
                         + trB->m_pointCache[0].m_positionWorldOnB.mVec128.m128_f32[0];
      *((float *)v5 + 4) = v24;
      *((float *)v5 + 5) = v25;
      v5[6] = 0;
      v11 = *((float *)v5 + 7) - *((float *)v5 + 3);
      v12 = *((float *)v5 + 13) * (float)(*((float *)v5 + 9) - *((float *)v5 + 5));
      v13 = *((float *)v5 + 12) * (float)(*((float *)v5 + 8) - *((float *)v5 + 4));
      v14 = *((float *)v5 + 11);
      ++v5[31];
      *((float *)v5 + 15) = (float)(v12 + v13) + (float)(v14 * v11);
      --v4;
      v5 -= 72;
    }
    while ( v4 >= 0 );
    v3 = this;
  }
  v15 = v3->m_cachedPoints - 1;
  if ( v15 >= 0 )
  {
    v16 = &v3->m_pointCache[v15].m_normalWorldOnB.mVec128.m128_f32[2];
    do
    {
      v17 = v16[2];
      if ( v3->m_contactBreakingThreshold >= v17
        && (v18 = *(v16 - 1) * v17,
            v19 = *(v16 - 10) - (float)(*(v16 - 6) - (float)(*(v16 - 2) * v17)),
            v20 = *(v16 - 8) - (float)(*(v16 - 4) - (float)(v17 * *v16)),
            v21 = *(v16 - 9) - (float)(*(v16 - 5) - v18),
            (float)((float)((float)(v20 * v20) + (float)(v21 * v21)) + (float)(v19 * v19)) <= (float)(v3->m_contactBreakingThreshold * v3->m_contactBreakingThreshold)) )
      {
        if ( gContactProcessedCallback )
          gContactProcessedCallback((btManifoldPoint *)(v16 - 18), v3->m_body0, v3->m_body1);
      }
      else
      {
        btPersistentManifold::removeContactPoint(trB, (int)v3, v15);
      }
      --v15;
      v16 -= 72;
    }
    while ( v15 >= 0 );
  }
}
