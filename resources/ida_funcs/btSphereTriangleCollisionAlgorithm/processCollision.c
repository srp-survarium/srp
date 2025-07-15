void __thiscall btSphereTriangleCollisionAlgorithm::processCollision(
        btSphereTriangleCollisionAlgorithm *this,
        btCollisionObject *col0,
        btCollisionObject *col1,
        const btDispatcherInfo *dispatchInfo,
        btManifoldResult *resultOut)
{
  bool m_swapped; // dl
  btCollisionObject *v7; // eax
  btCollisionObject *v8; // ecx
  btTriangleShape *m_collisionShape; // edi
  btPersistentManifold *m_manifoldPtr; // ebx
  btIDebugDraw *m_debugDraw; // edx
  unsigned __int64 v12; // xmm0_8
  btPersistentManifold *v13; // eax
  bool v14; // [esp+1D0h] [ebp-B4h]
  btPersistentManifold *v15; // [esp+1D0h] [ebp-B4h]
  SphereTriangleDetector v16; // [esp+1E4h] [ebp-A0h] BYREF
  btDiscreteCollisionDetectorInterface::ClosestPointInput v17; // [esp+1F4h] [ebp-90h] BYREF

  if ( this->m_manifoldPtr )
  {
    m_swapped = this->m_swapped;
    v7 = col0;
    v8 = col1;
    if ( !m_swapped )
    {
      v8 = col0;
      v7 = col1;
    }
    m_collisionShape = (btTriangleShape *)v7->m_collisionShape;
    m_manifoldPtr = this->m_manifoldPtr;
    v16.m_sphere = (btSphereShape *)v8->m_collisionShape;
    resultOut->m_manifoldPtr = m_manifoldPtr;
    v16.m_triangle = m_collisionShape;
    v16.m_contactBreakingThreshold = this->m_manifoldPtr->m_contactBreakingThreshold;
    v17.m_maximumDistanceSquared = 9.9999998e17;
    v17.m_transformA.m_basis.m_el[0].mVec128.m128_u64[0] = v8->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[0];
    v17.m_transformA.m_basis.m_el[0].mVec128.m128_u64[1] = v8->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[1];
    v17.m_transformA.m_basis.m_el[1] = v8->m_worldTransform.m_basis.m_el[1];
    v17.m_transformA.m_basis.m_el[2] = v8->m_worldTransform.m_basis.m_el[2];
    v17.m_transformA.m_origin.mVec128.m128_u64[0] = v8->m_worldTransform.m_origin.mVec128.m128_u64[0];
    m_debugDraw = dispatchInfo->m_debugDraw;
    v17.m_transformA.m_origin.mVec128.m128_u64[1] = v8->m_worldTransform.m_origin.mVec128.m128_u64[1];
    v17.m_transformB.m_basis.m_el[0].mVec128.m128_u64[0] = v7->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[0];
    v17.m_transformB.m_basis.m_el[0].mVec128.m128_u64[1] = v7->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[1];
    v17.m_transformB.m_basis.m_el[1] = v7->m_worldTransform.m_basis.m_el[1];
    v17.m_transformB.m_basis.m_el[2] = v7->m_worldTransform.m_basis.m_el[2];
    v17.m_transformB.m_origin.mVec128.m128_u64[0] = v7->m_worldTransform.m_origin.mVec128.m128_u64[0];
    v12 = v7->m_worldTransform.m_origin.mVec128.m128_u64[1];
    v14 = this->m_swapped;
    v16.__vftable = (SphereTriangleDetector_vtbl *)&SphereTriangleDetector::`vftable';
    v17.m_stackAlloc = 0;
    v17.m_transformB.m_origin.mVec128.m128_u64[1] = v12;
    SphereTriangleDetector::getClosestPoints(&v16, &v17, resultOut, m_debugDraw, v14);
    if ( this->m_ownManifold )
    {
      v13 = resultOut->m_manifoldPtr;
      if ( v13->m_cachedPoints )
      {
        v15 = resultOut->m_manifoldPtr;
        if ( v13->m_body0 == resultOut->m_body0 )
          btPersistentManifold::refreshContactPoints(v15, &resultOut->m_rootTransA, &resultOut->m_rootTransB);
        else
          btPersistentManifold::refreshContactPoints(v15, &resultOut->m_rootTransB, &resultOut->m_rootTransA);
      }
    }
  }
}
