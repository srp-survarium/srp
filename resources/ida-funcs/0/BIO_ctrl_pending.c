int __usercall BIO_ctrl_pending@<eax>(int a1@<ebx>, bio_st *bio)
{
  return BIO_ctrl(a1, bio, 10, 0, 0);
}
