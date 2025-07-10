int __cdecl ssl_rsa_private_decrypt(cert_st *c, int len, unsigned __int8 *from, unsigned __int8 *to)
{
  evp_pkey_st *privatekey; // eax
  int v6; // esi

  if ( c && (privatekey = c->pkeys[0].privatekey) != 0 )
  {
    if ( privatekey->type == 6 )
    {
      v6 = RSA_private_decrypt(len, from, to, privatekey->pkey.rsa);
      if ( v6 < 0 )
        ERR_put_error(0x14u, 187, 4, ".\\ssl\\s2_srvr.c", 1133);
      return v6;
    }
    else
    {
      ERR_put_error(0x14u, 187, 209, ".\\ssl\\s2_srvr.c", 1125);
      return -1;
    }
  }
  else
  {
    ERR_put_error(0x14u, 187, 189, ".\\ssl\\s2_srvr.c", 1120);
    return -1;
  }
}
