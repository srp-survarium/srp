char __cdecl jpeg_finish_decompress(int a1)
{
  int v1; // eax

  v1 = *(_DWORD *)(a1 + 20);
  if ( (v1 == 205 || v1 == 206) && !*(_BYTE *)(a1 + 64) )
  {
    if ( *(_DWORD *)(a1 + 120) < *(_DWORD *)(a1 + 96) )
    {
      *(_DWORD *)(*(_DWORD *)a1 + 20) = 69;
      (**(void (__cdecl ***)(int))a1)(a1);
    }
    (*(void (__cdecl **)(int))(*(_DWORD *)(a1 + 400) + 4))(a1);
    *(_DWORD *)(a1 + 20) = 210;
  }
  else if ( v1 == 207 )
  {
    *(_DWORD *)(a1 + 20) = 210;
  }
  else if ( v1 != 210 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 21;
    *(_DWORD *)(*(_DWORD *)a1 + 24) = *(_DWORD *)(a1 + 20);
    (**(void (__cdecl ***)(int))a1)(a1);
  }
  if ( *(_BYTE *)(*(_DWORD *)(a1 + 416) + 17) )
  {
LABEL_14:
    (*(void (__cdecl **)(int))(*(_DWORD *)(a1 + 24) + 24))(a1);
    jpeg_abort(a1);
    return 1;
  }
  else
  {
    while ( (**(int (__cdecl ***)(int))(a1 + 416))(a1) )
    {
      if ( *(_BYTE *)(*(_DWORD *)(a1 + 416) + 17) )
        goto LABEL_14;
    }
    return 0;
  }
}
