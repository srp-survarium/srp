int __cdecl png_free(int a1, void *pointer)
{
  int result; // eax

  if ( a1 && pointer )
  {
    if ( *(_DWORD *)(a1 + 616) )
      return (*(int (__cdecl **)(int, void *))(a1 + 616))(a1, pointer);
    else
      return png_free_default(a1, pointer);
  }
  return result;
}
