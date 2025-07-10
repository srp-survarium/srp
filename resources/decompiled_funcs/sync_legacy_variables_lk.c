int sync_legacy_variables_lk()
{
  int result; // eax

  __lc_codepage = __ptlocinfo->lc_codepage;
  __lc_collate_cp = __ptlocinfo->lc_collate_cp;
  __lc_clike = __ptlocinfo->lc_clike;
  __lc_time_curr = __ptlocinfo->lc_time_curr;
  __lconv = __ptlocinfo->lconv;
  _pctype = __ptlocinfo->pctype;
  result = __ptlocinfo->mb_cur_max;
  __mb_cur_max = result;
  return result;
}
