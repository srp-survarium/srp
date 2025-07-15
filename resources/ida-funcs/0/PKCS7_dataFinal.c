int __cdecl PKCS7_dataFinal(pkcs7_st *p7, bio_st *bio)
{
  unsigned __int8 *p_pmd; // edi
  int v3; // eax
  bio_st *type; // esi
  char *v5; // eax
  stack_st *v6; // ecx
  asn1_string_st *v7; // eax
  asn1_string_st *v8; // eax
  stack_st *v9; // ebx
  unsigned int v10; // esi
  char *v11; // eax
  pkcs7_signer_info_st *v12; // esi
  int v13; // eax
  asn1_string_st *v14; // eax
  char *ptr; // eax
  pkcs7_st *v16; // esi
  asn1_string_st *a; // [esp+10h] [ebp-78h]
  unsigned int size; // [esp+14h] [ebp-74h] BYREF
  env_md_ctx_st *pmd; // [esp+18h] [ebp-70h] BYREF
  bio_st *bioa; // [esp+1Ch] [ebp-6Ch]
  stack_st *st; // [esp+20h] [ebp-68h]
  unsigned int siglen; // [esp+24h] [ebp-64h] BYREF
  int v24; // [esp+28h] [ebp-60h]
  env_md_ctx_st ctx; // [esp+2Ch] [ebp-5Ch] BYREF
  unsigned __int8 md[64]; // [esp+44h] [ebp-44h] BYREF

  bioa = bio;
  v24 = 0;
  EVP_MD_CTX_init(&ctx);
  p_pmd = (unsigned __int8 *)OBJ_obj2nid(p7->type);
  p7->state = 0;
  switch ( (unsigned int)p_pmd )
  {
    case 0x15u:
      a = p7->d.data;
      goto LABEL_3;
    case 0x16u:
      ptr = p7->d.ptr;
      v16 = (pkcs7_st *)*((_DWORD *)ptr + 5);
      st = (stack_st *)*((_DWORD *)ptr + 4);
      a = PKCS7_get_octet_string(v16);
      if ( OBJ_obj2nid(*(const asn1_object_st **)(*((_DWORD *)p7->d.ptr + 5) + 16)) == 21 && p7->detached )
      {
        ASN1_STRING_free(a);
        *(_DWORD *)(*((_DWORD *)p7->d.ptr + 5) + 20) = 0;
      }
      goto LABEL_15;
    case 0x17u:
      a = *(asn1_string_st **)(*((_DWORD *)p7->d.ptr + 2) + 8);
      if ( a )
        goto LABEL_3;
      v14 = ASN1_STRING_type_new(4);
      a = v14;
      if ( !v14 )
      {
        ERR_put_error(0x21u, 128, 65, ".\\crypto\\pkcs7\\pk7_doit.c", 737);
        goto err_123;
      }
      *(_DWORD *)(*((_DWORD *)p7->d.ptr + 2) + 8) = v14;
      goto LABEL_3;
    case 0x18u:
      v5 = p7->d.ptr;
      v6 = (stack_st *)*((_DWORD *)v5 + 4);
      v7 = *(asn1_string_st **)(*((_DWORD *)v5 + 5) + 8);
      st = v6;
      a = v7;
      if ( v7 )
        goto LABEL_15;
      v8 = ASN1_STRING_type_new(4);
      a = v8;
      if ( !v8 )
      {
        ERR_put_error(0x21u, 128, 65, ".\\crypto\\pkcs7\\pk7_doit.c", 723);
        goto err_123;
      }
      *(_DWORD *)(*((_DWORD *)p7->d.ptr + 5) + 8) = v8;
LABEL_15:
      v9 = st;
      if ( st )
      {
        v10 = 0;
        for ( size = 0; (int)size < sk_num(st); v10 = size )
        {
          v11 = sk_value(v9, v10);
          v12 = (pkcs7_signer_info_st *)v11;
          if ( *((_DWORD *)v11 + 7) )
          {
            v13 = OBJ_obj2nid(**((const asn1_object_st ***)v11 + 2));
            p_pmd = (unsigned __int8 *)&pmd;
            if ( !PKCS7_find_digest((ui_string_st **)&pmd, v13, bioa) )
              goto err_123;
            EVP_MD_CTX_copy_ex(&ctx, pmd);
            if ( sk_num(&v12->auth_attr->stack) <= 0 )
            {
              siglen = EVP_PKEY_size(v12->pkey);
              p_pmd = (unsigned __int8 *)CRYPTO_malloc(siglen, ".\\crypto\\pkcs7\\pk7_doit.c", 803);
              if ( !p_pmd )
                goto err_123;
              if ( !EVP_SignFinal(&ctx, p_pmd, &siglen, v12->pkey) )
              {
                ERR_put_error(0x21u, 128, 6, ".\\crypto\\pkcs7\\pk7_doit.c", 811);
                goto err_123;
              }
              ASN1_STRING_set0(v12->enc_digest, p_pmd, siglen);
            }
            else
            {
              p_pmd = (unsigned __int8 *)&ctx;
              if ( !do_pkcs7_signed_attrib(v12, &ctx) )
                goto err_123;
            }
          }
          v9 = st;
          ++size;
        }
      }
      else
      {
LABEL_3:
        if ( p_pmd == (unsigned __int8 *)25 )
        {
          v3 = OBJ_obj2nid(**((const asn1_object_st ***)p7->d.ptr + 1));
          p_pmd = (unsigned __int8 *)&pmd;
          if ( !PKCS7_find_digest((ui_string_st **)&pmd, v3, bioa) )
            goto err_123;
          EVP_DigestFinal_ex((unsigned int)&pmd, pmd, md, &size);
          ASN1_STRING_set(*((asn1_string_st **)p7->d.ptr + 3), (char *)md, size);
        }
      }
      if ( (OBJ_obj2nid(p7->type) != 22 || !PKCS7_ctrl(p7, 2, 0, 0)) && (a->flags & 0x10) == 0 )
      {
        type = BIO_find_type(bioa, 1025);
        if ( !type )
        {
          ERR_put_error(0x21u, 128, 107, ".\\crypto\\pkcs7\\pk7_doit.c", 836);
          goto err_123;
        }
        p_pmd = (unsigned __int8 *)BIO_ctrl(type, 3, 0, &size);
        BIO_set_flags(type, 512);
        BIO_ctrl(type, 130, 0, 0);
        ASN1_STRING_set0(a, (unsigned __int8 *)size, (int)p_pmd);
      }
      v24 = 1;
err_123:
      EVP_MD_CTX_cleanup((unsigned int)p_pmd, &ctx);
      return v24;
    case 0x19u:
      a = PKCS7_get_octet_string(*((pkcs7_st **)p7->d.ptr + 2));
      if ( OBJ_obj2nid(*(const asn1_object_st **)(*((_DWORD *)p7->d.ptr + 2) + 16)) == 21 && p7->detached )
      {
        ASN1_STRING_free(a);
        *(_DWORD *)(*((_DWORD *)p7->d.ptr + 2) + 20) = 0;
      }
      goto LABEL_3;
    default:
      ERR_put_error(0x21u, 128, 112, ".\\crypto\\pkcs7\\pk7_doit.c", 764);
      goto err_123;
  }
}
