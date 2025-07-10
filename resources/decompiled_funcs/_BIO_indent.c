int __cdecl BIO_indent(bio_st *b, int indent, int max)
{
  int v3; // esi

  v3 = indent;
  if ( indent < 0 )
    v3 = 0;
  if ( v3 > max )
    v3 = max;
  if ( !v3 )
    return 1;
  while ( 1 )
  {
    --v3;
    if ( BIO_puts(b, (const char *)&stru_95AF78) != 1 )
      break;
    if ( !v3 )
      return 1;
  }
  return 0;
}
