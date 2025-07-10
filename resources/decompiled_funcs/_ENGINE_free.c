int __usercall ENGINE_free@<eax>(unsigned int a1@<edi>, engine_st *e)
{
  return engine_free_util(a1, e, 1);
}
