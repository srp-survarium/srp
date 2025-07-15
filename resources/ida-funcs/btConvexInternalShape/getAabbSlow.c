void __thiscall btConvexInternalShape::getAabbSlow(
        btConvexInternalShape *this,
        const btTransform *trans,
        btVector3 *minAabb,
        btVector3 *maxAabb)
{
  btConvexInternalShape *v4; // edi
  float v5; // xmm3_4
  float v6; // xmm4_4
  btConvexInternalShape_vtbl *v7; // eax
  float *v8; // esi
  float v9; // xmm3_4
  float v10; // xmm4_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  btConvexInternalShape_vtbl *v16; // eax
  float v17; // xmm4_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float *v20; // eax
  float v21; // xmm2_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm3_4
  float v25; // xmm4_4
  int v26; // [esp+10h] [ebp-80h]
  float v27; // [esp+14h] [ebp-7Ch]
  float v29; // [esp+20h] [ebp-70h] BYREF
  float v30; // [esp+24h] [ebp-6Ch]
  float v31; // [esp+28h] [ebp-68h]
  float v32; // [esp+30h] [ebp-60h] BYREF
  float v33; // [esp+34h] [ebp-5Ch]
  float v34; // [esp+38h] [ebp-58h]
  float v35; // [esp+40h] [ebp-50h]
  float v36; // [esp+44h] [ebp-4Ch]
  float v37; // [esp+48h] [ebp-48h]
  int v38; // [esp+4Ch] [ebp-44h]
  _DWORD v39[4]; // [esp+50h] [ebp-40h] BYREF
  float v40[4]; // [esp+60h] [ebp-30h] BYREF
  float v41; // [esp+70h] [ebp-20h]
  float v42; // [esp+74h] [ebp-1Ch]
  float v43; // [esp+78h] [ebp-18h]
  int v44; // [esp+7Ch] [ebp-14h]
  btVector3 v45; // [esp+80h] [ebp-10h] BYREF

  v4 = this;
  v27 = ((double (__fastcall *)(btConvexInternalShape *))this->getMargin)(this);
  v26 = 0;
  v44 = 0;
  while ( 1 )
  {
    v5 = trans->m_basis.m_el[0].mVec128.m128_f32[0];
    v6 = trans->m_basis.m_el[2].mVec128.m128_f32[0];
    v7 = v4->__vftable;
    v30 = 0.0;
    v29 = 0.0;
    v31 = 0.0;
    v8 = (float *)((char *)&v29 + v26);
    *(float *)((char *)&v29 + v26) = s_bm_current_air_resistance;
    v9 = (float)((float)(v5 * v29) + (float)(v6 * v31)) + (float)(trans->m_basis.m_el[1].mVec128.m128_f32[0] * v30);
    v10 = trans->m_basis.m_el[0].mVec128.m128_f32[1];
    *(float *)v39 = v9;
    v11 = v29 * trans->m_basis.m_el[0].mVec128.m128_f32[2];
    v12 = v31 * trans->m_basis.m_el[2].mVec128.m128_f32[2];
    *(float *)&v39[1] = (float)((float)(trans->m_basis.m_el[1].mVec128.m128_f32[1] * v30) + (float)(v10 * v29))
                      + (float)(trans->m_basis.m_el[2].mVec128.m128_f32[1] * v31);
    *(float *)&v39[2] = (float)((float)(trans->m_basis.m_el[1].mVec128.m128_f32[2] * v30) + v11) + v12;
    v39[3] = 0;
    v7->localGetSupportingVertex(v4, (btVector3 *)&v32, (const btVector3 *)v39);
    v13 = trans->m_basis.m_el[1].mVec128.m128_f32[2] * v34;
    v35 = (float)((float)((float)(trans->m_basis.m_el[0].mVec128.m128_f32[1] * v33)
                        + (float)(trans->m_basis.m_el[0].mVec128.m128_f32[0] * v32))
                + (float)(v34 * trans->m_basis.m_el[0].mVec128.m128_f32[2]))
        + trans->m_origin.mVec128.m128_f32[0];
    v14 = (float)((float)((float)(trans->m_basis.m_el[1].mVec128.m128_f32[1] * v33) + v13)
                + (float)(trans->m_basis.m_el[1].mVec128.m128_f32[0] * v32))
        + trans->m_origin.mVec128.m128_f32[1];
    v15 = trans->m_basis.m_el[2].mVec128.m128_f32[2] * v34;
    v36 = v14;
    v37 = (float)((float)((float)(trans->m_basis.m_el[2].mVec128.m128_f32[1] * v33) + v15)
                + (float)(trans->m_basis.m_el[2].mVec128.m128_f32[0] * v32))
        + trans->m_origin.mVec128.m128_f32[2];
    v38 = 0;
    *(float *)((char *)v8 + (char *)maxAabb - (char *)&v29) = *(float *)((char *)&v35 + v26) + v27;
    *v8 = FLOAT_N1_0;
    v16 = v4->__vftable;
    v17 = trans->m_basis.m_el[0].mVec128.m128_f32[1];
    v40[0] = (float)((float)(trans->m_basis.m_el[0].mVec128.m128_f32[0] * v29)
                   + (float)(trans->m_basis.m_el[2].mVec128.m128_f32[0] * v31))
           + (float)(trans->m_basis.m_el[1].mVec128.m128_f32[0] * v30);
    v18 = v29 * trans->m_basis.m_el[0].mVec128.m128_f32[2];
    v19 = v31 * trans->m_basis.m_el[2].mVec128.m128_f32[2];
    v40[1] = (float)((float)(trans->m_basis.m_el[1].mVec128.m128_f32[1] * v30) + (float)(v17 * v29))
           + (float)(trans->m_basis.m_el[2].mVec128.m128_f32[1] * v31);
    v40[2] = (float)((float)(trans->m_basis.m_el[1].mVec128.m128_f32[2] * v30) + v18) + v19;
    v40[3] = 0.0;
    v20 = (float *)v16->localGetSupportingVertex(v4, &v45, (const btVector3 *)v40);
    v21 = v20[1];
    v22 = *v20;
    v23 = v20[2];
    v41 = (float)((float)((float)(*v20 * trans->m_basis.m_el[0].mVec128.m128_f32[0])
                        + (float)(v21 * trans->m_basis.m_el[0].mVec128.m128_f32[1]))
                + (float)(v23 * trans->m_basis.m_el[0].mVec128.m128_f32[2]))
        + trans->m_origin.mVec128.m128_f32[0];
    v24 = (float)(v21 * trans->m_basis.m_el[1].mVec128.m128_f32[1])
        + (float)(v23 * trans->m_basis.m_el[1].mVec128.m128_f32[2]);
    v25 = v22 * trans->m_basis.m_el[1].mVec128.m128_f32[0];
    v43 = (float)((float)((float)(v22 * trans->m_basis.m_el[2].mVec128.m128_f32[0])
                        + (float)(v21 * trans->m_basis.m_el[2].mVec128.m128_f32[1]))
                + (float)(v23 * trans->m_basis.m_el[2].mVec128.m128_f32[2]))
        + trans->m_origin.mVec128.m128_f32[2];
    v42 = (float)(v24 + v25) + trans->m_origin.mVec128.m128_f32[1];
    v35 = v41;
    v36 = v42;
    v37 = v43;
    v38 = v44;
    minAabb->mVec128.m128_f32[v26 / 4u] = *(float *)((char *)&v35 + v26) - v27;
    v26 += 4;
    if ( v26 >= 12 )
      break;
    v4 = this;
  }
}
