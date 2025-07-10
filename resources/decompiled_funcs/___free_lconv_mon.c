void __cdecl __free_lconv_mon(lconv *l)
{
  char *negative_sign; // esi

  if ( l )
  {
    if ( l->int_curr_symbol != __lconv_c.int_curr_symbol )
      free(l->int_curr_symbol);
    if ( l->currency_symbol != __lconv_c.currency_symbol )
      free(l->currency_symbol);
    if ( l->mon_decimal_point != __lconv_c.mon_decimal_point )
      free(l->mon_decimal_point);
    if ( l->mon_thousands_sep != __lconv_c.mon_thousands_sep )
      free(l->mon_thousands_sep);
    if ( l->mon_grouping != __lconv_c.mon_grouping )
      free(l->mon_grouping);
    if ( l->positive_sign != __lconv_c.positive_sign )
      free(l->positive_sign);
    negative_sign = l->negative_sign;
    if ( negative_sign != __lconv_c.negative_sign )
      free(negative_sign);
  }
}
