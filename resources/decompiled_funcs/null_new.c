int __cdecl null_new(bio_st *bi)
{
  bi->init = 1;
  bi->num = 0;
  bi->ptr = 0;
  return 1;
}
