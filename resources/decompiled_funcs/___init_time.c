int __cdecl __init_time(threadlocaleinfostruct *ploci)
{
  __lc_time_data *v1; // esi
  __lc_time_data **p_lc_time_curr; // edi

  if ( ploci->lc_handle[5] )
  {
    v1 = (__lc_time_data *)_calloc_crt(1u, 0xB8u);
    if ( !v1 )
      return 1;
    if ( get_lc_time(v1, ploci) )
    {
      __free_lc_time(v1);
      free(v1);
      return 1;
    }
    v1->refcount = 1;
  }
  else
  {
    v1 = &__lc_time_c;
  }
  p_lc_time_curr = &ploci->lc_time_curr;
  if ( ploci->lc_time_curr != &__lc_time_c )
    InterlockedDecrement(&(*p_lc_time_curr)->refcount);
  *p_lc_time_curr = v1;
  return 0;
}
