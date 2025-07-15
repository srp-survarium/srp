void __userpurge __spoils<edx,ecx,st0> _adj_fdiv_m64(__int16 a1@<fpstat>, double a2@<st1>, double a3@<st0>, double a4)
{
  if ( (HIDWORD(a4) & 0x7FF00000) != 0x7FF00000 )
  {
    if ( (a1 & 0x3800) != 0 )
      _fdivp_sti_st(a2, a3);
    else
      _fdivp_sti_st(a4, a2);
  }
}
