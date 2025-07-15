void __usercall doapr_outch(
        const __m128i **sbuffer@<ebx>,
        char **buffer@<edi>,
        unsigned int *maxlen@<esi>,
        unsigned int *currlen,
        char c)
{
  char *v5; // eax
  unsigned int v6; // eax

  if ( buffer && *currlen >= *maxlen )
  {
    do
    {
      if ( *buffer )
      {
        *maxlen += 1024;
        *buffer = (char *)CRYPTO_realloc(*buffer, *maxlen, ".\\crypto\\bio\\b_print.c", 749);
      }
      else
      {
        if ( !*maxlen )
          *maxlen = 1024;
        v5 = (char *)CRYPTO_malloc(*maxlen, ".\\crypto\\bio\\b_print.c", 741);
        *buffer = v5;
        if ( *currlen )
          memcpy((int)v5, *sbuffer, *currlen);
        *sbuffer = 0;
      }
    }
    while ( *currlen >= *maxlen );
  }
  v6 = *currlen;
  if ( *currlen < *maxlen )
  {
    if ( *sbuffer )
      (*sbuffer)->m128i_i8[v6] = c;
    else
      (*buffer)[v6] = c;
    ++*currlen;
  }
}
