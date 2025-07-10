int __cdecl png_flush(int a1)
{
  int result; // eax

  result = a1;
  if ( *(_DWORD *)(a1 + 360) )
    return (*(int (__cdecl **)(int))(a1 + 360))(a1);
  return result;
}
