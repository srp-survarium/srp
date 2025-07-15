int __cdecl i2a_ASN1_OBJECT(bio_st *bp, asn1_object_st *a)
{
  bio_st *v2; // ebp
  char *v3; // esi
  signed int v4; // eax
  int v5; // ebx
  char *v6; // eax
  char buf[80]; // [esp+10h] [ebp-54h] BYREF

  v2 = bp;
  v3 = buf;
  if ( !a || !a->data )
    return BIO_write(bp, "NULL", 4);
  v4 = OBJ_obj2txt(buf, 0x50u, a, 0);
  v5 = v4;
  if ( v4 > 79 )
  {
    v6 = (char *)CRYPTO_malloc(v4 + 1, ".\\crypto\\asn1\\a_object.c", 245);
    v3 = v6;
    if ( !v6 )
      return -1;
    OBJ_obj2txt(v6, v5 + 1, a, 0);
    v2 = bp;
  }
  if ( v5 <= 0 )
    return BIO_write(v2, "<INVALID>", 9);
  BIO_write(v2, v3, v5);
  if ( v3 != buf )
    CRYPTO_free(v3);
  return v5;
}
