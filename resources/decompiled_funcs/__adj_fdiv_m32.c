void __userpurge __spoils<edx,ecx,st0> _adj_fdiv_m32(__int16 a1@<fpstat>, double a2@<st1>, double a3@<st0>, float a4)
{
  if ( (LODWORD(a4) & 0x7F800000) != 0x7F800000 )
  {
    if ( (a1 & 0x3800) != 0 )
      _fdivp_sti_st(a2, a3);
    else
      _fdivp_sti_st(a4, a2);
  }
}
