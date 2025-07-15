int __usercall tls1_setup_key_block@<eax>(int a1@<ebx>, ssl_st *s)
{
  ssl_st *v2; // esi
  int s3; // eax
  const rsa_meth_st *v5; // ebx
  bio_st *v6; // eax
  int v7; // edi
  unsigned __int8 *v8; // ebx
  unsigned __int8 *v9; // eax
  unsigned __int8 *v10; // ebp
  const ssl_cipher_st *cipher; // eax
  int v12; // [esp+8h] [ebp-14h] BYREF
  int v13; // [esp+Ch] [ebp-10h] BYREF
  int v14; // [esp+10h] [ebp-Ch]
  const env_md_st *v15; // [esp+14h] [ebp-8h] BYREF
  ssl_comp_st *v16; // [esp+18h] [ebp-4h] BYREF

  v2 = s;
  s3 = (int)s->s3;
  v13 = 0;
  v12 = 0;
  v14 = 0;
  if ( *(_DWORD *)(s3 + 884) )
    return 1;
  if ( ssl_cipher_get_evp(s->session, (const evp_cipher_st **)&s, &v15, &v13, &v12, &v16) )
  {
    v2->s3->tmp.new_sym_enc = (const evp_cipher_st *)s;
    v2->s3->tmp.new_hash = v15;
    v2->s3->tmp.new_mac_pkey_type = v13;
    v2->s3->tmp.new_mac_secret_size = v12;
    v5 = EC_KEY_get0_public_key((const engine_st *)s);
    v6 = EC_KEY_get0_private_key(s);
    v7 = 2 * ((int)v6 + (_DWORD)v5 + v12);
    ssl3_cleanup_key_block(v2);
    v8 = (unsigned __int8 *)CRYPTO_malloc(v7, ".\\ssl\\t1_enc.c", 579);
    if ( v8 )
    {
      v2->s3->tmp.key_block_length = v7;
      v2->s3->tmp.key_block = v8;
      v9 = (unsigned __int8 *)CRYPTO_malloc(v7, ".\\ssl\\t1_enc.c", 588);
      v10 = v9;
      if ( v9 )
      {
        if ( tls1_generate_key_block(v7, v2, v8, v9) )
        {
          if ( (v2->options & 0x800) == 0 )
          {
            v2->s3->need_empty_fragments = 1;
            cipher = v2->session->cipher;
            if ( cipher )
            {
              if ( cipher->algorithm_enc == 32 )
                v2->s3->need_empty_fragments = 0;
              if ( v2->session->cipher->algorithm_enc == 4 )
                v2->s3->need_empty_fragments = 0;
            }
          }
          v14 = 1;
        }
      }
      else
      {
        ERR_put_error((int)v8, 0x14u, 211, 65, ".\\ssl\\t1_enc.c", 590);
      }
      if ( v10 )
      {
        OPENSSL_cleanse(v10, v7);
        CRYPTO_free(v10);
      }
      return v14;
    }
    else
    {
      ERR_put_error(0, 0x14u, 211, 65, ".\\ssl\\t1_enc.c", 581);
      return v14;
    }
  }
  else
  {
    ERR_put_error(a1, 0x14u, 211, 138, ".\\ssl\\t1_enc.c", 566);
    return 0;
  }
}
