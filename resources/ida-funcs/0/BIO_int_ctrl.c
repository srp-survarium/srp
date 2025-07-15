int __usercall BIO_int_ctrl@<eax>(int a1@<ebx>, bio_st *b, int cmd, int larg, int iarg)
{
  return BIO_ctrl(a1, b, cmd, larg, &iarg);
}
