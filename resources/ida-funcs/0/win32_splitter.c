file_st *__usercall win32_splitter@<eax>(const char *filename@<ecx>, int assume_last_is_dir@<ebx>)
{
  const char *v2; // edi
  const char *v3; // ebp
  const char **v5; // eax
  const char **v6; // esi
  int v7; // eax
  char v8; // dl
  int v9; // eax
  int v10; // ecx
  int v11; // ecx
  int v12; // ecx

  v2 = filename;
  v3 = filename;
  if ( !filename )
  {
    ERR_put_error(0x25u, 136, 111, ".\\crypto\\dso\\dso_win32.c", 322);
    return 0;
  }
  v5 = (const char **)CRYPTO_malloc(40, ".\\crypto\\dso\\dso_win32.c", 327);
  v6 = v5;
  if ( !v5 )
  {
    ERR_put_error(0x25u, 136, 65, ".\\crypto\\dso\\dso_win32.c", 331);
    return 0;
  }
  *v5 = 0;
  v5[1] = 0;
  v5[2] = 0;
  v5[3] = 0;
  v5[4] = 0;
  v5[5] = 0;
  v5[6] = 0;
  v5[7] = 0;
  v5[8] = 0;
  v5[9] = 0;
  v7 = 1;
  if ( *v2 == 92 && v2[1] == 92 || *v2 == 47 && v2[1] == 47 )
  {
    v7 = 0;
    v2 += 2;
    v3 = v2;
    *v6 = v2;
  }
  while ( 2 )
  {
    v8 = *v2;
    switch ( *v2 )
    {
      case 0:
        v12 = v2 - v3;
        if ( v7 )
        {
          if ( v12 > 0 )
          {
            if ( assume_last_is_dir )
            {
              if ( v7 == 1 )
              {
                v6[6] = v3;
                v6[7] = 0;
              }
              v6[7] += v2 - v3;
            }
            else
            {
              v6[8] = v3;
              v6[9] = (const char *)v12;
            }
          }
        }
        else
        {
          v6[1] = (const char *)v12;
        }
        goto LABEL_28;
      case 0x2F:
      case 0x5C:
        if ( v7 )
        {
          v11 = ++v2 - v3;
          if ( v7 == 1 )
          {
            v6[6] = v3;
            v7 = 2;
            v6[7] = (const char *)v11;
          }
          else
          {
            v6[7] += v11;
          }
          v3 = v2;
        }
        else
        {
          v10 = v2 - v3;
          ++v2;
          v6[1] = (const char *)v10;
          v7 = 2;
          v3 = v2;
          v6[6] = v2;
        }
        goto LABEL_28;
      case 0x3A:
        if ( v7 != 1 )
        {
          ERR_put_error(0x25u, 136, 115, ".\\crypto\\dso\\dso_win32.c", 356);
          CRYPTO_free(v6);
          return 0;
        }
        v9 = v2 - v3;
        ++v2;
        v6[2] = v3;
        v6[3] = (const char *)v9;
        v7 = 2;
        v3 = v2;
        v6[6] = v2;
LABEL_28:
        if ( v8 )
          continue;
        if ( !v6[1] )
          *v6 = 0;
        if ( !v6[3] )
          v6[2] = 0;
        if ( !v6[7] )
          v6[6] = 0;
        if ( !v6[9] )
          v6[8] = 0;
        return (file_st *)v6;
      default:
        ++v2;
        goto LABEL_28;
    }
  }
}
