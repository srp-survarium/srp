int __cdecl def_is_number(const conf_st *conf, unsigned __int8 c)
{
  return *((_WORD *)conf->meth_data + c) & 1;
}
