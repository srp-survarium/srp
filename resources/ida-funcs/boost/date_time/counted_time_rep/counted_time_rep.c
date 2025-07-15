void __usercall boost::date_time::counted_time_rep<boost::posix_time::millisec_posix_time_system_config>::counted_time_rep<boost::posix_time::millisec_posix_time_system_config>(
        boost::date_time::counted_time_rep<boost::posix_time::millisec_posix_time_system_config> *this@<edi>,
        const boost::gregorian::date *d@<eax>,
        const boost::posix_time::time_duration *time_of_day@<ecx>)
{
  unsigned int days; // ebx
  int v5; // [esp+8h] [ebp-18h] BYREF
  boost::date_time::int_adapter<__int64> v6; // [esp+10h] [ebp-10h] BYREF
  boost::date_time::int_adapter<unsigned int> v7; // [esp+1Ch] [ebp-4h] BYREF

  this->time_count_.value_ = 1;
  days = d->days_;
  if ( !d->days_
    || days == -1
    || days == -2
    || boost::date_time::int_adapter<__int64>::is_special(&time_of_day->ticks_, (int)time_of_day) )
  {
    v6.value_ = time_of_day->ticks_.value_;
    v7.value_ = days;
    this->time_count_.value_ = boost::date_time::int_adapter<__int64>::operator+<unsigned int>(
                                 &time_of_day->ticks_,
                                 &v5,
                                 &v6,
                                 &v7)->value_;
  }
  else
  {
    this->time_count_.value_ = time_of_day->ticks_.value_ + 86400000000LL * days;
  }
}
