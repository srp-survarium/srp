void __fastcall fmtstr(
        unsigned int *maxlen,
        char **buffer,
        const __m128i **sbuffer,
        unsigned int *currlen,
        char *value,
        char flags,
        int min,
        int max)
{
  int v11; // eax
  int v12; // ebp
  char i; // al
  int v14; // [esp+24h] [ebp+14h]

  v14 = 0;
  if ( !value )
    value = "<NULL>";
  v11 = 0;
  if ( *value )
  {
    do
      ++v11;
    while ( value[v11] );
  }
  v12 = min - v11;
  if ( v12 < 0 )
    v12 = 0;
  if ( (flags & 1) != 0 )
    v12 = -v12;
  for ( ; v12 > 0; --v12 )
  {
    if ( v14 >= max )
      break;
    doapr_outch(sbuffer, buffer, maxlen, currlen, 32);
    ++v14;
  }
  for ( i = *value; *value; i = *++value )
  {
    if ( v14 >= max )
      break;
    doapr_outch(sbuffer, buffer, maxlen, currlen, i);
    ++v14;
  }
  for ( ; v12 < 0; ++v12 )
  {
    if ( v14 >= max )
      break;
    doapr_outch(sbuffer, buffer, maxlen, currlen, 32);
    ++v14;
  }
}
