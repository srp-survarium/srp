void __usercall stlp_std::priv::_Stl_norm_and_round(
        unsigned __int64 *p@<eax>,
        int *norm@<ecx>,
        unsigned __int64 prodhi,
        unsigned __int64 prodlo)
{
  int v4; // edx
  int v5; // ebp
  unsigned __int64 v6; // kr00_8

  *norm = 0;
  if ( (prodhi & 0x8000000000000000uLL) != 0LL )
  {
    v5 = HIDWORD(prodlo);
    v4 = prodlo;
    *p = prodhi;
  }
  else
  {
    if ( prodhi == 0x7FFFFFFFFFFFFFFFLL && HIDWORD(prodlo) >> 30 == 3 )
    {
      *(_DWORD *)p = 0;
      *((_DWORD *)p + 1) = 0x80000000;
      return;
    }
    *(_DWORD *)p = (2 * prodhi) | (HIDWORD(prodlo) >> 31);
    *((_DWORD *)p + 1) = prodhi >> 31;
    *norm = 1;
    v4 = 2 * prodlo;
    v5 = prodlo >> 31;
  }
  if ( v5 < 0 && ((*(_DWORD *)p & 1) != 0 || v4 || v5 != 0x80000000) )
  {
    v6 = *p + 1;
    *p = v6;
    if ( !v6 )
      *p = 1;
  }
}
