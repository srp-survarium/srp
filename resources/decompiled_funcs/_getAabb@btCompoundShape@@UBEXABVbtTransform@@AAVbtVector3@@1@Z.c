void __thiscall btCompoundShape::getAabb(
        btCompoundShape *this,
        const btTransform *trans,
        btVector3 *aabbMin,
        btVector3 *aabbMax)
{
  double v5; // st7
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm0_4
  float v10; // xmm4_4
  float v11; // xmm6_4
  float v12; // xmm1_4
  float v13; // [esp+4Ch] [ebp-50h]
  float v14; // [esp+50h] [ebp-4Ch]
  float _X; // [esp+50h] [ebp-4Ch]
  float v16; // [esp+54h] [ebp-48h]
  float v17; // [esp+54h] [ebp-48h]
  float v18; // [esp+58h] [ebp-44h]
  float v19; // [esp+5Ch] [ebp-40h]
  float v20; // [esp+60h] [ebp-3Ch]
  float v21; // [esp+64h] [ebp-38h]
  float v22; // [esp+68h] [ebp-34h]
  float v23; // [esp+6Ch] [ebp-30h]
  float v24; // [esp+70h] [ebp-2Ch]
  float v25; // [esp+74h] [ebp-28h]
  float v26; // [esp+78h] [ebp-24h]
  float v27; // [esp+7Ch] [ebp-20h]
  float v28; // [esp+7Ch] [ebp-20h]
  float v29; // [esp+80h] [ebp-1Ch]
  float v30; // [esp+80h] [ebp-1Ch]
  float v31; // [esp+84h] [ebp-18h]
  float v32; // [esp+84h] [ebp-18h]
  float v33; // [esp+8Ch] [ebp-10h]
  unsigned __int64 v34; // [esp+8Ch] [ebp-10h]
  float v35; // [esp+90h] [ebp-Ch]
  float v36; // [esp+94h] [ebp-8h]

  v27 = (float)(this->m_localAabbMax.mVec128.m128_f32[0] - this->m_localAabbMin.mVec128.m128_f32[0]) * 0.5;
  v29 = (float)(this->m_localAabbMax.mVec128.m128_f32[1] - this->m_localAabbMin.mVec128.m128_f32[1]) * 0.5;
  v31 = (float)(this->m_localAabbMax.mVec128.m128_f32[2] - this->m_localAabbMin.mVec128.m128_f32[2]) * 0.5;
  v33 = (float)(this->m_localAabbMin.mVec128.m128_f32[0] + this->m_localAabbMax.mVec128.m128_f32[0]) * 0.5;
  v35 = (float)(this->m_localAabbMax.mVec128.m128_f32[1] + this->m_localAabbMin.mVec128.m128_f32[1]) * 0.5;
  v36 = (float)(this->m_localAabbMax.mVec128.m128_f32[2] + this->m_localAabbMin.mVec128.m128_f32[2]) * 0.5;
  if ( !this->m_children.m_size )
  {
    v27 = 0.0;
    v29 = 0.0;
    v31 = 0.0;
    v33 = 0.0;
    v35 = 0.0;
    v36 = 0.0;
  }
  v14 = this->getMargin(this);
  v16 = this->getMargin(this);
  v5 = ((double (__thiscall *)(btCompoundShape *))this->getMargin)(this);
  v28 = v5 + v27;
  v30 = v29 + v16;
  v32 = v31 + v14;
  v24 = fabsf(trans->m_basis.m_el[2].mVec128.m128_f32[2]);
  v25 = fabsf(trans->m_basis.m_el[2].mVec128.m128_f32[1]);
  v26 = fabsf(trans->m_basis.m_el[2].mVec128.m128_f32[0]);
  v22 = fabsf(trans->m_basis.m_el[1].mVec128.m128_f32[2]);
  v21 = fabsf(trans->m_basis.m_el[1].mVec128.m128_f32[1]);
  v23 = fabsf(trans->m_basis.m_el[1].mVec128.m128_f32[0]);
  _X = trans->m_basis.m_el[0].mVec128.m128_f32[2];
  v19 = fabsf(_X);
  v13 = trans->m_basis.m_el[0].mVec128.m128_f32[1];
  v18 = fabsf(v13);
  v17 = trans->m_basis.m_el[0].mVec128.m128_f32[0];
  v20 = fabsf(trans->m_basis.m_el[0].mVec128.m128_f32[0]);
  v7 = (float)((float)((float)(trans->m_basis.m_el[1].mVec128.m128_f32[2] * v36)
                     + (float)(trans->m_basis.m_el[1].mVec128.m128_f32[1] * v35))
             + (float)(trans->m_basis.m_el[1].mVec128.m128_f32[0] * v33))
     + trans->m_origin.mVec128.m128_f32[1];
  v8 = (float)((float)((float)(trans->m_basis.m_el[2].mVec128.m128_f32[2] * v36)
                     + (float)(trans->m_basis.m_el[2].mVec128.m128_f32[1] * v35))
             + (float)(trans->m_basis.m_el[2].mVec128.m128_f32[0] * v33))
     + trans->m_origin.mVec128.m128_f32[2];
  v9 = (float)((float)(v30 * v18) + (float)(v32 * v19)) + (float)(v20 * v28);
  v10 = (float)((float)(v32 * v24) + (float)(v30 * v25)) + (float)(v26 * v28);
  v11 = (float)((float)((float)(v13 * v35) + (float)(_X * v36)) + (float)(v17 * v33))
      + trans->m_origin.mVec128.m128_f32[0];
  v12 = (float)((float)(v30 * v21) + (float)(v32 * v22)) + (float)(v23 * v28);
  *(float *)&v34 = v11 - v9;
  *((float *)&v34 + 1) = v7 - v12;
  aabbMin->mVec128.m128_u64[0] = v34;
  aabbMin->mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(v8 - v10);
  *(float *)&v34 = v9 + v11;
  *((float *)&v34 + 1) = v12 + v7;
  aabbMax->mVec128.m128_u64[0] = v34;
  aabbMax->mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(v10 + v8);
}
