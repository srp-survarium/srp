asn1_string_st *__usercall ASN1_STRING_set_by_NID@<eax>(
        int a1@<edi>,
        asn1_string_st **out,
        unsigned __int8 *in,
        int inlen,
        int inform,
        int nid)
{
  asn1_string_st **v6; // esi
  asn1_string_table_st *v7; // eax
  unsigned int mask; // ecx
  int v9; // eax
  int v11; // [esp+4h] [ebp-4h] BYREF

  v6 = out;
  v11 = 0;
  if ( !out )
    v6 = (asn1_string_st **)&v11;
  v7 = ASN1_STRING_TABLE_get(a1, nid);
  if ( v7 )
  {
    mask = v7->mask;
    if ( (v7->flags & 2) == 0 )
      mask &= global_mask;
    v9 = ASN1_mbstring_ncopy(v6, in, inlen, inform, mask, v7->minsize, v7->maxsize);
  }
  else
  {
    v9 = ASN1_mbstring_copy(v6, in, inlen, inform, global_mask & 0x2806);
  }
  if ( v9 > 0 )
    return *v6;
  else
    return 0;
}
