int __cdecl sub_4819F0(int a1, int a2, unsigned int a3, unsigned int a4, char a5)
{
  unsigned int v5; // ebp
  unsigned int v6; // eax
  int v7; // eax
  unsigned int v8; // edi
  int v9; // eax
  int v10; // ebx
  unsigned int v11; // edi
  unsigned int i; // ebp

  v5 = a3 + a4;
  if ( a3 + a4 > *(_DWORD *)(a2 + 4) || a4 > *(_DWORD *)(a2 + 12) || !*(_DWORD *)a2 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 23;
    (**(void (__cdecl ***)(int))a1)(a1);
  }
  v6 = *(_DWORD *)(a2 + 24);
  if ( a3 < v6 || v5 > v6 + *(_DWORD *)(a2 + 16) )
  {
    if ( !*(_BYTE *)(a2 + 34) )
    {
      *(_DWORD *)(*(_DWORD *)a1 + 20) = 71;
      (**(void (__cdecl ***)(int))a1)(a1);
    }
    if ( *(_BYTE *)(a2 + 33) )
    {
      sub_4818B0(a2, a1, 1);
      *(_BYTE *)(a2 + 33) = 0;
    }
    if ( a3 <= *(_DWORD *)(a2 + 24) )
    {
      v7 = v5 - *(_DWORD *)(a2 + 16);
      if ( v7 < 0 )
        v7 = 0;
      *(_DWORD *)(a2 + 24) = v7;
    }
    else
    {
      *(_DWORD *)(a2 + 24) = a3;
    }
    sub_4818B0(a2, a1, 0);
  }
  v8 = *(_DWORD *)(a2 + 28);
  if ( v8 >= v5 )
  {
LABEL_27:
    if ( !a5 )
      return *(_DWORD *)a2 + 4 * (a3 - *(_DWORD *)(a2 + 24));
LABEL_28:
    *(_BYTE *)(a2 + 33) = 1;
    return *(_DWORD *)a2 + 4 * (a3 - *(_DWORD *)(a2 + 24));
  }
  if ( v8 < a3 )
  {
    if ( a5 )
    {
      *(_DWORD *)(*(_DWORD *)a1 + 20) = 23;
      (**(void (__cdecl ***)(int))a1)(a1);
    }
    v8 = a3;
  }
  if ( a5 )
    *(_DWORD *)(a2 + 28) = v5;
  if ( *(_BYTE *)(a2 + 32) )
  {
    v9 = *(_DWORD *)(a2 + 24);
    v10 = *(_DWORD *)(a2 + 8);
    v11 = v8 - v9;
    for ( i = v5 - v9; v11 < i; ++v11 )
      memset(*(_DWORD *)(*(_DWORD *)a2 + 4 * v11), 0, v10);
    goto LABEL_27;
  }
  if ( a5 )
    goto LABEL_28;
  *(_DWORD *)(*(_DWORD *)a1 + 20) = 23;
  (**(void (__cdecl ***)(int))a1)(a1);
  return *(_DWORD *)a2 + 4 * (a3 - *(_DWORD *)(a2 + 24));
}
