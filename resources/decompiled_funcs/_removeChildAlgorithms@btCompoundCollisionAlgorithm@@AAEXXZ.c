void __usercall btCompoundCollisionAlgorithm::removeChildAlgorithms(
        btCompoundCollisionAlgorithm *this@<ecx>,
        int a2@<edi>)
{
  int v2; // ebx
  int i; // esi
  int v4; // eax
  bool v5; // zf
  _DWORD *v6; // eax

  v2 = *(_DWORD *)(a2 + 12);
  for ( i = 0; i < v2; ++i )
  {
    v4 = *(_DWORD *)(a2 + 20);
    v5 = *(_DWORD *)(v4 + 4 * i) == 0;
    v6 = (_DWORD *)(v4 + 4 * i);
    if ( !v5 )
    {
      (**(void (__thiscall ***)(_DWORD, _DWORD))*v6)(*v6, 0);
      (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(a2 + 4) + 56))(
        *(_DWORD *)(a2 + 4),
        *(_DWORD *)(*(_DWORD *)(a2 + 20) + 4 * i));
    }
  }
}
