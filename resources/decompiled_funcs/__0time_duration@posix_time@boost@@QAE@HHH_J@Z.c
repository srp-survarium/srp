void __thiscall boost::posix_time::time_duration::time_duration(
        boost::posix_time::time_duration *this,
        int hour,
        int min,
        int sec,
        __int64 fs)
{
  this->ticks_.value_ = boost::date_time::time_resolution_traits<boost::date_time::time_resolution_traits_adapted64_impl,5,1000000,6,int>::to_tick_count(
                          hour,
                          min,
                          sec,
                          fs);
}
