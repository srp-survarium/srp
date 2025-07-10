void __thiscall boost::date_time::counted_time_rep<boost::posix_time::millisec_posix_time_system_config>::counted_time_rep<boost::posix_time::millisec_posix_time_system_config>(
        boost::date_time::counted_time_rep<boost::posix_time::millisec_posix_time_system_config> *this,
        const boost::gregorian::date *d,
        const boost::posix_time::time_duration *time_of_day)
{
  int value_high; // ecx
  boost::date_time::int_adapter<__int64> *v4; // eax
  int v5; // edx
  bool v6; // [esp+4h] [ebp-D8h]
  boost::date_time::int_adapter<__int64> result; // [esp+C4h] [ebp-18h] BYREF
  boost::date_time::int_adapter<unsigned int> rhs; // [esp+D0h] [ebp-Ch] BYREF
  boost::date_time::int_adapter<__int64> v10; // [esp+D4h] [ebp-8h] BYREF

  this->time_count_.value_ = 1;
  v6 = !d->days_ || d->days_ == -1;
  if ( v6 || d->days_ == -2 || boost::date_time::int_adapter<__int64>::is_special(&time_of_day->ticks_) )
  {
    rhs.value_ = d->days_;
    value_high = HIDWORD(time_of_day->ticks_.value_);
    LODWORD(v10.value_) = time_of_day->ticks_.value_;
    HIDWORD(v10.value_) = value_high;
    v4 = boost::date_time::int_adapter<__int64>::operator+<unsigned int>(&v10, &result, &rhs);
    v5 = HIDWORD(v4->value_);
    LODWORD(this->time_count_.value_) = v4->value_;
    HIDWORD(this->time_count_.value_) = v5;
  }
  else
  {
    this->time_count_.value_ = time_of_day->ticks_.value_ + d->days_ * 86400LL * (unsigned int)&off_F4240;
  }
}
