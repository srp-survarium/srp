char *__cdecl win32_merger(dso_st *dso, const char *filespec1, const char *filespec2)
{
  file_st *v3; // esi
  file_st *v4; // ebx
  char *v6; // edi
  file_st *v7; // eax
  const char *dir; // eax
  char v9; // al

  v3 = 0;
  v4 = 0;
  if ( filespec1 )
  {
    if ( filespec2 )
    {
      v3 = win32_splitter(filespec1, 0);
      if ( !v3 )
      {
        ERR_put_error(0, 0x25u, 134, 65, ".\\crypto\\dso\\dso_win32.c", 586);
        return 0;
      }
      v7 = win32_splitter(filespec2, 1);
      v4 = v7;
      if ( !v7 )
      {
        ERR_put_error(0, 0x25u, 134, 65, ".\\crypto\\dso\\dso_win32.c", 593);
        CRYPTO_free(v3);
        return 0;
      }
      if ( !v3->node && !v3->device )
      {
        v3->node = v7->node;
        v3->nodelen = v7->nodelen;
        v3->device = v7->device;
        v3->devicelen = v7->devicelen;
      }
      dir = v3->dir;
      if ( dir )
      {
        v9 = *dir;
        if ( v9 != 92 && v9 != 47 )
        {
          v3->predir = v4->dir;
          v3->predirlen = v4->dirlen;
        }
      }
      else
      {
        v3->dir = v4->dir;
        v3->dirlen = v4->dirlen;
      }
      if ( !v3->file )
      {
        v3->file = v4->file;
        v3->filelen = v4->filelen;
      }
      v6 = win32_joiner(v3, (int)v4);
    }
    else
    {
      v6 = (char *)CRYPTO_malloc(strlen(filespec1) + 1, ".\\crypto\\dso\\dso_win32.c", 560);
      if ( !v6 )
      {
        ERR_put_error(0, 0x25u, 134, 65, ".\\crypto\\dso\\dso_win32.c", 564);
        return 0;
      }
      strcpy(v6, filespec1);
    }
  }
  else
  {
    if ( !filespec2 )
    {
      ERR_put_error(0, 0x25u, 134, 67, ".\\crypto\\dso\\dso_win32.c", 555);
      return 0;
    }
    v6 = (char *)CRYPTO_malloc(strlen(filespec2) + 1, ".\\crypto\\dso\\dso_win32.c", 571);
    if ( !v6 )
    {
      ERR_put_error(0, 0x25u, 134, 65, ".\\crypto\\dso\\dso_win32.c", 575);
      return 0;
    }
    strcpy(v6, filespec2);
  }
  CRYPTO_free(v3);
  CRYPTO_free(v4);
  return v6;
}
