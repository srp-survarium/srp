int __usercall ssl_prepare_serverhello_tlsext@<eax>(int a1@<ebx>, ssl_st *s)
{
  const ssl_cipher_st *new_cipher; // eax
  unsigned __int8 *v3; // eax

  new_cipher = s->s3->tmp.new_cipher;
  if ( ((new_cipher->algorithm_mkey & 0xE0) != 0 || (new_cipher->algorithm_auth & 0x40) != 0)
    && s->session->tlsext_ecpointformatlist )
  {
    if ( s->tlsext_ecpointformatlist )
      CRYPTO_free(s->tlsext_ecpointformatlist);
    v3 = (unsigned __int8 *)CRYPTO_malloc(3, ".\\ssl\\t1_lib.c", 1321);
    s->tlsext_ecpointformatlist = v3;
    if ( !v3 )
    {
      ERR_put_error(a1, 0x14u, 282, 65, ".\\ssl\\t1_lib.c", 1323);
      return -1;
    }
    s->tlsext_ecpointformatlist_length = 3;
    *v3 = 0;
    s->tlsext_ecpointformatlist[1] = 1;
    s->tlsext_ecpointformatlist[2] = 2;
  }
  return 1;
}
