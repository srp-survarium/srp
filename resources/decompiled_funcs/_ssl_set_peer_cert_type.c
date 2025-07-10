int __cdecl ssl_set_peer_cert_type(sess_cert_st *sc, int type)
{
  sc->peer_cert_type = type;
  return 1;
}
