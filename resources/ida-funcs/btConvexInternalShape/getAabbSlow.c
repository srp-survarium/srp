void __thiscall btConvexInternalShape::getAabbSlow(
        btConvexInternalShape *this,
        const btTransform *trans,
        btVector3 *minAabb,
        btVector3 *maxAabb)
{
  int i; // edi
  float v6; // xmm4_4
  float v7; // xmm3_4
  float v8; // xmm5_4
  btVector3 *(__thiscall *localGetSupportingVertex)(struct btConvexInternalShape *, btVector3 *, const btVector3 *); // edx
  float v10; // xmm4_4
  float v11; // xmm5_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm4_4
  _DWORD *v15; // eax
  btConvexInternalShape_vtbl *v16; // edx
  float v17; // xmm4_4
  float v18; // xmm2_4
  float v19; // xmm5_4
  btVector3 *(__thiscall *v20)(struct btConvexInternalShape *, btVector3 *, const btVector3 *); // edx
  float v21; // xmm4_4
  float v22; // xmm5_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float *v25; // eax
  float v26; // xmm0_4
  float v27; // xmm2_4
  float v28; // xmm1_4
  int v29; // xmm3_4
  float v30; // [esp+180h] [ebp-78h]
  __int64 v31; // [esp+188h] [ebp-70h] BYREF
  float v32; // [esp+190h] [ebp-68h]
  __m128i v33; // [esp+198h] [ebp-60h]
  _DWORD v34[4]; // [esp+1A8h] [ebp-50h] BYREF
  _DWORD v35[2]; // [esp+1B8h] [ebp-40h] BYREF
  __int64 v36; // [esp+1C0h] [ebp-38h]
  __m128i v37; // [esp+1C8h] [ebp-30h] BYREF
  float v38; // [esp+1D8h] [ebp-20h] BYREF
  float v39; // [esp+1DCh] [ebp-1Ch]
  float v40[2]; // [esp+1E0h] [ebp-18h]
  btVector3 v41; // [esp+1E8h] [ebp-10h] BYREF

  v30 = this->getMargin(this);
  v37.m128i_i32[3] = 0;
  for ( i = 0; i < 3; ++i )
  {
    v6 = trans->m_basis.m_el[0].mVec128.m128_f32[0];
    v7 = trans->m_basis.m_el[2].mVec128.m128_f32[0];
    v8 = trans->m_basis.m_el[1].mVec128.m128_f32[0];
    localGetSupportingVertex = this->localGetSupportingVertex;
    v31 = 0;
    v32 = 0.0;
    *(_DWORD *)((char *)&v31 + i * 4) = clear_value;
    v10 = (float)((float)(v6 * *(float *)&v31) + (float)(v7 * v32)) + (float)(v8 * *((float *)&v31 + 1));
    v11 = trans->m_basis.m_el[0].mVec128.m128_f32[1];
    *(float *)v34 = v10;
    v12 = *(float *)&v31 * trans->m_basis.m_el[0].mVec128.m128_f32[2];
    v13 = v32 * trans->m_basis.m_el[2].mVec128.m128_f32[2];
    *(float *)&v34[1] = (float)((float)(trans->m_basis.m_el[1].mVec128.m128_f32[1] * *((float *)&v31 + 1))
                              + (float)(v11 * *(float *)&v31))
                      + (float)(trans->m_basis.m_el[2].mVec128.m128_f32[1] * v32);
    *(float *)&v34[2] = (float)((float)(trans->m_basis.m_el[1].mVec128.m128_f32[2] * *((float *)&v31 + 1)) + v12) + v13;
    v34[3] = 0;
    localGetSupportingVertex(this, (btVector3 *)&v38, (const btVector3 *)v34);
    v14 = trans->m_basis.m_el[1].mVec128.m128_f32[2];
    *(float *)v33.m128i_i32 = (float)((float)((float)(trans->m_basis.m_el[0].mVec128.m128_f32[1] * v39)
                                            + (float)(trans->m_basis.m_el[0].mVec128.m128_f32[0] * v38))
                                    + (float)(v40[0] * trans->m_basis.m_el[0].mVec128.m128_f32[2]))
                            + trans->m_origin.mVec128.m128_f32[0];
    *(float *)&v33.m128i_i32[1] = (float)((float)((float)(trans->m_basis.m_el[1].mVec128.m128_f32[1] * v39)
                                                + (float)(v14 * v40[0]))
                                        + (float)(trans->m_basis.m_el[1].mVec128.m128_f32[0] * v38))
                                + trans->m_origin.mVec128.m128_f32[1];
    *(float *)&v33.m128i_i32[2] = (float)((float)((float)(trans->m_basis.m_el[2].mVec128.m128_f32[1] * v39)
                                                + (float)(trans->m_basis.m_el[2].mVec128.m128_f32[2] * v40[0]))
                                        + (float)(trans->m_basis.m_el[2].mVec128.m128_f32[0] * v38))
                                + trans->m_origin.mVec128.m128_f32[2];
    v33.m128i_i32[3] = 0;
    v15 = (_DWORD *)((char *)&v31 + i * 4);
    v16 = this->__vftable;
    *(float *)((char *)v15 + (char *)maxAabb - (char *)&v31) = *(float *)&v33.m128i_i32[i] + v30;
    v17 = trans->m_basis.m_el[0].mVec128.m128_f32[0];
    v18 = trans->m_basis.m_el[2].mVec128.m128_f32[0];
    v19 = trans->m_basis.m_el[1].mVec128.m128_f32[0];
    v20 = v16->localGetSupportingVertex;
    *v15 = -1082130432;
    v21 = (float)((float)(v17 * *(float *)&v31) + (float)(v18 * v32)) + (float)(v19 * *((float *)&v31 + 1));
    v22 = trans->m_basis.m_el[0].mVec128.m128_f32[1];
    *(float *)v35 = v21;
    v23 = *(float *)&v31 * trans->m_basis.m_el[0].mVec128.m128_f32[2];
    v24 = v32 * trans->m_basis.m_el[2].mVec128.m128_f32[2];
    *(float *)&v35[1] = (float)((float)(trans->m_basis.m_el[1].mVec128.m128_f32[1] * *((float *)&v31 + 1))
                              + (float)(v22 * *(float *)&v31))
                      + (float)(trans->m_basis.m_el[2].mVec128.m128_f32[1] * v32);
    v36 = COERCE_UNSIGNED_INT((float)((float)(trans->m_basis.m_el[1].mVec128.m128_f32[2] * *((float *)&v31 + 1)) + v23) + v24);
    v25 = (float *)v20(this, &v41, (const btVector3 *)v35);
    v26 = *v25;
    v27 = v25[1];
    v28 = v25[2];
    *(float *)v37.m128i_i32 = (float)((float)((float)(*v25 * trans->m_basis.m_el[0].mVec128.m128_f32[0])
                                            + (float)(v27 * trans->m_basis.m_el[0].mVec128.m128_f32[1]))
                                    + (float)(v28 * trans->m_basis.m_el[0].mVec128.m128_f32[2]))
                            + trans->m_origin.mVec128.m128_f32[0];
    *(float *)&v29 = (float)((float)((float)(v27 * trans->m_basis.m_el[1].mVec128.m128_f32[1])
                                   + (float)(v28 * trans->m_basis.m_el[1].mVec128.m128_f32[2]))
                           + (float)(v26 * trans->m_basis.m_el[1].mVec128.m128_f32[0]))
                   + trans->m_origin.mVec128.m128_f32[1];
    *(float *)&v37.m128i_i32[2] = (float)((float)((float)(v26 * trans->m_basis.m_el[2].mVec128.m128_f32[0])
                                                + (float)(v27 * trans->m_basis.m_el[2].mVec128.m128_f32[1]))
                                        + (float)(v28 * trans->m_basis.m_el[2].mVec128.m128_f32[2]))
                                + trans->m_origin.mVec128.m128_f32[2];
    v37.m128i_i32[1] = v29;
    v33 = _mm_load_si128(&v37);
    minAabb->mVec128.m128_f32[i] = *(float *)&v33.m128i_i32[i] - v30;
  }
}
