int __cdecl sub_3736F0(int a1)
{
  int v1; // edi
  int result; // eax

  v1 = *(_DWORD *)(a1 + 400);
  if ( *(_BYTE *)(v1 + 8) )
  {
    *(_BYTE *)(v1 + 8) = 0;
    (**(void (__cdecl ***)(int, _DWORD))(a1 + 440))(a1, 0);
    (**(void (__cdecl ***)(int, int))(a1 + 412))(a1, 2);
    (**(void (__cdecl ***)(int, int))(a1 + 404))(a1, 2);
  }
  else
  {
    if ( *(_BYTE *)(a1 + 74) && !*(_DWORD *)(a1 + 116) )
    {
      if ( *(_BYTE *)(a1 + 80) && *(_BYTE *)(a1 + 90) )
      {
        *(_DWORD *)(a1 + 440) = *(_DWORD *)(v1 + 24);
        *(_BYTE *)(v1 + 8) = 1;
      }
      else if ( *(_BYTE *)(a1 + 88) )
      {
        *(_DWORD *)(a1 + 440) = *(_DWORD *)(v1 + 20);
      }
      else
      {
        *(_DWORD *)(*(_DWORD *)a1 + 20) = 47;
        (**(void (__cdecl ***)(int))a1)(a1);
      }
    }
    (**(void (__cdecl ***)(int))(a1 + 428))(a1);
    (*(void (__cdecl **)(int))(*(_DWORD *)(a1 + 408) + 8))(a1);
    if ( !*(_BYTE *)(a1 + 65) )
    {
      if ( !*(_BYTE *)(v1 + 16) )
        (**(void (__cdecl ***)(int))(a1 + 436))(a1);
      (**(void (__cdecl ***)(int))(a1 + 432))(a1);
      if ( *(_BYTE *)(a1 + 74) )
        (**(void (__cdecl ***)(int, _DWORD))(a1 + 440))(a1, *(unsigned __int8 *)(v1 + 8));
      (**(void (__cdecl ***)(int, int))(a1 + 412))(a1, *(_BYTE *)(v1 + 8) != 0 ? 3 : 0);
      (**(void (__cdecl ***)(int, _DWORD))(a1 + 404))(a1, 0);
    }
  }
  result = *(_DWORD *)(a1 + 8);
  if ( result )
  {
    *(_DWORD *)(result + 12) = *(_DWORD *)(v1 + 12);
    result = *(_DWORD *)(a1 + 8);
    *(_DWORD *)(result + 16) = *(_DWORD *)(v1 + 12) + (*(_BYTE *)(v1 + 8) != 0) + 1;
    if ( *(_BYTE *)(a1 + 64) )
    {
      if ( !*(_BYTE *)(*(_DWORD *)(a1 + 416) + 17) )
      {
        result = *(_DWORD *)(a1 + 8);
        *(_DWORD *)(result + 16) += (*(_BYTE *)(a1 + 90) != 0) + 1;
      }
    }
  }
  return result;
}
