void __userpurge btConvexTriangleCallback::setTimeStepAndCounters(
        const btDispatcherInfo *dispatchInfo@<eax>,
        btManifoldResult *resultOut@<ecx>,
        btConvexTriangleCallback *this,
        float collisionMarginTriangle)
{
  float *m_convexBody; // esi
  btCollisionObject *m_triBody; // ecx
  float *v6; // eax
  float v7; // xmm5_4
  float v8; // xmm3_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm4_4
  float v12; // xmm1_4
  float v13; // xmm7_4
  float v14; // xmm6_4
  float v15; // xmm7_4
  float v16; // xmm3_4
  int v17; // xmm6_4
  float v18; // xmm7_4
  unsigned int v19; // xmm6_4
  float v20; // xmm3_4
  float v21; // xmm5_4
  float v22; // xmm4_4
  unsigned int v23; // xmm3_4
  unsigned int v24; // xmm4_4
  unsigned int v25; // xmm5_4
  btCollisionObject *v26; // edx
  float v27; // [esp+44h] [ebp-C4h]
  float v28; // [esp+50h] [ebp-B8h]
  float v29; // [esp+54h] [ebp-B4h]
  float v30; // [esp+58h] [ebp-B0h]
  float v31; // [esp+5Ch] [ebp-ACh]
  float v32; // [esp+60h] [ebp-A8h]
  float v33; // [esp+64h] [ebp-A4h]
  unsigned __int64 v34; // [esp+6Ch] [ebp-9Ch]
  unsigned int v35; // [esp+74h] [ebp-94h]
  __m128i v36; // [esp+78h] [ebp-90h] BYREF
  btTransform v37; // [esp+88h] [ebp-80h] BYREF
  _OWORD v38[4]; // [esp+C8h] [ebp-40h] BYREF

  m_convexBody = (float *)this->m_convexBody;
  this->m_resultOut = resultOut;
  m_triBody = this->m_triBody;
  this->m_dispatchInfoPtr = dispatchInfo;
  this->m_collisionMarginTriangle = collisionMarginTriangle;
  m_convexBody += 4;
  v6 = (float *)btTransform::inverse(&m_triBody->m_worldTransform, &v37);
  v7 = m_convexBody[13];
  v8 = m_convexBody[12];
  v9 = v6[1];
  v10 = *v6;
  v11 = m_convexBody[14];
  v12 = v6[2];
  v13 = v6[6];
  *(float *)v36.m128i_i32 = (float)((float)((float)(*v6 * v8) + (float)(v9 * v7)) + (float)(v12 * v11)) + v6[12];
  v14 = (float)(v6[5] * v7) + (float)(v13 * v11);
  v15 = v8 * v6[4];
  v16 = v8 * v6[8];
  *(float *)&v17 = (float)(v14 + v15) + v6[13];
  v18 = m_convexBody[1];
  v36.m128i_i32[1] = v17;
  *(float *)&v19 = (float)((float)((float)(v6[9] * v7) + (float)(v6[10] * v11)) + v16) + v6[14];
  v20 = v6[9] * m_convexBody[6];
  v30 = m_convexBody[6];
  v21 = v6[10] * m_convexBody[10];
  v29 = m_convexBody[10];
  v22 = v6[8];
  v36.m128i_i64[1] = v19;
  v27 = m_convexBody[2];
  *(float *)&v23 = (float)(v20 + v21) + (float)(v22 * v27);
  v31 = m_convexBody[5];
  v33 = m_convexBody[9];
  *(float *)&v24 = (float)((float)(v6[9] * v31) + (float)(v6[10] * v33)) + (float)(v6[8] * v18);
  v32 = m_convexBody[8];
  v28 = m_convexBody[4];
  *(float *)&v25 = (float)((float)(v6[9] * v28) + (float)(v6[10] * v32)) + (float)(*m_convexBody * v6[8]);
  *(float *)&v35 = (float)((float)(v6[5] * v30) + (float)(v6[6] * v29)) + (float)(v27 * v6[4]);
  *((float *)&v34 + 1) = (float)((float)(v6[5] * v31) + (float)(v6[6] * v33)) + (float)(v18 * v6[4]);
  *(float *)&v34 = (float)((float)(v6[5] * v28) + (float)(v6[6] * v32)) + (float)(*m_convexBody * v6[4]);
  v37.m_basis.m_el[0].mVec128.m128_f32[0] = (float)((float)(v10 * *m_convexBody) + (float)(v9 * v28))
                                          + (float)(v12 * v32);
  v37.m_basis.m_el[1].mVec128.m128_u64[0] = v34;
  v37.m_basis.m_el[0].mVec128.m128_u64[1] = COERCE_UNSIGNED_INT((float)((float)(v10 * v27) + (float)(v9 * v30)) + (float)(v12 * v29));
  v37.m_basis.m_el[0].mVec128.m128_f32[1] = (float)((float)(v10 * v18) + (float)(v9 * v31)) + (float)(v12 * v33);
  v26 = this->m_convexBody;
  v38[0] = _mm_load_si128((const __m128i *)&v37);
  v37.m_basis.m_el[1].mVec128.m128_u64[1] = v35;
  v38[1] = _mm_load_si128((const __m128i *)&v37.m_basis.m_el[1]);
  v37.m_basis.m_el[2].mVec128.m128_u64[0] = __PAIR64__(v24, v25);
  v37.m_basis.m_el[2].mVec128.m128_u64[1] = v23;
  v38[2] = _mm_load_si128((const __m128i *)&v37.m_basis.m_el[2]);
  v38[3] = _mm_load_si128(&v36);
  v26->m_collisionShape->getAabb(v26->m_collisionShape, (const btTransform *)v38, &this->m_aabbMin, &this->m_aabbMax);
  this->m_aabbMax.mVec128.m128_f32[0] = this->m_aabbMax.mVec128.m128_f32[0] + collisionMarginTriangle;
  this->m_aabbMax.mVec128.m128_f32[1] = collisionMarginTriangle + this->m_aabbMax.mVec128.m128_f32[1];
  this->m_aabbMax.mVec128.m128_f32[2] = collisionMarginTriangle + this->m_aabbMax.mVec128.m128_f32[2];
  this->m_aabbMin.mVec128.m128_f32[0] = this->m_aabbMin.mVec128.m128_f32[0] - collisionMarginTriangle;
  this->m_aabbMin.mVec128.m128_f32[1] = this->m_aabbMin.mVec128.m128_f32[1] - collisionMarginTriangle;
  this->m_aabbMin.mVec128.m128_f32[2] = this->m_aabbMin.mVec128.m128_f32[2] - collisionMarginTriangle;
}
