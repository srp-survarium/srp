void __usercall __tzset(unsigned int a1@<edi>)
{
  if ( !first_time_1 )
  {
    _lock(6);
    if ( !first_time_1 )
    {
      tzset_nolock(a1, 0);
      ++first_time_1;
    }
    _unlock(6);
  }
}
