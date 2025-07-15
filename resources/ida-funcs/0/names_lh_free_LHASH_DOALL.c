void __cdecl names_lh_free_LHASH_DOALL(const char **a1)
{
  if ( a1 && (free_type < 0 || (const char *)free_type == *a1) )
    OBJ_NAME_remove(a1[2], (int)*a1);
}
