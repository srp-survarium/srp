double __thiscall btCollisionWorld::objectQuerySingle_::_22_::BridgeTriangleConvexcastCallback::reportHit(
        btCollisionWorld::objectQuerySingle::__l22::BridgeTriangleConvexcastCallback *this,
        const btVector3 *hitNormalLocal,
        const btVector3 *hitPointLocal,
        float hitFraction,
        int partId,
        int triangleIndex)
{
  btCollisionWorld::ConvexResultCallback *m_resultCallback; // eax
  btCollisionWorld::ConvexResultCallback *v7; // ecx
  double result; // st7
  _DWORD v9[2]; // [esp+Ch] [ebp-4Ch] BYREF
  char v10; // [esp+14h] [ebp-44h]
  _DWORD v11[4]; // [esp+18h] [ebp-40h] BYREF
  unsigned __int64 v12; // [esp+28h] [ebp-30h]
  unsigned __int64 v13; // [esp+30h] [ebp-28h]
  btVector3 v14; // [esp+38h] [ebp-20h]
  float v15; // [esp+48h] [ebp-10h]

  v9[0] = partId;
  v9[1] = triangleIndex;
  m_resultCallback = this->m_resultCallback;
  v10 = 0;
  if ( m_resultCallback->m_closestHitFraction < hitFraction )
    return hitFraction;
  v11[0] = this->m_collisionObject;
  v11[1] = v9;
  v12 = hitNormalLocal->mVec128.m128_u64[0];
  v7 = this->m_resultCallback;
  v13 = hitNormalLocal->mVec128.m128_u64[1];
  v14.mVec128 = hitPointLocal->mVec128;
  v15 = hitFraction;
  v7->addSingleResult(v7, (btCollisionWorld::LocalConvexResult *)v11, 1);
  return result;
}
