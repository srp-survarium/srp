rsa_st *__usercall RSA_new@<eax>(int a1@<ebx>)
{
  return RSA_new_method(a1, 0);
}
