int __cdecl jinit_2pass_quantizer(int a1)
{
  int v1; // edi
  int i; // ebp
  int result; // eax
  int v4; // ebp

  v1 = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 44);
  *(_DWORD *)(a1 + 440) = v1;
  *(_DWORD *)v1 = sub_4890D0;
  *(_DWORD *)(v1 + 12) = sub_489200;
  *(_DWORD *)(v1 + 32) = 0;
  *(_DWORD *)(v1 + 40) = 0;
  if ( *(_DWORD *)(a1 + 100) != 3 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 48;
    (**(void (__cdecl ***)(int))a1)(a1);
  }
  *(_DWORD *)(v1 + 24) = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 128);
  for ( i = 0; i < 128; i += 4 )
  {
    result = (*(int (__cdecl **)(int, int, int))(*(_DWORD *)(a1 + 4) + 4))(a1, 1, 4096);
    *(_DWORD *)(*(_DWORD *)(v1 + 24) + i) = result;
  }
  *(_BYTE *)(v1 + 28) = 1;
  if ( *(_BYTE *)(a1 + 90) )
  {
    v4 = *(_DWORD *)(a1 + 84);
    if ( v4 < 8 )
    {
      *(_DWORD *)(*(_DWORD *)a1 + 20) = 58;
      *(_DWORD *)(*(_DWORD *)a1 + 24) = 8;
      (**(void (__cdecl ***)(int))a1)(a1);
    }
    if ( v4 > 256 )
    {
      *(_DWORD *)(*(_DWORD *)a1 + 20) = 59;
      *(_DWORD *)(*(_DWORD *)a1 + 24) = 256;
      (**(void (__cdecl ***)(int))a1)(a1);
    }
    result = (*(int (__cdecl **)(int, int, int, int))(*(_DWORD *)(a1 + 4) + 8))(a1, 1, v4, 3);
    *(_DWORD *)(v1 + 16) = result;
    *(_DWORD *)(v1 + 20) = v4;
  }
  else
  {
    *(_DWORD *)(v1 + 16) = 0;
  }
  if ( *(_DWORD *)(a1 + 76) )
    *(_DWORD *)(a1 + 76) = 2;
  if ( *(_DWORD *)(a1 + 76) == 2 )
  {
    *(_DWORD *)(v1 + 32) = (*(int (__cdecl **)(int, int, int))(*(_DWORD *)(a1 + 4) + 4))(
                             a1,
                             1,
                             6 * (*(_DWORD *)(a1 + 92) + 2));
    return sub_489000(a1);
  }
  return result;
}
