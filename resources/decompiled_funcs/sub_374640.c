int __cdecl sub_374640(_DWORD *a1, unsigned int a2, unsigned int a3)
{
  unsigned int v4; // edi
  _DWORD *i; // eax
  _DWORD *v6; // ebp
  unsigned int v7; // edi
  unsigned int v8; // esi
  int v9; // ecx
  int v11; // [esp+14h] [ebp+4h]

  v4 = a3;
  v11 = a1[1];
  if ( a3 > 0x3B9AC9F0 )
    sub_374620((int)a1, 1);
  if ( (a3 & 7) != 0 )
  {
    v4 = 8 - (a3 & 7) + a3;
    a3 = v4;
  }
  if ( a2 >= 2 )
  {
    *(_DWORD *)(*a1 + 20) = 15;
    *(_DWORD *)(*a1 + 24) = a2;
    (*(void (__cdecl **)(_DWORD *))*a1)(a1);
  }
  i = *(_DWORD **)(v11 + 4 * a2 + 52);
  v6 = 0;
  if ( i )
  {
    while ( i[2] < v4 )
    {
      v6 = i;
      i = (_DWORD *)*i;
      if ( !i )
        goto LABEL_10;
    }
  }
  else
  {
LABEL_10:
    v7 = v4 + 16;
    if ( v6 )
      v8 = dword_862608[a2];
    else
      v8 = dword_862600[a2];
    if ( v8 > 1000000000 - v7 )
      v8 = 1000000000 - v7;
    for ( i = (_DWORD *)jpeg_get_small((int)a1, v8 + v7); !i; i = (_DWORD *)jpeg_get_small((int)a1, v8 + v7) )
    {
      v8 >>= 1;
      if ( v8 < 0x32 )
        sub_374620((int)a1, 2);
    }
    *(_DWORD *)(v11 + 76) += v8 + v7;
    *i = 0;
    i[1] = 0;
    i[2] = a3 + v8;
    v4 = a3;
    if ( v6 )
      *v6 = i;
    else
      *(_DWORD *)(v11 + 4 * a2 + 52) = i;
  }
  v9 = i[1];
  i[2] -= v4;
  i[1] = v4 + v9;
  return (int)i + v9 + 16;
}
