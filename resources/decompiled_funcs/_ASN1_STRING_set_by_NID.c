asn1_string_st *__cdecl ASN1_STRING_set_by_NID(
        asn1_string_st **out,
        unsigned __int8 *in,
        int inlen,
        int inform,
        int nid)
{
  asn1_string_st **v5; // esi
  asn1_string_table_st *v6; // eax
  unsigned int mask; // ecx
  int v8; // eax
  int v10; // [esp+4h] [ebp-4h] BYREF

  v5 = out;
  v10 = 0;
  if ( !out )
    v5 = (asn1_string_st **)&v10;
  v6 = ASN1_STRING_TABLE_get(nid);
  if ( v6 )
  {
    mask = v6->mask;
    if ( (v6->flags & 2) == 0 )
      mask &= global_mask;
    v8 = ASN1_mbstring_ncopy(v5, in, inlen, inform, mask, v6->minsize, v6->maxsize);
  }
  else
  {
    v8 = ASN1_mbstring_copy(v5, in, inlen, inform, global_mask & 0x2806);
  }
  if ( v8 > 0 )
    return *v5;
  else
    return 0;
}
