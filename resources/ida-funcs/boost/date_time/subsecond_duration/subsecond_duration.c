void __userpurge boost::date_time::subsecond_duration<boost::posix_time::time_duration,1000>::subsecond_duration<boost::posix_time::time_duration,1000>(
        boost::date_time::subsecond_duration<boost::posix_time::time_duration,1000> *this@<ecx>,
        _QWORD *a2@<esi>,
        __int64 ss)
{
  *a2 = boost::date_time::time_resolution_traits<boost::date_time::time_resolution_traits_adapted64_impl,5,1000000,6,int>::to_tick_count(
          0,
          0,
          0,
          ss * (unsigned int)&loc_F4240 / 1000);
}


void __userpurge boost::date_time::subsecond_duration<boost::posix_time::time_duration,1000000>::subsecond_duration<boost::posix_time::time_duration,1000000>(
        boost::date_time::subsecond_duration<boost::posix_time::time_duration,1000000> *this@<ecx>,
        _QWORD *a2@<edi>,
        __int64 ss)
{
  *a2 = boost::date_time::time_resolution_traits<boost::date_time::time_resolution_traits_adapted64_impl,5,1000000,6,int>::to_tick_count(
          0,
          0,
          0,
          ss * (unsigned int)&loc_F4240 / (unsigned int)&loc_F4240);
}
