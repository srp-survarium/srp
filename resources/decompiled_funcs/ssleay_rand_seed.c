void __usercall ssleay_rand_seed(unsigned int a1@<edi>, char *buf, int num)
{
  void *v3; // esp

  v3 = alloca(8);
  ssleay_rand_add(a1, buf, num, (double)num);
}
