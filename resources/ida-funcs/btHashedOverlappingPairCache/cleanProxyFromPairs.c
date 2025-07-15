void __thiscall btHashedOverlappingPairCache::cleanProxyFromPairs(
        btHashedOverlappingPairCache *this,
        btBroadphaseProxy *proxy,
        btDispatcher *dispatcher)
{
  btHashedOverlappingPairCache_vtbl *v3; // edx
  _DWORD v4[4]; // [esp+0h] [ebp-10h] BYREF

  v3 = this->__vftable;
  v4[1] = proxy;
  v4[3] = dispatcher;
  v4[0] = &`btHashedOverlappingPairCache::cleanProxyFromPairs'::`2'::CleanPairCallback::`vftable';
  v4[2] = this;
  ((void (__stdcall *)(_DWORD *, btDispatcher *))v3->processAllOverlappingPairs)(v4, dispatcher);
}
