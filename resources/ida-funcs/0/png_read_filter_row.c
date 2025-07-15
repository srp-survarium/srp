int __cdecl png_read_filter_row(int a1, int a2, int a3, int a4, int a5)
{
  int result; // eax

  result = a1;
  if ( !*(_DWORD *)(a1 + 692) )
    result = sub_476150(a1);
  if ( a5 > 0 && a5 < 5 )
    return (*(int (__cdecl **)(int, int, int))(a1 + 4 * a5 + 688))(a2, a3, a4);
  return result;
}
