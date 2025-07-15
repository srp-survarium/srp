int __usercall _rtindfnpop@<eax>(int a1@<ebp>)
{
  if ( *(char *)(a1 - 144) > 0 )
    JUMPOUT(0x2ADFC0);
  return _rttosnpopde();
}
