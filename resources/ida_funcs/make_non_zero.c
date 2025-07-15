int __usercall make_non_zero@<eax>(int a1@<xmm0>)
{
  return a1 & 0x7FFFFFFF;
}
