int __cdecl asn1_ex_c2i(
        asn1_type_st **pval,
        const __m128i *cont,
        int len,
        int utype,
        char *free_cont,
        const ASN1_ITEM_st *it)
{
  _DWORD *funcs; // eax
  int (__cdecl *v7)(asn1_type_st **, const __m128i *, int, int, char *, const ASN1_ITEM_st *); // eax
  int v9; // edi
  asn1_type_st *v10; // eax
  asn1_type_st *v11; // ebp
  asn1_string_st **p_value; // ebp
  asn1_string_st *v13; // esi
  asn1_string_st *v14; // eax
  char *v15; // ebx
  int v16; // eax
  asn1_type_st *a; // [esp+4h] [ebp-Ch]
  asn1_type_st **v18; // [esp+8h] [ebp-8h]

  funcs = it->funcs;
  v18 = 0;
  a = 0;
  if ( funcs )
  {
    v7 = (int (__cdecl *)(asn1_type_st **, const __m128i *, int, int, char *, const ASN1_ITEM_st *))funcs[5];
    if ( v7 )
      return v7(pval, cont, len, utype, free_cont, it);
  }
  v9 = utype;
  if ( it->utype == -4 )
  {
    if ( *pval )
    {
      a = *pval;
      v11 = *pval;
    }
    else
    {
      v10 = ASN1_TYPE_new();
      a = v10;
      if ( !v10 )
        goto LABEL_20;
      v11 = v10;
      *pval = v10;
    }
    if ( v9 != v11->type )
      ASN1_TYPE_set(v11, v9, 0);
    v18 = pval;
    p_value = (asn1_string_st **)&v11->value;
  }
  else
  {
    p_value = (asn1_string_st **)pval;
  }
  if ( v9 <= 10 )
  {
    if ( v9 != 10 )
    {
      switch ( v9 )
      {
        case 1:
          if ( len != 1 )
          {
            ERR_put_error(0, 0xDu, 204, 106, ".\\crypto\\asn1\\tasn_dec.c", 971);
            goto LABEL_20;
          }
          *p_value = (asn1_string_st *)cont->m128i_u8[0];
          goto LABEL_50;
        case 2:
          goto $LN38_6;
        case 3:
          if ( c2i_ASN1_BIT_STRING(p_value, (unsigned __int8 **)&cont, len) )
            goto LABEL_50;
          goto LABEL_20;
        case 5:
          if ( len )
          {
            ERR_put_error(0, 0xDu, 204, 144, ".\\crypto\\asn1\\tasn_dec.c", 961);
            goto LABEL_20;
          }
          *p_value = (asn1_string_st *)1;
          break;
        case 6:
          if ( c2i_ASN1_OBJECT((asn1_object_st **)p_value, &cont, len) )
            goto LABEL_50;
          goto LABEL_20;
        default:
          goto LABEL_31;
      }
      goto LABEL_50;
    }
$LN38_6:
    if ( c2i_ASN1_INTEGER(p_value, &cont, len) )
    {
      (*p_value)->type = v9 | (*p_value)->type & 0x100;
      goto LABEL_50;
    }
LABEL_20:
    ASN1_TYPE_free(a);
    if ( v18 )
      *v18 = 0;
    return 0;
  }
  if ( v9 == 258 || v9 == 266 )
    goto $LN38_6;
LABEL_31:
  if ( v9 == 30 )
  {
    if ( (len & 1) != 0 )
    {
      ERR_put_error(0, 0xDu, 204, 214, ".\\crypto\\asn1\\tasn_dec.c", 1019);
      goto LABEL_20;
    }
  }
  else if ( v9 == 28 && (len & 3) != 0 )
  {
    ERR_put_error(0, 0xDu, 204, 215, ".\\crypto\\asn1\\tasn_dec.c", 1025);
    goto LABEL_20;
  }
  v13 = *p_value;
  if ( *p_value )
  {
    v13->type = v9;
  }
  else
  {
    v14 = ASN1_STRING_type_new(0, v9);
    v13 = v14;
    if ( !v14 )
    {
      ERR_put_error(0, 0xDu, 204, 65, ".\\crypto\\asn1\\tasn_dec.c", 1035);
      goto LABEL_20;
    }
    *p_value = v14;
  }
  v15 = free_cont;
  if ( *free_cont )
  {
    if ( v13->data )
      CRYPTO_free(v13->data);
    v16 = len;
    v13->data = (unsigned __int8 *)cont;
    v13->length = v16;
    *v15 = 0;
    goto LABEL_50;
  }
  if ( !ASN1_STRING_set(v13, cont, len) )
  {
    ERR_put_error((int)v15, 0xDu, 204, 65, ".\\crypto\\asn1\\tasn_dec.c", 1059);
    ASN1_STRING_free(v13);
    *p_value = 0;
    goto LABEL_20;
  }
LABEL_50:
  if ( a && v9 == 5 )
    a->value.boolean = 0;
  return 1;
}
