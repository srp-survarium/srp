void __thiscall btCollisionDispatcher::dispatchAllCollisionPairs(
        btCollisionDispatcher *this,
        btOverlappingPairCache *pairCache,
        const btDispatcherInfo *dispatchInfo,
        btDispatcher *dispatcher)
{
  btOverlappingPairCache_vtbl *v4; // eax
  _DWORD v5[3]; // [esp+0h] [ebp-Ch] BYREF

  v5[2] = this;
  v5[1] = dispatchInfo;
  v4 = pairCache->__vftable;
  v5[0] = &btCollisionPairCallback::`vftable';
  v4->processAllOverlappingPairs(pairCache, (btOverlapCallback *)v5, dispatcher);
}
