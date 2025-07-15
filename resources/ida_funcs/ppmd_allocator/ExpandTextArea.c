void __usercall ppmd_allocator::ExpandTextArea(ppmd_allocator *this@<ecx>, int a2@<eax>)
{
  _DWORD *i; // eax
  int v4; // ecx
  _DWORD *v5; // edx
  unsigned int *v6; // ecx
  int v7; // esi
  _DWORD *j; // eax
  bool v9; // zf
  unsigned int Count[38]; // [esp+8h] [ebp-98h] BYREF

  memset((unsigned __int8 *)Count, 0, sizeof(Count));
  for ( i = *(_DWORD **)(a2 + 492); *i == -1; i = *(_DWORD **)(a2 + 492) )
  {
    *(_DWORD *)(a2 + 492) = &i[3 * i[2]];
    v4 = *(unsigned __int8 *)(i[2] + a2 + 345);
    ++Count[v4];
    *i = 0;
  }
  v5 = (_DWORD *)(a2 + 4);
  v6 = Count;
  v7 = 38;
  do
  {
    for ( j = v5; *v6; j = (_DWORD *)j[1] )
    {
      if ( !*(_DWORD *)j[1] )
      {
        do
        {
          j[1] = *(_DWORD *)(j[1] + 4);
          --*v5;
          v9 = (*v6)-- == 1;
        }
        while ( !v9 && !*(_DWORD *)j[1] );
      }
    }
    v5 += 2;
    ++v6;
    --v7;
  }
  while ( v7 );
}
