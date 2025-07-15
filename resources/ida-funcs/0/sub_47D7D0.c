char __usercall sub_47D7D0@<al>(int a1@<esi>)
{
  unsigned int *v1; // edi
  unsigned int v2; // eax
  int v3; // ecx
  unsigned int v4; // ebx
  char result; // al

  if ( *(_DWORD *)(a1 + 20) != 204 )
  {
    (**(void (__cdecl ***)(int))(a1 + 400))(a1);
    *(_DWORD *)(a1 + 120) = 0;
    *(_DWORD *)(a1 + 20) = 204;
  }
  if ( *(_BYTE *)(*(_DWORD *)(a1 + 400) + 8) )
  {
    v1 = (unsigned int *)(a1 + 120);
    while ( 1 )
    {
      v2 = *v1;
      if ( *v1 < *(_DWORD *)(a1 + 96) )
        break;
LABEL_10:
      (*(void (__cdecl **)(int))(*(_DWORD *)(a1 + 400) + 4))(a1);
      (**(void (__cdecl ***)(int))(a1 + 400))(a1);
      *v1 = 0;
      if ( !*(_BYTE *)(*(_DWORD *)(a1 + 400) + 8) )
        goto LABEL_11;
    }
    while ( 1 )
    {
      v3 = *(_DWORD *)(a1 + 8);
      if ( v3 )
      {
        *(_DWORD *)(v3 + 4) = v2;
        *(_DWORD *)(*(_DWORD *)(a1 + 8) + 8) = *(_DWORD *)(a1 + 96);
        (**(void (__cdecl ***)(int))(a1 + 8))(a1);
      }
      v4 = *v1;
      (*(void (__cdecl **)(int, _DWORD, int, _DWORD))(*(_DWORD *)(a1 + 404) + 4))(a1, 0, a1 + 120, 0);
      v2 = *v1;
      if ( *v1 == v4 )
        return 0;
      if ( v2 >= *(_DWORD *)(a1 + 96) )
        goto LABEL_10;
    }
  }
  else
  {
LABEL_11:
    result = 1;
    *(_DWORD *)(a1 + 20) = (*(_BYTE *)(a1 + 65) != 0) + 205;
  }
  return result;
}
