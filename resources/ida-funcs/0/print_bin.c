BOOL __usercall print_bin@<eax>(
        bio_st *fp@<edi>,
        const char *name@<ecx>,
        const unsigned __int8 *buf@<ebx>,
        unsigned int len,
        int off)
{
  int v5; // ebp
  unsigned int v8; // esi
  const char *v9; // ecx
  char v10[128]; // [esp+Ch] [ebp-84h] BYREF

  v5 = off;
  if ( !buf )
    return 1;
  if ( off )
  {
    if ( off > 128 )
      v5 = 128;
    memset((int)v10, 32, v5);
    if ( BIO_write((int)buf, fp, v10, v5) <= 0 )
      return 0;
  }
  if ( BIO_printf(fp, (char *)&stru_7F9BE8.allocator, name) <= 0 )
    return 0;
  v8 = 0;
  if ( len )
  {
    while ( 1 )
    {
      if ( !(v8 % 0xF) )
      {
        v10[0] = 10;
        memset((int)&v10[1], 32, v5 + 4);
        if ( BIO_write((int)buf, fp, v10, v5 + 5) <= 0 )
          break;
      }
      v9 = uri;
      if ( v8 + 1 != len )
        v9 = ":";
      if ( BIO_printf(fp, "%02x%s", buf[v8], v9) <= 0 )
        break;
      if ( ++v8 >= len )
        return BIO_write((int)buf, fp, "\n", 1) > 0;
    }
    return 0;
  }
  return BIO_write((int)buf, fp, "\n", 1) > 0;
}
