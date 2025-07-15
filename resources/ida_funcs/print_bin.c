BOOL __usercall print_bin@<eax>(
        bio_st *fp@<edi>,
        const char *name@<ecx>,
        const unsigned __int8 *buf@<ebx>,
        unsigned int len,
        int off)
{
  int v5; // ebp
  unsigned int v8; // esi
  char **p_m_max_end; // ecx
  unsigned __int8 dst[128]; // [esp+Ch] [ebp-84h] BYREF

  v5 = off;
  if ( !buf )
    return 1;
  if ( off )
  {
    if ( off > 128 )
      v5 = 128;
    memset((int)dst, (unsigned __int8 *)0x20, v5);
    if ( BIO_write(fp, (const char *)dst, v5) <= 0 )
      return 0;
  }
  if ( (int)BIO_printf(fp, "%s", name) <= 0 )
    return 0;
  v8 = 0;
  if ( len )
  {
    while ( 1 )
    {
      if ( !(v8 % 0xF) )
      {
        dst[0] = 10;
        memset((int)&dst[1], (unsigned __int8 *)0x20, v5 + 4);
        if ( BIO_write(fp, (const char *)dst, v5 + 5) <= 0 )
          break;
      }
      p_m_max_end = (char **)&::buf;
      if ( v8 + 1 != len )
        p_m_max_end = &stru_95963C.m_max_end;
      if ( (int)BIO_printf(fp, "%02x%s", buf[v8], (const char *)p_m_max_end) <= 0 )
        break;
      if ( ++v8 >= len )
        return BIO_write(fp, "\n", 1) > 0;
    }
    return 0;
  }
  return BIO_write(fp, "\n", 1) > 0;
}
