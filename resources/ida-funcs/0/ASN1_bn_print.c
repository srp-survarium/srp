int __cdecl ASN1_bn_print(bio_st *bp, const char *number, const bignum_st *num, unsigned __int8 *buf, int off)
{
  int result; // eax
  const char *v6; // esi
  unsigned __int8 *v7; // ebp
  const char *v8; // eax
  int v9; // eax
  int v10; // edi
  int v11; // esi
  const char *v12; // ecx

  if ( !num )
    return 1;
  v6 = "-";
  if ( !num->neg )
    v6 = uri;
  result = BIO_indent((int)bp, bp, off, 128);
  if ( result )
  {
    if ( !num->top )
      return BIO_printf(bp, "%s 0\n", number) > 0;
    if ( (BN_num_bits(num) + 7) / 8 <= 4 )
      return BIO_printf(bp, "%s %s%lu (%s0x%lx)\n", number, v6, *num->d, v6, *num->d) > 0;
    v7 = buf;
    *buf = 0;
    v8 = " (Negative)";
    if ( *v6 != 45 )
      v8 = uri;
    if ( BIO_printf(bp, "%s%s", number, v8) > 0 )
    {
      v9 = BN_bn2bin(num, buf + 1);
      v10 = v9;
      if ( (buf[1] & 0x80u) == 0 )
        v7 = buf + 1;
      else
        v10 = v9 + 1;
      v11 = 0;
      if ( v10 <= 0 )
      {
LABEL_25:
        if ( BIO_write((int)bp, bp, "\n", 1) > 0 )
          return 1;
      }
      else
      {
        while ( v11 % 15 || BIO_puts((int)bp, bp, "\n") > 0 && BIO_indent((int)bp, bp, off + 4, 128) )
        {
          v12 = uri;
          if ( v11 + 1 != v10 )
            v12 = ":";
          if ( BIO_printf(bp, "%02x%s", v7[v11], v12) <= 0 )
            break;
          if ( ++v11 >= v10 )
            goto LABEL_25;
        }
      }
    }
    return 0;
  }
  return result;
}
