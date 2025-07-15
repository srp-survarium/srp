void __thiscall btHashedOverlappingPairCache::removeOverlappingPairsContainingProxy(
        btHashedOverlappingPairCache *this,
        btBroadphaseProxy *proxy,
        btDispatcher *dispatcher)
{
  btHashedOverlappingPairCache_vtbl *v3; // eax
  _DWORD v4[2]; // [esp+0h] [ebp-8h] BYREF

  v4[1] = proxy;
  v3 = this->__vftable;
  v4[0] = &`btHashedOverlappingPairCache::removeOverlappingPairsContainingProxy'::`2'::RemovePairCallback::`vftable';
  v3->processAllOverlappingPairs(this, (btOverlapCallback *)v4, dispatcher);
}
