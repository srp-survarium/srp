int __cdecl png_set_mem_fn(_DWORD *a1, int a2, int a3, int a4)
{
  int result; // eax

  if ( a1 )
  {
    a1[152] = a2;
    result = a3;
    a1[153] = a3;
    a1[154] = a4;
  }
  return result;
}
