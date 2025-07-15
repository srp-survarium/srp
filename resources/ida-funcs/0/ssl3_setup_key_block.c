int __usercall ssl3_setup_key_block@<eax>(int a1@<ebx>, ssl_st *s)
{
  ssl_st *v2; // esi
  int result; // eax
  int v4; // ebx
  bio_st *v5; // eax
  int v6; // edi
  unsigned __int8 *v7; // eax
  const ssl_cipher_st *cipher; // ecx
  const env_md_st *md; // [esp+4h] [ebp-Ch] BYREF
  ssl_comp_st *v10; // [esp+8h] [ebp-8h] BYREF
  const rsa_meth_st *v11; // [esp+Ch] [ebp-4h]

  v2 = s;
  if ( s->s3->tmp.key_block_length )
    return 1;
  if ( ssl_cipher_get_evp(s->session, (const evp_cipher_st **)&s, &md, 0, 0, &v10) )
  {
    v2->s3->tmp.new_sym_enc = (const evp_cipher_st *)s;
    v2->s3->tmp.new_hash = md;
    v2->s3->tmp.new_compression = v10;
    v4 = EVP_MD_size(a1, md);
    if ( v4 >= 0 )
    {
      v11 = EC_KEY_get0_public_key((const engine_st *)s);
      v5 = EC_KEY_get0_private_key(s);
      v6 = 2 * ((int)v5 + (_DWORD)v11 + v4);
      ssl3_cleanup_key_block(v2);
      v7 = (unsigned __int8 *)CRYPTO_malloc(v6, ".\\ssl\\s3_enc.c", 422);
      if ( v7 )
      {
        v2->s3->tmp.key_block_length = v6;
        v2->s3->tmp.key_block = v7;
        result = ssl3_generate_key_block(v7, v6);
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
      }
      else
      {
        ERR_put_error(v4, 0x14u, 157, 65, ".\\ssl\\s3_enc.c", 452);
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
    ERR_put_error(a1, 0x14u, 157, 138, ".\\ssl\\s3_enc.c", 401);
    return 0;
  }
  return result;
}
