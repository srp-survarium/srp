void __cdecl add_serialno(ogg_page *og, void **serialno_list, int *n)
{
  void *v3; // eax
  int v4; // [esp+0h] [ebp-4h]

  v4 = ogg_page_serialno(og);
  ++*n;
  if ( *serialno_list )
    v3 = ogg_realloc_impl(*serialno_list, 4 * *n);
  else
    v3 = ogg_malloc_impl(4u);
  *serialno_list = v3;
  *((_DWORD *)*serialno_list + *n - 1) = v4;
}
