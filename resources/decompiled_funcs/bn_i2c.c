int __cdecl bn_i2c(struct ASN1_VALUE_st **pval, unsigned __int8 *cont)
{
  const bignum_st *v2; // esi
  bool v4; // zf
  unsigned __int8 *v5; // eax
  BOOL v6; // edi

  v2 = (const bignum_st *)*pval;
  if ( !*pval )
    return -1;
  v4 = (BN_num_bits(v2) & 7) == 0;
  v5 = cont;
  v6 = v4;
  if ( cont )
  {
    if ( v4 )
    {
      *cont = 0;
      v5 = cont + 1;
    }
    BN_bn2bin(v2, v5);
  }
  return v6 + (BN_num_bits(v2) + 7) / 8;
}
