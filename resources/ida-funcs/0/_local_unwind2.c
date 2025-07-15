int __usercall _local_unwind2@<eax>(unsigned int ebp0@<ebp>, int a1, unsigned int a2)
{
  int result; // eax
  int v4; // ebx
  unsigned int v5; // esi
  int v6; // esi

  while ( 1 )
  {
    result = a1;
    v4 = *(_DWORD *)(a1 + 8);
    v5 = *(_DWORD *)(a1 + 12);
    if ( v5 == -1 || a2 != -1 && v5 <= a2 )
      break;
    v6 = 3 * v5;
    *(_DWORD *)(a1 + 12) = *(_DWORD *)(v4 + 4 * v6);
    if ( !*(_DWORD *)(v4 + 4 * v6 + 4) )
    {
      _NLG_Notify(*(_DWORD *)(v4 + 4 * v6 + 8), ebp0, 0x101u);
      _NLG_Call(*(int (**)(void))(v4 + 4 * v6 + 8));
    }
  }
  return result;
}
