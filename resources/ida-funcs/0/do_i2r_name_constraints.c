int __fastcall do_i2r_name_constraints(int ind, bio_st *bp, stack_st *method, stack_st_GENERAL_SUBTREE *trees)
{
  int v6; // edi
  char *v7; // esi
  int v9; // [esp+10h] [ebp-4h]

  if ( sk_num(method) > 0 )
    BIO_printf(bp, "%*s%s:\n", ind, uri, (const char *)trees);
  v6 = 0;
  if ( sk_num(method) > 0 )
  {
    v9 = ind + 2;
    do
    {
      v7 = sk_value(method, v6);
      BIO_printf(bp, "%*s", v9, uri);
      if ( **(_DWORD **)v7 == 7 )
        print_nc_ipadd(bp, *(asn1_string_st **)(*(_DWORD *)v7 + 4));
      else
        GENERAL_NAME_print(bp, *(GENERAL_NAME_st **)v7);
      BIO_puts((int)bp, bp, "\n");
      ++v6;
    }
    while ( v6 < sk_num(method) );
  }
  return 1;
}
