unsigned int __cdecl file_read(bio_st *b, char *out, unsigned int outl)
{
  unsigned int result; // eax
  unsigned int v4; // edi
  __int16 LastError; // ax

  result = 0;
  if ( b->init && out )
  {
    v4 = fread(out, 1u, outl, (_iobuf *)b->ptr);
    if ( ferror((_iobuf *)b->ptr) )
    {
      LastError = GetLastError();
      ERR_put_error(2u, 11, LastError, ".\\crypto\\bio\\bss_file.c", 245);
      ERR_put_error(0x20u, 130, 2, ".\\crypto\\bio\\bss_file.c", 246);
      return -1;
    }
    else
    {
      return v4;
    }
  }
  return result;
}
