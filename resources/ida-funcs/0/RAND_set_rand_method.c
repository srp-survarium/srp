int __usercall RAND_set_rand_method@<eax>(int a1@<edi>, const rand_meth_st *meth)
{
  if ( funct_ref )
  {
    ENGINE_finish(a1, funct_ref);
    default_RAND_meth = meth;
    funct_ref = 0;
  }
  else
  {
    default_RAND_meth = meth;
  }
  return 1;
}
