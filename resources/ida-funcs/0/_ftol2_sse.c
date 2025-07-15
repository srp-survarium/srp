unsigned int __usercall _ftol2_sse@<eax>(double a1@<st0>)
{
  if ( __sse2_available )
    return _ftol2_pentium4(a1);
  else
    return _ftol2(a1);
}
