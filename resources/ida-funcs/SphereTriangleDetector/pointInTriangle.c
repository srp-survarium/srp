bool __userpurge SphereTriangleDetector::pointInTriangle@<al>(
        const btVector3 *normal@<edx>,
        btVector3 *p@<ecx>,
        SphereTriangleDetector *this,
        const btVector3 *vertices)
{
  float v4; // xmm6_4
  float v5; // xmm7_4
  btSphereShape *m_sphere; // xmm1_4
  btSphereShape *v7; // xmm3_4
  btTriangleShape *m_triangle; // xmm4_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm2_4
  float v13; // xmm5_4
  float v14; // xmm4_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm0_4
  float v20; // [esp+10h] [ebp-70h]
  float v21; // [esp+14h] [ebp-6Ch]
  float v22; // [esp+18h] [ebp-68h]
  float v23; // [esp+24h] [ebp-5Ch]
  float v24; // [esp+28h] [ebp-58h]
  float v25; // [esp+34h] [ebp-4Ch]
  float v26; // [esp+38h] [ebp-48h]
  float v27; // [esp+48h] [ebp-38h]
  float v28; // [esp+54h] [ebp-2Ch]
  float v29; // [esp+58h] [ebp-28h]
  float v30; // [esp+68h] [ebp-18h]

  v4 = *(float *)&this[1].__vftable - *(float *)&this->__vftable;
  v5 = *(float *)&this[1].m_sphere - *(float *)&this->m_sphere;
  m_sphere = this[2].m_sphere;
  v20 = *(float *)&this[2].__vftable - *(float *)&this[1].__vftable;
  v21 = *(float *)&m_sphere - *(float *)&this[1].m_sphere;
  v7 = this->m_sphere;
  v22 = *(float *)&this[2].m_triangle - *(float *)&this[1].m_triangle;
  m_triangle = this->m_triangle;
  v23 = *(float *)&v7 - *(float *)&m_sphere;
  v24 = *(float *)&m_triangle - *(float *)&this[2].m_triangle;
  v9 = p->mVec128.m128_f32[1];
  v25 = v9 - *(float *)&v7;
  v10 = p->mVec128.m128_f32[2];
  v26 = v10 - *(float *)&m_triangle;
  v27 = v10 - *(float *)&this[1].m_triangle;
  v11 = normal->mVec128.m128_f32[2];
  v29 = v10 - *(float *)&this[2].m_triangle;
  v12 = normal->mVec128.m128_f32[1];
  v30 = *(float *)&this[1].m_triangle - *(float *)&m_triangle;
  v13 = normal->mVec128.m128_f32[0];
  v14 = (float)(v11 * v5) - (float)(v12 * v30);
  v28 = v9 - *(float *)&this[2].m_sphere;
  v15 = (float)((float)(v12 * v4) - (float)(normal->mVec128.m128_f32[0] * v5)) * v26;
  v16 = (float)((float)((float)((float)(v12 * v20) - (float)(v13 * v21)) * v27)
              + (float)((float)((float)(v13 * v22) - (float)(v11 * v20)) * (float)(v9 - *(float *)&this[1].m_sphere)))
      + (float)((float)((float)(v11 * v21) - (float)(v12 * v22))
              * (float)(p->mVec128.m128_f32[0] - *(float *)&this[1].__vftable));
  v17 = (float)((float)((float)((float)(v12 * (float)(*(float *)&this->__vftable - *(float *)&this[2].__vftable))
                              - (float)(v13 * v23))
                      * v29)
              + (float)((float)((float)(v13 * v24)
                              - (float)(v11 * (float)(*(float *)&this->__vftable - *(float *)&this[2].__vftable)))
                      * v28))
      + (float)((float)((float)(v11 * v23) - (float)(v12 * v24))
              * (float)(p->mVec128.m128_f32[0] - *(float *)&this[2].__vftable));
  v18 = (float)(v15 + (float)((float)((float)(normal->mVec128.m128_f32[0] * v30) - (float)(v11 * v4)) * v25))
      + (float)(v14 * (float)(p->mVec128.m128_f32[0] - *(float *)&this->__vftable));
  return v18 > 0.0 && v16 > 0.0 && v17 > 0.0 || v18 <= 0.0 && v16 <= 0.0 && v17 <= 0.0;
}
