void __cdecl __ascii_strnicmp(unsigned __int8 *first, unsigned __int8 *last, unsigned int count)
{
  unsigned int i; // ecx
  unsigned __int8 v6; // ah
  unsigned __int8 v7; // al

  for ( i = count; i; --i )
  {
    v6 = *first;
    v7 = *last;
    if ( !*first || !v7 )
      break;
    ++first;
    ++last;
    if ( v6 >= 0x41u && v6 <= 0x5Au )
      v6 += 32;
    if ( v7 >= 0x41u && v7 <= 0x5Au )
      v7 += 32;
    if ( v6 != v7 )
      break;
  }
}
