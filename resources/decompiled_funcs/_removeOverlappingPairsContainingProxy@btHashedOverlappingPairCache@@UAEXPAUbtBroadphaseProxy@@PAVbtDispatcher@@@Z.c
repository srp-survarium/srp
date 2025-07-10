void __thiscall btHashedOverlappingPairCache::removeOverlappingPairsContainingProxy(
        btHashedOverlappingPairCache *this,
        btBroadphaseProxy *proxy,
        btDispatcher *dispatcher)
{
  void (__thiscall *processAllOverlappingPairs)(struct btHashedOverlappingPairCache *, btOverlapCallback *, btDispatcher *); // edx
  btHashedOverlappingPairCache::removeOverlappingPairsContainingProxy::__l2::RemovePairCallback removeCallback; // [esp+0h] [ebp-8h] BYREF

  processAllOverlappingPairs = this->processAllOverlappingPairs;
  removeCallback.m_obsoleteProxy = proxy;
  removeCallback.__vftable = (btHashedOverlappingPairCache::removeOverlappingPairsContainingProxy::__l2::RemovePairCallback_vtbl *)&`btHashedOverlappingPairCache::removeOverlappingPairsContainingProxy'::`2'::RemovePairCallback::`vftable';
  processAllOverlappingPairs(this, &removeCallback, dispatcher);
}
