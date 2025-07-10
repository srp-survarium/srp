BOOL __cdecl PEM_get_EVP_CIPHER_INFO(char *header, evp_cipher_info_st *cipher)
{
  char *v2; // esi
  evp_cipher_info_st *v3; // edi
  _BYTE *v5; // esi
  _BYTE *v6; // esi
  const char *v7; // esi
  char v8; // al
  const char *v9; // esi
  char *v10; // esi
  const char *v11; // eax
  char v12; // bl
  const evp_cipher_st *cipherbyname; // eax

  v2 = header;
  v3 = cipher;
  cipher->cipher = 0;
  if ( !v2 || !*v2 || *v2 == 10 )
    return 1;
  if ( strncmp(v2, "Proc-Type: ", 0xBu) )
  {
    ERR_put_error(9u, 107, 107, ".\\crypto\\pem\\pem_lib.c", 493);
    return 0;
  }
  v5 = v2 + 11;
  if ( *v5 != 52 )
    return 0;
  v6 = v5 + 1;
  if ( *v6 != 44 )
    return 0;
  v7 = v6 + 1;
  if ( strncmp(v7, "ENCRYPTED", 9u) )
  {
    ERR_put_error(9u, 107, 106, ".\\crypto\\pem\\pem_lib.c", 498);
    return 0;
  }
  v8 = *v7;
  if ( *v7 != 10 )
  {
    while ( v8 )
    {
      v8 = *++v7;
      if ( v8 == 10 )
        goto LABEL_14;
    }
    goto LABEL_15;
  }
LABEL_14:
  if ( !*v7 )
  {
LABEL_15:
    ERR_put_error(9u, 107, 112, ".\\crypto\\pem\\pem_lib.c", 502);
    return 0;
  }
  v9 = v7 + 1;
  if ( !strncmp(v9, "DEK-Info: ", 0xAu) )
  {
    v10 = (char *)(v9 + 10);
    v11 = v10;
    while ( 1 )
    {
      v12 = *v10;
      if ( (*v10 < 65 || v12 > 90) && v12 != 45 && (unsigned __int8)(v12 - 48) > 9u )
        break;
      ++v10;
    }
    *v10 = 0;
    cipherbyname = EVP_get_cipherbyname(v11);
    v3->cipher = cipherbyname;
    *v10 = v12;
    header = v10 + 1;
    if ( cipherbyname )
    {
      return load_iv(&header, v3->iv) != 0;
    }
    else
    {
      ERR_put_error(9u, 107, 114, ".\\crypto\\pem\\pem_lib.c", 530);
      return 0;
    }
  }
  else
  {
    ERR_put_error(9u, 107, 105, ".\\crypto\\pem\\pem_lib.c", 505);
    return 0;
  }
}
