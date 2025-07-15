asn1_string_st *__usercall s2i_skey_id@<eax>(engine_st *a1@<ebx>, v3_ext_method *method, v3_ext_ctx *ctx, char *str)
{
  asn1_string_st *result; // eax
  asn1_string_st *v5; // edi
  X509_req_st *subject_req; // eax
  X509_pubkey_st *key; // edx
  asn1_string_st *public_key; // esi
  const env_md_st *v9; // eax
  int v10; // [esp+8h] [ebp-48h] BYREF
  __m128i v11[4]; // [esp+Ch] [ebp-44h] BYREF

  if ( strcmp(str, "hash") )
    return s2i_ASN1_OCTET_STRING((char)a1, method, ctx, str);
  result = ASN1_STRING_type_new((unsigned __int8)a1, 4);
  v5 = result;
  if ( !result )
  {
    ERR_put_error((unsigned __int8)a1, 0x22u, 115, 65, ".\\crypto\\x509v3\\v3_skey.c", 112);
    return 0;
  }
  if ( !ctx )
    goto LABEL_16;
  if ( ctx->flags == 1 )
    return result;
  subject_req = ctx->subject_req;
  if ( !subject_req )
  {
    if ( ctx->subject_cert )
    {
      key = ctx->subject_cert->cert_info->key;
      goto LABEL_11;
    }
LABEL_16:
    ERR_put_error((unsigned __int8)a1, 0x22u, 115, 114, ".\\crypto\\x509v3\\v3_skey.c", 119);
    goto LABEL_17;
  }
  key = subject_req->req_info->pubkey;
LABEL_11:
  public_key = key->public_key;
  if ( public_key )
  {
    v9 = EVP_sha1();
    EVP_Digest((int)v5, a1, public_key->data, public_key->length, (unsigned __int8 *)v11, (unsigned int *)&v10, v9, 0);
    if ( ASN1_STRING_set(v5, v11, v10) )
      return v5;
    ERR_put_error((unsigned __int8)a1, 0x22u, 115, 65, ".\\crypto\\x509v3\\v3_skey.c", 135);
  }
  else
  {
    ERR_put_error((unsigned __int8)a1, 0x22u, 115, 114, ".\\crypto\\x509v3\\v3_skey.c", 128);
  }
LABEL_17:
  ASN1_STRING_free(v5);
  return 0;
}
