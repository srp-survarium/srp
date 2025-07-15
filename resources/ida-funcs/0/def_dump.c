int __cdecl def_dump(const conf_st *conf, bio_st *out)
{
  lh_doall_arg((lhash_st *)conf->data, (void (__cdecl *)(void *, void *))dump_value_LHASH_DOALL_ARG, out);
  return 1;
}
