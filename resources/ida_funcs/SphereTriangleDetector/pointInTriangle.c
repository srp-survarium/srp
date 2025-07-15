bool __userpurge SphereTriangleDetector::pointInTriangle@<al>(
        const btVector3 *normal@<edx>,
        btVector3 *p@<ecx>,
        SphereTriangleDetector *this,
        const btVector3 *vertices)
{
  btSphereShape *m_sphere; // xmm2_4
  btTriangleShape *m_triangle; // xmm5_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm1_4
  float v9; // xmm6_4
  float v10; // xmm7_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm5_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm4_4
  float v18; // xmm0_4
  float v19; // xmm3_4
  float v21; // [esp+234h] [ebp-6Ch]
  float v22; // [esp+238h] [ebp-68h]
  float v23; // [esp+240h] [ebp-60h]
  float v24; // [esp+244h] [ebp-5Ch]
  float v25; // [esp+248h] [ebp-58h]
  float v26; // [esp+258h] [ebp-48h]
  float v27; // [esp+264h] [ebp-3Ch]
  float v28; // [esp+268h] [ebp-38h]
  float v29; // [esp+274h] [ebp-2Ch]
  float v30; // [esp+278h] [ebp-28h]
  float v31; // [esp+294h] [ebp-Ch]

  m_sphere = this->m_sphere;
  m_triangle = this->m_triangle;
  v23 = *(float *)&this[2].__vftable - *(float *)&this[1].__vftable;
  v24 = *(float *)&this[2].m_sphere - *(float *)&this[1].m_sphere;
  v25 = *(float *)&this[2].m_triangle - *(float *)&this[1].m_triangle;
  v21 = *(float *)&m_sphere - *(float *)&this[2].m_sphere;
  v22 = *(float *)&m_triangle - *(float *)&this[2].m_triangle;
  v6 = *(float *)&this[1].m_triangle - *(float *)&m_triangle;
  v7 = *(float *)&this[1].__vftable - *(float *)&this->__vftable;
  v8 = p->mVec128.m128_f32[1];
  v9 = *(float *)&this[1].m_sphere - *(float *)&m_sphere;
  v10 = v8 - *(float *)&m_sphere;
  v11 = p->mVec128.m128_f32[2];
  v26 = v11 - *(float *)&m_triangle;
  v27 = v8 - *(float *)&this[1].m_sphere;
  v28 = v11 - *(float *)&this[1].m_triangle;
  v12 = normal->mVec128.m128_f32[1];
  v30 = v11 - *(float *)&this[2].m_triangle;
  v29 = v8 - *(float *)&this[2].m_sphere;
  v13 = normal->mVec128.m128_f32[2];
  v14 = (float)(v13 * v9) - (float)(v12 * v6);
  v15 = normal->mVec128.m128_f32[0];
  v31 = (float)(normal->mVec128.m128_f32[0] * v6) - (float)(v13 * v7);
  v16 = (float)(v12 * v7) - (float)(normal->mVec128.m128_f32[0] * v9);
  v17 = (float)((float)((float)((float)(v12 * v23) - (float)(v15 * v24)) * v28)
              + (float)((float)((float)(v15 * v25) - (float)(v13 * v23)) * v27))
      + (float)((float)((float)(v13 * v24) - (float)(v12 * v25))
              * (float)(p->mVec128.m128_f32[0] - *(float *)&this[1].__vftable));
  v18 = (float)((float)((float)((float)(v12 * (float)(*(float *)&this->__vftable - *(float *)&this[2].__vftable))
                              - (float)(v15 * v21))
                      * v30)
              + (float)((float)((float)(v15 * v22)
                              - (float)(v13 * (float)(*(float *)&this->__vftable - *(float *)&this[2].__vftable)))
                      * v29))
      + (float)((float)((float)(v13 * v21) - (float)(v12 * v22))
              * (float)(p->mVec128.m128_f32[0] - *(float *)&this[2].__vftable));
  v19 = (float)((float)(v16 * v26) + (float)(v31 * v10))
      + (float)(v14 * (float)(p->mVec128.m128_f32[0] - *(float *)&this->__vftable));
  return v19 > 0.0 && v17 > 0.0 && v18 > 0.0 || v19 <= 0.0 && v17 <= 0.0 && v18 <= 0.0;
}
