void __cdecl names_lh_free_LHASH_DOALL(const char **arg)
{
  if ( arg && (free_type < 0 || (const char *)free_type == *arg) )
    OBJ_NAME_remove(arg[2], (int)*arg);
}
