int __cdecl jpeg_read_header(_DWORD *a1, char a2)
{
  int v2; // eax
  int result; // eax

  v2 = a1[5];
  if ( v2 != 200 && v2 != 201 )
  {
    *(_DWORD *)(*a1 + 20) = 21;
    *(_DWORD *)(*a1 + 24) = a1[5];
    (*(void (__cdecl **)(_DWORD *))*a1)(a1);
  }
  result = jpeg_consume_input(a1);
  if ( result == 1 )
    return 1;
  if ( result == 2 )
  {
    if ( a2 )
    {
      *(_DWORD *)(*a1 + 20) = 53;
      (*(void (__cdecl **)(_DWORD *))*a1)(a1);
    }
    jpeg_abort(a1);
    return 2;
  }
  return result;
}
