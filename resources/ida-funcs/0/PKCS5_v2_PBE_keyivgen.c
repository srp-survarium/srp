int __cdecl PKCS5_v2_PBE_keyivgen(
        evp_cipher_ctx_st *ctx,
        char *pass,
        unsigned int passlen,
        asn1_type_st *param,
        const evp_cipher_st *c,
        const env_md_st *md,
        int en_de)
{
  PBKDF2PARAM_st *v7; // esi
  char *ptr; // eax
  PBE2PARAM_st *v9; // edi
  void *v11; // eax
  char *v12; // eax
  const evp_cipher_st *cipherbyname; // eax
  unsigned int v14; // ebx
  asn1_type_st *parameter; // eax
  const asn1_object_st **p_algorithm; // eax
  int v17; // eax
  char *v18; // eax
  unsigned int *v19; // eax
  unsigned __int8 *v20; // ebx
  unsigned int v21; // ebp
  int v22; // eax
  int v23; // [esp-8h] [ebp-4Ch]
  unsigned __int8 *in; // [esp+8h] [ebp-3Ch] BYREF
  unsigned int v25; // [esp+Ch] [ebp-38h]
  const env_md_st *digestbyname; // [esp+10h] [ebp-34h]
  char *v27; // [esp+14h] [ebp-30h]
  evp_cipher_ctx_st *v28; // [esp+18h] [ebp-2Ch]
  int pmnid; // [esp+1Ch] [ebp-28h] BYREF
  unsigned __int8 key[32]; // [esp+20h] [ebp-24h] BYREF

  v27 = pass;
  v7 = 0;
  v28 = ctx;
  if ( param && param->type == 16 && param->value.boolean )
  {
    ptr = param->value.ptr;
    in = (unsigned __int8 *)*((_DWORD *)ptr + 2);
    v9 = d2i_PBE2PARAM(0, &in, *(const unsigned __int8 **)ptr);
    if ( !v9 )
    {
      ERR_put_error((int)ctx, 6u, 118, 114, ".\\crypto\\evp\\p5_crpt2.c", 190);
      return 0;
    }
    if ( OBJ_obj2nid(v9->keyfunc->algorithm) == (void *)69 )
    {
      v11 = OBJ_obj2nid(v9->encryption->algorithm);
      v12 = (char *)OBJ_nid2sn((int)ctx, (unsigned int)v11);
      cipherbyname = EVP_get_cipherbyname(v12);
      if ( cipherbyname )
      {
        EVP_CipherInit_ex(ctx, cipherbyname, 0, 0, 0, en_de);
        if ( EVP_CIPHER_asn1_to_param(ctx) >= 0 )
        {
          v14 = EVP_CIPHER_CTX_key_length(ctx);
          v25 = v14;
          if ( v14 > 0x20 )
            OpenSSLDie((int)v9, 0, v14, ".\\crypto\\evp\\p5_crpt2.c", 221, "keylen <= sizeof key");
          parameter = v9->keyfunc->parameter;
          if ( parameter && parameter->type == 16 )
          {
            in = *(unsigned __int8 **)(parameter->value.boolean + 8);
            v7 = d2i_PBKDF2PARAM(0, &in, *(const unsigned __int8 **)v9->keyfunc->parameter->value.ptr);
            if ( v7 )
            {
              PBE2PARAM_free(v9);
              v9 = 0;
              if ( !v7->keylength || ASN1_INTEGER_get(v7->keylength) == v14 )
              {
                p_algorithm = (const asn1_object_st **)&v7->prf->algorithm;
                if ( p_algorithm )
                  v17 = (int)OBJ_obj2nid(*p_algorithm);
                else
                  v17 = 163;
                if ( EVP_PBE_find(0, 1, v17, 0, &pmnid, 0) )
                {
                  v18 = (char *)OBJ_nid2sn(v14, pmnid);
                  digestbyname = EVP_get_digestbyname(v18);
                  if ( digestbyname )
                  {
                    if ( v7->salt->type == 4 )
                    {
                      v19 = (unsigned int *)v7->salt->value.ptr;
                      v20 = (unsigned __int8 *)v19[2];
                      v21 = *v19;
                      v22 = ASN1_INTEGER_get(v7->iter);
                      if ( PKCS5_PBKDF2_HMAC(v27, passlen, v20, v21, v22, digestbyname, v25, key) )
                      {
                        EVP_CipherInit_ex(v28, 0, 0, key, 0, en_de);
                        OPENSSL_cleanse(key, v25);
                        PBKDF2PARAM_free(v7);
                        return 1;
                      }
                    }
                    else
                    {
                      ERR_put_error(v14, 6u, 118, 126, ".\\crypto\\evp\\p5_crpt2.c", 270);
                    }
                  }
                  else
                  {
                    ERR_put_error(v14, 6u, 118, 125, ".\\crypto\\evp\\p5_crpt2.c", 264);
                  }
                }
                else
                {
                  ERR_put_error(v14, 6u, 118, 125, ".\\crypto\\evp\\p5_crpt2.c", 257);
                }
              }
              else
              {
                ERR_put_error(v14, 6u, 118, 123, ".\\crypto\\evp\\p5_crpt2.c", 246);
              }
              goto err_27;
            }
            v23 = 235;
          }
          else
          {
            v23 = 228;
          }
          ERR_put_error(v14, 6u, 118, 114, ".\\crypto\\evp\\p5_crpt2.c", v23);
        }
        else
        {
          ERR_put_error((int)ctx, 6u, 118, 122, ".\\crypto\\evp\\p5_crpt2.c", 217);
        }
      }
      else
      {
        ERR_put_error((int)ctx, 6u, 118, 107, ".\\crypto\\evp\\p5_crpt2.c", 209);
      }
    }
    else
    {
      ERR_put_error((int)ctx, 6u, 118, 124, ".\\crypto\\evp\\p5_crpt2.c", 198);
    }
err_27:
    PBE2PARAM_free(v9);
    PBKDF2PARAM_free(v7);
    return 0;
  }
  ERR_put_error((int)ctx, 6u, 118, 114, ".\\crypto\\evp\\p5_crpt2.c", 183);
  return 0;
}
