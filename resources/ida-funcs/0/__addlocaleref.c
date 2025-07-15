void __cdecl __addlocaleref(threadlocaleinfostruct *ptloci)
{
  volatile LONG **p_refcount; // ebx
  int ptlocia; // [esp+14h] [ebp+8h]

  InterlockedIncrement(&ptloci->refcount);
  if ( ptloci->lconv_intl_refcount )
    InterlockedIncrement(ptloci->lconv_intl_refcount);
  if ( ptloci->lconv_mon_refcount )
    InterlockedIncrement(ptloci->lconv_mon_refcount);
  if ( ptloci->lconv_num_refcount )
    InterlockedIncrement(ptloci->lconv_num_refcount);
  if ( ptloci->ctype1_refcount )
    InterlockedIncrement(ptloci->ctype1_refcount);
  p_refcount = (volatile LONG **)&ptloci->lc_category[0].refcount;
  ptlocia = 6;
  do
  {
    if ( *(p_refcount - 2) != (volatile LONG *)__clocalestr && *p_refcount )
      InterlockedIncrement(*p_refcount);
    if ( *(p_refcount - 1) && p_refcount[1] )
      InterlockedIncrement(p_refcount[1]);
    p_refcount += 4;
    --ptlocia;
  }
  while ( ptlocia );
  InterlockedIncrement(&ptloci->lc_time_curr->refcount);
}
