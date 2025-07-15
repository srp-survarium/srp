int __cdecl png_read_data(int a1, int a2, int a3)
{
  if ( !*(_DWORD *)(a1 + 84) )
    png_error(a1, (int)"Call to NULL read function");
  return (*(int (__cdecl **)(int, int, int))(a1 + 84))(a1, a2, a3);
}
