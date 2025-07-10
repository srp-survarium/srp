void __userpurge btGImpactCollisionAlgorithm::gimpact_vs_concave(
        btGImpactCollisionAlgorithm *this@<eax>,
        btCollisionObject *body0@<esi>,
        btConcaveShape *shape1@<edi>,
        bool swapped@<dl>,
        btCollisionObject *body1,
        btGImpactShapeInterface *shape0)
{
  btConcaveShape_vtbl *v6; // eax
  float (__thiscall *getMargin)(struct btConcaveShape *); // edx
  float *v8; // eax
  float v9; // xmm4_4
  float v10; // xmm5_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm3_4
  float v14; // xmm1_4
  float v15; // xmm7_4
  int v16; // xmm6_4
  float v17; // xmm7_4
  unsigned int v18; // xmm6_4
  float v19; // xmm3_4
  float v20; // xmm5_4
  float v21; // xmm4_4
  unsigned int v22; // xmm3_4
  unsigned int v23; // xmm4_4
  unsigned int v24; // xmm5_4
  float v25; // xmm6_4
  btGImpactShapeInterface_vtbl *v26; // eax
  void (__thiscall *getAabb)(struct btGImpactShapeInterface *, const btTransform *, btVector3 *, btVector3 *); // edx
  unsigned __int64 v28; // [esp+1BCh] [ebp-E0h]
  unsigned int v29; // [esp+1C4h] [ebp-D8h]
  unsigned int v30; // [esp+1C8h] [ebp-D4h]
  __m128i v31; // [esp+1CCh] [ebp-D0h] BYREF
  _DWORD v32[5]; // [esp+1E0h] [ebp-BCh] BYREF
  bool v33; // [esp+1F4h] [ebp-A8h]
  float v34; // [esp+1F8h] [ebp-A4h]
  btTransform v35; // [esp+1FCh] [ebp-A0h] BYREF
  btVector3 v36; // [esp+23Ch] [ebp-60h] BYREF
  btVector3 v37; // [esp+24Ch] [ebp-50h] BYREF
  _OWORD v38[4]; // [esp+25Ch] [ebp-40h] BYREF

  v32[1] = this;
  v6 = shape1->__vftable;
  v32[3] = body1;
  v33 = swapped;
  getMargin = v6->getMargin;
  v32[0] = &btGImpactTriangleCallback::`vftable';
  v32[2] = body0;
  v32[4] = shape0;
  v34 = getMargin(shape1);
  v8 = (float *)btTransform::inverse(&body1->m_worldTransform, &v35);
  v9 = body0->m_worldTransform.m_origin.mVec128.m128_f32[1];
  v10 = body0->m_worldTransform.m_origin.mVec128.m128_f32[0];
  v11 = v8[1];
  v12 = *v8;
  v13 = body0->m_worldTransform.m_origin.mVec128.m128_f32[2];
  v14 = v8[2];
  v15 = v8[6];
  *(float *)v31.m128i_i32 = (float)((float)((float)(*v8 * v10) + (float)(v11 * v9)) + (float)(v14 * v13)) + v8[12];
  *(float *)&v16 = (float)((float)((float)(v8[5] * v9) + (float)(v15 * v13)) + (float)(v8[4] * v10)) + v8[13];
  v17 = body0->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1] * v8[8];
  v31.m128i_i32[1] = v16;
  *(float *)&v18 = (float)((float)((float)(v8[9] * v9) + (float)(v8[10] * v13)) + (float)(v8[8] * v10)) + v8[14];
  v19 = v8[9] * body0->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2];
  v20 = v8[10] * body0->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2];
  v21 = v8[9];
  v31.m128i_i64[1] = v18;
  *(float *)&v22 = (float)(v19 + v20) + (float)(body0->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2] * v8[8]);
  *(float *)&v23 = (float)((float)(v21 * body0->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1])
                         + (float)(v8[10] * body0->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1]))
                 + v17;
  *(float *)&v24 = (float)((float)(v8[9] * body0->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0])
                         + (float)(v8[10] * body0->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0]))
                 + (float)(body0->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0] * v8[8]);
  *(float *)&v30 = (float)((float)(v8[5] * body0->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2])
                         + (float)(v8[6] * body0->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2]))
                 + (float)(v8[4] * body0->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2]);
  *((float *)&v28 + 1) = (float)((float)(v8[5] * body0->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1])
                               + (float)(v8[6] * body0->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1]))
                       + (float)(v8[4] * body0->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1]);
  *(float *)&v28 = (float)((float)(v8[5] * body0->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0])
                         + (float)(v8[6] * body0->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0]))
                 + (float)(body0->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0] * v8[4]);
  *(float *)&v29 = (float)((float)(v12 * body0->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2])
                         + (float)(v11 * body0->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2]))
                 + (float)(v14 * body0->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2]);
  v25 = (float)((float)(v12 * body0->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1])
              + (float)(v11 * body0->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1]))
      + (float)(v14 * body0->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1]);
  v26 = shape0->__vftable;
  v35.m_basis.m_el[0].mVec128.m128_f32[0] = (float)((float)(v12
                                                          * body0->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0])
                                                  + (float)(v11
                                                          * body0->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0]))
                                          + (float)(v14 * body0->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0]);
  v35.m_basis.m_el[0].mVec128.m128_u64[1] = v29;
  v35.m_basis.m_el[1].mVec128.m128_u64[0] = v28;
  v35.m_basis.m_el[0].mVec128.m128_f32[1] = v25;
  v38[0] = _mm_load_si128((const __m128i *)&v35);
  v35.m_basis.m_el[1].mVec128.m128_u64[1] = v30;
  v38[1] = _mm_load_si128((const __m128i *)&v35.m_basis.m_el[1]);
  getAabb = v26->getAabb;
  v35.m_basis.m_el[2].mVec128.m128_u64[0] = __PAIR64__(v23, v24);
  v35.m_basis.m_el[2].mVec128.m128_u64[1] = v22;
  v38[2] = _mm_load_si128((const __m128i *)&v35.m_basis.m_el[2]);
  v38[3] = _mm_load_si128(&v31);
  getAabb(shape0, (const btTransform *)v38, &v37, &v36);
  shape1->processAllTriangles(shape1, (btTriangleCallback *)v32, &v37, &v36);
}
