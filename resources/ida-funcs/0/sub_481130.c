int __cdecl sub_481130(_DWORD *a1)
{
  int v1; // edi
  int result; // eax
  int v3; // eax
  int v4; // eax

  v1 = a1[104];
  if ( *(_BYTE *)(v1 + 17) )
    return 2;
  while ( 1 )
  {
    result = (*(int (__cdecl **)(_DWORD *))(a1[105] + 4))(a1);
    if ( !result )
      return 0;
    if ( result != 1 )
      break;
    v3 = *(_DWORD *)(v1 + 20);
    if ( v3 )
    {
      if ( v3 == 1 )
        sub_480990((int)a1);
      if ( a1[74] )
      {
        *(_DWORD *)(v1 + 20) = 0;
        return 1;
      }
      *(_DWORD *)(v1 + 20) = 2;
    }
    else
    {
      if ( !*(_BYTE *)(v1 + 16) )
      {
        *(_DWORD *)(*a1 + 20) = 36;
        (*(void (__cdecl **)(_DWORD *))*a1)(a1);
      }
      if ( a1[74] )
      {
        sub_4810F0((int)a1);
        return 1;
      }
    }
  }
  if ( result != 2 )
    return result;
  *(_BYTE *)(v1 + 17) = 1;
  if ( !*(_DWORD *)(v1 + 20) )
  {
    v4 = a1[31];
    if ( a1[33] > v4 )
      a1[33] = v4;
    return 2;
  }
  if ( !*(_BYTE *)(a1[105] + 13) )
    return 2;
  *(_DWORD *)(*a1 + 20) = 61;
  (*(void (__cdecl **)(_DWORD *))*a1)(a1);
  return 2;
}
