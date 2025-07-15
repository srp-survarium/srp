int __cdecl DIST_POINT_set_dpname(DIST_POINT_NAME_st *dpn, X509_name_st *iname)
{
  stack_st_GENERAL_NAME *fullname; // ebx
  int result; // eax
  int v4; // esi
  char *v5; // eax

  if ( !dpn || dpn->type != 1 )
    return 1;
  fullname = dpn->name.fullname;
  result = (int)X509_NAME_dup(iname);
  dpn->dpname = (X509_name_st *)result;
  if ( !result )
    return result;
  v4 = 0;
  if ( sk_num(&fullname->stack) > 0 )
  {
    do
    {
      v5 = sk_value(&fullname->stack, v4);
      if ( !X509_NAME_add_entry(dpn->dpname, (X509_name_entry_st *)v5, -1, v4 == 0) )
        goto LABEL_8;
    }
    while ( ++v4 < sk_num(&fullname->stack) );
  }
  if ( i2d_X509_NAME(dpn->dpname, 0) < 0 )
  {
LABEL_8:
    X509_NAME_free(dpn->dpname);
    dpn->dpname = 0;
    return 0;
  }
  return 1;
}
