int __userpurge btVoronoiSimplexSolver::pointOutsideOfPlane@<eax>(
        const btVector3 *p@<edi>,
        const btVector3 *b@<esi>,
        const btVector3 *c@<edx>,
        const btVector3 *d@<ecx>,
        btVoronoiSimplexSolver *this,
        const btVector3 *a)
{
  float v6; // xmm1_4
  float v7; // xmm5_4
  float v8; // xmm2_4
  float v9; // xmm6_4
  float v10; // xmm1_4
  float v11; // xmm3_4
  float v12; // xmm5_4
  float v13; // xmm7_4
  float v14; // xmm6_4
  float v15; // xmm0_4
  float v16; // xmm2_4
  float v17; // xmm5_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v22; // [esp+24h] [ebp-1Ch]
  float v23; // [esp+28h] [ebp-18h]
  float v24; // [esp+34h] [ebp-Ch]
  float v25; // [esp+38h] [ebp-8h]

  v6 = *((float *)&this->m_numVertices + 1);
  v7 = *((float *)&this->m_numVertices + 2);
  v8 = b->mVec128.m128_f32[1] - v6;
  v9 = c->mVec128.m128_f32[1] - v6;
  v10 = b->mVec128.m128_f32[2] - v7;
  v11 = c->mVec128.m128_f32[0] - *(float *)&this->m_numVertices;
  v25 = c->mVec128.m128_f32[2] - v7;
  v12 = v8 * v25;
  v13 = v10 * v9;
  v24 = v9;
  v14 = b->mVec128.m128_f32[0] - *(float *)&this->m_numVertices;
  v15 = (float)(v14 * v24) - (float)(v8 * v11);
  v16 = *((float *)&this->m_numVertices + 1);
  v17 = v12 - v13;
  v23 = v15;
  v18 = p->mVec128.m128_f32[1] - v16;
  v22 = (float)(v10 * v11) - (float)(v14 * v25);
  v19 = *((float *)&this->m_numVertices + 2);
  v20 = (float)((float)((float)(d->mVec128.m128_f32[2] - v19) * v23)
              + (float)((float)(d->mVec128.m128_f32[0] - *(float *)&this->m_numVertices) * v17))
      + (float)((float)(d->mVec128.m128_f32[1] - v16) * v22);
  if ( (float)(v20 * v20) >= 0.0000000099999999 )
    return (float)((float)((float)((float)((float)(p->mVec128.m128_f32[2] - v19) * v23)
                                 + (float)((float)(p->mVec128.m128_f32[0] - *(float *)&this->m_numVertices) * v17))
                         + (float)(v18 * v22))
                 * v20) < 0.0;
  else
    return -1;
}
