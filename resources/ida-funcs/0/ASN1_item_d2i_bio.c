struct ASN1_VALUE_st *__usercall ASN1_item_d2i_bio@<eax>(
        int a1@<ebx>,
        const ASN1_ITEM_st *it,
        bio_st *in,
        struct ASN1_VALUE_st **x)
{
  struct ASN1_VALUE_st *v4; // esi
  const unsigned __int8 **v5; // eax
  buf_mem_st *v6; // edi
  buf_mem_st *pb; // [esp+8h] [ebp-8h] BYREF
  char *data; // [esp+Ch] [ebp-4h] BYREF

  pb = 0;
  v4 = 0;
  v5 = (const unsigned __int8 **)asn1_d2i_read_bio(a1, in, &pb);
  v6 = pb;
  if ( (int)v5 >= 0 )
  {
    data = pb->data;
    v4 = ASN1_item_d2i(x, (unsigned __int8 **)&data, v5, it);
  }
  if ( v6 )
    BUF_MEM_free(v6);
  return v4;
}
