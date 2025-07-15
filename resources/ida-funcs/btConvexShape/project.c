void __thiscall btConvexShape::project(
        btConvexShape *this,
        const btTransform *trans,
        const btVector3 *dir,
        float *min,
        float *max)
{
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm0_4
  float v10; // xmm4_4
  float v11; // xmm3_4
  float v12; // xmm4_4
  float v13; // xmm0_4
  btVector3 *(__thiscall *localGetSupportingVertex)(btConvexShape *, btVector3 *, const btVector3 *); // eax
  float *v15; // eax
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm3_4
  float v19; // xmm4_4
  float v20; // xmm0_4
  float v21; // xmm4_4
  float v22; // xmm1_4
  btVector3 *(__thiscall *v23)(btConvexShape *, btVector3 *, const btVector3 *); // edx
  float *v24; // eax
  float v25; // xmm1_4
  float v26; // xmm4_4
  float v27; // xmm2_4
  float v28; // xmm0_4
  float v29; // xmm3_4
  float v30; // xmm1_4
  int v31; // xmm0_4
  float v32; // [esp+80h] [ebp-40h] BYREF
  float v33; // [esp+84h] [ebp-3Ch]
  float v34; // [esp+88h] [ebp-38h]
  int v35; // [esp+8Ch] [ebp-34h]
  float v36; // [esp+90h] [ebp-30h]
  float v37; // [esp+94h] [ebp-2Ch]
  float v38; // [esp+98h] [ebp-28h]
  float v39[4]; // [esp+A0h] [ebp-20h] BYREF
  btVector3 v40; // [esp+B0h] [ebp-10h] BYREF

  v7 = dir->mVec128.m128_f32[2];
  v8 = dir->mVec128.m128_f32[1];
  v9 = dir->mVec128.m128_f32[0];
  v10 = trans->m_basis.m_el[2].mVec128.m128_f32[1];
  v32 = (float)((float)(trans->m_basis.m_el[1].mVec128.m128_f32[0] * v8)
              + (float)(v7 * trans->m_basis.m_el[2].mVec128.m128_f32[0]))
      + (float)(trans->m_basis.m_el[0].mVec128.m128_f32[0] * dir->mVec128.m128_f32[0]);
  v11 = (float)(trans->m_basis.m_el[1].mVec128.m128_f32[1] * v8) + (float)(v10 * v7);
  v12 = trans->m_basis.m_el[0].mVec128.m128_f32[1] * v9;
  v13 = v9 * trans->m_basis.m_el[0].mVec128.m128_f32[2];
  v33 = v11 + v12;
  localGetSupportingVertex = this->localGetSupportingVertex;
  v34 = (float)((float)(trans->m_basis.m_el[1].mVec128.m128_f32[2] * v8)
              + (float)(trans->m_basis.m_el[2].mVec128.m128_f32[2] * v7))
      + v13;
  v35 = 0;
  v15 = (float *)localGetSupportingVertex(this, (btVector3 *)v39, (const btVector3 *)&v32);
  v16 = v15[2];
  v17 = *v15;
  v18 = v15[1];
  v19 = trans->m_basis.m_el[1].mVec128.m128_f32[2];
  v36 = (float)((float)((float)(trans->m_basis.m_el[0].mVec128.m128_f32[0] * *v15)
                      + (float)(v16 * trans->m_basis.m_el[0].mVec128.m128_f32[2]))
              + (float)(trans->m_basis.m_el[0].mVec128.m128_f32[1] * v18))
      + trans->m_origin.mVec128.m128_f32[0];
  v20 = (float)(trans->m_basis.m_el[1].mVec128.m128_f32[1] * v18) + (float)(v19 * v16);
  v21 = v17 * trans->m_basis.m_el[1].mVec128.m128_f32[0];
  v22 = v17 * trans->m_basis.m_el[2].mVec128.m128_f32[0];
  v37 = (float)(v20 + v21) + trans->m_origin.mVec128.m128_f32[1];
  v38 = (float)((float)((float)(trans->m_basis.m_el[2].mVec128.m128_f32[1] * v18)
                      + (float)(trans->m_basis.m_el[2].mVec128.m128_f32[2] * v16))
              + v22)
      + trans->m_origin.mVec128.m128_f32[2];
  v39[0] = -v32;
  v23 = this->localGetSupportingVertex;
  LODWORD(v39[1]) = LODWORD(v33) ^ 0x80000000;
  v39[2] = -v34;
  v39[3] = 0.0;
  v24 = (float *)v23(this, &v40, (const btVector3 *)v39);
  v25 = v24[2];
  v26 = v24[1];
  v27 = (float)((float)((float)(trans->m_basis.m_el[0].mVec128.m128_f32[0] * *v24)
                      + (float)(v25 * trans->m_basis.m_el[0].mVec128.m128_f32[2]))
              + (float)(trans->m_basis.m_el[0].mVec128.m128_f32[1] * v26))
      + trans->m_origin.mVec128.m128_f32[0];
  v28 = (float)((float)((float)(trans->m_basis.m_el[1].mVec128.m128_f32[1] * v26)
                      + (float)(trans->m_basis.m_el[1].mVec128.m128_f32[2] * v25))
              + (float)(trans->m_basis.m_el[1].mVec128.m128_f32[0] * *v24))
      + trans->m_origin.mVec128.m128_f32[1];
  v29 = (float)((float)((float)(trans->m_basis.m_el[2].mVec128.m128_f32[1] * v26)
                      + (float)(trans->m_basis.m_el[2].mVec128.m128_f32[2] * v25))
              + (float)(trans->m_basis.m_el[2].mVec128.m128_f32[0] * *v24))
      + trans->m_origin.mVec128.m128_f32[2];
  *min = (float)((float)(dir->mVec128.m128_f32[0] * v36) + (float)(dir->mVec128.m128_f32[2] * v38))
       + (float)(v37 * dir->mVec128.m128_f32[1]);
  v30 = (float)((float)(dir->mVec128.m128_f32[0] * v27) + (float)(dir->mVec128.m128_f32[2] * v29))
      + (float)(v28 * dir->mVec128.m128_f32[1]);
  *max = v30;
  v31 = *(_DWORD *)min;
  if ( *min > v30 )
  {
    *min = v30;
    *(_DWORD *)max = v31;
  }
}
