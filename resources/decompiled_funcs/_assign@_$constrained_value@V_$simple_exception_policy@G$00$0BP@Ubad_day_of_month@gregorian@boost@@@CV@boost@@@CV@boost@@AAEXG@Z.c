void __thiscall boost::CV::constrained_value<boost::CV::simple_exception_policy<unsigned short,1,31,boost::gregorian::bad_day_of_month>>::assign(
        boost::CV::constrained_value<boost::CV::simple_exception_policy<unsigned short,1,31,boost::gregorian::bad_day_of_month> > *this,
        unsigned __int16 value)
{
  const std::exception *v2; // eax
  const std::exception *v3; // eax
  boost::gregorian::bad_day_of_month v4; // [esp+28h] [ebp-23Ch] BYREF
  unsigned __int16 v5; // [esp+138h] [ebp-12Ch]
  boost::gregorian::bad_day_of_month v6; // [esp+154h] [ebp-110h] BYREF

  if ( value + 1 >= 2 )
  {
    if ( value <= 0x1Fu )
    {
      this->value_ = value;
    }
    else
    {
      boost::gregorian::bad_day_of_month::bad_day_of_month(&v4);
      boost::throw_exception(v3);
      stlp_std::__Named_exception::~__Named_exception(&v4);
    }
  }
  else
  {
    v5 = this->value_;
    boost::gregorian::bad_day_of_month::bad_day_of_month(&v6);
    boost::throw_exception(v2);
    stlp_std::__Named_exception::~__Named_exception(&v6);
  }
}
