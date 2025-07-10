void __userpurge __spoils<edx,ecx,st0> _adj_fdivr_m16i(
        __int16 a1@<fpstat>,
        double a2@<st1>,
        double a3@<st0>,
        __int16 a4)
{
  if ( (a1 & 0x3800) != 0 )
    _fdivrp_sti_st(a2, a3);
  else
    _fdivrp_sti_st((double)a4, a2);
}
