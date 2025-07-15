int __usercall _rtindfnpop@<eax>(int a1@<ebp>)
{
  if ( *(char *)(a1 - 144) > 0 )
    JUMPOUT(0x1996C0);
  return _rttosnpopde();
}
