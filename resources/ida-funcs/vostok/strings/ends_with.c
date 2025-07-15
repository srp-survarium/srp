bool __usercall vostok::strings::ends_with@<al>(
        const char *source@<esi>,
        const unsigned int source_length@<edi>,
        const unsigned int string_to_search_for_length@<edx>,
        const char *string_to_search_for)
{
  const char *v4; // ecx
  const char *v5; // eax
  bool v6; // cf

  v4 = &string_to_search_for[string_to_search_for_length - 1];
  if ( &source[source_length - 1] < source )
    return v4 < string_to_search_for;
  v5 = &source[source_length - 1];
  while ( 1 )
  {
    v6 = v4 < string_to_search_for;
    if ( v4 < string_to_search_for )
      break;
    if ( *v5 != *v4 )
      return 0;
    --v4;
    if ( --v5 < source )
      return v4 < string_to_search_for;
  }
  return v6;
}
