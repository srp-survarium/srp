int __cdecl PKCS12_PBE_keyivgen(
        evp_cipher_ctx_st *ctx,
        const char *pass,
        int passlen,
        asn1_type_st *param,
        const engine_st *cipher,
        const env_md_st *md,
        int en_de)
{
  char *ptr; // eax
  PBEPARAM_st *v8; // eax
  PBEPARAM_st *v9; // ebx
  const asn1_string_st *iter; // eax
  int v12; // ebp
  unsigned __int8 *data; // esi
  int length; // edi
  const rsa_meth_st *v15; // eax
  bio_st *v16; // eax
  int v17; // esi
  unsigned __int8 *in; // [esp+Ch] [ebp-3Ch] BYREF
  evp_cipher_ctx_st *ctxa; // [esp+10h] [ebp-38h]
  unsigned __int8 iv[16]; // [esp+14h] [ebp-34h] BYREF
  unsigned __int8 out[32]; // [esp+24h] [ebp-24h] BYREF

  ctxa = ctx;
  if ( param && param->type == 16 && param->value.boolean )
  {
    ptr = param->value.ptr;
    in = (unsigned __int8 *)*((_DWORD *)ptr + 2);
    v8 = d2i_PBEPARAM(0, (const unsigned __int8 **)&in, *(_DWORD *)ptr);
    v9 = v8;
    if ( !v8 )
    {
      ERR_put_error(0x23u, 120, 101, ".\\crypto\\pkcs12\\p12_crpt.c", 87);
      return 0;
    }
    iter = v8->iter;
    if ( iter )
      v12 = ASN1_INTEGER_get(iter);
    else
      v12 = 1;
    data = v9->salt->data;
    length = v9->salt->length;
    v15 = EC_KEY_get0_public_key(cipher);
    if ( !PKCS12_key_gen_asc(pass, passlen, data, length, 1, v12, (int)v15, out, md) )
    {
      ERR_put_error(0x23u, 120, 107, ".\\crypto\\pkcs12\\p12_crpt.c", 97);
LABEL_11:
      PBEPARAM_free(v9);
      return 0;
    }
    v16 = EC_KEY_get0_private_key((const ssl_st *)cipher);
    if ( !PKCS12_key_gen_asc(pass, passlen, data, length, 2, v12, (int)v16, iv, md) )
    {
      ERR_put_error(0x23u, 120, 106, ".\\crypto\\pkcs12\\p12_crpt.c", 103);
      goto LABEL_11;
    }
    PBEPARAM_free(v9);
    v17 = EVP_CipherInit_ex(ctxa, (const evp_cipher_st *)cipher, 0, out, iv, en_de);
    OPENSSL_cleanse(out, 32);
    OPENSSL_cleanse(iv, 16);
    return v17;
  }
  else
  {
    ERR_put_error(0x23u, 120, 101, ".\\crypto\\pkcs12\\p12_crpt.c", 81);
    return 0;
  }
}
