void __cdecl sub_37D0C0(_DWORD *a1)
{
  int v1; // edi
  int v2; // eax
  int v3; // eax
  bool v4; // zf
  int *v5; // ebp
  int v6; // edi
  unsigned int i; // ebx

  v1 = a1[110];
  a1[29] = *(_DWORD *)(v1 + 16);
  v2 = a1[19];
  a1[28] = *(_DWORD *)(v1 + 20);
  if ( v2 )
  {
    v3 = v2 - 1;
    if ( v3 )
    {
      if ( v3 == 1 )
      {
        v4 = *(_DWORD *)(v1 + 68) == 0;
        v5 = (int *)(v1 + 68);
        *(_DWORD *)(v1 + 4) = sub_37CEE0;
        *(_BYTE *)(v1 + 84) = 0;
        if ( v4 )
          sub_37D080(a1);
        v6 = 0;
        for ( i = 2 * a1[23] + 4; v6 < a1[25]; ++v5 )
        {
          memset(*v5, 0, i);
          ++v6;
        }
      }
      else
      {
        *(_DWORD *)(*a1 + 20) = 49;
        (*(void (__cdecl **)(_DWORD *))*a1)(a1);
      }
    }
    else
    {
      if ( a1[25] == 3 )
        *(_DWORD *)(v1 + 4) = sub_37CDB0;
      else
        *(_DWORD *)(v1 + 4) = sub_37CCA0;
      v4 = *(_BYTE *)(v1 + 28) == 0;
      *(_DWORD *)(v1 + 48) = 0;
      if ( v4 )
        sub_37C940(a1);
      if ( !*(_DWORD *)(v1 + 52) )
        sub_37CAF0((int)a1);
    }
  }
  else if ( a1[25] == 3 )
  {
    *(_DWORD *)(v1 + 4) = sub_37CBF0;
  }
  else
  {
    *(_DWORD *)(v1 + 4) = sub_37CB40;
  }
}
