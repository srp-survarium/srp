unsigned int __usercall atol@<eax>(int a1@<ebx>, char *nptr)
{
  return strtol(a1, nptr, 0, 0xAu);
}
