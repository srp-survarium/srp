int __cdecl jpeg_read_coefficients(int a1)
{
  void (__cdecl **v1)(int); // eax
  int v2; // eax
  int v3; // ecx
  int v4; // eax
  int v5; // eax

  if ( *(_DWORD *)(a1 + 20) == 202 )
  {
    sub_47DEE0(a1);
    *(_DWORD *)(a1 + 20) = 209;
  }
  if ( *(_DWORD *)(a1 + 20) == 209 )
  {
    while ( 1 )
    {
      v1 = *(void (__cdecl ***)(int))(a1 + 8);
      if ( v1 )
        (*v1)(a1);
      v2 = (**(int (__cdecl ***)(int))(a1 + 416))(a1);
      if ( !v2 )
        break;
      if ( v2 == 2 )
      {
        *(_DWORD *)(a1 + 20) = 210;
        goto LABEL_14;
      }
      v3 = *(_DWORD *)(a1 + 8);
      if ( v3 && (v2 == 3 || v2 == 1) )
      {
        ++*(_DWORD *)(v3 + 4);
        v4 = *(_DWORD *)(a1 + 8);
        if ( *(_DWORD *)(v4 + 4) >= *(_DWORD *)(v4 + 8) )
          *(_DWORD *)(v4 + 8) += *(_DWORD *)(a1 + 288);
      }
    }
  }
  else
  {
LABEL_14:
    v5 = *(_DWORD *)(a1 + 20);
    if ( (v5 == 210 || v5 == 207) && *(_BYTE *)(a1 + 64) )
      return *(_DWORD *)(*(_DWORD *)(a1 + 408) + 16);
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 21;
    *(_DWORD *)(*(_DWORD *)a1 + 24) = *(_DWORD *)(a1 + 20);
    (**(void (__cdecl ***)(int))a1)(a1);
  }
  return 0;
}
