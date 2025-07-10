GENERAL_NAME_st *__cdecl a2i_GENERAL_NAME(
        GENERAL_NAME_st *out,
        const v3_ext_method *method,
        v3_ext_ctx *ctx,
        int gen_type,
        char *value,
        int is_nc)
{
  GENERAL_NAME_st *result; // eax
  GENERAL_NAME_st *v7; // edi
  GENERAL_NAME_st *v8; // ebx
  asn1_object_st *v9; // eax
  asn1_string_st *v10; // eax
  asn1_string_st *v11; // eax

  if ( !value )
  {
    ERR_put_error(0x22u, 164, 124, ".\\crypto\\x509v3\\v3_alt.c", 433);
    return 0;
  }
  v7 = out;
  if ( out )
  {
    v8 = out;
  }
  else
  {
    v8 = GENERAL_NAME_new();
    if ( !v8 )
    {
      ERR_put_error(0x22u, 164, 65, ".\\crypto\\x509v3\\v3_alt.c", 444);
      return 0;
    }
  }
  switch ( gen_type )
  {
    case 0:
      if ( do_othername(v8, value, ctx) )
        goto LABEL_11;
      ERR_put_error(0x22u, 164, 147, ".\\crypto\\x509v3\\v3_alt.c", 494);
      goto err_36;
    case 1:
    case 2:
    case 6:
      v11 = ASN1_STRING_type_new(22);
      v8->d.ptr = (char *)v11;
      if ( !v11 )
        goto LABEL_24;
      if ( ASN1_STRING_set(v11, value, strlen(value)) )
        goto LABEL_11;
      v7 = out;
LABEL_24:
      ERR_put_error(0x22u, 164, 65, ".\\crypto\\x509v3\\v3_alt.c", 509);
      goto err_36;
    case 4:
      if ( do_dirname(v8, ctx) )
        goto LABEL_11;
      ERR_put_error(0x22u, 164, 149, ".\\crypto\\x509v3\\v3_alt.c", 486);
      goto err_36;
    case 7:
      if ( is_nc )
        v10 = a2i_IPADDRESS_NC(value);
      else
        v10 = a2i_IPADDRESS(value);
      v8->d.ptr = (char *)v10;
      if ( v10 )
        goto LABEL_11;
      ERR_put_error(0x22u, 164, 118, ".\\crypto\\x509v3\\v3_alt.c", 477);
      ERR_add_error_data(2, "value=", value);
      goto err_36;
    case 8:
      v9 = OBJ_txt2obj(value, 0);
      if ( v9 )
      {
        v8->d.ptr = (char *)v9;
LABEL_11:
        v8->type = gen_type;
        result = v8;
      }
      else
      {
        ERR_put_error(0x22u, 164, 119, ".\\crypto\\x509v3\\v3_alt.c", 462);
        ERR_add_error_data(2, "value=", value);
err_36:
        if ( !v7 )
          GENERAL_NAME_free(v8);
        result = 0;
      }
      break;
    default:
      ERR_put_error(0x22u, 164, 167, ".\\crypto\\x509v3\\v3_alt.c", 499);
      goto err_36;
  }
  return result;
}
