void __cdecl ERR_print_errors_cb(int (__cdecl *cb)(const char *, unsigned int, void *), void *u)
{
  int v2; // esi
  unsigned int i; // eax
  char *v4; // eax
  char *file; // [esp+Ch] [ebp-111Ch] BYREF
  int flags; // [esp+10h] [ebp-1118h] BYREF
  int line; // [esp+14h] [ebp-1114h] BYREF
  char *data; // [esp+18h] [ebp-1110h] BYREF
  env_md_st id[3]; // [esp+1Ch] [ebp-110Ch] BYREF
  char v10[4096]; // [esp+124h] [ebp-1004h] BYREF

  CRYPTO_THREADID_current((crypto_threadid_st *)id);
  v2 = EVP_CIPHER_block_size(id);
  for ( i = ERR_get_error_line_data((const char **)&file, &line, (const char **)&data, &flags);
        i;
        i = ERR_get_error_line_data((const char **)&file, &line, (const char **)&data, &flags) )
  {
    ERR_error_string_n(i, (char *)&id[0].md_size, 0x100u);
    v4 = data;
    if ( (flags & 2) == 0 )
      v4 = (char *)&buf;
    BIO_snprintf(v10, 0x1000u, "%lu:%s:%s:%d:%s\n", v2, (const char *)&id[0].md_size, file, line, v4);
    if ( cb(v10, strlen(v10), u) <= 0 )
      break;
  }
}
