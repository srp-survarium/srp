int __usercall ENGINE_free@<eax>(int a1@<edi>, int a2@<ebx>, engine_st *e)
{
  return engine_free_util(a1, a2, e, 1);
}
