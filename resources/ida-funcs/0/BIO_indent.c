int __usercall BIO_indent@<eax>(int a1@<ebx>, bio_st *b, int indent, int max)
{
  int v4; // esi

  v4 = indent;
  if ( indent < 0 )
    v4 = 0;
  if ( v4 > max )
    v4 = max;
  if ( !v4 )
    return 1;
  while ( 1 )
  {
    --v4;
    if ( BIO_puts(a1, b, " ") != 1 )
      break;
    if ( !v4 )
      return 1;
  }
  return 0;
}
