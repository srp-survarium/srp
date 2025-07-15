int __usercall PKCS12_PBE_keyivgen@<eax>(
        int a1@<ebx>,
        evp_cipher_ctx_st *ctx,
        char *pass,
        int passlen,
        asn1_type_st *param,
        const engine_st *cipher,
        const env_md_st *md,
        int en_de)
{
  char *ptr; // eax
  PBEPARAM_st *v9; // eax
  PBEPARAM_st *v10; // ebx
  const asn1_string_st *iter; // eax
  int v13; // ebp
  unsigned __int8 *data; // esi
  int length; // edi
  const rsa_meth_st *v16; // eax
  bio_st *v17; // eax
  int v18; // esi
  unsigned __int8 *in; // [esp+Ch] [ebp-3Ch] BYREF
  evp_cipher_ctx_st *ctxa; // [esp+10h] [ebp-38h]
  unsigned __int8 iv[16]; // [esp+14h] [ebp-34h] BYREF
  unsigned __int8 out[32]; // [esp+24h] [ebp-24h] BYREF

  ctxa = ctx;
  if ( param && param->type == 16 && param->value.boolean )
  {
    ptr = param->value.ptr;
    in = (unsigned __int8 *)*((_DWORD *)ptr + 2);
    v9 = d2i_PBEPARAM(0, &in, *(const unsigned __int8 **)ptr);
    v10 = v9;
    if ( !v9 )
    {
      ERR_put_error(0, 0x23u, 120, 101, ".\\crypto\\pkcs12\\p12_crpt.c", 87);
      return 0;
    }
    iter = v9->iter;
    if ( iter )
      v13 = ASN1_INTEGER_get(iter);
    else
      v13 = 1;
    data = v10->salt->data;
    length = v10->salt->length;
    v16 = EC_KEY_get0_public_key(cipher);
    if ( !PKCS12_key_gen_asc(pass, passlen, data, length, 1, v13, (int)v16, out, md) )
    {
      ERR_put_error((int)v10, 0x23u, 120, 107, ".\\crypto\\pkcs12\\p12_crpt.c", 97);
LABEL_11:
      PBEPARAM_free(v10);
      return 0;
    }
    v17 = EC_KEY_get0_private_key((const ssl_st *)cipher);
    if ( !PKCS12_key_gen_asc(pass, passlen, data, length, 2, v13, (int)v17, iv, md) )
    {
      ERR_put_error((int)v10, 0x23u, 120, 106, ".\\crypto\\pkcs12\\p12_crpt.c", 103);
      goto LABEL_11;
    }
    PBEPARAM_free(v10);
    v18 = EVP_CipherInit_ex(ctxa, (const evp_cipher_st *)cipher, 0, out, iv, en_de);
    OPENSSL_cleanse(out, 32);
    OPENSSL_cleanse(iv, 16);
    return v18;
  }
  else
  {
    ERR_put_error(a1, 0x23u, 120, 101, ".\\crypto\\pkcs12\\p12_crpt.c", 81);
    return 0;
  }
}
