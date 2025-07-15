asn1_string_st *__cdecl s2i_skey_id(v3_ext_method *method, v3_ext_ctx *ctx, char *str)
{
  asn1_string_st *result; // eax
  asn1_string_st *v4; // edi
  X509_req_st *subject_req; // eax
  X509_pubkey_st *key; // edx
  asn1_string_st *public_key; // esi
  const env_md_st *v8; // eax
  unsigned int size; // [esp+8h] [ebp-48h] BYREF
  unsigned __int8 md[64]; // [esp+Ch] [ebp-44h] BYREF

  if ( strcmp(str, "hash") )
    return s2i_ASN1_OCTET_STRING(method, ctx, str);
  result = ASN1_STRING_type_new(4);
  v4 = result;
  if ( !result )
  {
    ERR_put_error(0x22u, 115, 65, ".\\crypto\\x509v3\\v3_skey.c", 112);
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
    ERR_put_error(0x22u, 115, 114, ".\\crypto\\x509v3\\v3_skey.c", 119);
    goto LABEL_17;
  }
  key = subject_req->req_info->pubkey;
LABEL_11:
  public_key = key->public_key;
  if ( public_key )
  {
    v8 = EVP_sha1();
    EVP_Digest((unsigned int)v4, public_key->data, public_key->length, md, &size, v8, 0);
    if ( ASN1_STRING_set(v4, (char *)md, size) )
      return v4;
    ERR_put_error(0x22u, 115, 65, ".\\crypto\\x509v3\\v3_skey.c", 135);
  }
  else
  {
    ERR_put_error(0x22u, 115, 114, ".\\crypto\\x509v3\\v3_skey.c", 128);
  }
LABEL_17:
  ASN1_STRING_free(v4);
  return 0;
}
