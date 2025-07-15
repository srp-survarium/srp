void __userpurge btTriangleMeshShape::getAabb(
        btTriangleMeshShape *this@<ecx>,
        const float *a2@<edi>,
        const btTransform *trans,
        btVector3 *aabbMin,
        btVector3 *aabbMax)
{
  btTriangleMeshShape_vtbl *v6; // eax
  unsigned int v7; // xmm1_4
  unsigned int v8; // xmm2_4
  float v9; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  int v13; // xmm1_4
  int v14; // xmm1_4
  float v15; // xmm3_4
  float v16; // xmm4_4
  float v17; // xmm5_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // [esp+4h] [ebp-74h] BYREF
  float v22; // [esp+8h] [ebp-70h] BYREF
  int v23; // [esp+Ch] [ebp-6Ch] BYREF
  int v24; // [esp+10h] [ebp-68h] BYREF
  int v25; // [esp+14h] [ebp-64h] BYREF
  int v26; // [esp+18h] [ebp-60h] BYREF
  int v27; // [esp+1Ch] [ebp-5Ch] BYREF
  int v28; // [esp+20h] [ebp-58h] BYREF
  btMatrix3x3 v29; // [esp+24h] [ebp-54h] BYREF
  float v30; // [esp+58h] [ebp-20h]
  float v31; // [esp+5Ch] [ebp-1Ch]
  float v32; // [esp+60h] [ebp-18h]
  float v33; // [esp+68h] [ebp-10h]
  float v34; // [esp+6Ch] [ebp-Ch]
  float v35; // [esp+70h] [ebp-8h]

  v6 = this->__vftable;
  *(float *)&v7 = (float)(this->m_localAabbMax.mVec128.m128_f32[1] - this->m_localAabbMin.mVec128.m128_f32[1]) * 0.5;
  *(float *)&v8 = (float)(this->m_localAabbMax.mVec128.m128_f32[2] - this->m_localAabbMin.mVec128.m128_f32[2]) * 0.5;
  v29.m_el[0].mVec128.m128_f32[1] = (float)(this->m_localAabbMax.mVec128.m128_f32[0]
                                          - this->m_localAabbMin.mVec128.m128_f32[0])
                                  * 0.5;
  v29.m_el[0].mVec128.m128_u64[1] = __PAIR64__(v8, v7);
  v22 = ((double (*)(void))v6->getMargin)();
  v21 = this->getMargin(this);
  v29.m_el[1].mVec128.m128_f32[1] = this->getMargin(this);
  v9 = this->m_localAabbMin.mVec128.m128_f32[2] + this->m_localAabbMax.mVec128.m128_f32[2];
  v10 = (float)(this->m_localAabbMin.mVec128.m128_f32[1] + this->m_localAabbMax.mVec128.m128_f32[1]) * 0.5;
  v29.m_el[0].mVec128.m128_f32[1] = v29.m_el[0].mVec128.m128_f32[1] + v29.m_el[1].mVec128.m128_f32[1];
  v29.m_el[1].mVec128.m128_f32[2] = v10;
  v29.m_el[0].mVec128.m128_f32[2] = v29.m_el[0].mVec128.m128_f32[2] + v21;
  v29.m_el[0].mVec128.m128_f32[3] = v29.m_el[0].mVec128.m128_f32[3] + v22;
  v11 = this->m_localAabbMin.mVec128.m128_f32[0] + this->m_localAabbMax.mVec128.m128_f32[0];
  v13 = trans->m_basis.m_el[2].mVec128.m128_i32[2];
  v29.m_el[1].mVec128.m128_f32[1] = v11 * 0.5;
  LODWORD(v22) = v13 & _mask__AbsFloat_;
  LODWORD(v21) = trans->m_basis.m_el[2].mVec128.m128_i32[1] & _mask__AbsFloat_;
  v23 = trans->m_basis.m_el[2].mVec128.m128_i32[0] & _mask__AbsFloat_;
  v24 = trans->m_basis.m_el[1].mVec128.m128_i32[2] & _mask__AbsFloat_;
  v25 = trans->m_basis.m_el[1].mVec128.m128_i32[1] & _mask__AbsFloat_;
  v26 = trans->m_basis.m_el[1].mVec128.m128_i32[0] & _mask__AbsFloat_;
  v27 = trans->m_basis.m_el[0].mVec128.m128_i32[2] & _mask__AbsFloat_;
  v28 = trans->m_basis.m_el[0].mVec128.m128_i32[1] & _mask__AbsFloat_;
  v14 = trans->m_basis.m_el[0].mVec128.m128_i32[0] & _mask__AbsFloat_;
  v29.m_el[1].mVec128.m128_f32[3] = v9 * 0.5;
  v29.m_el[0].mVec128.m128_i32[0] = v14;
  btMatrix3x3::setValue(
    &v29,
    (int)&v29.m_el[2].mVec128.m128_i32[1],
    (float *)&v28,
    (float *)&v27,
    (float *)&v26,
    (float *)&v25,
    (float *)&v24,
    (float *)&v23,
    &v21,
    &v22,
    a2);
  v15 = (float)((float)((float)(trans->m_basis.m_el[0].mVec128.m128_f32[2] * v29.m_el[1].mVec128.m128_f32[3])
                      + (float)(trans->m_basis.m_el[0].mVec128.m128_f32[1] * v29.m_el[1].mVec128.m128_f32[2]))
              + (float)(trans->m_basis.m_el[0].mVec128.m128_f32[0] * v29.m_el[1].mVec128.m128_f32[1]))
      + trans->m_origin.mVec128.m128_f32[0];
  v16 = (float)((float)((float)(trans->m_basis.m_el[1].mVec128.m128_f32[2] * v29.m_el[1].mVec128.m128_f32[3])
                      + (float)(trans->m_basis.m_el[1].mVec128.m128_f32[1] * v29.m_el[1].mVec128.m128_f32[2]))
              + (float)(trans->m_basis.m_el[1].mVec128.m128_f32[0] * v29.m_el[1].mVec128.m128_f32[1]))
      + trans->m_origin.mVec128.m128_f32[1];
  v17 = (float)((float)((float)(trans->m_basis.m_el[2].mVec128.m128_f32[2] * v29.m_el[1].mVec128.m128_f32[3])
                      + (float)(trans->m_basis.m_el[2].mVec128.m128_f32[1] * v29.m_el[1].mVec128.m128_f32[2]))
              + (float)(trans->m_basis.m_el[2].mVec128.m128_f32[0] * v29.m_el[1].mVec128.m128_f32[1]))
      + trans->m_origin.mVec128.m128_f32[2];
  v18 = (float)((float)(v29.m_el[2].mVec128.m128_f32[3] * v29.m_el[0].mVec128.m128_f32[3])
              + (float)(v29.m_el[2].mVec128.m128_f32[2] * v29.m_el[0].mVec128.m128_f32[2]))
      + (float)(v29.m_el[2].mVec128.m128_f32[1] * v29.m_el[0].mVec128.m128_f32[1]);
  v19 = (float)((float)(v32 * v29.m_el[0].mVec128.m128_f32[3]) + (float)(v31 * v29.m_el[0].mVec128.m128_f32[2]))
      + (float)(v30 * v29.m_el[0].mVec128.m128_f32[1]);
  v20 = (float)((float)(v35 * v29.m_el[0].mVec128.m128_f32[3]) + (float)(v34 * v29.m_el[0].mVec128.m128_f32[2]))
      + (float)(v33 * v29.m_el[0].mVec128.m128_f32[1]);
  v29.m_el[1].mVec128.m128_f32[2] = v16 - v19;
  v29.m_el[1].mVec128.m128_f32[3] = v17 - v20;
  v29.m_el[2].mVec128.m128_i32[0] = 0;
  aabbMin->mVec128.m128_f32[0] = v15 - v18;
  *(unsigned __int64 *)((char *)aabbMin->mVec128.m128_u64 + 4) = v29.m_el[1].mVec128.m128_u64[1];
  aabbMin->mVec128.m128_i32[3] = v29.m_el[2].mVec128.m128_i32[0];
  v29.m_el[2].mVec128.m128_i32[0] = 0;
  v29.m_el[1].mVec128.m128_f32[2] = v19 + v16;
  v29.m_el[1].mVec128.m128_f32[3] = v20 + v17;
  aabbMax->mVec128.m128_f32[0] = v18 + v15;
  *(unsigned __int64 *)((char *)aabbMax->mVec128.m128_u64 + 4) = v29.m_el[1].mVec128.m128_u64[1];
  aabbMax->mVec128.m128_i32[3] = v29.m_el[2].mVec128.m128_i32[0];
}
