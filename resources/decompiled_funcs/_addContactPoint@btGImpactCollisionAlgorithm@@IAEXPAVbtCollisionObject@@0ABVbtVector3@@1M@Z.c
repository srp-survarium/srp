void __userpurge btGImpactCollisionAlgorithm::addContactPoint(
        btGImpactCollisionAlgorithm *this@<ecx>,
        int a2@<esi>,
        btCollisionObject *body0,
        btCollisionObject *body1,
        const btVector3 *point,
        const btVector3 *normal,
        float distance)
{
  (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD))(**(_DWORD **)(a2 + 16) + 4))(
    *(_DWORD *)(a2 + 16),
    *(_DWORD *)(a2 + 28),
    *(_DWORD *)(a2 + 24));
  (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD))(**(_DWORD **)(a2 + 16) + 8))(
    *(_DWORD *)(a2 + 16),
    *(_DWORD *)(a2 + 36),
    *(_DWORD *)(a2 + 32));
  if ( !*(_DWORD *)(a2 + 12) )
    *(_DWORD *)(a2 + 12) = (*(int (__thiscall **)(_DWORD, btCollisionObject *, btCollisionObject *))(**(_DWORD **)(a2 + 4) + 8))(
                             *(_DWORD *)(a2 + 4),
                             body0,
                             body1);
  *(_DWORD *)(*(_DWORD *)(a2 + 16) + 4) = *(_DWORD *)(a2 + 12);
  (*(void (__stdcall **)(const btVector3 *, const btVector3 *, _DWORD))(**(_DWORD **)(a2 + 16) + 12))(
    normal,
    point,
    LODWORD(distance));
}
