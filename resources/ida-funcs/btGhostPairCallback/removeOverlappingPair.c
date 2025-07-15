void __thiscall btGhostPairCallback::removeOverlappingPair(
        btGhostPairCallback *this,
        btBroadphaseProxy *proxy0,
        btBroadphaseProxy *proxy1,
        btDispatcher *dispatcher)
{
  void *v4; // ecx
  void *v5; // esi

  v4 = *((_DWORD *)proxy0->m_clientObject + 61) == 4 ? proxy0->m_clientObject : 0;
  v5 = *((_DWORD *)proxy1->m_clientObject + 61) == 4 ? proxy1->m_clientObject : 0;
  if ( v4 )
    (*(void (__thiscall **)(void *, btBroadphaseProxy *, btDispatcher *, btBroadphaseProxy *))(*(_DWORD *)v4 + 28))(
      v4,
      proxy1,
      dispatcher,
      proxy0);
  if ( v5 )
    (*(void (__thiscall **)(void *, btBroadphaseProxy *, btDispatcher *, btBroadphaseProxy *))(*(_DWORD *)v5 + 28))(
      v5,
      proxy0,
      dispatcher,
      proxy1);
}
