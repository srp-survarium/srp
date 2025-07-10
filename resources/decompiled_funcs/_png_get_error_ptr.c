int __cdecl png_get_error_ptr(int a1)
{
  if ( a1 )
    return *(_DWORD *)(a1 + 76);
  else
    return 0;
}
