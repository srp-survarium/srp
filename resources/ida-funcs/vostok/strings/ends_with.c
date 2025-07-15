bool __cdecl vostok::strings::ends_with(
        const char *source,
        unsigned int source_length,
        const char *string_to_search_for,
        unsigned int string_to_search_for_length)
{
  const char *j; // [esp+0h] [ebp-8h]
  const char *i; // [esp+4h] [ebp-4h]

  i = &source[source_length - 1];
  for ( j = &string_to_search_for[string_to_search_for_length - 1]; i >= source && j >= string_to_search_for; --j )
  {
    if ( *i != *j )
      return 0;
    --i;
  }
  return j < string_to_search_for;
}
