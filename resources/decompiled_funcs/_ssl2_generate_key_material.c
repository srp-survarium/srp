int __cdecl ssl2_generate_key_material(ssl_st *s)
{
  const env_md_st *v1; // ebx
  unsigned __int8 *key_material; // edi
  int v3; // ebx
  ssl2_state_st *s2; // eax
  unsigned int v5; // ebp
  char data; // [esp+Fh] [ebp-1Dh]
  const env_md_st *type; // [esp+10h] [ebp-1Ch]
  env_md_ctx_st ctx; // [esp+14h] [ebp-18h] BYREF

  data = 48;
  v1 = EVP_md5();
  type = v1;
  EVP_MD_CTX_init(&ctx);
  key_material = s->s2->key_material;
  if ( s->session->master_key_length > 0x30u )
  {
    ERR_put_error(0x14u, 241, 68, ".\\ssl\\s2_lib.c", 469);
    return 0;
  }
  v3 = EVP_MD_size(v1);
  if ( v3 < 0 )
    return 0;
  s2 = s->s2;
  v5 = 0;
  if ( s2->key_material_length )
  {
    while ( (int)&key_material[v3 - (_DWORD)s2 - 160] <= 48 )
    {
      EVP_DigestInit_ex(&ctx, type, 0);
      if ( s->session->master_key_length >= 0x30u )
        OpenSSLDie(
          (unsigned int)key_material,
          (unsigned int)s,
          ".\\ssl\\s2_lib.c",
          489,
          "s->session->master_key_length >= 0 && s->session->master_key_length < (int)sizeof(s->session->master_key)");
      EVP_DigestUpdate(&ctx);
      EVP_DigestUpdate(&ctx);
      ++data;
      EVP_DigestUpdate(&ctx);
      EVP_DigestUpdate(&ctx);
      EVP_DigestFinal_ex((unsigned int)key_material, &ctx, key_material, 0);
      s2 = s->s2;
      v5 += v3;
      key_material += v3;
      if ( v5 >= s2->key_material_length )
        goto LABEL_8;
    }
    ERR_put_error(0x14u, 241, 68, ".\\ssl\\s2_lib.c", 481);
    return 0;
  }
  else
  {
LABEL_8:
    EVP_MD_CTX_cleanup((unsigned int)key_material, &ctx);
    return 1;
  }
}
