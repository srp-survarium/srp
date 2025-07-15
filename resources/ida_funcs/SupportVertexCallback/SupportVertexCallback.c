void __stdcall SupportVertexCallback::SupportVertexCallback(SupportVertexCallback *this)
{
  const btVector3 *supportVecWorld; // edx
  const btTransform *trans; // ecx
  float v4; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm4_4
  float v7; // xmm3_4
  float v8; // xmm2_4
  unsigned __int64 v9; // [esp+0h] [ebp-10h]
  unsigned __int64 v10; // [esp+8h] [ebp-8h]

  this->__vftable = (SupportVertexCallback_vtbl *)&SupportVertexCallback::`vftable';
  this->m_supportVertexLocal.mVec128.m128_u64[0] = 0;
  this->m_supportVertexLocal.mVec128.m128_u64[1] = 0;
  this->m_worldTrans = *trans;
  this->m_maxDot = -9.9999998e17;
  v4 = supportVecWorld->mVec128.m128_f32[1];
  v5 = supportVecWorld->mVec128.m128_f32[2];
  *(float *)&v9 = (float)((float)(this->m_worldTrans.m_basis.m_el[1].mVec128.m128_f32[0] * v4)
                        + (float)(this->m_worldTrans.m_basis.m_el[2].mVec128.m128_f32[0] * v5))
                + (float)(supportVecWorld->mVec128.m128_f32[0] * this->m_worldTrans.m_basis.m_el[0].mVec128.m128_f32[0]);
  *((float *)&v9 + 1) = (float)((float)(this->m_worldTrans.m_basis.m_el[0].mVec128.m128_f32[1]
                                      * supportVecWorld->mVec128.m128_f32[0])
                              + (float)(this->m_worldTrans.m_basis.m_el[1].mVec128.m128_f32[1] * v4))
                      + (float)(this->m_worldTrans.m_basis.m_el[2].mVec128.m128_f32[1] * v5);
  v6 = this->m_worldTrans.m_basis.m_el[0].mVec128.m128_f32[2] * supportVecWorld->mVec128.m128_f32[0];
  v7 = this->m_worldTrans.m_basis.m_el[1].mVec128.m128_f32[2] * v4;
  v8 = this->m_worldTrans.m_basis.m_el[2].mVec128.m128_f32[2];
  HIDWORD(v10) = 0;
  this->m_supportVecLocal.mVec128.m128_u64[0] = v9;
  *(float *)&v10 = (float)(v6 + v7) + (float)(v8 * v5);
  this->m_supportVecLocal.mVec128.m128_u64[1] = v10;
}
