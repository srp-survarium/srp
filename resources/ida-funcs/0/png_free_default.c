void __cdecl png_free_default(int a1, void *pointer)
{
  if ( a1 )
  {
    if ( pointer )
      free(pointer);
  }
}
