void __cdecl asn1_enc_init(struct ASN1_VALUE_st **pval, const ASN1_ITEM_st *it)
{
  _DWORD *funcs; // eax
  _DWORD *v3; // eax

  if ( pval )
  {
    if ( *pval )
    {
      funcs = it->funcs;
      if ( funcs )
      {
        if ( (funcs[1] & 2) != 0 )
        {
          v3 = (_DWORD *)((char *)*pval + funcs[5]);
          if ( v3 )
          {
            *v3 = 0;
            v3[1] = 0;
            v3[2] = 1;
          }
        }
      }
    }
  }
}
