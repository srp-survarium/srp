int __usercall tls1_generate_key_block@<eax>(int num@<edx>, ssl_st *s, unsigned __int8 *km, unsigned __int8 *tmp)
{
  return tls1_PRF(
           s->s3->tmp.new_cipher->algorithm2,
           "key expansion",
           13,
           s->s3->server_random,
           32,
           s->s3->client_random,
           32,
           0,
           0,
           0,
           0,
           (const __m128i *)s->session->master_key,
           s->session->master_key_length,
           km,
           tmp,
           num);
}
