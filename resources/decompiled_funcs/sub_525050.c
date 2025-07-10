int __cdecl sub_525050(int a1, int a2)
{
  int result; // eax
  int v3; // [esp+0h] [ebp-4h]

  while ( 1 )
  {
    result = a1;
    v3 = a1;
    if ( !a1 )
      break;
    a1 = *(_DWORD *)(a1 + 4);
    (*(void (__cdecl **)(_DWORD))(a2 + 20))(*(_DWORD *)(v3 + 16));
    (*(void (__cdecl **)(int))(a2 + 20))(v3);
  }
  return result;
}
