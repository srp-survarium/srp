void __thiscall btBoxBoxCollisionAlgorithm::processCollision(
        btBoxBoxCollisionAlgorithm *this,
        btCollisionObject *body0,
        btCollisionObject *body1,
        const btDispatcherInfo *dispatchInfo,
        btManifoldResult *resultOut)
{
  btPersistentManifold *m_manifoldPtr; // ebx
  btBoxShape *m_collisionShape; // edx
  btBoxShape *v7; // edi
  unsigned __int64 v8; // xmm0_8
  btPersistentManifold *v9; // eax
  btIDebugDraw *m_debugDraw; // [esp+124h] [ebp-B8h]
  btPersistentManifold *v11; // [esp+128h] [ebp-B4h]
  btBoxBoxDetector v13; // [esp+140h] [ebp-9Ch] BYREF
  btDiscreteCollisionDetectorInterface::ClosestPointInput v14; // [esp+14Ch] [ebp-90h] BYREF

  m_manifoldPtr = this->m_manifoldPtr;
  if ( m_manifoldPtr )
  {
    m_collisionShape = (btBoxShape *)body0->m_collisionShape;
    v7 = (btBoxShape *)body1->m_collisionShape;
    resultOut->m_manifoldPtr = m_manifoldPtr;
    v14.m_maximumDistanceSquared = 9.9999998e17;
    v14.m_transformA = body0->m_worldTransform;
    v14.m_transformB.m_basis.m_el[0].mVec128.m128_u64[0] = body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[0];
    v14.m_transformB.m_basis.m_el[0].mVec128.m128_u64[1] = body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[1];
    v14.m_transformB.m_basis.m_el[1] = body1->m_worldTransform.m_basis.m_el[1];
    v14.m_transformB.m_basis.m_el[2] = body1->m_worldTransform.m_basis.m_el[2];
    v14.m_transformB.m_origin.mVec128.m128_u64[0] = body1->m_worldTransform.m_origin.mVec128.m128_u64[0];
    v8 = body1->m_worldTransform.m_origin.mVec128.m128_u64[1];
    m_debugDraw = dispatchInfo->m_debugDraw;
    v13.m_box1 = m_collisionShape;
    v14.m_stackAlloc = 0;
    v14.m_transformB.m_origin.mVec128.m128_u64[1] = v8;
    v13.__vftable = (btBoxBoxDetector_vtbl *)&btBoxBoxDetector::`vftable';
    v13.m_box2 = v7;
    btBoxBoxDetector::getClosestPoints(&v13, &v14, resultOut, m_debugDraw, 0);
    if ( this->m_ownManifold )
    {
      v9 = resultOut->m_manifoldPtr;
      if ( v9->m_cachedPoints )
      {
        v11 = resultOut->m_manifoldPtr;
        if ( v9->m_body0 == resultOut->m_body0 )
          btPersistentManifold::refreshContactPoints(v11, &resultOut->m_rootTransA, &resultOut->m_rootTransB);
        else
          btPersistentManifold::refreshContactPoints(v11, &resultOut->m_rootTransB, &resultOut->m_rootTransA);
      }
    }
  }
}
