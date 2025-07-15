GENERAL_NAME_st *__usercall a2i_GENERAL_NAME@<eax>(
        int a1@<ebx>,
        GENERAL_NAME_st *out,
        const v3_ext_method *method,
        v3_ext_ctx *ctx,
        int gen_type,
        __m128i *value,
        int is_nc)
{
  GENERAL_NAME_st *result; // eax
  GENERAL_NAME_st *v8; // edi
  GENERAL_NAME_st *v9; // ebx
  asn1_object_st *v10; // eax
  asn1_string_st *v11; // eax
  asn1_string_st *v12; // eax

  if ( !value )
  {
    ERR_put_error(a1, 0x22u, 164, 124, ".\\crypto\\x509v3\\v3_alt.c", 433);
    return 0;
  }
  v8 = out;
  if ( out )
  {
    v9 = out;
  }
  else
  {
    v9 = GENERAL_NAME_new();
    if ( !v9 )
    {
      ERR_put_error(0, 0x22u, 164, 65, ".\\crypto\\x509v3\\v3_alt.c", 444);
      return 0;
    }
  }
  switch ( gen_type )
  {
    case 0:
      if ( do_othername(v9, value->m128i_i8, ctx) )
        goto LABEL_11;
      ERR_put_error((int)v9, 0x22u, 164, 147, ".\\crypto\\x509v3\\v3_alt.c", 494);
      goto err_38;
    case 1:
    case 2:
    case 6:
      v12 = ASN1_STRING_type_new((int)v9, 22);
      v9->d.ptr = (char *)v12;
      if ( !v12 )
        goto LABEL_24;
      if ( ASN1_STRING_set(v12, value, strlen(value->m128i_i8)) )
        goto LABEL_11;
      v8 = out;
LABEL_24:
      ERR_put_error((int)v9, 0x22u, 164, 65, ".\\crypto\\x509v3\\v3_alt.c", 509);
      goto err_38;
    case 4:
      if ( do_dirname(v9, ctx) )
        goto LABEL_11;
      ERR_put_error((int)v9, 0x22u, 164, 149, ".\\crypto\\x509v3\\v3_alt.c", 486);
      goto err_38;
    case 7:
      if ( is_nc )
        a2i_IPADDRESS_NC(value->m128i_i8);
      else
        v11 = a2i_IPADDRESS(value->m128i_i8);
      v9->d.ptr = (char *)v11;
      if ( v11 )
        goto LABEL_11;
      ERR_put_error((int)v9, 0x22u, 164, 118, ".\\crypto\\x509v3\\v3_alt.c", 477);
      ERR_add_error_data(2, "value=", value);
      goto err_38;
    case 8:
      v10 = OBJ_txt2obj((int)v9, value->m128i_i8, 0);
      if ( v10 )
      {
        v9->d.ptr = (char *)v10;
LABEL_11:
        v9->type = gen_type;
        result = v9;
      }
      else
      {
        ERR_put_error((int)v9, 0x22u, 164, 119, ".\\crypto\\x509v3\\v3_alt.c", 462);
        ERR_add_error_data(2, "value=", value);
err_38:
        if ( !v8 )
          GENERAL_NAME_free(v9);
        result = 0;
      }
      break;
    default:
      ERR_put_error((int)v9, 0x22u, 164, 167, ".\\crypto\\x509v3\\v3_alt.c", 499);
      goto err_38;
  }
  return result;
}
