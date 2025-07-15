void __thiscall btCollisionDispatcher::dispatchAllCollisionPairs(
        btCollisionDispatcher *this,
        btOverlappingPairCache *pairCache,
        const btDispatcherInfo *dispatchInfo,
        btDispatcher *dispatcher)
{
  void (__thiscall *processAllOverlappingPairs)(btOverlappingPairCache *, btOverlapCallback *, btDispatcher *); // edx
  btCollisionPairCallback collisionCallback; // [esp+0h] [ebp-Ch] BYREF

  collisionCallback.m_dispatchInfo = dispatchInfo;
  collisionCallback.m_dispatcher = this;
  processAllOverlappingPairs = pairCache->processAllOverlappingPairs;
  collisionCallback.__vftable = (btCollisionPairCallback_vtbl *)&btCollisionPairCallback::`vftable';
  processAllOverlappingPairs(pairCache, &collisionCallback, dispatcher);
}
