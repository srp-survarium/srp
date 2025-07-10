threadlocaleinfostruct *__cdecl __removelocaleref(threadlocaleinfostruct *ptloci)
{
  volatile LONG **p_refcount; // ebx
  int ptlocia; // [esp+Ch] [ebp+8h]

  if ( ptloci )
  {
    InterlockedDecrement(&ptloci->refcount);
    if ( ptloci->lconv_intl_refcount )
      InterlockedDecrement(ptloci->lconv_intl_refcount);
    if ( ptloci->lconv_mon_refcount )
      InterlockedDecrement(ptloci->lconv_mon_refcount);
    if ( ptloci->lconv_num_refcount )
      InterlockedDecrement(ptloci->lconv_num_refcount);
    if ( ptloci->ctype1_refcount )
      InterlockedDecrement(ptloci->ctype1_refcount);
    p_refcount = (volatile LONG **)&ptloci->lc_category[0].refcount;
    ptlocia = 6;
    do
    {
      if ( *(p_refcount - 2) != (volatile LONG *)__clocalestr && *p_refcount )
        InterlockedDecrement(*p_refcount);
      if ( *(p_refcount - 1) && p_refcount[1] )
        InterlockedDecrement(p_refcount[1]);
      p_refcount += 4;
      --ptlocia;
    }
    while ( ptlocia );
    InterlockedDecrement(&ptloci->lc_time_curr->refcount);
  }
  return ptloci;
}
