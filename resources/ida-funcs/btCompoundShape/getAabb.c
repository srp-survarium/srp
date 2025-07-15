void __userpurge btCompoundShape::getAabb(
        btCompoundShape *this@<ecx>,
        const float *a2@<edi>,
        const btTransform *trans,
        btVector3 *aabbMin,
        btVector3 *aabbMax)
{
  bool v6; // zf
  unsigned int v7; // xmm2_4
  unsigned int v8; // xmm3_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  double v12; // st7
  int v14; // xmm1_4
  double v15; // st7
  float v16; // xmm3_4
  float v17; // xmm4_4
  float v18; // xmm5_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // [esp+4h] [ebp-74h] BYREF
  float v23; // [esp+8h] [ebp-70h] BYREF
  int v24; // [esp+Ch] [ebp-6Ch] BYREF
  int v25; // [esp+10h] [ebp-68h] BYREF
  int v26; // [esp+14h] [ebp-64h] BYREF
  int v27; // [esp+18h] [ebp-60h] BYREF
  int v28; // [esp+1Ch] [ebp-5Ch] BYREF
  int v29; // [esp+20h] [ebp-58h] BYREF
  btMatrix3x3 v30; // [esp+24h] [ebp-54h] BYREF
  float v31; // [esp+58h] [ebp-20h]
  float v32; // [esp+5Ch] [ebp-1Ch]
  float v33; // [esp+60h] [ebp-18h]
  float v34; // [esp+68h] [ebp-10h]
  float v35; // [esp+6Ch] [ebp-Ch]
  float v36; // [esp+70h] [ebp-8h]

  v6 = this->m_children.m_size == 0;
  *(float *)&v7 = (float)(this->m_localAabbMax.mVec128.m128_f32[1] - this->m_localAabbMin.mVec128.m128_f32[1]) * 0.5;
  *(float *)&v8 = (float)(this->m_localAabbMax.mVec128.m128_f32[2] - this->m_localAabbMin.mVec128.m128_f32[2]) * 0.5;
  v30.m_el[0].mVec128.m128_f32[1] = (float)(this->m_localAabbMax.mVec128.m128_f32[0]
                                          - this->m_localAabbMin.mVec128.m128_f32[0])
                                  * 0.5;
  v9 = this->m_localAabbMin.mVec128.m128_f32[0] + this->m_localAabbMax.mVec128.m128_f32[0];
  v30.m_el[0].mVec128.m128_u64[1] = __PAIR64__(v8, v7);
  v10 = this->m_localAabbMax.mVec128.m128_f32[1] + this->m_localAabbMin.mVec128.m128_f32[1];
  v11 = (float)(this->m_localAabbMax.mVec128.m128_f32[2] + this->m_localAabbMin.mVec128.m128_f32[2]) * 0.5;
  v30.m_el[1].mVec128.m128_f32[1] = v9 * 0.5;
  v30.m_el[1].mVec128.m128_f32[2] = v10 * 0.5;
  v30.m_el[1].mVec128.m128_f32[3] = v11;
  if ( v6 )
  {
    memset(&v30.m_el[0].m_floats[1], 0, 12);
    memset(&v30.m_el[1].m_floats[1], 0, 12);
  }
  v23 = this->getMargin(this);
  v22 = this->getMargin(this);
  v12 = ((double (__thiscall *)(btCompoundShape *))this->getMargin)(this);
  v14 = trans->m_basis.m_el[2].mVec128.m128_i32[2];
  v30.m_el[0].mVec128.m128_f32[1] = v12 + v30.m_el[0].mVec128.m128_f32[1];
  v30.m_el[0].mVec128.m128_f32[2] = v30.m_el[0].mVec128.m128_f32[2] + v22;
  v15 = v30.m_el[0].mVec128.m128_f32[3] + v23;
  LODWORD(v23) = v14 & _mask__AbsFloat_;
  LODWORD(v22) = trans->m_basis.m_el[2].mVec128.m128_i32[1] & _mask__AbsFloat_;
  v30.m_el[0].mVec128.m128_f32[3] = v15;
  v24 = trans->m_basis.m_el[2].mVec128.m128_i32[0] & _mask__AbsFloat_;
  v25 = trans->m_basis.m_el[1].mVec128.m128_i32[2] & _mask__AbsFloat_;
  v26 = trans->m_basis.m_el[1].mVec128.m128_i32[1] & _mask__AbsFloat_;
  v27 = trans->m_basis.m_el[1].mVec128.m128_i32[0] & _mask__AbsFloat_;
  v28 = trans->m_basis.m_el[0].mVec128.m128_i32[2] & _mask__AbsFloat_;
  v29 = trans->m_basis.m_el[0].mVec128.m128_i32[1] & _mask__AbsFloat_;
  v30.m_el[0].mVec128.m128_i32[0] = trans->m_basis.m_el[0].mVec128.m128_i32[0] & _mask__AbsFloat_;
  btMatrix3x3::setValue(
    &v30,
    (int)&v30.m_el[2].mVec128.m128_i32[1],
    (float *)&v29,
    (float *)&v28,
    (float *)&v27,
    (float *)&v26,
    (float *)&v25,
    (float *)&v24,
    &v22,
    &v23,
    a2);
  v16 = (float)((float)((float)(trans->m_basis.m_el[0].mVec128.m128_f32[2] * v30.m_el[1].mVec128.m128_f32[3])
                      + (float)(trans->m_basis.m_el[0].mVec128.m128_f32[1] * v30.m_el[1].mVec128.m128_f32[2]))
              + (float)(trans->m_basis.m_el[0].mVec128.m128_f32[0] * v30.m_el[1].mVec128.m128_f32[1]))
      + trans->m_origin.mVec128.m128_f32[0];
  v17 = (float)((float)((float)(trans->m_basis.m_el[1].mVec128.m128_f32[2] * v30.m_el[1].mVec128.m128_f32[3])
                      + (float)(trans->m_basis.m_el[1].mVec128.m128_f32[1] * v30.m_el[1].mVec128.m128_f32[2]))
              + (float)(trans->m_basis.m_el[1].mVec128.m128_f32[0] * v30.m_el[1].mVec128.m128_f32[1]))
      + trans->m_origin.mVec128.m128_f32[1];
  v18 = (float)((float)((float)(trans->m_basis.m_el[2].mVec128.m128_f32[2] * v30.m_el[1].mVec128.m128_f32[3])
                      + (float)(trans->m_basis.m_el[2].mVec128.m128_f32[1] * v30.m_el[1].mVec128.m128_f32[2]))
              + (float)(trans->m_basis.m_el[2].mVec128.m128_f32[0] * v30.m_el[1].mVec128.m128_f32[1]))
      + trans->m_origin.mVec128.m128_f32[2];
  v19 = (float)((float)(v30.m_el[2].mVec128.m128_f32[3] * v30.m_el[0].mVec128.m128_f32[3])
              + (float)(v30.m_el[2].mVec128.m128_f32[2] * v30.m_el[0].mVec128.m128_f32[2]))
      + (float)(v30.m_el[2].mVec128.m128_f32[1] * v30.m_el[0].mVec128.m128_f32[1]);
  v20 = (float)((float)(v31 * v30.m_el[0].mVec128.m128_f32[1]) + (float)(v33 * v30.m_el[0].mVec128.m128_f32[3]))
      + (float)(v32 * v30.m_el[0].mVec128.m128_f32[2]);
  v21 = (float)((float)(v36 * v30.m_el[0].mVec128.m128_f32[3]) + (float)(v35 * v30.m_el[0].mVec128.m128_f32[2]))
      + (float)(v34 * v30.m_el[0].mVec128.m128_f32[1]);
  v30.m_el[1].mVec128.m128_f32[2] = v17 - v20;
  v30.m_el[1].mVec128.m128_f32[3] = v18 - v21;
  v30.m_el[2].mVec128.m128_i32[0] = 0;
  aabbMin->mVec128.m128_f32[0] = v16 - v19;
  *(unsigned __int64 *)((char *)aabbMin->mVec128.m128_u64 + 4) = v30.m_el[1].mVec128.m128_u64[1];
  aabbMin->mVec128.m128_i32[3] = v30.m_el[2].mVec128.m128_i32[0];
  v30.m_el[2].mVec128.m128_i32[0] = 0;
  v30.m_el[1].mVec128.m128_f32[2] = v20 + v17;
  v30.m_el[1].mVec128.m128_f32[3] = v21 + v18;
  aabbMax->mVec128.m128_f32[0] = v19 + v16;
  *(unsigned __int64 *)((char *)aabbMax->mVec128.m128_u64 + 4) = v30.m_el[1].mVec128.m128_u64[1];
  aabbMax->mVec128.m128_i32[3] = v30.m_el[2].mVec128.m128_i32[0];
}
