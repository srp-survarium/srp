void __thiscall btTriangleMeshShape::getAabb(
        btTriangleMeshShape *this,
        const btTransform *trans,
        btVector3 *aabbMin,
        btVector3 *aabbMax)
{
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm0_4
  float v9; // xmm3_4
  float v10; // xmm4_4
  float v11; // xmm0_4
  float v12; // xmm2_4
  float v13; // xmm5_4
  float v14; // xmm1_4
  float v15; // [esp+4Ch] [ebp-50h]
  float v16; // [esp+50h] [ebp-4Ch]
  float _X; // [esp+50h] [ebp-4Ch]
  float v18; // [esp+54h] [ebp-48h]
  float v19; // [esp+54h] [ebp-48h]
  float v20; // [esp+58h] [ebp-44h]
  float v21; // [esp+5Ch] [ebp-40h]
  float v22; // [esp+60h] [ebp-3Ch]
  float v23; // [esp+64h] [ebp-38h]
  float v24; // [esp+68h] [ebp-34h]
  float v25; // [esp+6Ch] [ebp-30h]
  float v26; // [esp+70h] [ebp-2Ch]
  float v27; // [esp+74h] [ebp-28h]
  float v28; // [esp+78h] [ebp-24h]
  float v29; // [esp+7Ch] [ebp-20h]
  float v30; // [esp+7Ch] [ebp-20h]
  float v31; // [esp+80h] [ebp-1Ch]
  float v32; // [esp+80h] [ebp-1Ch]
  float v33; // [esp+84h] [ebp-18h]
  float v34; // [esp+84h] [ebp-18h]
  float v35; // [esp+8Ch] [ebp-10h]
  float v36; // [esp+8Ch] [ebp-10h]
  unsigned __int64 v37; // [esp+8Ch] [ebp-10h]
  float v38; // [esp+94h] [ebp-8h]

  v29 = (float)(this->m_localAabbMax.mVec128.m128_f32[0] - this->m_localAabbMin.mVec128.m128_f32[0]) * 0.5;
  v31 = (float)(this->m_localAabbMax.mVec128.m128_f32[1] - this->m_localAabbMin.mVec128.m128_f32[1]) * 0.5;
  v33 = (float)(this->m_localAabbMax.mVec128.m128_f32[2] - this->m_localAabbMin.mVec128.m128_f32[2]) * 0.5;
  v16 = ((double (*)(void))this->getMargin)();
  v18 = this->getMargin(this);
  v35 = this->getMargin(this);
  v5 = this->m_localAabbMin.mVec128.m128_f32[1] + this->m_localAabbMax.mVec128.m128_f32[1];
  v6 = this->m_localAabbMin.mVec128.m128_f32[2] + this->m_localAabbMax.mVec128.m128_f32[2];
  v30 = v29 + v35;
  v32 = v31 + v18;
  v34 = v33 + v16;
  v7 = this->m_localAabbMin.mVec128.m128_f32[0] + this->m_localAabbMax.mVec128.m128_f32[0];
  v36 = v7 * 0.5;
  v38 = v6 * 0.5;
  v27 = fabsf(trans->m_basis.m_el[2].mVec128.m128_f32[2]);
  v26 = fabsf(trans->m_basis.m_el[2].mVec128.m128_f32[1]);
  v28 = fabsf(trans->m_basis.m_el[2].mVec128.m128_f32[0]);
  v24 = fabsf(trans->m_basis.m_el[1].mVec128.m128_f32[2]);
  v23 = fabsf(trans->m_basis.m_el[1].mVec128.m128_f32[1]);
  v25 = fabsf(trans->m_basis.m_el[1].mVec128.m128_f32[0]);
  _X = trans->m_basis.m_el[0].mVec128.m128_f32[2];
  v20 = fabsf(_X);
  v15 = trans->m_basis.m_el[0].mVec128.m128_f32[1];
  v21 = fabsf(v15);
  v19 = trans->m_basis.m_el[0].mVec128.m128_f32[0];
  v22 = fabsf(trans->m_basis.m_el[0].mVec128.m128_f32[0]);
  v9 = (float)((float)((float)(trans->m_basis.m_el[1].mVec128.m128_f32[2] * (float)(v6 * 0.5))
                     + (float)(trans->m_basis.m_el[1].mVec128.m128_f32[1] * (float)(v5 * 0.5)))
             + (float)(trans->m_basis.m_el[1].mVec128.m128_f32[0] * (float)(v7 * 0.5)))
     + trans->m_origin.mVec128.m128_f32[1];
  v10 = (float)((float)((float)(trans->m_basis.m_el[2].mVec128.m128_f32[2] * (float)(v6 * 0.5))
                      + (float)(trans->m_basis.m_el[2].mVec128.m128_f32[1] * (float)(v5 * 0.5)))
              + (float)(trans->m_basis.m_el[2].mVec128.m128_f32[0] * (float)(v7 * 0.5)))
      + trans->m_origin.mVec128.m128_f32[2];
  v11 = (float)((float)(v34 * v20) + (float)(v32 * v21)) + (float)(v22 * v30);
  v12 = (float)((float)(v32 * v26) + (float)(v34 * v27)) + (float)(v30 * v28);
  v13 = (float)((float)((float)(v15 * (float)(v5 * 0.5)) + (float)(_X * v38)) + (float)(v19 * v36))
      + trans->m_origin.mVec128.m128_f32[0];
  *(float *)&v37 = v13 - v11;
  v14 = (float)((float)(v32 * v23) + (float)(v34 * v24)) + (float)(v25 * v30);
  *((float *)&v37 + 1) = v9 - v14;
  aabbMin->mVec128.m128_u64[0] = v37;
  aabbMin->mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(v10 - v12);
  *(float *)&v37 = v11 + v13;
  *((float *)&v37 + 1) = v14 + v9;
  aabbMax->mVec128.m128_u64[0] = v37;
  aabbMax->mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(v12 + v10);
}
