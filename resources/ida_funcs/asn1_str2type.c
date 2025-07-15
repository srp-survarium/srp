asn1_type_st *__cdecl asn1_str2type(int format, unsigned int utype)
{
  char *str; // ecx
  char *v3; // edi
  asn1_type_st *v4; // esi
  asn1_string_st *v6; // eax
  asn1_object_st *v7; // eax
  asn1_string_st *v8; // eax
  int v9; // ebp
  unsigned int v10; // eax
  asn1_string_st *v11; // eax
  unsigned __int8 *v12; // eax
  int len; // [esp+Ch] [ebp-10h] BYREF
  CONF_VALUE value; // [esp+10h] [ebp-Ch] BYREF

  v3 = str;
  v4 = ASN1_TYPE_new();
  if ( !v4 )
  {
    ERR_put_error(0xDu, 179, 65, ".\\crypto\\asn1\\asn1_gen.c", 642);
    return 0;
  }
  if ( !v3 )
    v3 = (char *)&buf;
  switch ( utype )
  {
    case 1u:
      if ( format == 1 )
      {
        value.name = 0;
        value.section = 0;
        value.value = v3;
        if ( X509V3_get_value_bool(&value, (int *)&v4->value) )
          goto LABEL_44;
        ERR_put_error(0xDu, 179, 176, ".\\crypto\\asn1\\asn1_gen.c", 671);
        goto LABEL_53;
      }
      ERR_put_error(0xDu, 179, 190, ".\\crypto\\asn1\\asn1_gen.c", 663);
      ASN1_TYPE_free(v4);
      return 0;
    case 2u:
    case 0xAu:
      if ( format == 1 )
      {
        v6 = s2i_ASN1_INTEGER(0, v3);
        v4->value.boolean = (int)v6;
        if ( v6 )
          goto LABEL_44;
        ERR_put_error(0xDu, 179, 180, ".\\crypto\\asn1\\asn1_gen.c", 685);
        goto LABEL_53;
      }
      ERR_put_error(0xDu, 179, 185, ".\\crypto\\asn1\\asn1_gen.c", 680);
      ASN1_TYPE_free(v4);
      return 0;
    case 3u:
    case 4u:
      v11 = ASN1_STRING_new();
      v4->value.boolean = (int)v11;
      if ( !v11 )
      {
        ERR_put_error(0xDu, 179, 65, ".\\crypto\\asn1\\asn1_gen.c", 766);
        ASN1_TYPE_free(v4);
        return 0;
      }
      if ( format == 3 )
      {
        v12 = string_to_hex(v3, &len);
        if ( !v12 )
        {
          ERR_put_error(0xDu, 179, 178, ".\\crypto\\asn1\\asn1_gen.c", 775);
          goto LABEL_53;
        }
        *(_DWORD *)(v4->value.boolean + 8) = v12;
        *(_DWORD *)v4->value.ptr = len;
        *(_DWORD *)(v4->value.boolean + 4) = utype;
        goto LABEL_42;
      }
      if ( format == 1 )
      {
        ASN1_STRING_set(v11, v3, -1);
LABEL_42:
        if ( utype == 3 )
        {
          *(_DWORD *)(v4->value.boolean + 12) &= 0xFFFFFFF0;
          *(_DWORD *)(v4->value.boolean + 12) |= 8u;
        }
        goto LABEL_44;
      }
      if ( format == 4 && utype == 3 )
      {
        if ( CONF_parse_list(v3, 0x2Cu, 1, (int (__cdecl *)(const char *, int, void *))bitstr_cb, v11) )
          goto LABEL_44;
        ERR_put_error(0xDu, 179, 188, ".\\crypto\\asn1\\asn1_gen.c", 790);
LABEL_53:
        ERR_add_error_data(2, "string=", v3);
        ASN1_TYPE_free(v4);
        return 0;
      }
      else
      {
        ERR_put_error(0xDu, 179, 175, ".\\crypto\\asn1\\asn1_gen.c", 798);
        ASN1_TYPE_free(v4);
        return 0;
      }
    case 5u:
      if ( !v3 || !*v3 )
        goto LABEL_44;
      ERR_put_error(0xDu, 179, 182, ".\\crypto\\asn1\\asn1_gen.c", 655);
      ASN1_TYPE_free(v4);
      return 0;
    case 6u:
      if ( format != 1 )
      {
        ERR_put_error(0xDu, 179, 191, ".\\crypto\\asn1\\asn1_gen.c", 693);
        ASN1_TYPE_free(v4);
        return 0;
      }
      v7 = OBJ_txt2obj(v3, 0);
      v4->value.boolean = (int)v7;
      if ( v7 )
        goto LABEL_44;
      ERR_put_error(0xDu, 179, 183, ".\\crypto\\asn1\\asn1_gen.c", 698);
      goto LABEL_53;
    case 0xCu:
    case 0x12u:
    case 0x13u:
    case 0x14u:
    case 0x16u:
    case 0x1Au:
    case 0x1Bu:
    case 0x1Cu:
    case 0x1Eu:
      if ( format == 1 )
      {
        v9 = 4097;
      }
      else
      {
        if ( format != 2 )
        {
          ERR_put_error(0xDu, 179, 177, ".\\crypto\\asn1\\asn1_gen.c", 745);
          ASN1_TYPE_free(v4);
          return 0;
        }
        v9 = 4096;
      }
      v10 = ASN1_tag2bit(utype);
      if ( ASN1_mbstring_copy((asn1_string_st **)&v4->value, (const unsigned __int8 *)v3, -1, v9, v10) > 0 )
        goto LABEL_44;
      ERR_put_error(0xDu, 179, 65, ".\\crypto\\asn1\\asn1_gen.c", 753);
      goto LABEL_53;
    case 0x17u:
    case 0x18u:
      if ( format != 1 )
      {
        ERR_put_error(0xDu, 179, 193, ".\\crypto\\asn1\\asn1_gen.c", 707);
        ASN1_TYPE_free(v4);
        return 0;
      }
      v8 = ASN1_STRING_new();
      v4->value.boolean = (int)v8;
      if ( !v8 )
      {
        ERR_put_error(0xDu, 179, 65, ".\\crypto\\asn1\\asn1_gen.c", 712);
        goto LABEL_53;
      }
      if ( !ASN1_STRING_set(v8, v3, -1) )
      {
        ERR_put_error(0xDu, 179, 65, ".\\crypto\\asn1\\asn1_gen.c", 717);
        goto LABEL_53;
      }
      *(_DWORD *)(v4->value.boolean + 4) = utype;
      if ( !ASN1_TIME_check(v4->value.asn1_string) )
      {
        ERR_put_error(0xDu, 179, 184, ".\\crypto\\asn1\\asn1_gen.c", 723);
        goto LABEL_53;
      }
LABEL_44:
      v4->type = utype;
      return v4;
    default:
      ERR_put_error(0xDu, 179, 196, ".\\crypto\\asn1\\asn1_gen.c", 814);
      goto LABEL_53;
  }
}
