evp_pkey_st *__usercall d2i_PrivateKey@<eax>(
        pkcs8_priv_key_info_st *a1@<edi>,
        int a2@<ebx>,
        void *type,
        evp_pkey_st **a,
        unsigned __int8 **pp,
        const unsigned __int8 **length)
{
  evp_pkey_st *v6; // esi
  int (__cdecl *old_priv_decode)(evp_pkey_st *, const unsigned __int8 **, int); // eax

  if ( a && (v6 = *a) != 0 )
  {
    if ( v6->engine )
    {
      ENGINE_finish((int)a1, a2, v6->engine);
      v6->engine = 0;
    }
  }
  else
  {
    v6 = EVP_PKEY_new(a2);
    if ( !v6 )
    {
      ERR_put_error(a2, 0xDu, 154, 6, ".\\crypto\\asn1\\d2i_pr.c", 80);
      return 0;
    }
  }
  if ( !EVP_PKEY_set_type(v6, type) )
  {
    ERR_put_error(a2, 0xDu, 154, 163, ".\\crypto\\asn1\\d2i_pr.c", 98);
    goto err_61;
  }
  old_priv_decode = v6->ameth->old_priv_decode;
  a1 = (pkcs8_priv_key_info_st *)length;
  if ( !old_priv_decode || !old_priv_decode(v6, (const unsigned __int8 **)pp, (int)length) )
  {
    if ( v6->ameth->priv_decode )
    {
      a1 = d2i_PKCS8_PRIV_KEY_INFO(0, pp, length);
      if ( a1 )
      {
        EVP_PKEY_free((int)a1, v6);
        v6 = EVP_PKCS82PKEY((int)pp, a1);
        PKCS8_PRIV_KEY_INFO_free(a1);
        goto LABEL_14;
      }
    }
    else
    {
      ERR_put_error((int)pp, 0xDu, 154, 13, ".\\crypto\\asn1\\d2i_pr.c", 117);
    }
err_61:
    if ( v6 && (!a || *a != v6) )
      EVP_PKEY_free((int)a1, v6);
    return 0;
  }
LABEL_14:
  if ( a )
    *a = v6;
  return v6;
}
