int __usercall process_pci_value@<eax>(
        CONF_VALUE *val@<ebx>,
        asn1_object_st **language@<ecx>,
        asn1_string_st **policy@<esi>,
        asn1_string_st **pathlen)
{
  char *name; // ebp
  asn1_object_st *v7; // eax
  unsigned __int8 *v8; // edi
  asn1_string_st *v9; // eax
  __m128i *v10; // ebp
  unsigned __int8 *v11; // eax
  int v12; // eax
  signed int v13; // ebp
  unsigned __int8 *v14; // eax
  char *v15; // eax
  asn1_string_st *v16; // ecx
  unsigned __int8 *v17; // eax
  int len; // [esp+8h] [ebp-810h] BYREF
  asn1_string_st **aint; // [esp+Ch] [ebp-80Ch]
  int v20; // [esp+10h] [ebp-808h]
  __m128i src[128]; // [esp+14h] [ebp-804h] BYREF

  name = val->name;
  aint = pathlen;
  v20 = 0;
  if ( !strcmp(name, "language") )
  {
    if ( *language )
    {
      ERR_put_error((int)val, 0x22u, 150, 155, ".\\crypto\\x509v3\\v3_pci.c", 85);
      ERR_add_error_data(6, "section:", val->section, ",name:", val->name, ",value:", val->value);
      return 0;
    }
    v7 = OBJ_txt2obj((int)val, val->value, 0);
    *language = v7;
    if ( !v7 )
    {
      ERR_put_error((int)val, 0x22u, 150, 110, ".\\crypto\\x509v3\\v3_pci.c", 91);
LABEL_7:
      ERR_add_error_data(6, "section:", val->section, ",name:", val->name, ",value:", val->value);
      return 0;
    }
    return 1;
  }
  if ( strcmp(name, "pathlen") )
  {
    if ( strcmp(name, "policy") )
      return 1;
    v8 = 0;
    if ( !*policy )
    {
      v9 = ASN1_OCTET_STRING_new();
      *policy = v9;
      if ( !v9 )
      {
        ERR_put_error((int)val, 0x22u, 150, 65, ".\\crypto\\x509v3\\v3_pci.c", 120);
        goto LABEL_7;
      }
      v20 = 1;
    }
    if ( !strncmp(val->value, "hex:", 4u) )
    {
      v10 = (__m128i *)string_to_hex((char)val, (const char *)val->value + 4, &len);
      if ( !v10 )
      {
        ERR_put_error((int)val, 0x22u, 150, 113, ".\\crypto\\x509v3\\v3_pci.c", 133);
LABEL_41:
        ERR_add_error_data(6, "section:", val->section, ",name:", val->name, ",value:", val->value);
        goto err_90;
      }
      v11 = (unsigned __int8 *)CRYPTO_realloc(
                                 (*policy)->data,
                                 len + (*policy)->length + 1,
                                 ".\\crypto\\x509v3\\v3_pci.c",
                                 139);
      v8 = v11;
      if ( !v11 )
      {
        CRYPTO_free(v10);
        (*policy)->data = 0;
        (*policy)->length = 0;
        ERR_put_error((int)val, 0x22u, 150, 65, ".\\crypto\\x509v3\\v3_pci.c", 154);
        ERR_add_error_data(6, "section:", val->section, ",name:", val->name, ",value:", val->value);
        goto err_90;
      }
      (*policy)->data = v11;
      memcpy((int)&(*policy)->data[(*policy)->length], v10, len);
      (*policy)->length += len;
      (*policy)->data[(*policy)->length] = 0;
      CRYPTO_free(v10);
    }
    else if ( !strncmp(val->value, "file:", 5u) )
    {
      aint = (asn1_string_st **)BIO_new_file((const char *)val->value + 5, "r");
      if ( !aint )
      {
        ERR_put_error((int)val, 0x22u, 150, 32, ".\\crypto\\x509v3\\v3_pci.c", 167);
        ERR_add_error_data(6, "section:", val->section, ",name:", val->name, ",value:", val->value);
        goto err_90;
      }
      do
      {
        while ( 1 )
        {
          v12 = BIO_read((int)val, (bio_st *)aint, src[0].m128i_i8, 2048);
          v13 = v12;
          if ( v12 <= 0 )
            break;
          v14 = (unsigned __int8 *)CRYPTO_realloc(
                                     (*policy)->data,
                                     (*policy)->length + v12 + 1,
                                     ".\\crypto\\x509v3\\v3_pci.c",
                                     177);
          v8 = v14;
          if ( !v14 )
            goto LABEL_30;
          (*policy)->data = v14;
          memcpy((int)&(*policy)->data[(*policy)->length], src, v13);
          (*policy)->length += v13;
          (*policy)->data[(*policy)->length] = 0;
        }
      }
      while ( !v12 && BIO_test_flags((const bio_st *)aint, 8) );
LABEL_30:
      BIO_free_all((int)val, (bio_st *)aint);
      if ( v13 < 0 )
      {
        ERR_put_error((int)val, 0x22u, 150, 32, ".\\crypto\\x509v3\\v3_pci.c", 192);
        goto LABEL_41;
      }
    }
    else
    {
      if ( strncmp(val->value, "text:", 5u) )
      {
        ERR_put_error((int)val, 0x22u, 150, 152, ".\\crypto\\x509v3\\v3_pci.c", 222);
        goto LABEL_41;
      }
      v15 = &val->value[strlen((const char *)val->value + 5) + 6];
      v16 = *policy;
      len = v15 - (val->value + 6);
      v17 = (unsigned __int8 *)CRYPTO_realloc(v16->data, len + v16->length + 1, ".\\crypto\\x509v3\\v3_pci.c", 201);
      v8 = v17;
      if ( !v17 )
      {
        (*policy)->data = 0;
        (*policy)->length = 0;
        ERR_put_error((int)val, 0x22u, 150, 65, ".\\crypto\\x509v3\\v3_pci.c", 215);
        goto LABEL_41;
      }
      (*policy)->data = v17;
      memcpy((int)&(*policy)->data[(*policy)->length], (const __m128i *)(val->value + 5), len);
      (*policy)->length += len;
      (*policy)->data[(*policy)->length] = 0;
    }
    if ( v8 )
      return 1;
    ERR_put_error((int)val, 0x22u, 150, 65, ".\\crypto\\x509v3\\v3_pci.c", 228);
    ERR_add_error_data(6, "section:", val->section, ",name:", val->name, ",value:", val->value);
err_90:
    if ( v20 )
    {
      ASN1_OCTET_STRING_free(*policy);
      *policy = 0;
    }
    return 0;
  }
  if ( *aint )
  {
    ERR_put_error((int)val, 0x22u, 150, 157, ".\\crypto\\x509v3\\v3_pci.c", 100);
    goto LABEL_7;
  }
  if ( !X509V3_get_value_int((int)val, val, aint) )
  {
    ERR_put_error((int)val, 0x22u, 150, 156, ".\\crypto\\x509v3\\v3_pci.c", 106);
    goto LABEL_7;
  }
  return 1;
}
