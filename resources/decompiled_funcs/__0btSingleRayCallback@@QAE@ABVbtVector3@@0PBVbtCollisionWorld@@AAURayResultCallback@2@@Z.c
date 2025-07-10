void __userpurge btSingleRayCallback::btSingleRayCallback(
        btSingleRayCallback *this@<esi>,
        const btVector3 *rayFromWorld@<ecx>,
        const btVector3 *rayToWorld@<eax>,
        const btCollisionWorld *world,
        btCollisionWorld::RayResultCallback *resultCallback)
{
  const vostok::math::float4x4 *v5; // xmm1_4
  float v6; // xmm1_4
  const vostok::math::float4x4 *v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm4_4
  float v10; // xmm5_4
  float v11; // xmm6_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // [esp+1Ch] [ebp-14h]
  float v15; // [esp+20h] [ebp-10h]
  float v16; // [esp+28h] [ebp-8h]

  this->__vftable = (btSingleRayCallback_vtbl *)&btSingleRayCallback::`vftable';
  this->m_rayFromWorld = (btVector3)rayFromWorld->mVec128;
  this->m_rayToWorld = (btVector3)rayToWorld->mVec128;
  v5 = clear_value;
  this->m_world = world;
  this->m_resultCallback = resultCallback;
  this->m_rayFromTrans.m_basis.m_el[0].mVec128.m128_u64[0] = (unsigned int)v5;
  this->m_rayFromTrans.m_basis.m_el[0].mVec128.m128_u64[1] = 0;
  this->m_rayFromTrans.m_basis.m_el[1].mVec128.m128_i32[0] = 0;
  *(unsigned __int64 *)((char *)this->m_rayFromTrans.m_basis.m_el[1].mVec128.m128_u64 + 4) = (unsigned int)v5;
  this->m_rayFromTrans.m_basis.m_el[1].mVec128.m128_i32[3] = 0;
  this->m_rayFromTrans.m_basis.m_el[2].mVec128.m128_u64[0] = 0;
  this->m_rayFromTrans.m_basis.m_el[2].mVec128.m128_u64[1] = (unsigned int)v5;
  this->m_rayFromTrans.m_origin.mVec128.m128_u64[0] = 0;
  this->m_rayFromTrans.m_origin.mVec128.m128_u64[1] = 0;
  this->m_rayFromTrans.m_origin = this->m_rayFromWorld;
  this->m_rayToTrans.m_basis.m_el[0].mVec128.m128_u64[0] = (unsigned int)v5;
  this->m_rayToTrans.m_basis.m_el[0].mVec128.m128_u64[1] = 0;
  this->m_rayToTrans.m_basis.m_el[1].mVec128.m128_i32[0] = 0;
  *(unsigned __int64 *)((char *)this->m_rayToTrans.m_basis.m_el[1].mVec128.m128_u64 + 4) = (unsigned int)v5;
  this->m_rayToTrans.m_basis.m_el[1].mVec128.m128_i32[3] = 0;
  this->m_rayToTrans.m_basis.m_el[2].mVec128.m128_u64[0] = 0;
  this->m_rayToTrans.m_basis.m_el[2].mVec128.m128_u64[1] = (unsigned int)v5;
  this->m_rayToTrans.m_origin.mVec128.m128_u64[0] = 0;
  this->m_rayToTrans.m_origin.mVec128.m128_u64[1] = 0;
  this->m_rayToTrans.m_origin = this->m_rayToWorld;
  v6 = rayToWorld->mVec128.m128_f32[1] - rayFromWorld->mVec128.m128_f32[1];
  v15 = rayToWorld->mVec128.m128_f32[0] - rayFromWorld->mVec128.m128_f32[0];
  v16 = rayToWorld->mVec128.m128_f32[2] - rayFromWorld->mVec128.m128_f32[2];
  v14 = 1.0 / sqrtf((float)((float)(v6 * v6) + (float)(v15 * v15)) + (float)(v16 * v16));
  v7 = clear_value;
  v8 = v15 * v14;
  v9 = v6 * v14;
  v10 = v16 * v14;
  if ( (float)(v15 * v14) == 0.0 )
    v11 = 9.9999998e17;
  else
    v11 = *(float *)&clear_value / v8;
  this->m_rayDirectionInverse.mVec128.m128_f32[0] = v11;
  if ( v9 == 0.0 )
    v12 = 9.9999998e17;
  else
    v12 = *(float *)&v7 / v9;
  this->m_rayDirectionInverse.mVec128.m128_f32[1] = v12;
  if ( v10 == 0.0 )
    v13 = 9.9999998e17;
  else
    v13 = *(float *)&v7 / v10;
  this->m_rayDirectionInverse.mVec128.m128_f32[2] = v13;
  this->m_signs[0] = v11 < 0.0;
  this->m_signs[1] = v12 < 0.0;
  this->m_signs[2] = v13 < 0.0;
  this->m_lambda_max = (float)((float)((float)(this->m_rayToWorld.mVec128.m128_f32[1]
                                             - this->m_rayFromWorld.mVec128.m128_f32[1])
                                     * v9)
                             + (float)((float)(this->m_rayToWorld.mVec128.m128_f32[0]
                                             - this->m_rayFromWorld.mVec128.m128_f32[0])
                                     * v8))
                     + (float)((float)(this->m_rayToWorld.mVec128.m128_f32[2] - this->m_rayFromWorld.mVec128.m128_f32[2])
                             * v10);
}
