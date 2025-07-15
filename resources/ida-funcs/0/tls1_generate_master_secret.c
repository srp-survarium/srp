int __cdecl tls1_generate_master_secret(ssl_st *s, unsigned __int8 *out, const __m128i *p, int len)
{
  unsigned __int8 v5[48]; // [esp+4h] [ebp-34h] BYREF

  tls1_PRF(
    s->s3->tmp.new_cipher->algorithm2,
    "master secret",
    13,
    s->s3->client_random,
    32,
    0,
    0,
    s->s3->server_random,
    32,
    0,
    0,
    p,
    len,
    s->session->master_key,
    v5,
    48);
  return 48;
}
