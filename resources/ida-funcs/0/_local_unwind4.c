int __usercall _local_unwind4@<eax>(unsigned int ebp0@<ebp>, _DWORD *a1, int a2, unsigned int a3)
{
  int result; // eax
  unsigned int v5; // esi
  int v6; // esi
  int v7; // ebx

  while ( 1 )
  {
    result = a2;
    v5 = *(_DWORD *)(a2 + 12);
    if ( v5 == -2 || a3 != -2 && v5 <= a3 )
      break;
    v6 = 3 * v5;
    v7 = (*a1 ^ *(_DWORD *)(a2 + 8)) + 4 * v6 + 16;
    *(_DWORD *)(a2 + 12) = *(_DWORD *)((*a1 ^ *(_DWORD *)(a2 + 8)) + 4 * v6 + 0x10);
    if ( !*(_DWORD *)(v7 + 4) )
    {
      _NLG_Notify(*(_DWORD *)(v7 + 8), ebp0, 0x101u);
      _NLG_Call(*(int (**)(void))(v7 + 8));
    }
  }
  return result;
}
