void __cdecl add_serialno(ogg_page *og, void **serialno_list, int *n)
{
  int *v3; // eax
  int s; // [esp+0h] [ebp-4h]

  s = ogg_page_serialno(og);
  ++*n;
  if ( *serialno_list )
    v3 = (int *)realloc(*serialno_list, 4 * *n);
  else
    v3 = (int *)malloc(4u);
  *serialno_list = v3;
  *((_DWORD *)*serialno_list + *n - 1) = s;
}
