char *__cdecl BUF_strndup(char *str, unsigned int siz)
{
  char *v3; // eax
  char *v4; // esi

  if ( !str )
    return 0;
  v3 = (char *)CRYPTO_malloc(siz + 1, ".\\crypto\\buffer\\buffer.c", 177);
  v4 = v3;
  if ( v3 )
  {
    BUF_strlcpy(v3, str, siz + 1);
    return v4;
  }
  else
  {
    ERR_put_error((int)str, 7u, 104, 65, ".\\crypto\\buffer\\buffer.c", 180);
    return 0;
  }
}
