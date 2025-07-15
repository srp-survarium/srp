unsigned int __usercall file_read@<eax>(int a1@<ebx>, int a2@<edi>, bio_st *b, char *out, unsigned int outl)
{
  unsigned int result; // eax
  unsigned int v6; // edi
  __int16 LastError; // ax

  result = 0;
  if ( b->init && out )
  {
    v6 = fread(a1, a2, (unsigned __int8 *)out, 1u, outl, (_iobuf *)b->ptr);
    if ( ferror((_iobuf *)b->ptr) )
    {
      LastError = GetLastError();
      ERR_put_error(a1, 2u, 11, LastError, ".\\crypto\\bio\\bss_file.c", 245);
      ERR_put_error(a1, 0x20u, 130, 2, ".\\crypto\\bio\\bss_file.c", 246);
      return -1;
    }
    else
    {
      return v6;
    }
  }
  return result;
}
