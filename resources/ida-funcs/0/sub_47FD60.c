int __cdecl sub_47FD60(int *a1, int a2)
{
  int result; // eax
  int v3; // esi

  result = a2;
  v3 = *a1;
  if ( a2 >= 0 )
  {
    if ( *(_DWORD *)(v3 + 104) >= a2 )
      return (*(int (__cdecl **)(int *))(v3 + 8))(a1);
  }
  else
  {
    if ( !*(_DWORD *)(v3 + 108) || *(int *)(v3 + 104) >= 3 )
      result = (*(int (__cdecl **)(int *))(v3 + 8))(a1);
    ++*(_DWORD *)(v3 + 108);
  }
  return result;
}
