int __cdecl long_i2c(struct ASN1_VALUE_st **pval, unsigned __int8 *cont, int *putype, const ASN1_ITEM_st *it)
{
  int v4; // edi
  unsigned int v6; // ebx
  int v7; // eax
  unsigned __int8 *v8; // esi
  BOOL v9; // ecx
  int v10; // ebp
  int i; // eax

  v4 = (int)*pval;
  if ( *pval == (struct ASN1_VALUE_st *)it->size )
    return -1;
  if ( v4 >= 0 )
    v6 = (unsigned int)*pval;
  else
    v6 = -1 - v4;
  v7 = BN_num_bits_word(v6);
  v8 = cont;
  v9 = (v7 & 7) == 0;
  v10 = (v7 + 7) >> 3;
  if ( cont )
  {
    if ( (v7 & 7) == 0 )
    {
      *cont = (v4 >= 0) - 1;
      v8 = cont + 1;
    }
    for ( i = v10 - 1; i >= 0; --i )
    {
      v8[i] = v6;
      if ( v4 < 0 )
        v8[i] = ~(_BYTE)v6;
      v6 >>= 8;
    }
  }
  return v9 + v10;
}
