int __usercall file_ctrl@<eax>(stlp_std::ioinfo **a1@<edi>, int a2@<ebx>, bio_st *b, int cmd, int num, _iobuf *ptr)
{
  bio_st *v6; // esi
  int v7; // ebp
  int v9; // ebx
  int v10; // eax
  int v11; // ebx
  char *v12; // edi
  char *v15; // edi
  _iobuf *v16; // eax
  __int16 LastError; // ax
  _iobuf *v18; // [esp-8h] [ebp-18h]
  const char *v19; // [esp-8h] [ebp-18h]
  _UNKNOWN *retaddr; // [esp+10h] [ebp+0h] BYREF

  v6 = b;
  v7 = 1;
  switch ( cmd )
  {
    case 1:
    case 128:
      return fseek(a2, (int)a1, (_iobuf *)b->ptr, num, 0);
    case 2:
      return feof((_iobuf *)b->ptr);
    case 3:
    case 133:
      return ftell(a2, (int)a1, (_iobuf *)b->ptr);
    case 8:
      return b->shutdown;
    case 9:
      b->shutdown = num;
      return 1;
    case 11:
      fflush(a2, (int)a1, (_iobuf *)b->ptr);
      return 1;
    case 12:
      return v7;
    case 106:
      file_free(a2, b);
      v9 = num;
      v6->shutdown = num & 1;
      v18 = ptr;
      v6->ptr = ptr;
      v6->init = 1;
      v10 = _fileno(v9, (int)a1, v18);
      if ( (v9 & 0x10) != 0 )
        _setmode(a1, (int)v6, v10, (HINSTANCE__ *)0x4000);
      else
        _setmode(a1, (int)v6, v10, (HINSTANCE__ *)0x8000);
      return 1;
    case 107:
      if ( !ptr )
        return v7;
      ptr->_ptr = (char *)b->ptr;
      return 1;
    case 108:
      file_free(a2, b);
      v11 = num;
      v6->shutdown = num & 1;
      if ( (v11 & 8) != 0 )
      {
        if ( (v11 & 2) != 0 )
        {
          BUF_strlcpy((char *)&b, "a+", 4u);
          goto LABEL_21;
        }
        v19 = (const char *)&stru_809F70;
      }
      else
      {
        if ( (v11 & 2) != 0 )
        {
          if ( (v11 & 4) != 0 )
          {
            BUF_strlcpy((char *)&b, "r+", 4u);
            goto LABEL_21;
          }
        }
        else if ( (v11 & 4) != 0 )
        {
          BUF_strlcpy((char *)&b, "w", 4u);
          goto LABEL_21;
        }
        if ( (v11 & 2) == 0 )
        {
          ERR_put_error(v11, 0x20u, 116, 101, ".\\crypto\\bio\\bss_file.c", 379);
          return 0;
        }
        v19 = "r";
      }
      BUF_strlcpy((char *)&b, v19, 4u);
LABEL_21:
      v12 = (char *)&retaddr + 3;
      if ( (v11 & 0x10) != 0 )
      {
        while ( *++v12 )
          ;
        strcpy(v12, "t");
      }
      else
      {
        while ( *++v12 )
          ;
        strcpy(v12, "b");
      }
      v15 = (char *)ptr;
      v16 = fopen((const char *)v6, (char *)ptr, (char *)&b);
      if ( v16 )
      {
        v6->ptr = v16;
        v6->init = 1;
        BIO_clear_flags(v6, 0);
        return 1;
      }
      else
      {
        LastError = GetLastError();
        ERR_put_error(v11, 2u, 1, LastError, ".\\crypto\\bio\\bss_file.c", 398);
        ERR_add_error_data(5, "fopen('", v15, "','", &b, "')");
        ERR_put_error(v11, 0x20u, 116, 2, ".\\crypto\\bio\\bss_file.c", 400);
        return 0;
      }
    default:
      return 0;
  }
}
