void __thiscall boost::posix_time::ptime::ptime(boost::posix_time::ptime *this)
{
  const boost::gregorian::date *v1; // eax
  boost::gregorian::date v3; // [esp+23Ch] [ebp-Ch] BYREF
  boost::posix_time::time_duration time_of_day; // [esp+240h] [ebp-8h] BYREF

  time_of_day.ticks_.value_ = 0x7FFFFFFFFFFFFFFELL;
  boost::gregorian::date::date(&v3, not_a_date_time);
  boost::date_time::counted_time_rep<boost::posix_time::millisec_posix_time_system_config>::counted_time_rep<boost::posix_time::millisec_posix_time_system_config>(
    &this->time_,
    v1,
    &time_of_day);
}
