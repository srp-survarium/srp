char __usercall sub_4833D0@<al>(_DWORD *a1@<esi>)
{
  int v1; // edi
  char result; // al
  int v3; // eax
  _DWORD *v4; // ecx

  v1 = a1[106];
  *(_DWORD *)(a1[105] + 20) += *(_DWORD *)(v1 + 12) / 8;
  *(_DWORD *)(v1 + 12) = 0;
  result = (*(int (**)(void))(a1[105] + 8))();
  if ( result )
  {
    v3 = 0;
    if ( (int)a1[74] > 0 )
    {
      v4 = (_DWORD *)(v1 + 20);
      do
      {
        *v4 = 0;
        ++v3;
        ++v4;
      }
      while ( v3 < a1[74] );
    }
    *(_DWORD *)(v1 + 16) = 0;
    *(_DWORD *)(v1 + 40) = a1[63];
    if ( !a1[99] )
      *(_BYTE *)(v1 + 36) = 0;
    return 1;
  }
  return result;
}
