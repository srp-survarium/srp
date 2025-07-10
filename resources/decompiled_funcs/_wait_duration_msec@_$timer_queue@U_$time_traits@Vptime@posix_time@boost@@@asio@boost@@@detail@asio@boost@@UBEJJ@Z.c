int __thiscall boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::wait_duration_msec(
        boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime> > *this,
        int max_duration)
{
  __int64 v5; // [esp+3Ch] [ebp-70h]
  boost::date_time::int_adapter<__int64> rhs; // [esp+6Ch] [ebp-40h] BYREF
  int v7; // [esp+78h] [ebp-34h]
  boost::date_time::int_adapter<__int64> v8; // [esp+7Ch] [ebp-30h] BYREF
  boost::date_time::int_adapter<__int64> v9; // [esp+8Ch] [ebp-20h] BYREF
  boost::posix_time::time_duration v10; // [esp+94h] [ebp-18h] BYREF
  boost::posix_time::ptime result; // [esp+9Ch] [ebp-10h] BYREF
  boost::posix_time::time_duration duration; // [esp+A4h] [ebp-8h] BYREF

  if ( this->heap_._M_impl._M_start == this->heap_._M_impl._M_finish )
    return max_duration;
  boost::date_time::microsec_clock<boost::posix_time::ptime>::create_time(&result, boost::date_time::c_time::gmtime);
  boost::date_time::counted_time_system<boost::date_time::counted_time_rep<boost::posix_time::millisec_posix_time_system_config>>::subtract_times(
    &v10,
    &this->heap_._M_impl._M_start->time_.time_,
    &result.time_);
  duration.ticks_.value_ = v10.ticks_.value_;
  v9.value_ = boost::date_time::time_resolution_traits<boost::date_time::time_resolution_traits_adapted64_impl,5,1000000,6,int>::to_tick_count(
                0,
                0,
                0,
                (__int64)(max_duration * (unsigned __int64)(unsigned int)&off_F4240) / 1000);
  if ( boost::date_time::int_adapter<__int64>::compare(&v9, &duration.ticks_) == -1 )
  {
    duration.ticks_.value_ = boost::date_time::time_resolution_traits<boost::date_time::time_resolution_traits_adapted64_impl,5,1000000,6,int>::to_tick_count(
                               0,
                               0,
                               0,
                               (__int64)(max_duration * (unsigned __int64)(unsigned int)&off_F4240) / 1000);
  }
  else
  {
    v8.value_ = boost::date_time::time_resolution_traits<boost::date_time::time_resolution_traits_adapted64_impl,5,1000000,6,int>::to_tick_count(
                  0,
                  0,
                  0,
                  0);
    if ( boost::date_time::int_adapter<__int64>::compare(&v8, &duration.ticks_) == -1 )
    {
      rhs.value_ = boost::date_time::time_resolution_traits<boost::date_time::time_resolution_traits_adapted64_impl,5,1000000,6,int>::to_tick_count(
                     0,
                     0,
                     0,
                     (unsigned int)&off_F4240 / 1000LL);
      if ( boost::date_time::int_adapter<__int64>::compare(&duration.ticks_, &rhs) == -1 )
        duration.ticks_.value_ = boost::date_time::time_resolution_traits<boost::date_time::time_resolution_traits_adapted64_impl,5,1000000,6,int>::to_tick_count(
                                   0,
                                   0,
                                   0,
                                   (unsigned int)&off_F4240 / 1000LL);
    }
    else
    {
      v5 = boost::date_time::time_resolution_traits<boost::date_time::time_resolution_traits_adapted64_impl,5,1000000,6,int>::to_tick_count(
             0,
             0,
             0,
             0);
      v7 = HIDWORD(v5);
      duration.ticks_.value_ = v5;
    }
  }
  if ( (unsigned int)&off_F4240 >= 0x3E8 )
    return duration.ticks_.value_ / ((unsigned int)&off_F4240 / 1000LL);
  else
    return duration.ticks_.value_ * (1000LL / (unsigned int)&off_F4240);
}
