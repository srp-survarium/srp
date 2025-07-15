char __cdecl sub_3728C0(_DWORD *a1)
{
  _DWORD *v1; // ebx
  unsigned __int8 **v2; // ebp
  unsigned __int8 *v3; // esi
  unsigned __int8 *i; // edi
  int v5; // eax
  int v6; // eax
  int v7; // ebx
  _DWORD *v8; // eax

  v1 = a1;
  v2 = (unsigned __int8 **)a1[6];
  v3 = *v2;
  for ( i = v2[1]; ; v2[1] = i )
  {
    if ( !i )
    {
      if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v2[3])(v1) )
        return 0;
      v3 = *v2;
      i = v2[1];
    }
    v5 = *v3;
    --i;
    ++v3;
    if ( v5 == 255 )
      goto LABEL_12;
    do
    {
      ++*(_DWORD *)(v1[105] + 20);
      *v2 = v3;
      v2[1] = i;
      if ( !i )
      {
        if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v2[3])(v1) )
          return 0;
        v3 = *v2;
        i = v2[1];
      }
      v6 = *v3;
      --i;
      ++v3;
    }
    while ( v6 != 255 );
    while ( 1 )
    {
LABEL_12:
      if ( !i )
      {
        if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v2[3])(v1) )
          return 0;
        v3 = *v2;
        i = v2[1];
      }
      v7 = *v3;
      --i;
      ++v3;
      if ( v7 != 255 )
        break;
      v1 = a1;
    }
    v8 = a1;
    if ( v7 )
      break;
    *(_DWORD *)(a1[105] + 20) += 2;
    v1 = a1;
    *v2 = v3;
  }
  if ( *(_DWORD *)(a1[105] + 20) )
  {
    *(_DWORD *)(*a1 + 20) = 119;
    *(_DWORD *)(*a1 + 24) = *(_DWORD *)(a1[105] + 20);
    *(_DWORD *)(*a1 + 28) = v7;
    (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, -1);
    v8 = a1;
    *(_DWORD *)(a1[105] + 20) = 0;
  }
  v8[99] = v7;
  v2[1] = i;
  *v2 = v3;
  return 1;
}
