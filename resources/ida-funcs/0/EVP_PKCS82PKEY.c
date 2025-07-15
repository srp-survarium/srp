evp_pkey_st *__cdecl EVP_PKCS82PKEY(pkcs8_priv_key_info_st *p8)
{
  evp_pkey_st *result; // eax
  evp_pkey_st *v2; // esi
  int v3; // eax
  int (__cdecl *priv_decode)(evp_pkey_st *, pkcs8_priv_key_info_st *); // eax
  asn1_object_st *ppkalg; // [esp+4h] [ebp-58h] BYREF
  char buf[80]; // [esp+8h] [ebp-54h] BYREF

  result = (evp_pkey_st *)PKCS8_pkey_get0(&ppkalg, 0, 0, 0, p8);
  if ( result )
  {
    v2 = EVP_PKEY_new();
    if ( !v2 )
    {
      ERR_put_error(6u, 111, 65, ".\\crypto\\evp\\evp_pkey.c", 78);
      return 0;
    }
    v3 = OBJ_obj2nid(ppkalg);
    if ( EVP_PKEY_set_type(v2, v3) )
    {
      priv_decode = v2->ameth->priv_decode;
      if ( priv_decode )
      {
        if ( priv_decode(v2, p8) )
          return v2;
        ERR_put_error(6u, 111, 145, ".\\crypto\\evp\\evp_pkey.c", 95);
      }
      else
      {
        ERR_put_error(6u, 111, 144, ".\\crypto\\evp\\evp_pkey.c", 101);
      }
    }
    else
    {
      ERR_put_error(6u, 111, 118, ".\\crypto\\evp\\evp_pkey.c", 84);
      i2t_ASN1_OBJECT(buf, 0x50u, ppkalg);
      ERR_add_error_data(2, "TYPE=", buf);
    }
    EVP_PKEY_free(v2);
    return 0;
  }
  return result;
}
