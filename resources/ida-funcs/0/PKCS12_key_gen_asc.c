int __usercall PKCS12_key_gen_asc@<eax>(
        int a1@<ebx>,
        char *pass,
        unsigned int passlen,
        unsigned __int8 *salt,
        int saltlen,
        int id,
        int iter,
        int n,
        unsigned __int8 *out,
        const env_md_st *md_type)
{
  int v10; // esi
  int passlena; // [esp+0h] [ebp-4h] BYREF

  if ( pass )
  {
    if ( !OPENSSL_asc2uni(pass, passlen, (unsigned __int8 **)&pass, &passlena) )
    {
      ERR_put_error(a1, 0x23u, 110, 65, ".\\crypto\\pkcs12\\p12_key.c", 89);
      return 0;
    }
  }
  else
  {
    pass = 0;
    passlena = 0;
  }
  v10 = PKCS12_key_gen_uni(a1, (unsigned __int8 *)pass, passlena, salt, saltlen, id, iter, n, out, md_type);
  if ( v10 <= 0 )
    return 0;
  if ( pass )
  {
    OPENSSL_cleanse(pass, passlena);
    CRYPTO_free(pass);
  }
  return v10;
}
