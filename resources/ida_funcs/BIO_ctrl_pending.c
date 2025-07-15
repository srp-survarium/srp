int __cdecl BIO_ctrl_pending(bio_st *bio)
{
  return BIO_ctrl(bio, 10, 0, 0);
}
