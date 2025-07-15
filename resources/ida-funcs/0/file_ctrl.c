int __usercall file_ctrl@<eax>(stlp_std::ioinfo **a1@<edi>, bio_st *b, int cmd, int num, _iobuf *ptr)
{
  bio_st *v5; // esi
  int v6; // ebp
  unsigned int v8; // ebx
  int v9; // eax
  char v10; // bl
  char *v11; // edi
  _iobuf *v14; // edi
  _iobuf *v15; // eax
  __int16 LastError; // ax
  _iobuf *v17; // [esp-8h] [ebp-18h]
  const char *v18; // [esp-8h] [ebp-18h]
  _UNKNOWN *retaddr; // [esp+10h] [ebp+0h] BYREF

  v5 = b;
  v6 = 1;
  switch ( cmd )
  {
    case 1:
    case 128:
      return fseek((_iobuf *)b->ptr, num, 0);
    case 2:
      return feof((_iobuf *)b->ptr);
    case 3:
    case 133:
      return ftell((_iobuf *)b->ptr);
    case 8:
      return b->shutdown;
    case 9:
      b->shutdown = num;
      return 1;
    case 11:
      fflush((_iobuf *)b->ptr);
      return 1;
    case 12:
      return v6;
    case 106:
      file_free(b);
      v8 = num;
      v5->shutdown = num & 1;
      v17 = ptr;
      v5->ptr = ptr;
      v5->init = 1;
      v9 = _fileno(v8, (unsigned int)a1, v17);
      if ( (v8 & 0x10) != 0 )
        _setmode(a1, (unsigned int)v5, v9, (HINSTANCE__ *)0x4000);
      else
        _setmode(a1, (unsigned int)v5, v9, (HINSTANCE__ *)0x8000);
      return 1;
    case 107:
      if ( !ptr )
        return v6;
      ptr->_ptr = (char *)b->ptr;
      return 1;
    case 108:
      file_free(b);
      v10 = num;
      v5->shutdown = num & 1;
      if ( (v10 & 8) != 0 )
      {
        if ( (v10 & 2) != 0 )
        {
          BUF_strlcpy((char *)&b, "a+", 4u);
          goto LABEL_21;
        }
        v18 = "a";
      }
      else
      {
        if ( (v10 & 2) != 0 )
        {
          if ( (v10 & 4) != 0 )
          {
            BUF_strlcpy((char *)&b, "r+", 4u);
            goto LABEL_21;
          }
        }
        else if ( (v10 & 4) != 0 )
        {
          BUF_strlcpy((char *)&b, "w", 4u);
          goto LABEL_21;
        }
        if ( (v10 & 2) == 0 )
        {
          ERR_put_error(0x20u, 116, 101, ".\\crypto\\bio\\bss_file.c", 379);
          return 0;
        }
        v18 = "r";
      }
      BUF_strlcpy((char *)&b, v18, 4u);
LABEL_21:
      v11 = (char *)&retaddr + 3;
      if ( (v10 & 0x10) != 0 )
      {
        while ( *++v11 )
          ;
        strcpy(v11, "t");
      }
      else
      {
        while ( *++v11 )
          ;
        strcpy(v11, "b");
      }
      v14 = ptr;
      v15 = fopen(ptr, (const char *)&b);
      if ( v15 )
      {
        v5->ptr = v15;
        v5->init = 1;
        BIO_clear_flags(v5, 0);
        return 1;
      }
      else
      {
        LastError = GetLastError();
        ERR_put_error(2u, 1, LastError, ".\\crypto\\bio\\bss_file.c", 398);
        ERR_add_error_data(5, "fopen('", v14, "','", &b, "')");
        ERR_put_error(0x20u, 116, 2, ".\\crypto\\bio\\bss_file.c", 400);
        return 0;
      }
    default:
      return 0;
  }
}
