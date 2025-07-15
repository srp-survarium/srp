int __usercall ssl_rsa_public_encrypt@<eax>(
        int a1@<ebx>,
        sess_cert_st *sc,
        int len,
        unsigned __int8 *from,
        unsigned __int8 *to)
{
  int v5; // esi
  cert_pkey_st *peer_key; // eax
  evp_pkey_st *pubkey; // eax
  evp_pkey_st *v8; // edi

  v5 = -1;
  if ( sc && (peer_key = sc->peer_key, peer_key->x509) && (pubkey = X509_get_pubkey(peer_key->x509), (v8 = pubkey) != 0) )
  {
    if ( pubkey->type == 6 )
    {
      v5 = RSA_public_encrypt(len, from, to, pubkey->pkey.rsa);
      if ( v5 < 0 )
        ERR_put_error(a1, 0x14u, 188, 4, ".\\ssl\\s2_clnt.c", 1114);
    }
    else
    {
      ERR_put_error(a1, 0x14u, 188, 209, ".\\ssl\\s2_clnt.c", 1107);
    }
    EVP_PKEY_free((int)v8, v8);
    return v5;
  }
  else
  {
    ERR_put_error(a1, 0x14u, 188, 192, ".\\ssl\\s2_clnt.c", 1102);
    return -1;
  }
}
