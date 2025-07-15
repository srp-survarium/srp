void __cdecl ssl_sess_cert_free(sess_cert_st *sc)
{
  cert_pkey_st *peer_pkeys; // esi
  int v2; // ebx

  if ( sc && CRYPTO_add_lock(&sc->references, -1, 15, ".\\ssl\\ssl_cert.c", 439) <= 0 )
  {
    if ( sc->cert_chain )
      sk_pop_free(&sc->cert_chain->stack, (void (__cdecl *)(void *))X509_free);
    peer_pkeys = sc->peer_pkeys;
    v2 = 8;
    do
    {
      if ( peer_pkeys->x509 )
        X509_free(peer_pkeys->x509);
      ++peer_pkeys;
      --v2;
    }
    while ( v2 );
    if ( sc->peer_rsa_tmp )
      RSA_free((unsigned int)sc, sc->peer_rsa_tmp);
    if ( sc->peer_dh_tmp )
      DH_free((unsigned int)sc, sc->peer_dh_tmp);
    if ( sc->peer_ecdh_tmp )
      EC_KEY_free(sc->peer_ecdh_tmp);
    CRYPTO_free(sc);
  }
}
