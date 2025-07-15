int __usercall do_esc_char@<eax>(
        unsigned __int8 flags@<dl>,
        int (__cdecl *io_ch)(void *, const void *, int)@<esi>,
        void *arg@<edi>,
        unsigned int c,
        char *do_quotes)
{
  char v6; // cl
  char v7; // [esp+7h] [ebp-11h] BYREF
  char v8[12]; // [esp+8h] [ebp-10h] BYREF

  if ( c > 0xFFFF )
  {
    BIO_snprintf(v8, 0xBu, "\\W%08lX", c);
    return io_ch(arg, v8, 10) != 0 ? 10 : -1;
  }
  if ( c > 0xFF )
  {
    BIO_snprintf(v8, 0xBu, "\\U%04lX", c);
    return io_ch(arg, v8, 6) != 0 ? 6 : -1;
  }
  v7 = c;
  if ( (unsigned __int8)c <= 0x7Fu )
    v6 = flags & char_type[(unsigned __int8)c];
  else
    v6 = flags & 4;
  if ( (v6 & 0x61) == 0 )
  {
    if ( (v6 & 6) != 0 )
    {
      BIO_snprintf(v8, 0xBu, "\\%02X", (unsigned __int8)c);
      return io_ch(arg, v8, 3) != 0 ? 3 : -1;
    }
    if ( (_BYTE)c == 92 && (flags & 0xF) != 0 )
      return io_ch(arg, asc_6D4EB0, 2) != 0 ? 2 : -1;
    return io_ch(arg, &v7, 1) != 0 ? 1 : -1;
  }
  if ( (v6 & 8) != 0 )
  {
    if ( do_quotes )
      *do_quotes = 1;
    return io_ch(arg, &v7, 1) != 0 ? 1 : -1;
  }
  if ( io_ch(arg, "\\", 1) )
    return io_ch(arg, &v7, 1) != 0 ? 2 : -1;
  else
    return -1;
}
