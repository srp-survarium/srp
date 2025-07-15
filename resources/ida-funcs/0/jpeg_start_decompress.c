char __cdecl jpeg_start_decompress(int a1)
{
  int v2; // eax
  void (__cdecl **v3)(int); // eax
  int v4; // eax
  int v5; // ecx
  int v6; // eax

  if ( *(_DWORD *)(a1 + 20) == 202 )
  {
    jinit_master_decompress(a1);
    if ( *(_BYTE *)(a1 + 64) )
    {
      *(_DWORD *)(a1 + 20) = 207;
      return 1;
    }
    *(_DWORD *)(a1 + 20) = 203;
  }
  v2 = *(_DWORD *)(a1 + 20);
  if ( v2 == 203 )
  {
    if ( *(_BYTE *)(*(_DWORD *)(a1 + 416) + 16) )
    {
      while ( 1 )
      {
        v3 = *(void (__cdecl ***)(int))(a1 + 8);
        if ( v3 )
          (*v3)(a1);
        v4 = (**(int (__cdecl ***)(int))(a1 + 416))(a1);
        if ( !v4 )
          return 0;
        if ( v4 == 2 )
          goto LABEL_17;
        v5 = *(_DWORD *)(a1 + 8);
        if ( v5 && (v4 == 3 || v4 == 1) )
        {
          ++*(_DWORD *)(v5 + 4);
          v6 = *(_DWORD *)(a1 + 8);
          if ( *(_DWORD *)(v6 + 4) >= *(_DWORD *)(v6 + 8) )
            *(_DWORD *)(v6 + 8) += *(_DWORD *)(a1 + 288);
        }
      }
    }
    else
    {
LABEL_17:
      *(_DWORD *)(a1 + 132) = *(_DWORD *)(a1 + 124);
      return sub_370B10(a1);
    }
  }
  else
  {
    if ( v2 != 204 )
    {
      *(_DWORD *)(*(_DWORD *)a1 + 20) = 21;
      *(_DWORD *)(*(_DWORD *)a1 + 24) = *(_DWORD *)(a1 + 20);
      (**(void (__cdecl ***)(int))a1)(a1);
    }
    return sub_370B10(a1);
  }
}
