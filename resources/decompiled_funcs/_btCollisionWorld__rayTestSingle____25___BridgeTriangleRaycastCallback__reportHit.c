void __thiscall btCollisionWorld::rayTestSingle_::_25_::BridgeTriangleRaycastCallback::reportHit(
        btCollisionWorld::rayTestSingle::__l25::BridgeTriangleRaycastCallback *this,
        const btVector3 *hitNormalLocal,
        float hitFraction,
        int partId,
        int triangleIndex)
{
  float v5; // xmm3_4
  float v6; // xmm4_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  btCollisionObject *m_collisionObject; // eax
  float v11; // xmm3_4
  float v12; // xmm4_4
  float v13; // xmm3_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  btCollisionWorld::RayResultCallback *m_resultCallback; // ecx
  _DWORD v17[2]; // [esp+C0h] [ebp-4Ch] BYREF
  char v18; // [esp+C8h] [ebp-44h]
  __m128i v19; // [esp+CCh] [ebp-40h] BYREF
  _DWORD v20[4]; // [esp+DCh] [ebp-30h] BYREF
  __m128i v21; // [esp+ECh] [ebp-20h]
  float v22; // [esp+FCh] [ebp-10h]

  v5 = this->m_colObjWorldTransform.m_basis.m_el[0].mVec128.m128_f32[1];
  v6 = this->m_colObjWorldTransform.m_basis.m_el[0].mVec128.m128_f32[2];
  v17[0] = partId;
  v7 = hitNormalLocal->mVec128.m128_f32[2];
  v8 = hitNormalLocal->mVec128.m128_f32[1];
  v9 = hitNormalLocal->mVec128.m128_f32[0];
  m_collisionObject = this->m_collisionObject;
  v11 = (float)((float)(v5 * v8) + (float)(v6 * v7))
      + (float)(hitNormalLocal->mVec128.m128_f32[0] * this->m_colObjWorldTransform.m_basis.m_el[0].mVec128.m128_f32[0]);
  v12 = this->m_colObjWorldTransform.m_basis.m_el[1].mVec128.m128_f32[2];
  *(float *)v19.m128i_i32 = v11;
  *(float *)&v19.m128i_i32[1] = (float)((float)(this->m_colObjWorldTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v8)
                                      + (float)(v12 * v7))
                              + (float)(this->m_colObjWorldTransform.m_basis.m_el[1].mVec128.m128_f32[0] * v9);
  v13 = this->m_colObjWorldTransform.m_basis.m_el[2].mVec128.m128_f32[1] * v8;
  v14 = this->m_colObjWorldTransform.m_basis.m_el[2].mVec128.m128_f32[2] * v7;
  v15 = this->m_colObjWorldTransform.m_basis.m_el[2].mVec128.m128_f32[0];
  m_resultCallback = this->m_resultCallback;
  v17[1] = triangleIndex;
  v19.m128i_i64[1] = COERCE_UNSIGNED_INT((float)(v13 + v14) + (float)(v15 * v9));
  v21 = _mm_load_si128(&v19);
  v20[0] = m_collisionObject;
  v20[1] = v17;
  v18 = 0;
  v22 = hitFraction;
  m_resultCallback->addSingleResult(m_resultCallback, (btCollisionWorld::LocalRayResult *)v20, 1);
}
