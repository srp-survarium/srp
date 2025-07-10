int __cdecl BIO_int_ctrl(bio_st *b, int cmd, int larg, int iarg)
{
  return BIO_ctrl(b, cmd, larg, &iarg);
}
