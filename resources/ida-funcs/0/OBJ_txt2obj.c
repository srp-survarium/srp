asn1_object_st *__usercall OBJ_txt2obj@<eax>(int a1@<ebx>, char *s, unsigned __int8 *no_name)
{
  void *v3; // eax
  asn1_object_st *result; // eax
  int v5; // eax
  int v6; // edi
  int v7; // ebx
  unsigned __int8 *v8; // esi
  asn1_object_st *v9; // edi
  unsigned __int8 *v10; // [esp+4h] [ebp-4h] BYREF

  if ( !no_name )
  {
    v3 = OBJ_sn2nid(s);
    if ( v3 )
      return OBJ_nid2obj(a1, (unsigned int)v3);
    v3 = OBJ_ln2nid(s);
    if ( v3 )
      return OBJ_nid2obj(a1, (unsigned int)v3);
  }
  v5 = a2d_ASN1_OBJECT(0, 0, s, 0xFFFFFFFF);
  v6 = v5;
  if ( v5 <= 0 )
    return 0;
  v7 = ASN1_object_size(0, v5, 6);
  result = (asn1_object_st *)CRYPTO_malloc(v7, ".\\crypto\\objects\\obj_dat.c", 452);
  v8 = (unsigned __int8 *)result;
  if ( result )
  {
    no_name = (unsigned __int8 *)result;
    ASN1_put_object(&no_name, 0, v6, 6, 0);
    a2d_ASN1_OBJECT(no_name, v6, s, 0xFFFFFFFF);
    v10 = v8;
    v9 = d2i_ASN1_OBJECT(0, (const unsigned __int8 **)&v10, v7);
    CRYPTO_free(v8);
    return v9;
  }
  return result;
}
