void __userpurge btSingleSweepCallback::btSingleSweepCallback(
        btSingleSweepCallback *this@<esi>,
        const btTransform *convexFromTrans@<ecx>,
        const btTransform *convexToTrans@<eax>,
        const btConvexShape *castShape,
        const btCollisionWorld *world,
        btCollisionWorld::ConvexResultCallback *resultCallback,
        float allowedPenetration)
{
  float v7; // xmm2_4
  long double v8; // st7
  const vostok::math::float4x4 *v9; // xmm6_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm5_4
  float v14; // xmm4_4
  float v15; // xmm6_4
  float v16; // [esp+1Ch] [ebp-14h]
  float v17; // [esp+20h] [ebp-10h]
  float v18; // [esp+24h] [ebp-Ch]
  float v19; // [esp+28h] [ebp-8h]

  this->__vftable = (btSingleSweepCallback_vtbl *)&btSingleSweepCallback::`vftable';
  this->m_convexFromTrans = *convexFromTrans;
  this->m_convexToTrans = *convexToTrans;
  this->m_allowedCcdPenetration = allowedPenetration;
  this->m_world = world;
  this->m_resultCallback = resultCallback;
  this->m_castShape = castShape;
  v7 = this->m_convexToTrans.m_origin.mVec128.m128_f32[2] - this->m_convexFromTrans.m_origin.mVec128.m128_f32[2];
  v17 = this->m_convexToTrans.m_origin.mVec128.m128_f32[0] - this->m_convexFromTrans.m_origin.mVec128.m128_f32[0];
  v18 = this->m_convexToTrans.m_origin.mVec128.m128_f32[1] - this->m_convexFromTrans.m_origin.mVec128.m128_f32[1];
  v19 = v7;
  v8 = sqrtf((float)((float)(v17 * v17) + (float)(v7 * v7)) + (float)(v18 * v18));
  v9 = clear_value;
  v16 = 1.0 / v8;
  v10 = v16 * v17;
  v11 = v16 * v18;
  v12 = v16 * v19;
  if ( (float)(v16 * v17) == 0.0 )
    v13 = 9.9999998e17;
  else
    v13 = *(float *)&clear_value / v10;
  this->m_rayDirectionInverse.mVec128.m128_f32[0] = v13;
  if ( v11 == 0.0 )
    v14 = 9.9999998e17;
  else
    v14 = *(float *)&v9 / v11;
  this->m_rayDirectionInverse.mVec128.m128_f32[1] = v14;
  if ( v12 == 0.0 )
    v15 = 9.9999998e17;
  else
    v15 = *(float *)&v9 / v12;
  this->m_rayDirectionInverse.mVec128.m128_f32[2] = v15;
  this->m_signs[0] = v13 < 0.0;
  this->m_signs[1] = v14 < 0.0;
  this->m_signs[2] = v15 < 0.0;
  this->m_lambda_max = (float)((float)(v10 * v17) + (float)(v12 * v19)) + (float)(v11 * v18);
}
