void __usercall btCompoundCollisionAlgorithm::removeChildAlgorithms(
        btCompoundCollisionAlgorithm *this@<ecx>,
        int a2@<esi>)
{
  int v2; // ebx
  int i; // edi
  _DWORD *v4; // eax

  v2 = *(_DWORD *)(a2 + 12);
  for ( i = 0; i < v2; ++i )
  {
    v4 = (_DWORD *)(*(_DWORD *)(a2 + 20) + 4 * i);
    if ( *v4 )
    {
      (**(void (__thiscall ***)(_DWORD, _DWORD))*v4)(*v4, 0);
      (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(a2 + 4) + 56))(
        *(_DWORD *)(a2 + 4),
        *(_DWORD *)(*(_DWORD *)(a2 + 20) + 4 * i));
    }
  }
}
