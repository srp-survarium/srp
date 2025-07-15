btBroadphasePair *__thiscall btGhostPairCallback::addOverlappingPair(
        btGhostPairCallback *this,
        btBroadphaseProxy *proxy0,
        btBroadphaseProxy *proxy1)
{
  void *v3; // ecx
  void *v4; // esi

  v3 = *((_DWORD *)proxy0->m_clientObject + 61) != 4 ? 0 : proxy0->m_clientObject;
  v4 = *((_DWORD *)proxy1->m_clientObject + 61) != 4 ? 0 : proxy1->m_clientObject;
  if ( v3 )
    (*(void (__thiscall **)(void *, btBroadphaseProxy *, btBroadphaseProxy *))(*(_DWORD *)v3 + 24))(v3, proxy1, proxy0);
  if ( v4 )
    (*(void (__thiscall **)(void *, btBroadphaseProxy *, btBroadphaseProxy *))(*(_DWORD *)v4 + 24))(v4, proxy0, proxy1);
  return 0;
}
