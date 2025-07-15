asn1_type_st *__cdecl asn1_multi(int utype, const char *section, v3_ext_ctx *cnf)
{
  stack_st_CONF_VALUE *v3; // edi
  asn1_type_st *v4; // ebp
  stack_st_ASN1_TYPE *v5; // esi
  v3_ext_ctx *v6; // ebx
  stack_st_CONF_VALUE *v7; // eax
  int v8; // esi
  char *v9; // eax
  char *v10; // eax
  int v11; // eax
  int v12; // esi
  asn1_string_st *v13; // eax
  stack_st *st; // [esp+10h] [ebp-8h]
  unsigned __int8 *out; // [esp+14h] [ebp-4h] BYREF

  v3 = 0;
  v4 = 0;
  out = 0;
  v5 = (stack_st_ASN1_TYPE *)sk_new_null();
  st = &v5->stack;
  if ( !v5 )
  {
    v6 = cnf;
    goto bad;
  }
  if ( !section )
    goto LABEL_10;
  v6 = cnf;
  if ( cnf )
  {
    v7 = X509V3_get_section((int)cnf, cnf);
    v3 = v7;
    if ( v7 )
    {
      v8 = 0;
      if ( sk_num(&v7->stack) > 0 )
      {
        while ( 1 )
        {
          v9 = sk_value(&v3->stack, v8);
          v10 = (char *)ASN1_generate_v3(*((char **)v9 + 2), cnf);
          if ( !v10 || !sk_push(st, v10) )
            break;
          if ( ++v8 >= sk_num(&v3->stack) )
            goto LABEL_9;
        }
LABEL_19:
        v5 = (stack_st_ASN1_TYPE *)st;
        goto bad;
      }
LABEL_9:
      v5 = (stack_st_ASN1_TYPE *)st;
LABEL_10:
      if ( utype == 17 )
        v11 = i2d_ASN1_SET_ANY(v5, &out);
      else
        v11 = i2d_ASN1_SEQUENCE_ANY(v5, &out);
      v12 = v11;
      if ( v11 >= 0 )
      {
        v4 = ASN1_TYPE_new();
        if ( v4 )
        {
          v13 = ASN1_STRING_type_new(utype, utype);
          v4->value.boolean = (int)v13;
          if ( v13 )
          {
            v4->type = utype;
            v6 = cnf;
            v13->data = out;
            *(_DWORD *)v4->value.ptr = v12;
            v5 = (stack_st_ASN1_TYPE *)st;
            out = 0;
            goto LABEL_22;
          }
        }
      }
      v6 = cnf;
      goto LABEL_19;
    }
  }
bad:
  if ( out )
    CRYPTO_free(out);
LABEL_22:
  if ( v5 )
    sk_pop_free(&v5->stack, (void (__cdecl *)(void *))ASN1_TYPE_free);
  if ( v3 )
    X509V3_section_free(v6, v3);
  return v4;
}
