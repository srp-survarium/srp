BOOL __usercall PEM_get_EVP_CIPHER_INFO@<eax>(int a1@<ebx>, char *header, evp_cipher_info_st *cipher)
{
  char *v3; // esi
  evp_cipher_info_st *v4; // edi
  _BYTE *v6; // esi
  _BYTE *v7; // esi
  const char *v8; // esi
  char v9; // al
  const char *v10; // esi
  char *v11; // esi
  char *v12; // eax
  char v13; // bl
  const evp_cipher_st *cipherbyname; // eax

  v3 = header;
  v4 = cipher;
  cipher->cipher = 0;
  if ( !v3 || !*v3 || *v3 == 10 )
    return 1;
  if ( strncmp(v3, "Proc-Type: ", 0xBu) )
  {
    ERR_put_error(a1, 9u, 107, 107, ".\\crypto\\pem\\pem_lib.c", 493);
    return 0;
  }
  v6 = v3 + 11;
  if ( *v6 != 52 )
    return 0;
  v7 = v6 + 1;
  if ( *v7 != 44 )
    return 0;
  v8 = v7 + 1;
  if ( strncmp(v8, "ENCRYPTED", 9u) )
  {
    ERR_put_error(a1, 9u, 107, 106, ".\\crypto\\pem\\pem_lib.c", 498);
    return 0;
  }
  v9 = *v8;
  if ( *v8 != 10 )
  {
    while ( v9 )
    {
      v9 = *++v8;
      if ( v9 == 10 )
        goto LABEL_14;
    }
    goto LABEL_15;
  }
LABEL_14:
  if ( !*v8 )
  {
LABEL_15:
    ERR_put_error(a1, 9u, 107, 112, ".\\crypto\\pem\\pem_lib.c", 502);
    return 0;
  }
  v10 = v8 + 1;
  if ( !strncmp(v10, "DEK-Info: ", 0xAu) )
  {
    v11 = (char *)(v10 + 10);
    v12 = v11;
    while ( 1 )
    {
      v13 = *v11;
      if ( (*v11 < 65 || v13 > 90) && v13 != 45 && (unsigned __int8)(v13 - 48) > 9u )
        break;
      ++v11;
    }
    *v11 = 0;
    cipherbyname = EVP_get_cipherbyname(v12);
    v4->cipher = cipherbyname;
    *v11 = v13;
    header = v11 + 1;
    if ( cipherbyname )
    {
      return load_iv(cipherbyname->iv_len, a1, &header, v4->iv) != 0;
    }
    else
    {
      ERR_put_error(a1, 9u, 107, 114, ".\\crypto\\pem\\pem_lib.c", 530);
      return 0;
    }
  }
  else
  {
    ERR_put_error(a1, 9u, 107, 105, ".\\crypto\\pem\\pem_lib.c", 505);
    return 0;
  }
}
