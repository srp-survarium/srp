void __thiscall btCollisionWorld::rayTestSingle_::_33_::BridgeTriangleRaycastCallback::reportHit(
        btCollisionWorld::rayTestSingle::__l33::BridgeTriangleRaycastCallback *this,
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
  _DWORD v17[2]; // [esp+14h] [ebp-4Ch] BYREF
  char v18; // [esp+1Ch] [ebp-44h]
  float v19; // [esp+20h] [ebp-40h]
  float v20; // [esp+24h] [ebp-3Ch]
  float v21; // [esp+28h] [ebp-38h]
  int v22; // [esp+2Ch] [ebp-34h]
  _DWORD v23[12]; // [esp+30h] [ebp-30h] BYREF

  v5 = this->m_colObjWorldTransform.m_basis.m_el[0].mVec128.m128_f32[1];
  v6 = this->m_colObjWorldTransform.m_basis.m_el[0].mVec128.m128_f32[2];
  v17[0] = partId;
  v17[1] = triangleIndex;
  v7 = hitNormalLocal->mVec128.m128_f32[2];
  v8 = hitNormalLocal->mVec128.m128_f32[1];
  v9 = hitNormalLocal->mVec128.m128_f32[0];
  m_collisionObject = this->m_collisionObject;
  v11 = (float)((float)(v5 * v8) + (float)(v6 * v7))
      + (float)(hitNormalLocal->mVec128.m128_f32[0] * this->m_colObjWorldTransform.m_basis.m_el[0].mVec128.m128_f32[0]);
  v12 = this->m_colObjWorldTransform.m_basis.m_el[1].mVec128.m128_f32[2];
  v19 = v11;
  v20 = (float)((float)(this->m_colObjWorldTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v8) + (float)(v12 * v7))
      + (float)(this->m_colObjWorldTransform.m_basis.m_el[1].mVec128.m128_f32[0] * v9);
  v13 = this->m_colObjWorldTransform.m_basis.m_el[2].mVec128.m128_f32[1] * v8;
  v14 = this->m_colObjWorldTransform.m_basis.m_el[2].mVec128.m128_f32[2] * v7;
  v15 = this->m_colObjWorldTransform.m_basis.m_el[2].mVec128.m128_f32[0];
  m_resultCallback = this->m_resultCallback;
  v23[0] = m_collisionObject;
  v22 = 0;
  v21 = (float)(v13 + v14) + (float)(v15 * v9);
  v23[1] = v17;
  *(float *)&v23[4] = v19;
  *(float *)&v23[5] = v20;
  *(float *)&v23[6] = v21;
  v23[7] = 0;
  v18 = 0;
  *(float *)&v23[8] = hitFraction;
  m_resultCallback->addSingleResult(m_resultCallback, (btCollisionWorld::LocalRayResult *)v23, 1);
}
