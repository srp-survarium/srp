int __userpurge btVoronoiSimplexSolver::pointOutsideOfPlane@<eax>(
        const btVector3 *p@<edi>,
        const btVector3 *b@<esi>,
        const btVector3 *c@<edx>,
        const btVector3 *d@<ecx>,
        btVoronoiSimplexSolver *this,
        const btVector3 *a)
{
  float v6; // xmm6_4
  float v7; // xmm7_4
  float v8; // xmm3_4
  float v9; // xmm2_4
  float v10; // xmm4_4
  float v11; // xmm1_4
  float v12; // xmm5_4
  float v13; // xmm7_4
  float v14; // xmm6_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v18; // [esp+4h] [ebp-Ch]
  float v19; // [esp+8h] [ebp-8h]

  v6 = *((float *)&this->m_numVertices + 1);
  v7 = *((float *)&this->m_numVertices + 2);
  v8 = c->mVec128.m128_f32[0] - *(float *)&this->m_numVertices;
  v9 = b->mVec128.m128_f32[1] - v6;
  v10 = c->mVec128.m128_f32[1] - v6;
  v11 = b->mVec128.m128_f32[2] - v7;
  v12 = c->mVec128.m128_f32[2] - v7;
  v13 = (float)(v9 * v12) - (float)(v11 * v10);
  v14 = b->mVec128.m128_f32[0] - *(float *)&this->m_numVertices;
  v18 = (float)(v11 * v8) - (float)(v14 * v12);
  v15 = *((float *)&this->m_numVertices + 1);
  v19 = (float)(v14 * v10) - (float)(v9 * v8);
  v16 = (float)((float)((float)(d->mVec128.m128_f32[2] - *((float *)&this->m_numVertices + 2)) * v19)
              + (float)((float)(d->mVec128.m128_f32[0] - *(float *)&this->m_numVertices) * v13))
      + (float)((float)(d->mVec128.m128_f32[1] - v15) * v18);
  if ( (float)(v16 * v16) >= 0.0000000099999999 )
    return (float)((float)((float)((float)((float)(p->mVec128.m128_f32[2] - *((float *)&this->m_numVertices + 2)) * v19)
                                 + (float)((float)(p->mVec128.m128_f32[0] - *(float *)&this->m_numVertices) * v13))
                         + (float)((float)(p->mVec128.m128_f32[1] - v15) * v18))
                 * v16) < 0.0;
  else
    return -1;
}
