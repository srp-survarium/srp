dsa_st *__usercall DSA_new@<eax>(int a1@<ebx>)
{
  return DSA_new_method(a1, 0);
}
