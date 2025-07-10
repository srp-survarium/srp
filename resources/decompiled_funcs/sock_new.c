int __cdecl sock_new(bio_st *bi)
{
  bi->init = 0;
  bi->num = 0;
  bi->ptr = 0;
  bi->flags = 0;
  return 1;
}
