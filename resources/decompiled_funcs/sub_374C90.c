int __usercall sub_374C90@<eax>(int a1@<esi>, int a2, char a3)
{
  int result; // eax
  int v4; // ebp
  int v5; // ebx
  int v6; // edi
  int v7; // ecx
  int v8; // ebp
  int v9; // [esp+Ch] [ebp-4h]

  result = *(_DWORD *)(a1 + 16);
  v4 = *(_DWORD *)(a1 + 8) << 7;
  v5 = v4 * *(_DWORD *)(a1 + 24);
  v6 = 0;
  v9 = v4;
  if ( result > 0 )
  {
    while ( 1 )
    {
      result -= v6;
      if ( *(_DWORD *)(a1 + 20) < result )
        result = *(_DWORD *)(a1 + 20);
      v7 = v6 + *(_DWORD *)(a1 + 24);
      if ( result >= *(_DWORD *)(a1 + 28) - v7 )
        result = *(_DWORD *)(a1 + 28) - v7;
      if ( result >= *(_DWORD *)(a1 + 4) - v7 )
        result = *(_DWORD *)(a1 + 4) - v7;
      if ( result <= 0 )
        break;
      v8 = v4 * result;
      if ( a3 )
        (*(void (__cdecl **)(int, int, _DWORD, int, int))(a1 + 44))(
          a2,
          a1 + 40,
          *(_DWORD *)(*(_DWORD *)a1 + 4 * v6),
          v5,
          v8);
      else
        (*(void (__cdecl **)(int, int, _DWORD, int, int))(a1 + 40))(
          a2,
          a1 + 40,
          *(_DWORD *)(*(_DWORD *)a1 + 4 * v6),
          v5,
          v8);
      v6 += *(_DWORD *)(a1 + 20);
      result = *(_DWORD *)(a1 + 16);
      v5 += v8;
      if ( v6 >= result )
        break;
      v4 = v9;
    }
  }
  return result;
}
