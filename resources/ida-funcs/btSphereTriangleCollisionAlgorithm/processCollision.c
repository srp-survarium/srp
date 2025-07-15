void __thiscall btSphereTriangleCollisionAlgorithm::processCollision(
        btSphereTriangleCollisionAlgorithm *this,
        btCollisionObject *col0,
        btCollisionObject *col1,
        const btDispatcherInfo *dispatchInfo,
        btManifoldResult *resultOut)
{
  bool m_swapped; // al
  btCollisionObject *v7; // ecx
  btCollisionObject *v8; // edx
  btPersistentManifold *m_manifoldPtr; // edi
  btSphereShape *m_collisionShape; // eax
  btTriangleShape *v11; // esi
  btPersistentManifold *v12; // esi
  btTransform *p_m_rootTransB; // ecx
  btTransform *p_m_rootTransA; // edx
  btIDebugDraw *m_debugDraw; // [esp-8h] [ebp-B8h]
  btCollisionObject *v16; // [esp+Ch] [ebp-A4h]
  SphereTriangleDetector v17; // [esp+10h] [ebp-A0h] BYREF
  btDiscreteCollisionDetectorInterface::ClosestPointInput input; // [esp+20h] [ebp-90h] BYREF

  if ( this->m_manifoldPtr )
  {
    m_swapped = this->m_swapped;
    v7 = col0;
    if ( m_swapped )
    {
      v8 = col1;
      v16 = col1;
    }
    else
    {
      v8 = col0;
      v16 = col0;
    }
    m_manifoldPtr = this->m_manifoldPtr;
    if ( !m_swapped )
      v7 = col1;
    input.m_stackAlloc = 0;
    m_collisionShape = (btSphereShape *)v8->m_collisionShape;
    v11 = (btTriangleShape *)v7->m_collisionShape;
    resultOut->m_manifoldPtr = m_manifoldPtr;
    v17.m_triangle = v11;
    v17.m_sphere = m_collisionShape;
    v17.m_contactBreakingThreshold = this->m_manifoldPtr->m_contactBreakingThreshold;
    input.m_maximumDistanceSquared = FLOAT_9_9999998e17;
    input.m_transformA.m_basis.m_el[0].mVec128.m128_u64[0] = v16->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[0];
    input.m_transformA.m_basis.m_el[0].mVec128.m128_u64[1] = v16->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[1];
    input.m_transformA.m_basis.m_el[1] = v16->m_worldTransform.m_basis.m_el[1];
    input.m_transformA.m_basis.m_el[2] = v16->m_worldTransform.m_basis.m_el[2];
    input.m_transformA.m_origin = v16->m_worldTransform.m_origin;
    input.m_transformB.m_basis.m_el[0].mVec128.m128_u64[0] = v7->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[0];
    input.m_transformB.m_basis.m_el[0].mVec128.m128_u64[1] = v7->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[1];
    input.m_transformB.m_basis.m_el[1] = v7->m_worldTransform.m_basis.m_el[1];
    input.m_transformB.m_basis.m_el[2] = v7->m_worldTransform.m_basis.m_el[2];
    LOBYTE(m_collisionShape) = this->m_swapped;
    input.m_transformB.m_origin.mVec128.m128_i32[0] = v7->m_worldTransform.m_origin.mVec128.m128_i32[0];
    m_debugDraw = dispatchInfo->m_debugDraw;
    *(unsigned __int64 *)((char *)input.m_transformB.m_origin.mVec128.m128_u64 + 4) = *(unsigned __int64 *)((char *)v7->m_worldTransform.m_origin.mVec128.m128_u64 + 4);
    v17.__vftable = (SphereTriangleDetector_vtbl *)&SphereTriangleDetector::`vftable';
    input.m_transformB.m_origin.mVec128.m128_i32[3] = v7->m_worldTransform.m_origin.mVec128.m128_i32[3];
    SphereTriangleDetector::getClosestPoints(&v17, &input, resultOut, m_debugDraw, (bool)m_collisionShape);
    if ( this->m_ownManifold )
    {
      v12 = resultOut->m_manifoldPtr;
      if ( v12->m_cachedPoints )
      {
        if ( v12->m_body0 == resultOut->m_body0 )
        {
          p_m_rootTransB = &resultOut->m_rootTransB;
          p_m_rootTransA = &resultOut->m_rootTransA;
        }
        else
        {
          p_m_rootTransB = &resultOut->m_rootTransA;
          p_m_rootTransA = &resultOut->m_rootTransB;
        }
        btPersistentManifold::refreshContactPoints(
          (btPersistentManifold *)p_m_rootTransB,
          p_m_rootTransA,
          resultOut->m_manifoldPtr);
      }
    }
  }
}
