double __thiscall btCollisionWorld::objectQuerySingle_::_39_::BridgeTriangleConvexcastCallback::reportHit(
        btCollisionWorld::objectQuerySingle::__l39::BridgeTriangleConvexcastCallback *this,
        const btVector3 *hitNormalLocal,
        const btVector3 *hitPointLocal,
        float hitFraction,
        int partId,
        int triangleIndex)
{
  btCollisionWorld::ConvexResultCallback *m_resultCallback; // eax
  btCollisionObject *m_collisionObject; // edx
  btCollisionWorld::ConvexResultCallback *v8; // ecx
  unsigned __int64 v9; // xmm1_8
  double result; // st7
  _DWORD v11[2]; // [esp+90h] [ebp-4Ch] BYREF
  char v12; // [esp+98h] [ebp-44h]
  _DWORD v13[4]; // [esp+9Ch] [ebp-40h] BYREF
  btVector3 v14; // [esp+ACh] [ebp-30h]
  unsigned __int64 v15; // [esp+BCh] [ebp-20h]
  unsigned __int64 v16; // [esp+C4h] [ebp-18h]
  float v17; // [esp+CCh] [ebp-10h]

  v11[0] = partId;
  m_resultCallback = this->m_resultCallback;
  v11[1] = triangleIndex;
  v12 = 0;
  if ( m_resultCallback->m_closestHitFraction < hitFraction )
    return hitFraction;
  m_collisionObject = this->m_collisionObject;
  v8 = this->m_resultCallback;
  v13[1] = v11;
  v14.mVec128 = hitNormalLocal->mVec128;
  v15 = hitPointLocal->mVec128.m128_u64[0];
  v9 = hitPointLocal->mVec128.m128_u64[1];
  v13[0] = m_collisionObject;
  v16 = v9;
  v17 = hitFraction;
  v8->addSingleResult(v8, (btCollisionWorld::LocalConvexResult *)v13, 0);
  return result;
}
