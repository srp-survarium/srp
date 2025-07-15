asn1_object_st *__usercall OBJ_dup@<eax>(int a1@<ebx>, const asn1_object_st *o)
{
  char *v2; // ebp
  asn1_object_st *v4; // ebx
  unsigned __int8 *v5; // edi
  const __m128i *data; // eax
  const char *ln; // eax
  unsigned int v8; // kr00_4
  char *v9; // eax
  unsigned int v10; // kr04_4
  const char *str; // [esp+8h] [ebp-4h]

  v2 = 0;
  if ( !o )
    return 0;
  if ( (o->flags & 1) == 0 )
    return (asn1_object_st *)o;
  v4 = ASN1_OBJECT_new(a1);
  if ( !v4 )
  {
    ERR_put_error(0, 8u, 101, 13, ".\\crypto\\objects\\obj_lib.c", 80);
    return 0;
  }
  v5 = (unsigned __int8 *)CRYPTO_malloc(o->length, ".\\crypto\\objects\\obj_lib.c", 83);
  if ( !v5 )
    goto err_22;
  data = (const __m128i *)o->data;
  if ( data )
    memcpy((int)v5, data, o->length);
  v4->data = v5;
  v4->length = o->length;
  v4->nid = o->nid;
  v4->sn = 0;
  v4->ln = 0;
  ln = o->ln;
  if ( !ln )
  {
LABEL_13:
    if ( o->sn )
    {
      v10 = strlen(o->sn);
      str = (const char *)CRYPTO_malloc(v10 + 1, ".\\crypto\\objects\\obj_lib.c", 105);
      if ( !str )
        goto err_22;
      memcpy((int)str, (const __m128i *)o->sn, v10 + 1);
      v4->sn = str;
    }
    v4->flags = o->flags | 0xD;
    return v4;
  }
  v8 = strlen(ln);
  v9 = (char *)CRYPTO_malloc(v8 + 1, ".\\crypto\\objects\\obj_lib.c", 96);
  v2 = v9;
  if ( v9 )
  {
    memcpy((int)v9, (const __m128i *)o->ln, v8 + 1);
    v4->ln = v2;
    goto LABEL_13;
  }
err_22:
  ERR_put_error((int)v4, 8u, 101, 65, ".\\crypto\\objects\\obj_lib.c", 114);
  if ( v2 )
    CRYPTO_free(v2);
  if ( v5 )
    CRYPTO_free(v5);
  CRYPTO_free(v4);
  return 0;
}
