int __cdecl tls1_generate_master_secret(ssl_st *s, unsigned __int8 *out, unsigned __int8 *p, int len)
{
  unsigned __int8 out2[48]; // [esp+4h] [ebp-34h] BYREF

  tls1_PRF(
    s->s3->tmp.new_cipher->algorithm2,
    "master secret",
    0xDu,
    s->s3->client_random,
    0x20u,
    0,
    0,
    s->s3->server_random,
    0x20u,
    0,
    0,
    p,
    len,
    s->session->master_key,
    out2,
    48);
  return 48;
}
