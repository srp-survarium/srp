int __usercall ssl_rsa_private_decrypt@<eax>(
        int a1@<ebx>,
        cert_st *c,
        int len,
        unsigned __int8 *from,
        unsigned __int8 *to)
{
  evp_pkey_st *privatekey; // eax
  int v7; // esi

  if ( c && (privatekey = c->pkeys[0].privatekey) != 0 )
  {
    if ( privatekey->type == 6 )
    {
      v7 = RSA_private_decrypt(len, from, to, privatekey->pkey.rsa);
      if ( v7 < 0 )
        ERR_put_error(a1, 0x14u, 187, 4, ".\\ssl\\s2_srvr.c", 1133);
      return v7;
    }
    else
    {
      ERR_put_error(a1, 0x14u, 187, 209, ".\\ssl\\s2_srvr.c", 1125);
      return -1;
    }
  }
  else
  {
    ERR_put_error(a1, 0x14u, 187, 189, ".\\ssl\\s2_srvr.c", 1120);
    return -1;
  }
}
