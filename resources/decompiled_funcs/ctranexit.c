int __usercall ctranexit@<eax>(int a1@<ebp>)
{
  *(_BYTE *)(a1 - 712) &= ~1u;
  return cintrinexit();
}
