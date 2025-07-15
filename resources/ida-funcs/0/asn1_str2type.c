asn1_type_st *__usercall asn1_str2type@<eax>(__m128i *a1@<ecx>, char a2@<bl>, int format, unsigned int utype)
{
  asn1_type_st *v5; // esi
  asn1_string_st *v7; // eax
  asn1_object_st *v8; // eax
  asn1_string_st *v9; // eax
  int v10; // ebp
  unsigned int v11; // eax
  asn1_string_st *v12; // eax
  unsigned __int8 *v13; // eax
  int len; // [esp+Ch] [ebp-10h] BYREF
  CONF_VALUE value; // [esp+10h] [ebp-Ch] BYREF

  v5 = ASN1_TYPE_new();
  if ( !v5 )
  {
    ERR_put_error(a2, 0xDu, 179, 65, ".\\crypto\\asn1\\asn1_gen.c", 642);
    return 0;
  }
  if ( !a1 )
    a1 = (__m128i *)uri;
  switch ( utype )
  {
    case 1u:
      if ( format == 1 )
      {
        value.name = 0;
        value.section = 0;
        value.value = (char *)a1;
        if ( X509V3_get_value_bool(a2, &value, (int *)&v5->value) )
          goto LABEL_44;
        ERR_put_error(a2, 0xDu, 179, 176, ".\\crypto\\asn1\\asn1_gen.c", 671);
        goto LABEL_53;
      }
      ERR_put_error(a2, 0xDu, 179, 190, ".\\crypto\\asn1\\asn1_gen.c", 663);
      ASN1_TYPE_free(v5);
      return 0;
    case 2u:
    case 0xAu:
      if ( format == 1 )
      {
        v7 = s2i_ASN1_INTEGER(a2, 0, a1->m128i_i8);
        v5->value.boolean = (int)v7;
        if ( v7 )
          goto LABEL_44;
        ERR_put_error(a2, 0xDu, 179, 180, ".\\crypto\\asn1\\asn1_gen.c", 685);
        goto LABEL_53;
      }
      ERR_put_error(a2, 0xDu, 179, 185, ".\\crypto\\asn1\\asn1_gen.c", 680);
      ASN1_TYPE_free(v5);
      return 0;
    case 3u:
    case 4u:
      v12 = ASN1_STRING_new(a2);
      v5->value.boolean = (int)v12;
      if ( !v12 )
      {
        ERR_put_error(a2, 0xDu, 179, 65, ".\\crypto\\asn1\\asn1_gen.c", 766);
        ASN1_TYPE_free(v5);
        return 0;
      }
      if ( format == 3 )
      {
        v13 = string_to_hex(a2, a1->m128i_i8, &len);
        if ( !v13 )
        {
          ERR_put_error(a2, 0xDu, 179, 178, ".\\crypto\\asn1\\asn1_gen.c", 775);
          goto LABEL_53;
        }
        *(_DWORD *)(v5->value.boolean + 8) = v13;
        *(_DWORD *)v5->value.ptr = len;
        *(_DWORD *)(v5->value.boolean + 4) = utype;
        goto LABEL_42;
      }
      if ( format == 1 )
      {
        ASN1_STRING_set(v12, a1, -1);
LABEL_42:
        if ( utype == 3 )
        {
          *(_DWORD *)(v5->value.boolean + 12) &= 0xFFFFFFF0;
          *(_DWORD *)(v5->value.boolean + 12) |= 8u;
        }
        goto LABEL_44;
      }
      if ( format == 4 && utype == 3 )
      {
        if ( CONF_parse_list(a2, a1->m128i_i8, 0x2Cu, 1, (int (__cdecl *)(const char *, int, void *))bitstr_cb, v12) )
          goto LABEL_44;
        ERR_put_error(a2, 0xDu, 179, 188, ".\\crypto\\asn1\\asn1_gen.c", 790);
LABEL_53:
        ERR_add_error_data(2, "string=", a1);
        ASN1_TYPE_free(v5);
        return 0;
      }
      else
      {
        ERR_put_error(a2, 0xDu, 179, 175, ".\\crypto\\asn1\\asn1_gen.c", 798);
        ASN1_TYPE_free(v5);
        return 0;
      }
    case 5u:
      if ( !a1 || !a1->m128i_i8[0] )
        goto LABEL_44;
      ERR_put_error(a2, 0xDu, 179, 182, ".\\crypto\\asn1\\asn1_gen.c", 655);
      ASN1_TYPE_free(v5);
      return 0;
    case 6u:
      if ( format != 1 )
      {
        ERR_put_error(a2, 0xDu, 179, 191, ".\\crypto\\asn1\\asn1_gen.c", 693);
        ASN1_TYPE_free(v5);
        return 0;
      }
      v8 = OBJ_txt2obj(a2, a1->m128i_i8, 0);
      v5->value.boolean = (int)v8;
      if ( v8 )
        goto LABEL_44;
      ERR_put_error(a2, 0xDu, 179, 183, ".\\crypto\\asn1\\asn1_gen.c", 698);
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
        v10 = 4097;
      }
      else
      {
        if ( format != 2 )
        {
          ERR_put_error(a2, 0xDu, 179, 177, ".\\crypto\\asn1\\asn1_gen.c", 745);
          ASN1_TYPE_free(v5);
          return 0;
        }
        v10 = 4096;
      }
      v11 = ASN1_tag2bit(utype);
      if ( ASN1_mbstring_copy((asn1_string_st **)&v5->value, (unsigned __int8 *)a1, -1, v10, v11) > 0 )
        goto LABEL_44;
      ERR_put_error(a2, 0xDu, 179, 65, ".\\crypto\\asn1\\asn1_gen.c", 753);
      goto LABEL_53;
    case 0x17u:
    case 0x18u:
      if ( format != 1 )
      {
        ERR_put_error(a2, 0xDu, 179, 193, ".\\crypto\\asn1\\asn1_gen.c", 707);
        ASN1_TYPE_free(v5);
        return 0;
      }
      v9 = ASN1_STRING_new(a2);
      v5->value.boolean = (int)v9;
      if ( !v9 )
      {
        ERR_put_error(a2, 0xDu, 179, 65, ".\\crypto\\asn1\\asn1_gen.c", 712);
        goto LABEL_53;
      }
      if ( !ASN1_STRING_set(v9, a1, -1) )
      {
        ERR_put_error(a2, 0xDu, 179, 65, ".\\crypto\\asn1\\asn1_gen.c", 717);
        goto LABEL_53;
      }
      *(_DWORD *)(v5->value.boolean + 4) = utype;
      if ( !ASN1_TIME_check(v5->value.asn1_string) )
      {
        ERR_put_error(a2, 0xDu, 179, 184, ".\\crypto\\asn1\\asn1_gen.c", 723);
        goto LABEL_53;
      }
LABEL_44:
      v5->type = utype;
      return v5;
    default:
      ERR_put_error(a2, 0xDu, 179, 196, ".\\crypto\\asn1\\asn1_gen.c", 814);
      goto LABEL_53;
  }
}
