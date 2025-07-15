void __fastcall fmtstr(
        unsigned int *maxlen,
        char **buffer,
        char **sbuffer,
        unsigned int *currlen,
        char *value,
        char flags,
        int min,
        int max)
{
  int v11; // eax
  int v12; // ebp
  char i; // al
  int cnt; // [esp+24h] [ebp+14h]

  cnt = 0;
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
    if ( cnt >= max )
      break;
    doapr_outch(sbuffer, buffer, maxlen, currlen, 32);
    ++cnt;
  }
  for ( i = *value; *value; i = *++value )
  {
    if ( cnt >= max )
      break;
    doapr_outch(sbuffer, buffer, maxlen, currlen, i);
    ++cnt;
  }
  for ( ; v12 < 0; ++v12 )
  {
    if ( cnt >= max )
      break;
    doapr_outch(sbuffer, buffer, maxlen, currlen, 32);
    ++cnt;
  }
}
