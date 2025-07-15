unsigned int __cdecl Scaleform::Alg::LowerBoundSliced<Scaleform::GUnicodePairType const [641],unsigned short,bool (__cdecl *)(Scaleform::GUnicodePairType const &,unsigned short)>(
        const Scaleform::GUnicodePairType (*arr)[677],
        unsigned int start,
        unsigned int end,
        unsigned __int16 *val,
        bool (__cdecl *less)(const Scaleform::GUnicodePairType *, unsigned __int16))
{
  unsigned int v5; // ebp
  int v6; // edi
  unsigned int v7; // ebx

  v5 = start;
  v6 = end - start;
  while ( v6 > 0 )
  {
    v7 = (v6 >> 1) + v5;
    if ( less(&(*arr)[v7], *val) )
    {
      v5 = v7 + 1;
      v6 += -1 - (v6 >> 1);
    }
    else
    {
      v6 >>= 1;
    }
  }
  return v5;
}
