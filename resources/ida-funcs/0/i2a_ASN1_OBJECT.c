int __usercall i2a_ASN1_OBJECT@<eax>(int a1@<ebx>, bio_st *bp, asn1_object_st *a)
{
  bio_st *v3; // ebp
  char *v4; // esi
  signed int v5; // eax
  int v6; // ebx
  char *v7; // eax
  char str[80]; // [esp+10h] [ebp-54h] BYREF

  v3 = bp;
  v4 = str;
  if ( !a || !a->data )
    return BIO_write(a1, bp, "NULL", 4);
  v5 = OBJ_obj2txt(str, 0x50u, a, 0);
  v6 = v5;
  if ( v5 > 79 )
  {
    v7 = (char *)CRYPTO_malloc(v5 + 1, ".\\crypto\\asn1\\a_object.c", 245);
    v4 = v7;
    if ( !v7 )
      return -1;
    OBJ_obj2txt(v7, v6 + 1, a, 0);
    v3 = bp;
  }
  if ( v6 <= 0 )
    return BIO_write(v6, v3, "<INVALID>", 9);
  BIO_write(v6, v3, v4, v6);
  if ( v4 != str )
    CRYPTO_free(v4);
  return v6;
}
