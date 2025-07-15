void __thiscall btSortedOverlappingPairCache::cleanProxyFromPairs(
        btSortedOverlappingPairCache *this,
        btBroadphaseProxy *proxy,
        btDispatcher *dispatcher)
{
  void (__thiscall *processAllOverlappingPairs)(struct btSortedOverlappingPairCache *, btOverlapCallback *, btDispatcher *); // edx
  btSortedOverlappingPairCache::cleanProxyFromPairs::__l2::CleanPairCallback cleanPairs; // [esp+0h] [ebp-10h] BYREF

  processAllOverlappingPairs = this->processAllOverlappingPairs;
  cleanPairs.m_cleanProxy = proxy;
  cleanPairs.m_dispatcher = dispatcher;
  cleanPairs.__vftable = (btSortedOverlappingPairCache::cleanProxyFromPairs::__l2::CleanPairCallback_vtbl *)&`btSortedOverlappingPairCache::cleanProxyFromPairs'::`2'::CleanPairCallback::`vftable';
  cleanPairs.m_pairCache = this;
  ((void (__stdcall *)(btSortedOverlappingPairCache::cleanProxyFromPairs::__l2::CleanPairCallback *, btDispatcher *))processAllOverlappingPairs)(
    &cleanPairs,
    dispatcher);
}
