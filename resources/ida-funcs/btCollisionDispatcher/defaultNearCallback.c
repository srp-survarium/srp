void __cdecl btCollisionDispatcher::defaultNearCallback(
        btBroadphasePair *collisionPair,
        btCollisionDispatcher *dispatcher,
        const btDispatcherInfo *dispatchInfo)
{
  btCollisionObject *m_clientObject; // ebx
  btCollisionObject *v4; // eax
  btCollisionAlgorithm *m_algorithm; // ecx
  btCollisionAlgorithm *v6; // eax
  btCollisionObject *v7; // edx
  void *m_internalInfo1; // eax
  btCollisionAlgorithm *v9; // ecx
  btCollisionObject *v10; // edx
  btCollisionObject *v11; // [esp+20h] [ebp-C0h]
  btCollisionObject *body0; // [esp+2Ch] [ebp-B4h]
  float body0a; // [esp+2Ch] [ebp-B4h]
  btManifoldResult v14; // [esp+30h] [ebp-B0h] BYREF

  m_clientObject = (btCollisionObject *)collisionPair->m_pProxy0->m_clientObject;
  body0 = (btCollisionObject *)collisionPair->m_pProxy1->m_clientObject;
  if ( dispatcher->needsCollision(dispatcher, m_clientObject, body0) )
  {
    v4 = body0;
    m_algorithm = collisionPair->m_algorithm;
    if ( m_algorithm
      && collisionPair->m_internalTmpValue != (float)((float)((float)(m_clientObject->m_worldTransform.m_origin.mVec128.m128_f32[2]
                                                                    * m_clientObject->m_worldTransform.m_origin.mVec128.m128_f32[2])
                                                            + (float)(m_clientObject->m_worldTransform.m_origin.mVec128.m128_f32[0]
                                                                    * m_clientObject->m_worldTransform.m_origin.mVec128.m128_f32[0]))
                                                    + (float)(m_clientObject->m_worldTransform.m_origin.mVec128.m128_f32[1]
                                                            * m_clientObject->m_worldTransform.m_origin.mVec128.m128_f32[1])) > (float)((float)((float)(body0->m_worldTransform.m_origin.mVec128.m128_f32[0] * body0->m_worldTransform.m_origin.mVec128.m128_f32[0]) + (float)(body0->m_worldTransform.m_origin.mVec128.m128_f32[1] * body0->m_worldTransform.m_origin.mVec128.m128_f32[1])) + (float)(body0->m_worldTransform.m_origin.mVec128.m128_f32[2] * body0->m_worldTransform.m_origin.mVec128.m128_f32[2])) )
    {
      ((void (__thiscall *)(btCollisionAlgorithm *, _DWORD))m_algorithm->~btCollisionAlgorithm)(m_algorithm, 0);
      dispatcher->freeCollisionAlgorithm(dispatcher, collisionPair->m_algorithm);
      collisionPair->m_algorithm = 0;
      v4 = body0;
    }
    if ( !collisionPair->m_algorithm )
    {
      if ( (float)((float)((float)(m_clientObject->m_worldTransform.m_origin.mVec128.m128_f32[0]
                                 * m_clientObject->m_worldTransform.m_origin.mVec128.m128_f32[0])
                         + (float)(m_clientObject->m_worldTransform.m_origin.mVec128.m128_f32[1]
                                 * m_clientObject->m_worldTransform.m_origin.mVec128.m128_f32[1]))
                 + (float)(m_clientObject->m_worldTransform.m_origin.mVec128.m128_f32[2]
                         * m_clientObject->m_worldTransform.m_origin.mVec128.m128_f32[2])) <= (float)((float)((float)(v4->m_worldTransform.m_origin.mVec128.m128_f32[0] * v4->m_worldTransform.m_origin.mVec128.m128_f32[0]) + (float)(v4->m_worldTransform.m_origin.mVec128.m128_f32[1] * v4->m_worldTransform.m_origin.mVec128.m128_f32[1])) + (float)(v4->m_worldTransform.m_origin.mVec128.m128_f32[2] * v4->m_worldTransform.m_origin.mVec128.m128_f32[2])) )
      {
        collisionPair->m_internalTmpValue = 0;
        v6 = dispatcher->findAlgorithm(dispatcher, m_clientObject, v4, 0);
      }
      else
      {
        collisionPair->m_internalTmpValue = 1;
        v6 = dispatcher->findAlgorithm(dispatcher, v4, m_clientObject, 0);
      }
      collisionPair->m_algorithm = v6;
      v4 = body0;
    }
    if ( collisionPair->m_algorithm )
    {
      v7 = m_clientObject;
      if ( !collisionPair->m_internalTmpValue )
      {
        v7 = v4;
        v4 = m_clientObject;
      }
      btManifoldResult::btManifoldResult((btManifoldResult *)v4, &v14, v7, v11);
      m_internalInfo1 = collisionPair->m_internalInfo1;
      v9 = collisionPair->m_algorithm;
      v10 = m_clientObject;
      if ( dispatchInfo->m_dispatchFunc == 1 )
      {
        if ( m_internalInfo1 )
          m_clientObject = body0;
        else
          v10 = body0;
        v9->processCollision(v9, m_clientObject, v10, dispatchInfo, &v14);
      }
      else
      {
        if ( m_internalInfo1 )
          m_clientObject = body0;
        else
          v10 = body0;
        body0a = v9->calculateTimeOfImpact(v9, m_clientObject, v10, dispatchInfo, &v14);
        if ( dispatchInfo->m_timeOfImpact > (double)body0a )
          dispatchInfo->m_timeOfImpact = body0a;
      }
    }
  }
}
