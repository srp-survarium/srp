int __cdecl lookup_page_serialno(ogg_page *og, int *serialno_list, int n)
{
  int s; // [esp+0h] [ebp-4h]

  s = ogg_page_serialno(og);
  return lookup_serialno(s, serialno_list, n);
}
