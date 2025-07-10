int __cdecl lookup_serialno(int s, int *serialno_list, int n)
{
  if ( serialno_list )
  {
    while ( n-- )
    {
      if ( *serialno_list == s )
        return 1;
      ++serialno_list;
    }
  }
  return 0;
}
