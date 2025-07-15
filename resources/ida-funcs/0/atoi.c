unsigned int __usercall atoi@<eax>(int a1@<ebx>, char *nptr)
{
  return atol(a1, nptr);
}
