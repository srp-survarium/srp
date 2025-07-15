bool __usercall vostok::strings::starts_with@<al>(
        const char *const source@<edx>,
        const char *const string_to_search_for@<eax>)
{
  int v2; // edx

  if ( *source )
  {
    v2 = source - string_to_search_for;
    while ( *string_to_search_for )
    {
      if ( string_to_search_for[v2] != *string_to_search_for )
        return 0;
      ++string_to_search_for;
      if ( !string_to_search_for[v2] )
        return *string_to_search_for == 0;
    }
  }
  return *string_to_search_for == 0;
}
