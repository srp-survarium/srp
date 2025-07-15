void __cdecl __freetlocinfo(threadlocaleinfostruct *ptloci)
{
  lconv *lconv; // eax
  int *lconv_intl_refcount; // eax
  int *lconv_mon_refcount; // eax
  int *lconv_num_refcount; // eax
  int *ctype1_refcount; // eax
  __lc_time_data *lc_time_curr; // eax
  void **p_refcount; // edi
  _DWORD *v9; // eax
  int ptlocia; // [esp+14h] [ebp+8h]

  lconv = ptloci->lconv;
  if ( lconv )
  {
    if ( lconv != &__lconv_c )
    {
      lconv_intl_refcount = ptloci->lconv_intl_refcount;
      if ( lconv_intl_refcount )
      {
        if ( !*lconv_intl_refcount )
        {
          lconv_mon_refcount = ptloci->lconv_mon_refcount;
          if ( lconv_mon_refcount && !*lconv_mon_refcount )
          {
            free(ptloci->lconv_mon_refcount);
            __free_lconv_mon(ptloci->lconv);
          }
          lconv_num_refcount = ptloci->lconv_num_refcount;
          if ( lconv_num_refcount && !*lconv_num_refcount )
          {
            free(ptloci->lconv_num_refcount);
            __free_lconv_num(ptloci->lconv);
          }
          free(ptloci->lconv_intl_refcount);
          free(ptloci->lconv);
        }
      }
    }
  }
  ctype1_refcount = ptloci->ctype1_refcount;
  if ( ctype1_refcount && !*ctype1_refcount )
  {
    free(ptloci->ctype1 - 127);
    free((void *)(ptloci->pclmap - 128));
    free((void *)(ptloci->pcumap - 128));
    free(ptloci->ctype1_refcount);
  }
  lc_time_curr = ptloci->lc_time_curr;
  if ( lc_time_curr != &__lc_time_c && !lc_time_curr->refcount )
  {
    __free_lc_time(ptloci->lc_time_curr);
    free(ptloci->lc_time_curr);
  }
  p_refcount = (void **)&ptloci->lc_category[0].refcount;
  ptlocia = 6;
  do
  {
    if ( *(p_refcount - 2) != __clocalestr && *p_refcount && !*(_DWORD *)*p_refcount )
      free(*p_refcount);
    if ( *(p_refcount - 1) )
    {
      v9 = p_refcount[1];
      if ( v9 )
      {
        if ( !*v9 )
          free(p_refcount[1]);
      }
    }
    p_refcount += 4;
    --ptlocia;
  }
  while ( ptlocia );
  free(ptloci);
}
