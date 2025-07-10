int __cdecl jpeg_destroy(int a1)
{
  int result; // eax

  result = *(_DWORD *)(a1 + 4);
  if ( result )
    result = (*(int (__cdecl **)(int))(result + 40))(a1);
  *(_DWORD *)(a1 + 20) = 0;
  *(_DWORD *)(a1 + 4) = 0;
  return result;
}
