void __cdecl __free_lconv_num(lconv *l)
{
  char *grouping; // esi

  if ( l )
  {
    if ( l->decimal_point != __lconv_c.decimal_point )
      free(l->decimal_point);
    if ( l->thousands_sep != __lconv_c.thousands_sep )
      free(l->thousands_sep);
    grouping = l->grouping;
    if ( grouping != __lconv_c.grouping )
      free(grouping);
  }
}
