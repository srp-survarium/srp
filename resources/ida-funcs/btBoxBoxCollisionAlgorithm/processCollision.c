void __thiscall btBoxBoxCollisionAlgorithm::processCollision(
        btBoxBoxCollisionAlgorithm *this,
        btCollisionObject *body0,
        btCollisionObject *body1,
        const btDispatcherInfo *dispatchInfo,
        btManifoldResult *resultOut)
{
  btPersistentManifold *m_manifoldPtr; // esi
  btBoxShape *m_collisionShape; // ecx
  btPersistentManifold *v7; // eax
  btTransform *p_m_rootTransB; // ecx
  btTransform *p_m_rootTransA; // edx
  btIDebugDraw *m_debugDraw; // [esp-8h] [ebp-B8h]
  btBoxShape *v12; // [esp+10h] [ebp-A0h]
  btBoxBoxDetector v13; // [esp+14h] [ebp-9Ch] BYREF
  btDiscreteCollisionDetectorInterface::ClosestPointInput input; // [esp+20h] [ebp-90h] BYREF

  m_manifoldPtr = this->m_manifoldPtr;
  if ( m_manifoldPtr )
  {
    input.m_stackAlloc = 0;
    m_collisionShape = (btBoxShape *)body0->m_collisionShape;
    v12 = (btBoxShape *)body1->m_collisionShape;
    resultOut->m_manifoldPtr = m_manifoldPtr;
    input.m_maximumDistanceSquared = FLOAT_9_9999998e17;
    input.m_transformA = body0->m_worldTransform;
    input.m_transformB.m_basis.m_el[0].mVec128.m128_u64[0] = body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[0];
    input.m_transformB.m_basis.m_el[0].mVec128.m128_u64[1] = body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[1];
    input.m_transformB.m_basis.m_el[1] = body1->m_worldTransform.m_basis.m_el[1];
    input.m_transformB.m_basis.m_el[2] = body1->m_worldTransform.m_basis.m_el[2];
    input.m_transformB.m_origin.mVec128.m128_u64[0] = body1->m_worldTransform.m_origin.mVec128.m128_u64[0];
    v13.m_box2 = v12;
    m_debugDraw = dispatchInfo->m_debugDraw;
    input.m_transformB.m_origin.mVec128.m128_i32[2] = body1->m_worldTransform.m_origin.mVec128.m128_i32[2];
    v13.m_box1 = m_collisionShape;
    input.m_transformB.m_origin.mVec128.m128_i32[3] = body1->m_worldTransform.m_origin.mVec128.m128_i32[3];
    v13.__vftable = (btBoxBoxDetector_vtbl *)&btBoxBoxDetector::`vftable';
    btBoxBoxDetector::getClosestPoints(&v13, &input, resultOut, m_debugDraw, 0);
    if ( this->m_ownManifold )
    {
      v7 = resultOut->m_manifoldPtr;
      if ( v7->m_cachedPoints )
      {
        if ( v7->m_body0 == resultOut->m_body0 )
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
