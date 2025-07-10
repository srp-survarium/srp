void __cdecl btCollisionDispatcher::defaultNearCallback(
        btBroadphasePair *collisionPair,
        btCollisionDispatcher *dispatcher,
        const btDispatcherInfo *dispatchInfo)
{
  btCollisionObject *m_clientObject; // ebx
  btCollisionObject *v4; // edi
  btCollisionAlgorithm *v5; // eax
  btCollisionAlgorithm *m_algorithm; // esi
  btCollisionAlgorithm_vtbl *v7; // edx
  double v8; // st7
  float v9; // [esp+170h] [ebp-B4h]
  btManifoldResult v10; // [esp+174h] [ebp-B0h] BYREF

  m_clientObject = (btCollisionObject *)collisionPair->m_pProxy1->m_clientObject;
  v4 = (btCollisionObject *)collisionPair->m_pProxy0->m_clientObject;
  if ( dispatcher->needsCollision(dispatcher, v4, m_clientObject) )
  {
    if ( collisionPair->m_algorithm
      || (v5 = dispatcher->findAlgorithm(dispatcher, v4, m_clientObject, 0), (collisionPair->m_algorithm = v5) != 0) )
    {
      btManifoldResult::btManifoldResult(&v10, v4, m_clientObject);
      m_algorithm = collisionPair->m_algorithm;
      v7 = m_algorithm->__vftable;
      if ( dispatchInfo->m_dispatchFunc == 1 )
      {
        v7->processCollision(m_algorithm, v4, m_clientObject, dispatchInfo, &v10);
      }
      else
      {
        v8 = ((double (__thiscall *)(btCollisionAlgorithm *, btCollisionObject *, btCollisionObject *, const btDispatcherInfo *, btManifoldResult *))v7->calculateTimeOfImpact)(
               m_algorithm,
               v4,
               m_clientObject,
               dispatchInfo,
               &v10);
        if ( dispatchInfo->m_timeOfImpact > v8 )
        {
          v9 = v8;
          dispatchInfo->m_timeOfImpact = v9;
        }
      }
    }
  }
}
