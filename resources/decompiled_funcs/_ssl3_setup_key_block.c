int __cdecl ssl3_setup_key_block(const engine_st *s)
{
  ssl_st *v1; // esi
  int result; // eax
  int v3; // ebx
  bio_st *v4; // eax
  int v5; // edi
  unsigned __int8 *v6; // eax
  const ssl_cipher_st *cipher; // ecx
  const env_md_st *md; // [esp+4h] [ebp-Ch] BYREF
  ssl_comp_st *comp; // [esp+8h] [ebp-8h] BYREF
  const rsa_meth_st *v10; // [esp+Ch] [ebp-4h]

  v1 = (ssl_st *)s;
  if ( *(_DWORD *)(s->struct_ref + 884) )
    return 1;
  if ( ssl_cipher_get_evp((const ssl_session_st *)s[1].cmd_defns, (const evp_cipher_st **)&s, &md, 0, 0, &comp) )
  {
    v1->s3->tmp.new_sym_enc = (const evp_cipher_st *)s;
    v1->s3->tmp.new_hash = md;
    v1->s3->tmp.new_compression = comp;
    v3 = EVP_MD_size(md);
    if ( v3 >= 0 )
    {
      v10 = EC_KEY_get0_public_key(s);
      v4 = EC_KEY_get0_private_key((const ssl_st *)s);
      v5 = 2 * ((int)v4 + (_DWORD)v10 + v3);
      ssl3_cleanup_key_block(v1);
      v6 = (unsigned __int8 *)CRYPTO_malloc(v5, ".\\ssl\\s3_enc.c", 422);
      if ( v6 )
      {
        v1->s3->tmp.key_block_length = v5;
        v1->s3->tmp.key_block = v6;
        result = ssl3_generate_key_block(v6, v5);
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
      }
      else
      {
        ERR_put_error(0x14u, 157, 65, ".\\ssl\\s3_enc.c", 452);
        return 0;
      }
    }
    else
    {
      return 0;
    }
  }
  else
  {
    ERR_put_error(0x14u, 157, 138, ".\\ssl\\s3_enc.c", 401);
    return 0;
  }
  return result;
}
