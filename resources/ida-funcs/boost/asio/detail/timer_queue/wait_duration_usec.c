int __thiscall boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::wait_duration_usec(
        boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime> > *this,
        int max_duration)
{
  int v4; // esi
  int v5; // ebx
  boost::date_time::int_adapter<__int64> *v6; // eax
  boost::date_time::subsecond_duration<boost::posix_time::time_duration,1000000> *v7; // ecx
  boost::date_time::int_adapter<__int64> *v8; // eax
  const boost::date_time::int_adapter<__int64> *v9; // eax
  int *v10; // eax
  __int64 v11; // [esp-8h] [ebp-30h]
  boost::date_time::subsecond_duration<boost::posix_time::time_duration,1000000> *v12; // [esp-4h] [ebp-2Ch]
  boost::posix_time::ptime result; // [esp+10h] [ebp-18h] BYREF
  __int64 v14; // [esp+18h] [ebp-10h] BYREF
  __int64 v15; // [esp+20h] [ebp-8h] BYREF

  if ( this->heap_._M_impl._M_start == this->heap_._M_impl._M_finish )
    return max_duration;
  boost::date_time::microsec_clock<boost::posix_time::ptime>::create_time(&result);
  boost::date_time::counted_time_system<boost::date_time::counted_time_rep<boost::posix_time::millisec_posix_time_system_config>>::subtract_times(
    &this->heap_._M_impl._M_start->time_.time_,
    &result.time_,
    &v14);
  v4 = v14;
  v5 = max_duration;
  result.time_.time_count_.value_ = v14;
  HIDWORD(v14) = max_duration >> 31;
  boost::date_time::subsecond_duration<boost::posix_time::time_duration,1000000>::subsecond_duration<boost::posix_time::time_duration,1000000>(
    v12,
    &v15,
    max_duration);
  if ( boost::date_time::int_adapter<__int64>::compare(v6, &result.time_.time_count_) == -1 )
  {
    HIDWORD(v11) = HIDWORD(v14);
LABEL_5:
    LODWORD(v11) = v5;
LABEL_9:
    boost::date_time::subsecond_duration<boost::posix_time::time_duration,1000000>::subsecond_duration<boost::posix_time::time_duration,1000000>(
      v7,
      &v15,
      v11);
    v4 = *v10;
    HIDWORD(result.time_.time_count_.value_) = v10[1];
    return v4;
  }
  v5 = 0;
  boost::date_time::subsecond_duration<boost::posix_time::time_duration,1000000>::subsecond_duration<boost::posix_time::time_duration,1000000>(
    v7,
    &v15,
    0);
  HIDWORD(v11) = 0;
  if ( boost::date_time::int_adapter<__int64>::compare(v8, &result.time_.time_count_) != -1 )
    goto LABEL_5;
  boost::date_time::subsecond_duration<boost::posix_time::time_duration,1000000>::subsecond_duration<boost::posix_time::time_duration,1000000>(
    v7,
    &v15,
    1);
  if ( boost::date_time::int_adapter<__int64>::compare(&result.time_.time_count_, v9) == -1 )
  {
    v11 = 1;
    goto LABEL_9;
  }
  return v4;
}
