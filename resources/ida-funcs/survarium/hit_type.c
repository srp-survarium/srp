int __cdecl survarium::hit_type(char *hit_type_name)
{
  int i; // esi

  for ( i = 0; vostok::strings::compare(hit_type_name, hit_type_names_77[i]); ++i )
    ;
  return i;
}
