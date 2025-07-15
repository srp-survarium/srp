int __cdecl png_get_io_ptr(int a1)
{
  if ( a1 )
    return *(_DWORD *)(a1 + 88);
  else
    return 0;
}
