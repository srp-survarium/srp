void __usercall boost::posix_time::ptime::ptime(
        boost::posix_time::ptime *this@<ecx>,
        boost::date_time::counted_time_rep<boost::posix_time::millisec_posix_time_system_config> *a2@<eax>)
{
  boost::posix_time::time_duration time_of_day; // [esp+8h] [ebp-10h] BYREF
  boost::gregorian::date d; // [esp+14h] [ebp-4h] BYREF

  time_of_day.ticks_.value_ = 0x7FFFFFFFFFFFFFFELL;
  d.days_ = -2;
  boost::date_time::counted_time_rep<boost::posix_time::millisec_posix_time_system_config>::counted_time_rep<boost::posix_time::millisec_posix_time_system_config>(
    a2,
    &d,
    &time_of_day);
}
