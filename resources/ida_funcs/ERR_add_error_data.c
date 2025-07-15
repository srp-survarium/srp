void ERR_add_error_data(int num, ...)
{
  int v1; // esi
  _BYTE *v2; // eax
  void *v3; // edi
  int v4; // ebx
  bool v5; // cc
  int *p_num; // eax
  const char *v7; // ebp
  void *v8; // eax
  int v9; // [esp+Ch] [ebp-8h]
  int *v10; // [esp+10h] [ebp-4h]

  v1 = 80;
  v2 = CRYPTO_malloc(81, ".\\crypto\\err\\err.c", 1073);
  v3 = v2;
  v4 = 0;
  if ( v2 )
  {
    v5 = num <= 0;
    *v2 = 0;
    v9 = 0;
    if ( !v5 )
    {
      p_num = &num;
      do
      {
        v7 = (const char *)p_num[1];
        v10 = ++p_num;
        if ( v7 )
        {
          v4 += strlen(v7);
          if ( v4 > v1 )
          {
            v1 = v4 + 20;
            v8 = CRYPTO_realloc(v3, v4 + 21, ".\\crypto\\err\\err.c", 1089);
            if ( !v8 )
            {
              CRYPTO_free(v3);
              return;
            }
            v3 = v8;
          }
          BUF_strlcat((char *)v3, v7, v1 + 1);
          p_num = v10;
        }
        ++v9;
      }
      while ( v9 < num );
    }
    ERR_set_error_data((char *)v3, 3);
  }
}
