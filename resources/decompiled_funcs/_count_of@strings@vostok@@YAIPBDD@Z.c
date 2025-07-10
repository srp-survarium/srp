unsigned int __cdecl vostok::strings::count_of(const char *string, char char_to_count)
{
  unsigned int out_count; // [esp+0h] [ebp-4h]

  out_count = 0;
  while ( *string )
  {
    if ( *string == char_to_count )
      ++out_count;
    ++string;
  }
  return out_count;
}
