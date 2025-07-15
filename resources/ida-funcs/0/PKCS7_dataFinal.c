int __cdecl PKCS7_dataFinal(pkcs7_st *p7, bio_st *bio)
{
  const stack_st *v2; // ebx
  unsigned __int8 *p_in; // edi
  bio_st *type; // esi
  char *v5; // eax
  stack_st *v6; // ecx
  asn1_string_st *v7; // eax
  asn1_string_st *v8; // eax
  unsigned __int8 *v9; // esi
  char *v10; // eax
  pkcs7_signer_info_st *v11; // esi
  asn1_string_st *v12; // eax
  char *ptr; // eax
  pkcs7_st *v14; // esi
  asn1_string_st *a; // [esp+10h] [ebp-78h]
  unsigned __int8 *parg; // [esp+14h] [ebp-74h] BYREF
  env_md_ctx_st *in; // [esp+18h] [ebp-70h] BYREF
  bio_st *bioa; // [esp+1Ch] [ebp-6Ch]
  stack_st *st; // [esp+20h] [ebp-68h]
  unsigned int siglen; // [esp+24h] [ebp-64h] BYREF
  int v22; // [esp+28h] [ebp-60h]
  env_md_ctx_st ctx; // [esp+2Ch] [ebp-5Ch] BYREF
  __m128i v24[4]; // [esp+44h] [ebp-44h] BYREF

  v2 = 0;
  bioa = bio;
  v22 = 0;
  EVP_MD_CTX_init(&ctx);
  p_in = (unsigned __int8 *)OBJ_obj2nid(p7->type);
  p7->state = 0;
  switch ( (unsigned int)p_in )
  {
    case 0x15u:
      a = p7->d.data;
      goto LABEL_3;
    case 0x16u:
      ptr = p7->d.ptr;
      v14 = (pkcs7_st *)*((_DWORD *)ptr + 5);
      st = (stack_st *)*((_DWORD *)ptr + 4);
      a = PKCS7_get_octet_string(v14);
      if ( OBJ_obj2nid(*(const asn1_object_st **)(*((_DWORD *)p7->d.ptr + 5) + 16)) == (void *)21 && p7->detached )
      {
        ASN1_STRING_free(a);
        *(_DWORD *)(*((_DWORD *)p7->d.ptr + 5) + 20) = 0;
      }
      goto LABEL_15;
    case 0x17u:
      a = *(asn1_string_st **)(*((_DWORD *)p7->d.ptr + 2) + 8);
      if ( a )
        goto LABEL_3;
      v12 = ASN1_STRING_type_new(0, 4);
      a = v12;
      if ( !v12 )
      {
        ERR_put_error(0, 0x21u, 128, 65, ".\\crypto\\pkcs7\\pk7_doit.c", 737);
        goto err_125;
      }
      *(_DWORD *)(*((_DWORD *)p7->d.ptr + 2) + 8) = v12;
      goto LABEL_3;
    case 0x18u:
      v5 = p7->d.ptr;
      v6 = (stack_st *)*((_DWORD *)v5 + 4);
      v7 = *(asn1_string_st **)(*((_DWORD *)v5 + 5) + 8);
      st = v6;
      a = v7;
      if ( v7 )
        goto LABEL_15;
      v8 = ASN1_STRING_type_new(0, 4);
      a = v8;
      if ( !v8 )
      {
        ERR_put_error(0, 0x21u, 128, 65, ".\\crypto\\pkcs7\\pk7_doit.c", 723);
        goto err_125;
      }
      *(_DWORD *)(*((_DWORD *)p7->d.ptr + 5) + 8) = v8;
LABEL_15:
      v2 = st;
      if ( st )
      {
        v9 = 0;
        for ( parg = 0; (int)parg < sk_num(st); v9 = parg )
        {
          v10 = sk_value(v2, (int)v9);
          v11 = (pkcs7_signer_info_st *)v10;
          if ( *((_DWORD *)v10 + 7) )
          {
            v2 = (const stack_st *)OBJ_obj2nid(**((const asn1_object_st ***)v10 + 2));
            p_in = (unsigned __int8 *)&in;
            if ( !PKCS7_find_digest((ui_string_st **)&in, (int)v2, bioa) )
              goto err_125;
            EVP_MD_CTX_copy_ex((int)v2, &ctx, in);
            if ( sk_num(&v11->auth_attr->stack) <= 0 )
            {
              siglen = EVP_PKEY_size(v11->pkey);
              p_in = (unsigned __int8 *)CRYPTO_malloc(siglen, ".\\crypto\\pkcs7\\pk7_doit.c", 803);
              if ( !p_in )
                goto err_125;
              if ( !EVP_SignFinal(&ctx, p_in, &siglen, v11->pkey) )
              {
                ERR_put_error((int)v2, 0x21u, 128, 6, ".\\crypto\\pkcs7\\pk7_doit.c", 811);
                goto err_125;
              }
              ASN1_STRING_set0(v11->enc_digest, p_in, siglen);
            }
            else
            {
              p_in = (unsigned __int8 *)&ctx;
              if ( !do_pkcs7_signed_attrib(v11, &ctx) )
                goto err_125;
            }
          }
          v2 = st;
          ++parg;
        }
      }
      else
      {
LABEL_3:
        if ( p_in == (unsigned __int8 *)25 )
        {
          v2 = (const stack_st *)OBJ_obj2nid(**((const asn1_object_st ***)p7->d.ptr + 1));
          p_in = (unsigned __int8 *)&in;
          if ( !PKCS7_find_digest((ui_string_st **)&in, (int)v2, bioa) )
            goto err_125;
          EVP_DigestFinal_ex((int)&in, (int)v2, in, (unsigned __int8 *)v24, (unsigned int *)&parg);
          ASN1_STRING_set(*((asn1_string_st **)p7->d.ptr + 3), v24, (int)parg);
        }
      }
      if ( (OBJ_obj2nid(p7->type) != (void *)22 || !PKCS7_ctrl(p7, 2, 0)) && (a->flags & 0x10) == 0 )
      {
        type = BIO_find_type(bioa, 1025);
        if ( !type )
        {
          ERR_put_error((int)v2, 0x21u, 128, 107, ".\\crypto\\pkcs7\\pk7_doit.c", 836);
          goto err_125;
        }
        p_in = (unsigned __int8 *)BIO_ctrl((int)v2, type, 3, 0, &parg);
        BIO_set_flags(type, 512);
        BIO_ctrl((int)v2, type, 130, 0, 0);
        ASN1_STRING_set0(a, parg, (int)p_in);
      }
      v22 = 1;
err_125:
      EVP_MD_CTX_cleanup((int)p_in, (int)v2, &ctx);
      return v22;
    case 0x19u:
      a = PKCS7_get_octet_string(*((pkcs7_st **)p7->d.ptr + 2));
      if ( OBJ_obj2nid(*(const asn1_object_st **)(*((_DWORD *)p7->d.ptr + 2) + 16)) == (void *)21 && p7->detached )
      {
        ASN1_STRING_free(a);
        *(_DWORD *)(*((_DWORD *)p7->d.ptr + 2) + 20) = 0;
      }
      goto LABEL_3;
    default:
      ERR_put_error(0, 0x21u, 128, 112, ".\\crypto\\pkcs7\\pk7_doit.c", 764);
      goto err_125;
  }
}
