void __stdcall btSoftSingleRayCallback::btSoftSingleRayCallback(
        btSoftSingleRayCallback *this,
        const btVector3 *rayFromWorld,
        const btVector3 *rayToWorld,
        btCollisionWorld::RayResultCallback *resultCallback)
{
  const btSoftRigidDynamicsWorld *v4; // eax
  btMatrix3x3 *v5; // ecx
  btMatrix3x3 *v6; // ecx
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm4_4
  float v10; // xmm5_4
  float v11; // xmm6_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm6_4
  float v16; // xmm4_4
  float v17; // xmm5_4

  this->__vftable = (btSoftSingleRayCallback_vtbl *)&btSoftSingleRayCallback::`vftable';
  this->m_rayFromWorld = (btVector3)rayFromWorld->mVec128;
  this->m_rayToWorld = (btVector3)rayToWorld->mVec128;
  this->m_world = v4;
  this->m_resultCallback = resultCallback;
  btMatrix3x3::setIdentity(v5, (int)&this->m_rayFromTrans);
  this->m_rayFromTrans.m_origin.mVec128.m128_u64[0] = 0;
  this->m_rayFromTrans.m_origin.mVec128.m128_u64[1] = 0;
  this->m_rayFromTrans.m_origin = this->m_rayFromWorld;
  btMatrix3x3::setIdentity(v6, (int)&this->m_rayToTrans);
  this->m_rayToTrans.m_origin.mVec128.m128_u64[0] = 0;
  this->m_rayToTrans.m_origin.mVec128.m128_u64[1] = 0;
  this->m_rayToTrans.m_origin = this->m_rayToWorld;
  v7 = rayToWorld->mVec128.m128_f32[0] - rayFromWorld->mVec128.m128_f32[0];
  v8 = rayToWorld->mVec128.m128_f32[1] - rayFromWorld->mVec128.m128_f32[1];
  v9 = rayToWorld->mVec128.m128_f32[2] - rayFromWorld->mVec128.m128_f32[2];
  v10 = s_bm_current_air_resistance;
  v11 = fsqrt((float)((float)(v8 * v8) + (float)(v7 * v7)) + (float)(v9 * v9));
  v12 = v7 * (float)(s_bm_current_air_resistance / v11);
  v13 = v8 * (float)(s_bm_current_air_resistance / v11);
  v14 = (float)(s_bm_current_air_resistance / v11) * v9;
  if ( v12 == 0.0 )
    v15 = FLOAT_1_0e30;
  else
    v15 = s_bm_current_air_resistance / v12;
  this->m_rayDirectionInverse.mVec128.m128_f32[0] = v15;
  if ( v13 == 0.0 )
    v16 = FLOAT_1_0e30;
  else
    v16 = v10 / v13;
  this->m_rayDirectionInverse.mVec128.m128_f32[1] = v16;
  if ( v14 == 0.0 )
    v17 = FLOAT_1_0e30;
  else
    v17 = v10 / v14;
  this->m_rayDirectionInverse.mVec128.m128_f32[2] = v17;
  this->m_signs[0] = v15 < 0.0;
  this->m_signs[1] = v16 < 0.0;
  this->m_signs[2] = v17 < 0.0;
  this->m_lambda_max = (float)((float)((float)(this->m_rayToWorld.mVec128.m128_f32[1]
                                             - this->m_rayFromWorld.mVec128.m128_f32[1])
                                     * v13)
                             + (float)((float)(this->m_rayToWorld.mVec128.m128_f32[0]
                                             - this->m_rayFromWorld.mVec128.m128_f32[0])
                                     * v12))
                     + (float)((float)(this->m_rayToWorld.mVec128.m128_f32[2] - this->m_rayFromWorld.mVec128.m128_f32[2])
                             * v14);
}
