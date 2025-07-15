int __usercall sub_376650@<eax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4, int a5)
{
  int v5; // ebx
  int v7; // ecx
  int i; // esi
  int v9; // esi

  v5 = a2;
  if ( a3 < a2 )
  {
    if ( !sub_376530((unsigned __int8 **)a4, a1, a3, a2) )
      return -1;
    a1 = *(_DWORD *)(a4 + 8);
    a3 = *(_DWORD *)(a4 + 12);
  }
  v7 = a3 - v5;
  for ( i = (a1 >> v7) & dword_862950[v5]; i > *(_DWORD *)(a5 + 4 * v5); i = (a1 >> v7) & 1 | v9 )
  {
    v9 = 2 * i;
    if ( v7 < 1 )
    {
      if ( !sub_376530((unsigned __int8 **)a4, a1, v7, 1) )
        return -1;
      a1 = *(_DWORD *)(a4 + 8);
      v7 = *(_DWORD *)(a4 + 12);
    }
    --v7;
    ++v5;
  }
  *(_DWORD *)(a4 + 8) = a1;
  *(_DWORD *)(a4 + 12) = v7;
  if ( v5 <= 16 )
    return *(unsigned __int8 *)(*(_DWORD *)(a5 + 140) + *(_DWORD *)(a5 + 4 * v5 + 72) + i + 17);
  *(_DWORD *)(**(_DWORD **)(a4 + 16) + 20) = 121;
  (*(void (__cdecl **)(_DWORD, int))(**(_DWORD **)(a4 + 16) + 4))(*(_DWORD *)(a4 + 16), -1);
  return 0;
}
