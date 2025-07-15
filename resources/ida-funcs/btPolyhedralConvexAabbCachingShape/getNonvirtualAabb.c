void __userpurge btPolyhedralConvexAabbCachingShape::getNonvirtualAabb(
        btPolyhedralConvexAabbCachingShape *this@<ecx>,
        float *a2@<eax>,
        const float *a3@<edi>,
        const btTransform *trans,
        btVector3 *aabbMin,
        btVector3 *aabbMax,
        float margin)
{
  float v7; // xmm4_4
  float v8; // xmm5_4
  float v9; // xmm2_4
  float v10; // xmm6_4
  float v11; // xmm3_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  unsigned int v15; // xmm4_4
  unsigned int v16; // xmm5_4
  unsigned int v17; // xmm6_4
  unsigned int v18; // xmm1_4
  float v19; // xmm3_4
  float v20; // xmm4_4
  float v21; // xmm5_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  int v25; // [esp+4h] [ebp-74h] BYREF
  int v26; // [esp+8h] [ebp-70h] BYREF
  int v27; // [esp+Ch] [ebp-6Ch] BYREF
  int v28; // [esp+10h] [ebp-68h] BYREF
  int v29; // [esp+14h] [ebp-64h] BYREF
  int v30; // [esp+18h] [ebp-60h] BYREF
  int v31; // [esp+1Ch] [ebp-5Ch] BYREF
  int v32; // [esp+20h] [ebp-58h] BYREF
  btMatrix3x3 v33; // [esp+24h] [ebp-54h] BYREF
  float v34; // [esp+58h] [ebp-20h]
  float v35; // [esp+5Ch] [ebp-1Ch]
  float v36; // [esp+60h] [ebp-18h]
  float v37; // [esp+68h] [ebp-10h]
  float v38; // [esp+6Ch] [ebp-Ch]
  float v39; // [esp+70h] [ebp-8h]

  v7 = a2[20];
  v8 = a2[21];
  v9 = a2[25];
  v10 = a2[22];
  v11 = a2[26];
  v33.m_el[1].mVec128.m128_f32[1] = (float)((float)(a2[24] - v7) * 0.5) + *(float *)&aabbMax;
  v13 = v9 - v8;
  v14 = (float)((float)(v11 - v10) * 0.5) + *(float *)&aabbMax;
  *(float *)&v15 = (float)(v7 + a2[24]) * 0.5;
  *(float *)&v16 = (float)(v8 + a2[25]) * 0.5;
  *(float *)&v17 = (float)(v10 + a2[26]) * 0.5;
  v25 = this->m_implicitShapeDimensions.mVec128.m128_i32[2] & _mask__AbsFloat_;
  v26 = this->m_implicitShapeDimensions.mVec128.m128_i32[1] & _mask__AbsFloat_;
  v27 = this->m_implicitShapeDimensions.mVec128.m128_i32[0] & _mask__AbsFloat_;
  v28 = this->m_localScaling.mVec128.m128_i32[2] & _mask__AbsFloat_;
  v29 = this->m_localScaling.mVec128.m128_i32[1] & _mask__AbsFloat_;
  v30 = this->m_localScaling.mVec128.m128_i32[0] & _mask__AbsFloat_;
  v31 = (__int128)this->m_userPointer & _mask__AbsFloat_;
  v32 = this->m_shapeType & _mask__AbsFloat_;
  v18 = (__int128)this->__vftable & _mask__AbsFloat_;
  v33.m_el[1].mVec128.m128_f32[2] = (float)(v13 * 0.5) + *(float *)&aabbMax;
  v33.m_el[1].mVec128.m128_f32[3] = v14;
  v33.m_el[0].mVec128.m128_u64[1] = __PAIR64__(v17, v16);
  v33.m_el[0].mVec128.m128_u64[0] = __PAIR64__(v15, v18);
  btMatrix3x3::setValue(
    &v33,
    (int)&v33.m_el[2].mVec128.m128_i32[1],
    (float *)&v32,
    (float *)&v31,
    (float *)&v30,
    (float *)&v29,
    (float *)&v28,
    (float *)&v27,
    (float *)&v26,
    (const float *)&v25,
    a3);
  v19 = (float)((float)((float)(*(float *)&this->__vftable * v33.m_el[0].mVec128.m128_f32[1])
                      + (float)(*(float *)&this->m_userPointer * v33.m_el[0].mVec128.m128_f32[3]))
              + (float)(*(float *)&this->m_shapeType * v33.m_el[0].mVec128.m128_f32[2]))
      + this->m_collisionMargin;
  v20 = (float)((float)((float)(this->m_localScaling.mVec128.m128_f32[2] * v33.m_el[0].mVec128.m128_f32[3])
                      + (float)(this->m_localScaling.mVec128.m128_f32[1] * v33.m_el[0].mVec128.m128_f32[2]))
              + (float)(this->m_localScaling.mVec128.m128_f32[0] * v33.m_el[0].mVec128.m128_f32[1]))
      + this->m_padding;
  v21 = (float)((float)((float)(this->m_implicitShapeDimensions.mVec128.m128_f32[2] * v33.m_el[0].mVec128.m128_f32[3])
                      + (float)(this->m_implicitShapeDimensions.mVec128.m128_f32[1] * v33.m_el[0].mVec128.m128_f32[2]))
              + (float)(this->m_implicitShapeDimensions.mVec128.m128_f32[0] * v33.m_el[0].mVec128.m128_f32[1]))
      + *(&this->m_padding + 1);
  v22 = (float)((float)(v33.m_el[2].mVec128.m128_f32[3] * v33.m_el[1].mVec128.m128_f32[3])
              + (float)(v33.m_el[2].mVec128.m128_f32[2] * v33.m_el[1].mVec128.m128_f32[2]))
      + (float)(v33.m_el[2].mVec128.m128_f32[1] * v33.m_el[1].mVec128.m128_f32[1]);
  v23 = (float)((float)(v36 * v33.m_el[1].mVec128.m128_f32[3]) + (float)(v35 * v33.m_el[1].mVec128.m128_f32[2]))
      + (float)(v34 * v33.m_el[1].mVec128.m128_f32[1]);
  v24 = (float)((float)(v39 * v33.m_el[1].mVec128.m128_f32[3]) + (float)(v38 * v33.m_el[1].mVec128.m128_f32[2]))
      + (float)(v37 * v33.m_el[1].mVec128.m128_f32[1]);
  v33.m_el[1].mVec128.m128_f32[2] = v20 - v23;
  v33.m_el[1].mVec128.m128_f32[3] = v21 - v24;
  v33.m_el[2].mVec128.m128_i32[0] = 0;
  trans->m_basis.m_el[0].mVec128.m128_f32[0] = v19 - v22;
  *(unsigned __int64 *)((char *)trans->m_basis.m_el[0].mVec128.m128_u64 + 4) = v33.m_el[1].mVec128.m128_u64[1];
  trans->m_basis.m_el[0].mVec128.m128_i32[3] = v33.m_el[2].mVec128.m128_i32[0];
  v33.m_el[2].mVec128.m128_i32[0] = 0;
  v33.m_el[1].mVec128.m128_f32[2] = v23 + v20;
  v33.m_el[1].mVec128.m128_f32[3] = v24 + v21;
  aabbMin->mVec128.m128_f32[0] = v22 + v19;
  *(unsigned __int64 *)((char *)aabbMin->mVec128.m128_u64 + 4) = v33.m_el[1].mVec128.m128_u64[1];
  aabbMin->mVec128.m128_i32[3] = v33.m_el[2].mVec128.m128_i32[0];
}
