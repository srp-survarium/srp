int __cdecl jpeg_abort(int a1)
{
  int result; // eax

  result = *(_DWORD *)(a1 + 4);
  if ( result )
  {
    result = (*(int (__cdecl **)(int, int))(result + 36))(a1, 1);
    if ( *(_BYTE *)(a1 + 16) )
    {
      *(_DWORD *)(a1 + 20) = 200;
      *(_DWORD *)(a1 + 268) = 0;
    }
    else
    {
      *(_DWORD *)(a1 + 20) = 100;
    }
  }
  return result;
}
