void __thiscall btHashedOverlappingPairCache::cleanProxyFromPairs(
        btHashedOverlappingPairCache *this,
        btBroadphaseProxy *proxy,
        btDispatcher *dispatcher)
{
  void (__thiscall *processAllOverlappingPairs)(struct btHashedOverlappingPairCache *, btOverlapCallback *, btDispatcher *); // edx
  btHashedOverlappingPairCache::cleanProxyFromPairs::__l2::CleanPairCallback cleanPairs; // [esp+0h] [ebp-10h] BYREF

  processAllOverlappingPairs = this->processAllOverlappingPairs;
  cleanPairs.m_cleanProxy = proxy;
  cleanPairs.m_dispatcher = dispatcher;
  cleanPairs.__vftable = (btHashedOverlappingPairCache::cleanProxyFromPairs::__l2::CleanPairCallback_vtbl *)&`btHashedOverlappingPairCache::cleanProxyFromPairs'::`2'::CleanPairCallback::`vftable';
  cleanPairs.m_pairCache = this;
  ((void (__stdcall *)(btHashedOverlappingPairCache::cleanProxyFromPairs::__l2::CleanPairCallback *, btDispatcher *))processAllOverlappingPairs)(
    &cleanPairs,
    dispatcher);
}
