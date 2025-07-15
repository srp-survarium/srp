evp_pkey_st *__usercall ssl_get_sign_pkey@<eax>(int a1@<ebx>, ssl_st *s, const ssl_cipher_st *cipher)
{
  unsigned int algorithm_auth; // edx
  cert_st *cert; // ecx
  evp_pkey_st *result; // eax

  algorithm_auth = cipher->algorithm_auth;
  cert = s->cert;
  if ( (algorithm_auth & 2) == 0 || (result = cert->pkeys[2].privatekey) == 0 )
  {
    if ( (algorithm_auth & 1) != 0 )
    {
      result = cert->pkeys[1].privatekey;
      if ( !result )
        return cert->pkeys[0].privatekey;
    }
    else if ( (algorithm_auth & 0x40) == 0 || (result = cert->pkeys[5].privatekey) == 0 )
    {
      ERR_put_error(a1, 0x14u, 183, 68, ".\\ssl\\ssl_lib.c", 2198);
      return 0;
    }
  }
  return result;
}
