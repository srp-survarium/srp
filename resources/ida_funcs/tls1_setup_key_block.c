int __cdecl tls1_setup_key_block(const engine_st *s)
{
  ssl_st *v1; // esi
  ssl3_state_st *struct_ref; // eax
  const rsa_meth_st *v4; // ebx
  bio_st *v5; // eax
  int v6; // edi
  unsigned __int8 *v7; // ebx
  unsigned __int8 *v8; // eax
  unsigned __int8 *v9; // ebp
  const ssl_cipher_st *cipher; // eax
  int mac_secret_size; // [esp+8h] [ebp-14h] BYREF
  int mac_pkey_type; // [esp+Ch] [ebp-10h] BYREF
  int v13; // [esp+10h] [ebp-Ch]
  const env_md_st *md; // [esp+14h] [ebp-8h] BYREF
  ssl_comp_st *comp; // [esp+18h] [ebp-4h] BYREF

  v1 = (ssl_st *)s;
  struct_ref = (ssl3_state_st *)s->struct_ref;
  mac_pkey_type = 0;
  mac_secret_size = 0;
  v13 = 0;
  if ( struct_ref->tmp.key_block_length )
    return 1;
  if ( ssl_cipher_get_evp(
         (const ssl_session_st *)s[1].cmd_defns,
         (const evp_cipher_st **)&s,
         &md,
         &mac_pkey_type,
         &mac_secret_size,
         &comp) )
  {
    v1->s3->tmp.new_sym_enc = (const evp_cipher_st *)s;
    v1->s3->tmp.new_hash = md;
    v1->s3->tmp.new_mac_pkey_type = mac_pkey_type;
    v1->s3->tmp.new_mac_secret_size = mac_secret_size;
    v4 = EC_KEY_get0_public_key(s);
    v5 = EC_KEY_get0_private_key((const ssl_st *)s);
    v6 = 2 * ((int)v5 + (_DWORD)v4 + mac_secret_size);
    ssl3_cleanup_key_block(v1);
    v7 = (unsigned __int8 *)CRYPTO_malloc(v6, ".\\ssl\\t1_enc.c", 579);
    if ( v7 )
    {
      v1->s3->tmp.key_block_length = v6;
      v1->s3->tmp.key_block = v7;
      v8 = (unsigned __int8 *)CRYPTO_malloc(v6, ".\\ssl\\t1_enc.c", 588);
      v9 = v8;
      if ( v8 )
      {
        if ( tls1_generate_key_block(v6, v1, v7, v8) )
        {
          if ( (v1->options & 0x800) == 0 )
          {
            v1->s3->need_empty_fragments = 1;
            cipher = v1->session->cipher;
            if ( cipher )
            {
              if ( cipher->algorithm_enc == 32 )
                v1->s3->need_empty_fragments = 0;
              if ( v1->session->cipher->algorithm_enc == 4 )
                v1->s3->need_empty_fragments = 0;
            }
          }
          v13 = 1;
        }
      }
      else
      {
        ERR_put_error(0x14u, 211, 65, ".\\ssl\\t1_enc.c", 590);
      }
      if ( v9 )
      {
        OPENSSL_cleanse(v9, v6);
        CRYPTO_free(v9);
      }
      return v13;
    }
    else
    {
      ERR_put_error(0x14u, 211, 65, ".\\ssl\\t1_enc.c", 581);
      return v13;
    }
  }
  else
  {
    ERR_put_error(0x14u, 211, 138, ".\\ssl\\t1_enc.c", 566);
    return 0;
  }
}
