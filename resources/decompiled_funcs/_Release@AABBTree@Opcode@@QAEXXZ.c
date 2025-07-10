void __usercall Opcode::AABBTree::Release(Opcode::AABBTree *this@<ecx>, int a2@<esi>)
{
  unsigned int v2; // eax
  _DWORD *v3; // edi
  _DWORD *i; // ebx
  unsigned int v5; // eax

  v2 = *(_DWORD *)(a2 + 24) & 0xFFFFFFFE;
  if ( (*(_DWORD *)(a2 + 24) & 1) == 0 && v2 )
    (*(void (__thiscall **)(_DWORD, unsigned int))(**(_DWORD **)(a2 + 52) + 24))(*(_DWORD *)(a2 + 52), v2 - 8);
  v3 = *(_DWORD **)(a2 + 40);
  *(_DWORD *)(a2 + 28) = 0;
  *(_DWORD *)(a2 + 32) = 0;
  if ( v3 )
  {
    for ( i = &v3[9 * *(_DWORD *)(a2 + 44)]; v3 != i; v3 += 9 )
    {
      v5 = v3[6] & 0xFFFFFFFE;
      if ( (v3[6] & 1) == 0 && v5 )
        (*(void (__thiscall **)(_DWORD, unsigned int))(**(_DWORD **)(a2 + 52) + 24))(*(_DWORD *)(a2 + 52), v5 - 8);
      v3[7] = 0;
      v3[8] = 0;
    }
    if ( *(_DWORD *)(a2 + 40) )
    {
      (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)(a2 + 52) + 24))(
        *(_DWORD *)(a2 + 52),
        *(_DWORD *)(a2 + 40) - 8);
      *(_DWORD *)(a2 + 40) = 0;
    }
  }
  if ( *(_DWORD *)(a2 + 36) )
  {
    (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)(a2 + 52) + 24))(*(_DWORD *)(a2 + 52), *(_DWORD *)(a2 + 36) - 8);
    *(_DWORD *)(a2 + 36) = 0;
  }
}
