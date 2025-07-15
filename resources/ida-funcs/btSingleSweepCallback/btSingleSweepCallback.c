btSingleSweepCallback *__userpurge btSingleSweepCallback::btSingleSweepCallback@<eax>(
        btSingleSweepCallback *this@<ecx>,
        int a2@<edx>,
        float a3@<xmm0>,
        const btConvexShape *castShape,
        const btTransform *convexFromTrans,
        const btCollisionWorld *world,
        btCollisionWorld::ConvexResultCallback *resultCallback,
        struct btCollisionWorld::ConvexResultCallback *a8,
        float a9)
{
  float v9; // xmm7_4
  float v10; // xmm3_4
  float v11; // xmm5_4
  float v12; // xmm4_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm7_4
  float v20; // [esp+18h] [ebp-18h]
  float v21; // [esp+28h] [ebp-8h]

  this->__vftable = (btSingleSweepCallback_vtbl *)&btSingleSweepCallback::`vftable';
  this->m_convexFromTrans = *convexFromTrans;
  this->m_convexToTrans.m_basis.m_el[0].mVec128.m128_u64[0] = *(_QWORD *)a2;
  this->m_convexToTrans.m_basis.m_el[0].mVec128.m128_u64[1] = *(_QWORD *)(a2 + 8);
  this->m_convexToTrans.m_basis.m_el[1] = *(btVector3 *)(a2 + 16);
  this->m_convexToTrans.m_basis.m_el[2] = *(btVector3 *)(a2 + 32);
  this->m_convexToTrans.m_origin.mVec128.m128_u64[0] = *(_QWORD *)(a2 + 48);
  this->m_convexToTrans.m_origin.mVec128.m128_i32[2] = *(_DWORD *)(a2 + 56);
  v9 = s_bm_current_air_resistance;
  this->m_convexToTrans.m_origin.mVec128.m128_i32[3] = *(_DWORD *)(a2 + 60);
  this->m_world = world;
  this->m_resultCallback = resultCallback;
  this->m_allowedCcdPenetration = a3;
  this->m_castShape = castShape;
  v10 = this->m_convexToTrans.m_origin.mVec128.m128_f32[0] - this->m_convexFromTrans.m_origin.mVec128.m128_f32[0];
  v11 = this->m_convexToTrans.m_origin.mVec128.m128_f32[2] - this->m_convexFromTrans.m_origin.mVec128.m128_f32[2];
  v12 = this->m_convexToTrans.m_origin.mVec128.m128_f32[1] - this->m_convexFromTrans.m_origin.mVec128.m128_f32[1];
  v13 = v9 / fsqrt((float)((float)(v10 * v10) + (float)(v11 * v11)) + (float)(v12 * v12));
  v14 = v13 * v10;
  v15 = v13 * v12;
  v21 = v13 * v11;
  if ( (float)(v13 * v10) == 0.0 )
    v16 = FLOAT_9_9999998e17;
  else
    v16 = v9 / v14;
  v20 = v16;
  this->m_rayDirectionInverse.mVec128.m128_f32[0] = v16;
  if ( v15 == 0.0 )
    v17 = FLOAT_9_9999998e17;
  else
    v17 = v9 / v15;
  this->m_rayDirectionInverse.mVec128.m128_f32[1] = v17;
  if ( v21 == 0.0 )
    v18 = FLOAT_9_9999998e17;
  else
    v18 = v9 / v21;
  this->m_rayDirectionInverse.mVec128.m128_f32[2] = v18;
  this->m_signs[0] = v20 < 0.0;
  this->m_signs[1] = v17 < 0.0;
  this->m_signs[2] = v18 < 0.0;
  this->m_lambda_max = (float)((float)(v14 * v10) + (float)(v21 * v11)) + (float)(v15 * v12);
  return this;
}
