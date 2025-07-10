int __cdecl mem_new(bio_st *bi)
{
  int result; // eax

  result = (int)BUF_MEM_new();
  if ( result )
  {
    bi->ptr = (void *)result;
    bi->shutdown = 1;
    bi->init = 1;
    bi->num = -1;
    return 1;
  }
  return result;
}
