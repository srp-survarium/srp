evp_pkey_st *__usercall d2i_PrivateKey@<eax>(
        unsigned int a1@<edi>,
        int type,
        evp_pkey_st **a,
        unsigned __int8 **pp,
        unsigned __int8 *length)
{
  evp_pkey_st *v5; // esi
  int (__cdecl *old_priv_decode)(evp_pkey_st *, const unsigned __int8 **, int); // eax
  pkcs8_priv_key_info_st *v8; // edi

  if ( a && (v5 = *a) != 0 )
  {
    if ( v5->engine )
    {
      ENGINE_finish(a1, v5->engine);
      v5->engine = 0;
    }
  }
  else
  {
    v5 = EVP_PKEY_new();
    if ( !v5 )
    {
      ERR_put_error(0xDu, 154, 6, ".\\crypto\\asn1\\d2i_pr.c", 80);
      return 0;
    }
  }
  if ( !EVP_PKEY_set_type(v5, type) )
  {
    ERR_put_error(0xDu, 154, 163, ".\\crypto\\asn1\\d2i_pr.c", 98);
    goto err_59;
  }
  old_priv_decode = v5->ameth->old_priv_decode;
  if ( !old_priv_decode || !old_priv_decode(v5, (const unsigned __int8 **)pp, (int)length) )
  {
    if ( v5->ameth->priv_decode )
    {
      v8 = d2i_PKCS8_PRIV_KEY_INFO(0, pp, length);
      if ( v8 )
      {
        EVP_PKEY_free(v5);
        v5 = EVP_PKCS82PKEY(v8);
        PKCS8_PRIV_KEY_INFO_free(v8);
        goto LABEL_14;
      }
    }
    else
    {
      ERR_put_error(0xDu, 154, 13, ".\\crypto\\asn1\\d2i_pr.c", 117);
    }
err_59:
    if ( v5 && (!a || *a != v5) )
      EVP_PKEY_free(v5);
    return 0;
  }
LABEL_14:
  if ( a )
    *a = v5;
  return v5;
}
