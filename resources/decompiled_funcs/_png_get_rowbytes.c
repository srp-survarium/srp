int __cdecl png_get_rowbytes(int a1, int a2)
{
  if ( a1 && a2 )
    return *(_DWORD *)(a2 + 12);
  else
    return 0;
}
