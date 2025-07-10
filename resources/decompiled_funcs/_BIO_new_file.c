bio_st *__cdecl BIO_new_file(const char *filename, const char *mode)
{
  int v2; // edi
  int v3; // esi
  _iobuf *v4; // eax
  void *v5; // esp
  _iobuf *v6; // esi
  __int16 LastError; // ax
  bio_st *v9; // eax
  bio_st *v10; // edi
  wchar_t v11[6]; // [esp+0h] [ebp-30h] BYREF
  wchar_t *file; // [esp+Ch] [ebp-24h]
  DWORD dwFlags; // [esp+10h] [ebp-20h]
  LPCCH v14; // [esp+14h] [ebp-1Ch]
  LPCCH v15; // [esp+18h] [ebp-18h]
  wchar_t WideCharStr[8]; // [esp+1Ch] [ebp-14h] BYREF

  v14 = mode;
  v15 = filename;
  v2 = strlen(filename) + 1;
  dwFlags = 8;
  v3 = MultiByteToWideChar(0xFDE9u, 8u, filename, v2, 0, 0);
  if ( v3 > 0 || GetLastError() == 1004 && (dwFlags = 0, v3 = MultiByteToWideChar(0xFDE9u, 0, v15, v2, 0, 0), v3 > 0) )
  {
    v5 = alloca(2 * v3);
    file = v11;
    if ( MultiByteToWideChar(0xFDE9u, dwFlags, v15, v2, v11, v3)
      && MultiByteToWideChar(0xFDE9u, 0, v14, strlen(v14) + 1, WideCharStr, 8) )
    {
      v6 = _wfopen(file, WideCharStr);
      if ( v6 )
        goto LABEL_18;
      if ( *_errno() != 2 && *_errno() != 9 )
      {
LABEL_13:
        if ( !v6 )
          goto LABEL_14;
LABEL_18:
        v9 = BIO_new(&methods_filep);
        v10 = v9;
        if ( v9 )
        {
          BIO_clear_flags(v9, 0);
          BIO_ctrl(v10, 106, 1, v6);
          return v10;
        }
        else
        {
          fclose(v6);
          return 0;
        }
      }
      v4 = fopen((_iobuf *)v15, v14);
LABEL_12:
      v6 = v4;
      goto LABEL_13;
    }
  }
  else if ( GetLastError() == 1113 )
  {
    v4 = fopen((_iobuf *)v15, v14);
    goto LABEL_12;
  }
LABEL_14:
  LastError = GetLastError();
  ERR_put_error(2u, 1, LastError, ".\\crypto\\bio\\bss_file.c", 169);
  ERR_add_error_data(5, "fopen('", v15, "','", v14, "')");
  if ( *_errno() == 2 )
    ERR_put_error(0x20u, 109, 128, ".\\crypto\\bio\\bss_file.c", 172);
  else
    ERR_put_error(0x20u, 109, 2, ".\\crypto\\bio\\bss_file.c", 174);
  return 0;
}
