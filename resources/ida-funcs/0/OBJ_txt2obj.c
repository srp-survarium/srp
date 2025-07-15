asn1_object_st *__cdecl OBJ_txt2obj(char *s, unsigned __int8 *no_name)
{
  unsigned int v2; // eax
  asn1_object_st *result; // eax
  int v4; // eax
  int v5; // edi
  int v6; // ebx
  unsigned __int8 *v7; // esi
  asn1_object_st *v8; // edi
  unsigned __int8 *v9; // [esp+4h] [ebp-4h] BYREF

  if ( !no_name )
  {
    v2 = OBJ_sn2nid(s);
    if ( v2 )
      return OBJ_nid2obj(v2);
    v2 = OBJ_ln2nid(s);
    if ( v2 )
      return OBJ_nid2obj(v2);
  }
  v4 = a2d_ASN1_OBJECT(0, 0, s, -1);
  v5 = v4;
  if ( v4 <= 0 )
    return 0;
  v6 = ASN1_object_size(0, v4, 6);
  result = (asn1_object_st *)CRYPTO_malloc(v6, ".\\crypto\\objects\\obj_dat.c", 452);
  v7 = (unsigned __int8 *)result;
  if ( result )
  {
    no_name = (unsigned __int8 *)result;
    ASN1_put_object(&no_name, 0, v5, 6, 0);
    a2d_ASN1_OBJECT(no_name, v5, s, -1);
    v9 = v7;
    v8 = d2i_ASN1_OBJECT(0, (const unsigned __int8 **)&v9, v6);
    CRYPTO_free(v7);
    return v8;
  }
  return result;
}
