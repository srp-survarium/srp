int __cdecl png_write_data(int a1, int a2, int a3)
{
  if ( !*(_DWORD *)(a1 + 80) )
    png_error(a1, (int)"Call to NULL write function");
  return (*(int (__cdecl **)(int, int, int))(a1 + 80))(a1, a2, a3);
}
