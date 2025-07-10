void __thiscall btSortedOverlappingPairCache::removeOverlappingPairsContainingProxy(
        btSortedOverlappingPairCache *this,
        btBroadphaseProxy *proxy,
        btDispatcher *dispatcher)
{
  void (__thiscall *processAllOverlappingPairs)(struct btSortedOverlappingPairCache *, btOverlapCallback *, btDispatcher *); // edx
  btSortedOverlappingPairCache::removeOverlappingPairsContainingProxy::__l2::RemovePairCallback removeCallback; // [esp+0h] [ebp-8h] BYREF

  processAllOverlappingPairs = this->processAllOverlappingPairs;
  removeCallback.m_obsoleteProxy = proxy;
  removeCallback.__vftable = (btSortedOverlappingPairCache::removeOverlappingPairsContainingProxy::__l2::RemovePairCallback_vtbl *)&`btSortedOverlappingPairCache::removeOverlappingPairsContainingProxy'::`2'::RemovePairCallback::`vftable';
  processAllOverlappingPairs(this, &removeCallback, dispatcher);
}
