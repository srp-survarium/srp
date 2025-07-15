int __cdecl RAND_set_rand_method(const rand_meth_st *meth)
{
  if ( funct_ref )
  {
    ENGINE_finish(funct_ref);
    default_RAND_meth = meth;
    funct_ref = 0;
  }
  else
  {
    default_RAND_meth = meth;
  }
  return 1;
}
