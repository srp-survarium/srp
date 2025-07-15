int __thiscall boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::wait_duration_msec(
        boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime> > *this,
        int max_duration)
{
  __int64 v3; // rax
  __int64 v4; // kr00_8
  boost::date_time::int_adapter<__int64> *v5; // eax
  boost::date_time::subsecond_duration<boost::posix_time::time_duration,1000> *v6; // ecx
  __int64 *v7; // eax
  boost::date_time::int_adapter<__int64> *v8; // eax
  boost::date_time::subsecond_duration<boost::posix_time::time_duration,1000> *v9; // ecx
  const boost::date_time::int_adapter<__int64> *v10; // eax
  __int64 v12; // [esp-8h] [ebp-30h]
  boost::date_time::subsecond_duration<boost::posix_time::time_duration,1000> *v13; // [esp-4h] [ebp-2Ch]
  boost::posix_time::ptime result; // [esp+10h] [ebp-18h] BYREF
  __int64 v15; // [esp+18h] [ebp-10h] BYREF
  __int64 v16; // [esp+20h] [ebp-8h] BYREF

  if ( this->heap_._M_impl._M_start != this->heap_._M_impl._M_finish )
  {
    boost::date_time::microsec_clock<boost::posix_time::ptime>::create_time(&result);
    boost::date_time::counted_time_system<boost::date_time::counted_time_rep<boost::posix_time::millisec_posix_time_system_config>>::subtract_times(
      &this->heap_._M_impl._M_start->time_.time_,
      &result.time_,
      &v15);
    v4 = v15;
    result.time_.time_count_.value_ = v15;
    v15 = max_duration;
    boost::date_time::subsecond_duration<boost::posix_time::time_duration,1000>::subsecond_duration<boost::posix_time::time_duration,1000>(
      v13,
      &v16,
      max_duration);
    if ( boost::date_time::int_adapter<__int64>::compare(v5, &result.time_.time_count_) == -1 )
    {
      boost::date_time::subsecond_duration<boost::posix_time::time_duration,1000>::subsecond_duration<boost::posix_time::time_duration,1000>(
        v6,
        &v16,
        v15);
    }
    else
    {
      boost::date_time::subsecond_duration<boost::posix_time::time_duration,1000>::subsecond_duration<boost::posix_time::time_duration,1000>(
        v6,
        &v16,
        0);
      HIDWORD(v12) = 0;
      if ( boost::date_time::int_adapter<__int64>::compare(v8, &result.time_.time_count_) == -1 )
      {
        boost::date_time::subsecond_duration<boost::posix_time::time_duration,1000>::subsecond_duration<boost::posix_time::time_duration,1000>(
          v9,
          &v16,
          1);
        if ( boost::date_time::int_adapter<__int64>::compare(&result.time_.time_count_, v10) != -1 )
          return v4 / 1000;
        v12 = 1;
      }
      else
      {
        LODWORD(v12) = 0;
      }
      boost::date_time::subsecond_duration<boost::posix_time::time_duration,1000>::subsecond_duration<boost::posix_time::time_duration,1000>(
        v9,
        &v16,
        v12);
    }
    v4 = *v7;
    return v4 / 1000;
  }
  LODWORD(v3) = max_duration;
  return v3;
}
