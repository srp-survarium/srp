void __thiscall btCollisionWorld::convexSweepTest(
        btCollisionWorld *this,
        const btCollisionWorld *castShape,
        btConvexShape *convexFromWorld,
        const btTransform *convexToWorld,
        btCollisionWorld::ConvexResultCallback *resultCallback,
        btCollisionWorld::ConvexResultCallback *allowedCcdPenetration,
        float a7)
{
  btMatrix3x3 *v7; // ecx
  btVector3 *v8; // [esp+Ch] [ebp-1F0h]
  struct btCollisionWorld::ConvexResultCallback *v9; // [esp+Ch] [ebp-1F0h]
  float v10; // [esp+10h] [ebp-1ECh]
  btVector3 v11; // [esp+1Ch] [ebp-1E0h] BYREF
  btQuaternion q; // [esp+2Ch] [ebp-1D0h] BYREF
  btVector3 v13; // [esp+3Ch] [ebp-1C0h] BYREF
  btVector3 v14; // [esp+4Ch] [ebp-1B0h] BYREF
  btVector3 v15; // [esp+5Ch] [ebp-1A0h] BYREF
  btTransform v16; // [esp+6Ch] [ebp-190h] BYREF
  btTransform v17; // [esp+ACh] [ebp-150h] BYREF
  btTransform v18; // [esp+ECh] [ebp-110h] BYREF
  btSingleSweepCallback v19; // [esp+12Ch] [ebp-D0h] BYREF

  v17 = *convexToWorld;
  v18.m_basis.m_el[0].mVec128.m128_u64[0] = *(_QWORD *)&resultCallback->__vftable;
  v18.m_basis.m_el[0].mVec128.m128_u64[1] = *(_QWORD *)&resultCallback->m_collisionFilterGroup;
  v18.m_basis.m_el[1] = *(btVector3 *)&resultCallback[1].m_closestHitFraction;
  v18.m_basis.m_el[2] = *(btVector3 *)&resultCallback[2].m_collisionFilterGroup;
  v18.m_origin.mVec128.m128_u64[0] = *(_QWORD *)&resultCallback[4].__vftable;
  v18.m_origin.mVec128.m128_u64[1] = *(_QWORD *)&resultCallback[4].m_collisionFilterGroup;
  btTransformUtil::calculateVelocity(&v17, &v18, 1.0, (btVector3 *)&q, &v15);
  memset(&v11, 0, sizeof(v11));
  btMatrix3x3::setIdentity(v7, (int)&v16);
  memset(&v16.m_origin, 0, sizeof(v16.m_origin));
  btMatrix3x3::getRotation(&v17.m_basis, &q);
  btMatrix3x3::setRotation(&q, &v16.m_basis);
  btCollisionShape::calculateTemporalAabb(&v11, convexFromWorld, &v16, &v15, &v13, &v14, v8);
  btSingleSweepCallback::btSingleSweepCallback(
    &v19,
    (int)resultCallback,
    a7,
    convexFromWorld,
    convexToWorld,
    castShape,
    allowedCcdPenetration,
    v9,
    v10);
  castShape->m_broadphasePairCache->rayTest(
    castShape->m_broadphasePairCache,
    &v17.m_origin,
    &v18.m_origin,
    &v19,
    &v13,
    &v14);
}
