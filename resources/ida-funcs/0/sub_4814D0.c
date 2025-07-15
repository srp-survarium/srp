int __cdecl sub_4814D0(_DWORD *a1, unsigned int a2, unsigned int a3, unsigned int a4)
{
  int v4; // ebp
  unsigned int v5; // edi
  unsigned int v6; // esi
  int v7; // ebp
  _DWORD *v8; // eax
  unsigned int i; // ecx

  v4 = a1[1];
  v5 = 0x3B9AC9F0 / a3;
  if ( (int)(0x3B9AC9F0 / a3) <= 0 )
  {
    *(_DWORD *)(*a1 + 20) = 72;
    (*(void (__cdecl **)(_DWORD *))*a1)(a1);
  }
  if ( (int)v5 >= (int)a4 )
    v5 = a4;
  *(_DWORD *)(v4 + 80) = v5;
  v6 = 0;
  v7 = sub_481300(a1, a2, 4 * a4);
  while ( v6 < a4 )
  {
    if ( v5 >= a4 - v6 )
      v5 = a4 - v6;
    v8 = sub_481430(a1, a2, a3 * v5);
    for ( i = v5; i; --i )
    {
      *(_DWORD *)(v7 + 4 * v6++) = v8;
      v8 = (_DWORD *)((char *)v8 + a3);
    }
  }
  return v7;
}
