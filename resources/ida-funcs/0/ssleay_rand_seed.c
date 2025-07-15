void __usercall ssleay_rand_seed(int a1@<edi>, int a2@<ebx>, char *buf, int num)
{
  void *v4; // esp

  v4 = alloca(8);
  ssleay_rand_add(a1, a2, buf, num, (double)num);
}
