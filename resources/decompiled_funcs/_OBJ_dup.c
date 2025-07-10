asn1_object_st *__cdecl OBJ_dup(const asn1_object_st *o)
{
  unsigned __int8 *v2; // ebp
  asn1_object_st *v4; // ebx
  unsigned __int8 *v5; // edi
  unsigned __int8 *data; // eax
  const char *ln; // eax
  unsigned int v8; // edi
  unsigned __int8 *v9; // eax
  unsigned int v10; // edi
  unsigned __int8 *str; // [esp+8h] [ebp-4h]
  unsigned __int8 *v12; // [esp+10h] [ebp+4h]

  v2 = 0;
  if ( !o )
    return 0;
  if ( (o->flags & 1) == 0 )
    return (asn1_object_st *)o;
  v4 = ASN1_OBJECT_new();
  if ( !v4 )
  {
    ERR_put_error(8u, 101, 13, ".\\crypto\\objects\\obj_lib.c", 80);
    return 0;
  }
  v5 = (unsigned __int8 *)CRYPTO_malloc(o->length, ".\\crypto\\objects\\obj_lib.c", 83);
  v12 = v5;
  if ( !v5 )
    goto err_20;
  data = (unsigned __int8 *)o->data;
  if ( data )
    memcpy(v5, data, o->length);
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
      v10 = strlen(o->sn) + 1;
      str = (unsigned __int8 *)CRYPTO_malloc(v10, ".\\crypto\\objects\\obj_lib.c", 105);
      if ( !str )
        goto LABEL_15;
      memcpy(str, (unsigned __int8 *)o->sn, v10);
      v4->sn = (const char *)str;
    }
    v4->flags = o->flags | 0xD;
    return v4;
  }
  v8 = strlen(ln) + 1;
  v9 = (unsigned __int8 *)CRYPTO_malloc(v8, ".\\crypto\\objects\\obj_lib.c", 96);
  v2 = v9;
  if ( v9 )
  {
    memcpy(v9, (unsigned __int8 *)o->ln, v8);
    v4->ln = (const char *)v2;
    goto LABEL_13;
  }
LABEL_15:
  v5 = v12;
err_20:
  ERR_put_error(8u, 101, 65, ".\\crypto\\objects\\obj_lib.c", 114);
  if ( v2 )
    CRYPTO_free(v2);
  if ( v5 )
    CRYPTO_free(v5);
  CRYPTO_free(v4);
  return 0;
}
