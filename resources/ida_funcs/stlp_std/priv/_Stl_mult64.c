void __usercall stlp_std::priv::_Stl_mult64(
        unsigned __int64 *low@<esi>,
        unsigned __int64 u,
        unsigned __int64 v,
        unsigned __int64 *high)
{
  unsigned __int64 v4; // kr00_8
  unsigned __int64 v5; // kr08_8

  *low = (unsigned int)(v * u);
  v4 = (((unsigned int)v * (unsigned __int64)(unsigned int)u) >> 32) + (unsigned int)v * (unsigned __int64)HIDWORD(u);
  v5 = (unsigned int)v4 + HIDWORD(v) * (unsigned __int64)(unsigned int)u;
  *low += v5 << 32;
  *high = HIDWORD(v4) + HIDWORD(v5) + HIDWORD(v) * (unsigned __int64)HIDWORD(u);
}
