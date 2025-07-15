char __cdecl sub_378640(_DWORD *a1, int a2)
{
  int v2; // edi
  _BYTE *v3; // ebp
  int v4; // edi
  int i; // ebx

  v2 = a1[106];
  if ( a1[63] )
  {
    if ( !*(_DWORD *)(v2 + 52) )
      sub_378100((int)a1);
    --*(_DWORD *)(v2 + 52);
  }
  v3 = (_BYTE *)(v2 + 184);
  v4 = 0;
  for ( i = 1 << a1[95]; v4 < a1[81]; ++v4 )
  {
    if ( sub_377FD0(a1, v3) )
      **(_WORD **)(a2 + 4 * v4) |= i;
  }
  return 1;
}
